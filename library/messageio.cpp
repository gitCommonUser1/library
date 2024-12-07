#include "messageio.h"
#include "messageCmd.h"
#include <QTcpSocket>
#include <QTimer>
#include "client.h"
#include "booksmodel.h"
#include "borrowmodel.h"
#include "state.h"

extern Client *client;
extern BooksModel *booksModel;
extern BorrowModel *borrowModel;
extern State *state;


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

void MessageIO::sendBytes(int type,QByteArray bytes)
{
    uint8_t sendbuf[to_msg_len(bytes.length())];
    pack_bytes(Image,bytes,sendbuf);
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
        if(paramerType == "res"){
            emit client->signInSignal(list[0].toBool());
        }
    }else if(messageType == "getBooks"){
        if(paramerType == "res"){
            BookItem item;
            item.setName(list[0].toString());
            item.setAuthor(list[1].toString());
            item.setBookId(list[2].toString());
            item.setPages(list[3].toInt());
            item.setType(list[4].toString());
            item.setLanguage(list[5].toString());
            item.setPrice(list[6].toDouble());
            booksModel->appendItem(item);
        }
    }else if(messageType == "removeBook"){
        if(paramerType == "res"){
            booksModel->removeOneByBookId(list[0].toString());
        }
    }else if(messageType == "addBook"){
        if(paramerType == "res"){
            BookItem item;
            item.setName(list[0].toString());
            item.setBookId(list[1].toString());
            item.setAuthor(list[1].toString());
            item.setPages(list[3].toInt());
            item.setPrice(list[4].toDouble());
            item.setType(list[5].toString());
            item.setLanguage(list[6].toString());
            booksModel->appendItem(item);
        }
    }else if(messageType == "getBorrow"){
        if(paramerType == "res"){
            BorrowItem item;
            item.setUserId(list[0].toString());
            item.setBookId(list[1].toString());
            item.setBorrowStatus(list[2].toString());
            QDateTime dateTime = QDateTime::fromString(list[3].toString(), Qt::ISODate);
            QString formattedDate = dateTime.toString("yyyy-MM-dd HH:mm:ss");
            item.setBorrowDate(formattedDate);
            dateTime = QDateTime::fromString(list[4].toString(), Qt::ISODate);
            formattedDate = dateTime.toString("yyyy-MM-dd HH:mm:ss");
            item.setReturnDate(formattedDate);
            borrowModel->appendItem(item);
            state->appendUserId(list[0].toString());
            state->appendBookId(list[1].toString());
        }
    }else if(messageType == "borrowBook"){
        BorrowItem item;
        item.setUserId(list[0].toString());
        item.setBookId(list[1].toString());
        item.setBorrowDate(list[2].toString());
        // item.setReturnDate("");
        item.setBorrowStatus("borrowed");
        borrowModel->appendItem(item);
        state->appendUserId(list[0].toString());
        state->appendBookId(list[1].toString());
        emit client->borrowBookOk();
    }else if(messageType == "borrowBookError"){
        emit client->borrowBookError();
    }else if(messageType == "returnBook"){
        QDateTime dateTime = QDateTime::fromString(list[1].toString(), Qt::ISODate);
        QString formattedDate = dateTime.toString("yyyy-MM-dd HH:mm:ss");
        borrowModel->returnBookByBookId(list[0].toString(),formattedDate);
        emit client->returnBookOk();
    }else if(messageType == "returnBookError"){
        emit client->returnBookError();
    }
}
