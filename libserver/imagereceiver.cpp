#include "imagereceiver.h"
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>

ImageReceiver::ImageReceiver(QObject *parent)
    : QObject{parent}
{
    m_fileData = new FileData;

    m_savePath = QCoreApplication::applicationDirPath() + "/images/";

    QDir dir (m_savePath);
    if(!dir.exists())
    {
        dir.mkdir(m_savePath);
    }
}

void ImageReceiver::fileBegin(QString filename,int size)
{
    m_fileData->setSize(size);
    m_fileData->setWorking(true);
    m_fileData->setBytes(QByteArray());
    m_fileData->setFileName(filename);
}

void ImageReceiver::fileEnd()
{
    if(m_fileData->bytes().size() == m_fileData->size()){
        emit result(true,m_fileData->bytes());
        QFile file(m_savePath + m_fileData->fileName());
        file.open(QIODevice::WriteOnly);
        file.write(m_fileData->bytes(),m_fileData->size());
    }else{
        emit result(false,QByteArray());
    }
    m_fileData->setWorking(false);
}

void ImageReceiver::fileReceive(QByteArray data, int len)
{
    if(m_fileData->bytes().size() >= m_fileData->size())
        return ;
    if(m_fileData->working())
        m_fileData->appendBytes(data,len);
}

QString ImageReceiver::savePath() const
{
    return m_savePath;
}

void ImageReceiver::setSavePath(const QString &newSavePath)
{
    if (m_savePath == newSavePath)
        return;
    m_savePath = newSavePath;
    emit savePathChanged();
}
