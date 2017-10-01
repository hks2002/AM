#include <TreeFrogModel>
#include "refloctype.h"
#include "refloctypeobject.h"

RefLocType::RefLocType()
    : TAbstractModel(), d(new RefLocTypeObject())
{ }

RefLocType::RefLocType(const RefLocType &other)
    : TAbstractModel(), d(new RefLocTypeObject(*other.d))
{ }

RefLocType::RefLocType(const RefLocTypeObject &object)
    : TAbstractModel(), d(new RefLocTypeObject(object))
{ }

RefLocType::~RefLocType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefLocTypeObject' is deleted.
}

QString RefLocType::locTypeCd() const
{
    return d->loc_type_cd;
}

void RefLocType::setLocTypeCd(const QString &locTypeCd)
{
    d->loc_type_cd = locTypeCd;
}

QString RefLocType::locTypeNameEn() const
{
    return d->loc_type_name_en;
}

void RefLocType::setLocTypeNameEn(const QString &locTypeNameEn)
{
    d->loc_type_name_en = locTypeNameEn;
}

QString RefLocType::locTypeNameZh() const
{
    return d->loc_type_name_zh;
}

void RefLocType::setLocTypeNameZh(const QString &locTypeNameZh)
{
    d->loc_type_name_zh = locTypeNameZh;
}

QString RefLocType::locTypeDesc() const
{
    return d->loc_type_desc;
}

void RefLocType::setLocTypeDesc(const QString &locTypeDesc)
{
    d->loc_type_desc = locTypeDesc;
}

QDateTime RefLocType::createdAt() const
{
    return d->created_at;
}

QString RefLocType::createdBy() const
{
    return d->created_by;
}

void RefLocType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefLocType::updatedAt() const
{
    return d->updated_at;
}

QString RefLocType::updatedBy() const
{
    return d->updated_by;
}

void RefLocType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLocType &RefLocType::operator=(const RefLocType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefLocType RefLocType::create(const QString &locTypeCd, const QString &locTypeNameEn, const QString &locTypeNameZh, const QString &locTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefLocTypeObject obj;
    obj.loc_type_cd = locTypeCd;
    obj.loc_type_name_en = locTypeNameEn;
    obj.loc_type_name_zh = locTypeNameZh;
    obj.loc_type_desc = locTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefLocType();
    }
    return RefLocType(obj);
}

RefLocType RefLocType::create(const QVariantMap &values)
{
    RefLocType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefLocType RefLocType::get(const QString &locTypeCd)
{
    TSqlORMapper<RefLocTypeObject> mapper;
    return RefLocType(mapper.findByPrimaryKey(locTypeCd));
}

int RefLocType::count()
{
    TSqlORMapper<RefLocTypeObject> mapper;
    return mapper.findCount();
}

QList<RefLocType> RefLocType::getAll()
{
    return tfGetModelListByCriteria<RefLocType, RefLocTypeObject>();
}

TModelObject *RefLocType::modelData()
{
    return d.data();
}

const TModelObject *RefLocType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefLocType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefLocType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefLocType)
