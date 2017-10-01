#include <TreeFrogModel>
#include "eqppartnovendorpur.h"
#include "eqppartnovendorpurobject.h"
#include "vendor.h"
#include "eqppartno.h"

EqpPartNoVendorPur::EqpPartNoVendorPur()
    : TAbstractModel(), d(new EqpPartNoVendorPurObject())
{
    d->part_no_id = 0;
    d->vendor_id = 0;
    d->min_pur_account = 0;
}

EqpPartNoVendorPur::EqpPartNoVendorPur(const EqpPartNoVendorPur &other)
    : TAbstractModel(), d(new EqpPartNoVendorPurObject(*other.d))
{ }

EqpPartNoVendorPur::EqpPartNoVendorPur(const EqpPartNoVendorPurObject &object)
    : TAbstractModel(), d(new EqpPartNoVendorPurObject(object))
{ }

EqpPartNoVendorPur::~EqpPartNoVendorPur()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoVendorPurObject' is deleted.
}

int EqpPartNoVendorPur::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoVendorPur::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoVendorPur::vendorId() const
{
    return d->vendor_id;
}

void EqpPartNoVendorPur::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

bool EqpPartNoVendorPur::prefBool() const
{
    return d->pref_bool;
}

void EqpPartNoVendorPur::setPrefBool(bool prefBool)
{
    d->pref_bool = prefBool;
}

QString EqpPartNoVendorPur::partNoVendor() const
{
    return d->part_no_vendor;
}

void EqpPartNoVendorPur::setPartNoVendor(const QString &partNoVendor)
{
    d->part_no_vendor = partNoVendor;
}

int EqpPartNoVendorPur::minPurAccount() const
{
    return d->min_pur_account;
}

void EqpPartNoVendorPur::setMinPurAccount(int minPurAccount)
{
    d->min_pur_account = minPurAccount;
}

QDateTime EqpPartNoVendorPur::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoVendorPur::createdBy() const
{
    return d->created_by;
}

void EqpPartNoVendorPur::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoVendorPur::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoVendorPur::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoVendorPur::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor EqpPartNoVendorPur::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

EqpPartNo EqpPartNoVendorPur::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoVendorPur &EqpPartNoVendorPur::operator=(const EqpPartNoVendorPur &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoVendorPur EqpPartNoVendorPur::create(int partNoId, int vendorId, bool prefBool, const QString &partNoVendor, int minPurAccount, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoVendorPurObject obj;
    obj.part_no_id = partNoId;
    obj.vendor_id = vendorId;
    obj.pref_bool = prefBool;
    obj.part_no_vendor = partNoVendor;
    obj.min_pur_account = minPurAccount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoVendorPur();
    }
    return EqpPartNoVendorPur(obj);
}

EqpPartNoVendorPur EqpPartNoVendorPur::create(const QVariantMap &values)
{
    EqpPartNoVendorPur model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoVendorPur EqpPartNoVendorPur::get(int partNoId, int vendorId)
{
    TSqlORMapper<EqpPartNoVendorPurObject> mapper;
    return EqpPartNoVendorPur(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(vendorId)));
}

int EqpPartNoVendorPur::count()
{
    TSqlORMapper<EqpPartNoVendorPurObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoVendorPur> EqpPartNoVendorPur::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoVendorPur, EqpPartNoVendorPurObject>();
}

TModelObject *EqpPartNoVendorPur::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoVendorPur::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorPur &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorPur &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoVendorPur)
