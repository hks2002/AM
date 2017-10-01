#include <TreeFrogModel>
#include "refcancelwhen.h"
#include "refcancelwhenobject.h"

RefCancelWhen::RefCancelWhen()
    : TAbstractModel(), d(new RefCancelWhenObject())
{ }

RefCancelWhen::RefCancelWhen(const RefCancelWhen &other)
    : TAbstractModel(), d(new RefCancelWhenObject(*other.d))
{ }

RefCancelWhen::RefCancelWhen(const RefCancelWhenObject &object)
    : TAbstractModel(), d(new RefCancelWhenObject(object))
{ }

RefCancelWhen::~RefCancelWhen()
{
    // If the reference count becomes 0,
    // the shared data object 'RefCancelWhenObject' is deleted.
}

QString RefCancelWhen::cancelWhenCd() const
{
    return d->cancel_when_cd;
}

void RefCancelWhen::setCancelWhenCd(const QString &cancelWhenCd)
{
    d->cancel_when_cd = cancelWhenCd;
}

QString RefCancelWhen::cancelWhenNameEn() const
{
    return d->cancel_when_name_en;
}

void RefCancelWhen::setCancelWhenNameEn(const QString &cancelWhenNameEn)
{
    d->cancel_when_name_en = cancelWhenNameEn;
}

QString RefCancelWhen::cancelWhenNameZh() const
{
    return d->cancel_when_name_zh;
}

void RefCancelWhen::setCancelWhenNameZh(const QString &cancelWhenNameZh)
{
    d->cancel_when_name_zh = cancelWhenNameZh;
}

QString RefCancelWhen::cancelWhenDesc() const
{
    return d->cancel_when_desc;
}

void RefCancelWhen::setCancelWhenDesc(const QString &cancelWhenDesc)
{
    d->cancel_when_desc = cancelWhenDesc;
}

QDateTime RefCancelWhen::createdAt() const
{
    return d->created_at;
}

QString RefCancelWhen::createdBy() const
{
    return d->created_by;
}

void RefCancelWhen::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefCancelWhen::updatedAt() const
{
    return d->updated_at;
}

QString RefCancelWhen::updatedBy() const
{
    return d->updated_by;
}

void RefCancelWhen::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefCancelWhen &RefCancelWhen::operator=(const RefCancelWhen &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefCancelWhen RefCancelWhen::create(const QString &cancelWhenCd, const QString &cancelWhenNameEn, const QString &cancelWhenNameZh, const QString &cancelWhenDesc, const QString &createdBy, const QString &updatedBy)
{
    RefCancelWhenObject obj;
    obj.cancel_when_cd = cancelWhenCd;
    obj.cancel_when_name_en = cancelWhenNameEn;
    obj.cancel_when_name_zh = cancelWhenNameZh;
    obj.cancel_when_desc = cancelWhenDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefCancelWhen();
    }
    return RefCancelWhen(obj);
}

RefCancelWhen RefCancelWhen::create(const QVariantMap &values)
{
    RefCancelWhen model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefCancelWhen RefCancelWhen::get(const QString &cancelWhenCd)
{
    TSqlORMapper<RefCancelWhenObject> mapper;
    return RefCancelWhen(mapper.findByPrimaryKey(cancelWhenCd));
}

int RefCancelWhen::count()
{
    TSqlORMapper<RefCancelWhenObject> mapper;
    return mapper.findCount();
}

QList<RefCancelWhen> RefCancelWhen::getAll()
{
    return tfGetModelListByCriteria<RefCancelWhen, RefCancelWhenObject>();
}

TModelObject *RefCancelWhen::modelData()
{
    return d.data();
}

const TModelObject *RefCancelWhen::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefCancelWhen &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefCancelWhen &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefCancelWhen)
