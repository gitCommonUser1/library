#ifndef IMAGERECEIVER_H
#define IMAGERECEIVER_H

#include <QObject>

class FileData{
    Q_GADGET
    Q_PROPERTY(QByteArray bytes READ bytes WRITE setBytes)
    Q_PROPERTY(int size READ size WRITE setSize)
    Q_PROPERTY(bool working READ working WRITE setWorking)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
public:
    FileData(){
    }
    QByteArray bytes() const
    {
        return m_bytes;
    }

    int size() const
    {
        return m_size;
    }

    bool working() const
    {
        return m_working;
    }

    QString fileName() const
    {
        return m_fileName;
    }

public slots:
    void setBytes(QByteArray bytes)
    {
        m_bytes = bytes;
    }

    void appendBytes(QByteArray bytes,int len){
        m_bytes.append(bytes,len);
    }

    void setSize(int size)
    {
        m_size = size;
    }

    void setWorking(bool working)
    {
        m_working = working;
    }

    void setFileName(QString fileName)
    {
        m_fileName = fileName;
    }

private:
    QByteArray m_bytes;
    int m_size;
    bool m_working;
    QString m_fileName;
};


class ImageReceiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString savePath READ savePath WRITE setSavePath NOTIFY savePathChanged FINAL)
public:
    explicit ImageReceiver(QObject *parent = nullptr);

    void fileBegin(QString filename,int size);
    void fileEnd();
    void fileReceive(QByteArray data,int len);

    QString savePath() const;
    void setSavePath(const QString &newSavePath);

signals:
    void result(bool result,const QByteArray &bytes);

    void savePathChanged();

private:
    FileData *m_fileData;
    QString m_savePath;
};

#endif // IMAGERECEIVER_H
