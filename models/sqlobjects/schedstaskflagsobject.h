#ifndef SCHEDSTASKFLAGSOBJECT_H
#define SCHEDSTASKFLAGSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedStaskFlagsObject : public TSqlObject, public QSharedData
{
public:
    int sched_id {0};
    bool prevent_exe_bool;
    QDateTime prevent_exe_review_dt;
    bool etops_bool;
    bool rvsm_bool;
    bool recur_bool;
    bool corr_fix_bool;
    bool orphan_frct_bool;
    bool parts_ready_bool;
    bool soft_deadline_bool;
    bool routine_bool;
    bool request_parts_bool;
    bool resource_sum_bool;
    bool tools_ready_bool;
    bool task_lock_bool;
    bool manual_sched_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedId = 0,
        PreventExeBool,
        PreventExeReviewDt,
        EtopsBool,
        RvsmBool,
        RecurBool,
        CorrFixBool,
        OrphanFrctBool,
        PartsReadyBool,
        SoftDeadlineBool,
        RoutineBool,
        RequestPartsBool,
        ResourceSumBool,
        ToolsReadyBool,
        TaskLockBool,
        ManualSchedBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_stask_flags"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(bool prevent_exe_bool READ getprevent_exe_bool WRITE setprevent_exe_bool)
    T_DEFINE_PROPERTY(bool, prevent_exe_bool)
    Q_PROPERTY(QDateTime prevent_exe_review_dt READ getprevent_exe_review_dt WRITE setprevent_exe_review_dt)
    T_DEFINE_PROPERTY(QDateTime, prevent_exe_review_dt)
    Q_PROPERTY(bool etops_bool READ getetops_bool WRITE setetops_bool)
    T_DEFINE_PROPERTY(bool, etops_bool)
    Q_PROPERTY(bool rvsm_bool READ getrvsm_bool WRITE setrvsm_bool)
    T_DEFINE_PROPERTY(bool, rvsm_bool)
    Q_PROPERTY(bool recur_bool READ getrecur_bool WRITE setrecur_bool)
    T_DEFINE_PROPERTY(bool, recur_bool)
    Q_PROPERTY(bool corr_fix_bool READ getcorr_fix_bool WRITE setcorr_fix_bool)
    T_DEFINE_PROPERTY(bool, corr_fix_bool)
    Q_PROPERTY(bool orphan_frct_bool READ getorphan_frct_bool WRITE setorphan_frct_bool)
    T_DEFINE_PROPERTY(bool, orphan_frct_bool)
    Q_PROPERTY(bool parts_ready_bool READ getparts_ready_bool WRITE setparts_ready_bool)
    T_DEFINE_PROPERTY(bool, parts_ready_bool)
    Q_PROPERTY(bool soft_deadline_bool READ getsoft_deadline_bool WRITE setsoft_deadline_bool)
    T_DEFINE_PROPERTY(bool, soft_deadline_bool)
    Q_PROPERTY(bool routine_bool READ getroutine_bool WRITE setroutine_bool)
    T_DEFINE_PROPERTY(bool, routine_bool)
    Q_PROPERTY(bool request_parts_bool READ getrequest_parts_bool WRITE setrequest_parts_bool)
    T_DEFINE_PROPERTY(bool, request_parts_bool)
    Q_PROPERTY(bool resource_sum_bool READ getresource_sum_bool WRITE setresource_sum_bool)
    T_DEFINE_PROPERTY(bool, resource_sum_bool)
    Q_PROPERTY(bool tools_ready_bool READ gettools_ready_bool WRITE settools_ready_bool)
    T_DEFINE_PROPERTY(bool, tools_ready_bool)
    Q_PROPERTY(bool task_lock_bool READ gettask_lock_bool WRITE settask_lock_bool)
    T_DEFINE_PROPERTY(bool, task_lock_bool)
    Q_PROPERTY(bool manual_sched_bool READ getmanual_sched_bool WRITE setmanual_sched_bool)
    T_DEFINE_PROPERTY(bool, manual_sched_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDSTASKFLAGSOBJECT_H
