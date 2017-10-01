#include <TreeFrogModel>
#include "poinvoiceline.h"
#include "poinvoicelineobject.h"
#include "fncaccount.h"
#include "qtyunit.h"
#include "eqppartno.h"
#include "poinvoice.h"

PoInvoiceLine::PoInvoiceLine()
    : TAbstractModel(), d(new PoInvoiceLineObject())
{
    d->po_invoice_line_id = 0;
    d->po_invoice_id = 0;
    d->line_no_ord = 0;
    d->part_no_id = 0;
    d->invoice_qt = 0;
    d->qty_unit_id = 0;
    d->unit_price = 0;
    d->line_price = 0;
    d->account_id = 0;
}

PoInvoiceLine::PoInvoiceLine(const PoInvoiceLine &other)
    : TAbstractModel(), d(new PoInvoiceLineObject(*other.d))
{ }

PoInvoiceLine::PoInvoiceLine(const PoInvoiceLineObject &object)
    : TAbstractModel(), d(new PoInvoiceLineObject(object))
{ }

PoInvoiceLine::~PoInvoiceLine()
{
    // If the reference count becomes 0,
    // the shared data object 'PoInvoiceLineObject' is deleted.
}

int PoInvoiceLine::poInvoiceLineId() const
{
    return d->po_invoice_line_id;
}

int PoInvoiceLine::poInvoiceId() const
{
    return d->po_invoice_id;
}

void PoInvoiceLine::setPoInvoiceId(int poInvoiceId)
{
    d->po_invoice_id = poInvoiceId;
}

int PoInvoiceLine::lineNoOrd() const
{
    return d->line_no_ord;
}

void PoInvoiceLine::setLineNoOrd(int lineNoOrd)
{
    d->line_no_ord = lineNoOrd;
}

QString PoInvoiceLine::lineDesc() const
{
    return d->line_desc;
}

void PoInvoiceLine::setLineDesc(const QString &lineDesc)
{
    d->line_desc = lineDesc;
}

int PoInvoiceLine::partNoId() const
{
    return d->part_no_id;
}

void PoInvoiceLine::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int PoInvoiceLine::invoiceQt() const
{
    return d->invoice_qt;
}

void PoInvoiceLine::setInvoiceQt(int invoiceQt)
{
    d->invoice_qt = invoiceQt;
}

int PoInvoiceLine::qtyUnitId() const
{
    return d->qty_unit_id;
}

void PoInvoiceLine::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

double PoInvoiceLine::unitPrice() const
{
    return d->unit_price;
}

void PoInvoiceLine::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

double PoInvoiceLine::linePrice() const
{
    return d->line_price;
}

void PoInvoiceLine::setLinePrice(double linePrice)
{
    d->line_price = linePrice;
}

QString PoInvoiceLine::invoiceLineNote() const
{
    return d->invoice_line_note;
}

void PoInvoiceLine::setInvoiceLineNote(const QString &invoiceLineNote)
{
    d->invoice_line_note = invoiceLineNote;
}

bool PoInvoiceLine::csgnBool() const
{
    return d->csgn_bool;
}

void PoInvoiceLine::setCsgnBool(bool csgnBool)
{
    d->csgn_bool = csgnBool;
}

int PoInvoiceLine::accountId() const
{
    return d->account_id;
}

void PoInvoiceLine::setAccountId(int accountId)
{
    d->account_id = accountId;
}

QDateTime PoInvoiceLine::createdAt() const
{
    return d->created_at;
}

QString PoInvoiceLine::createdBy() const
{
    return d->created_by;
}

void PoInvoiceLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoInvoiceLine::updatedAt() const
{
    return d->updated_at;
}

QString PoInvoiceLine::updatedBy() const
{
    return d->updated_by;
}

void PoInvoiceLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount PoInvoiceLine::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

QtyUnit PoInvoiceLine::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

EqpPartNo PoInvoiceLine::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

PoInvoice PoInvoiceLine::poInvoiceBypoInvoiceId() const
{
 return PoInvoice::get(d->po_invoice_id);
}

PoInvoiceLine &PoInvoiceLine::operator=(const PoInvoiceLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoInvoiceLine PoInvoiceLine::create(int poInvoiceId, int lineNoOrd, const QString &lineDesc, int partNoId, int invoiceQt, int qtyUnitId, double unitPrice, double linePrice, const QString &invoiceLineNote, bool csgnBool, int accountId, const QString &createdBy, const QString &updatedBy)
{
    PoInvoiceLineObject obj;
    obj.po_invoice_id = poInvoiceId;
    obj.line_no_ord = lineNoOrd;
    obj.line_desc = lineDesc;
    obj.part_no_id = partNoId;
    obj.invoice_qt = invoiceQt;
    obj.qty_unit_id = qtyUnitId;
    obj.unit_price = unitPrice;
    obj.line_price = linePrice;
    obj.invoice_line_note = invoiceLineNote;
    obj.csgn_bool = csgnBool;
    obj.account_id = accountId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoInvoiceLine();
    }
    return PoInvoiceLine(obj);
}

PoInvoiceLine PoInvoiceLine::create(const QVariantMap &values)
{
    PoInvoiceLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoInvoiceLine PoInvoiceLine::get(int poInvoiceLineId)
{
    TSqlORMapper<PoInvoiceLineObject> mapper;
    return PoInvoiceLine(mapper.findByPrimaryKey(poInvoiceLineId));
}

int PoInvoiceLine::count()
{
    TSqlORMapper<PoInvoiceLineObject> mapper;
    return mapper.findCount();
}

QList<PoInvoiceLine> PoInvoiceLine::getAll()
{
    return tfGetModelListByCriteria<PoInvoiceLine, PoInvoiceLineObject>();
}

TModelObject *PoInvoiceLine::modelData()
{
    return d.data();
}

const TModelObject *PoInvoiceLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoInvoiceLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoInvoiceLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoInvoiceLine)
