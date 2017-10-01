#ifndef USERAUTHORITYOBJECT_H
#define USERAUTHORITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserAuthorityObject : public TSqlObject, public QSharedData
{
public:
    int user_id {0};
    int authority_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserId = 0,
        AuthorityId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserId<<AuthorityId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AuthorityId<<UserId; }
    QString tableName() const override { return QLatin1String("user_authority"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int authority_id READ getauthority_id WRITE setauthority_id)
    T_DEFINE_PROPERTY(int, authority_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // USERAUTHORITYOBJECT_H
