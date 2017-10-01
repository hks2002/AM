#include <TreeFrogModel>
#include "tasktoolreq.h"
#include "tasktoolreqobject.h"
#include "eqppartno.h"
#include "eqpassmblbom.h"
#include "eqpassmbl.h"
#include "tasktask.h"

TaskToolReq::TaskToolReq()
    : TAbstractModel(), d(new TaskToolReqObject())
{
    d->task_tool_req_id = 0;
    d->task_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
    d->part_no_id = 0;
    d->req_qt = 0;
}

TaskToolReq::TaskToolReq(const TaskToolReq &other)
    : TAbstractModel(), d(new TaskToolReqObject(*other.d))
{ }

TaskToolReq::TaskToolReq(const TaskToolReqObject &object)
    : TAbstractModel(), d(new TaskToolReqObject(object))
{ }

TaskToolReq::~TaskToolReq()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskToolReqObject' is deleted.
}

int TaskToolReq::taskToolReqId() const
{
    return d->task_tool_req_id;
}

int TaskToolReq::taskId() const
{
    return d->task_id;
}

void TaskToolReq::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskToolReq::assmblId() const
{
    return d->assmbl_id;
}

void TaskToolReq::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int TaskToolReq::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void TaskToolReq::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int TaskToolReq::partNoId() const
{
    return d->part_no_id;
}

void TaskToolReq::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString TaskToolReq::reqNote() const
{
    return d->req_note;
}

void TaskToolReq::setReqNote(const QString &reqNote)
{
    d->req_note = reqNote;
}

int TaskToolReq::reqQt() const
{
    return d->req_qt;
}

void TaskToolReq::setReqQt(int reqQt)
{
    d->req_qt = reqQt;
}

QString TaskToolReq::schedUsetime() const
{
    return d->sched_usetime;
}

void TaskToolReq::setSchedUsetime(const QString &schedUsetime)
{
    d->sched_usetime = schedUsetime;
}

QDateTime TaskToolReq::createdAt() const
{
    return d->created_at;
}

QString TaskToolReq::createdBy() const
{
    return d->created_by;
}

void TaskToolReq::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskToolReq::updatedAt() const
{
    return d->updated_at;
}

QString TaskToolReq::updatedBy() const
{
    return d->updated_by;
}

void TaskToolReq::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo TaskToolReq::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBom TaskToolReq::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmbl TaskToolReq::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

TaskTask TaskToolReq::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskToolReq &TaskToolReq::operator=(const TaskToolReq &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskToolReq TaskToolReq::create(int taskId, int assmblId, int assmblBomId, int partNoId, const QString &reqNote, int reqQt, const QString &schedUsetime, const QString &createdBy, const QString &updatedBy)
{
    TaskToolReqObject obj;
    obj.task_id = taskId;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.part_no_id = partNoId;
    obj.req_note = reqNote;
    obj.req_qt = reqQt;
    obj.sched_usetime = schedUsetime;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskToolReq();
    }
    return TaskToolReq(obj);
}

TaskToolReq TaskToolReq::create(const QVariantMap &values)
{
    TaskToolReq model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskToolReq TaskToolReq::get(int taskToolReqId)
{
    TSqlORMapper<TaskToolReqObject> mapper;
    return TaskToolReq(mapper.findByPrimaryKey(taskToolReqId));
}

int TaskToolReq::count()
{
    TSqlORMapper<TaskToolReqObject> mapper;
    return mapper.findCount();
}

QList<TaskToolReq> TaskToolReq::getAll()
{
    return tfGetModelListByCriteria<TaskToolReq, TaskToolReqObject>();
}

TModelObject *TaskToolReq::modelData()
{
    return d.data();
}

const TModelObject *TaskToolReq::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskToolReq &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskToolReq &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskToolReq)
