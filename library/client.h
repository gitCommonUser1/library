#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class MessageIO;

class QTimer;

#define DEFAULT_PORT 19010
#define AUTO_CONNECT_TIME 3000

class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)
public:
    explicit Client(QObject *parent = nullptr);
    Q_INVOKABLE void connectByIpAddress(QString ipAddress);

    bool connected() const
    {
        return m_connected;
    }

    Q_INVOKABLE bool signIn(QString username,QString password);
    Q_INVOKABLE void sendImage(QString fileName);
private:
    void signInCall(bool &ok, bool &value,const QVariantList &pars);

signals:
    void signInSignal(bool result);

public slots:
    void setConnected(bool connected)
    {
        if (m_connected == connected)
            return;

        m_connected = connected;
        emit connectedChanged(m_connected);
    }

private:
    MessageIO *messageIO;

    bool m_connected;

    QTimer *m_timer;


private:
    void write(QString id, QString type,QList<QVariant>pars);
    void writeImage(char *data,int len);

    template<typename T>
    void waitMessageCall(bool &ok,T &value,QString id,QVariantList pars, void (Client::*signal)(T));

signals:
    void connectedChanged(bool connected);
};

#endif // CLIENT_H
