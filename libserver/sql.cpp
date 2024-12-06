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

QVariantList Sql::getAllBooks()
{
    QVariantList bookList;
    QSqlQuery query("SELECT * FROM books", db);
    while (query.next()) {
        QStringList book;
        book << query.value("id").toString();
        book << query.value("name").toString();
        book << query.value("author").toString();
        book << query.value("book_id").toString();
        book << query.value("pages").toString();
        book << query.value("type").toString();
        book << query.value("language").toString();
        book << query.value("price").toString();
        book << query.value("status").toString();
        bookList.append(book);
    }
    return bookList;
}

bool Sql::removeBook(QString bookId)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM books WHERE book_id = :book_id");
    query.bindValue(":book_id", bookId);

    if (!query.exec()) {
        qDebug() << "Failed to delete book:" << query.lastError();
        return false;
    }
    return true;
}

