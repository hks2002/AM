#include <TreeFrogModel>
#include "refremovereason.h"
#include "refremovereasonobject.h"

RefRemoveReason::RefRemoveReason()
    : TAbstractModel(), d(new RefRemoveReasonObject())
{ }

RefRemoveReason::RefRemoveReason(const RefRemoveReason &other)
    : TAbstractModel(), d(new RefRemoveReasonObject(*other.d))
{ }

RefRemoveReason::RefRemoveReason(const RefRemoveReasonObject &object)
    : TAbstractModel(), d(new RefRemoveReasonObject(object))
{ }

RefRemoveReason::~RefRemoveReason()
{
    // If the reference count becomes 0,
    // the shared data object 'RefRemoveReasonObject' is deleted.
}

QString RefRemoveReason::removeReasonCd() const
{
    return d->remove_reason_cd;
}

void RefRemoveReason::setRemoveReasonCd(const QString &removeReasonCd)
{
    d->remove_reason_cd = removeReasonCd;
}

QString RefRemoveReason::removeReasonNameEn() const
{
    return d->remove_reason_name_en;
}

void RefRemoveReason::setRemoveReasonNameEn(const QString &removeReasonNameEn)
{
    d->remove_reason_name_en = removeReasonNameEn;
}

QString RefRemoveReason::removeReasonNameZh() const
{
    return d->remove_reason_name_zh;
}

void RefRemoveReason::setRemoveReasonNameZh(const QString &removeReasonNameZh)
{
    d->remove_reason_name_zh = removeReasonNameZh;
}

QString RefRemoveReason::removeReasonDesc() const
{
    return d->remove_reason_desc;
}

void RefRemoveReason::setRemoveReasonDesc(const QString &removeReasonDesc)
{
    d->remove_reason_desc = removeReasonDesc;
}

QDateTime RefRemoveReason::createdAt() const
{
    return d->created_at;
}

QString RefRemoveReason::createdBy() const
{
    return d->created_by;
}

void RefRemoveReason::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefRemoveReason::updatedAt() const
{
    return d->updated_at;
}

QString RefRemoveReason::updatedBy() const
{
    return d->updated_by;
}

void RefRemoveReason::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefRemoveReason &RefRemoveReason::operator=(const RefRemoveReason &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefRemoveReason RefRemoveReason::create(const QString &removeReasonCd, const QString &removeReasonNameEn, const QString &removeReasonNameZh, const QString &removeReasonDesc, const QString &createdBy, const QString &updatedBy)
{
    RefRemoveReasonObject obj;
    obj.remove_reason_cd = removeReasonCd;
    obj.remove_reason_name_en = removeReasonNameEn;
    obj.remove_reason_name_zh = removeReasonNameZh;
    obj.remove_reason_desc = removeReasonDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefRemoveReason();
    }
    return RefRemoveReason(obj);
}

RefRemoveReason RefRemoveReason::create(const QVariantMap &values)
{
    RefRemoveReason model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefRemoveReason RefRemoveReason::get(const QString &removeReasonCd)
{
    TSqlORMapper<RefRemoveReasonObject> mapper;
    return RefRemoveReason(mapper.findByPrimaryKey(removeReasonCd));
}

int RefRemoveReason::count()
{
    TSqlORMapper<RefRemoveReasonObject> mapper;
    return mapper.findCount();
}

QList<RefRemoveReason> RefRemoveReason::getAll()
{
    return tfGetModelListByCriteria<RefRemoveReason, RefRemoveReasonObject>();
}

TModelObject *RefRemoveReason::modelData()
{
    return d.data();
}

const TModelObject *RefRemoveReason::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefRemoveReason &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefRemoveReason &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefRemoveReason)
