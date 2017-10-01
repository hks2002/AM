#include <TreeFrogModel>
#include "polinewarranty.h"
#include "polinewarrantyobject.h"
#include "warrantydefn.h"
#include "poline.h"

PoLineWarranty::PoLineWarranty()
    : TAbstractModel(), d(new PoLineWarrantyObject())
{
    d->po_line_id = 0;
    d->warranty_defn_id = 0;
}

PoLineWarranty::PoLineWarranty(const PoLineWarranty &other)
    : TAbstractModel(), d(new PoLineWarrantyObject(*other.d))
{ }

PoLineWarranty::PoLineWarranty(const PoLineWarrantyObject &object)
    : TAbstractModel(), d(new PoLineWarrantyObject(object))
{ }

PoLineWarranty::~PoLineWarranty()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineWarrantyObject' is deleted.
}

int PoLineWarranty::poLineId() const
{
    return d->po_line_id;
}

void PoLineWarranty::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoLineWarranty::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

void PoLineWarranty::setWarrantyDefnId(int warrantyDefnId)
{
    d->warranty_defn_id = warrantyDefnId;
}

QDateTime PoLineWarranty::createdAt() const
{
    return d->created_at;
}

QString PoLineWarranty::createdBy() const
{
    return d->created_by;
}

void PoLineWarranty::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLineWarranty::updatedAt() const
{
    return d->updated_at;
}

QString PoLineWarranty::updatedBy() const
{
    return d->updated_by;
}

void PoLineWarranty::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

WarrantyDefn PoLineWarranty::warrantyDefnBywarrantyDefnId() const
{
 return WarrantyDefn::get(d->warranty_defn_id);
}

PoLine PoLineWarranty::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoLineWarranty &PoLineWarranty::operator=(const PoLineWarranty &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLineWarranty PoLineWarranty::create(int poLineId, int warrantyDefnId, const QString &createdBy, const QString &updatedBy)
{
    PoLineWarrantyObject obj;
    obj.po_line_id = poLineId;
    obj.warranty_defn_id = warrantyDefnId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLineWarranty();
    }
    return PoLineWarranty(obj);
}

PoLineWarranty PoLineWarranty::create(const QVariantMap &values)
{
    PoLineWarranty model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLineWarranty PoLineWarranty::get(int poLineId)
{
    TSqlORMapper<PoLineWarrantyObject> mapper;
    return PoLineWarranty(mapper.findByPrimaryKey(poLineId));
}

int PoLineWarranty::count()
{
    TSqlORMapper<PoLineWarrantyObject> mapper;
    return mapper.findCount();
}

QList<PoLineWarranty> PoLineWarranty::getAll()
{
    return tfGetModelListByCriteria<PoLineWarranty, PoLineWarrantyObject>();
}

TModelObject *PoLineWarranty::modelData()
{
    return d.data();
}

const TModelObject *PoLineWarranty::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLineWarranty &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLineWarranty &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLineWarranty)
