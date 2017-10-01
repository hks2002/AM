#include <TreeFrogModel>
#include "refwarrantypriority.h"
#include "refwarrantypriorityobject.h"

RefWarrantyPriority::RefWarrantyPriority()
    : TAbstractModel(), d(new RefWarrantyPriorityObject())
{ }

RefWarrantyPriority::RefWarrantyPriority(const RefWarrantyPriority &other)
    : TAbstractModel(), d(new RefWarrantyPriorityObject(*other.d))
{ }

RefWarrantyPriority::RefWarrantyPriority(const RefWarrantyPriorityObject &object)
    : TAbstractModel(), d(new RefWarrantyPriorityObject(object))
{ }

RefWarrantyPriority::~RefWarrantyPriority()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWarrantyPriorityObject' is deleted.
}

QString RefWarrantyPriority::warrantyPriorityCd() const
{
    return d->warranty_priority_cd;
}

void RefWarrantyPriority::setWarrantyPriorityCd(const QString &warrantyPriorityCd)
{
    d->warranty_priority_cd = warrantyPriorityCd;
}

QString RefWarrantyPriority::warrantyPriorityNameEn() const
{
    return d->warranty_priority_name_en;
}

void RefWarrantyPriority::setWarrantyPriorityNameEn(const QString &warrantyPriorityNameEn)
{
    d->warranty_priority_name_en = warrantyPriorityNameEn;
}

QString RefWarrantyPriority::warrantyPriorityNameZh() const
{
    return d->warranty_priority_name_zh;
}

void RefWarrantyPriority::setWarrantyPriorityNameZh(const QString &warrantyPriorityNameZh)
{
    d->warranty_priority_name_zh = warrantyPriorityNameZh;
}

QString RefWarrantyPriority::warrantyPriorityDesc() const
{
    return d->warranty_priority_desc;
}

void RefWarrantyPriority::setWarrantyPriorityDesc(const QString &warrantyPriorityDesc)
{
    d->warranty_priority_desc = warrantyPriorityDesc;
}

QDateTime RefWarrantyPriority::createdAt() const
{
    return d->created_at;
}

QString RefWarrantyPriority::createdBy() const
{
    return d->created_by;
}

void RefWarrantyPriority::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWarrantyPriority::updatedAt() const
{
    return d->updated_at;
}

QString RefWarrantyPriority::updatedBy() const
{
    return d->updated_by;
}

void RefWarrantyPriority::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyPriority &RefWarrantyPriority::operator=(const RefWarrantyPriority &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWarrantyPriority RefWarrantyPriority::create(const QString &warrantyPriorityCd, const QString &warrantyPriorityNameEn, const QString &warrantyPriorityNameZh, const QString &warrantyPriorityDesc, const QString &createdBy, const QString &updatedBy)
{
    RefWarrantyPriorityObject obj;
    obj.warranty_priority_cd = warrantyPriorityCd;
    obj.warranty_priority_name_en = warrantyPriorityNameEn;
    obj.warranty_priority_name_zh = warrantyPriorityNameZh;
    obj.warranty_priority_desc = warrantyPriorityDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWarrantyPriority();
    }
    return RefWarrantyPriority(obj);
}

RefWarrantyPriority RefWarrantyPriority::create(const QVariantMap &values)
{
    RefWarrantyPriority model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWarrantyPriority RefWarrantyPriority::get(const QString &warrantyPriorityCd)
{
    TSqlORMapper<RefWarrantyPriorityObject> mapper;
    return RefWarrantyPriority(mapper.findByPrimaryKey(warrantyPriorityCd));
}

int RefWarrantyPriority::count()
{
    TSqlORMapper<RefWarrantyPriorityObject> mapper;
    return mapper.findCount();
}

QList<RefWarrantyPriority> RefWarrantyPriority::getAll()
{
    return tfGetModelListByCriteria<RefWarrantyPriority, RefWarrantyPriorityObject>();
}

TModelObject *RefWarrantyPriority::modelData()
{
    return d.data();
}

const TModelObject *RefWarrantyPriority::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWarrantyPriority &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWarrantyPriority &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWarrantyPriority)
