#include <TreeFrogModel>
#include "refpartprovidertype.h"
#include "refpartprovidertypeobject.h"

RefPartProviderType::RefPartProviderType()
    : TAbstractModel(), d(new RefPartProviderTypeObject())
{ }

RefPartProviderType::RefPartProviderType(const RefPartProviderType &other)
    : TAbstractModel(), d(new RefPartProviderTypeObject(*other.d))
{ }

RefPartProviderType::RefPartProviderType(const RefPartProviderTypeObject &object)
    : TAbstractModel(), d(new RefPartProviderTypeObject(object))
{ }

RefPartProviderType::~RefPartProviderType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPartProviderTypeObject' is deleted.
}

QString RefPartProviderType::partProviderTypeCd() const
{
    return d->part_provider_type_cd;
}

void RefPartProviderType::setPartProviderTypeCd(const QString &partProviderTypeCd)
{
    d->part_provider_type_cd = partProviderTypeCd;
}

QString RefPartProviderType::partProviderTypeNameEn() const
{
    return d->part_provider_type_name_en;
}

void RefPartProviderType::setPartProviderTypeNameEn(const QString &partProviderTypeNameEn)
{
    d->part_provider_type_name_en = partProviderTypeNameEn;
}

QString RefPartProviderType::partProviderTypeNameZh() const
{
    return d->part_provider_type_name_zh;
}

void RefPartProviderType::setPartProviderTypeNameZh(const QString &partProviderTypeNameZh)
{
    d->part_provider_type_name_zh = partProviderTypeNameZh;
}

QString RefPartProviderType::partProviderTypeDesc() const
{
    return d->part_provider_type_desc;
}

void RefPartProviderType::setPartProviderTypeDesc(const QString &partProviderTypeDesc)
{
    d->part_provider_type_desc = partProviderTypeDesc;
}

QDateTime RefPartProviderType::createdAt() const
{
    return d->created_at;
}

QString RefPartProviderType::createdBy() const
{
    return d->created_by;
}

void RefPartProviderType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPartProviderType::updatedAt() const
{
    return d->updated_at;
}

QString RefPartProviderType::updatedBy() const
{
    return d->updated_by;
}

void RefPartProviderType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPartProviderType &RefPartProviderType::operator=(const RefPartProviderType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPartProviderType RefPartProviderType::create(const QString &partProviderTypeCd, const QString &partProviderTypeNameEn, const QString &partProviderTypeNameZh, const QString &partProviderTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPartProviderTypeObject obj;
    obj.part_provider_type_cd = partProviderTypeCd;
    obj.part_provider_type_name_en = partProviderTypeNameEn;
    obj.part_provider_type_name_zh = partProviderTypeNameZh;
    obj.part_provider_type_desc = partProviderTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPartProviderType();
    }
    return RefPartProviderType(obj);
}

RefPartProviderType RefPartProviderType::create(const QVariantMap &values)
{
    RefPartProviderType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPartProviderType RefPartProviderType::get(const QString &partProviderTypeCd)
{
    TSqlORMapper<RefPartProviderTypeObject> mapper;
    return RefPartProviderType(mapper.findByPrimaryKey(partProviderTypeCd));
}

int RefPartProviderType::count()
{
    TSqlORMapper<RefPartProviderTypeObject> mapper;
    return mapper.findCount();
}

QList<RefPartProviderType> RefPartProviderType::getAll()
{
    return tfGetModelListByCriteria<RefPartProviderType, RefPartProviderTypeObject>();
}

TModelObject *RefPartProviderType::modelData()
{
    return d.data();
}

const TModelObject *RefPartProviderType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPartProviderType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPartProviderType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPartProviderType)
