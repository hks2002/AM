#ifndef TASKTASKOBJECT_H
#define TASKTASKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskTaskObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int task_defn_id {0};
    QString task_def_status_cd;
    QString task_cd;
    QString task_name;
    QString task_ref_desc;
    QString task_desc;
    QString instruction_desc;
    QString engineering_desc;
    int task_originator_id {0};
    QString task_class_cd;
    int task_subclass_id {0};
    bool task_must_remove_cd;
    bool recur_bool;
    QString first_sched_from_cd;
    QString resched_from_cd;
    QString create_when_cd;
    QString cancel_when_cd;
    bool sched_from_latest_bool;
    bool last_sched_dead_bool;
    QDate effective_dt;
    QString est_duration_qt;
    QString task_appl_eff_desc;
    QString task_appl_desc;
    QString task_appl_sql_desc;
    int revision_ord {0};
    QString rev_note;
    int prepared_by {0};
    QDateTime prepared_dt;
    int reviewed_by {0};
    QDateTime reviewed_dt;
    int approved_by {0};
    QDateTime approved_dt;
    int actived_by {0};
    QDateTime actived_dt;
    int locked_by {0};
    QDateTime locked_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        TaskDefnId,
        TaskDefStatusCd,
        TaskCd,
        TaskName,
        TaskRefDesc,
        TaskDesc,
        InstructionDesc,
        EngineeringDesc,
        TaskOriginatorId,
        TaskClassCd,
        TaskSubclassId,
        TaskMustRemoveCd,
        RecurBool,
        FirstSchedFromCd,
        ReschedFromCd,
        CreateWhenCd,
        CancelWhenCd,
        SchedFromLatestBool,
        LastSchedDeadBool,
        EffectiveDt,
        EstDurationQt,
        TaskApplEffDesc,
        TaskApplDesc,
        TaskApplSqlDesc,
        RevisionOrd,
        RevNote,
        PreparedBy,
        PreparedDt,
        ReviewedBy,
        ReviewedDt,
        ApprovedBy,
        ApprovedDt,
        ActivedBy,
        ActivedDt,
        LockedBy,
        LockedDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId; }
    int autoValueIndex() const override { return TaskId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskDefnId<<TaskDefStatusCd<<TaskOriginatorId<<TaskClassCd<<TaskSubclassId<<FirstSchedFromCd<<ReschedFromCd<<CreateWhenCd<<CancelWhenCd<<PreparedBy<<ReviewedBy<<ApprovedBy<<ActivedBy<<LockedBy; }
    QString tableName() const override { return QLatin1String("task_task"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int task_defn_id READ gettask_defn_id WRITE settask_defn_id)
    T_DEFINE_PROPERTY(int, task_defn_id)
    Q_PROPERTY(QString task_def_status_cd READ gettask_def_status_cd WRITE settask_def_status_cd)
    T_DEFINE_PROPERTY(QString, task_def_status_cd)
    Q_PROPERTY(QString task_cd READ gettask_cd WRITE settask_cd)
    T_DEFINE_PROPERTY(QString, task_cd)
    Q_PROPERTY(QString task_name READ gettask_name WRITE settask_name)
    T_DEFINE_PROPERTY(QString, task_name)
    Q_PROPERTY(QString task_ref_desc READ gettask_ref_desc WRITE settask_ref_desc)
    T_DEFINE_PROPERTY(QString, task_ref_desc)
    Q_PROPERTY(QString task_desc READ gettask_desc WRITE settask_desc)
    T_DEFINE_PROPERTY(QString, task_desc)
    Q_PROPERTY(QString instruction_desc READ getinstruction_desc WRITE setinstruction_desc)
    T_DEFINE_PROPERTY(QString, instruction_desc)
    Q_PROPERTY(QString engineering_desc READ getengineering_desc WRITE setengineering_desc)
    T_DEFINE_PROPERTY(QString, engineering_desc)
    Q_PROPERTY(int task_originator_id READ gettask_originator_id WRITE settask_originator_id)
    T_DEFINE_PROPERTY(int, task_originator_id)
    Q_PROPERTY(QString task_class_cd READ gettask_class_cd WRITE settask_class_cd)
    T_DEFINE_PROPERTY(QString, task_class_cd)
    Q_PROPERTY(int task_subclass_id READ gettask_subclass_id WRITE settask_subclass_id)
    T_DEFINE_PROPERTY(int, task_subclass_id)
    Q_PROPERTY(bool task_must_remove_cd READ gettask_must_remove_cd WRITE settask_must_remove_cd)
    T_DEFINE_PROPERTY(bool, task_must_remove_cd)
    Q_PROPERTY(bool recur_bool READ getrecur_bool WRITE setrecur_bool)
    T_DEFINE_PROPERTY(bool, recur_bool)
    Q_PROPERTY(QString first_sched_from_cd READ getfirst_sched_from_cd WRITE setfirst_sched_from_cd)
    T_DEFINE_PROPERTY(QString, first_sched_from_cd)
    Q_PROPERTY(QString resched_from_cd READ getresched_from_cd WRITE setresched_from_cd)
    T_DEFINE_PROPERTY(QString, resched_from_cd)
    Q_PROPERTY(QString create_when_cd READ getcreate_when_cd WRITE setcreate_when_cd)
    T_DEFINE_PROPERTY(QString, create_when_cd)
    Q_PROPERTY(QString cancel_when_cd READ getcancel_when_cd WRITE setcancel_when_cd)
    T_DEFINE_PROPERTY(QString, cancel_when_cd)
    Q_PROPERTY(bool sched_from_latest_bool READ getsched_from_latest_bool WRITE setsched_from_latest_bool)
    T_DEFINE_PROPERTY(bool, sched_from_latest_bool)
    Q_PROPERTY(bool last_sched_dead_bool READ getlast_sched_dead_bool WRITE setlast_sched_dead_bool)
    T_DEFINE_PROPERTY(bool, last_sched_dead_bool)
    Q_PROPERTY(QDate effective_dt READ geteffective_dt WRITE seteffective_dt)
    T_DEFINE_PROPERTY(QDate, effective_dt)
    Q_PROPERTY(QString est_duration_qt READ getest_duration_qt WRITE setest_duration_qt)
    T_DEFINE_PROPERTY(QString, est_duration_qt)
    Q_PROPERTY(QString task_appl_eff_desc READ gettask_appl_eff_desc WRITE settask_appl_eff_desc)
    T_DEFINE_PROPERTY(QString, task_appl_eff_desc)
    Q_PROPERTY(QString task_appl_desc READ gettask_appl_desc WRITE settask_appl_desc)
    T_DEFINE_PROPERTY(QString, task_appl_desc)
    Q_PROPERTY(QString task_appl_sql_desc READ gettask_appl_sql_desc WRITE settask_appl_sql_desc)
    T_DEFINE_PROPERTY(QString, task_appl_sql_desc)
    Q_PROPERTY(int revision_ord READ getrevision_ord WRITE setrevision_ord)
    T_DEFINE_PROPERTY(int, revision_ord)
    Q_PROPERTY(QString rev_note READ getrev_note WRITE setrev_note)
    T_DEFINE_PROPERTY(QString, rev_note)
    Q_PROPERTY(int prepared_by READ getprepared_by WRITE setprepared_by)
    T_DEFINE_PROPERTY(int, prepared_by)
    Q_PROPERTY(QDateTime prepared_dt READ getprepared_dt WRITE setprepared_dt)
    T_DEFINE_PROPERTY(QDateTime, prepared_dt)
    Q_PROPERTY(int reviewed_by READ getreviewed_by WRITE setreviewed_by)
    T_DEFINE_PROPERTY(int, reviewed_by)
    Q_PROPERTY(QDateTime reviewed_dt READ getreviewed_dt WRITE setreviewed_dt)
    T_DEFINE_PROPERTY(QDateTime, reviewed_dt)
    Q_PROPERTY(int approved_by READ getapproved_by WRITE setapproved_by)
    T_DEFINE_PROPERTY(int, approved_by)
    Q_PROPERTY(QDateTime approved_dt READ getapproved_dt WRITE setapproved_dt)
    T_DEFINE_PROPERTY(QDateTime, approved_dt)
    Q_PROPERTY(int actived_by READ getactived_by WRITE setactived_by)
    T_DEFINE_PROPERTY(int, actived_by)
    Q_PROPERTY(QDateTime actived_dt READ getactived_dt WRITE setactived_dt)
    T_DEFINE_PROPERTY(QDateTime, actived_dt)
    Q_PROPERTY(int locked_by READ getlocked_by WRITE setlocked_by)
    T_DEFINE_PROPERTY(int, locked_by)
    Q_PROPERTY(QDateTime locked_dt READ getlocked_dt WRITE setlocked_dt)
    T_DEFINE_PROPERTY(QDateTime, locked_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKTASKOBJECT_H
