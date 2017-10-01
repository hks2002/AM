#include <TreeFrogModel>
#include "invcapability.h"
#include "invcapabilityobject.h"
#include "operationcapability.h"
#include "invinv.h"

InvCapability::InvCapability()
    : TAbstractModel(), d(new InvCapabilityObject())
{
    d->inv_no_id = 0;
    d->capability_id = 0;
}

InvCapability::InvCapability(const InvCapability &other)
    : TAbstractModel(), d(new InvCapabilityObject(*other.d))
{ }

InvCapability::InvCapability(const InvCapabilityObject &object)
    : TAbstractModel(), d(new InvCapabilityObject(object))
{ }

InvCapability::~InvCapability()
{
    // If the reference count becomes 0,
    // the shared data object 'InvCapabilityObject' is deleted.
}

int InvCapability::invNoId() const
{
    return d->inv_no_id;
}

void InvCapability::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int InvCapability::capabilityId() const
{
    return d->capability_id;
}

void InvCapability::setCapabilityId(int capabilityId)
{
    d->capability_id = capabilityId;
}

QDateTime InvCapability::createdAt() const
{
    return d->created_at;
}

QString InvCapability::createdBy() const
{
    return d->created_by;
}

void InvCapability::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvCapability::updatedAt() const
{
    return d->updated_at;
}

QString InvCapability::updatedBy() const
{
    return d->updated_by;
}

void InvCapability::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

OperationCapability InvCapability::operationCapabilityBycapabilityId() const
{
 return OperationCapability::get(d->capability_id);
}

InvInv InvCapability::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvCapability &InvCapability::operator=(const InvCapability &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvCapability InvCapability::create(int invNoId, int capabilityId, const QString &createdBy, const QString &updatedBy)
{
    InvCapabilityObject obj;
    obj.inv_no_id = invNoId;
    obj.capability_id = capabilityId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvCapability();
    }
    return InvCapability(obj);
}

InvCapability InvCapability::create(const QVariantMap &values)
{
    InvCapability model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvCapability InvCapability::get(int invNoId, int capabilityId)
{
    TSqlORMapper<InvCapabilityObject> mapper;
    return InvCapability(mapper.findByPrimaryKey(QVariantList()<<QVariant(invNoId)<<QVariant(capabilityId)));
}

int InvCapability::count()
{
    TSqlORMapper<InvCapabilityObject> mapper;
    return mapper.findCount();
}

QList<InvCapability> InvCapability::getAll()
{
    return tfGetModelListByCriteria<InvCapability, InvCapabilityObject>();
}

TModelObject *InvCapability::modelData()
{
    return d.data();
}

const TModelObject *InvCapability::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvCapability &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvCapability &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvCapability)
