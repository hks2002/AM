#include <TreeFrogModel>
#include "orgaddress.h"
#include "orgaddressobject.h"
#include "address.h"
#include "org.h"

OrgAddress::OrgAddress()
    : TAbstractModel(), d(new OrgAddressObject())
{
    d->org_id = 0;
    d->address_id = 0;
}

OrgAddress::OrgAddress(const OrgAddress &other)
    : TAbstractModel(), d(new OrgAddressObject(*other.d))
{ }

OrgAddress::OrgAddress(const OrgAddressObject &object)
    : TAbstractModel(), d(new OrgAddressObject(object))
{ }

OrgAddress::~OrgAddress()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgAddressObject' is deleted.
}

int OrgAddress::orgId() const
{
    return d->org_id;
}

void OrgAddress::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int OrgAddress::addressId() const
{
    return d->address_id;
}

void OrgAddress::setAddressId(int addressId)
{
    d->address_id = addressId;
}

QDateTime OrgAddress::createdAt() const
{
    return d->created_at;
}

QString OrgAddress::createdBy() const
{
    return d->created_by;
}

void OrgAddress::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OrgAddress::updatedAt() const
{
    return d->updated_at;
}

QString OrgAddress::updatedBy() const
{
    return d->updated_by;
}

void OrgAddress::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Address OrgAddress::addressByaddressId() const
{
 return Address::get(d->address_id);
}

Org OrgAddress::orgByorgId() const
{
 return Org::get(d->org_id);
}

OrgAddress &OrgAddress::operator=(const OrgAddress &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OrgAddress OrgAddress::create(int orgId, int addressId, const QString &createdBy, const QString &updatedBy)
{
    OrgAddressObject obj;
    obj.org_id = orgId;
    obj.address_id = addressId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OrgAddress();
    }
    return OrgAddress(obj);
}

OrgAddress OrgAddress::create(const QVariantMap &values)
{
    OrgAddress model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OrgAddress OrgAddress::get(int orgId)
{
    TSqlORMapper<OrgAddressObject> mapper;
    return OrgAddress(mapper.findByPrimaryKey(orgId));
}

int OrgAddress::count()
{
    TSqlORMapper<OrgAddressObject> mapper;
    return mapper.findCount();
}

QList<OrgAddress> OrgAddress::getAll()
{
    return tfGetModelListByCriteria<OrgAddress, OrgAddressObject>();
}

TModelObject *OrgAddress::modelData()
{
    return d.data();
}

const TModelObject *OrgAddress::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OrgAddress &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OrgAddress &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OrgAddress)
