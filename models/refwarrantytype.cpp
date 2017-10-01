#include <TreeFrogModel>
#include "refwarrantytype.h"
#include "refwarrantytypeobject.h"

RefWarrantyType::RefWarrantyType()
    : TAbstractModel(), d(new RefWarrantyTypeObject())
{ }

RefWarrantyType::RefWarrantyType(const RefWarrantyType &other)
    : TAbstractModel(), d(new RefWarrantyTypeObject(*other.d))
{ }

RefWarrantyType::RefWarrantyType(const RefWarrantyTypeObject &object)
    : TAbstractModel(), d(new RefWarrantyTypeObject(object))
{ }

RefWarrantyType::~RefWarrantyType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWarrantyTypeObject' is deleted.
}

QString RefWarrantyType::warrantyTypeCd() const
{
    return d->warranty_type_cd;
}

void RefWarrantyType::setWarrantyTypeCd(const QString &warrantyTypeCd)
{
    d->warranty_type_cd = warrantyTypeCd;
}

QString RefWarrantyType::warrantyTypeNameEn() const
{
    return d->warranty_type_name_en;
}

void RefWarrantyType::setWarrantyTypeNameEn(const QString &warrantyTypeNameEn)
{
    d->warranty_type_name_en = warrantyTypeNameEn;
}

QString RefWarrantyType::warrantyTypeNameZh() const
{
    return d->warranty_type_name_zh;
}

void RefWarrantyType::setWarrantyTypeNameZh(const QString &warrantyTypeNameZh)
{
    d->warranty_type_name_zh = warrantyTypeNameZh;
}

QString RefWarrantyType::warrantyTypeDesc() const
{
    return d->warranty_type_desc;
}

void RefWarrantyType::setWarrantyTypeDesc(const QString &warrantyTypeDesc)
{
    d->warranty_type_desc = warrantyTypeDesc;
}

QDateTime RefWarrantyType::createdAt() const
{
    return d->created_at;
}

QString RefWarrantyType::createdBy() const
{
    return d->created_by;
}

void RefWarrantyType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWarrantyType::updatedAt() const
{
    return d->updated_at;
}

QString RefWarrantyType::updatedBy() const
{
    return d->updated_by;
}

void RefWarrantyType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyType &RefWarrantyType::operator=(const RefWarrantyType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWarrantyType RefWarrantyType::create(const QString &warrantyTypeCd, const QString &warrantyTypeNameEn, const QString &warrantyTypeNameZh, const QString &warrantyTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefWarrantyTypeObject obj;
    obj.warranty_type_cd = warrantyTypeCd;
    obj.warranty_type_name_en = warrantyTypeNameEn;
    obj.warranty_type_name_zh = warrantyTypeNameZh;
    obj.warranty_type_desc = warrantyTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWarrantyType();
    }
    return RefWarrantyType(obj);
}

RefWarrantyType RefWarrantyType::create(const QVariantMap &values)
{
    RefWarrantyType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWarrantyType RefWarrantyType::get(const QString &warrantyTypeCd)
{
    TSqlORMapper<RefWarrantyTypeObject> mapper;
    return RefWarrantyType(mapper.findByPrimaryKey(warrantyTypeCd));
}

int RefWarrantyType::count()
{
    TSqlORMapper<RefWarrantyTypeObject> mapper;
    return mapper.findCount();
}

QList<RefWarrantyType> RefWarrantyType::getAll()
{
    return tfGetModelListByCriteria<RefWarrantyType, RefWarrantyTypeObject>();
}

TModelObject *RefWarrantyType::modelData()
{
    return d.data();
}

const TModelObject *RefWarrantyType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWarrantyType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWarrantyType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWarrantyType)
