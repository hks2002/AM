#include <TreeFrogModel>
#include "poheader.h"
#include "poheaderobject.h"
#include "refpotype.h"
#include "refreqpriority.h"
#include "refreqtype.h"
#include "vendor.h"
#include "fncaccount.h"
#include "currency.h"
#include "refborrowrate.h"
#include "refpaymentterms.h"
#include "reftradeterms.h"
#include "loc.h"
#include "transportor.h"
#include "org.h"
#include "userapp.h"

PoHeader::PoHeader()
    : TAbstractModel(), d(new PoHeaderObject())
{
    d->po_id = 0;
    d->vendor_id = 0;
    d->vendor_account_id = 0;
    d->currency_id = 0;
    d->final_loc_id = 0;
    d->re_expedite_to_loc_id = 0;
    d->transportor_id = 0;
    d->org_id = 0;
    d->contact_to = 0;
    d->po_created_by = 0;
    d->po_issued_by = 0;
    d->po_closed_by = 0;
    d->po_invoice_created_by = 0;
}

PoHeader::PoHeader(const PoHeader &other)
    : TAbstractModel(), d(new PoHeaderObject(*other.d))
{ }

PoHeader::PoHeader(const PoHeaderObject &object)
    : TAbstractModel(), d(new PoHeaderObject(object))
{ }

PoHeader::~PoHeader()
{
    // If the reference count becomes 0,
    // the shared data object 'PoHeaderObject' is deleted.
}

int PoHeader::poId() const
{
    return d->po_id;
}

QString PoHeader::poTypeCd() const
{
    return d->po_type_cd;
}

void PoHeader::setPoTypeCd(const QString &poTypeCd)
{
    d->po_type_cd = poTypeCd;
}

QString PoHeader::reqPriorityCd() const
{
    return d->req_priority_cd;
}

void PoHeader::setReqPriorityCd(const QString &reqPriorityCd)
{
    d->req_priority_cd = reqPriorityCd;
}

QString PoHeader::reqTypeCd() const
{
    return d->req_type_cd;
}

void PoHeader::setReqTypeCd(const QString &reqTypeCd)
{
    d->req_type_cd = reqTypeCd;
}

int PoHeader::vendorId() const
{
    return d->vendor_id;
}

void PoHeader::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int PoHeader::vendorAccountId() const
{
    return d->vendor_account_id;
}

void PoHeader::setVendorAccountId(int vendorAccountId)
{
    d->vendor_account_id = vendorAccountId;
}

int PoHeader::currencyId() const
{
    return d->currency_id;
}

void PoHeader::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

QString PoHeader::borrowRateCd() const
{
    return d->borrow_rate_cd;
}

void PoHeader::setBorrowRateCd(const QString &borrowRateCd)
{
    d->borrow_rate_cd = borrowRateCd;
}

QString PoHeader::paymentTermsCd() const
{
    return d->payment_terms_cd;
}

void PoHeader::setPaymentTermsCd(const QString &paymentTermsCd)
{
    d->payment_terms_cd = paymentTermsCd;
}

QString PoHeader::tradeTermCd() const
{
    return d->trade_term_cd;
}

void PoHeader::setTradeTermCd(const QString &tradeTermCd)
{
    d->trade_term_cd = tradeTermCd;
}

QString PoHeader::shippingPoint() const
{
    return d->shipping_point;
}

void PoHeader::setShippingPoint(const QString &shippingPoint)
{
    d->shipping_point = shippingPoint;
}

int PoHeader::finalLocId() const
{
    return d->final_loc_id;
}

void PoHeader::setFinalLocId(int finalLocId)
{
    d->final_loc_id = finalLocId;
}

int PoHeader::reExpediteToLocId() const
{
    return d->re_expedite_to_loc_id;
}

void PoHeader::setReExpediteToLocId(int reExpediteToLocId)
{
    d->re_expedite_to_loc_id = reExpediteToLocId;
}

int PoHeader::transportorId() const
{
    return d->transportor_id;
}

void PoHeader::setTransportorId(int transportorId)
{
    d->transportor_id = transportorId;
}

bool PoHeader::receiptInspBool() const
{
    return d->receipt_insp_bool;
}

void PoHeader::setReceiptInspBool(bool receiptInspBool)
{
    d->receipt_insp_bool = receiptInspBool;
}

QString PoHeader::noteToVendor() const
{
    return d->note_to_vendor;
}

void PoHeader::setNoteToVendor(const QString &noteToVendor)
{
    d->note_to_vendor = noteToVendor;
}

QString PoHeader::noteToReceiver() const
{
    return d->note_to_receiver;
}

void PoHeader::setNoteToReceiver(const QString &noteToReceiver)
{
    d->note_to_receiver = noteToReceiver;
}

bool PoHeader::authBool() const
{
    return d->auth_bool;
}

void PoHeader::setAuthBool(bool authBool)
{
    d->auth_bool = authBool;
}

int PoHeader::orgId() const
{
    return d->org_id;
}

void PoHeader::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int PoHeader::contactTo() const
{
    return d->contact_to;
}

void PoHeader::setContactTo(int contactTo)
{
    d->contact_to = contactTo;
}

int PoHeader::poCreatedBy() const
{
    return d->po_created_by;
}

void PoHeader::setPoCreatedBy(int poCreatedBy)
{
    d->po_created_by = poCreatedBy;
}

QDateTime PoHeader::poCreatedDt() const
{
    return d->po_created_dt;
}

void PoHeader::setPoCreatedDt(const QDateTime &poCreatedDt)
{
    d->po_created_dt = poCreatedDt;
}

int PoHeader::poIssuedBy() const
{
    return d->po_issued_by;
}

void PoHeader::setPoIssuedBy(int poIssuedBy)
{
    d->po_issued_by = poIssuedBy;
}

QDateTime PoHeader::poIssuedDt() const
{
    return d->po_issued_dt;
}

void PoHeader::setPoIssuedDt(const QDateTime &poIssuedDt)
{
    d->po_issued_dt = poIssuedDt;
}

int PoHeader::poClosedBy() const
{
    return d->po_closed_by;
}

void PoHeader::setPoClosedBy(int poClosedBy)
{
    d->po_closed_by = poClosedBy;
}

QDateTime PoHeader::poClosedDt() const
{
    return d->po_closed_dt;
}

void PoHeader::setPoClosedDt(const QDateTime &poClosedDt)
{
    d->po_closed_dt = poClosedDt;
}

int PoHeader::poInvoiceCreatedBy() const
{
    return d->po_invoice_created_by;
}

void PoHeader::setPoInvoiceCreatedBy(int poInvoiceCreatedBy)
{
    d->po_invoice_created_by = poInvoiceCreatedBy;
}

QDateTime PoHeader::poInvoiceCreatedDt() const
{
    return d->po_invoice_created_dt;
}

void PoHeader::setPoInvoiceCreatedDt(const QDateTime &poInvoiceCreatedDt)
{
    d->po_invoice_created_dt = poInvoiceCreatedDt;
}

QDateTime PoHeader::createdAt() const
{
    return d->created_at;
}

QString PoHeader::createdBy() const
{
    return d->created_by;
}

void PoHeader::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoHeader::updatedAt() const
{
    return d->updated_at;
}

QString PoHeader::updatedBy() const
{
    return d->updated_by;
}

void PoHeader::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPoType PoHeader::refPoTypeBypoTypeCd() const
{
 return RefPoType::get(d->po_type_cd);
}

RefReqPriority PoHeader::refReqPriorityByreqPriorityCd() const
{
 return RefReqPriority::get(d->req_priority_cd);
}

RefReqType PoHeader::refReqTypeByreqTypeCd() const
{
 return RefReqType::get(d->req_type_cd);
}

Vendor PoHeader::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

FncAccount PoHeader::fncAccountByvendorAccountId() const
{
 return FncAccount::get(d->vendor_account_id);
}

Currency PoHeader::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

RefBorrowRate PoHeader::refBorrowRateByborrowRateCd() const
{
 return RefBorrowRate::get(d->borrow_rate_cd);
}

RefPaymentTerms PoHeader::refPaymentTermsBypaymentTermsCd() const
{
 return RefPaymentTerms::get(d->payment_terms_cd);
}

RefTradeTerms PoHeader::refTradeTermsBytradeTermCd() const
{
 return RefTradeTerms::get(d->trade_term_cd);
}

Loc PoHeader::locByfinalLocId() const
{
 return Loc::get(d->final_loc_id);
}

Transportor PoHeader::transportorBytransportorId() const
{
 return Transportor::get(d->transportor_id);
}

Org PoHeader::orgByorgId() const
{
 return Org::get(d->org_id);
}

UserApp PoHeader::userAppBycontactTo() const
{
 return UserApp::get(d->contact_to);
}

PoHeader &PoHeader::operator=(const PoHeader &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoHeader PoHeader::create(const QString &poTypeCd, const QString &reqPriorityCd, const QString &reqTypeCd, int vendorId, int vendorAccountId, int currencyId, const QString &borrowRateCd, const QString &paymentTermsCd, const QString &tradeTermCd, const QString &shippingPoint, int finalLocId, int reExpediteToLocId, int transportorId, bool receiptInspBool, const QString &noteToVendor, const QString &noteToReceiver, bool authBool, int orgId, int contactTo, int poCreatedBy, const QDateTime &poCreatedDt, int poIssuedBy, const QDateTime &poIssuedDt, int poClosedBy, const QDateTime &poClosedDt, int poInvoiceCreatedBy, const QDateTime &poInvoiceCreatedDt, const QString &createdBy, const QString &updatedBy)
{
    PoHeaderObject obj;
    obj.po_type_cd = poTypeCd;
    obj.req_priority_cd = reqPriorityCd;
    obj.req_type_cd = reqTypeCd;
    obj.vendor_id = vendorId;
    obj.vendor_account_id = vendorAccountId;
    obj.currency_id = currencyId;
    obj.borrow_rate_cd = borrowRateCd;
    obj.payment_terms_cd = paymentTermsCd;
    obj.trade_term_cd = tradeTermCd;
    obj.shipping_point = shippingPoint;
    obj.final_loc_id = finalLocId;
    obj.re_expedite_to_loc_id = reExpediteToLocId;
    obj.transportor_id = transportorId;
    obj.receipt_insp_bool = receiptInspBool;
    obj.note_to_vendor = noteToVendor;
    obj.note_to_receiver = noteToReceiver;
    obj.auth_bool = authBool;
    obj.org_id = orgId;
    obj.contact_to = contactTo;
    obj.po_created_by = poCreatedBy;
    obj.po_created_dt = poCreatedDt;
    obj.po_issued_by = poIssuedBy;
    obj.po_issued_dt = poIssuedDt;
    obj.po_closed_by = poClosedBy;
    obj.po_closed_dt = poClosedDt;
    obj.po_invoice_created_by = poInvoiceCreatedBy;
    obj.po_invoice_created_dt = poInvoiceCreatedDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoHeader();
    }
    return PoHeader(obj);
}

PoHeader PoHeader::create(const QVariantMap &values)
{
    PoHeader model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoHeader PoHeader::get(int poId)
{
    TSqlORMapper<PoHeaderObject> mapper;
    return PoHeader(mapper.findByPrimaryKey(poId));
}

int PoHeader::count()
{
    TSqlORMapper<PoHeaderObject> mapper;
    return mapper.findCount();
}

QList<PoHeader> PoHeader::getAll()
{
    return tfGetModelListByCriteria<PoHeader, PoHeaderObject>();
}

TModelObject *PoHeader::modelData()
{
    return d.data();
}

const TModelObject *PoHeader::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoHeader &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoHeader &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoHeader)
