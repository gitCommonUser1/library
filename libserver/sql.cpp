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
    if(userName.isEmpty() || password.isEmpty())
        return false;
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
        book << query.value("name").toString();
        book << query.value("author").toString();
        book << query.value("book_id").toString();
        book << query.value("pages").toString();
        book << query.value("type").toString();
        book << query.value("language").toString();
        book << query.value("price").toString();
        bookList.append(book);
    }
    return bookList;
}

bool Sql::removeBook(QString bookId)
{
    if (bookId.isEmpty()) {
        qDebug() << "Book ID cannot be empty!";
        return false;
    }

    // 检查这本书是否已经借出
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM borrow WHERE book_id = :book_id AND borrow_status = 'borrowed'");
    checkQuery.bindValue(":book_id", bookId);

    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Failed to check borrow status:" << checkQuery.lastError();
        return false;
    }

    if (checkQuery.value(0).toInt() > 0) {
        qDebug() << "Cannot delete book. It has been borrowed.";
        return false;
    }
    QSqlQuery query(db);
    query.prepare("DELETE FROM books WHERE book_id = :book_id");
    query.bindValue(":book_id", bookId);

    if (!query.exec()) {
        qDebug() << "Failed to delete book:" << query.lastError();
        return false;
    }
    return true;
}

bool Sql::addBook(QString name, QString bookid, QString auname, int pages, double price, QString type, QString language)
{
    if(name == "" || bookid == "" || auname == "" || type == "" || language == "")
        return false;
    QSqlQuery query(db);
    query.prepare("INSERT INTO books (name, book_id, author, pages, price, type, language) "
                  "VALUES (:name, :book_id, :author, :pages, :price, :type, :language)");
    query.bindValue(":name", name);
    query.bindValue(":book_id", bookid);
    query.bindValue(":author", auname);
    query.bindValue(":pages", pages);
    query.bindValue(":price", price);
    query.bindValue(":type", type);
    query.bindValue(":language", language);

    if (!query.exec()) {
        qDebug() << "Failed to insert book:" << query.lastError();
        return false;
    }

    return true;
}

QVariantList Sql::getAllBorrow()
{
    QVariantList bookList;
    QSqlQuery query("SELECT * FROM borrow", db);
    while (query.next()) {
        QStringList book;
        book << query.value("user_id").toString();
        book << query.value("book_id").toString();
        book << query.value("borrow_status").toString();
        book << query.value("borrow_date").toString();
        book << query.value("return_date").toString();
        bookList.append(book);
    }
    return bookList;
}

bool Sql::borrowBook(QString userId, QString bookId, QString date)
{
    if(userId.isEmpty() || bookId.isEmpty() || date.isEmpty())
        return false;
    // 检查这本书是否已经借出
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM borrow WHERE book_id = :book_id AND borrow_status = 'borrowed'");
    checkQuery.bindValue(":book_id", bookId);

    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Failed to check borrow status:" << checkQuery.lastError();
        return false;
    }

    if (checkQuery.value(0).toInt() > 0) {
        qDebug() << "Book is already borrowed!";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO borrow (user_id, book_id, borrow_status, borrow_date) "
                  "VALUES (:user_id, :book_id, 'borrowed', :borrow_date)");
    query.bindValue(":user_id", userId);
    query.bindValue(":book_id", bookId);
    query.bindValue(":borrow_date", date);
    if (!query.exec()) {
        qDebug() << "Failed to borrow book:" << query.lastError();
        return false;
    }
    return true;
}

bool Sql::returnBook(QString bookId, QString date)
{
    if(bookId.isEmpty() || date.isEmpty())
        return false;
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM borrow WHERE book_id = :book_id AND borrow_status = 'borrowed'");
    checkQuery.bindValue(":book_id", bookId);
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Failed to check borrow records:" << checkQuery.lastError();
        return false;
    }
    if (checkQuery.value(0).toInt() == 0) {
        qDebug() << "No borrowed record found for book ID:" << bookId;
        return false;
    }

    QSqlQuery query(db);
    query.prepare("UPDATE borrow "
                  "SET borrow_status = 'returned', return_date = :return_date "
                  "WHERE book_id = :book_id AND borrow_status = 'borrowed'");
    query.bindValue(":book_id", bookId);
    query.bindValue(":return_date", date);

    if (!query.exec()) {
        qDebug() << "Failed to return book:" << query.lastError();
        return false;
    }
    return true;
}

