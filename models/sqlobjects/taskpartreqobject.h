#ifndef TASKPARTREQOBJECT_H
#define TASKPARTREQOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskPartReqObject : public TSqlObject, public QSharedData
{
public:
    int task_part_req_id {0};
    int task_id {0};
    int assmbl_id {0};
    int assmbl_bom_id {0};
    int assmbl_bom_pos_id {0};
    int part_no_id {0};
    QString req_action_cd;
    int req_qt {0};
    QString req_note;
    int qty_unit_id {0};
    bool remove_bool;
    QString remove_reason_cd;
    bool install_bool;
    QString req_priority_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskPartReqId = 0,
        TaskId,
        AssmblId,
        AssmblBomId,
        AssmblBomPosId,
        PartNoId,
        ReqActionCd,
        ReqQt,
        ReqNote,
        QtyUnitId,
        RemoveBool,
        RemoveReasonCd,
        InstallBool,
        ReqPriorityCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskPartReqId; }
    int autoValueIndex() const override { return TaskPartReqId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ReqPriorityCd<<RemoveReasonCd<<QtyUnitId<<ReqActionCd<<PartNoId<<AssmblBomPosId<<AssmblBomId<<AssmblId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_part_req"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_part_req_id READ gettask_part_req_id WRITE settask_part_req_id)
    T_DEFINE_PROPERTY(int, task_part_req_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int assmbl_bom_pos_id READ getassmbl_bom_pos_id WRITE setassmbl_bom_pos_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_pos_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString req_action_cd READ getreq_action_cd WRITE setreq_action_cd)
    T_DEFINE_PROPERTY(QString, req_action_cd)
    Q_PROPERTY(int req_qt READ getreq_qt WRITE setreq_qt)
    T_DEFINE_PROPERTY(int, req_qt)
    Q_PROPERTY(QString req_note READ getreq_note WRITE setreq_note)
    T_DEFINE_PROPERTY(QString, req_note)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(bool remove_bool READ getremove_bool WRITE setremove_bool)
    T_DEFINE_PROPERTY(bool, remove_bool)
    Q_PROPERTY(QString remove_reason_cd READ getremove_reason_cd WRITE setremove_reason_cd)
    T_DEFINE_PROPERTY(QString, remove_reason_cd)
    Q_PROPERTY(bool install_bool READ getinstall_bool WRITE setinstall_bool)
    T_DEFINE_PROPERTY(bool, install_bool)
    Q_PROPERTY(QString req_priority_cd READ getreq_priority_cd WRITE setreq_priority_cd)
    T_DEFINE_PROPERTY(QString, req_priority_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKPARTREQOBJECT_H
