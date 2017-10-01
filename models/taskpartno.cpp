#include <TreeFrogModel>
#include "taskpartno.h"
#include "taskpartnoobject.h"
#include "manufact.h"
#include "eqppartno.h"
#include "tasktask.h"

TaskPartNo::TaskPartNo()
    : TAbstractModel(), d(new TaskPartNoObject())
{
    d->task_id = 0;
    d->part_no_id = 0;
    d->manufact_id = 0;
}

TaskPartNo::TaskPartNo(const TaskPartNo &other)
    : TAbstractModel(), d(new TaskPartNoObject(*other.d))
{ }

TaskPartNo::TaskPartNo(const TaskPartNoObject &object)
    : TAbstractModel(), d(new TaskPartNoObject(object))
{ }

TaskPartNo::~TaskPartNo()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskPartNoObject' is deleted.
}

int TaskPartNo::taskId() const
{
    return d->task_id;
}

void TaskPartNo::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskPartNo::partNoId() const
{
    return d->part_no_id;
}

void TaskPartNo::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int TaskPartNo::manufactId() const
{
    return d->manufact_id;
}

void TaskPartNo::setManufactId(int manufactId)
{
    d->manufact_id = manufactId;
}

QDateTime TaskPartNo::createdAt() const
{
    return d->created_at;
}

QString TaskPartNo::createdBy() const
{
    return d->created_by;
}

void TaskPartNo::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskPartNo::updatedAt() const
{
    return d->updated_at;
}

QString TaskPartNo::updatedBy() const
{
    return d->updated_by;
}

void TaskPartNo::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Manufact TaskPartNo::manufactBymanufactId() const
{
 return Manufact::get(d->manufact_id);
}

EqpPartNo TaskPartNo::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

TaskTask TaskPartNo::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskPartNo &TaskPartNo::operator=(const TaskPartNo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskPartNo TaskPartNo::create(int taskId, int partNoId, int manufactId, const QString &createdBy, const QString &updatedBy)
{
    TaskPartNoObject obj;
    obj.task_id = taskId;
    obj.part_no_id = partNoId;
    obj.manufact_id = manufactId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskPartNo();
    }
    return TaskPartNo(obj);
}

TaskPartNo TaskPartNo::create(const QVariantMap &values)
{
    TaskPartNo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskPartNo TaskPartNo::get(int taskId, int partNoId, int manufactId)
{
    TSqlORMapper<TaskPartNoObject> mapper;
    return TaskPartNo(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(partNoId)<<QVariant(manufactId)));
}

int TaskPartNo::count()
{
    TSqlORMapper<TaskPartNoObject> mapper;
    return mapper.findCount();
}

QList<TaskPartNo> TaskPartNo::getAll()
{
    return tfGetModelListByCriteria<TaskPartNo, TaskPartNoObject>();
}

TModelObject *TaskPartNo::modelData()
{
    return d.data();
}

const TModelObject *TaskPartNo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskPartNo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskPartNo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskPartNo)
