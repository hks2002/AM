#include <TreeFrogModel>
#include "refreqpriority.h"
#include "refreqpriorityobject.h"

RefReqPriority::RefReqPriority()
    : TAbstractModel(), d(new RefReqPriorityObject())
{ }

RefReqPriority::RefReqPriority(const RefReqPriority &other)
    : TAbstractModel(), d(new RefReqPriorityObject(*other.d))
{ }

RefReqPriority::RefReqPriority(const RefReqPriorityObject &object)
    : TAbstractModel(), d(new RefReqPriorityObject(object))
{ }

RefReqPriority::~RefReqPriority()
{
    // If the reference count becomes 0,
    // the shared data object 'RefReqPriorityObject' is deleted.
}

QString RefReqPriority::reqPriorityCd() const
{
    return d->req_priority_cd;
}

void RefReqPriority::setReqPriorityCd(const QString &reqPriorityCd)
{
    d->req_priority_cd = reqPriorityCd;
}

QString RefReqPriority::reqPriorityNameEn() const
{
    return d->req_priority_name_en;
}

void RefReqPriority::setReqPriorityNameEn(const QString &reqPriorityNameEn)
{
    d->req_priority_name_en = reqPriorityNameEn;
}

QString RefReqPriority::reqPriorityNameZh() const
{
    return d->req_priority_name_zh;
}

void RefReqPriority::setReqPriorityNameZh(const QString &reqPriorityNameZh)
{
    d->req_priority_name_zh = reqPriorityNameZh;
}

QString RefReqPriority::reqPriorityDesc() const
{
    return d->req_priority_desc;
}

void RefReqPriority::setReqPriorityDesc(const QString &reqPriorityDesc)
{
    d->req_priority_desc = reqPriorityDesc;
}

QDateTime RefReqPriority::createdAt() const
{
    return d->created_at;
}

QString RefReqPriority::createdBy() const
{
    return d->created_by;
}

void RefReqPriority::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefReqPriority::updatedAt() const
{
    return d->updated_at;
}

QString RefReqPriority::updatedBy() const
{
    return d->updated_by;
}

void RefReqPriority::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReqPriority &RefReqPriority::operator=(const RefReqPriority &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefReqPriority RefReqPriority::create(const QString &reqPriorityCd, const QString &reqPriorityNameEn, const QString &reqPriorityNameZh, const QString &reqPriorityDesc, const QString &createdBy, const QString &updatedBy)
{
    RefReqPriorityObject obj;
    obj.req_priority_cd = reqPriorityCd;
    obj.req_priority_name_en = reqPriorityNameEn;
    obj.req_priority_name_zh = reqPriorityNameZh;
    obj.req_priority_desc = reqPriorityDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefReqPriority();
    }
    return RefReqPriority(obj);
}

RefReqPriority RefReqPriority::create(const QVariantMap &values)
{
    RefReqPriority model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefReqPriority RefReqPriority::get(const QString &reqPriorityCd)
{
    TSqlORMapper<RefReqPriorityObject> mapper;
    return RefReqPriority(mapper.findByPrimaryKey(reqPriorityCd));
}

int RefReqPriority::count()
{
    TSqlORMapper<RefReqPriorityObject> mapper;
    return mapper.findCount();
}

QList<RefReqPriority> RefReqPriority::getAll()
{
    return tfGetModelListByCriteria<RefReqPriority, RefReqPriorityObject>();
}

TModelObject *RefReqPriority::modelData()
{
    return d.data();
}

const TModelObject *RefReqPriority::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefReqPriority &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefReqPriority &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefReqPriority)
