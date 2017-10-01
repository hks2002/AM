#ifndef EVTTOOLOBJECT_H
#define EVTTOOLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtToolObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    int sched_tool_id {0};
    int assmbl_bom_id {0};
    int part_no_id {0};
    int inv_no_id {0};
    int task_id {0};
    int task_tool_req_id {0};
    int sched_hr {0};
    int actual_hr {0};
    double tool_cost {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        SchedToolId,
        AssmblBomId,
        PartNoId,
        InvNoId,
        TaskId,
        TaskToolReqId,
        SchedHr,
        ActualHr,
        ToolCost,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId<<SchedToolId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskToolReqId<<TaskId<<InvNoId<<PartNoId<<AssmblBomId<<SchedToolId<<EventId; }
    QString tableName() const override { return QLatin1String("evt_tool"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int sched_tool_id READ getsched_tool_id WRITE setsched_tool_id)
    T_DEFINE_PROPERTY(int, sched_tool_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int task_tool_req_id READ gettask_tool_req_id WRITE settask_tool_req_id)
    T_DEFINE_PROPERTY(int, task_tool_req_id)
    Q_PROPERTY(int sched_hr READ getsched_hr WRITE setsched_hr)
    T_DEFINE_PROPERTY(int, sched_hr)
    Q_PROPERTY(int actual_hr READ getactual_hr WRITE setactual_hr)
    T_DEFINE_PROPERTY(int, actual_hr)
    Q_PROPERTY(double tool_cost READ gettool_cost WRITE settool_cost)
    T_DEFINE_PROPERTY(double, tool_cost)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EVTTOOLOBJECT_H
