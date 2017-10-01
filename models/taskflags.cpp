#include <TreeFrogModel>
#include "taskflags.h"
#include "taskflagsobject.h"
#include "tasktask.h"

TaskFlags::TaskFlags()
    : TAbstractModel(), d(new TaskFlagsObject())
{
    d->task_id = 0;
}

TaskFlags::TaskFlags(const TaskFlags &other)
    : TAbstractModel(), d(new TaskFlagsObject(*other.d))
{ }

TaskFlags::TaskFlags(const TaskFlagsObject &object)
    : TAbstractModel(), d(new TaskFlagsObject(object))
{ }

TaskFlags::~TaskFlags()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskFlagsObject' is deleted.
}

int TaskFlags::taskId() const
{
    return d->task_id;
}

void TaskFlags::setTaskId(int taskId)
{
    d->task_id = taskId;
}

bool TaskFlags::nsvBool() const
{
    return d->nsv_bool;
}

void TaskFlags::setNsvBool(bool nsvBool)
{
    d->nsv_bool = nsvBool;
}

bool TaskFlags::preventExeBool() const
{
    return d->prevent_exe_bool;
}

void TaskFlags::setPreventExeBool(bool preventExeBool)
{
    d->prevent_exe_bool = preventExeBool;
}

QDateTime TaskFlags::preventExeReviewDt() const
{
    return d->prevent_exe_review_dt;
}

void TaskFlags::setPreventExeReviewDt(const QDateTime &preventExeReviewDt)
{
    d->prevent_exe_review_dt = preventExeReviewDt;
}

bool TaskFlags::reviewReceiptBool() const
{
    return d->review_receipt_bool;
}

void TaskFlags::setReviewReceiptBool(bool reviewReceiptBool)
{
    d->review_receipt_bool = reviewReceiptBool;
}

bool TaskFlags::riiReqBool() const
{
    return d->rii_req_bool;
}

void TaskFlags::setRiiReqBool(bool riiReqBool)
{
    d->rii_req_bool = riiReqBool;
}

bool TaskFlags::routineBool() const
{
    return d->routine_bool;
}

void TaskFlags::setRoutineBool(bool routineBool)
{
    d->routine_bool = routineBool;
}

bool TaskFlags::etopsBool() const
{
    return d->etops_bool;
}

void TaskFlags::setEtopsBool(bool etopsBool)
{
    d->etops_bool = etopsBool;
}

bool TaskFlags::rvsmBool() const
{
    return d->rvsm_bool;
}

void TaskFlags::setRvsmBool(bool rvsmBool)
{
    d->rvsm_bool = rvsmBool;
}

bool TaskFlags::softDeadlineBool() const
{
    return d->soft_deadline_bool;
}

void TaskFlags::setSoftDeadlineBool(bool softDeadlineBool)
{
    d->soft_deadline_bool = softDeadlineBool;
}

QDateTime TaskFlags::createdAt() const
{
    return d->created_at;
}

QString TaskFlags::createdBy() const
{
    return d->created_by;
}

void TaskFlags::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskFlags::updatedAt() const
{
    return d->updated_at;
}

QString TaskFlags::updatedBy() const
{
    return d->updated_by;
}

void TaskFlags::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskTask TaskFlags::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskFlags &TaskFlags::operator=(const TaskFlags &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskFlags TaskFlags::create(int taskId, bool nsvBool, bool preventExeBool, const QDateTime &preventExeReviewDt, bool reviewReceiptBool, bool riiReqBool, bool routineBool, bool etopsBool, bool rvsmBool, bool softDeadlineBool, const QString &createdBy, const QString &updatedBy)
{
    TaskFlagsObject obj;
    obj.task_id = taskId;
    obj.nsv_bool = nsvBool;
    obj.prevent_exe_bool = preventExeBool;
    obj.prevent_exe_review_dt = preventExeReviewDt;
    obj.review_receipt_bool = reviewReceiptBool;
    obj.rii_req_bool = riiReqBool;
    obj.routine_bool = routineBool;
    obj.etops_bool = etopsBool;
    obj.rvsm_bool = rvsmBool;
    obj.soft_deadline_bool = softDeadlineBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskFlags();
    }
    return TaskFlags(obj);
}

TaskFlags TaskFlags::create(const QVariantMap &values)
{
    TaskFlags model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskFlags TaskFlags::get(int taskId)
{
    TSqlORMapper<TaskFlagsObject> mapper;
    return TaskFlags(mapper.findByPrimaryKey(taskId));
}

int TaskFlags::count()
{
    TSqlORMapper<TaskFlagsObject> mapper;
    return mapper.findCount();
}

QList<TaskFlags> TaskFlags::getAll()
{
    return tfGetModelListByCriteria<TaskFlags, TaskFlagsObject>();
}

TModelObject *TaskFlags::modelData()
{
    return d.data();
}

const TModelObject *TaskFlags::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskFlags &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskFlags &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskFlags)
