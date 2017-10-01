#include <TreeFrogModel>
#include "warrantyevaltask.h"
#include "warrantyevaltaskobject.h"
#include "schedstask.h"
#include "warrantyeval.h"

WarrantyEvalTask::WarrantyEvalTask()
    : TAbstractModel(), d(new WarrantyEvalTaskObject())
{
    d->warranty_eval_id = 0;
    d->sched_id = 0;
}

WarrantyEvalTask::WarrantyEvalTask(const WarrantyEvalTask &other)
    : TAbstractModel(), d(new WarrantyEvalTaskObject(*other.d))
{ }

WarrantyEvalTask::WarrantyEvalTask(const WarrantyEvalTaskObject &object)
    : TAbstractModel(), d(new WarrantyEvalTaskObject(object))
{ }

WarrantyEvalTask::~WarrantyEvalTask()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyEvalTaskObject' is deleted.
}

int WarrantyEvalTask::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

void WarrantyEvalTask::setWarrantyEvalId(int warrantyEvalId)
{
    d->warranty_eval_id = warrantyEvalId;
}

int WarrantyEvalTask::schedId() const
{
    return d->sched_id;
}

void WarrantyEvalTask::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

QDateTime WarrantyEvalTask::createdAt() const
{
    return d->created_at;
}

QString WarrantyEvalTask::createdBy() const
{
    return d->created_by;
}

void WarrantyEvalTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyEvalTask::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyEvalTask::updatedBy() const
{
    return d->updated_by;
}

void WarrantyEvalTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

SchedStask WarrantyEvalTask::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

WarrantyEval WarrantyEvalTask::warrantyEvalBywarrantyEvalId() const
{
 return WarrantyEval::get(d->warranty_eval_id);
}

WarrantyEvalTask &WarrantyEvalTask::operator=(const WarrantyEvalTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyEvalTask WarrantyEvalTask::create(int warrantyEvalId, int schedId, const QString &createdBy, const QString &updatedBy)
{
    WarrantyEvalTaskObject obj;
    obj.warranty_eval_id = warrantyEvalId;
    obj.sched_id = schedId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyEvalTask();
    }
    return WarrantyEvalTask(obj);
}

WarrantyEvalTask WarrantyEvalTask::create(const QVariantMap &values)
{
    WarrantyEvalTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyEvalTask WarrantyEvalTask::get(int warrantyEvalId, int schedId)
{
    TSqlORMapper<WarrantyEvalTaskObject> mapper;
    return WarrantyEvalTask(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyEvalId)<<QVariant(schedId)));
}

int WarrantyEvalTask::count()
{
    TSqlORMapper<WarrantyEvalTaskObject> mapper;
    return mapper.findCount();
}

QList<WarrantyEvalTask> WarrantyEvalTask::getAll()
{
    return tfGetModelListByCriteria<WarrantyEvalTask, WarrantyEvalTaskObject>();
}

TModelObject *WarrantyEvalTask::modelData()
{
    return d.data();
}

const TModelObject *WarrantyEvalTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyEvalTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyEvalTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyEvalTask)
