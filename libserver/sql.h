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
    QVariantList getAllBooks();
    bool removeBook(QString bookId);
    bool addBook(QString name, QString bookid, QString auname, int pages, double price, QString type, QString language);
    QVariantList getAllBorrow();
    bool borrowBook(QString userId,QString bookId,QString date);
    bool returnBook(QString bookId,QString date);

private:

signals:

public slots:

};

#endif // SQL_H
