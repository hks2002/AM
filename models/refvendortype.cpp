#include <TreeFrogModel>
#include "refvendortype.h"
#include "refvendortypeobject.h"

RefVendorType::RefVendorType()
    : TAbstractModel(), d(new RefVendorTypeObject())
{ }

RefVendorType::RefVendorType(const RefVendorType &other)
    : TAbstractModel(), d(new RefVendorTypeObject(*other.d))
{ }

RefVendorType::RefVendorType(const RefVendorTypeObject &object)
    : TAbstractModel(), d(new RefVendorTypeObject(object))
{ }

RefVendorType::~RefVendorType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefVendorTypeObject' is deleted.
}

QString RefVendorType::vendorTypeCd() const
{
    return d->vendor_type_cd;
}

void RefVendorType::setVendorTypeCd(const QString &vendorTypeCd)
{
    d->vendor_type_cd = vendorTypeCd;
}

QString RefVendorType::vendorTypeNameEn() const
{
    return d->vendor_type_name_en;
}

void RefVendorType::setVendorTypeNameEn(const QString &vendorTypeNameEn)
{
    d->vendor_type_name_en = vendorTypeNameEn;
}

QString RefVendorType::vendorTypeNameZh() const
{
    return d->vendor_type_name_zh;
}

void RefVendorType::setVendorTypeNameZh(const QString &vendorTypeNameZh)
{
    d->vendor_type_name_zh = vendorTypeNameZh;
}

QString RefVendorType::vendorTypeDesc() const
{
    return d->vendor_type_desc;
}

void RefVendorType::setVendorTypeDesc(const QString &vendorTypeDesc)
{
    d->vendor_type_desc = vendorTypeDesc;
}

QDateTime RefVendorType::createdAt() const
{
    return d->created_at;
}

QString RefVendorType::createdBy() const
{
    return d->created_by;
}

void RefVendorType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefVendorType::updatedAt() const
{
    return d->updated_at;
}

QString RefVendorType::updatedBy() const
{
    return d->updated_by;
}

void RefVendorType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefVendorType &RefVendorType::operator=(const RefVendorType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefVendorType RefVendorType::create(const QString &vendorTypeCd, const QString &vendorTypeNameEn, const QString &vendorTypeNameZh, const QString &vendorTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefVendorTypeObject obj;
    obj.vendor_type_cd = vendorTypeCd;
    obj.vendor_type_name_en = vendorTypeNameEn;
    obj.vendor_type_name_zh = vendorTypeNameZh;
    obj.vendor_type_desc = vendorTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefVendorType();
    }
    return RefVendorType(obj);
}

RefVendorType RefVendorType::create(const QVariantMap &values)
{
    RefVendorType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefVendorType RefVendorType::get(const QString &vendorTypeCd)
{
    TSqlORMapper<RefVendorTypeObject> mapper;
    return RefVendorType(mapper.findByPrimaryKey(vendorTypeCd));
}

int RefVendorType::count()
{
    TSqlORMapper<RefVendorTypeObject> mapper;
    return mapper.findCount();
}

QList<RefVendorType> RefVendorType::getAll()
{
    return tfGetModelListByCriteria<RefVendorType, RefVendorTypeObject>();
}

TModelObject *RefVendorType::modelData()
{
    return d.data();
}

const TModelObject *RefVendorType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefVendorType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefVendorType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefVendorType)
