#include <TreeFrogModel>
#include "locaddress.h"
#include "locaddressobject.h"
#include "address.h"
#include "loc.h"

LocAddress::LocAddress()
    : TAbstractModel(), d(new LocAddressObject())
{
    d->loc_id = 0;
    d->address_id = 0;
}

LocAddress::LocAddress(const LocAddress &other)
    : TAbstractModel(), d(new LocAddressObject(*other.d))
{ }

LocAddress::LocAddress(const LocAddressObject &object)
    : TAbstractModel(), d(new LocAddressObject(object))
{ }

LocAddress::~LocAddress()
{
    // If the reference count becomes 0,
    // the shared data object 'LocAddressObject' is deleted.
}

int LocAddress::locId() const
{
    return d->loc_id;
}

void LocAddress::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocAddress::addressId() const
{
    return d->address_id;
}

void LocAddress::setAddressId(int addressId)
{
    d->address_id = addressId;
}

QDateTime LocAddress::createdAt() const
{
    return d->created_at;
}

QString LocAddress::createdBy() const
{
    return d->created_by;
}

void LocAddress::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocAddress::updatedAt() const
{
    return d->updated_at;
}

QString LocAddress::updatedBy() const
{
    return d->updated_by;
}

void LocAddress::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Address LocAddress::addressByaddressId() const
{
 return Address::get(d->address_id);
}

Loc LocAddress::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocAddress &LocAddress::operator=(const LocAddress &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocAddress LocAddress::create(int locId, int addressId, const QString &createdBy, const QString &updatedBy)
{
    LocAddressObject obj;
    obj.loc_id = locId;
    obj.address_id = addressId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocAddress();
    }
    return LocAddress(obj);
}

LocAddress LocAddress::create(const QVariantMap &values)
{
    LocAddress model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocAddress LocAddress::get(int locId)
{
    TSqlORMapper<LocAddressObject> mapper;
    return LocAddress(mapper.findByPrimaryKey(locId));
}

int LocAddress::count()
{
    TSqlORMapper<LocAddressObject> mapper;
    return mapper.findCount();
}

QList<LocAddress> LocAddress::getAll()
{
    return tfGetModelListByCriteria<LocAddress, LocAddressObject>();
}

TModelObject *LocAddress::modelData()
{
    return d.data();
}

const TModelObject *LocAddress::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocAddress &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocAddress &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocAddress)
