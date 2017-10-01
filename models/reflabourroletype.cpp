#include <TreeFrogModel>
#include "reflabourroletype.h"
#include "reflabourroletypeobject.h"

RefLabourRoleType::RefLabourRoleType()
    : TAbstractModel(), d(new RefLabourRoleTypeObject())
{ }

RefLabourRoleType::RefLabourRoleType(const RefLabourRoleType &other)
    : TAbstractModel(), d(new RefLabourRoleTypeObject(*other.d))
{ }

RefLabourRoleType::RefLabourRoleType(const RefLabourRoleTypeObject &object)
    : TAbstractModel(), d(new RefLabourRoleTypeObject(object))
{ }

RefLabourRoleType::~RefLabourRoleType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefLabourRoleTypeObject' is deleted.
}

QString RefLabourRoleType::labourRoleTypeCd() const
{
    return d->labour_role_type_cd;
}

void RefLabourRoleType::setLabourRoleTypeCd(const QString &labourRoleTypeCd)
{
    d->labour_role_type_cd = labourRoleTypeCd;
}

QString RefLabourRoleType::labourRoleTypeNameEn() const
{
    return d->labour_role_type_name_en;
}

void RefLabourRoleType::setLabourRoleTypeNameEn(const QString &labourRoleTypeNameEn)
{
    d->labour_role_type_name_en = labourRoleTypeNameEn;
}

QString RefLabourRoleType::labourRoleTypeNameZh() const
{
    return d->labour_role_type_name_zh;
}

void RefLabourRoleType::setLabourRoleTypeNameZh(const QString &labourRoleTypeNameZh)
{
    d->labour_role_type_name_zh = labourRoleTypeNameZh;
}

QString RefLabourRoleType::labourRoleTypeDesc() const
{
    return d->labour_role_type_desc;
}

void RefLabourRoleType::setLabourRoleTypeDesc(const QString &labourRoleTypeDesc)
{
    d->labour_role_type_desc = labourRoleTypeDesc;
}

QDateTime RefLabourRoleType::createdAt() const
{
    return d->created_at;
}

QString RefLabourRoleType::createdBy() const
{
    return d->created_by;
}

void RefLabourRoleType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefLabourRoleType::updatedAt() const
{
    return d->updated_at;
}

QString RefLabourRoleType::updatedBy() const
{
    return d->updated_by;
}

void RefLabourRoleType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLabourRoleType &RefLabourRoleType::operator=(const RefLabourRoleType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefLabourRoleType RefLabourRoleType::create(const QString &labourRoleTypeCd, const QString &labourRoleTypeNameEn, const QString &labourRoleTypeNameZh, const QString &labourRoleTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefLabourRoleTypeObject obj;
    obj.labour_role_type_cd = labourRoleTypeCd;
    obj.labour_role_type_name_en = labourRoleTypeNameEn;
    obj.labour_role_type_name_zh = labourRoleTypeNameZh;
    obj.labour_role_type_desc = labourRoleTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefLabourRoleType();
    }
    return RefLabourRoleType(obj);
}

RefLabourRoleType RefLabourRoleType::create(const QVariantMap &values)
{
    RefLabourRoleType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefLabourRoleType RefLabourRoleType::get(const QString &labourRoleTypeCd)
{
    TSqlORMapper<RefLabourRoleTypeObject> mapper;
    return RefLabourRoleType(mapper.findByPrimaryKey(labourRoleTypeCd));
}

int RefLabourRoleType::count()
{
    TSqlORMapper<RefLabourRoleTypeObject> mapper;
    return mapper.findCount();
}

QList<RefLabourRoleType> RefLabourRoleType::getAll()
{
    return tfGetModelListByCriteria<RefLabourRoleType, RefLabourRoleTypeObject>();
}

TModelObject *RefLabourRoleType::modelData()
{
    return d.data();
}

const TModelObject *RefLabourRoleType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefLabourRoleType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefLabourRoleType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefLabourRoleType)
