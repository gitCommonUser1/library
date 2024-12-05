#ifndef DATETIME_H
#define DATETIME_H

#include <QObject>

class DateTime : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString d READ d WRITE setD NOTIFY dChanged FINAL)
    Q_PROPERTY(QString m READ m WRITE setM NOTIFY mChanged FINAL)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged FINAL)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged FINAL)
public:
    explicit DateTime(QObject *parent = nullptr);

    QString d() const;
    void setD(const QString &newD);

    QString m() const;
    void setM(const QString &newM);

    QString time() const;
    void setTime(const QString &newTime);

    QString date() const;
    void setDate(const QString &newDate);

signals:
    void dChanged();
    void mChanged();

    void timeChanged();

    void dateChanged();

private:
    QString m_d;
    QString m_m;
    QString m_time;
    QString m_date;
};

#endif // DATETIME_H
