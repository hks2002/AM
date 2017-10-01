#include <TreeFrogModel>
#include "warrantyevalpart.h"
#include "warrantyevalpartobject.h"
#include "schedrmvdpart.h"
#include "warrantyevaltask.h"

WarrantyEvalPart::WarrantyEvalPart()
    : TAbstractModel(), d(new WarrantyEvalPartObject())
{
    d->warranty_eval_id = 0;
    d->sched_id = 0;
    d->sched_part_id = 0;
}

WarrantyEvalPart::WarrantyEvalPart(const WarrantyEvalPart &other)
    : TAbstractModel(), d(new WarrantyEvalPartObject(*other.d))
{ }

WarrantyEvalPart::WarrantyEvalPart(const WarrantyEvalPartObject &object)
    : TAbstractModel(), d(new WarrantyEvalPartObject(object))
{ }

WarrantyEvalPart::~WarrantyEvalPart()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyEvalPartObject' is deleted.
}

int WarrantyEvalPart::warrantyEvalId() const
{
    return d->warranty_eval_id;
}

void WarrantyEvalPart::setWarrantyEvalId(int warrantyEvalId)
{
    d->warranty_eval_id = warrantyEvalId;
}

int WarrantyEvalPart::schedId() const
{
    return d->sched_id;
}

void WarrantyEvalPart::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int WarrantyEvalPart::schedPartId() const
{
    return d->sched_part_id;
}

void WarrantyEvalPart::setSchedPartId(int schedPartId)
{
    d->sched_part_id = schedPartId;
}

bool WarrantyEvalPart::rtrnReqBool() const
{
    return d->rtrn_req_bool;
}

void WarrantyEvalPart::setRtrnReqBool(bool rtrnReqBool)
{
    d->rtrn_req_bool = rtrnReqBool;
}

QDateTime WarrantyEvalPart::createdAt() const
{
    return d->created_at;
}

QString WarrantyEvalPart::createdBy() const
{
    return d->created_by;
}

void WarrantyEvalPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyEvalPart::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyEvalPart::updatedBy() const
{
    return d->updated_by;
}

void WarrantyEvalPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

SchedRmvdPart WarrantyEvalPart::schedRmvdPartByschedPartId() const
{
 return SchedRmvdPart::get(d->sched_part_id);
}

WarrantyEvalTask WarrantyEvalPart::warrantyEvalTaskBywarrantyEvalIdschedId() const
{
 return WarrantyEvalTask::get(d->warranty_eval_id, d->sched_id);
}

WarrantyEvalPart &WarrantyEvalPart::operator=(const WarrantyEvalPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyEvalPart WarrantyEvalPart::create(int warrantyEvalId, int schedId, int schedPartId, bool rtrnReqBool, const QString &createdBy, const QString &updatedBy)
{
    WarrantyEvalPartObject obj;
    obj.warranty_eval_id = warrantyEvalId;
    obj.sched_id = schedId;
    obj.sched_part_id = schedPartId;
    obj.rtrn_req_bool = rtrnReqBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyEvalPart();
    }
    return WarrantyEvalPart(obj);
}

WarrantyEvalPart WarrantyEvalPart::create(const QVariantMap &values)
{
    WarrantyEvalPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyEvalPart WarrantyEvalPart::get(int warrantyEvalId, int schedId, int schedPartId)
{
    TSqlORMapper<WarrantyEvalPartObject> mapper;
    return WarrantyEvalPart(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyEvalId)<<QVariant(schedId)<<QVariant(schedPartId)));
}

int WarrantyEvalPart::count()
{
    TSqlORMapper<WarrantyEvalPartObject> mapper;
    return mapper.findCount();
}

QList<WarrantyEvalPart> WarrantyEvalPart::getAll()
{
    return tfGetModelListByCriteria<WarrantyEvalPart, WarrantyEvalPartObject>();
}

TModelObject *WarrantyEvalPart::modelData()
{
    return d.data();
}

const TModelObject *WarrantyEvalPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyEvalPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyEvalPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyEvalPart)
