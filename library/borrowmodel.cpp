#include "borrowmodel.h"
#include <QDebug>

QString BorrowItem::userId() const
{
    return m_userId;
}

void BorrowItem::setUserId(const QString &newUserId)
{
    m_userId = newUserId;
}

QString BorrowItem::bookId() const
{
    return m_bookId;
}

void BorrowItem::setBookId(const QString &newBookId)
{
    m_bookId = newBookId;
}

QString BorrowItem::borrowDate() const
{
    return m_borrowDate;
}

void BorrowItem::setBorrowDate(const QString &newBorrowDate)
{
    m_borrowDate = newBorrowDate;
}

QString BorrowItem::returnDate() const
{
    return m_returnDate;
}

void BorrowItem::setReturnDate(const QString &newReturnDate)
{
    m_returnDate = newReturnDate;
}

QString BorrowItem::borrowStatus() const
{
    return m_borrowStatus;
}

void BorrowItem::setBorrowStatus(const QString &newBorrowStatus)
{
    m_borrowStatus = newBorrowStatus;
}

BorrowModel::BorrowModel(QObject *parent)
{

}

void BorrowModel::returnBookByBookId(QString bookId,QString returnDate)
{
    for(int i = 0;i < m_items.size();++i)
    {
        auto item = m_items[i];
        if(item.bookId() == bookId){
            item.setBorrowStatus("returned");
            item.setReturnDate(returnDate);
            changeItem(item,i);
            break;
        }
    }
}

int BorrowModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant BorrowModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_items.count())
        return QVariant();
    BorrowItem item = m_items[index.row()];
    if (role == BorrowModel::TypeUserId)
        return item.userId();
    else if(role == BorrowModel::TypeBookId)
        return item.bookId();
    else if(role == BorrowModel::TypeBorrowDate)
        return item.borrowDate();
    else if(role == BorrowModel::TypeReturnDate)
        return item.returnDate();
    else if(role == BorrowModel::TypeBorrowStatus)
        return item.borrowStatus();
    return QVariant();
}

void BorrowModel::appendItem(const BorrowItem &item)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_items << item;
    endInsertRows();
}

void BorrowModel::insertItem(const BorrowItem &item, int index)
{
    beginInsertRows(QModelIndex(),index,index);
    m_items.insert(index,item);
    endInsertRows();
}

void BorrowModel::removeItem(int index)
{
    beginRemoveRows(QModelIndex(),index,index);
    m_items.removeAt(index);
    endRemoveRows();
}

void BorrowModel::changeItem(const BorrowItem &item, int ind)
{
    m_items[ind] = item;
    dataChanged(index(ind,0),index(ind,0));
}

QHash<int, QByteArray> BorrowModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BorrowModel::TypeUserId] = "modelUserId";
    roles[BorrowModel::TypeBookId] = "modelBookId";
    roles[BorrowModel::TypeBorrowDate] = "modelBorrowDate";
    roles[BorrowModel::TypeReturnDate] = "modelReturnDate";
    roles[BorrowModel::TypeBorrowStatus] = "modelBorrowStatus";
    return roles;
}
