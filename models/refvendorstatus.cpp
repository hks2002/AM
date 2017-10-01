#include <TreeFrogModel>
#include "refvendorstatus.h"
#include "refvendorstatusobject.h"

RefVendorStatus::RefVendorStatus()
    : TAbstractModel(), d(new RefVendorStatusObject())
{ }

RefVendorStatus::RefVendorStatus(const RefVendorStatus &other)
    : TAbstractModel(), d(new RefVendorStatusObject(*other.d))
{ }

RefVendorStatus::RefVendorStatus(const RefVendorStatusObject &object)
    : TAbstractModel(), d(new RefVendorStatusObject(object))
{ }

RefVendorStatus::~RefVendorStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefVendorStatusObject' is deleted.
}

QString RefVendorStatus::vendorStatusCd() const
{
    return d->vendor_status_cd;
}

void RefVendorStatus::setVendorStatusCd(const QString &vendorStatusCd)
{
    d->vendor_status_cd = vendorStatusCd;
}

QString RefVendorStatus::vendorStatusNameEn() const
{
    return d->vendor_status_name_en;
}

void RefVendorStatus::setVendorStatusNameEn(const QString &vendorStatusNameEn)
{
    d->vendor_status_name_en = vendorStatusNameEn;
}

QString RefVendorStatus::vendorStatusNameZh() const
{
    return d->vendor_status_name_zh;
}

void RefVendorStatus::setVendorStatusNameZh(const QString &vendorStatusNameZh)
{
    d->vendor_status_name_zh = vendorStatusNameZh;
}

QString RefVendorStatus::vendorStatusDesc() const
{
    return d->vendor_status_desc;
}

void RefVendorStatus::setVendorStatusDesc(const QString &vendorStatusDesc)
{
    d->vendor_status_desc = vendorStatusDesc;
}

QDateTime RefVendorStatus::createdAt() const
{
    return d->created_at;
}

QString RefVendorStatus::createdBy() const
{
    return d->created_by;
}

void RefVendorStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefVendorStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefVendorStatus::updatedBy() const
{
    return d->updated_by;
}

void RefVendorStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefVendorStatus &RefVendorStatus::operator=(const RefVendorStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefVendorStatus RefVendorStatus::create(const QString &vendorStatusCd, const QString &vendorStatusNameEn, const QString &vendorStatusNameZh, const QString &vendorStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefVendorStatusObject obj;
    obj.vendor_status_cd = vendorStatusCd;
    obj.vendor_status_name_en = vendorStatusNameEn;
    obj.vendor_status_name_zh = vendorStatusNameZh;
    obj.vendor_status_desc = vendorStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefVendorStatus();
    }
    return RefVendorStatus(obj);
}

RefVendorStatus RefVendorStatus::create(const QVariantMap &values)
{
    RefVendorStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefVendorStatus RefVendorStatus::get(const QString &vendorStatusCd)
{
    TSqlORMapper<RefVendorStatusObject> mapper;
    return RefVendorStatus(mapper.findByPrimaryKey(vendorStatusCd));
}

int RefVendorStatus::count()
{
    TSqlORMapper<RefVendorStatusObject> mapper;
    return mapper.findCount();
}

QList<RefVendorStatus> RefVendorStatus::getAll()
{
    return tfGetModelListByCriteria<RefVendorStatus, RefVendorStatusObject>();
}

TModelObject *RefVendorStatus::modelData()
{
    return d.data();
}

const TModelObject *RefVendorStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefVendorStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefVendorStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefVendorStatus)
