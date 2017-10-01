#include <TreeFrogModel>
#include "refinvclass.h"
#include "refinvclassobject.h"

RefInvClass::RefInvClass()
    : TAbstractModel(), d(new RefInvClassObject())
{ }

RefInvClass::RefInvClass(const RefInvClass &other)
    : TAbstractModel(), d(new RefInvClassObject(*other.d))
{ }

RefInvClass::RefInvClass(const RefInvClassObject &object)
    : TAbstractModel(), d(new RefInvClassObject(object))
{ }

RefInvClass::~RefInvClass()
{
    // If the reference count becomes 0,
    // the shared data object 'RefInvClassObject' is deleted.
}

QString RefInvClass::invClassCd() const
{
    return d->inv_class_cd;
}

void RefInvClass::setInvClassCd(const QString &invClassCd)
{
    d->inv_class_cd = invClassCd;
}

QString RefInvClass::invClassNameEn() const
{
    return d->inv_class_name_en;
}

void RefInvClass::setInvClassNameEn(const QString &invClassNameEn)
{
    d->inv_class_name_en = invClassNameEn;
}

QString RefInvClass::invClassNameZh() const
{
    return d->inv_class_name_zh;
}

void RefInvClass::setInvClassNameZh(const QString &invClassNameZh)
{
    d->inv_class_name_zh = invClassNameZh;
}

QString RefInvClass::invClassDesc() const
{
    return d->inv_class_desc;
}

void RefInvClass::setInvClassDesc(const QString &invClassDesc)
{
    d->inv_class_desc = invClassDesc;
}

QDateTime RefInvClass::createdAt() const
{
    return d->created_at;
}

QString RefInvClass::createdBy() const
{
    return d->created_by;
}

void RefInvClass::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefInvClass::updatedAt() const
{
    return d->updated_at;
}

QString RefInvClass::updatedBy() const
{
    return d->updated_by;
}

void RefInvClass::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefInvClass &RefInvClass::operator=(const RefInvClass &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefInvClass RefInvClass::create(const QString &invClassCd, const QString &invClassNameEn, const QString &invClassNameZh, const QString &invClassDesc, const QString &createdBy, const QString &updatedBy)
{
    RefInvClassObject obj;
    obj.inv_class_cd = invClassCd;
    obj.inv_class_name_en = invClassNameEn;
    obj.inv_class_name_zh = invClassNameZh;
    obj.inv_class_desc = invClassDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefInvClass();
    }
    return RefInvClass(obj);
}

RefInvClass RefInvClass::create(const QVariantMap &values)
{
    RefInvClass model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefInvClass RefInvClass::get(const QString &invClassCd)
{
    TSqlORMapper<RefInvClassObject> mapper;
    return RefInvClass(mapper.findByPrimaryKey(invClassCd));
}

int RefInvClass::count()
{
    TSqlORMapper<RefInvClassObject> mapper;
    return mapper.findCount();
}

QList<RefInvClass> RefInvClass::getAll()
{
    return tfGetModelListByCriteria<RefInvClass, RefInvClassObject>();
}

TModelObject *RefInvClass::modelData()
{
    return d.data();
}

const TModelObject *RefInvClass::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefInvClass &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefInvClass &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefInvClass)
