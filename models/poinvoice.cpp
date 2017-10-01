#include <TreeFrogModel>
#include "poinvoice.h"
#include "poinvoiceobject.h"
#include "userapp.h"
#include "refpaymentterms.h"
#include "currency.h"
#include "fncaccount.h"
#include "vendor.h"

PoInvoice::PoInvoice()
    : TAbstractModel(), d(new PoInvoiceObject())
{
    d->po_invoice_id = 0;
    d->vendor_id = 0;
    d->vendor_account_id = 0;
    d->total_invoice = 0;
    d->currency_id = 0;
    d->exchg_qt = 0;
    d->cash_discount_pct = 0;
    d->po_invoice_pay_by = 0;
}

PoInvoice::PoInvoice(const PoInvoice &other)
    : TAbstractModel(), d(new PoInvoiceObject(*other.d))
{ }

PoInvoice::PoInvoice(const PoInvoiceObject &object)
    : TAbstractModel(), d(new PoInvoiceObject(object))
{ }

PoInvoice::~PoInvoice()
{
    // If the reference count becomes 0,
    // the shared data object 'PoInvoiceObject' is deleted.
}

int PoInvoice::poInvoiceId() const
{
    return d->po_invoice_id;
}

QString PoInvoice::poInvoiceCd() const
{
    return d->po_invoice_cd;
}

void PoInvoice::setPoInvoiceCd(const QString &poInvoiceCd)
{
    d->po_invoice_cd = poInvoiceCd;
}

int PoInvoice::vendorId() const
{
    return d->vendor_id;
}

void PoInvoice::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int PoInvoice::vendorAccountId() const
{
    return d->vendor_account_id;
}

void PoInvoice::setVendorAccountId(int vendorAccountId)
{
    d->vendor_account_id = vendorAccountId;
}

double PoInvoice::totalInvoice() const
{
    return d->total_invoice;
}

void PoInvoice::setTotalInvoice(double totalInvoice)
{
    d->total_invoice = totalInvoice;
}

int PoInvoice::currencyId() const
{
    return d->currency_id;
}

void PoInvoice::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

double PoInvoice::exchgQt() const
{
    return d->exchg_qt;
}

void PoInvoice::setExchgQt(double exchgQt)
{
    d->exchg_qt = exchgQt;
}

QString PoInvoice::paymentTermsCd() const
{
    return d->payment_terms_cd;
}

void PoInvoice::setPaymentTermsCd(const QString &paymentTermsCd)
{
    d->payment_terms_cd = paymentTermsCd;
}

QString PoInvoice::invoiceNote() const
{
    return d->invoice_note;
}

void PoInvoice::setInvoiceNote(const QString &invoiceNote)
{
    d->invoice_note = invoiceNote;
}

double PoInvoice::cashDiscountPct() const
{
    return d->cash_discount_pct;
}

void PoInvoice::setCashDiscountPct(double cashDiscountPct)
{
    d->cash_discount_pct = cashDiscountPct;
}

QDateTime PoInvoice::cashDiscountExpDt() const
{
    return d->cash_discount_exp_dt;
}

void PoInvoice::setCashDiscountExpDt(const QDateTime &cashDiscountExpDt)
{
    d->cash_discount_exp_dt = cashDiscountExpDt;
}

QDateTime PoInvoice::invoiceDt() const
{
    return d->invoice_dt;
}

void PoInvoice::setInvoiceDt(const QDateTime &invoiceDt)
{
    d->invoice_dt = invoiceDt;
}

int PoInvoice::poInvoicePayBy() const
{
    return d->po_invoice_pay_by;
}

void PoInvoice::setPoInvoicePayBy(int poInvoicePayBy)
{
    d->po_invoice_pay_by = poInvoicePayBy;
}

QDateTime PoInvoice::poInvoicePayDt() const
{
    return d->po_invoice_pay_dt;
}

void PoInvoice::setPoInvoicePayDt(const QDateTime &poInvoicePayDt)
{
    d->po_invoice_pay_dt = poInvoicePayDt;
}

QDateTime PoInvoice::createdAt() const
{
    return d->created_at;
}

QString PoInvoice::createdBy() const
{
    return d->created_by;
}

void PoInvoice::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoInvoice::updatedAt() const
{
    return d->updated_at;
}

QString PoInvoice::updatedBy() const
{
    return d->updated_by;
}

void PoInvoice::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp PoInvoice::userAppBypoInvoicePayBy() const
{
 return UserApp::get(d->po_invoice_pay_by);
}

RefPaymentTerms PoInvoice::refPaymentTermsBypaymentTermsCd() const
{
 return RefPaymentTerms::get(d->payment_terms_cd);
}

Currency PoInvoice::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

FncAccount PoInvoice::fncAccountByvendorAccountId() const
{
 return FncAccount::get(d->vendor_account_id);
}

Vendor PoInvoice::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

PoInvoice &PoInvoice::operator=(const PoInvoice &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoInvoice PoInvoice::create(const QString &poInvoiceCd, int vendorId, int vendorAccountId, double totalInvoice, int currencyId, double exchgQt, const QString &paymentTermsCd, const QString &invoiceNote, double cashDiscountPct, const QDateTime &cashDiscountExpDt, const QDateTime &invoiceDt, int poInvoicePayBy, const QDateTime &poInvoicePayDt, const QString &createdBy, const QString &updatedBy)
{
    PoInvoiceObject obj;
    obj.po_invoice_cd = poInvoiceCd;
    obj.vendor_id = vendorId;
    obj.vendor_account_id = vendorAccountId;
    obj.total_invoice = totalInvoice;
    obj.currency_id = currencyId;
    obj.exchg_qt = exchgQt;
    obj.payment_terms_cd = paymentTermsCd;
    obj.invoice_note = invoiceNote;
    obj.cash_discount_pct = cashDiscountPct;
    obj.cash_discount_exp_dt = cashDiscountExpDt;
    obj.invoice_dt = invoiceDt;
    obj.po_invoice_pay_by = poInvoicePayBy;
    obj.po_invoice_pay_dt = poInvoicePayDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoInvoice();
    }
    return PoInvoice(obj);
}

PoInvoice PoInvoice::create(const QVariantMap &values)
{
    PoInvoice model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoInvoice PoInvoice::get(int poInvoiceId)
{
    TSqlORMapper<PoInvoiceObject> mapper;
    return PoInvoice(mapper.findByPrimaryKey(poInvoiceId));
}

int PoInvoice::count()
{
    TSqlORMapper<PoInvoiceObject> mapper;
    return mapper.findCount();
}

QList<PoInvoice> PoInvoice::getAll()
{
    return tfGetModelListByCriteria<PoInvoice, PoInvoiceObject>();
}

TModelObject *PoInvoice::modelData()
{
    return d.data();
}

const TModelObject *PoInvoice::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoInvoice &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoInvoice &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoInvoice)
