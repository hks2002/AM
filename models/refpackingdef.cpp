#include <TreeFrogModel>
#include "refpackingdef.h"
#include "refpackingdefobject.h"

RefPackingDef::RefPackingDef()
    : TAbstractModel(), d(new RefPackingDefObject())
{ }

RefPackingDef::RefPackingDef(const RefPackingDef &other)
    : TAbstractModel(), d(new RefPackingDefObject(*other.d))
{ }

RefPackingDef::RefPackingDef(const RefPackingDefObject &object)
    : TAbstractModel(), d(new RefPackingDefObject(object))
{ }

RefPackingDef::~RefPackingDef()
{
    // If the reference count becomes 0,
    // the shared data object 'RefPackingDefObject' is deleted.
}

QDateTime RefPackingDef::createdAt() const
{
    return d->created_at;
}

QString RefPackingDef::createdBy() const
{
    return d->created_by;
}

void RefPackingDef::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefPackingDef::updatedAt() const
{
    return d->updated_at;
}

QString RefPackingDef::updatedBy() const
{
    return d->updated_by;
}

void RefPackingDef::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPackingDef &RefPackingDef::operator=(const RefPackingDef &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefPackingDef RefPackingDef::create(const QString &createdBy, const QString &updatedBy)
{
    RefPackingDefObject obj;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefPackingDef();
    }
    return RefPackingDef(obj);
}

RefPackingDef RefPackingDef::create(const QVariantMap &values)
{
    RefPackingDef model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefPackingDef RefPackingDef::get(const QString &createdBy, const QString &updatedBy)
{
    TCriteria cri;
    cri.add(RefPackingDefObject::CreatedBy, createdBy);
    cri.add(RefPackingDefObject::UpdatedBy, updatedBy);
    TSqlORMapper<RefPackingDefObject> mapper;
    return RefPackingDef(mapper.findFirst(cri));
}

int RefPackingDef::count()
{
    TSqlORMapper<RefPackingDefObject> mapper;
    return mapper.findCount();
}

QList<RefPackingDef> RefPackingDef::getAll()
{
    return tfGetModelListByCriteria<RefPackingDef, RefPackingDefObject>();
}

TModelObject *RefPackingDef::modelData()
{
    return d.data();
}

const TModelObject *RefPackingDef::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefPackingDef &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefPackingDef &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefPackingDef)
