#include <TreeFrogModel>
#include "tasktaskdep.h"
#include "tasktaskdepobject.h"
#include "reftaskdepaction.h"
#include "taskdefn.h"
#include "tasktask.h"

TaskTaskDep::TaskTaskDep()
    : TAbstractModel(), d(new TaskTaskDepObject())
{
    d->task_id = 0;
    d->task_dep_id = 0;
}

TaskTaskDep::TaskTaskDep(const TaskTaskDep &other)
    : TAbstractModel(), d(new TaskTaskDepObject(*other.d))
{ }

TaskTaskDep::TaskTaskDep(const TaskTaskDepObject &object)
    : TAbstractModel(), d(new TaskTaskDepObject(object))
{ }

TaskTaskDep::~TaskTaskDep()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskTaskDepObject' is deleted.
}

int TaskTaskDep::taskId() const
{
    return d->task_id;
}

void TaskTaskDep::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskTaskDep::taskDepId() const
{
    return d->task_dep_id;
}

void TaskTaskDep::setTaskDepId(int taskDepId)
{
    d->task_dep_id = taskDepId;
}

QString TaskTaskDep::taskDepActionCd() const
{
    return d->task_dep_action_cd;
}

void TaskTaskDep::setTaskDepActionCd(const QString &taskDepActionCd)
{
    d->task_dep_action_cd = taskDepActionCd;
}

QDateTime TaskTaskDep::createdAt() const
{
    return d->created_at;
}

QString TaskTaskDep::createdBy() const
{
    return d->created_by;
}

void TaskTaskDep::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskTaskDep::updatedAt() const
{
    return d->updated_at;
}

QString TaskTaskDep::updatedBy() const
{
    return d->updated_by;
}

void TaskTaskDep::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefTaskDepAction TaskTaskDep::refTaskDepActionBytaskDepActionCd() const
{
 return RefTaskDepAction::get(d->task_dep_action_cd);
}

TaskDefn TaskTaskDep::taskDefnBytaskDepId() const
{
 return TaskDefn::get(d->task_dep_id);
}

TaskTask TaskTaskDep::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskTaskDep &TaskTaskDep::operator=(const TaskTaskDep &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskTaskDep TaskTaskDep::create(int taskId, int taskDepId, const QString &taskDepActionCd, const QString &createdBy, const QString &updatedBy)
{
    TaskTaskDepObject obj;
    obj.task_id = taskId;
    obj.task_dep_id = taskDepId;
    obj.task_dep_action_cd = taskDepActionCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskTaskDep();
    }
    return TaskTaskDep(obj);
}

TaskTaskDep TaskTaskDep::create(const QVariantMap &values)
{
    TaskTaskDep model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskTaskDep TaskTaskDep::get(int taskId, int taskDepId)
{
    TSqlORMapper<TaskTaskDepObject> mapper;
    return TaskTaskDep(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(taskDepId)));
}

int TaskTaskDep::count()
{
    TSqlORMapper<TaskTaskDepObject> mapper;
    return mapper.findCount();
}

QList<TaskTaskDep> TaskTaskDep::getAll()
{
    return tfGetModelListByCriteria<TaskTaskDep, TaskTaskDepObject>();
}

TModelObject *TaskTaskDep::modelData()
{
    return d.data();
}

const TModelObject *TaskTaskDep::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskTaskDep &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskTaskDep &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskTaskDep)
