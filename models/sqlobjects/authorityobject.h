#ifndef AUTHORITYOBJECT_H
#define AUTHORITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AuthorityObject : public TSqlObject, public QSharedData
{
public:
    int authority_id {0};
    QString authority_cd;
    QString authority_name;
    QString authority_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AuthorityId = 0,
        AuthorityCd,
        AuthorityName,
        AuthorityDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AuthorityId; }
    int autoValueIndex() const override { return AuthorityId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("authority"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int authority_id READ getauthority_id WRITE setauthority_id)
    T_DEFINE_PROPERTY(int, authority_id)
    Q_PROPERTY(QString authority_cd READ getauthority_cd WRITE setauthority_cd)
    T_DEFINE_PROPERTY(QString, authority_cd)
    Q_PROPERTY(QString authority_name READ getauthority_name WRITE setauthority_name)
    T_DEFINE_PROPERTY(QString, authority_name)
    Q_PROPERTY(QString authority_desc READ getauthority_desc WRITE setauthority_desc)
    T_DEFINE_PROPERTY(QString, authority_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // AUTHORITYOBJECT_H
