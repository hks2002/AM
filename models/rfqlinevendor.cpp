#include <TreeFrogModel>
#include "rfqlinevendor.h"
#include "rfqlinevendorobject.h"
#include "qtyunit.h"
#include "refreceivecond.h"
#include "eqppartno.h"
#include "rfqline.h"
#include "rfqvendor.h"

RfqLineVendor::RfqLineVendor()
    : TAbstractModel(), d(new RfqLineVendorObject())
{
    d->rfq_id = 0;
    d->rfq_line_id = 0;
    d->vendor_id = 0;
    d->part_no_id = 0;
    d->quote_qt = 0;
    d->unit_price = 0;
    d->qty_unit_id = 0;
    d->line_price = 0;
}

RfqLineVendor::RfqLineVendor(const RfqLineVendor &other)
    : TAbstractModel(), d(new RfqLineVendorObject(*other.d))
{ }

RfqLineVendor::RfqLineVendor(const RfqLineVendorObject &object)
    : TAbstractModel(), d(new RfqLineVendorObject(object))
{ }

RfqLineVendor::~RfqLineVendor()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqLineVendorObject' is deleted.
}

int RfqLineVendor::rfqId() const
{
    return d->rfq_id;
}

void RfqLineVendor::setRfqId(int rfqId)
{
    d->rfq_id = rfqId;
}

int RfqLineVendor::rfqLineId() const
{
    return d->rfq_line_id;
}

void RfqLineVendor::setRfqLineId(int rfqLineId)
{
    d->rfq_line_id = rfqLineId;
}

int RfqLineVendor::vendorId() const
{
    return d->vendor_id;
}

void RfqLineVendor::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

bool RfqLineVendor::noQuoteBool() const
{
    return d->no_quote_bool;
}

void RfqLineVendor::setNoQuoteBool(bool noQuoteBool)
{
    d->no_quote_bool = noQuoteBool;
}

bool RfqLineVendor::noSupplyBool() const
{
    return d->no_supply_bool;
}

void RfqLineVendor::setNoSupplyBool(bool noSupplyBool)
{
    d->no_supply_bool = noSupplyBool;
}

int RfqLineVendor::partNoId() const
{
    return d->part_no_id;
}

void RfqLineVendor::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString RfqLineVendor::receiveCondCd() const
{
    return d->receive_cond_cd;
}

void RfqLineVendor::setReceiveCondCd(const QString &receiveCondCd)
{
    d->receive_cond_cd = receiveCondCd;
}

int RfqLineVendor::quoteQt() const
{
    return d->quote_qt;
}

void RfqLineVendor::setQuoteQt(int quoteQt)
{
    d->quote_qt = quoteQt;
}

QDateTime RfqLineVendor::quoteDt() const
{
    return d->quote_dt;
}

void RfqLineVendor::setQuoteDt(const QDateTime &quoteDt)
{
    d->quote_dt = quoteDt;
}

double RfqLineVendor::unitPrice() const
{
    return d->unit_price;
}

void RfqLineVendor::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

int RfqLineVendor::qtyUnitId() const
{
    return d->qty_unit_id;
}

void RfqLineVendor::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

double RfqLineVendor::linePrice() const
{
    return d->line_price;
}

void RfqLineVendor::setLinePrice(double linePrice)
{
    d->line_price = linePrice;
}

QString RfqLineVendor::leadTime() const
{
    return d->lead_time;
}

void RfqLineVendor::setLeadTime(const QString &leadTime)
{
    d->lead_time = leadTime;
}

QDateTime RfqLineVendor::effectiveToDt() const
{
    return d->effective_to_dt;
}

void RfqLineVendor::setEffectiveToDt(const QDateTime &effectiveToDt)
{
    d->effective_to_dt = effectiveToDt;
}

bool RfqLineVendor::respondedBool() const
{
    return d->responded_bool;
}

void RfqLineVendor::setRespondedBool(bool respondedBool)
{
    d->responded_bool = respondedBool;
}

QString RfqLineVendor::noteToVendor() const
{
    return d->note_to_vendor;
}

void RfqLineVendor::setNoteToVendor(const QString &noteToVendor)
{
    d->note_to_vendor = noteToVendor;
}

QString RfqLineVendor::docRefDesc() const
{
    return d->doc_ref_desc;
}

void RfqLineVendor::setDocRefDesc(const QString &docRefDesc)
{
    d->doc_ref_desc = docRefDesc;
}

QDateTime RfqLineVendor::respondDt() const
{
    return d->respond_dt;
}

void RfqLineVendor::setRespondDt(const QDateTime &respondDt)
{
    d->respond_dt = respondDt;
}

QDateTime RfqLineVendor::createdAt() const
{
    return d->created_at;
}

QString RfqLineVendor::createdBy() const
{
    return d->created_by;
}

void RfqLineVendor::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqLineVendor::updatedAt() const
{
    return d->updated_at;
}

QString RfqLineVendor::updatedBy() const
{
    return d->updated_by;
}

void RfqLineVendor::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

QtyUnit RfqLineVendor::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

RefReceiveCond RfqLineVendor::refReceiveCondByreceiveCondCd() const
{
 return RefReceiveCond::get(d->receive_cond_cd);
}

EqpPartNo RfqLineVendor::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

RfqLine RfqLineVendor::rfqLineByrfqLineId() const
{
 return RfqLine::get(d->rfq_line_id);
}

RfqVendor RfqLineVendor::rfqVendorByrfqIdvendorId() const
{
 return RfqVendor::get(d->rfq_id, d->vendor_id);
}

RfqLineVendor &RfqLineVendor::operator=(const RfqLineVendor &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqLineVendor RfqLineVendor::create(int rfqId, int rfqLineId, int vendorId, bool noQuoteBool, bool noSupplyBool, int partNoId, const QString &receiveCondCd, int quoteQt, const QDateTime &quoteDt, double unitPrice, int qtyUnitId, double linePrice, const QString &leadTime, const QDateTime &effectiveToDt, bool respondedBool, const QString &noteToVendor, const QString &docRefDesc, const QDateTime &respondDt, const QString &createdBy, const QString &updatedBy)
{
    RfqLineVendorObject obj;
    obj.rfq_id = rfqId;
    obj.rfq_line_id = rfqLineId;
    obj.vendor_id = vendorId;
    obj.no_quote_bool = noQuoteBool;
    obj.no_supply_bool = noSupplyBool;
    obj.part_no_id = partNoId;
    obj.receive_cond_cd = receiveCondCd;
    obj.quote_qt = quoteQt;
    obj.quote_dt = quoteDt;
    obj.unit_price = unitPrice;
    obj.qty_unit_id = qtyUnitId;
    obj.line_price = linePrice;
    obj.lead_time = leadTime;
    obj.effective_to_dt = effectiveToDt;
    obj.responded_bool = respondedBool;
    obj.note_to_vendor = noteToVendor;
    obj.doc_ref_desc = docRefDesc;
    obj.respond_dt = respondDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqLineVendor();
    }
    return RfqLineVendor(obj);
}

RfqLineVendor RfqLineVendor::create(const QVariantMap &values)
{
    RfqLineVendor model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqLineVendor RfqLineVendor::get(int rfqId, int rfqLineId, int vendorId)
{
    TSqlORMapper<RfqLineVendorObject> mapper;
    return RfqLineVendor(mapper.findByPrimaryKey(QVariantList()<<QVariant(rfqId)<<QVariant(rfqLineId)<<QVariant(vendorId)));
}

int RfqLineVendor::count()
{
    TSqlORMapper<RfqLineVendorObject> mapper;
    return mapper.findCount();
}

QList<RfqLineVendor> RfqLineVendor::getAll()
{
    return tfGetModelListByCriteria<RfqLineVendor, RfqLineVendorObject>();
}

TModelObject *RfqLineVendor::modelData()
{
    return d.data();
}

const TModelObject *RfqLineVendor::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqLineVendor &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqLineVendor &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqLineVendor)
