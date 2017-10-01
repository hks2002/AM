#include <TreeFrogModel>
#include "schedstep.h"
#include "schedstepobject.h"
#include "taskstep.h"
#include "schedstask.h"

SchedStep::SchedStep()
    : TAbstractModel(), d(new SchedStepObject())
{
    d->step_id = 0;
    d->sched_id = 0;
    d->task_id = 0;
    d->step_ord = 0;
}

SchedStep::SchedStep(const SchedStep &other)
    : TAbstractModel(), d(new SchedStepObject(*other.d))
{ }

SchedStep::SchedStep(const SchedStepObject &object)
    : TAbstractModel(), d(new SchedStepObject(object))
{ }

SchedStep::~SchedStep()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedStepObject' is deleted.
}

int SchedStep::stepId() const
{
    return d->step_id;
}

int SchedStep::schedId() const
{
    return d->sched_id;
}

void SchedStep::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedStep::taskId() const
{
    return d->task_id;
}

void SchedStep::setTaskId(int taskId)
{
    d->task_id = taskId;
}

QString SchedStep::stepDesc() const
{
    return d->step_desc;
}

void SchedStep::setStepDesc(const QString &stepDesc)
{
    d->step_desc = stepDesc;
}

int SchedStep::stepOrd() const
{
    return d->step_ord;
}

void SchedStep::setStepOrd(int stepOrd)
{
    d->step_ord = stepOrd;
}

bool SchedStep::signBool() const
{
    return d->sign_bool;
}

void SchedStep::setSignBool(bool signBool)
{
    d->sign_bool = signBool;
}

bool SchedStep::inspBool() const
{
    return d->insp_bool;
}

void SchedStep::setInspBool(bool inspBool)
{
    d->insp_bool = inspBool;
}

bool SchedStep::riiBool() const
{
    return d->rii_bool;
}

void SchedStep::setRiiBool(bool riiBool)
{
    d->rii_bool = riiBool;
}

QDateTime SchedStep::createdAt() const
{
    return d->created_at;
}

QString SchedStep::createdBy() const
{
    return d->created_by;
}

void SchedStep::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedStep::updatedAt() const
{
    return d->updated_at;
}

QString SchedStep::updatedBy() const
{
    return d->updated_by;
}

void SchedStep::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskStep SchedStep::taskStepBytaskIdstepOrd() const
{
 return TaskStep::get(d->task_id, d->step_ord);
}

SchedStask SchedStep::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedStep &SchedStep::operator=(const SchedStep &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedStep SchedStep::create(int schedId, int taskId, const QString &stepDesc, int stepOrd, bool signBool, bool inspBool, bool riiBool, const QString &createdBy, const QString &updatedBy)
{
    SchedStepObject obj;
    obj.sched_id = schedId;
    obj.task_id = taskId;
    obj.step_desc = stepDesc;
    obj.step_ord = stepOrd;
    obj.sign_bool = signBool;
    obj.insp_bool = inspBool;
    obj.rii_bool = riiBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedStep();
    }
    return SchedStep(obj);
}

SchedStep SchedStep::create(const QVariantMap &values)
{
    SchedStep model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedStep SchedStep::get(int stepId)
{
    TSqlORMapper<SchedStepObject> mapper;
    return SchedStep(mapper.findByPrimaryKey(stepId));
}

int SchedStep::count()
{
    TSqlORMapper<SchedStepObject> mapper;
    return mapper.findCount();
}

QList<SchedStep> SchedStep::getAll()
{
    return tfGetModelListByCriteria<SchedStep, SchedStepObject>();
}

TModelObject *SchedStep::modelData()
{
    return d.data();
}

const TModelObject *SchedStep::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedStep &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedStep &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedStep)
