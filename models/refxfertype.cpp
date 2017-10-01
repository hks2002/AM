#include <TreeFrogModel>
#include "refxfertype.h"
#include "refxfertypeobject.h"

RefXferType::RefXferType()
    : TAbstractModel(), d(new RefXferTypeObject())
{ }

RefXferType::RefXferType(const RefXferType &other)
    : TAbstractModel(), d(new RefXferTypeObject(*other.d))
{ }

RefXferType::RefXferType(const RefXferTypeObject &object)
    : TAbstractModel(), d(new RefXferTypeObject(object))
{ }

RefXferType::~RefXferType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefXferTypeObject' is deleted.
}

QString RefXferType::xferTypeCd() const
{
    return d->xfer_type_cd;
}

void RefXferType::setXferTypeCd(const QString &xferTypeCd)
{
    d->xfer_type_cd = xferTypeCd;
}

QString RefXferType::xferTypeNameEn() const
{
    return d->xfer_type_name_en;
}

void RefXferType::setXferTypeNameEn(const QString &xferTypeNameEn)
{
    d->xfer_type_name_en = xferTypeNameEn;
}

QString RefXferType::xferTypeNameZh() const
{
    return d->xfer_type_name_zh;
}

void RefXferType::setXferTypeNameZh(const QString &xferTypeNameZh)
{
    d->xfer_type_name_zh = xferTypeNameZh;
}

QString RefXferType::xferTypeDesc() const
{
    return d->xfer_type_desc;
}

void RefXferType::setXferTypeDesc(const QString &xferTypeDesc)
{
    d->xfer_type_desc = xferTypeDesc;
}

QDateTime RefXferType::createdAt() const
{
    return d->created_at;
}

QString RefXferType::createdBy() const
{
    return d->created_by;
}

void RefXferType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefXferType::updatedAt() const
{
    return d->updated_at;
}

QString RefXferType::updatedBy() const
{
    return d->updated_by;
}

void RefXferType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefXferType &RefXferType::operator=(const RefXferType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefXferType RefXferType::create(const QString &xferTypeCd, const QString &xferTypeNameEn, const QString &xferTypeNameZh, const QString &xferTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefXferTypeObject obj;
    obj.xfer_type_cd = xferTypeCd;
    obj.xfer_type_name_en = xferTypeNameEn;
    obj.xfer_type_name_zh = xferTypeNameZh;
    obj.xfer_type_desc = xferTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefXferType();
    }
    return RefXferType(obj);
}

RefXferType RefXferType::create(const QVariantMap &values)
{
    RefXferType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefXferType RefXferType::get(const QString &xferTypeCd)
{
    TSqlORMapper<RefXferTypeObject> mapper;
    return RefXferType(mapper.findByPrimaryKey(xferTypeCd));
}

int RefXferType::count()
{
    TSqlORMapper<RefXferTypeObject> mapper;
    return mapper.findCount();
}

QList<RefXferType> RefXferType::getAll()
{
    return tfGetModelListByCriteria<RefXferType, RefXferTypeObject>();
}

TModelObject *RefXferType::modelData()
{
    return d.data();
}

const TModelObject *RefXferType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefXferType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefXferType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefXferType)
