#include <TreeFrogModel>
#include "refxactiontype.h"
#include "refxactiontypeobject.h"

RefXactionType::RefXactionType()
    : TAbstractModel(), d(new RefXactionTypeObject())
{ }

RefXactionType::RefXactionType(const RefXactionType &other)
    : TAbstractModel(), d(new RefXactionTypeObject(*other.d))
{ }

RefXactionType::RefXactionType(const RefXactionTypeObject &object)
    : TAbstractModel(), d(new RefXactionTypeObject(object))
{ }

RefXactionType::~RefXactionType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefXactionTypeObject' is deleted.
}

QString RefXactionType::xactionTypeCd() const
{
    return d->xaction_type_cd;
}

void RefXactionType::setXactionTypeCd(const QString &xactionTypeCd)
{
    d->xaction_type_cd = xactionTypeCd;
}

QString RefXactionType::xactionTypeNameEn() const
{
    return d->xaction_type_name_en;
}

void RefXactionType::setXactionTypeNameEn(const QString &xactionTypeNameEn)
{
    d->xaction_type_name_en = xactionTypeNameEn;
}

QString RefXactionType::xactionTypeNameZh() const
{
    return d->xaction_type_name_zh;
}

void RefXactionType::setXactionTypeNameZh(const QString &xactionTypeNameZh)
{
    d->xaction_type_name_zh = xactionTypeNameZh;
}

QString RefXactionType::xactionTypeDesc() const
{
    return d->xaction_type_desc;
}

void RefXactionType::setXactionTypeDesc(const QString &xactionTypeDesc)
{
    d->xaction_type_desc = xactionTypeDesc;
}

QDateTime RefXactionType::createdAt() const
{
    return d->created_at;
}

QString RefXactionType::createdBy() const
{
    return d->created_by;
}

void RefXactionType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefXactionType::updatedAt() const
{
    return d->updated_at;
}

QString RefXactionType::updatedBy() const
{
    return d->updated_by;
}

void RefXactionType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefXactionType &RefXactionType::operator=(const RefXactionType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefXactionType RefXactionType::create(const QString &xactionTypeCd, const QString &xactionTypeNameEn, const QString &xactionTypeNameZh, const QString &xactionTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefXactionTypeObject obj;
    obj.xaction_type_cd = xactionTypeCd;
    obj.xaction_type_name_en = xactionTypeNameEn;
    obj.xaction_type_name_zh = xactionTypeNameZh;
    obj.xaction_type_desc = xactionTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefXactionType();
    }
    return RefXactionType(obj);
}

RefXactionType RefXactionType::create(const QVariantMap &values)
{
    RefXactionType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefXactionType RefXactionType::get(const QString &xactionTypeCd)
{
    TSqlORMapper<RefXactionTypeObject> mapper;
    return RefXactionType(mapper.findByPrimaryKey(xactionTypeCd));
}

int RefXactionType::count()
{
    TSqlORMapper<RefXactionTypeObject> mapper;
    return mapper.findCount();
}

QList<RefXactionType> RefXactionType::getAll()
{
    return tfGetModelListByCriteria<RefXactionType, RefXactionTypeObject>();
}

TModelObject *RefXactionType::modelData()
{
    return d.data();
}

const TModelObject *RefXactionType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefXactionType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefXactionType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefXactionType)
