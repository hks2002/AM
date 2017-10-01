#include <TreeFrogModel>
#include "refinvcond.h"
#include "refinvcondobject.h"

RefInvCond::RefInvCond()
    : TAbstractModel(), d(new RefInvCondObject())
{ }

RefInvCond::RefInvCond(const RefInvCond &other)
    : TAbstractModel(), d(new RefInvCondObject(*other.d))
{ }

RefInvCond::RefInvCond(const RefInvCondObject &object)
    : TAbstractModel(), d(new RefInvCondObject(object))
{ }

RefInvCond::~RefInvCond()
{
    // If the reference count becomes 0,
    // the shared data object 'RefInvCondObject' is deleted.
}

QString RefInvCond::invCondCd() const
{
    return d->inv_cond_cd;
}

void RefInvCond::setInvCondCd(const QString &invCondCd)
{
    d->inv_cond_cd = invCondCd;
}

QString RefInvCond::invCondNameEn() const
{
    return d->inv_cond_name_en;
}

void RefInvCond::setInvCondNameEn(const QString &invCondNameEn)
{
    d->inv_cond_name_en = invCondNameEn;
}

QString RefInvCond::invCondNameZh() const
{
    return d->inv_cond_name_zh;
}

void RefInvCond::setInvCondNameZh(const QString &invCondNameZh)
{
    d->inv_cond_name_zh = invCondNameZh;
}

QString RefInvCond::invCondDesc() const
{
    return d->inv_cond_desc;
}

void RefInvCond::setInvCondDesc(const QString &invCondDesc)
{
    d->inv_cond_desc = invCondDesc;
}

QDateTime RefInvCond::createdAt() const
{
    return d->created_at;
}

QString RefInvCond::createdBy() const
{
    return d->created_by;
}

void RefInvCond::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefInvCond::updatedAt() const
{
    return d->updated_at;
}

QString RefInvCond::updatedBy() const
{
    return d->updated_by;
}

void RefInvCond::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefInvCond &RefInvCond::operator=(const RefInvCond &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefInvCond RefInvCond::create(const QString &invCondCd, const QString &invCondNameEn, const QString &invCondNameZh, const QString &invCondDesc, const QString &createdBy, const QString &updatedBy)
{
    RefInvCondObject obj;
    obj.inv_cond_cd = invCondCd;
    obj.inv_cond_name_en = invCondNameEn;
    obj.inv_cond_name_zh = invCondNameZh;
    obj.inv_cond_desc = invCondDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefInvCond();
    }
    return RefInvCond(obj);
}

RefInvCond RefInvCond::create(const QVariantMap &values)
{
    RefInvCond model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefInvCond RefInvCond::get(const QString &invCondCd)
{
    TSqlORMapper<RefInvCondObject> mapper;
    return RefInvCond(mapper.findByPrimaryKey(invCondCd));
}

int RefInvCond::count()
{
    TSqlORMapper<RefInvCondObject> mapper;
    return mapper.findCount();
}

QList<RefInvCond> RefInvCond::getAll()
{
    return tfGetModelListByCriteria<RefInvCond, RefInvCondObject>();
}

TModelObject *RefInvCond::modelData()
{
    return d.data();
}

const TModelObject *RefInvCond::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefInvCond &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefInvCond &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefInvCond)
