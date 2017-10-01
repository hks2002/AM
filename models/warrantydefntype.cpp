#include <TreeFrogModel>
#include "warrantydefntype.h"
#include "warrantydefntypeobject.h"
#include "refwarrantytype.h"
#include "warrantydefn.h"

WarrantyDefnType::WarrantyDefnType()
    : TAbstractModel(), d(new WarrantyDefnTypeObject())
{
    d->warranty_defn_id = 0;
}

WarrantyDefnType::WarrantyDefnType(const WarrantyDefnType &other)
    : TAbstractModel(), d(new WarrantyDefnTypeObject(*other.d))
{ }

WarrantyDefnType::WarrantyDefnType(const WarrantyDefnTypeObject &object)
    : TAbstractModel(), d(new WarrantyDefnTypeObject(object))
{ }

WarrantyDefnType::~WarrantyDefnType()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnTypeObject' is deleted.
}

int WarrantyDefnType::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyDefnType::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

QString WarrantyDefnType::warrantyTypeCd() const
{
    return d->warranty_type_cd;
}

void WarrantyDefnType::setWarrantyTypeCd(const QString &warrantyTypeCd)
{
    d->warranty_type_cd = warrantyTypeCd;
}

QDateTime WarrantyDefnType::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefnType::createdBy() const
{
    return d->created_by;
}

void WarrantyDefnType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefnType::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefnType::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefnType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantyType WarrantyDefnType::refWarrantyTypeBywarrantyTypeCd() const
{
 return RefWarrantyType::get(d->warranty_type_cd);
}

WarrantyDefn WarrantyDefnType::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyDefnType &WarrantyDefnType::operator=(const WarrantyDefnType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefnType WarrantyDefnType::create(int warrantyDefnId, const QString &warrantyTypeCd, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnTypeObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.warranty_type_cd = warrantyTypeCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefnType();
    }
    return WarrantyDefnType(obj);
}

WarrantyDefnType WarrantyDefnType::create(const QVariantMap &values)
{
    WarrantyDefnType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefnType WarrantyDefnType::get(int warrantyDefnId, const QString &warrantyTypeCd)
{
    TSqlORMapper<WarrantyDefnTypeObject> mapper;
    return WarrantyDefnType(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyDefnId)<<QVariant(warrantyTypeCd)));
}

int WarrantyDefnType::count()
{
    TSqlORMapper<WarrantyDefnTypeObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefnType> WarrantyDefnType::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefnType, WarrantyDefnTypeObject>();
}

TModelObject *WarrantyDefnType::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefnType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefnType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefnType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefnType)
