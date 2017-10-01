#ifndef ORGSUBORGOBJECT_H
#define ORGSUBORGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OrgSuborgObject : public TSqlObject, public QSharedData
{
public:
    int org_id {0};
    int sub_org_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OrgId = 0,
        SubOrgId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OrgId<<SubOrgId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SubOrgId<<OrgId; }
    QString tableName() const override { return QLatin1String("org_suborg"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(int sub_org_id READ getsub_org_id WRITE setsub_org_id)
    T_DEFINE_PROPERTY(int, sub_org_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ORGSUBORGOBJECT_H
