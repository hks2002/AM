#include <TreeFrogModel>
#include "taskjicreqmap.h"
#include "taskjicreqmapobject.h"
#include "taskdefn.h"
#include "tasktask.h"

TaskJicReqMap::TaskJicReqMap()
    : TAbstractModel(), d(new TaskJicReqMapObject())
{
    d->task_id = 0;
    d->task_defn_id = 0;
    d->jic_task_order = 0;
}

TaskJicReqMap::TaskJicReqMap(const TaskJicReqMap &other)
    : TAbstractModel(), d(new TaskJicReqMapObject(*other.d))
{ }

TaskJicReqMap::TaskJicReqMap(const TaskJicReqMapObject &object)
    : TAbstractModel(), d(new TaskJicReqMapObject(object))
{ }

TaskJicReqMap::~TaskJicReqMap()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskJicReqMapObject' is deleted.
}

int TaskJicReqMap::taskId() const
{
    return d->task_id;
}

void TaskJicReqMap::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskJicReqMap::taskDefnId() const
{
    return d->task_defn_id;
}

void TaskJicReqMap::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

int TaskJicReqMap::jicTaskOrder() const
{
    return d->jic_task_order;
}

void TaskJicReqMap::setJicTaskOrder(int jicTaskOrder)
{
    d->jic_task_order = jicTaskOrder;
}

QDateTime TaskJicReqMap::createdAt() const
{
    return d->created_at;
}

QString TaskJicReqMap::createdBy() const
{
    return d->created_by;
}

void TaskJicReqMap::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskJicReqMap::updatedAt() const
{
    return d->updated_at;
}

QString TaskJicReqMap::updatedBy() const
{
    return d->updated_by;
}

void TaskJicReqMap::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn TaskJicReqMap::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

TaskTask TaskJicReqMap::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskJicReqMap &TaskJicReqMap::operator=(const TaskJicReqMap &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskJicReqMap TaskJicReqMap::create(int taskId, int taskDefnId, int jicTaskOrder, const QString &createdBy, const QString &updatedBy)
{
    TaskJicReqMapObject obj;
    obj.task_id = taskId;
    obj.task_defn_id = taskDefnId;
    obj.jic_task_order = jicTaskOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskJicReqMap();
    }
    return TaskJicReqMap(obj);
}

TaskJicReqMap TaskJicReqMap::create(const QVariantMap &values)
{
    TaskJicReqMap model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskJicReqMap TaskJicReqMap::get(int taskId, int taskDefnId)
{
    TSqlORMapper<TaskJicReqMapObject> mapper;
    return TaskJicReqMap(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(taskDefnId)));
}

int TaskJicReqMap::count()
{
    TSqlORMapper<TaskJicReqMapObject> mapper;
    return mapper.findCount();
}

QList<TaskJicReqMap> TaskJicReqMap::getAll()
{
    return tfGetModelListByCriteria<TaskJicReqMap, TaskJicReqMapObject>();
}

TModelObject *TaskJicReqMap::modelData()
{
    return d.data();
}

const TModelObject *TaskJicReqMap::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskJicReqMap &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskJicReqMap &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskJicReqMap)
