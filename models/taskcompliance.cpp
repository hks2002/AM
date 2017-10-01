#include <TreeFrogModel>
#include "taskcompliance.h"
#include "taskcomplianceobject.h"
#include "taskdefn.h"
#include "tasktask.h"

TaskCompliance::TaskCompliance()
    : TAbstractModel(), d(new TaskComplianceObject())
{
    d->task_id = 0;
    d->compliance_task__id = 0;
}

TaskCompliance::TaskCompliance(const TaskCompliance &other)
    : TAbstractModel(), d(new TaskComplianceObject(*other.d))
{ }

TaskCompliance::TaskCompliance(const TaskComplianceObject &object)
    : TAbstractModel(), d(new TaskComplianceObject(object))
{ }

TaskCompliance::~TaskCompliance()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskComplianceObject' is deleted.
}

int TaskCompliance::taskId() const
{
    return d->task_id;
}

void TaskCompliance::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskCompliance::complianceTask_id() const
{
    return d->compliance_task__id;
}

void TaskCompliance::setComplianceTask_id(int complianceTask_id)
{
    d->compliance_task__id = complianceTask_id;
}

QDateTime TaskCompliance::createdAt() const
{
    return d->created_at;
}

QString TaskCompliance::createdBy() const
{
    return d->created_by;
}

void TaskCompliance::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskCompliance::updatedAt() const
{
    return d->updated_at;
}

QString TaskCompliance::updatedBy() const
{
    return d->updated_by;
}

void TaskCompliance::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn TaskCompliance::taskDefnBycomplianceTask_id() const
{
 return TaskDefn::get(d->compliance_task__id);
}

TaskTask TaskCompliance::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskCompliance &TaskCompliance::operator=(const TaskCompliance &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskCompliance TaskCompliance::create(int taskId, int complianceTask_id, const QString &createdBy, const QString &updatedBy)
{
    TaskComplianceObject obj;
    obj.task_id = taskId;
    obj.compliance_task__id = complianceTask_id;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskCompliance();
    }
    return TaskCompliance(obj);
}

TaskCompliance TaskCompliance::create(const QVariantMap &values)
{
    TaskCompliance model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskCompliance TaskCompliance::get(int taskId, int complianceTask_id)
{
    TSqlORMapper<TaskComplianceObject> mapper;
    return TaskCompliance(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(complianceTask_id)));
}

int TaskCompliance::count()
{
    TSqlORMapper<TaskComplianceObject> mapper;
    return mapper.findCount();
}

QList<TaskCompliance> TaskCompliance::getAll()
{
    return tfGetModelListByCriteria<TaskCompliance, TaskComplianceObject>();
}

TModelObject *TaskCompliance::modelData()
{
    return d.data();
}

const TModelObject *TaskCompliance::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskCompliance &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskCompliance &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskCompliance)
