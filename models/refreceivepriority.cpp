#include <TreeFrogModel>
#include "refreceivepriority.h"
#include "refreceivepriorityobject.h"

RefReceivePriority::RefReceivePriority()
    : TAbstractModel(), d(new RefReceivePriorityObject())
{ }

RefReceivePriority::RefReceivePriority(const RefReceivePriority &other)
    : TAbstractModel(), d(new RefReceivePriorityObject(*other.d))
{ }

RefReceivePriority::RefReceivePriority(const RefReceivePriorityObject &object)
    : TAbstractModel(), d(new RefReceivePriorityObject(object))
{ }

RefReceivePriority::~RefReceivePriority()
{
    // If the reference count becomes 0,
    // the shared data object 'RefReceivePriorityObject' is deleted.
}

QString RefReceivePriority::rcvPriorityCd() const
{
    return d->rcv_priority_cd;
}

void RefReceivePriority::setRcvPriorityCd(const QString &rcvPriorityCd)
{
    d->rcv_priority_cd = rcvPriorityCd;
}

QString RefReceivePriority::rcvPriorityNameEn() const
{
    return d->rcv_priority_name_en;
}

void RefReceivePriority::setRcvPriorityNameEn(const QString &rcvPriorityNameEn)
{
    d->rcv_priority_name_en = rcvPriorityNameEn;
}

QString RefReceivePriority::rcvPriorityNameZh() const
{
    return d->rcv_priority_name_zh;
}

void RefReceivePriority::setRcvPriorityNameZh(const QString &rcvPriorityNameZh)
{
    d->rcv_priority_name_zh = rcvPriorityNameZh;
}

QString RefReceivePriority::rcvPriorityDesc() const
{
    return d->rcv_priority_desc;
}

void RefReceivePriority::setRcvPriorityDesc(const QString &rcvPriorityDesc)
{
    d->rcv_priority_desc = rcvPriorityDesc;
}

QDateTime RefReceivePriority::createdAt() const
{
    return d->created_at;
}

QString RefReceivePriority::createdBy() const
{
    return d->created_by;
}

void RefReceivePriority::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefReceivePriority::updatedAt() const
{
    return d->updated_at;
}

QString RefReceivePriority::updatedBy() const
{
    return d->updated_by;
}

void RefReceivePriority::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReceivePriority &RefReceivePriority::operator=(const RefReceivePriority &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefReceivePriority RefReceivePriority::create(const QString &rcvPriorityCd, const QString &rcvPriorityNameEn, const QString &rcvPriorityNameZh, const QString &rcvPriorityDesc, const QString &createdBy, const QString &updatedBy)
{
    RefReceivePriorityObject obj;
    obj.rcv_priority_cd = rcvPriorityCd;
    obj.rcv_priority_name_en = rcvPriorityNameEn;
    obj.rcv_priority_name_zh = rcvPriorityNameZh;
    obj.rcv_priority_desc = rcvPriorityDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefReceivePriority();
    }
    return RefReceivePriority(obj);
}

RefReceivePriority RefReceivePriority::create(const QVariantMap &values)
{
    RefReceivePriority model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefReceivePriority RefReceivePriority::get(const QString &rcvPriorityCd)
{
    TSqlORMapper<RefReceivePriorityObject> mapper;
    return RefReceivePriority(mapper.findByPrimaryKey(rcvPriorityCd));
}

int RefReceivePriority::count()
{
    TSqlORMapper<RefReceivePriorityObject> mapper;
    return mapper.findCount();
}

QList<RefReceivePriority> RefReceivePriority::getAll()
{
    return tfGetModelListByCriteria<RefReceivePriority, RefReceivePriorityObject>();
}

TModelObject *RefReceivePriority::modelData()
{
    return d.data();
}

const TModelObject *RefReceivePriority::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefReceivePriority &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefReceivePriority &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefReceivePriority)
