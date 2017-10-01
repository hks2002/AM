#include <TreeFrogModel>
#include "poinvoicelinemap.h"
#include "poinvoicelinemapobject.h"
#include "poinvoiceline.h"
#include "poinvoice.h"
#include "poline.h"
#include "poheader.h"

PoInvoiceLineMap::PoInvoiceLineMap()
    : TAbstractModel(), d(new PoInvoiceLineMapObject())
{
    d->po_id = 0;
    d->po_line_id = 0;
    d->po_invoice_id = 0;
    d->po_invoice_line_id = 0;
}

PoInvoiceLineMap::PoInvoiceLineMap(const PoInvoiceLineMap &other)
    : TAbstractModel(), d(new PoInvoiceLineMapObject(*other.d))
{ }

PoInvoiceLineMap::PoInvoiceLineMap(const PoInvoiceLineMapObject &object)
    : TAbstractModel(), d(new PoInvoiceLineMapObject(object))
{ }

PoInvoiceLineMap::~PoInvoiceLineMap()
{
    // If the reference count becomes 0,
    // the shared data object 'PoInvoiceLineMapObject' is deleted.
}

int PoInvoiceLineMap::poId() const
{
    return d->po_id;
}

void PoInvoiceLineMap::setPoId(int poId)
{
    d->po_id = poId;
}

int PoInvoiceLineMap::poLineId() const
{
    return d->po_line_id;
}

void PoInvoiceLineMap::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoInvoiceLineMap::poInvoiceId() const
{
    return d->po_invoice_id;
}

void PoInvoiceLineMap::setPoInvoiceId(int poInvoiceId)
{
    d->po_invoice_id = poInvoiceId;
}

int PoInvoiceLineMap::poInvoiceLineId() const
{
    return d->po_invoice_line_id;
}

void PoInvoiceLineMap::setPoInvoiceLineId(int poInvoiceLineId)
{
    d->po_invoice_line_id = poInvoiceLineId;
}

QDateTime PoInvoiceLineMap::createdAt() const
{
    return d->created_at;
}

QString PoInvoiceLineMap::createdBy() const
{
    return d->created_by;
}

void PoInvoiceLineMap::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoInvoiceLineMap::updatedAt() const
{
    return d->updated_at;
}

QString PoInvoiceLineMap::updatedBy() const
{
    return d->updated_by;
}

void PoInvoiceLineMap::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

PoInvoiceLine PoInvoiceLineMap::poInvoiceLineBypoInvoiceLineId() const
{
 return PoInvoiceLine::get(d->po_invoice_line_id);
}

PoInvoice PoInvoiceLineMap::poInvoiceBypoInvoiceId() const
{
 return PoInvoice::get(d->po_invoice_id);
}

PoLine PoInvoiceLineMap::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoHeader PoInvoiceLineMap::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

PoInvoiceLineMap &PoInvoiceLineMap::operator=(const PoInvoiceLineMap &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoInvoiceLineMap PoInvoiceLineMap::create(int poId, int poLineId, int poInvoiceId, int poInvoiceLineId, const QString &createdBy, const QString &updatedBy)
{
    PoInvoiceLineMapObject obj;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.po_invoice_id = poInvoiceId;
    obj.po_invoice_line_id = poInvoiceLineId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoInvoiceLineMap();
    }
    return PoInvoiceLineMap(obj);
}

PoInvoiceLineMap PoInvoiceLineMap::create(const QVariantMap &values)
{
    PoInvoiceLineMap model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoInvoiceLineMap PoInvoiceLineMap::get(int poId, int poLineId, int poInvoiceId, int poInvoiceLineId)
{
    TSqlORMapper<PoInvoiceLineMapObject> mapper;
    return PoInvoiceLineMap(mapper.findByPrimaryKey(QVariantList()<<QVariant(poId)<<QVariant(poLineId)<<QVariant(poInvoiceId)<<QVariant(poInvoiceLineId)));
}

int PoInvoiceLineMap::count()
{
    TSqlORMapper<PoInvoiceLineMapObject> mapper;
    return mapper.findCount();
}

QList<PoInvoiceLineMap> PoInvoiceLineMap::getAll()
{
    return tfGetModelListByCriteria<PoInvoiceLineMap, PoInvoiceLineMapObject>();
}

TModelObject *PoInvoiceLineMap::modelData()
{
    return d.data();
}

const TModelObject *PoInvoiceLineMap::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoInvoiceLineMap &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoInvoiceLineMap &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoInvoiceLineMap)
