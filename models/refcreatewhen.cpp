#include <TreeFrogModel>
#include "refcreatewhen.h"
#include "refcreatewhenobject.h"

RefCreateWhen::RefCreateWhen()
    : TAbstractModel(), d(new RefCreateWhenObject())
{ }

RefCreateWhen::RefCreateWhen(const RefCreateWhen &other)
    : TAbstractModel(), d(new RefCreateWhenObject(*other.d))
{ }

RefCreateWhen::RefCreateWhen(const RefCreateWhenObject &object)
    : TAbstractModel(), d(new RefCreateWhenObject(object))
{ }

RefCreateWhen::~RefCreateWhen()
{
    // If the reference count becomes 0,
    // the shared data object 'RefCreateWhenObject' is deleted.
}

QString RefCreateWhen::createWhenCd() const
{
    return d->create_when_cd;
}

void RefCreateWhen::setCreateWhenCd(const QString &createWhenCd)
{
    d->create_when_cd = createWhenCd;
}

QString RefCreateWhen::createWhenNameEn() const
{
    return d->create_when_name_en;
}

void RefCreateWhen::setCreateWhenNameEn(const QString &createWhenNameEn)
{
    d->create_when_name_en = createWhenNameEn;
}

QString RefCreateWhen::createWhenNameZh() const
{
    return d->create_when_name_zh;
}

void RefCreateWhen::setCreateWhenNameZh(const QString &createWhenNameZh)
{
    d->create_when_name_zh = createWhenNameZh;
}

QString RefCreateWhen::createWhenDesc() const
{
    return d->create_when_desc;
}

void RefCreateWhen::setCreateWhenDesc(const QString &createWhenDesc)
{
    d->create_when_desc = createWhenDesc;
}

QDateTime RefCreateWhen::createdAt() const
{
    return d->created_at;
}

QString RefCreateWhen::createdBy() const
{
    return d->created_by;
}

void RefCreateWhen::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefCreateWhen::updatedAt() const
{
    return d->updated_at;
}

QString RefCreateWhen::updatedBy() const
{
    return d->updated_by;
}

void RefCreateWhen::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefCreateWhen &RefCreateWhen::operator=(const RefCreateWhen &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefCreateWhen RefCreateWhen::create(const QString &createWhenCd, const QString &createWhenNameEn, const QString &createWhenNameZh, const QString &createWhenDesc, const QString &createdBy, const QString &updatedBy)
{
    RefCreateWhenObject obj;
    obj.create_when_cd = createWhenCd;
    obj.create_when_name_en = createWhenNameEn;
    obj.create_when_name_zh = createWhenNameZh;
    obj.create_when_desc = createWhenDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefCreateWhen();
    }
    return RefCreateWhen(obj);
}

RefCreateWhen RefCreateWhen::create(const QVariantMap &values)
{
    RefCreateWhen model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefCreateWhen RefCreateWhen::get(const QString &createWhenCd)
{
    TSqlORMapper<RefCreateWhenObject> mapper;
    return RefCreateWhen(mapper.findByPrimaryKey(createWhenCd));
}

int RefCreateWhen::count()
{
    TSqlORMapper<RefCreateWhenObject> mapper;
    return mapper.findCount();
}

QList<RefCreateWhen> RefCreateWhen::getAll()
{
    return tfGetModelListByCriteria<RefCreateWhen, RefCreateWhenObject>();
}

TModelObject *RefCreateWhen::modelData()
{
    return d.data();
}

const TModelObject *RefCreateWhen::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefCreateWhen &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefCreateWhen &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefCreateWhen)
