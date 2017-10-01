#include <TreeFrogModel>
#include "tasknrest.h"
#include "tasknrestobject.h"
#include "labourskill.h"
#include "tasktask.h"

TaskNrEst::TaskNrEst()
    : TAbstractModel(), d(new TaskNrEstObject())
{
    d->task_id = 0;
    d->labour_skill_id = 0;
    d->est_nr_factor = 0;
}

TaskNrEst::TaskNrEst(const TaskNrEst &other)
    : TAbstractModel(), d(new TaskNrEstObject(*other.d))
{ }

TaskNrEst::TaskNrEst(const TaskNrEstObject &object)
    : TAbstractModel(), d(new TaskNrEstObject(object))
{ }

TaskNrEst::~TaskNrEst()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskNrEstObject' is deleted.
}

int TaskNrEst::taskId() const
{
    return d->task_id;
}

void TaskNrEst::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskNrEst::labourSkillId() const
{
    return d->labour_skill_id;
}

void TaskNrEst::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

QString TaskNrEst::estEffort() const
{
    return d->est_effort;
}

void TaskNrEst::setEstEffort(const QString &estEffort)
{
    d->est_effort = estEffort;
}

double TaskNrEst::estNrFactor() const
{
    return d->est_nr_factor;
}

void TaskNrEst::setEstNrFactor(double estNrFactor)
{
    d->est_nr_factor = estNrFactor;
}

QDateTime TaskNrEst::createdAt() const
{
    return d->created_at;
}

QString TaskNrEst::createdBy() const
{
    return d->created_by;
}

void TaskNrEst::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskNrEst::updatedAt() const
{
    return d->updated_at;
}

QString TaskNrEst::updatedBy() const
{
    return d->updated_by;
}

void TaskNrEst::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

LabourSkill TaskNrEst::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

TaskTask TaskNrEst::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskNrEst &TaskNrEst::operator=(const TaskNrEst &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskNrEst TaskNrEst::create(int taskId, int labourSkillId, const QString &estEffort, double estNrFactor, const QString &createdBy, const QString &updatedBy)
{
    TaskNrEstObject obj;
    obj.task_id = taskId;
    obj.labour_skill_id = labourSkillId;
    obj.est_effort = estEffort;
    obj.est_nr_factor = estNrFactor;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskNrEst();
    }
    return TaskNrEst(obj);
}

TaskNrEst TaskNrEst::create(const QVariantMap &values)
{
    TaskNrEst model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskNrEst TaskNrEst::get(int taskId, int labourSkillId)
{
    TSqlORMapper<TaskNrEstObject> mapper;
    return TaskNrEst(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(labourSkillId)));
}

int TaskNrEst::count()
{
    TSqlORMapper<TaskNrEstObject> mapper;
    return mapper.findCount();
}

QList<TaskNrEst> TaskNrEst::getAll()
{
    return tfGetModelListByCriteria<TaskNrEst, TaskNrEstObject>();
}

TModelObject *TaskNrEst::modelData()
{
    return d.data();
}

const TModelObject *TaskNrEst::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskNrEst &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskNrEst &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskNrEst)
