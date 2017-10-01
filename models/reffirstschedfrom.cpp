#include <TreeFrogModel>
#include "reffirstschedfrom.h"
#include "reffirstschedfromobject.h"

RefFirstSchedFrom::RefFirstSchedFrom()
    : TAbstractModel(), d(new RefFirstSchedFromObject())
{ }

RefFirstSchedFrom::RefFirstSchedFrom(const RefFirstSchedFrom &other)
    : TAbstractModel(), d(new RefFirstSchedFromObject(*other.d))
{ }

RefFirstSchedFrom::RefFirstSchedFrom(const RefFirstSchedFromObject &object)
    : TAbstractModel(), d(new RefFirstSchedFromObject(object))
{ }

RefFirstSchedFrom::~RefFirstSchedFrom()
{
    // If the reference count becomes 0,
    // the shared data object 'RefFirstSchedFromObject' is deleted.
}

QString RefFirstSchedFrom::firstSchedFromCd() const
{
    return d->first_sched_from_cd;
}

void RefFirstSchedFrom::setFirstSchedFromCd(const QString &firstSchedFromCd)
{
    d->first_sched_from_cd = firstSchedFromCd;
}

QString RefFirstSchedFrom::firstSchedFromNameEn() const
{
    return d->first_sched_from_name_en;
}

void RefFirstSchedFrom::setFirstSchedFromNameEn(const QString &firstSchedFromNameEn)
{
    d->first_sched_from_name_en = firstSchedFromNameEn;
}

QString RefFirstSchedFrom::firstSchedFromNameZh() const
{
    return d->first_sched_from_name_zh;
}

void RefFirstSchedFrom::setFirstSchedFromNameZh(const QString &firstSchedFromNameZh)
{
    d->first_sched_from_name_zh = firstSchedFromNameZh;
}

QString RefFirstSchedFrom::firstSchedFromDesc() const
{
    return d->first_sched_from_desc;
}

void RefFirstSchedFrom::setFirstSchedFromDesc(const QString &firstSchedFromDesc)
{
    d->first_sched_from_desc = firstSchedFromDesc;
}

QDateTime RefFirstSchedFrom::createdAt() const
{
    return d->created_at;
}

QString RefFirstSchedFrom::createdBy() const
{
    return d->created_by;
}

void RefFirstSchedFrom::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefFirstSchedFrom::updatedAt() const
{
    return d->updated_at;
}

QString RefFirstSchedFrom::updatedBy() const
{
    return d->updated_by;
}

void RefFirstSchedFrom::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFirstSchedFrom &RefFirstSchedFrom::operator=(const RefFirstSchedFrom &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefFirstSchedFrom RefFirstSchedFrom::create(const QString &firstSchedFromCd, const QString &firstSchedFromNameEn, const QString &firstSchedFromNameZh, const QString &firstSchedFromDesc, const QString &createdBy, const QString &updatedBy)
{
    RefFirstSchedFromObject obj;
    obj.first_sched_from_cd = firstSchedFromCd;
    obj.first_sched_from_name_en = firstSchedFromNameEn;
    obj.first_sched_from_name_zh = firstSchedFromNameZh;
    obj.first_sched_from_desc = firstSchedFromDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefFirstSchedFrom();
    }
    return RefFirstSchedFrom(obj);
}

RefFirstSchedFrom RefFirstSchedFrom::create(const QVariantMap &values)
{
    RefFirstSchedFrom model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefFirstSchedFrom RefFirstSchedFrom::get(const QString &firstSchedFromCd)
{
    TSqlORMapper<RefFirstSchedFromObject> mapper;
    return RefFirstSchedFrom(mapper.findByPrimaryKey(firstSchedFromCd));
}

int RefFirstSchedFrom::count()
{
    TSqlORMapper<RefFirstSchedFromObject> mapper;
    return mapper.findCount();
}

QList<RefFirstSchedFrom> RefFirstSchedFrom::getAll()
{
    return tfGetModelListByCriteria<RefFirstSchedFrom, RefFirstSchedFromObject>();
}

TModelObject *RefFirstSchedFrom::modelData()
{
    return d.data();
}

const TModelObject *RefFirstSchedFrom::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefFirstSchedFrom &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefFirstSchedFrom &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefFirstSchedFrom)
