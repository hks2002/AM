#include <TreeFrogModel>
#include "taskimpact.h"
#include "taskimpactobject.h"
#include "refmesurtype.h"
#include "mesurunit.h"
#include "tasktask.h"

TaskImpact::TaskImpact()
    : TAbstractModel(), d(new TaskImpactObject())
{
    d->task_id = 0;
    d->mesur_unit_id = 0;
    d->mesur_qt = 0;
}

TaskImpact::TaskImpact(const TaskImpact &other)
    : TAbstractModel(), d(new TaskImpactObject(*other.d))
{ }

TaskImpact::TaskImpact(const TaskImpactObject &object)
    : TAbstractModel(), d(new TaskImpactObject(object))
{ }

TaskImpact::~TaskImpact()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskImpactObject' is deleted.
}

int TaskImpact::taskId() const
{
    return d->task_id;
}

void TaskImpact::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskImpact::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void TaskImpact::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

QString TaskImpact::mesurTypeCd() const
{
    return d->mesur_type_cd;
}

void TaskImpact::setMesurTypeCd(const QString &mesurTypeCd)
{
    d->mesur_type_cd = mesurTypeCd;
}

double TaskImpact::mesurQt() const
{
    return d->mesur_qt;
}

void TaskImpact::setMesurQt(double mesurQt)
{
    d->mesur_qt = mesurQt;
}

QString TaskImpact::impactDesc() const
{
    return d->impact_desc;
}

void TaskImpact::setImpactDesc(const QString &impactDesc)
{
    d->impact_desc = impactDesc;
}

QDateTime TaskImpact::createdAt() const
{
    return d->created_at;
}

QString TaskImpact::createdBy() const
{
    return d->created_by;
}

void TaskImpact::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskImpact::updatedAt() const
{
    return d->updated_at;
}

QString TaskImpact::updatedBy() const
{
    return d->updated_by;
}

void TaskImpact::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefMesurType TaskImpact::refMesurTypeBymesurTypeCd() const
{
 return RefMesurType::get(d->mesur_type_cd);
}

MesurUnit TaskImpact::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

TaskTask TaskImpact::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskImpact &TaskImpact::operator=(const TaskImpact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskImpact TaskImpact::create(int taskId, int mesurUnitId, const QString &mesurTypeCd, double mesurQt, const QString &impactDesc, const QString &createdBy, const QString &updatedBy)
{
    TaskImpactObject obj;
    obj.task_id = taskId;
    obj.mesur_unit_id = mesurUnitId;
    obj.mesur_type_cd = mesurTypeCd;
    obj.mesur_qt = mesurQt;
    obj.impact_desc = impactDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskImpact();
    }
    return TaskImpact(obj);
}

TaskImpact TaskImpact::create(const QVariantMap &values)
{
    TaskImpact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskImpact TaskImpact::get(int taskId, int mesurUnitId, const QString &mesurTypeCd)
{
    TSqlORMapper<TaskImpactObject> mapper;
    return TaskImpact(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(mesurUnitId)<<QVariant(mesurTypeCd)));
}

int TaskImpact::count()
{
    TSqlORMapper<TaskImpactObject> mapper;
    return mapper.findCount();
}

QList<TaskImpact> TaskImpact::getAll()
{
    return tfGetModelListByCriteria<TaskImpact, TaskImpactObject>();
}

TModelObject *TaskImpact::modelData()
{
    return d.data();
}

const TModelObject *TaskImpact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskImpact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskImpact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskImpact)
