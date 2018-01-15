#ifndef SCHEDSTASKOBJECT_H
#define SCHEDSTASKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedStaskObject : public TSqlObject, public QSharedData
{
public:
    int sched_id {0};
    int h_sched_id {0};
    int task_id {0};
    int part_no_id {0};
    QString task_class_cd;
    int task_subclass_id {0};
    int task_originator_id {0};
    QString task_ref_desc;
    int inv_no_id {0};
    QString task_name;
    QString task_desc;
    QString instruction_desc;
    QString operation_restriction;
    QString engineering_desc;
    QString barcode_desc;
    QString est_duration_qt;
    QString nr_mult_qt;
    QString first_sched_from_cd;
    QString cancel_when_cd;
    QString resched_from_cd;
    QDateTime plan_by_dt;
    QString warranty_note;
    int wo_commit_line_ord {0};
    int account_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedId = 0,
        HSchedId,
        TaskId,
        PartNoId,
        TaskClassCd,
        TaskSubclassId,
        TaskOriginatorId,
        TaskRefDesc,
        InvNoId,
        TaskName,
        TaskDesc,
        InstructionDesc,
        OperationRestriction,
        EngineeringDesc,
        BarcodeDesc,
        EstDurationQt,
        NrMultQt,
        FirstSchedFromCd,
        CancelWhenCd,
        ReschedFromCd,
        PlanByDt,
        WarrantyNote,
        WoCommitLineOrd,
        AccountId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedId; }
    int autoValueIndex() const override { return SchedId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AccountId<<ReschedFromCd<<CancelWhenCd<<FirstSchedFromCd<<InvNoId<<TaskOriginatorId<<TaskSubclassId<<TaskClassCd<<PartNoId<<TaskId<<HSchedId; }
    QString tableName() const override { return QLatin1String("sched_stask"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int h_sched_id READ geth_sched_id WRITE seth_sched_id)
    T_DEFINE_PROPERTY(int, h_sched_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString task_class_cd READ gettask_class_cd WRITE settask_class_cd)
    T_DEFINE_PROPERTY(QString, task_class_cd)
    Q_PROPERTY(int task_subclass_id READ gettask_subclass_id WRITE settask_subclass_id)
    T_DEFINE_PROPERTY(int, task_subclass_id)
    Q_PROPERTY(int task_originator_id READ gettask_originator_id WRITE settask_originator_id)
    T_DEFINE_PROPERTY(int, task_originator_id)
    Q_PROPERTY(QString task_ref_desc READ gettask_ref_desc WRITE settask_ref_desc)
    T_DEFINE_PROPERTY(QString, task_ref_desc)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QString task_name READ gettask_name WRITE settask_name)
    T_DEFINE_PROPERTY(QString, task_name)
    Q_PROPERTY(QString task_desc READ gettask_desc WRITE settask_desc)
    T_DEFINE_PROPERTY(QString, task_desc)
    Q_PROPERTY(QString instruction_desc READ getinstruction_desc WRITE setinstruction_desc)
    T_DEFINE_PROPERTY(QString, instruction_desc)
    Q_PROPERTY(QString operation_restriction READ getoperation_restriction WRITE setoperation_restriction)
    T_DEFINE_PROPERTY(QString, operation_restriction)
    Q_PROPERTY(QString engineering_desc READ getengineering_desc WRITE setengineering_desc)
    T_DEFINE_PROPERTY(QString, engineering_desc)
    Q_PROPERTY(QString barcode_desc READ getbarcode_desc WRITE setbarcode_desc)
    T_DEFINE_PROPERTY(QString, barcode_desc)
    Q_PROPERTY(QString est_duration_qt READ getest_duration_qt WRITE setest_duration_qt)
    T_DEFINE_PROPERTY(QString, est_duration_qt)
    Q_PROPERTY(QString nr_mult_qt READ getnr_mult_qt WRITE setnr_mult_qt)
    T_DEFINE_PROPERTY(QString, nr_mult_qt)
    Q_PROPERTY(QString first_sched_from_cd READ getfirst_sched_from_cd WRITE setfirst_sched_from_cd)
    T_DEFINE_PROPERTY(QString, first_sched_from_cd)
    Q_PROPERTY(QString cancel_when_cd READ getcancel_when_cd WRITE setcancel_when_cd)
    T_DEFINE_PROPERTY(QString, cancel_when_cd)
    Q_PROPERTY(QString resched_from_cd READ getresched_from_cd WRITE setresched_from_cd)
    T_DEFINE_PROPERTY(QString, resched_from_cd)
    Q_PROPERTY(QDateTime plan_by_dt READ getplan_by_dt WRITE setplan_by_dt)
    T_DEFINE_PROPERTY(QDateTime, plan_by_dt)
    Q_PROPERTY(QString warranty_note READ getwarranty_note WRITE setwarranty_note)
    T_DEFINE_PROPERTY(QString, warranty_note)
    Q_PROPERTY(int wo_commit_line_ord READ getwo_commit_line_ord WRITE setwo_commit_line_ord)
    T_DEFINE_PROPERTY(int, wo_commit_line_ord)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // SCHEDSTASKOBJECT_H
