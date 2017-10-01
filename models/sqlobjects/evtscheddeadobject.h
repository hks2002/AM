#ifndef EVTSCHEDDEADOBJECT_H
#define EVTSCHEDDEADOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtSchedDeadObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    int data_type_id {0};
    double sched_dead_qt {0};
    QDateTime sched_dead_dt;
    QDateTime sched_dead_dt_last_updated;
    QString sched_from_cd;
    double start_qt {0};
    QDateTime start_dt;
    double usage_rem_qt {0};
    bool sched_driver_bool;
    double deviation_qt {0};
    double interval_qt {0};
    double prefixed_qt {0};
    double postfixed_qt {0};
    double notify_qt {0};
    double min_plan_qt {0};
    bool postfixed_mand_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        DataTypeId,
        SchedDeadQt,
        SchedDeadDt,
        SchedDeadDtLastUpdated,
        SchedFromCd,
        StartQt,
        StartDt,
        UsageRemQt,
        SchedDriverBool,
        DeviationQt,
        IntervalQt,
        PrefixedQt,
        PostfixedQt,
        NotifyQt,
        MinPlanQt,
        PostfixedMandBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId<<DataTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<DataTypeId<<EventId; }
    QString tableName() const override { return QLatin1String("evt_sched_dead"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(double sched_dead_qt READ getsched_dead_qt WRITE setsched_dead_qt)
    T_DEFINE_PROPERTY(double, sched_dead_qt)
    Q_PROPERTY(QDateTime sched_dead_dt READ getsched_dead_dt WRITE setsched_dead_dt)
    T_DEFINE_PROPERTY(QDateTime, sched_dead_dt)
    Q_PROPERTY(QDateTime sched_dead_dt_last_updated READ getsched_dead_dt_last_updated WRITE setsched_dead_dt_last_updated)
    T_DEFINE_PROPERTY(QDateTime, sched_dead_dt_last_updated)
    Q_PROPERTY(QString sched_from_cd READ getsched_from_cd WRITE setsched_from_cd)
    T_DEFINE_PROPERTY(QString, sched_from_cd)
    Q_PROPERTY(double start_qt READ getstart_qt WRITE setstart_qt)
    T_DEFINE_PROPERTY(double, start_qt)
    Q_PROPERTY(QDateTime start_dt READ getstart_dt WRITE setstart_dt)
    T_DEFINE_PROPERTY(QDateTime, start_dt)
    Q_PROPERTY(double usage_rem_qt READ getusage_rem_qt WRITE setusage_rem_qt)
    T_DEFINE_PROPERTY(double, usage_rem_qt)
    Q_PROPERTY(bool sched_driver_bool READ getsched_driver_bool WRITE setsched_driver_bool)
    T_DEFINE_PROPERTY(bool, sched_driver_bool)
    Q_PROPERTY(double deviation_qt READ getdeviation_qt WRITE setdeviation_qt)
    T_DEFINE_PROPERTY(double, deviation_qt)
    Q_PROPERTY(double interval_qt READ getinterval_qt WRITE setinterval_qt)
    T_DEFINE_PROPERTY(double, interval_qt)
    Q_PROPERTY(double prefixed_qt READ getprefixed_qt WRITE setprefixed_qt)
    T_DEFINE_PROPERTY(double, prefixed_qt)
    Q_PROPERTY(double postfixed_qt READ getpostfixed_qt WRITE setpostfixed_qt)
    T_DEFINE_PROPERTY(double, postfixed_qt)
    Q_PROPERTY(double notify_qt READ getnotify_qt WRITE setnotify_qt)
    T_DEFINE_PROPERTY(double, notify_qt)
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

#endif // EVTSCHEDDEADOBJECT_H
