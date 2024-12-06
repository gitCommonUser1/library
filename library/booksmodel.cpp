#include "booksmodel.h"

BooksModel::BooksModel(QObject *parent)
{

}

int BooksModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant BooksModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_items.count())
        return QVariant();
    MenuItem item = m_items[index.row()];
    if (role == BooksModel::TypeName)
        return item.name();
    else if(role == BooksModel::TypeAuthor)
        return item.author();
    else if(role == BooksModel::TypeBookId)
        return item.bookId();
    else if(role == BooksModel::TypePages)
        return item.pages();
    else if(role == BooksModel::TypePrice)
        return item.price();
    return QVariant();
}

void BooksModel::init(QList<MenuItem> items)
{
    m_items = items;
    for(int i = 0;i < m_items.size();++i)
    {
        appendItem(m_items[i]);
    }
}

void BooksModel::removeOneByBookId(QString bookId)
{
    for(int i = 0;i < m_items.size();++i)
    {
        if(m_items[i].bookId() == bookId){
            removeItem(i);
            return ;
        }
    }
}

QHash<int, QByteArray> BooksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BooksModel::TypeName] = "modelName";
    roles[BooksModel::TypeAuthor] = "modelAuthor";
    roles[BooksModel::TypeBookId] = "modelBookId";
    roles[BooksModel::TypePages] = "modelPages";
    roles[BooksModel::TypePrice] = "modelPrice";
    return roles;
}

void BooksModel::appendItem(const MenuItem &item)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_items << item;
    endInsertRows();
}

void BooksModel::insertItem(const MenuItem &item, int index)
{
    beginInsertRows(QModelIndex(),index,index);
    m_items.insert(index,item);
    endInsertRows();
}

void BooksModel::removeItem(int index)
{
    beginRemoveRows(QModelIndex(),index,index);
    m_items.removeAt(index);
    endRemoveRows();
}

void BooksModel::changeItem(const MenuItem &item, int ind)
{
    m_items[ind] = item;
    dataChanged(index(ind,0),index(ind,0));
}
