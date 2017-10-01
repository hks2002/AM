#include <TreeFrogModel>
#include "refownertype.h"
#include "refownertypeobject.h"

RefOwnerType::RefOwnerType()
    : TAbstractModel(), d(new RefOwnerTypeObject())
{ }

RefOwnerType::RefOwnerType(const RefOwnerType &other)
    : TAbstractModel(), d(new RefOwnerTypeObject(*other.d))
{ }

RefOwnerType::RefOwnerType(const RefOwnerTypeObject &object)
    : TAbstractModel(), d(new RefOwnerTypeObject(object))
{ }

RefOwnerType::~RefOwnerType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefOwnerTypeObject' is deleted.
}

QString RefOwnerType::ownerTypeCd() const
{
    return d->owner_type_cd;
}

void RefOwnerType::setOwnerTypeCd(const QString &ownerTypeCd)
{
    d->owner_type_cd = ownerTypeCd;
}

QString RefOwnerType::ownerTypeNameEn() const
{
    return d->owner_type_name_en;
}

void RefOwnerType::setOwnerTypeNameEn(const QString &ownerTypeNameEn)
{
    d->owner_type_name_en = ownerTypeNameEn;
}

QString RefOwnerType::ownerTypeNameZh() const
{
    return d->owner_type_name_zh;
}

void RefOwnerType::setOwnerTypeNameZh(const QString &ownerTypeNameZh)
{
    d->owner_type_name_zh = ownerTypeNameZh;
}

QString RefOwnerType::ownerTypeDesc() const
{
    return d->owner_type_desc;
}

void RefOwnerType::setOwnerTypeDesc(const QString &ownerTypeDesc)
{
    d->owner_type_desc = ownerTypeDesc;
}

QDateTime RefOwnerType::createdAt() const
{
    return d->created_at;
}

QString RefOwnerType::createdBy() const
{
    return d->created_by;
}

void RefOwnerType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefOwnerType::updatedAt() const
{
    return d->updated_at;
}

QString RefOwnerType::updatedBy() const
{
    return d->updated_by;
}

void RefOwnerType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefOwnerType &RefOwnerType::operator=(const RefOwnerType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefOwnerType RefOwnerType::create(const QString &ownerTypeCd, const QString &ownerTypeNameEn, const QString &ownerTypeNameZh, const QString &ownerTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefOwnerTypeObject obj;
    obj.owner_type_cd = ownerTypeCd;
    obj.owner_type_name_en = ownerTypeNameEn;
    obj.owner_type_name_zh = ownerTypeNameZh;
    obj.owner_type_desc = ownerTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefOwnerType();
    }
    return RefOwnerType(obj);
}

RefOwnerType RefOwnerType::create(const QVariantMap &values)
{
    RefOwnerType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefOwnerType RefOwnerType::get(const QString &ownerTypeCd)
{
    TSqlORMapper<RefOwnerTypeObject> mapper;
    return RefOwnerType(mapper.findByPrimaryKey(ownerTypeCd));
}

int RefOwnerType::count()
{
    TSqlORMapper<RefOwnerTypeObject> mapper;
    return mapper.findCount();
}

QList<RefOwnerType> RefOwnerType::getAll()
{
    return tfGetModelListByCriteria<RefOwnerType, RefOwnerTypeObject>();
}

TModelObject *RefOwnerType::modelData()
{
    return d.data();
}

const TModelObject *RefOwnerType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefOwnerType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefOwnerType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefOwnerType)
