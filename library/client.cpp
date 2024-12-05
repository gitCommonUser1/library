#include "client.h"
#include "messageio.h"
#include "messageCmd.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QEventLoop>

#define WAIT_TIME 1000

Client::Client(QObject *parent) : QObject(parent)
{
    m_connected = false;
    messageIO = new MessageIO();
    QTcpSocket *socket = new QTcpSocket;
    messageIO->setObj(socket);
    connect(socket,&QTcpSocket::readyRead,messageIO,&MessageIO::read);
    connect(socket,&QTcpSocket::connected,this,[=](){setConnected(true);});
    connect(socket,&QTcpSocket::disconnected,this,[=](){setConnected(false);});
    m_timer = new QTimer;
    //auto connect
    connect(m_timer,&QTimer::timeout,this,[=](){
        if(!m_connected){
            connectByIpAddress("localhost");
        }
    });
    m_timer->start(AUTO_CONNECT_TIME);
    connectByIpAddress("localhost");
}

void Client::connectByIpAddress(QString ipAddress)
{
    qobject_cast<QTcpSocket*>(messageIO->obj())->connectToHost(ipAddress,DEFAULT_PORT);
    qobject_cast<QTcpSocket*>(messageIO->obj())->waitForConnected(100);
}

bool Client::signIn(QString username,QString password)
{
    bool ok;
    bool value;
    signInCall(ok,value,{username,password});
    if(ok){
        return value;
    }
}

void Client::signInCall(bool &ok, bool &value,const QVariantList &pars)
{
    waitMessageCall(ok,value,"signIn",pars,&Client::signInSignal);
}

void Client::write(QString id, QString type, QList<QVariant> pars)
{
    QByteArray bytes = createMessage(id,type,pars);
    messageIO->sendPack(bytes);
}

template<typename T>
void Client::waitMessageCall(bool &ok, T &value, QString id, QVariantList pars, void (Client::*signal)(T))
{
    ok = false;
    QEventLoop loop;
    QTimer t;
    connect(&t,&QTimer::timeout,this,[&](){
        loop.quit();
    });
    t.start(WAIT_TIME);
    connect(this,signal,&loop,[&](T par){
        ok = true;
        value = par;
        t.stop();
        loop.quit();
    });
    write(id,"get",pars);
    loop.exec();
}
