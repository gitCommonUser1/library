#ifndef BOOKSMODEL_H
#define BOOKSMODEL_H

#include <QAbstractListModel>
#include <QObject>


class BookItem{
    Q_GADGET
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString author READ author WRITE setAuthor)
    Q_PROPERTY(QString bookId READ bookId WRITE setBookId)
    Q_PROPERTY(int pages READ pages WRITE setPages)
    Q_PROPERTY(double price READ price WRITE setPrice)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(QString language READ language WRITE setLanguage)
public:
    BookItem(){

    }
    BookItem(const BookItem &) = default;
    BookItem(BookItem &&) = default;
    BookItem &operator=(const BookItem &) = default;
    BookItem &operator=(BookItem &&) = default;

    QString author() const{
        return m_author;
    }
    void setAuthor(const QString &newAuthor){
        if(newAuthor != m_author)
            m_author = newAuthor;
    }
    QString name() const{
        return m_name;
    }
    void setName(const QString &newName){
        if(newName != m_name)
            m_name = newName;
    }
    QString bookId() const{
        return m_bookId;
    }
    void setBookId(const QString &newBookId){
        if(newBookId != m_bookId)
            m_bookId = newBookId;
    }
    int pages() const{
        return m_pages;
    }
    void setPages(const int &newPages){
        if(newPages != m_pages)
            m_pages = newPages;
    }
    double price() const{
        return m_price;
    }
    void setPrice(const double &newPrice){
        if(newPrice != m_price)
            m_price = newPrice;
    }
    QString type() const{
        return m_type;
    }
    void setType(const QString &newType){
        if(newType != m_type)
            m_type = newType;
    }
    QString language() const{
        return m_language;
    }
    void setLanguage(const QString &newLanguage){
        if(newLanguage != m_language)
            m_language = newLanguage;
    }

private:
    QString m_author;
    QString m_name;
    QString m_bookId;
    int m_pages;
    double m_price;
    QString m_type;
    QString m_language;

};
Q_DECLARE_METATYPE(BookItem)

class BooksModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ItemRoles{
        TypeName = Qt::UserRole + 100,
        TypeAuthor,
        TypeBookId,
        TypePages,
        TypePrice
    };
    explicit BooksModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & parent = QModelIndex())const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void removeOneByBookId(QString bookId);

    //item操作
    void appendItem(const BookItem& item);
    void insertItem(const BookItem& item,int index);
    void removeItem(int index);
    void changeItem(const BookItem& item,int index);

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<BookItem> m_items;

signals:

};

#endif // BOOKSMODEL_H
