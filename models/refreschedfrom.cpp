#include <TreeFrogModel>
#include "refreschedfrom.h"
#include "refreschedfromobject.h"

RefReschedFrom::RefReschedFrom()
    : TAbstractModel(), d(new RefReschedFromObject())
{ }

RefReschedFrom::RefReschedFrom(const RefReschedFrom &other)
    : TAbstractModel(), d(new RefReschedFromObject(*other.d))
{ }

RefReschedFrom::RefReschedFrom(const RefReschedFromObject &object)
    : TAbstractModel(), d(new RefReschedFromObject(object))
{ }

RefReschedFrom::~RefReschedFrom()
{
    // If the reference count becomes 0,
    // the shared data object 'RefReschedFromObject' is deleted.
}

QString RefReschedFrom::reschedFromCd() const
{
    return d->resched_from_cd;
}

void RefReschedFrom::setReschedFromCd(const QString &reschedFromCd)
{
    d->resched_from_cd = reschedFromCd;
}

QString RefReschedFrom::reschedFromNameEn() const
{
    return d->resched_from_name_en;
}

void RefReschedFrom::setReschedFromNameEn(const QString &reschedFromNameEn)
{
    d->resched_from_name_en = reschedFromNameEn;
}

QString RefReschedFrom::reschedFromNameZh() const
{
    return d->resched_from_name_zh;
}

void RefReschedFrom::setReschedFromNameZh(const QString &reschedFromNameZh)
{
    d->resched_from_name_zh = reschedFromNameZh;
}

QString RefReschedFrom::reschedFromDesc() const
{
    return d->resched_from_desc;
}

void RefReschedFrom::setReschedFromDesc(const QString &reschedFromDesc)
{
    d->resched_from_desc = reschedFromDesc;
}

QDateTime RefReschedFrom::createdAt() const
{
    return d->created_at;
}

QString RefReschedFrom::createdBy() const
{
    return d->created_by;
}

void RefReschedFrom::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefReschedFrom::updatedAt() const
{
    return d->updated_at;
}

QString RefReschedFrom::updatedBy() const
{
    return d->updated_by;
}

void RefReschedFrom::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReschedFrom &RefReschedFrom::operator=(const RefReschedFrom &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefReschedFrom RefReschedFrom::create(const QString &reschedFromCd, const QString &reschedFromNameEn, const QString &reschedFromNameZh, const QString &reschedFromDesc, const QString &createdBy, const QString &updatedBy)
{
    RefReschedFromObject obj;
    obj.resched_from_cd = reschedFromCd;
    obj.resched_from_name_en = reschedFromNameEn;
    obj.resched_from_name_zh = reschedFromNameZh;
    obj.resched_from_desc = reschedFromDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefReschedFrom();
    }
    return RefReschedFrom(obj);
}

RefReschedFrom RefReschedFrom::create(const QVariantMap &values)
{
    RefReschedFrom model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefReschedFrom RefReschedFrom::get(const QString &reschedFromCd)
{
    TSqlORMapper<RefReschedFromObject> mapper;
    return RefReschedFrom(mapper.findByPrimaryKey(reschedFromCd));
}

int RefReschedFrom::count()
{
    TSqlORMapper<RefReschedFromObject> mapper;
    return mapper.findCount();
}

QList<RefReschedFrom> RefReschedFrom::getAll()
{
    return tfGetModelListByCriteria<RefReschedFrom, RefReschedFromObject>();
}

TModelObject *RefReschedFrom::modelData()
{
    return d.data();
}

const TModelObject *RefReschedFrom::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefReschedFrom &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefReschedFrom &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefReschedFrom)
