#include <TreeFrogModel>
#include "eqpassmblbomcapability.h"
#include "eqpassmblbomcapabilityobject.h"
#include "operationcapability.h"
#include "eqpassmblbom.h"

EqpAssmblBomCapability::EqpAssmblBomCapability()
    : TAbstractModel(), d(new EqpAssmblBomCapabilityObject())
{
    d->assmbl_bom_id = 0;
    d->capability_id = 0;
}

EqpAssmblBomCapability::EqpAssmblBomCapability(const EqpAssmblBomCapability &other)
    : TAbstractModel(), d(new EqpAssmblBomCapabilityObject(*other.d))
{ }

EqpAssmblBomCapability::EqpAssmblBomCapability(const EqpAssmblBomCapabilityObject &object)
    : TAbstractModel(), d(new EqpAssmblBomCapabilityObject(object))
{ }

EqpAssmblBomCapability::~EqpAssmblBomCapability()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpAssmblBomCapabilityObject' is deleted.
}

int EqpAssmblBomCapability::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EqpAssmblBomCapability::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int EqpAssmblBomCapability::capabilityId() const
{
    return d->capability_id;
}

void EqpAssmblBomCapability::setCapabilityId(int capabilityId)
{
    d->capability_id = capabilityId;
}

QDateTime EqpAssmblBomCapability::createdAt() const
{
    return d->created_at;
}

QString EqpAssmblBomCapability::createdBy() const
{
    return d->created_by;
}

void EqpAssmblBomCapability::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpAssmblBomCapability::updatedAt() const
{
    return d->updated_at;
}

QString EqpAssmblBomCapability::updatedBy() const
{
    return d->updated_by;
}

void EqpAssmblBomCapability::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

OperationCapability EqpAssmblBomCapability::operationCapabilityBycapabilityId() const
{
 return OperationCapability::get(d->capability_id);
}

EqpAssmblBom EqpAssmblBomCapability::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmblBomCapability &EqpAssmblBomCapability::operator=(const EqpAssmblBomCapability &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpAssmblBomCapability EqpAssmblBomCapability::create(int assmblBomId, int capabilityId, const QString &createdBy, const QString &updatedBy)
{
    EqpAssmblBomCapabilityObject obj;
    obj.assmbl_bom_id = assmblBomId;
    obj.capability_id = capabilityId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpAssmblBomCapability();
    }
    return EqpAssmblBomCapability(obj);
}

EqpAssmblBomCapability EqpAssmblBomCapability::create(const QVariantMap &values)
{
    EqpAssmblBomCapability model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpAssmblBomCapability EqpAssmblBomCapability::get(int assmblBomId, int capabilityId)
{
    TSqlORMapper<EqpAssmblBomCapabilityObject> mapper;
    return EqpAssmblBomCapability(mapper.findByPrimaryKey(QVariantList()<<QVariant(assmblBomId)<<QVariant(capabilityId)));
}

int EqpAssmblBomCapability::count()
{
    TSqlORMapper<EqpAssmblBomCapabilityObject> mapper;
    return mapper.findCount();
}

QList<EqpAssmblBomCapability> EqpAssmblBomCapability::getAll()
{
    return tfGetModelListByCriteria<EqpAssmblBomCapability, EqpAssmblBomCapabilityObject>();
}

TModelObject *EqpAssmblBomCapability::modelData()
{
    return d.data();
}

const TModelObject *EqpAssmblBomCapability::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomCapability &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpAssmblBomCapability &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpAssmblBomCapability)
