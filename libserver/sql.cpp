#include "sql.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

Sql:: Sql(QObject *parent) : QObject(parent)
{

}

Sql::~Sql()
{
    db.close();
}

bool Sql::connect(QString host, int port, QString username, QString password, QString database)
{
    db.setHostName(host);
    db.setPort(port);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName(database);

    if(db.open()==false){
        qDebug()<< db.lastError().text();
        return false;
    }else{
        qDebug()<<"connect database success!!";
        return true;
    }
}

bool Sql::signIn(const QString &userName, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", userName);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        return false;
    }
    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
}

