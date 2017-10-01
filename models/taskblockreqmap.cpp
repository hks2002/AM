#include <TreeFrogModel>
#include "taskblockreqmap.h"
#include "taskblockreqmapobject.h"
#include "taskdefn.h"
#include "tasktask.h"

TaskBlockReqMap::TaskBlockReqMap()
    : TAbstractModel(), d(new TaskBlockReqMapObject())
{
    d->task_id = 0;
    d->task_defn_id = 0;
    d->req_task_order = 0;
}

TaskBlockReqMap::TaskBlockReqMap(const TaskBlockReqMap &other)
    : TAbstractModel(), d(new TaskBlockReqMapObject(*other.d))
{ }

TaskBlockReqMap::TaskBlockReqMap(const TaskBlockReqMapObject &object)
    : TAbstractModel(), d(new TaskBlockReqMapObject(object))
{ }

TaskBlockReqMap::~TaskBlockReqMap()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskBlockReqMapObject' is deleted.
}

int TaskBlockReqMap::taskId() const
{
    return d->task_id;
}

void TaskBlockReqMap::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskBlockReqMap::taskDefnId() const
{
    return d->task_defn_id;
}

void TaskBlockReqMap::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

int TaskBlockReqMap::reqTaskOrder() const
{
    return d->req_task_order;
}

void TaskBlockReqMap::setReqTaskOrder(int reqTaskOrder)
{
    d->req_task_order = reqTaskOrder;
}

QDateTime TaskBlockReqMap::createdAt() const
{
    return d->created_at;
}

QString TaskBlockReqMap::createdBy() const
{
    return d->created_by;
}

void TaskBlockReqMap::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskBlockReqMap::updatedAt() const
{
    return d->updated_at;
}

QString TaskBlockReqMap::updatedBy() const
{
    return d->updated_by;
}

void TaskBlockReqMap::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn TaskBlockReqMap::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

TaskTask TaskBlockReqMap::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskBlockReqMap &TaskBlockReqMap::operator=(const TaskBlockReqMap &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskBlockReqMap TaskBlockReqMap::create(int taskId, int taskDefnId, int reqTaskOrder, const QString &createdBy, const QString &updatedBy)
{
    TaskBlockReqMapObject obj;
    obj.task_id = taskId;
    obj.task_defn_id = taskDefnId;
    obj.req_task_order = reqTaskOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskBlockReqMap();
    }
    return TaskBlockReqMap(obj);
}

TaskBlockReqMap TaskBlockReqMap::create(const QVariantMap &values)
{
    TaskBlockReqMap model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskBlockReqMap TaskBlockReqMap::get(int taskId, int taskDefnId)
{
    TSqlORMapper<TaskBlockReqMapObject> mapper;
    return TaskBlockReqMap(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(taskDefnId)));
}

int TaskBlockReqMap::count()
{
    TSqlORMapper<TaskBlockReqMapObject> mapper;
    return mapper.findCount();
}

QList<TaskBlockReqMap> TaskBlockReqMap::getAll()
{
    return tfGetModelListByCriteria<TaskBlockReqMap, TaskBlockReqMapObject>();
}

TModelObject *TaskBlockReqMap::modelData()
{
    return d.data();
}

const TModelObject *TaskBlockReqMap::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskBlockReqMap &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskBlockReqMap &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskBlockReqMap)
