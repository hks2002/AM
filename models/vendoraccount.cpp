#include <TreeFrogModel>
#include "vendoraccount.h"
#include "vendoraccountobject.h"
#include "fncaccount.h"
#include "vendor.h"

VendorAccount::VendorAccount()
    : TAbstractModel(), d(new VendorAccountObject())
{
    d->vendor_id = 0;
    d->account_id = 0;
}

VendorAccount::VendorAccount(const VendorAccount &other)
    : TAbstractModel(), d(new VendorAccountObject(*other.d))
{ }

VendorAccount::VendorAccount(const VendorAccountObject &object)
    : TAbstractModel(), d(new VendorAccountObject(object))
{ }

VendorAccount::~VendorAccount()
{
    // If the reference count becomes 0,
    // the shared data object 'VendorAccountObject' is deleted.
}

int VendorAccount::vendorId() const
{
    return d->vendor_id;
}

void VendorAccount::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int VendorAccount::accountId() const
{
    return d->account_id;
}

void VendorAccount::setAccountId(int accountId)
{
    d->account_id = accountId;
}

bool VendorAccount::mainBool() const
{
    return d->main_bool;
}

void VendorAccount::setMainBool(bool mainBool)
{
    d->main_bool = mainBool;
}

bool VendorAccount::activeBool() const
{
    return d->active_bool;
}

void VendorAccount::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime VendorAccount::createdAt() const
{
    return d->created_at;
}

QString VendorAccount::createdBy() const
{
    return d->created_by;
}

void VendorAccount::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime VendorAccount::updatedAt() const
{
    return d->updated_at;
}

QString VendorAccount::updatedBy() const
{
    return d->updated_by;
}

void VendorAccount::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount VendorAccount::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

Vendor VendorAccount::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

VendorAccount &VendorAccount::operator=(const VendorAccount &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VendorAccount VendorAccount::create(int vendorId, int accountId, bool mainBool, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    VendorAccountObject obj;
    obj.vendor_id = vendorId;
    obj.account_id = accountId;
    obj.main_bool = mainBool;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return VendorAccount();
    }
    return VendorAccount(obj);
}

VendorAccount VendorAccount::create(const QVariantMap &values)
{
    VendorAccount model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VendorAccount VendorAccount::get(int vendorId, int accountId)
{
    TSqlORMapper<VendorAccountObject> mapper;
    return VendorAccount(mapper.findByPrimaryKey(QVariantList()<<QVariant(vendorId)<<QVariant(accountId)));
}

int VendorAccount::count()
{
    TSqlORMapper<VendorAccountObject> mapper;
    return mapper.findCount();
}

QList<VendorAccount> VendorAccount::getAll()
{
    return tfGetModelListByCriteria<VendorAccount, VendorAccountObject>();
}

TModelObject *VendorAccount::modelData()
{
    return d.data();
}

const TModelObject *VendorAccount::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VendorAccount &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VendorAccount &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VendorAccount)
