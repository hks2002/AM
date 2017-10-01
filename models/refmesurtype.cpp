#include <TreeFrogModel>
#include "refmesurtype.h"
#include "refmesurtypeobject.h"

RefMesurType::RefMesurType()
    : TAbstractModel(), d(new RefMesurTypeObject())
{ }

RefMesurType::RefMesurType(const RefMesurType &other)
    : TAbstractModel(), d(new RefMesurTypeObject(*other.d))
{ }

RefMesurType::RefMesurType(const RefMesurTypeObject &object)
    : TAbstractModel(), d(new RefMesurTypeObject(object))
{ }

RefMesurType::~RefMesurType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefMesurTypeObject' is deleted.
}

QString RefMesurType::mesurTypeCd() const
{
    return d->mesur_type_cd;
}

void RefMesurType::setMesurTypeCd(const QString &mesurTypeCd)
{
    d->mesur_type_cd = mesurTypeCd;
}

QString RefMesurType::mesurTypeNameEn() const
{
    return d->mesur_type_name_en;
}

void RefMesurType::setMesurTypeNameEn(const QString &mesurTypeNameEn)
{
    d->mesur_type_name_en = mesurTypeNameEn;
}

QString RefMesurType::mesurTypeNameZh() const
{
    return d->mesur_type_name_zh;
}

void RefMesurType::setMesurTypeNameZh(const QString &mesurTypeNameZh)
{
    d->mesur_type_name_zh = mesurTypeNameZh;
}

QString RefMesurType::mesurTypeDesc() const
{
    return d->mesur_type_desc;
}

void RefMesurType::setMesurTypeDesc(const QString &mesurTypeDesc)
{
    d->mesur_type_desc = mesurTypeDesc;
}

QDateTime RefMesurType::createdAt() const
{
    return d->created_at;
}

QString RefMesurType::createdBy() const
{
    return d->created_by;
}

void RefMesurType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefMesurType::updatedAt() const
{
    return d->updated_at;
}

QString RefMesurType::updatedBy() const
{
    return d->updated_by;
}

void RefMesurType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefMesurType &RefMesurType::operator=(const RefMesurType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefMesurType RefMesurType::create(const QString &mesurTypeCd, const QString &mesurTypeNameEn, const QString &mesurTypeNameZh, const QString &mesurTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefMesurTypeObject obj;
    obj.mesur_type_cd = mesurTypeCd;
    obj.mesur_type_name_en = mesurTypeNameEn;
    obj.mesur_type_name_zh = mesurTypeNameZh;
    obj.mesur_type_desc = mesurTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefMesurType();
    }
    return RefMesurType(obj);
}

RefMesurType RefMesurType::create(const QVariantMap &values)
{
    RefMesurType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefMesurType RefMesurType::get(const QString &mesurTypeCd)
{
    TSqlORMapper<RefMesurTypeObject> mapper;
    return RefMesurType(mapper.findByPrimaryKey(mesurTypeCd));
}

int RefMesurType::count()
{
    TSqlORMapper<RefMesurTypeObject> mapper;
    return mapper.findCount();
}

QList<RefMesurType> RefMesurType::getAll()
{
    return tfGetModelListByCriteria<RefMesurType, RefMesurTypeObject>();
}

TModelObject *RefMesurType::modelData()
{
    return d.data();
}

const TModelObject *RefMesurType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefMesurType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefMesurType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefMesurType)
