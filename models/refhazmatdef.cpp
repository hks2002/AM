#include <TreeFrogModel>
#include "refhazmatdef.h"
#include "refhazmatdefobject.h"

RefHazmatDef::RefHazmatDef()
    : TAbstractModel(), d(new RefHazmatDefObject())
{ }

RefHazmatDef::RefHazmatDef(const RefHazmatDef &other)
    : TAbstractModel(), d(new RefHazmatDefObject(*other.d))
{ }

RefHazmatDef::RefHazmatDef(const RefHazmatDefObject &object)
    : TAbstractModel(), d(new RefHazmatDefObject(object))
{ }

RefHazmatDef::~RefHazmatDef()
{
    // If the reference count becomes 0,
    // the shared data object 'RefHazmatDefObject' is deleted.
}

QString RefHazmatDef::hazmatDefCd() const
{
    return d->hazmat_def_cd;
}

void RefHazmatDef::setHazmatDefCd(const QString &hazmatDefCd)
{
    d->hazmat_def_cd = hazmatDefCd;
}

QString RefHazmatDef::hazmatDefNameEn() const
{
    return d->hazmat_def_name_en;
}

void RefHazmatDef::setHazmatDefNameEn(const QString &hazmatDefNameEn)
{
    d->hazmat_def_name_en = hazmatDefNameEn;
}

QString RefHazmatDef::hazmatDefNameZh() const
{
    return d->hazmat_def_name_zh;
}

void RefHazmatDef::setHazmatDefNameZh(const QString &hazmatDefNameZh)
{
    d->hazmat_def_name_zh = hazmatDefNameZh;
}

QString RefHazmatDef::hazmatDefDesc() const
{
    return d->hazmat_def_desc;
}

void RefHazmatDef::setHazmatDefDesc(const QString &hazmatDefDesc)
{
    d->hazmat_def_desc = hazmatDefDesc;
}

QDateTime RefHazmatDef::createdAt() const
{
    return d->created_at;
}

QString RefHazmatDef::createdBy() const
{
    return d->created_by;
}

void RefHazmatDef::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefHazmatDef::updatedAt() const
{
    return d->updated_at;
}

QString RefHazmatDef::updatedBy() const
{
    return d->updated_by;
}

void RefHazmatDef::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefHazmatDef &RefHazmatDef::operator=(const RefHazmatDef &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefHazmatDef RefHazmatDef::create(const QString &hazmatDefCd, const QString &hazmatDefNameEn, const QString &hazmatDefNameZh, const QString &hazmatDefDesc, const QString &createdBy, const QString &updatedBy)
{
    RefHazmatDefObject obj;
    obj.hazmat_def_cd = hazmatDefCd;
    obj.hazmat_def_name_en = hazmatDefNameEn;
    obj.hazmat_def_name_zh = hazmatDefNameZh;
    obj.hazmat_def_desc = hazmatDefDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefHazmatDef();
    }
    return RefHazmatDef(obj);
}

RefHazmatDef RefHazmatDef::create(const QVariantMap &values)
{
    RefHazmatDef model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefHazmatDef RefHazmatDef::get(const QString &hazmatDefCd)
{
    TSqlORMapper<RefHazmatDefObject> mapper;
    return RefHazmatDef(mapper.findByPrimaryKey(hazmatDefCd));
}

int RefHazmatDef::count()
{
    TSqlORMapper<RefHazmatDefObject> mapper;
    return mapper.findCount();
}

QList<RefHazmatDef> RefHazmatDef::getAll()
{
    return tfGetModelListByCriteria<RefHazmatDef, RefHazmatDefObject>();
}

TModelObject *RefHazmatDef::modelData()
{
    return d.data();
}

const TModelObject *RefHazmatDef::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefHazmatDef &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefHazmatDef &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefHazmatDef)
