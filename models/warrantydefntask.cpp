#include <TreeFrogModel>
#include "warrantydefntask.h"
#include "warrantydefntaskobject.h"
#include "tasktask.h"
#include "warrantydefn.h"

WarrantyDefnTask::WarrantyDefnTask()
    : TAbstractModel(), d(new WarrantyDefnTaskObject())
{
    d->warranty_defn_id = 0;
    d->task_id = 0;
}

WarrantyDefnTask::WarrantyDefnTask(const WarrantyDefnTask &other)
    : TAbstractModel(), d(new WarrantyDefnTaskObject(*other.d))
{ }

WarrantyDefnTask::WarrantyDefnTask(const WarrantyDefnTaskObject &object)
    : TAbstractModel(), d(new WarrantyDefnTaskObject(object))
{ }

WarrantyDefnTask::~WarrantyDefnTask()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnTaskObject' is deleted.
}

int WarrantyDefnTask::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyDefnTask::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

int WarrantyDefnTask::taskId() const
{
    return d->task_id;
}

void WarrantyDefnTask::setTaskId(int taskId)
{
    d->task_id = taskId;
}

QDateTime WarrantyDefnTask::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefnTask::createdBy() const
{
    return d->created_by;
}

void WarrantyDefnTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefnTask::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefnTask::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefnTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskTask WarrantyDefnTask::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

WarrantyDefn WarrantyDefnTask::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyDefnTask &WarrantyDefnTask::operator=(const WarrantyDefnTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefnTask WarrantyDefnTask::create(int warrantyDefnId, int taskId, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnTaskObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.task_id = taskId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefnTask();
    }
    return WarrantyDefnTask(obj);
}

WarrantyDefnTask WarrantyDefnTask::create(const QVariantMap &values)
{
    WarrantyDefnTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefnTask WarrantyDefnTask::get(int warrantyDefnId, int taskId)
{
    TSqlORMapper<WarrantyDefnTaskObject> mapper;
    return WarrantyDefnTask(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyDefnId)<<QVariant(taskId)));
}

int WarrantyDefnTask::count()
{
    TSqlORMapper<WarrantyDefnTaskObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefnTask> WarrantyDefnTask::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefnTask, WarrantyDefnTaskObject>();
}

TModelObject *WarrantyDefnTask::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefnTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefnTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefnTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefnTask)
