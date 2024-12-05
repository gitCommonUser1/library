#ifndef SQL_H
#define SQL_H

#include <QObject>

class QSqlDatabase;

class Sql : public QObject
{
    Q_OBJECT
public:
    explicit Sql(QObject *parent = nullptr);
    ~Sql();
    bool connect(QString host,int port,QString username,QString password,QString database);

    bool signIn(const QString &userName, const QString &password);
private:

signals:

public slots:

};

#endif // SQL_H
