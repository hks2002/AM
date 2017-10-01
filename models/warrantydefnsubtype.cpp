#include <TreeFrogModel>
#include "warrantydefnsubtype.h"
#include "warrantydefnsubtypeobject.h"
#include "refwarrantysubtype.h"
#include "warrantydefn.h"

WarrantyDefnSubtype::WarrantyDefnSubtype()
    : TAbstractModel(), d(new WarrantyDefnSubtypeObject())
{
    d->warranty_defn_id = 0;
}

WarrantyDefnSubtype::WarrantyDefnSubtype(const WarrantyDefnSubtype &other)
    : TAbstractModel(), d(new WarrantyDefnSubtypeObject(*other.d))
{ }

WarrantyDefnSubtype::WarrantyDefnSubtype(const WarrantyDefnSubtypeObject &object)
    : TAbstractModel(), d(new WarrantyDefnSubtypeObject(object))
{ }

WarrantyDefnSubtype::~WarrantyDefnSubtype()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnSubtypeObject' is deleted.
}

int WarrantyDefnSubtype::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyDefnSubtype::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

QString WarrantyDefnSubtype::warrantySubtypeCd() const
{
    return d->warranty_subtype_cd;
}

void WarrantyDefnSubtype::setWarrantySubtypeCd(const QString &warrantySubtypeCd)
{
    d->warranty_subtype_cd = warrantySubtypeCd;
}

QDateTime WarrantyDefnSubtype::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefnSubtype::createdBy() const
{
    return d->created_by;
}

void WarrantyDefnSubtype::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefnSubtype::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefnSubtype::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefnSubtype::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefWarrantySubtype WarrantyDefnSubtype::refWarrantySubtypeBywarrantySubtypeCd() const
{
 return RefWarrantySubtype::get(d->warranty_subtype_cd);
}

WarrantyDefn WarrantyDefnSubtype::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyDefnSubtype &WarrantyDefnSubtype::operator=(const WarrantyDefnSubtype &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefnSubtype WarrantyDefnSubtype::create(int warrantyDefnId, const QString &warrantySubtypeCd, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnSubtypeObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.warranty_subtype_cd = warrantySubtypeCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefnSubtype();
    }
    return WarrantyDefnSubtype(obj);
}

WarrantyDefnSubtype WarrantyDefnSubtype::create(const QVariantMap &values)
{
    WarrantyDefnSubtype model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefnSubtype WarrantyDefnSubtype::get(int warrantyDefnId, const QString &warrantySubtypeCd)
{
    TSqlORMapper<WarrantyDefnSubtypeObject> mapper;
    return WarrantyDefnSubtype(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyDefnId)<<QVariant(warrantySubtypeCd)));
}

int WarrantyDefnSubtype::count()
{
    TSqlORMapper<WarrantyDefnSubtypeObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefnSubtype> WarrantyDefnSubtype::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefnSubtype, WarrantyDefnSubtypeObject>();
}

TModelObject *WarrantyDefnSubtype::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefnSubtype::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefnSubtype &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefnSubtype &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefnSubtype)
