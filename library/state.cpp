#include "state.h"
#include <QDebug>

bool compareFrequency(const QPair<QString, int> &a, const QPair<QString, int> &b) { return a.second > b.second; }

State::State(QObject *parent)
    : QObject{parent}
{}

void State::appendUserId(QString userId)
{
    userIdMap[userId]++;
}

void State::appendBookId(QString bookId)
{
    bookIdMap[bookId]++;
}

void State::calcUserIdRank()
{
    // // 将 QMap 转换为 QList 以便排序
    // QList<QPair<QString, int>> list;

    // for (auto it = userIdMap.begin(); it != userIdMap.end(); ++it) {
    //     list.append(qMakePair(it.key(), it.value()));
    // }
    // // 排序
    // std::sort(list.begin(), list.end(), compareFrequency);

    // QVariantList vList;
    // // 输出排序结果
    // for (const QPair<QString, int> &pair : list) {
    //     qDebug() << pair.first << "->" << pair.second;
    //     vList  << pair;
    // }

    // setUserIdRank(list);
}

void State::calcBookIdRank()
{

}

QVariantList State::userIdRank() const
{
    return m_userIdRank;
}

void State::setUserIdRank(const QVariantList &newUserIdRank)
{
    if (m_userIdRank == newUserIdRank)
        return;
    m_userIdRank = newUserIdRank;
    emit userIdRankChanged();
}
