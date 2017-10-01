#include <TreeFrogModel>
#include "advsryvendor.h"
#include "advsryvendorobject.h"
#include "vendor.h"
#include "advsry.h"

AdvsryVendor::AdvsryVendor()
    : TAbstractModel(), d(new AdvsryVendorObject())
{
    d->advsry_id = 0;
    d->vendor_id = 0;
}

AdvsryVendor::AdvsryVendor(const AdvsryVendor &other)
    : TAbstractModel(), d(new AdvsryVendorObject(*other.d))
{ }

AdvsryVendor::AdvsryVendor(const AdvsryVendorObject &object)
    : TAbstractModel(), d(new AdvsryVendorObject(object))
{ }

AdvsryVendor::~AdvsryVendor()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryVendorObject' is deleted.
}

int AdvsryVendor::advsryId() const
{
    return d->advsry_id;
}

void AdvsryVendor::setAdvsryId(int advsryId)
{
    d->advsry_id = advsryId;
}

int AdvsryVendor::vendorId() const
{
    return d->vendor_id;
}

void AdvsryVendor::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

bool AdvsryVendor::activeBool() const
{
    return d->active_bool;
}

void AdvsryVendor::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime AdvsryVendor::createdAt() const
{
    return d->created_at;
}

QString AdvsryVendor::createdBy() const
{
    return d->created_by;
}

void AdvsryVendor::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryVendor::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryVendor::updatedBy() const
{
    return d->updated_by;
}

void AdvsryVendor::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor AdvsryVendor::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

Advsry AdvsryVendor::advsryByadvsryId() const
{
 return Advsry::get(d->advsry_id);
}

AdvsryVendor &AdvsryVendor::operator=(const AdvsryVendor &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryVendor AdvsryVendor::create(int advsryId, int vendorId, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    AdvsryVendorObject obj;
    obj.advsry_id = advsryId;
    obj.vendor_id = vendorId;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryVendor();
    }
    return AdvsryVendor(obj);
}

AdvsryVendor AdvsryVendor::create(const QVariantMap &values)
{
    AdvsryVendor model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryVendor AdvsryVendor::get(int advsryId, int vendorId)
{
    TSqlORMapper<AdvsryVendorObject> mapper;
    return AdvsryVendor(mapper.findByPrimaryKey(QVariantList()<<QVariant(advsryId)<<QVariant(vendorId)));
}

int AdvsryVendor::count()
{
    TSqlORMapper<AdvsryVendorObject> mapper;
    return mapper.findCount();
}

QList<AdvsryVendor> AdvsryVendor::getAll()
{
    return tfGetModelListByCriteria<AdvsryVendor, AdvsryVendorObject>();
}

TModelObject *AdvsryVendor::modelData()
{
    return d.data();
}

const TModelObject *AdvsryVendor::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryVendor &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryVendor &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryVendor)
