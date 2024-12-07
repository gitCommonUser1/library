#ifndef STATE_H
#define STATE_H

#include <QObject>
#include <QVariantMap>

class State : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList userIdRank READ userIdRank WRITE setUserIdRank NOTIFY userIdRankChanged FINAL)

public:
    explicit State(QObject *parent = nullptr);

    void appendUserId(QString userId);
    void appendBookId(QString bookId);

    void calcUserIdRank();
    void calcBookIdRank();


    QVariantList userIdRank() const;
    void setUserIdRank(const QVariantList &newUserIdRank);

private:

    QMap<QString, int> userIdMap;
    QMap<QString, int> bookIdMap;

    QVariantList m_userIdRank;

signals:
    void userIdRankChanged();
};

#endif // STATE_H
