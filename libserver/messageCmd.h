#ifndef MESSAGECMD_H
#define MESSAGECMD_H

#include "crc16.h"
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QByteArray>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

enum CtrlType{
    Json = 0,
};


#pragma   pack(1)
struct pc_ctrl_head_t {
    uint16_t header;
    uint8_t type;
    uint16_t len;
    uint8_t data[0];
};
#pragma   pack() \
    //ntohs
#define pack_crc16(data)   (crc16_modbus((data), (((((struct pc_ctrl_head_t *)(data))->len) - 2) + sizeof(struct pc_ctrl_head_t))))
#define to_msg_len(n)	((n) + sizeof(struct pc_ctrl_head_t) + 2)
#define QT_CTRL_HEAD						0xEBA6


#define get_msg_len(data)			(sizeof(struct pc_ctrl_head_t) + (((struct pc_ctrl_head_t *)(data))->len))//ntohs
#define get_msg_data_len(data)		((((struct pc_ctrl_head_t *)(data))->len) - 2)//ntohs

static inline void pack_act(uint8_t *data)
{
    uint16_t crc = 0;
    uint16_t len = 0;

    len = (((struct pc_ctrl_head_t *)(data))->len);//ntohs
    len += 2;
    (((struct pc_ctrl_head_t *)(data))->len) = (len);//htons
    crc = pack_crc16(data);
    (((struct pc_ctrl_head_t *)(data))->data[len - 2]) = (crc & 0xFF);
    (((struct pc_ctrl_head_t *)(data))->data[len - 1]) = ((crc >> 8) & 0xFF);
}

static inline void pack_json(QByteArray array,uint8_t *sendbuf)
{
    struct pc_ctrl_head_t *pc_ctrl = (struct pc_ctrl_head_t *)sendbuf;
    pc_ctrl->header = htons(QT_CTRL_HEAD);
    pc_ctrl->len = array.length();
    pc_ctrl->type = Json;
    memcpy(pc_ctrl->data,array.data(),pc_ctrl->len);
    pack_act(sendbuf);
}


static int parseMessage(QByteArray bytes,QString& messageType,QString& paramerType,QList<QVariant>& list)
{
    QJsonDocument doc = QJsonDocument::fromJson(bytes);
    list.clear();

    if(!doc.isObject())
        return -1;

    QJsonObject obj = doc.object();
    if(obj.contains("id"))
    {
        messageType = obj["id"].toString();
    }
    else
    {
        return -1;
    }

    if(obj.contains("type"))
    {
        paramerType = obj["type"].toString();
    }
    else
    {
        return -1;
    }

    if(obj.contains("value"))
    {
        if(obj["value"].isArray())
        {
            auto array = obj["value"].toArray();
            foreach (auto var, array) {
                list << var.toVariant();
            }
        }
    }
    else
    {
        return -1;
    }

    return 0;
}

static QByteArray createMessage(QString messageType,QString paramerType, QList<QVariant> list)
{
    QJsonObject obj;
    obj["id"] = messageType;
    obj["type"] = paramerType;
    //    if(list.size() != 0)
    {
        QJsonArray array;
        foreach (auto var, list) {
            if(var.type() == QVariant::Bool){
                if(var.toBool() == true){
                    array << 1;
                }else{
                    array << 0;
                }
            }else{
                array << QJsonValue::fromVariant(var);
            }
        }
        obj["value"] = array;
    }
    return QJsonDocument(obj).toJson();
}


#endif // MESSAGECMD_H
