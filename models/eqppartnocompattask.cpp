#include <TreeFrogModel>
#include "eqppartnocompattask.h"
#include "eqppartnocompattaskobject.h"
#include "taskdefn.h"
#include "eqppartno.h"
#include "eqpassmbl.h"

EqpPartNoCompatTask::EqpPartNoCompatTask()
    : TAbstractModel(), d(new EqpPartNoCompatTaskObject())
{
    d->assmbl_id = 0;
    d->part_no_id = 0;
    d->task_defn_id = 0;
}

EqpPartNoCompatTask::EqpPartNoCompatTask(const EqpPartNoCompatTask &other)
    : TAbstractModel(), d(new EqpPartNoCompatTaskObject(*other.d))
{ }

EqpPartNoCompatTask::EqpPartNoCompatTask(const EqpPartNoCompatTaskObject &object)
    : TAbstractModel(), d(new EqpPartNoCompatTaskObject(object))
{ }

EqpPartNoCompatTask::~EqpPartNoCompatTask()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoCompatTaskObject' is deleted.
}

int EqpPartNoCompatTask::assmblId() const
{
    return d->assmbl_id;
}

void EqpPartNoCompatTask::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EqpPartNoCompatTask::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoCompatTask::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoCompatTask::taskDefnId() const
{
    return d->task_defn_id;
}

void EqpPartNoCompatTask::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

bool EqpPartNoCompatTask::preCompleteBool() const
{
    return d->pre_complete_bool;
}

void EqpPartNoCompatTask::setPreCompleteBool(bool preCompleteBool)
{
    d->pre_complete_bool = preCompleteBool;
}

QDateTime EqpPartNoCompatTask::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoCompatTask::createdBy() const
{
    return d->created_by;
}

void EqpPartNoCompatTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoCompatTask::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoCompatTask::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoCompatTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn EqpPartNoCompatTask::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

EqpPartNo EqpPartNoCompatTask::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmbl EqpPartNoCompatTask::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpPartNoCompatTask &EqpPartNoCompatTask::operator=(const EqpPartNoCompatTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoCompatTask EqpPartNoCompatTask::create(int assmblId, int partNoId, int taskDefnId, bool preCompleteBool, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoCompatTaskObject obj;
    obj.assmbl_id = assmblId;
    obj.part_no_id = partNoId;
    obj.task_defn_id = taskDefnId;
    obj.pre_complete_bool = preCompleteBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoCompatTask();
    }
    return EqpPartNoCompatTask(obj);
}

EqpPartNoCompatTask EqpPartNoCompatTask::create(const QVariantMap &values)
{
    EqpPartNoCompatTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoCompatTask EqpPartNoCompatTask::get(int assmblId, int partNoId, int taskDefnId)
{
    TSqlORMapper<EqpPartNoCompatTaskObject> mapper;
    return EqpPartNoCompatTask(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblId)<<QVariant(partNoId)<<QVariant(taskDefnId)));
}

int EqpPartNoCompatTask::count()
{
    TSqlORMapper<EqpPartNoCompatTaskObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoCompatTask> EqpPartNoCompatTask::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoCompatTask, EqpPartNoCompatTaskObject>();
}

TModelObject *EqpPartNoCompatTask::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoCompatTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoCompatTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoCompatTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoCompatTask)
