#include <TreeFrogModel>
#include "rfqlinevendorcharge.h"
#include "rfqlinevendorchargeobject.h"
#include "charge.h"
#include "rfqlinevendor.h"

RfqLineVendorCharge::RfqLineVendorCharge()
    : TAbstractModel(), d(new RfqLineVendorChargeObject())
{
    d->vendor_id = 0;
    d->rfq_id = 0;
    d->rfq_line_id = 0;
    d->charge_id = 0;
    d->charge_amount = 0;
}

RfqLineVendorCharge::RfqLineVendorCharge(const RfqLineVendorCharge &other)
    : TAbstractModel(), d(new RfqLineVendorChargeObject(*other.d))
{ }

RfqLineVendorCharge::RfqLineVendorCharge(const RfqLineVendorChargeObject &object)
    : TAbstractModel(), d(new RfqLineVendorChargeObject(object))
{ }

RfqLineVendorCharge::~RfqLineVendorCharge()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqLineVendorChargeObject' is deleted.
}

int RfqLineVendorCharge::vendorId() const
{
    return d->vendor_id;
}

void RfqLineVendorCharge::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int RfqLineVendorCharge::rfqId() const
{
    return d->rfq_id;
}

void RfqLineVendorCharge::setRfqId(int rfqId)
{
    d->rfq_id = rfqId;
}

int RfqLineVendorCharge::rfqLineId() const
{
    return d->rfq_line_id;
}

void RfqLineVendorCharge::setRfqLineId(int rfqLineId)
{
    d->rfq_line_id = rfqLineId;
}

int RfqLineVendorCharge::chargeId() const
{
    return d->charge_id;
}

void RfqLineVendorCharge::setChargeId(int chargeId)
{
    d->charge_id = chargeId;
}

double RfqLineVendorCharge::chargeAmount() const
{
    return d->charge_amount;
}

void RfqLineVendorCharge::setChargeAmount(double chargeAmount)
{
    d->charge_amount = chargeAmount;
}

QDateTime RfqLineVendorCharge::createdAt() const
{
    return d->created_at;
}

QString RfqLineVendorCharge::createdBy() const
{
    return d->created_by;
}

void RfqLineVendorCharge::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqLineVendorCharge::updatedAt() const
{
    return d->updated_at;
}

QString RfqLineVendorCharge::updatedBy() const
{
    return d->updated_by;
}

void RfqLineVendorCharge::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Charge RfqLineVendorCharge::chargeBychargeId() const
{
 return Charge::get(d->charge_id);
}

RfqLineVendor RfqLineVendorCharge::rfqLineVendorByvendorIdrfqIdrfqLineId() const
{
 return RfqLineVendor::get(d->vendor_id, d->rfq_id, d->rfq_line_id);
}

RfqLineVendorCharge &RfqLineVendorCharge::operator=(const RfqLineVendorCharge &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqLineVendorCharge RfqLineVendorCharge::create(int vendorId, int rfqId, int rfqLineId, int chargeId, double chargeAmount, const QString &createdBy, const QString &updatedBy)
{
    RfqLineVendorChargeObject obj;
    obj.vendor_id = vendorId;
    obj.rfq_id = rfqId;
    obj.rfq_line_id = rfqLineId;
    obj.charge_id = chargeId;
    obj.charge_amount = chargeAmount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqLineVendorCharge();
    }
    return RfqLineVendorCharge(obj);
}

RfqLineVendorCharge RfqLineVendorCharge::create(const QVariantMap &values)
{
    RfqLineVendorCharge model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqLineVendorCharge RfqLineVendorCharge::get(int vendorId, int rfqId, int rfqLineId)
{
    TSqlORMapper<RfqLineVendorChargeObject> mapper;
    return RfqLineVendorCharge(mapper.findByPrimaryKey(QVariantList()<<QVariant(vendorId)<<QVariant(rfqId)<<QVariant(rfqLineId)));
}

int RfqLineVendorCharge::count()
{
    TSqlORMapper<RfqLineVendorChargeObject> mapper;
    return mapper.findCount();
}

QList<RfqLineVendorCharge> RfqLineVendorCharge::getAll()
{
    return tfGetModelListByCriteria<RfqLineVendorCharge, RfqLineVendorChargeObject>();
}

TModelObject *RfqLineVendorCharge::modelData()
{
    return d.data();
}

const TModelObject *RfqLineVendorCharge::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqLineVendorCharge &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqLineVendorCharge &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqLineVendorCharge)
