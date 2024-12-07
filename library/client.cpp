#include "client.h"
#include "messageio.h"
#include "messageCmd.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>

#define WAIT_TIME 1000

// #define Max_fileSize 1024 * 200
#define SinglePack 1024 * 50
#define TIMER_WAIT 50

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

void Client::getBooks()
{
    write("getBooks","get",{});
}

void Client::removeBook(QString bookId)
{
    write("removeBook","set",{bookId});
}

void Client::addBook(QString name, QString bookid, QString auname, int pages, double price, QString type, QString language)
{
    write("addBook","set",{name,bookid,auname,pages,price,type,language});
}

void Client::getBorrow()
{
    write("getBorrow","get",{});
}

void Client::sendImage(QString fileName)
{
    static QTimer *timer = nullptr;
    static int offSetBytes = 0;
    static QByteArray bytes = QByteArray();
    if(timer != nullptr && timer->isActive())
        return ;
    QUrl url(fileName);
    if(!QFile::exists(fileName))
        return ;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
        return ;
    bytes = file.readAll();
    if(/*bytes.size() > Max_fileSize || */bytes.size() == 0){
        file.close();
        return ;
    }
    QFileInfo fileInfo(fileName);
    fileName = fileInfo.fileName();
    offSetBytes = -1;
    if(timer == nullptr){
        timer = new QTimer;
        timer->setInterval(TIMER_WAIT);
        connect(timer,&QTimer::timeout,this,[=](){
            if(offSetBytes == -1){
                write("imageBegin","set",{fileName,bytes.size()});
                offSetBytes = 0;
            }else if(offSetBytes >= bytes.size()){
                write("imageEnd","set",{});
                timer->stop();
            }else{
                if(offSetBytes < bytes.size()){
                    QByteArray data = bytes.mid(offSetBytes,SinglePack);
                    qDebug() << "data:" << data.length();
                    writeImage(data.data(),data.size());
                    offSetBytes += data.size();
                }
            }
        });
    }
    timer->start();
    file.close();
}

void Client::borrowBook(QString userId, QString bookId, QString date)
{
    write("borrowBook","set",{userId,bookId,date});
}

void Client::returnBook(QString bookId, QString date)
{
    write("returnBook","set",{bookId,date});
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

void Client::writeImage(char *data,int len)
{
    messageIO->sendBytes(Image,QByteArray(data,len));
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
