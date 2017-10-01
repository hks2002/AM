#include <TreeFrogModel>
#include "refassmblclass.h"
#include "refassmblclassobject.h"

RefAssmblClass::RefAssmblClass()
    : TAbstractModel(), d(new RefAssmblClassObject())
{ }

RefAssmblClass::RefAssmblClass(const RefAssmblClass &other)
    : TAbstractModel(), d(new RefAssmblClassObject(*other.d))
{ }

RefAssmblClass::RefAssmblClass(const RefAssmblClassObject &object)
    : TAbstractModel(), d(new RefAssmblClassObject(object))
{ }

RefAssmblClass::~RefAssmblClass()
{
    // If the reference count becomes 0,
    // the shared data object 'RefAssmblClassObject' is deleted.
}

QString RefAssmblClass::assmblClassCd() const
{
    return d->assmbl_class_cd;
}

void RefAssmblClass::setAssmblClassCd(const QString &assmblClassCd)
{
    d->assmbl_class_cd = assmblClassCd;
}

QString RefAssmblClass::assmblClassNameEn() const
{
    return d->assmbl_class_name_en;
}

void RefAssmblClass::setAssmblClassNameEn(const QString &assmblClassNameEn)
{
    d->assmbl_class_name_en = assmblClassNameEn;
}

QString RefAssmblClass::assmblClassNameZh() const
{
    return d->assmbl_class_name_zh;
}

void RefAssmblClass::setAssmblClassNameZh(const QString &assmblClassNameZh)
{
    d->assmbl_class_name_zh = assmblClassNameZh;
}

QString RefAssmblClass::assmblClassDesc() const
{
    return d->assmbl_class_desc;
}

void RefAssmblClass::setAssmblClassDesc(const QString &assmblClassDesc)
{
    d->assmbl_class_desc = assmblClassDesc;
}

QDateTime RefAssmblClass::createdAt() const
{
    return d->created_at;
}

QString RefAssmblClass::createdBy() const
{
    return d->created_by;
}

void RefAssmblClass::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefAssmblClass::updatedAt() const
{
    return d->updated_at;
}

QString RefAssmblClass::updatedBy() const
{
    return d->updated_by;
}

void RefAssmblClass::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAssmblClass &RefAssmblClass::operator=(const RefAssmblClass &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefAssmblClass RefAssmblClass::create(const QString &assmblClassCd, const QString &assmblClassNameEn, const QString &assmblClassNameZh, const QString &assmblClassDesc, const QString &createdBy, const QString &updatedBy)
{
    RefAssmblClassObject obj;
    obj.assmbl_class_cd = assmblClassCd;
    obj.assmbl_class_name_en = assmblClassNameEn;
    obj.assmbl_class_name_zh = assmblClassNameZh;
    obj.assmbl_class_desc = assmblClassDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefAssmblClass();
    }
    return RefAssmblClass(obj);
}

RefAssmblClass RefAssmblClass::create(const QVariantMap &values)
{
    RefAssmblClass model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefAssmblClass RefAssmblClass::get(const QString &assmblClassCd)
{
    TSqlORMapper<RefAssmblClassObject> mapper;
    return RefAssmblClass(mapper.findByPrimaryKey(assmblClassCd));
}

int RefAssmblClass::count()
{
    TSqlORMapper<RefAssmblClassObject> mapper;
    return mapper.findCount();
}

QList<RefAssmblClass> RefAssmblClass::getAll()
{
    return tfGetModelListByCriteria<RefAssmblClass, RefAssmblClassObject>();
}

TModelObject *RefAssmblClass::modelData()
{
    return d.data();
}

const TModelObject *RefAssmblClass::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefAssmblClass &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefAssmblClass &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefAssmblClass)
