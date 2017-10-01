#include <TreeFrogModel>
#include "refadvsrytype.h"
#include "refadvsrytypeobject.h"

RefAdvsryType::RefAdvsryType()
    : TAbstractModel(), d(new RefAdvsryTypeObject())
{ }

RefAdvsryType::RefAdvsryType(const RefAdvsryType &other)
    : TAbstractModel(), d(new RefAdvsryTypeObject(*other.d))
{ }

RefAdvsryType::RefAdvsryType(const RefAdvsryTypeObject &object)
    : TAbstractModel(), d(new RefAdvsryTypeObject(object))
{ }

RefAdvsryType::~RefAdvsryType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefAdvsryTypeObject' is deleted.
}

QString RefAdvsryType::advsryTypeCd() const
{
    return d->advsry_type_cd;
}

void RefAdvsryType::setAdvsryTypeCd(const QString &advsryTypeCd)
{
    d->advsry_type_cd = advsryTypeCd;
}

QString RefAdvsryType::advsryTypeNameEn() const
{
    return d->advsry_type_name_en;
}

void RefAdvsryType::setAdvsryTypeNameEn(const QString &advsryTypeNameEn)
{
    d->advsry_type_name_en = advsryTypeNameEn;
}

QString RefAdvsryType::advsryTypeNameZh() const
{
    return d->advsry_type_name_zh;
}

void RefAdvsryType::setAdvsryTypeNameZh(const QString &advsryTypeNameZh)
{
    d->advsry_type_name_zh = advsryTypeNameZh;
}

QString RefAdvsryType::advsryTypeDesc() const
{
    return d->advsry_type_desc;
}

void RefAdvsryType::setAdvsryTypeDesc(const QString &advsryTypeDesc)
{
    d->advsry_type_desc = advsryTypeDesc;
}

QDateTime RefAdvsryType::createdAt() const
{
    return d->created_at;
}

QString RefAdvsryType::createdBy() const
{
    return d->created_by;
}

void RefAdvsryType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefAdvsryType::updatedAt() const
{
    return d->updated_at;
}

QString RefAdvsryType::updatedBy() const
{
    return d->updated_by;
}

void RefAdvsryType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAdvsryType &RefAdvsryType::operator=(const RefAdvsryType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefAdvsryType RefAdvsryType::create(const QString &advsryTypeCd, const QString &advsryTypeNameEn, const QString &advsryTypeNameZh, const QString &advsryTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefAdvsryTypeObject obj;
    obj.advsry_type_cd = advsryTypeCd;
    obj.advsry_type_name_en = advsryTypeNameEn;
    obj.advsry_type_name_zh = advsryTypeNameZh;
    obj.advsry_type_desc = advsryTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefAdvsryType();
    }
    return RefAdvsryType(obj);
}

RefAdvsryType RefAdvsryType::create(const QVariantMap &values)
{
    RefAdvsryType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefAdvsryType RefAdvsryType::get(const QString &advsryTypeCd)
{
    TSqlORMapper<RefAdvsryTypeObject> mapper;
    return RefAdvsryType(mapper.findByPrimaryKey(advsryTypeCd));
}

int RefAdvsryType::count()
{
    TSqlORMapper<RefAdvsryTypeObject> mapper;
    return mapper.findCount();
}

QList<RefAdvsryType> RefAdvsryType::getAll()
{
    return tfGetModelListByCriteria<RefAdvsryType, RefAdvsryTypeObject>();
}

TModelObject *RefAdvsryType::modelData()
{
    return d.data();
}

const TModelObject *RefAdvsryType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefAdvsryType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefAdvsryType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefAdvsryType)
