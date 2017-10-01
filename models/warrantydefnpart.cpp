#include <TreeFrogModel>
#include "warrantydefnpart.h"
#include "warrantydefnpartobject.h"
#include "eqppartno.h"
#include "warrantydefn.h"

WarrantyDefnPart::WarrantyDefnPart()
    : TAbstractModel(), d(new WarrantyDefnPartObject())
{
    d->warranty_defn_id = 0;
    d->part_no_id = 0;
}

WarrantyDefnPart::WarrantyDefnPart(const WarrantyDefnPart &other)
    : TAbstractModel(), d(new WarrantyDefnPartObject(*other.d))
{ }

WarrantyDefnPart::WarrantyDefnPart(const WarrantyDefnPartObject &object)
    : TAbstractModel(), d(new WarrantyDefnPartObject(object))
{ }

WarrantyDefnPart::~WarrantyDefnPart()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnPartObject' is deleted.
}

int WarrantyDefnPart::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyDefnPart::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

int WarrantyDefnPart::partNoId() const
{
    return d->part_no_id;
}

void WarrantyDefnPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QDateTime WarrantyDefnPart::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefnPart::createdBy() const
{
    return d->created_by;
}

void WarrantyDefnPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefnPart::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefnPart::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefnPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo WarrantyDefnPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

WarrantyDefn WarrantyDefnPart::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyDefnPart &WarrantyDefnPart::operator=(const WarrantyDefnPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefnPart WarrantyDefnPart::create(int warrantyDefnId, int partNoId, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnPartObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.part_no_id = partNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefnPart();
    }
    return WarrantyDefnPart(obj);
}

WarrantyDefnPart WarrantyDefnPart::create(const QVariantMap &values)
{
    WarrantyDefnPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefnPart WarrantyDefnPart::get(int warrantyDefnId, int partNoId)
{
    TSqlORMapper<WarrantyDefnPartObject> mapper;
    return WarrantyDefnPart(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyDefnId)<<QVariant(partNoId)));
}

int WarrantyDefnPart::count()
{
    TSqlORMapper<WarrantyDefnPartObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefnPart> WarrantyDefnPart::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefnPart, WarrantyDefnPartObject>();
}

TModelObject *WarrantyDefnPart::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefnPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefnPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefnPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefnPart)
