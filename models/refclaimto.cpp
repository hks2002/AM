#include <TreeFrogModel>
#include "refclaimto.h"
#include "refclaimtoobject.h"

RefClaimTo::RefClaimTo()
    : TAbstractModel(), d(new RefClaimToObject())
{ }

RefClaimTo::RefClaimTo(const RefClaimTo &other)
    : TAbstractModel(), d(new RefClaimToObject(*other.d))
{ }

RefClaimTo::RefClaimTo(const RefClaimToObject &object)
    : TAbstractModel(), d(new RefClaimToObject(object))
{ }

RefClaimTo::~RefClaimTo()
{
    // If the reference count becomes 0,
    // the shared data object 'RefClaimToObject' is deleted.
}

QString RefClaimTo::claimToCd() const
{
    return d->claim_to_cd;
}

void RefClaimTo::setClaimToCd(const QString &claimToCd)
{
    d->claim_to_cd = claimToCd;
}

QString RefClaimTo::claimToNameEn() const
{
    return d->claim_to_name_en;
}

void RefClaimTo::setClaimToNameEn(const QString &claimToNameEn)
{
    d->claim_to_name_en = claimToNameEn;
}

QString RefClaimTo::claimToNameZh() const
{
    return d->claim_to_name_zh;
}

void RefClaimTo::setClaimToNameZh(const QString &claimToNameZh)
{
    d->claim_to_name_zh = claimToNameZh;
}

QString RefClaimTo::claimToDesc() const
{
    return d->claim_to_desc;
}

void RefClaimTo::setClaimToDesc(const QString &claimToDesc)
{
    d->claim_to_desc = claimToDesc;
}

QDateTime RefClaimTo::createdAt() const
{
    return d->created_at;
}

QString RefClaimTo::createdBy() const
{
    return d->created_by;
}

void RefClaimTo::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefClaimTo::updatedAt() const
{
    return d->updated_at;
}

QString RefClaimTo::updatedBy() const
{
    return d->updated_by;
}

void RefClaimTo::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefClaimTo &RefClaimTo::operator=(const RefClaimTo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefClaimTo RefClaimTo::create(const QString &claimToCd, const QString &claimToNameEn, const QString &claimToNameZh, const QString &claimToDesc, const QString &createdBy, const QString &updatedBy)
{
    RefClaimToObject obj;
    obj.claim_to_cd = claimToCd;
    obj.claim_to_name_en = claimToNameEn;
    obj.claim_to_name_zh = claimToNameZh;
    obj.claim_to_desc = claimToDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefClaimTo();
    }
    return RefClaimTo(obj);
}

RefClaimTo RefClaimTo::create(const QVariantMap &values)
{
    RefClaimTo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefClaimTo RefClaimTo::get(const QString &claimToCd)
{
    TSqlORMapper<RefClaimToObject> mapper;
    return RefClaimTo(mapper.findByPrimaryKey(claimToCd));
}

int RefClaimTo::count()
{
    TSqlORMapper<RefClaimToObject> mapper;
    return mapper.findCount();
}

QList<RefClaimTo> RefClaimTo::getAll()
{
    return tfGetModelListByCriteria<RefClaimTo, RefClaimToObject>();
}

TModelObject *RefClaimTo::modelData()
{
    return d.data();
}

const TModelObject *RefClaimTo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefClaimTo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefClaimTo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefClaimTo)
