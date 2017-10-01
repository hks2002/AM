#include <TreeFrogModel>
#include "warrantyevallabour.h"
#include "warrantyevallabourobject.h"
#include "schedlabour.h"
#include "warrantyevaltask.h"

WarrantyEvalLabour::WarrantyEvalLabour()
    : TAbstractModel(), d(new WarrantyEvalLabourObject())
{
    d->warranty_eval_id = 0;
    d->sched_id = 0;
    d->labour_id = 0;
}

WarrantyEvalLabour::WarrantyEvalLabour(const WarrantyEvalLabour &other)
    : TAbstractModel(), d(new WarrantyEvalLabourObject(*other.d))
{ }

WarrantyEvalLabour::WarrantyEvalLabour(const WarrantyEvalLabourObject &object)
    : TAbstractModel(), d(new WarrantyEvalLabourObject(object))
{ }

WarrantyEvalLabour::~WarrantyEvalLabour()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyEvalLabourObject' is deleted.
}

int WarrantyEvalLabour::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

void WarrantyEvalLabour::setWarrantyEvalId(int warrantyEvalId)
{
    d->warranty_eval_id = warrantyEvalId;
}

int WarrantyEvalLabour::schedId() const
{
    return d->sched_id;
}

void WarrantyEvalLabour::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int WarrantyEvalLabour::labourId() const
{
    return d->labour_id;
}

void WarrantyEvalLabour::setLabourId(int labourId)
{
    d->labour_id = labourId;
}

QDateTime WarrantyEvalLabour::createdAt() const
{
    return d->created_at;
}

QString WarrantyEvalLabour::createdBy() const
{
    return d->created_by;
}

void WarrantyEvalLabour::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyEvalLabour::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyEvalLabour::updatedBy() const
{
    return d->updated_by;
}

void WarrantyEvalLabour::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

SchedLabour WarrantyEvalLabour::schedLabourBylabourId() const
{
 return SchedLabour::get(d->labour_id);
}

WarrantyEvalTask WarrantyEvalLabour::warrantyEvalTaskBywarrantyEvalIdschedId() const
{
 return WarrantyEvalTask::get(d->warranty_eval_id, d->sched_id);
}

WarrantyEvalLabour &WarrantyEvalLabour::operator=(const WarrantyEvalLabour &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyEvalLabour WarrantyEvalLabour::create(int warrantyEvalId, int schedId, int labourId, const QString &createdBy, const QString &updatedBy)
{
    WarrantyEvalLabourObject obj;
    obj.warranty_eval_id = warrantyEvalId;
    obj.sched_id = schedId;
    obj.labour_id = labourId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyEvalLabour();
    }
    return WarrantyEvalLabour(obj);
}

WarrantyEvalLabour WarrantyEvalLabour::create(const QVariantMap &values)
{
    WarrantyEvalLabour model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyEvalLabour WarrantyEvalLabour::get(int warrantyEvalId, int schedId, int labourId)
{
    TSqlORMapper<WarrantyEvalLabourObject> mapper;
    return WarrantyEvalLabour(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyEvalId)<<QVariant(schedId)<<QVariant(labourId)));
}

int WarrantyEvalLabour::count()
{
    TSqlORMapper<WarrantyEvalLabourObject> mapper;
    return mapper.findCount();
}

QList<WarrantyEvalLabour> WarrantyEvalLabour::getAll()
{
    return tfGetModelListByCriteria<WarrantyEvalLabour, WarrantyEvalLabourObject>();
}

TModelObject *WarrantyEvalLabour::modelData()
{
    return d.data();
}

const TModelObject *WarrantyEvalLabour::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyEvalLabour &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyEvalLabour &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyEvalLabour)
