#include <TreeFrogModel>
#include "refworkpackagetype.h"
#include "refworkpackagetypeobject.h"

RefWorkpackageType::RefWorkpackageType()
    : TAbstractModel(), d(new RefWorkpackageTypeObject())
{ }

RefWorkpackageType::RefWorkpackageType(const RefWorkpackageType &other)
    : TAbstractModel(), d(new RefWorkpackageTypeObject(*other.d))
{ }

RefWorkpackageType::RefWorkpackageType(const RefWorkpackageTypeObject &object)
    : TAbstractModel(), d(new RefWorkpackageTypeObject(object))
{ }

RefWorkpackageType::~RefWorkpackageType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefWorkpackageTypeObject' is deleted.
}

QString RefWorkpackageType::workpackageTypeCd() const
{
    return d->workpackage_type_cd;
}

void RefWorkpackageType::setWorkpackageTypeCd(const QString &workpackageTypeCd)
{
    d->workpackage_type_cd = workpackageTypeCd;
}

QString RefWorkpackageType::workpackageTypeNameEn() const
{
    return d->workpackage_type_name_en;
}

void RefWorkpackageType::setWorkpackageTypeNameEn(const QString &workpackageTypeNameEn)
{
    d->workpackage_type_name_en = workpackageTypeNameEn;
}

QString RefWorkpackageType::workpackageTypeNameZh() const
{
    return d->workpackage_type_name_zh;
}

void RefWorkpackageType::setWorkpackageTypeNameZh(const QString &workpackageTypeNameZh)
{
    d->workpackage_type_name_zh = workpackageTypeNameZh;
}

QString RefWorkpackageType::workpackageTypeDesc() const
{
    return d->workpackage_type_desc;
}

void RefWorkpackageType::setWorkpackageTypeDesc(const QString &workpackageTypeDesc)
{
    d->workpackage_type_desc = workpackageTypeDesc;
}

QDateTime RefWorkpackageType::createdAt() const
{
    return d->created_at;
}

QString RefWorkpackageType::createdBy() const
{
    return d->created_by;
}

void RefWorkpackageType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefWorkpackageType::updatedAt() const
{
    return d->updated_at;
}

QString RefWorkpackageType::updatedBy() const
{
    return d->updated_by;
}

void RefWorkpackageType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWorkpackageType &RefWorkpackageType::operator=(const RefWorkpackageType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefWorkpackageType RefWorkpackageType::create(const QString &workpackageTypeCd, const QString &workpackageTypeNameEn, const QString &workpackageTypeNameZh, const QString &workpackageTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefWorkpackageTypeObject obj;
    obj.workpackage_type_cd = workpackageTypeCd;
    obj.workpackage_type_name_en = workpackageTypeNameEn;
    obj.workpackage_type_name_zh = workpackageTypeNameZh;
    obj.workpackage_type_desc = workpackageTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefWorkpackageType();
    }
    return RefWorkpackageType(obj);
}

RefWorkpackageType RefWorkpackageType::create(const QVariantMap &values)
{
    RefWorkpackageType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefWorkpackageType RefWorkpackageType::get(const QString &workpackageTypeCd)
{
    TSqlORMapper<RefWorkpackageTypeObject> mapper;
    return RefWorkpackageType(mapper.findByPrimaryKey(workpackageTypeCd));
}

int RefWorkpackageType::count()
{
    TSqlORMapper<RefWorkpackageTypeObject> mapper;
    return mapper.findCount();
}

QList<RefWorkpackageType> RefWorkpackageType::getAll()
{
    return tfGetModelListByCriteria<RefWorkpackageType, RefWorkpackageTypeObject>();
}

TModelObject *RefWorkpackageType::modelData()
{
    return d.data();
}

const TModelObject *RefWorkpackageType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefWorkpackageType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefWorkpackageType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefWorkpackageType)
