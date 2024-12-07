#ifndef BORROWMODEL_H
#define BORROWMODEL_H

#include <QAbstractListModel>
#include <QObject>

class BorrowItem{
    Q_GADGET
    Q_PROPERTY(QString userId READ userId WRITE setUserId)
    Q_PROPERTY(QString bookId READ bookId WRITE setBookId)
    Q_PROPERTY(QString borrowDate READ borrowDate WRITE setBorrowDate)
    Q_PROPERTY(QString returnDate READ returnDate WRITE setReturnDate)
    Q_PROPERTY(QString borrowStatus READ borrowStatus WRITE setBorrowStatus)
public:
    BorrowItem(){

    }
    BorrowItem(const BorrowItem &) = default;
    BorrowItem(BorrowItem &&) = default;
    BorrowItem &operator=(const BorrowItem &) = default;
    BorrowItem &operator=(BorrowItem &&) = default;

    QString userId() const;
    void setUserId(const QString &newUserId);

    QString bookId() const;
    void setBookId(const QString &newBookId);

    QString borrowDate() const;
    void setBorrowDate(const QString &newBorrowDate);

    QString returnDate() const;
    void setReturnDate(const QString &newReturnDate);

    QString borrowStatus() const;
    void setBorrowStatus(const QString &newBorrowStatus);

private:

    QString m_userId;
    QString m_bookId;
    QString m_borrowDate;
    QString m_returnDate;
    QString m_borrowStatus;
};
Q_DECLARE_METATYPE(BorrowItem)


class BorrowModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ItemRoles{
        TypeUserId = Qt::UserRole + 100,
        TypeBookId,
        TypeBorrowDate,
        TypeReturnDate,
        TypeBorrowStatus
    };
    explicit BorrowModel(QObject *parent = nullptr);

    void returnBookByBookId(QString bookId,QString returnDate);

    int rowCount(const QModelIndex & parent = QModelIndex())const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    //item操作
    void appendItem(const BorrowItem& item);
    void insertItem(const BorrowItem& item,int index);
    void removeItem(int index);
    void changeItem(const BorrowItem& item,int index);

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<BorrowItem> m_items;

signals:

};

#endif // BORROWMODEL_H
