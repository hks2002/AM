#include <TreeFrogModel>
#include "refpotype.h"
#include "refpotypeobject.h"

RefPoType::RefPoType()
    : TAbstractModel(), d(new RefPoTypeObject())
{ }

RefPoType::RefPoType(const RefPoType &other)
    : TAbstractModel(), d(new RefPoTypeObject(*other.d))
{ }

RefPoType::RefPoType(const RefPoTypeObject &object)
    : TAbstractModel(), d(new RefPoTypeObject(object))
{ }

RefPoType::~RefPoType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPoTypeObject' is deleted.
}

QString RefPoType::poTypeCd() const
{
    return d->po_type_cd;
}

void RefPoType::setPoTypeCd(const QString &poTypeCd)
{
    d->po_type_cd = poTypeCd;
}

QString RefPoType::poTypeNameEn() const
{
    return d->po_type_name_en;
}

void RefPoType::setPoTypeNameEn(const QString &poTypeNameEn)
{
    d->po_type_name_en = poTypeNameEn;
}

QString RefPoType::poTypeNameZh() const
{
    return d->po_type_name_zh;
}

void RefPoType::setPoTypeNameZh(const QString &poTypeNameZh)
{
    d->po_type_name_zh = poTypeNameZh;
}

QString RefPoType::poTypeDesc() const
{
    return d->po_type_desc;
}

void RefPoType::setPoTypeDesc(const QString &poTypeDesc)
{
    d->po_type_desc = poTypeDesc;
}

QDateTime RefPoType::createdAt() const
{
    return d->created_at;
}

QString RefPoType::createdBy() const
{
    return d->created_by;
}

void RefPoType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPoType::updatedAt() const
{
    return d->updated_at;
}

QString RefPoType::updatedBy() const
{
    return d->updated_by;
}

void RefPoType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPoType &RefPoType::operator=(const RefPoType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPoType RefPoType::create(const QString &poTypeCd, const QString &poTypeNameEn, const QString &poTypeNameZh, const QString &poTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPoTypeObject obj;
    obj.po_type_cd = poTypeCd;
    obj.po_type_name_en = poTypeNameEn;
    obj.po_type_name_zh = poTypeNameZh;
    obj.po_type_desc = poTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPoType();
    }
    return RefPoType(obj);
}

RefPoType RefPoType::create(const QVariantMap &values)
{
    RefPoType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPoType RefPoType::get(const QString &poTypeCd)
{
    TSqlORMapper<RefPoTypeObject> mapper;
    return RefPoType(mapper.findByPrimaryKey(poTypeCd));
}

int RefPoType::count()
{
    TSqlORMapper<RefPoTypeObject> mapper;
    return mapper.findCount();
}

QList<RefPoType> RefPoType::getAll()
{
    return tfGetModelListByCriteria<RefPoType, RefPoTypeObject>();
}

TModelObject *RefPoType::modelData()
{
    return d.data();
}

const TModelObject *RefPoType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPoType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPoType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPoType)
