#include <TreeFrogModel>
#include "refbomclass.h"
#include "refbomclassobject.h"

RefBomClass::RefBomClass()
    : TAbstractModel(), d(new RefBomClassObject())
{ }

RefBomClass::RefBomClass(const RefBomClass &other)
    : TAbstractModel(), d(new RefBomClassObject(*other.d))
{ }

RefBomClass::RefBomClass(const RefBomClassObject &object)
    : TAbstractModel(), d(new RefBomClassObject(object))
{ }

RefBomClass::~RefBomClass()
{
    // If the reference count becomes 0,
    // the shared data object 'RefBomClassObject' is deleted.
}

QString RefBomClass::bomClassCd() const
{
    return d->bom_class_cd;
}

void RefBomClass::setBomClassCd(const QString &bomClassCd)
{
    d->bom_class_cd = bomClassCd;
}

QString RefBomClass::bomClassNameEn() const
{
    return d->bom_class_name_en;
}

void RefBomClass::setBomClassNameEn(const QString &bomClassNameEn)
{
    d->bom_class_name_en = bomClassNameEn;
}

QString RefBomClass::bomClassNameZh() const
{
    return d->bom_class_name_zh;
}

void RefBomClass::setBomClassNameZh(const QString &bomClassNameZh)
{
    d->bom_class_name_zh = bomClassNameZh;
}

QString RefBomClass::bomClassDesc() const
{
    return d->bom_class_desc;
}

void RefBomClass::setBomClassDesc(const QString &bomClassDesc)
{
    d->bom_class_desc = bomClassDesc;
}

QDateTime RefBomClass::createdAt() const
{
    return d->created_at;
}

QString RefBomClass::createdBy() const
{
    return d->created_by;
}

void RefBomClass::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefBomClass::updatedAt() const
{
    return d->updated_at;
}

QString RefBomClass::updatedBy() const
{
    return d->updated_by;
}

void RefBomClass::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefBomClass &RefBomClass::operator=(const RefBomClass &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefBomClass RefBomClass::create(const QString &bomClassCd, const QString &bomClassNameEn, const QString &bomClassNameZh, const QString &bomClassDesc, const QString &createdBy, const QString &updatedBy)
{
    RefBomClassObject obj;
    obj.bom_class_cd = bomClassCd;
    obj.bom_class_name_en = bomClassNameEn;
    obj.bom_class_name_zh = bomClassNameZh;
    obj.bom_class_desc = bomClassDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefBomClass();
    }
    return RefBomClass(obj);
}

RefBomClass RefBomClass::create(const QVariantMap &values)
{
    RefBomClass model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefBomClass RefBomClass::get(const QString &bomClassCd)
{
    TSqlORMapper<RefBomClassObject> mapper;
    return RefBomClass(mapper.findByPrimaryKey(bomClassCd));
}

int RefBomClass::count()
{
    TSqlORMapper<RefBomClassObject> mapper;
    return mapper.findCount();
}

QList<RefBomClass> RefBomClass::getAll()
{
    return tfGetModelListByCriteria<RefBomClass, RefBomClassObject>();
}

TModelObject *RefBomClass::modelData()
{
    return d.data();
}

const TModelObject *RefBomClass::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefBomClass &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefBomClass &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefBomClass)
