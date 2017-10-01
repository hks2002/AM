#include <TreeFrogModel>
#include "refwarrantytypesubtype.h"
#include "refwarrantytypesubtypeobject.h"

RefWarrantyTypeSubtype::RefWarrantyTypeSubtype()
    : TAbstractModel(), d(new RefWarrantyTypeSubtypeObject())
{ }

RefWarrantyTypeSubtype::RefWarrantyTypeSubtype(const RefWarrantyTypeSubtype &other)
    : TAbstractModel(), d(new RefWarrantyTypeSubtypeObject(*other.d))
{ }

RefWarrantyTypeSubtype::RefWarrantyTypeSubtype(const RefWarrantyTypeSubtypeObject &object)
    : TAbstractModel(), d(new RefWarrantyTypeSubtypeObject(object))
{ }

RefWarrantyTypeSubtype::~RefWarrantyTypeSubtype()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWarrantyTypeSubtypeObject' is deleted.
}

QString RefWarrantyTypeSubtype::warrantyTypeCd() const
{
    return d->warranty_type_cd;
}

void RefWarrantyTypeSubtype::setWarrantyTypeCd(const QString &warrantyTypeCd)
{
    d->warranty_type_cd = warrantyTypeCd;
}

QString RefWarrantyTypeSubtype::warrantySubtypeCd() const
{
    return d->warranty_subtype_cd;
}

void RefWarrantyTypeSubtype::setWarrantySubtypeCd(const QString &warrantySubtypeCd)
{
    d->warranty_subtype_cd = warrantySubtypeCd;
}

QDateTime RefWarrantyTypeSubtype::createdAt() const
{
    return d->created_at;
}

QString RefWarrantyTypeSubtype::createdBy() const
{
    return d->created_by;
}

void RefWarrantyTypeSubtype::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWarrantyTypeSubtype::updatedAt() const
{
    return d->updated_at;
}

QString RefWarrantyTypeSubtype::updatedBy() const
{
    return d->updated_by;
}

void RefWarrantyTypeSubtype::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyTypeSubtype &RefWarrantyTypeSubtype::operator=(const RefWarrantyTypeSubtype &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWarrantyTypeSubtype RefWarrantyTypeSubtype::create(const QString &warrantyTypeCd, const QString &warrantySubtypeCd, const QString &createdBy, const QString &updatedBy)
{
    RefWarrantyTypeSubtypeObject obj;
    obj.warranty_type_cd = warrantyTypeCd;
    obj.warranty_subtype_cd = warrantySubtypeCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWarrantyTypeSubtype();
    }
    return RefWarrantyTypeSubtype(obj);
}

RefWarrantyTypeSubtype RefWarrantyTypeSubtype::create(const QVariantMap &values)
{
    RefWarrantyTypeSubtype model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWarrantyTypeSubtype RefWarrantyTypeSubtype::get(const QString &warrantyTypeCd, const QString &warrantySubtypeCd)
{
    TSqlORMapper<RefWarrantyTypeSubtypeObject> mapper;
    return RefWarrantyTypeSubtype(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyTypeCd)<<QVariant(warrantySubtypeCd)));
}

int RefWarrantyTypeSubtype::count()
{
    TSqlORMapper<RefWarrantyTypeSubtypeObject> mapper;
    return mapper.findCount();
}

QList<RefWarrantyTypeSubtype> RefWarrantyTypeSubtype::getAll()
{
    return tfGetModelListByCriteria<RefWarrantyTypeSubtype, RefWarrantyTypeSubtypeObject>();
}

TModelObject *RefWarrantyTypeSubtype::modelData()
{
    return d.data();
}

const TModelObject *RefWarrantyTypeSubtype::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWarrantyTypeSubtype &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWarrantyTypeSubtype &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWarrantyTypeSubtype)
