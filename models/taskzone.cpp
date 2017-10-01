#include <TreeFrogModel>
#include "taskzone.h"
#include "taskzoneobject.h"
#include "eqpzone.h"
#include "tasktask.h"

TaskZone::TaskZone()
    : TAbstractModel(), d(new TaskZoneObject())
{
    d->task_id = 0;
    d->zone_id = 0;
}

TaskZone::TaskZone(const TaskZone &other)
    : TAbstractModel(), d(new TaskZoneObject(*other.d))
{ }

TaskZone::TaskZone(const TaskZoneObject &object)
    : TAbstractModel(), d(new TaskZoneObject(object))
{ }

TaskZone::~TaskZone()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskZoneObject' is deleted.
}

int TaskZone::taskId() const
{
    return d->task_id;
}

void TaskZone::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskZone::zoneId() const
{
    return d->zone_id;
}

void TaskZone::setZoneId(int zoneId)
{
    d->zone_id = zoneId;
}

QDateTime TaskZone::createdAt() const
{
    return d->created_at;
}

QString TaskZone::createdBy() const
{
    return d->created_by;
}

void TaskZone::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskZone::updatedAt() const
{
    return d->updated_at;
}

QString TaskZone::updatedBy() const
{
    return d->updated_by;
}

void TaskZone::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpZone TaskZone::eqpZoneByzoneId() const
{
 return EqpZone::get(d->zone_id);
}

TaskTask TaskZone::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskZone &TaskZone::operator=(const TaskZone &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskZone TaskZone::create(int taskId, int zoneId, const QString &createdBy, const QString &updatedBy)
{
    TaskZoneObject obj;
    obj.task_id = taskId;
    obj.zone_id = zoneId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskZone();
    }
    return TaskZone(obj);
}

TaskZone TaskZone::create(const QVariantMap &values)
{
    TaskZone model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskZone TaskZone::get(int taskId, int zoneId)
{
    TSqlORMapper<TaskZoneObject> mapper;
    return TaskZone(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(zoneId)));
}

int TaskZone::count()
{
    TSqlORMapper<TaskZoneObject> mapper;
    return mapper.findCount();
}

QList<TaskZone> TaskZone::getAll()
{
    return tfGetModelListByCriteria<TaskZone, TaskZoneObject>();
}

TModelObject *TaskZone::modelData()
{
    return d.data();
}

const TModelObject *TaskZone::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskZone &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskZone &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskZone)
