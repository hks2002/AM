#include <TreeFrogModel>
#include "poinvoicelinetax.h"
#include "poinvoicelinetaxobject.h"
#include "tax.h"
#include "poinvoiceline.h"

PoInvoiceLineTax::PoInvoiceLineTax()
    : TAbstractModel(), d(new PoInvoiceLineTaxObject())
{
    d->po_invoice_line_id = 0;
    d->tax_id = 0;
    d->tax_amount = 0;
}

PoInvoiceLineTax::PoInvoiceLineTax(const PoInvoiceLineTax &other)
    : TAbstractModel(), d(new PoInvoiceLineTaxObject(*other.d))
{ }

PoInvoiceLineTax::PoInvoiceLineTax(const PoInvoiceLineTaxObject &object)
    : TAbstractModel(), d(new PoInvoiceLineTaxObject(object))
{ }

PoInvoiceLineTax::~PoInvoiceLineTax()
{
    // If the reference count becomes 0,
    // the shared data object 'PoInvoiceLineTaxObject' is deleted.
}

int PoInvoiceLineTax::poInvoiceLineId() const
{
    return d->po_invoice_line_id;
}

void PoInvoiceLineTax::setPoInvoiceLineId(int poInvoiceLineId)
{
    d->po_invoice_line_id = poInvoiceLineId;
}

int PoInvoiceLineTax::taxId() const
{
    return d->tax_id;
}

void PoInvoiceLineTax::setTaxId(int taxId)
{
    d->tax_id = taxId;
}

double PoInvoiceLineTax::taxAmount() const
{
    return d->tax_amount;
}

void PoInvoiceLineTax::setTaxAmount(double taxAmount)
{
    d->tax_amount = taxAmount;
}

QDateTime PoInvoiceLineTax::createdAt() const
{
    return d->created_at;
}

QString PoInvoiceLineTax::createdBy() const
{
    return d->created_by;
}

void PoInvoiceLineTax::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoInvoiceLineTax::updatedAt() const
{
    return d->updated_at;
}

QString PoInvoiceLineTax::updatedBy() const
{
    return d->updated_by;
}

void PoInvoiceLineTax::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Tax PoInvoiceLineTax::taxBytaxId() const
{
 return Tax::get(d->tax_id);
}

PoInvoiceLine PoInvoiceLineTax::poInvoiceLineBypoInvoiceLineId() const
{
 return PoInvoiceLine::get(d->po_invoice_line_id);
}

PoInvoiceLineTax &PoInvoiceLineTax::operator=(const PoInvoiceLineTax &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoInvoiceLineTax PoInvoiceLineTax::create(int poInvoiceLineId, int taxId, double taxAmount, const QString &createdBy, const QString &updatedBy)
{
    PoInvoiceLineTaxObject obj;
    obj.po_invoice_line_id = poInvoiceLineId;
    obj.tax_id = taxId;
    obj.tax_amount = taxAmount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoInvoiceLineTax();
    }
    return PoInvoiceLineTax(obj);
}

PoInvoiceLineTax PoInvoiceLineTax::create(const QVariantMap &values)
{
    PoInvoiceLineTax model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoInvoiceLineTax PoInvoiceLineTax::get(int poInvoiceLineId)
{
    TSqlORMapper<PoInvoiceLineTaxObject> mapper;
    return PoInvoiceLineTax(mapper.findByPrimaryKey(poInvoiceLineId));
}

int PoInvoiceLineTax::count()
{
    TSqlORMapper<PoInvoiceLineTaxObject> mapper;
    return mapper.findCount();
}

QList<PoInvoiceLineTax> PoInvoiceLineTax::getAll()
{
    return tfGetModelListByCriteria<PoInvoiceLineTax, PoInvoiceLineTaxObject>();
}

TModelObject *PoInvoiceLineTax::modelData()
{
    return d.data();
}

const TModelObject *PoInvoiceLineTax::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoInvoiceLineTax &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoInvoiceLineTax &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoInvoiceLineTax)
