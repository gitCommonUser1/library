#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QHostAddress>
class QTcpServer;

#define DEFAULT_PORT 19010

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);

private:
    QTcpServer*m_server;
signals:

};

#endif // SERVER_H
