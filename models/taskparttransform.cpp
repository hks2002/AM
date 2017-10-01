#include <TreeFrogModel>
#include "taskparttransform.h"
#include "taskparttransformobject.h"
#include "eqppartno.h"
#include "tasktask.h"

TaskPartTransform::TaskPartTransform()
    : TAbstractModel(), d(new TaskPartTransformObject())
{
    d->task_id = 0;
    d->old_part_no_id = 0;
    d->new_part_no_id = 0;
}

TaskPartTransform::TaskPartTransform(const TaskPartTransform &other)
    : TAbstractModel(), d(new TaskPartTransformObject(*other.d))
{ }

TaskPartTransform::TaskPartTransform(const TaskPartTransformObject &object)
    : TAbstractModel(), d(new TaskPartTransformObject(object))
{ }

TaskPartTransform::~TaskPartTransform()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskPartTransformObject' is deleted.
}

int TaskPartTransform::taskId() const
{
    return d->task_id;
}

void TaskPartTransform::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskPartTransform::oldPartNoId() const
{
    return d->old_part_no_id;
}

void TaskPartTransform::setOldPartNoId(int oldPartNoId)
{
    d->old_part_no_id = oldPartNoId;
}

int TaskPartTransform::newPartNoId() const
{
    return d->new_part_no_id;
}

void TaskPartTransform::setNewPartNoId(int newPartNoId)
{
    d->new_part_no_id = newPartNoId;
}

QDateTime TaskPartTransform::createdAt() const
{
    return d->created_at;
}

QString TaskPartTransform::createdBy() const
{
    return d->created_by;
}

void TaskPartTransform::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskPartTransform::updatedAt() const
{
    return d->updated_at;
}

QString TaskPartTransform::updatedBy() const
{
    return d->updated_by;
}

void TaskPartTransform::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo TaskPartTransform::eqpPartNoBynewPartNoId() const
{
 return EqpPartNo::get(d->new_part_no_id);
}

TaskTask TaskPartTransform::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskPartTransform &TaskPartTransform::operator=(const TaskPartTransform &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskPartTransform TaskPartTransform::create(int taskId, int oldPartNoId, int newPartNoId, const QString &createdBy, const QString &updatedBy)
{
    TaskPartTransformObject obj;
    obj.task_id = taskId;
    obj.old_part_no_id = oldPartNoId;
    obj.new_part_no_id = newPartNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskPartTransform();
    }
    return TaskPartTransform(obj);
}

TaskPartTransform TaskPartTransform::create(const QVariantMap &values)
{
    TaskPartTransform model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskPartTransform TaskPartTransform::get(int taskId, int oldPartNoId, int newPartNoId)
{
    TSqlORMapper<TaskPartTransformObject> mapper;
    return TaskPartTransform(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(oldPartNoId)<<QVariant(newPartNoId)));
}

int TaskPartTransform::count()
{
    TSqlORMapper<TaskPartTransformObject> mapper;
    return mapper.findCount();
}

QList<TaskPartTransform> TaskPartTransform::getAll()
{
    return tfGetModelListByCriteria<TaskPartTransform, TaskPartTransformObject>();
}

TModelObject *TaskPartTransform::modelData()
{
    return d.data();
}

const TModelObject *TaskPartTransform::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskPartTransform &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskPartTransform &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskPartTransform)
