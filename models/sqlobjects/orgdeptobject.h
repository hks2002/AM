#ifndef ORGDEPTOBJECT_H
#define ORGDEPTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OrgDeptObject : public TSqlObject, public QSharedData
{
public:
    int dept_id {0};
    int org_id {0};
    bool primary_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        DeptId = 0,
        OrgId,
        PrimaryBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<DeptId<<OrgId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<OrgId<<DeptId; }
    QString tableName() const override { return QLatin1String("org_dept"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int dept_id READ getdept_id WRITE setdept_id)
    T_DEFINE_PROPERTY(int, dept_id)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(bool primary_bool READ getprimary_bool WRITE setprimary_bool)
    T_DEFINE_PROPERTY(bool, primary_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ORGDEPTOBJECT_H
