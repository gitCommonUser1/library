#include "datetime.h"
#include <QDateTime>
#include <QLocale>
#include <QDebug>
#include <QTimer>

DateTime::DateTime(QObject *parent)
    : QObject{parent}
{
    QTimer *timer = new QTimer;
    connect(timer,&QTimer::timeout,this,[=](){
        QLocale locale = QLocale::English;
        setDate(locale.toString(QDateTime::currentDateTime(),QString("MMMM d,yyyy")));
        setTime(locale.toString(QDateTime::currentDateTime(),QString("h:mm AP")));
        setD(locale.toString(QDateTime::currentDateTime(),QString("d")));
        setM(m_date.left(3).toUpper());
        setDateTime(locale.toString(QDateTime::currentDateTime(),QString("yyyy-MM-dd-HH:mm")));
    });
    timer->start(1000);
}

QString DateTime::d() const
{
    return m_d;
}

void DateTime::setD(const QString &newD)
{
    if (m_d == newD)
        return;
    m_d = newD;
    emit dChanged();
}

QString DateTime::m() const
{
    return m_m;
}

void DateTime::setM(const QString &newM)
{
    if (m_m == newM)
        return;
    m_m = newM;
    emit mChanged();
}

QString DateTime::time() const
{
    return m_time;
}

void DateTime::setTime(const QString &newTime)
{
    if (m_time == newTime)
        return;
    m_time = newTime;
    emit timeChanged();
}

QString DateTime::date() const
{
    return m_date;
}

void DateTime::setDate(const QString &newDate)
{
    if (m_date == newDate)
        return;
    m_date = newDate;
    emit dateChanged();
}

QString DateTime::dateTime() const
{
    return m_dateTime;
}

void DateTime::setDateTime(const QString &newDateTime)
{
    if (m_dateTime == newDateTime)
        return;
    m_dateTime = newDateTime;
    emit dateTimeChanged();
}
