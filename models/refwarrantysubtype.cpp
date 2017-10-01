#include <TreeFrogModel>
#include "refwarrantysubtype.h"
#include "refwarrantysubtypeobject.h"

RefWarrantySubtype::RefWarrantySubtype()
    : TAbstractModel(), d(new RefWarrantySubtypeObject())
{ }

RefWarrantySubtype::RefWarrantySubtype(const RefWarrantySubtype &other)
    : TAbstractModel(), d(new RefWarrantySubtypeObject(*other.d))
{ }

RefWarrantySubtype::RefWarrantySubtype(const RefWarrantySubtypeObject &object)
    : TAbstractModel(), d(new RefWarrantySubtypeObject(object))
{ }

RefWarrantySubtype::~RefWarrantySubtype()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWarrantySubtypeObject' is deleted.
}

QString RefWarrantySubtype::warrantySubtypeCd() const
{
    return d->warranty_subtype_cd;
}

void RefWarrantySubtype::setWarrantySubtypeCd(const QString &warrantySubtypeCd)
{
    d->warranty_subtype_cd = warrantySubtypeCd;
}

QString RefWarrantySubtype::warrantySubtypeNameEn() const
{
    return d->warranty_subtype_name_en;
}

void RefWarrantySubtype::setWarrantySubtypeNameEn(const QString &warrantySubtypeNameEn)
{
    d->warranty_subtype_name_en = warrantySubtypeNameEn;
}

QString RefWarrantySubtype::warrantySubtypeNameZh() const
{
    return d->warranty_subtype_name_zh;
}

void RefWarrantySubtype::setWarrantySubtypeNameZh(const QString &warrantySubtypeNameZh)
{
    d->warranty_subtype_name_zh = warrantySubtypeNameZh;
}

QString RefWarrantySubtype::warrantySubtypeDesc() const
{
    return d->warranty_subtype_desc;
}

void RefWarrantySubtype::setWarrantySubtypeDesc(const QString &warrantySubtypeDesc)
{
    d->warranty_subtype_desc = warrantySubtypeDesc;
}

QDateTime RefWarrantySubtype::createdAt() const
{
    return d->created_at;
}

QString RefWarrantySubtype::createdBy() const
{
    return d->created_by;
}

void RefWarrantySubtype::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWarrantySubtype::updatedAt() const
{
    return d->updated_at;
}

QString RefWarrantySubtype::updatedBy() const
{
    return d->updated_by;
}

void RefWarrantySubtype::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantySubtype &RefWarrantySubtype::operator=(const RefWarrantySubtype &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWarrantySubtype RefWarrantySubtype::create(const QString &warrantySubtypeCd, const QString &warrantySubtypeNameEn, const QString &warrantySubtypeNameZh, const QString &warrantySubtypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefWarrantySubtypeObject obj;
    obj.warranty_subtype_cd = warrantySubtypeCd;
    obj.warranty_subtype_name_en = warrantySubtypeNameEn;
    obj.warranty_subtype_name_zh = warrantySubtypeNameZh;
    obj.warranty_subtype_desc = warrantySubtypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWarrantySubtype();
    }
    return RefWarrantySubtype(obj);
}

RefWarrantySubtype RefWarrantySubtype::create(const QVariantMap &values)
{
    RefWarrantySubtype model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWarrantySubtype RefWarrantySubtype::get(const QString &warrantySubtypeCd)
{
    TSqlORMapper<RefWarrantySubtypeObject> mapper;
    return RefWarrantySubtype(mapper.findByPrimaryKey(warrantySubtypeCd));
}

int RefWarrantySubtype::count()
{
    TSqlORMapper<RefWarrantySubtypeObject> mapper;
    return mapper.findCount();
}

QList<RefWarrantySubtype> RefWarrantySubtype::getAll()
{
    return tfGetModelListByCriteria<RefWarrantySubtype, RefWarrantySubtypeObject>();
}

TModelObject *RefWarrantySubtype::modelData()
{
    return d.data();
}

const TModelObject *RefWarrantySubtype::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWarrantySubtype &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWarrantySubtype &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWarrantySubtype)
