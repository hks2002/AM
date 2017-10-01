#include <TreeFrogModel>
#include "refownby.h"
#include "refownbyobject.h"

RefOwnBy::RefOwnBy()
    : TAbstractModel(), d(new RefOwnByObject())
{ }

RefOwnBy::RefOwnBy(const RefOwnBy &other)
    : TAbstractModel(), d(new RefOwnByObject(*other.d))
{ }

RefOwnBy::RefOwnBy(const RefOwnByObject &object)
    : TAbstractModel(), d(new RefOwnByObject(object))
{ }

RefOwnBy::~RefOwnBy()
{
    // If the reference count becomes 0,
    // the shared data object 'RefOwnByObject' is deleted.
}

QString RefOwnBy::ownByCd() const
{
    return d->own_by_cd;
}

void RefOwnBy::setOwnByCd(const QString &ownByCd)
{
    d->own_by_cd = ownByCd;
}

QString RefOwnBy::ownByNameEn() const
{
    return d->own_by_name_en;
}

void RefOwnBy::setOwnByNameEn(const QString &ownByNameEn)
{
    d->own_by_name_en = ownByNameEn;
}

QString RefOwnBy::ownByNameZh() const
{
    return d->own_by_name_zh;
}

void RefOwnBy::setOwnByNameZh(const QString &ownByNameZh)
{
    d->own_by_name_zh = ownByNameZh;
}

QString RefOwnBy::ownByDesc() const
{
    return d->own_by_desc;
}

void RefOwnBy::setOwnByDesc(const QString &ownByDesc)
{
    d->own_by_desc = ownByDesc;
}

QDateTime RefOwnBy::createdAt() const
{
    return d->created_at;
}

QString RefOwnBy::createdBy() const
{
    return d->created_by;
}

void RefOwnBy::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefOwnBy::updatedAt() const
{
    return d->updated_at;
}

QString RefOwnBy::updatedBy() const
{
    return d->updated_by;
}

void RefOwnBy::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefOwnBy &RefOwnBy::operator=(const RefOwnBy &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefOwnBy RefOwnBy::create(const QString &ownByCd, const QString &ownByNameEn, const QString &ownByNameZh, const QString &ownByDesc, const QString &createdBy, const QString &updatedBy)
{
    RefOwnByObject obj;
    obj.own_by_cd = ownByCd;
    obj.own_by_name_en = ownByNameEn;
    obj.own_by_name_zh = ownByNameZh;
    obj.own_by_desc = ownByDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefOwnBy();
    }
    return RefOwnBy(obj);
}

RefOwnBy RefOwnBy::create(const QVariantMap &values)
{
    RefOwnBy model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefOwnBy RefOwnBy::get(const QString &ownByCd)
{
    TSqlORMapper<RefOwnByObject> mapper;
    return RefOwnBy(mapper.findByPrimaryKey(ownByCd));
}

int RefOwnBy::count()
{
    TSqlORMapper<RefOwnByObject> mapper;
    return mapper.findCount();
}

QList<RefOwnBy> RefOwnBy::getAll()
{
    return tfGetModelListByCriteria<RefOwnBy, RefOwnByObject>();
}

TModelObject *RefOwnBy::modelData()
{
    return d.data();
}

const TModelObject *RefOwnBy::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefOwnBy &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefOwnBy &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefOwnBy)
