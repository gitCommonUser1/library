#include "server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>
#include "messageio.h"
#include <QDebug>

Server::Server(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer;
    connect(m_server,&QTcpServer::newConnection,this,[=](){
        if(m_server->hasPendingConnections())
        {
            qDebug() << "socket connect!!!!";
            QTcpSocket *socket = m_server->nextPendingConnection();
            if(socket != nullptr)
            {
                MessageIO *messageio = new MessageIO();
                messageio->setObj(socket);
                connect(socket,&QTcpSocket::disconnected,this,[=](){
                    messageio->deleteLater();
                    messageio->obj()->deleteLater();
                });
                connect(socket,&QTcpSocket::readyRead,messageio,&MessageIO::read);
            }
        }
    });
}

bool Server::listen(const QHostAddress &address, quint16 port)
{
    m_server->listen(address,port);
}

