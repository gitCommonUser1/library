#ifndef BOOKSMODEL_H
#define BOOKSMODEL_H

#include <QAbstractListModel>
#include <QObject>


class MenuItem{
    Q_GADGET
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString author READ author WRITE setAuthor)
    Q_PROPERTY(QString bookId READ bookId WRITE setBookId)
    Q_PROPERTY(int pages READ pages WRITE setPages)
    Q_PROPERTY(QString price READ price WRITE setPrice)
    Q_PROPERTY(QString type READ type WRITE setType)
    Q_PROPERTY(QString language READ language WRITE setLanguage)
    Q_PROPERTY(int status READ status WRITE setStatus)
public:
    MenuItem(){

    }
    MenuItem(const MenuItem &) = default;
    MenuItem(MenuItem &&) = default;
    MenuItem &operator=(const MenuItem &) = default;
    MenuItem &operator=(MenuItem &&) = default;

    int id() const{
        return m_id;
    }
    void setId(const int &newId){
        if(newId != m_id)
            m_id = newId;
    }
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
    QString price() const{
        return m_price;
    }
    void setPrice(const QString &newPrice){
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
    int status() const{
        return m_status;
    }
    void setStatus(const int &newStatus){
        if(newStatus != m_status)
            m_status = newStatus;
    }

private:
    int m_id;
    QString m_author;
    QString m_name;
    QString m_bookId;
    int m_pages;
    QString m_price;
    QString m_type;
    QString m_language;
    int m_status;

};
Q_DECLARE_METATYPE(MenuItem)

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

    void init(QList<MenuItem> items);
    void removeOneByBookId(QString bookId);

    //item操作
    void appendItem(const MenuItem& item);
    void insertItem(const MenuItem& item,int index);
    void removeItem(int index);
    void changeItem(const MenuItem& item,int index);

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<MenuItem> m_items;

signals:

};

#endif // BOOKSMODEL_H
