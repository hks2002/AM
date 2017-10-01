#include <TreeFrogModel>
#include "operationcapability.h"
#include "operationcapabilityobject.h"

OperationCapability::OperationCapability()
    : TAbstractModel(), d(new OperationCapabilityObject())
{
    d->capability_id = 0;
}

OperationCapability::OperationCapability(const OperationCapability &other)
    : TAbstractModel(), d(new OperationCapabilityObject(*other.d))
{ }

OperationCapability::OperationCapability(const OperationCapabilityObject &object)
    : TAbstractModel(), d(new OperationCapabilityObject(object))
{ }

OperationCapability::~OperationCapability()
{
    // If the reference count becomes 0,
    // the shared data object 'OperationCapabilityObject' is deleted.
}

int OperationCapability::capabilityId() const
{
    return d->capability_id;
}

QString OperationCapability::capabilityCd() const
{
    return d->capability_cd;
}

void OperationCapability::setCapabilityCd(const QString &capabilityCd)
{
    d->capability_cd = capabilityCd;
}

QString OperationCapability::capabilityNameZh() const
{
    return d->capability_name_zh;
}

void OperationCapability::setCapabilityNameZh(const QString &capabilityNameZh)
{
    d->capability_name_zh = capabilityNameZh;
}

QString OperationCapability::capabilityNameEn() const
{
    return d->capability_name_en;
}

void OperationCapability::setCapabilityNameEn(const QString &capabilityNameEn)
{
    d->capability_name_en = capabilityNameEn;
}

QDateTime OperationCapability::createdAt() const
{
    return d->created_at;
}

QString OperationCapability::createdBy() const
{
    return d->created_by;
}

void OperationCapability::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OperationCapability::updatedAt() const
{
    return d->updated_at;
}

QString OperationCapability::updatedBy() const
{
    return d->updated_by;
}

void OperationCapability::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

OperationCapability &OperationCapability::operator=(const OperationCapability &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OperationCapability OperationCapability::create(const QString &capabilityCd, const QString &capabilityNameZh, const QString &capabilityNameEn, const QString &createdBy, const QString &updatedBy)
{
    OperationCapabilityObject obj;
    obj.capability_cd = capabilityCd;
    obj.capability_name_zh = capabilityNameZh;
    obj.capability_name_en = capabilityNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OperationCapability();
    }
    return OperationCapability(obj);
}

OperationCapability OperationCapability::create(const QVariantMap &values)
{
    OperationCapability model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OperationCapability OperationCapability::get(int capabilityId)
{
    TSqlORMapper<OperationCapabilityObject> mapper;
    return OperationCapability(mapper.findByPrimaryKey(capabilityId));
}

int OperationCapability::count()
{
    TSqlORMapper<OperationCapabilityObject> mapper;
    return mapper.findCount();
}

QList<OperationCapability> OperationCapability::getAll()
{
    return tfGetModelListByCriteria<OperationCapability, OperationCapabilityObject>();
}

TModelObject *OperationCapability::modelData()
{
    return d.data();
}

const TModelObject *OperationCapability::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OperationCapability &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OperationCapability &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OperationCapability)
