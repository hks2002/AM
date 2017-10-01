#include <TreeFrogModel>
#include "taskstep.h"
#include "taskstepobject.h"
#include "tasktask.h"

TaskStep::TaskStep()
    : TAbstractModel(), d(new TaskStepObject())
{
    d->task_id = 0;
    d->step_ord = 0;
}

TaskStep::TaskStep(const TaskStep &other)
    : TAbstractModel(), d(new TaskStepObject(*other.d))
{ }

TaskStep::TaskStep(const TaskStepObject &object)
    : TAbstractModel(), d(new TaskStepObject(object))
{ }

TaskStep::~TaskStep()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskStepObject' is deleted.
}

int TaskStep::taskId() const
{
    return d->task_id;
}

void TaskStep::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskStep::stepOrd() const
{
    return d->step_ord;
}

void TaskStep::setStepOrd(int stepOrd)
{
    d->step_ord = stepOrd;
}

QString TaskStep::stepDesc() const
{
    return d->step_desc;
}

void TaskStep::setStepDesc(const QString &stepDesc)
{
    d->step_desc = stepDesc;
}

bool TaskStep::signBool() const
{
    return d->sign_bool;
}

void TaskStep::setSignBool(bool signBool)
{
    d->sign_bool = signBool;
}

bool TaskStep::inspBool() const
{
    return d->insp_bool;
}

void TaskStep::setInspBool(bool inspBool)
{
    d->insp_bool = inspBool;
}

bool TaskStep::riiBool() const
{
    return d->rii_bool;
}

void TaskStep::setRiiBool(bool riiBool)
{
    d->rii_bool = riiBool;
}

QDateTime TaskStep::createdAt() const
{
    return d->created_at;
}

QString TaskStep::createdBy() const
{
    return d->created_by;
}

void TaskStep::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskStep::updatedAt() const
{
    return d->updated_at;
}

QString TaskStep::updatedBy() const
{
    return d->updated_by;
}

void TaskStep::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskTask TaskStep::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskStep &TaskStep::operator=(const TaskStep &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskStep TaskStep::create(int taskId, int stepOrd, const QString &stepDesc, bool signBool, bool inspBool, bool riiBool, const QString &createdBy, const QString &updatedBy)
{
    TaskStepObject obj;
    obj.task_id = taskId;
    obj.step_ord = stepOrd;
    obj.step_desc = stepDesc;
    obj.sign_bool = signBool;
    obj.insp_bool = inspBool;
    obj.rii_bool = riiBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskStep();
    }
    return TaskStep(obj);
}

TaskStep TaskStep::create(const QVariantMap &values)
{
    TaskStep model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskStep TaskStep::get(int taskId, int stepOrd)
{
    TSqlORMapper<TaskStepObject> mapper;
    return TaskStep(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(stepOrd)));
}

int TaskStep::count()
{
    TSqlORMapper<TaskStepObject> mapper;
    return mapper.findCount();
}

QList<TaskStep> TaskStep::getAll()
{
    return tfGetModelListByCriteria<TaskStep, TaskStepObject>();
}

TModelObject *TaskStep::modelData()
{
    return d.data();
}

const TModelObject *TaskStep::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskStep &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskStep &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskStep)
