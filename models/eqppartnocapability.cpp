#include <TreeFrogModel>
#include "eqppartnocapability.h"
#include "eqppartnocapabilityobject.h"
#include "operationcapability.h"
#include "eqppartno.h"

EqpPartNoCapability::EqpPartNoCapability()
    : TAbstractModel(), d(new EqpPartNoCapabilityObject())
{
    d->part_no_id = 0;
    d->capability_id = 0;
}

EqpPartNoCapability::EqpPartNoCapability(const EqpPartNoCapability &other)
    : TAbstractModel(), d(new EqpPartNoCapabilityObject(*other.d))
{ }

EqpPartNoCapability::EqpPartNoCapability(const EqpPartNoCapabilityObject &object)
    : TAbstractModel(), d(new EqpPartNoCapabilityObject(object))
{ }

EqpPartNoCapability::~EqpPartNoCapability()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoCapabilityObject' is deleted.
}

int EqpPartNoCapability::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoCapability::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoCapability::capabilityId() const
{
    return d->capability_id;
}

void EqpPartNoCapability::setCapabilityId(int capabilityId)
{
    d->capability_id = capabilityId;
}

QDateTime EqpPartNoCapability::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoCapability::createdBy() const
{
    return d->created_by;
}

void EqpPartNoCapability::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoCapability::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoCapability::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoCapability::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

OperationCapability EqpPartNoCapability::operationCapabilityBycapabilityId() const
{
 return OperationCapability::get(d->capability_id);
}

EqpPartNo EqpPartNoCapability::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoCapability &EqpPartNoCapability::operator=(const EqpPartNoCapability &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoCapability EqpPartNoCapability::create(int partNoId, int capabilityId, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoCapabilityObject obj;
    obj.part_no_id = partNoId;
    obj.capability_id = capabilityId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoCapability();
    }
    return EqpPartNoCapability(obj);
}

EqpPartNoCapability EqpPartNoCapability::create(const QVariantMap &values)
{
    EqpPartNoCapability model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoCapability EqpPartNoCapability::get(int partNoId, int capabilityId)
{
    TSqlORMapper<EqpPartNoCapabilityObject> mapper;
    return EqpPartNoCapability(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(capabilityId)));
}

int EqpPartNoCapability::count()
{
    TSqlORMapper<EqpPartNoCapabilityObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoCapability> EqpPartNoCapability::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoCapability, EqpPartNoCapabilityObject>();
}

TModelObject *EqpPartNoCapability::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoCapability::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoCapability &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoCapability &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoCapability)
