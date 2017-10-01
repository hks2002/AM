#include <TreeFrogModel>
#include "refpricetype.h"
#include "refpricetypeobject.h"

RefPriceType::RefPriceType()
    : TAbstractModel(), d(new RefPriceTypeObject())
{ }

RefPriceType::RefPriceType(const RefPriceType &other)
    : TAbstractModel(), d(new RefPriceTypeObject(*other.d))
{ }

RefPriceType::RefPriceType(const RefPriceTypeObject &object)
    : TAbstractModel(), d(new RefPriceTypeObject(object))
{ }

RefPriceType::~RefPriceType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPriceTypeObject' is deleted.
}

QString RefPriceType::priceTypeCd() const
{
    return d->price_type_cd;
}

void RefPriceType::setPriceTypeCd(const QString &priceTypeCd)
{
    d->price_type_cd = priceTypeCd;
}

QString RefPriceType::priceTypeNameEn() const
{
    return d->price_type_name_en;
}

void RefPriceType::setPriceTypeNameEn(const QString &priceTypeNameEn)
{
    d->price_type_name_en = priceTypeNameEn;
}

QString RefPriceType::priceTypeNameZh() const
{
    return d->price_type_name_zh;
}

void RefPriceType::setPriceTypeNameZh(const QString &priceTypeNameZh)
{
    d->price_type_name_zh = priceTypeNameZh;
}

QString RefPriceType::priceTypeDesc() const
{
    return d->price_type_desc;
}

void RefPriceType::setPriceTypeDesc(const QString &priceTypeDesc)
{
    d->price_type_desc = priceTypeDesc;
}

QDateTime RefPriceType::createdAt() const
{
    return d->created_at;
}

QString RefPriceType::createdBy() const
{
    return d->created_by;
}

void RefPriceType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPriceType::updatedAt() const
{
    return d->updated_at;
}

QString RefPriceType::updatedBy() const
{
    return d->updated_by;
}

void RefPriceType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPriceType &RefPriceType::operator=(const RefPriceType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPriceType RefPriceType::create(const QString &priceTypeCd, const QString &priceTypeNameEn, const QString &priceTypeNameZh, const QString &priceTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPriceTypeObject obj;
    obj.price_type_cd = priceTypeCd;
    obj.price_type_name_en = priceTypeNameEn;
    obj.price_type_name_zh = priceTypeNameZh;
    obj.price_type_desc = priceTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPriceType();
    }
    return RefPriceType(obj);
}

RefPriceType RefPriceType::create(const QVariantMap &values)
{
    RefPriceType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPriceType RefPriceType::get(const QString &priceTypeCd)
{
    TSqlORMapper<RefPriceTypeObject> mapper;
    return RefPriceType(mapper.findByPrimaryKey(priceTypeCd));
}

int RefPriceType::count()
{
    TSqlORMapper<RefPriceTypeObject> mapper;
    return mapper.findCount();
}

QList<RefPriceType> RefPriceType::getAll()
{
    return tfGetModelListByCriteria<RefPriceType, RefPriceTypeObject>();
}

TModelObject *RefPriceType::modelData()
{
    return d.data();
}

const TModelObject *RefPriceType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPriceType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPriceType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPriceType)
