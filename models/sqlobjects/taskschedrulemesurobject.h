#ifndef TASKSCHEDRULEMESUROBJECT_H
#define TASKSCHEDRULEMESUROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskSchedRuleMesurObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int data_type_id {0};
    int mesur_unit_id {0};
    int mesur_form_qt {0};
    int mesur_to_qt {0};
    double deviation_qt {0};
    double initial_qt {0};
    double interval_qt {0};
    double notify_qt {0};
    double prefixed_qt {0};
    double postfixed_qt {0};
    double min_plan_qt {0};
    bool postfixed_mand_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        DataTypeId,
        MesurUnitId,
        MesurFormQt,
        MesurToQt,
        DeviationQt,
        InitialQt,
        IntervalQt,
        NotifyQt,
        PrefixedQt,
        PostfixedQt,
        MinPlanQt,
        PostfixedMandBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<DataTypeId<<MesurUnitId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<MesurUnitId<<DataTypeId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_sched_rule_mesur"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(int mesur_unit_id READ getmesur_unit_id WRITE setmesur_unit_id)
    T_DEFINE_PROPERTY(int, mesur_unit_id)
    Q_PROPERTY(int mesur_form_qt READ getmesur_form_qt WRITE setmesur_form_qt)
    T_DEFINE_PROPERTY(int, mesur_form_qt)
    Q_PROPERTY(int mesur_to_qt READ getmesur_to_qt WRITE setmesur_to_qt)
    T_DEFINE_PROPERTY(int, mesur_to_qt)
    Q_PROPERTY(double deviation_qt READ getdeviation_qt WRITE setdeviation_qt)
    T_DEFINE_PROPERTY(double, deviation_qt)
    Q_PROPERTY(double initial_qt READ getinitial_qt WRITE setinitial_qt)
    T_DEFINE_PROPERTY(double, initial_qt)
    Q_PROPERTY(double interval_qt READ getinterval_qt WRITE setinterval_qt)
    T_DEFINE_PROPERTY(double, interval_qt)
    Q_PROPERTY(double notify_qt READ getnotify_qt WRITE setnotify_qt)
    T_DEFINE_PROPERTY(double, notify_qt)
    Q_PROPERTY(double prefixed_qt READ getprefixed_qt WRITE setprefixed_qt)
    T_DEFINE_PROPERTY(double, prefixed_qt)
    Q_PROPERTY(double postfixed_qt READ getpostfixed_qt WRITE setpostfixed_qt)
    T_DEFINE_PROPERTY(double, postfixed_qt)
    Q_PROPERTY(double min_plan_qt READ getmin_plan_qt WRITE setmin_plan_qt)
    T_DEFINE_PROPERTY(double, min_plan_qt)
    Q_PROPERTY(bool postfixed_mand_bool READ getpostfixed_mand_bool WRITE setpostfixed_mand_bool)
    T_DEFINE_PROPERTY(bool, postfixed_mand_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKSCHEDRULEMESUROBJECT_H
