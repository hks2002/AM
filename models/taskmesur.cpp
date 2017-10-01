#include <TreeFrogModel>
#include "taskmesur.h"
#include "taskmesurobject.h"
#include "mesurunit.h"
#include "tasktask.h"

TaskMesur::TaskMesur()
    : TAbstractModel(), d(new TaskMesurObject())
{
    d->task_id = 0;
    d->mesur_unit_id = 0;
    d->mesur_ord = 0;
}

TaskMesur::TaskMesur(const TaskMesur &other)
    : TAbstractModel(), d(new TaskMesurObject(*other.d))
{ }

TaskMesur::TaskMesur(const TaskMesurObject &object)
    : TAbstractModel(), d(new TaskMesurObject(object))
{ }

TaskMesur::~TaskMesur()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskMesurObject' is deleted.
}

int TaskMesur::taskId() const
{
    return d->task_id;
}

void TaskMesur::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskMesur::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void TaskMesur::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

int TaskMesur::mesurOrd() const
{
    return d->mesur_ord;
}

void TaskMesur::setMesurOrd(int mesurOrd)
{
    d->mesur_ord = mesurOrd;
}

QDateTime TaskMesur::createdAt() const
{
    return d->created_at;
}

QString TaskMesur::createdBy() const
{
    return d->created_by;
}

void TaskMesur::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskMesur::updatedAt() const
{
    return d->updated_at;
}

QString TaskMesur::updatedBy() const
{
    return d->updated_by;
}

void TaskMesur::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit TaskMesur::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

TaskTask TaskMesur::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskMesur &TaskMesur::operator=(const TaskMesur &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskMesur TaskMesur::create(int taskId, int mesurUnitId, int mesurOrd, const QString &createdBy, const QString &updatedBy)
{
    TaskMesurObject obj;
    obj.task_id = taskId;
    obj.mesur_unit_id = mesurUnitId;
    obj.mesur_ord = mesurOrd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskMesur();
    }
    return TaskMesur(obj);
}

TaskMesur TaskMesur::create(const QVariantMap &values)
{
    TaskMesur model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskMesur TaskMesur::get(int taskId, int mesurUnitId)
{
    TSqlORMapper<TaskMesurObject> mapper;
    return TaskMesur(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(mesurUnitId)));
}

int TaskMesur::count()
{
    TSqlORMapper<TaskMesurObject> mapper;
    return mapper.findCount();
}

QList<TaskMesur> TaskMesur::getAll()
{
    return tfGetModelListByCriteria<TaskMesur, TaskMesurObject>();
}

TModelObject *TaskMesur::modelData()
{
    return d.data();
}

const TModelObject *TaskMesur::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskMesur &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskMesur &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskMesur)
