#include <TreeFrogModel>
#include "rfqvendor.h"
#include "rfqvendorobject.h"
#include "reftradeterms.h"
#include "refpaymentterms.h"
#include "transportor.h"
#include "currency.h"
#include "vendor.h"
#include "rfqheader.h"

RfqVendor::RfqVendor()
    : TAbstractModel(), d(new RfqVendorObject())
{
    d->rfq_id = 0;
    d->vendor_id = 0;
    d->currency_id = 0;
    d->exchg_qt = 0;
    d->transportor_id = 0;
}

RfqVendor::RfqVendor(const RfqVendor &other)
    : TAbstractModel(), d(new RfqVendorObject(*other.d))
{ }

RfqVendor::RfqVendor(const RfqVendorObject &object)
    : TAbstractModel(), d(new RfqVendorObject(object))
{ }

RfqVendor::~RfqVendor()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqVendorObject' is deleted.
}

int RfqVendor::rfqId() const
{
    return d->rfq_id;
}

void RfqVendor::setRfqId(int rfqId)
{
    d->rfq_id = rfqId;
}

int RfqVendor::vendorId() const
{
    return d->vendor_id;
}

void RfqVendor::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int RfqVendor::currencyId() const
{
    return d->currency_id;
}

void RfqVendor::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

double RfqVendor::exchgQt() const
{
    return d->exchg_qt;
}

void RfqVendor::setExchgQt(double exchgQt)
{
    d->exchg_qt = exchgQt;
}

int RfqVendor::transportorId() const
{
    return d->transportor_id;
}

void RfqVendor::setTransportorId(int transportorId)
{
    d->transportor_id = transportorId;
}

QString RfqVendor::paymentTermsCd() const
{
    return d->payment_terms_cd;
}

void RfqVendor::setPaymentTermsCd(const QString &paymentTermsCd)
{
    d->payment_terms_cd = paymentTermsCd;
}

QString RfqVendor::tradeTermCd() const
{
    return d->trade_term_cd;
}

void RfqVendor::setTradeTermCd(const QString &tradeTermCd)
{
    d->trade_term_cd = tradeTermCd;
}

QString RfqVendor::vendorNote() const
{
    return d->vendor_note;
}

void RfqVendor::setVendorNote(const QString &vendorNote)
{
    d->vendor_note = vendorNote;
}

QDateTime RfqVendor::createdAt() const
{
    return d->created_at;
}

QString RfqVendor::createdBy() const
{
    return d->created_by;
}

void RfqVendor::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqVendor::updatedAt() const
{
    return d->updated_at;
}

QString RfqVendor::updatedBy() const
{
    return d->updated_by;
}

void RfqVendor::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefTradeTerms RfqVendor::refTradeTermsBytradeTermCd() const
{
 return RefTradeTerms::get(d->trade_term_cd);
}

RefPaymentTerms RfqVendor::refPaymentTermsBypaymentTermsCd() const
{
 return RefPaymentTerms::get(d->payment_terms_cd);
}

Transportor RfqVendor::transportorBytransportorId() const
{
 return Transportor::get(d->transportor_id);
}

Currency RfqVendor::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

Vendor RfqVendor::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

RfqHeader RfqVendor::rfqHeaderByrfqId() const
{
 return RfqHeader::get(d->rfq_id);
}

RfqVendor &RfqVendor::operator=(const RfqVendor &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqVendor RfqVendor::create(int rfqId, int vendorId, int currencyId, double exchgQt, int transportorId, const QString &paymentTermsCd, const QString &tradeTermCd, const QString &vendorNote, const QString &createdBy, const QString &updatedBy)
{
    RfqVendorObject obj;
    obj.rfq_id = rfqId;
    obj.vendor_id = vendorId;
    obj.currency_id = currencyId;
    obj.exchg_qt = exchgQt;
    obj.transportor_id = transportorId;
    obj.payment_terms_cd = paymentTermsCd;
    obj.trade_term_cd = tradeTermCd;
    obj.vendor_note = vendorNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqVendor();
    }
    return RfqVendor(obj);
}

RfqVendor RfqVendor::create(const QVariantMap &values)
{
    RfqVendor model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqVendor RfqVendor::get(int rfqId, int vendorId)
{
    TSqlORMapper<RfqVendorObject> mapper;
    return RfqVendor(mapper.findByPrimaryKey(QVariantList()<<QVariant(rfqId)<<QVariant(vendorId)));
}

int RfqVendor::count()
{
    TSqlORMapper<RfqVendorObject> mapper;
    return mapper.findCount();
}

QList<RfqVendor> RfqVendor::getAll()
{
    return tfGetModelListByCriteria<RfqVendor, RfqVendorObject>();
}

TModelObject *RfqVendor::modelData()
{
    return d.data();
}

const TModelObject *RfqVendor::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqVendor &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqVendor &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqVendor)
