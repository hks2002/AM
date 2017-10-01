#include <TreeFrogModel>
#include "taskassemblbom.h"
#include "taskassemblbomobject.h"
#include "eqpassmbl.h"
#include "eqpassmblbom.h"
#include "tasktask.h"

TaskAssemblBom::TaskAssemblBom()
    : TAbstractModel(), d(new TaskAssemblBomObject())
{
    d->task_id = 0;
    d->assmbl_bom_id = 0;
    d->assmbl_id = 0;
}

TaskAssemblBom::TaskAssemblBom(const TaskAssemblBom &other)
    : TAbstractModel(), d(new TaskAssemblBomObject(*other.d))
{ }

TaskAssemblBom::TaskAssemblBom(const TaskAssemblBomObject &object)
    : TAbstractModel(), d(new TaskAssemblBomObject(object))
{ }

TaskAssemblBom::~TaskAssemblBom()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskAssemblBomObject' is deleted.
}

int TaskAssemblBom::taskId() const
{
    return d->task_id;
}

void TaskAssemblBom::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskAssemblBom::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void TaskAssemblBom::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int TaskAssemblBom::assmblId() const
{
    return d->assmbl_id;
}

void TaskAssemblBom::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

QDateTime TaskAssemblBom::createdAt() const
{
    return d->created_at;
}

QString TaskAssemblBom::createdBy() const
{
    return d->created_by;
}

void TaskAssemblBom::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskAssemblBom::updatedAt() const
{
    return d->updated_at;
}

QString TaskAssemblBom::updatedBy() const
{
    return d->updated_by;
}

void TaskAssemblBom::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpAssmbl TaskAssemblBom::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblBom TaskAssemblBom::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

TaskTask TaskAssemblBom::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskAssemblBom &TaskAssemblBom::operator=(const TaskAssemblBom &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskAssemblBom TaskAssemblBom::create(int taskId, int assmblBomId, int assmblId, const QString &createdBy, const QString &updatedBy)
{
    TaskAssemblBomObject obj;
    obj.task_id = taskId;
    obj.assmbl_bom_id = assmblBomId;
    obj.assmbl_id = assmblId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskAssemblBom();
    }
    return TaskAssemblBom(obj);
}

TaskAssemblBom TaskAssemblBom::create(const QVariantMap &values)
{
    TaskAssemblBom model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskAssemblBom TaskAssemblBom::get(int taskId, int assmblBomId, int assmblId)
{
    TSqlORMapper<TaskAssemblBomObject> mapper;
    return TaskAssemblBom(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(assmblBomId)<<QVariant(assmblId)));
}

int TaskAssemblBom::count()
{
    TSqlORMapper<TaskAssemblBomObject> mapper;
    return mapper.findCount();
}

QList<TaskAssemblBom> TaskAssemblBom::getAll()
{
    return tfGetModelListByCriteria<TaskAssemblBom, TaskAssemblBomObject>();
}

TModelObject *TaskAssemblBom::modelData()
{
    return d.data();
}

const TModelObject *TaskAssemblBom::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskAssemblBom &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskAssemblBom &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskAssemblBom)
