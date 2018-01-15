#ifndef TASKFLAGSOBJECT_H
#define TASKFLAGSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskFlagsObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    bool nsv_bool;
    bool prevent_exe_bool;
    QDateTime prevent_exe_review_dt;
    bool review_receipt_bool;
    bool rii_req_bool;
    bool routine_bool;
    bool etops_bool;
    bool rvsm_bool;
    bool soft_deadline_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        NsvBool,
        PreventExeBool,
        PreventExeReviewDt,
        ReviewReceiptBool,
        RiiReqBool,
        RoutineBool,
        EtopsBool,
        RvsmBool,
        SoftDeadlineBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskId; }
    QString tableName() const override { return QLatin1String("task_flags"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(bool nsv_bool READ getnsv_bool WRITE setnsv_bool)
    T_DEFINE_PROPERTY(bool, nsv_bool)
    Q_PROPERTY(bool prevent_exe_bool READ getprevent_exe_bool WRITE setprevent_exe_bool)
    T_DEFINE_PROPERTY(bool, prevent_exe_bool)
    Q_PROPERTY(QDateTime prevent_exe_review_dt READ getprevent_exe_review_dt WRITE setprevent_exe_review_dt)
    T_DEFINE_PROPERTY(QDateTime, prevent_exe_review_dt)
    Q_PROPERTY(bool review_receipt_bool READ getreview_receipt_bool WRITE setreview_receipt_bool)
    T_DEFINE_PROPERTY(bool, review_receipt_bool)
    Q_PROPERTY(bool rii_req_bool READ getrii_req_bool WRITE setrii_req_bool)
    T_DEFINE_PROPERTY(bool, rii_req_bool)
    Q_PROPERTY(bool routine_bool READ getroutine_bool WRITE setroutine_bool)
    T_DEFINE_PROPERTY(bool, routine_bool)
    Q_PROPERTY(bool etops_bool READ getetops_bool WRITE setetops_bool)
    T_DEFINE_PROPERTY(bool, etops_bool)
    Q_PROPERTY(bool rvsm_bool READ getrvsm_bool WRITE setrvsm_bool)
    T_DEFINE_PROPERTY(bool, rvsm_bool)
    Q_PROPERTY(bool soft_deadline_bool READ getsoft_deadline_bool WRITE setsoft_deadline_bool)
    T_DEFINE_PROPERTY(bool, soft_deadline_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKFLAGSOBJECT_H
