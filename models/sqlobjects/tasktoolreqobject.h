#ifndef TASKTOOLREQOBJECT_H
#define TASKTOOLREQOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskToolReqObject : public TSqlObject, public QSharedData
{
public:
    int task_tool_req_id {0};
    int task_id {0};
    int assmbl_id {0};
    int assmbl_bom_id {0};
    int part_no_id {0};
    QString req_note;
    int req_qt {0};
    QString sched_usetime;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskToolReqId = 0,
        TaskId,
        AssmblId,
        AssmblBomId,
        PartNoId,
        ReqNote,
        ReqQt,
        SchedUsetime,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskToolReqId; }
    int autoValueIndex() const override { return TaskToolReqId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<AssmblBomId<<AssmblId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_tool_req"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_tool_req_id READ gettask_tool_req_id WRITE settask_tool_req_id)
    T_DEFINE_PROPERTY(int, task_tool_req_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString req_note READ getreq_note WRITE setreq_note)
    T_DEFINE_PROPERTY(QString, req_note)
    Q_PROPERTY(int req_qt READ getreq_qt WRITE setreq_qt)
    T_DEFINE_PROPERTY(int, req_qt)
    Q_PROPERTY(QString sched_usetime READ getsched_usetime WRITE setsched_usetime)
    T_DEFINE_PROPERTY(QString, sched_usetime)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKTOOLREQOBJECT_H
