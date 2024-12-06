#include "messageio.h"
#include "messageCmd.h"
#include <QTcpSocket>
#include <QTimer>
#include "sql.h"
#include "imagereceiver.h"

extern Sql *sql;
extern ImageReceiver *imageReceiver;

MessageIO::MessageIO(QObject *parent) : QObject(parent)
{
    connect(this,&MessageIO::bufferChanged,this,&MessageIO::parse);
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,[=](){
        m_buffer.append(m_lessSize,0);
        emit bufferChanged();
    });
    m_timer->setInterval(500);
}

void MessageIO::sendPack(QByteArray bytes)
{
    uint8_t sendbuf[to_msg_len(bytes.length())];
    pack_json(bytes,sendbuf);
    write((char *)sendbuf,to_msg_len(bytes.length()));
}

void MessageIO::write(char *buf, int len)
{
    if(m_obj->inherits("QTcpSocket"))
    {
        //socket
        qobject_cast<QTcpSocket*>(m_obj)->write(buf,len);
    }
}

void MessageIO::read()
{
    if(m_obj->inherits("QTcpSocket"))
    {
        //socket
        m_buffer.append(qobject_cast<QTcpSocket*>(m_obj)->readAll());
        emit bufferChanged();
    }
}

void MessageIO::parse()
{
    m_mutex.lock();
    int length = m_buffer.length();
    int offset = 0;
    const char *data = m_buffer.data();
    struct pc_ctrl_head_t *pc_ctrl = NULL;
    while(offset < length){
        pc_ctrl = (struct pc_ctrl_head_t *)data;
        if(QT_CTRL_HEAD == ntohs(pc_ctrl->header)){
            int msg_len = sizeof(struct pc_ctrl_head_t) + pc_ctrl->len;
            if(msg_len > length - offset){
                m_lessSize = msg_len - (length - offset);
                m_timer->start();
                break;
            }else{
                m_timer->stop();
                auto p_crc = (uint16_t *)(data + msg_len - 2);
                if (crc16_modbus((uint8_t*)data,msg_len - 2) != (*p_crc))//ntohs
                {
                    qDebug() << " message error !!!!!";
                    data+=2;
                    offset+=2;
                    //返回错误消息
                }
                else
                {
                    int dataLen = pc_ctrl->len - 2;
                    char *m_data = (char*)malloc(dataLen);
                    memcpy(m_data,pc_ctrl->data,dataLen);
                    switch (pc_ctrl->type) {
                    case Json:
                        newMessage(m_data,dataLen);
                        break;
                    case Image:
                        newImage(m_data,dataLen);
                        break;
                    }
                    data += msg_len;
                    offset += msg_len;
                }
            }
        }else if((QT_CTRL_HEAD >> 8 << 8) == ntohs(pc_ctrl->header) && length - offset == 1 ){
            break;
        }else{
            data++;
            offset++;
        }
    }
    m_buffer = m_buffer.mid(offset);
    m_mutex.unlock();
}



void MessageIO::newMessage(char *data, int len)
{
    QByteArray message(data,len);
    qDebug() << "server message:" << message;
    free(data);

    QString paramerType,messageType;
    QList<QVariant> list;
    int parse_ret = parseMessage(message,messageType,paramerType,list);
    if(parse_ret != 0)
    {
        //错误消息
        return ;
    }
    if(messageType == "signIn"){
        if(paramerType == "get"){
            if(list.size() > 1){
                bool result = sql->signIn(list[0].toString(),list[1].toString());
                sendPack(createMessage(messageType,"res",{result}));
            }
        }
    }else if(messageType == "imageBegin"){
        if(list.size() > 1){
            imageReceiver->fileBegin(list[0].toString(),list[1].toInt());
        }
    }else if(messageType == "imageEnd"){
        imageReceiver->fileEnd();
    }
}

void MessageIO::newImage(char *data, int len)
{
    imageReceiver->fileReceive(QByteArray(data,len),len);
    free(data);
}
