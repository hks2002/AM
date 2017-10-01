#include <TreeFrogModel>
#include "fncxactionlog.h"
#include "fncxactionlogobject.h"
#include "currency.h"
#include "invinv.h"
#include "eqppartno.h"
#include "poinvoiceline.h"
#include "poinvoice.h"
#include "poline.h"
#include "poheader.h"
#include "refxactiontype.h"

FncXactionLog::FncXactionLog()
    : TAbstractModel(), d(new FncXactionLogObject())
{
    d->xaction_id = 0;
    d->po_id = 0;
    d->po_line_id = 0;
    d->po_invoice_id = 0;
    d->po_invoice_line_id = 0;
    d->part_no_id = 0;
    d->inv_no_id = 0;
    d->qty = 0;
    d->unit_price = 0;
    d->currency_id = 0;
    d->exchg_qt = 0;
}

FncXactionLog::FncXactionLog(const FncXactionLog &other)
    : TAbstractModel(), d(new FncXactionLogObject(*other.d))
{ }

FncXactionLog::FncXactionLog(const FncXactionLogObject &object)
    : TAbstractModel(), d(new FncXactionLogObject(object))
{ }

FncXactionLog::~FncXactionLog()
{
    // If the reference count becomes 0,
    // the shared data object 'FncXactionLogObject' is deleted.
}

int FncXactionLog::xactionId() const
{
    return d->xaction_id;
}

QString FncXactionLog::xactionTypeCd() const
{
    return d->xaction_type_cd;
}

void FncXactionLog::setXactionTypeCd(const QString &xactionTypeCd)
{
    d->xaction_type_cd = xactionTypeCd;
}

QString FncXactionLog::xactionDesc() const
{
    return d->xaction_desc;
}

void FncXactionLog::setXactionDesc(const QString &xactionDesc)
{
    d->xaction_desc = xactionDesc;
}

QDateTime FncXactionLog::xactionDt() const
{
    return d->xaction_dt;
}

void FncXactionLog::setXactionDt(const QDateTime &xactionDt)
{
    d->xaction_dt = xactionDt;
}

int FncXactionLog::poId() const
{
    return d->po_id;
}

void FncXactionLog::setPoId(int poId)
{
    d->po_id = poId;
}

int FncXactionLog::poLineId() const
{
    return d->po_line_id;
}

void FncXactionLog::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int FncXactionLog::poInvoiceId() const
{
    return d->po_invoice_id;
}

void FncXactionLog::setPoInvoiceId(int poInvoiceId)
{
    d->po_invoice_id = poInvoiceId;
}

int FncXactionLog::poInvoiceLineId() const
{
    return d->po_invoice_line_id;
}

void FncXactionLog::setPoInvoiceLineId(int poInvoiceLineId)
{
    d->po_invoice_line_id = poInvoiceLineId;
}

int FncXactionLog::partNoId() const
{
    return d->part_no_id;
}

void FncXactionLog::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int FncXactionLog::invNoId() const
{
    return d->inv_no_id;
}

void FncXactionLog::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int FncXactionLog::qty() const
{
    return d->qty;
}

void FncXactionLog::setQty(int qty)
{
    d->qty = qty;
}

double FncXactionLog::unitPrice() const
{
    return d->unit_price;
}

void FncXactionLog::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

int FncXactionLog::currencyId() const
{
    return d->currency_id;
}

void FncXactionLog::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

double FncXactionLog::exchgQt() const
{
    return d->exchg_qt;
}

void FncXactionLog::setExchgQt(double exchgQt)
{
    d->exchg_qt = exchgQt;
}

QDateTime FncXactionLog::createdAt() const
{
    return d->created_at;
}

QString FncXactionLog::createdBy() const
{
    return d->created_by;
}

void FncXactionLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FncXactionLog::updatedAt() const
{
    return d->updated_at;
}

QString FncXactionLog::updatedBy() const
{
    return d->updated_by;
}

void FncXactionLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Currency FncXactionLog::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

InvInv FncXactionLog::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

EqpPartNo FncXactionLog::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

PoInvoiceLine FncXactionLog::poInvoiceLineBypoInvoiceLineId() const
{
 return PoInvoiceLine::get(d->po_invoice_line_id);
}

PoInvoice FncXactionLog::poInvoiceBypoInvoiceId() const
{
 return PoInvoice::get(d->po_invoice_id);
}

PoLine FncXactionLog::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoHeader FncXactionLog::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

RefXactionType FncXactionLog::refXactionTypeByxactionTypeCd() const
{
 return RefXactionType::get(d->xaction_type_cd);
}

FncXactionLog &FncXactionLog::operator=(const FncXactionLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FncXactionLog FncXactionLog::create(const QString &xactionTypeCd, const QString &xactionDesc, const QDateTime &xactionDt, int poId, int poLineId, int poInvoiceId, int poInvoiceLineId, int partNoId, int invNoId, int qty, double unitPrice, int currencyId, double exchgQt, const QString &createdBy, const QString &updatedBy)
{
    FncXactionLogObject obj;
    obj.xaction_type_cd = xactionTypeCd;
    obj.xaction_desc = xactionDesc;
    obj.xaction_dt = xactionDt;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.po_invoice_id = poInvoiceId;
    obj.po_invoice_line_id = poInvoiceLineId;
    obj.part_no_id = partNoId;
    obj.inv_no_id = invNoId;
    obj.qty = qty;
    obj.unit_price = unitPrice;
    obj.currency_id = currencyId;
    obj.exchg_qt = exchgQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FncXactionLog();
    }
    return FncXactionLog(obj);
}

FncXactionLog FncXactionLog::create(const QVariantMap &values)
{
    FncXactionLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FncXactionLog FncXactionLog::get(int xactionId)
{
    TSqlORMapper<FncXactionLogObject> mapper;
    return FncXactionLog(mapper.findByPrimaryKey(xactionId));
}

int FncXactionLog::count()
{
    TSqlORMapper<FncXactionLogObject> mapper;
    return mapper.findCount();
}

QList<FncXactionLog> FncXactionLog::getAll()
{
    return tfGetModelListByCriteria<FncXactionLog, FncXactionLogObject>();
}

TModelObject *FncXactionLog::modelData()
{
    return d.data();
}

const TModelObject *FncXactionLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FncXactionLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FncXactionLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FncXactionLog)
