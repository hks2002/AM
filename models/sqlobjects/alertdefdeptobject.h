#ifndef ALERTDEFDEPTOBJECT_H
#define ALERTDEFDEPTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AlertDefDeptObject : public TSqlObject, public QSharedData
{
public:
    int alert_def_id {0};
    int dept_id {0};
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AlertDefId = 0,
        DeptId,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AlertDefId<<DeptId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<DeptId<<AlertDefId; }
    QString tableName() const override { return QLatin1String("alert_def_dept"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int alert_def_id READ getalert_def_id WRITE setalert_def_id)
    T_DEFINE_PROPERTY(int, alert_def_id)
    Q_PROPERTY(int dept_id READ getdept_id WRITE setdept_id)
    T_DEFINE_PROPERTY(int, dept_id)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ALERTDEFDEPTOBJECT_H
