#include <TreeFrogModel>
#include "warrantydefnassmbl.h"
#include "warrantydefnassmblobject.h"
#include "eqpassmbl.h"
#include "warrantydefn.h"

WarrantyDefnAssmbl::WarrantyDefnAssmbl()
    : TAbstractModel(), d(new WarrantyDefnAssmblObject())
{
    d->warranty_defn_id = 0;
    d->assmbl_id = 0;
}

WarrantyDefnAssmbl::WarrantyDefnAssmbl(const WarrantyDefnAssmbl &other)
    : TAbstractModel(), d(new WarrantyDefnAssmblObject(*other.d))
{ }

WarrantyDefnAssmbl::WarrantyDefnAssmbl(const WarrantyDefnAssmblObject &object)
    : TAbstractModel(), d(new WarrantyDefnAssmblObject(object))
{ }

WarrantyDefnAssmbl::~WarrantyDefnAssmbl()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnAssmblObject' is deleted.
}

int WarrantyDefnAssmbl::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void WarrantyDefnAssmbl::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

int WarrantyDefnAssmbl::assmblId() const
{
    return d->assmbl_id;
}

void WarrantyDefnAssmbl::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

QDateTime WarrantyDefnAssmbl::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefnAssmbl::createdBy() const
{
    return d->created_by;
}

void WarrantyDefnAssmbl::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefnAssmbl::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefnAssmbl::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefnAssmbl::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpAssmbl WarrantyDefnAssmbl::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

WarrantyDefn WarrantyDefnAssmbl::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

WarrantyDefnAssmbl &WarrantyDefnAssmbl::operator=(const WarrantyDefnAssmbl &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefnAssmbl WarrantyDefnAssmbl::create(int warrantyDefnId, int assmblId, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnAssmblObject obj;
    obj.warranty_defn_id = warrantyDefnId;
    obj.assmbl_id = assmblId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefnAssmbl();
    }
    return WarrantyDefnAssmbl(obj);
}

WarrantyDefnAssmbl WarrantyDefnAssmbl::create(const QVariantMap &values)
{
    WarrantyDefnAssmbl model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefnAssmbl WarrantyDefnAssmbl::get(int warrantyDefnId, int assmblId)
{
    TSqlORMapper<WarrantyDefnAssmblObject> mapper;
    return WarrantyDefnAssmbl(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyDefnId)<<QVariant(assmblId)));
}

int WarrantyDefnAssmbl::count()
{
    TSqlORMapper<WarrantyDefnAssmblObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefnAssmbl> WarrantyDefnAssmbl::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefnAssmbl, WarrantyDefnAssmblObject>();
}

TModelObject *WarrantyDefnAssmbl::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefnAssmbl::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefnAssmbl &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefnAssmbl &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefnAssmbl)
