#ifndef MESSAGEIO_H
#define MESSAGEIO_H

#include <QObject>
#include <QMutex>

class QTimer;
class MessageInterface;

class MessageIO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* obj READ obj WRITE setObj)
public:
    explicit MessageIO(QObject *parent = nullptr);
    QObject* obj() const
    {
        return m_obj;
    }
    void sendPack(QByteArray bytes);
    void sendBytes(int type,QByteArray bytes);
    void newMessage(char *data,int len);

public slots:
    void setObj(QObject* obj)
    {
        m_obj = obj;
    }

private:
    //socket or hid
    QObject* m_obj;
    QByteArray m_buffer;
    QMutex m_mutex;
    QTimer *m_timer;
    int m_lessSize;
    MessageInterface *m_interface;

signals:
    void bufferChanged();

public slots:
    void write(char *buf, int len);
    void read();
    void parse();
};


#endif // MESSAGEIO_H
