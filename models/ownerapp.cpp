#include <TreeFrogModel>
#include "ownerapp.h"
#include "ownerappobject.h"
#include "vendor.h"
#include "org.h"
#include "refownertype.h"

OwnerApp::OwnerApp()
    : TAbstractModel(), d(new OwnerAppObject())
{
    d->owner_id = 0;
    d->org_id = 0;
    d->vendor_id = 0;
}

OwnerApp::OwnerApp(const OwnerApp &other)
    : TAbstractModel(), d(new OwnerAppObject(*other.d))
{ }

OwnerApp::OwnerApp(const OwnerAppObject &object)
    : TAbstractModel(), d(new OwnerAppObject(object))
{ }

OwnerApp::~OwnerApp()
{
    // If the reference count becomes 0,
    // the shared data object 'OwnerAppObject' is deleted.
}

int OwnerApp::ownerId() const
{
    return d->owner_id;
}

QString OwnerApp::ownerTypeCd() const
{
    return d->owner_type_cd;
}

void OwnerApp::setOwnerTypeCd(const QString &ownerTypeCd)
{
    d->owner_type_cd = ownerTypeCd;
}

int OwnerApp::orgId() const
{
    return d->org_id;
}

void OwnerApp::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int OwnerApp::vendorId() const
{
    return d->vendor_id;
}

void OwnerApp::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QDateTime OwnerApp::createdAt() const
{
    return d->created_at;
}

QString OwnerApp::createdBy() const
{
    return d->created_by;
}

void OwnerApp::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OwnerApp::updatedAt() const
{
    return d->updated_at;
}

QString OwnerApp::updatedBy() const
{
    return d->updated_by;
}

void OwnerApp::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor OwnerApp::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

Org OwnerApp::orgByorgId() const
{
 return Org::get(d->org_id);
}

RefOwnerType OwnerApp::refOwnerTypeByownerTypeCd() const
{
 return RefOwnerType::get(d->owner_type_cd);
}

OwnerApp &OwnerApp::operator=(const OwnerApp &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OwnerApp OwnerApp::create(const QString &ownerTypeCd, int orgId, int vendorId, const QString &createdBy, const QString &updatedBy)
{
    OwnerAppObject obj;
    obj.owner_type_cd = ownerTypeCd;
    obj.org_id = orgId;
    obj.vendor_id = vendorId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OwnerApp();
    }
    return OwnerApp(obj);
}

OwnerApp OwnerApp::create(const QVariantMap &values)
{
    OwnerApp model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OwnerApp OwnerApp::get(int ownerId)
{
    TSqlORMapper<OwnerAppObject> mapper;
    return OwnerApp(mapper.findByPrimaryKey(ownerId));
}

int OwnerApp::count()
{
    TSqlORMapper<OwnerAppObject> mapper;
    return mapper.findCount();
}

QList<OwnerApp> OwnerApp::getAll()
{
    return tfGetModelListByCriteria<OwnerApp, OwnerAppObject>();
}

TModelObject *OwnerApp::modelData()
{
    return d.data();
}

const TModelObject *OwnerApp::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OwnerApp &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OwnerApp &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OwnerApp)
