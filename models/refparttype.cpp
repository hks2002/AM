#include <TreeFrogModel>
#include "refparttype.h"
#include "refparttypeobject.h"

RefPartType::RefPartType()
    : TAbstractModel(), d(new RefPartTypeObject())
{ }

RefPartType::RefPartType(const RefPartType &other)
    : TAbstractModel(), d(new RefPartTypeObject(*other.d))
{ }

RefPartType::RefPartType(const RefPartTypeObject &object)
    : TAbstractModel(), d(new RefPartTypeObject(object))
{ }

RefPartType::~RefPartType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPartTypeObject' is deleted.
}

QString RefPartType::partTypeCd() const
{
    return d->part_type_cd;
}

void RefPartType::setPartTypeCd(const QString &partTypeCd)
{
    d->part_type_cd = partTypeCd;
}

QString RefPartType::partTypeNameEn() const
{
    return d->part_type_name_en;
}

void RefPartType::setPartTypeNameEn(const QString &partTypeNameEn)
{
    d->part_type_name_en = partTypeNameEn;
}

QString RefPartType::partTypeNameZh() const
{
    return d->part_type_name_zh;
}

void RefPartType::setPartTypeNameZh(const QString &partTypeNameZh)
{
    d->part_type_name_zh = partTypeNameZh;
}

QString RefPartType::partTypeDesc() const
{
    return d->part_type_desc;
}

void RefPartType::setPartTypeDesc(const QString &partTypeDesc)
{
    d->part_type_desc = partTypeDesc;
}

QDateTime RefPartType::createdAt() const
{
    return d->created_at;
}

QString RefPartType::createdBy() const
{
    return d->created_by;
}

void RefPartType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPartType::updatedAt() const
{
    return d->updated_at;
}

QString RefPartType::updatedBy() const
{
    return d->updated_by;
}

void RefPartType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPartType &RefPartType::operator=(const RefPartType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPartType RefPartType::create(const QString &partTypeCd, const QString &partTypeNameEn, const QString &partTypeNameZh, const QString &partTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefPartTypeObject obj;
    obj.part_type_cd = partTypeCd;
    obj.part_type_name_en = partTypeNameEn;
    obj.part_type_name_zh = partTypeNameZh;
    obj.part_type_desc = partTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPartType();
    }
    return RefPartType(obj);
}

RefPartType RefPartType::create(const QVariantMap &values)
{
    RefPartType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPartType RefPartType::get(const QString &partTypeCd)
{
    TSqlORMapper<RefPartTypeObject> mapper;
    return RefPartType(mapper.findByPrimaryKey(partTypeCd));
}

int RefPartType::count()
{
    TSqlORMapper<RefPartTypeObject> mapper;
    return mapper.findCount();
}

QList<RefPartType> RefPartType::getAll()
{
    return tfGetModelListByCriteria<RefPartType, RefPartTypeObject>();
}

TModelObject *RefPartType::modelData()
{
    return d.data();
}

const TModelObject *RefPartType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPartType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPartType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPartType)
