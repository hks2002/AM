#include <TreeFrogModel>
#include "rfqlinevendortax.h"
#include "rfqlinevendortaxobject.h"
#include "tax.h"
#include "rfqlinevendor.h"

RfqLineVendorTax::RfqLineVendorTax()
    : TAbstractModel(), d(new RfqLineVendorTaxObject())
{
    d->vendor_id = 0;
    d->rfq_id = 0;
    d->rfq_line_id = 0;
    d->tax_id = 0;
    d->tax_amount = 0;
}

RfqLineVendorTax::RfqLineVendorTax(const RfqLineVendorTax &other)
    : TAbstractModel(), d(new RfqLineVendorTaxObject(*other.d))
{ }

RfqLineVendorTax::RfqLineVendorTax(const RfqLineVendorTaxObject &object)
    : TAbstractModel(), d(new RfqLineVendorTaxObject(object))
{ }

RfqLineVendorTax::~RfqLineVendorTax()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqLineVendorTaxObject' is deleted.
}

int RfqLineVendorTax::vendorId() const
{
    return d->vendor_id;
}

void RfqLineVendorTax::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int RfqLineVendorTax::rfqId() const
{
    return d->rfq_id;
}

void RfqLineVendorTax::setRfqId(int rfqId)
{
    d->rfq_id = rfqId;
}

int RfqLineVendorTax::rfqLineId() const
{
    return d->rfq_line_id;
}

void RfqLineVendorTax::setRfqLineId(int rfqLineId)
{
    d->rfq_line_id = rfqLineId;
}

int RfqLineVendorTax::taxId() const
{
    return d->tax_id;
}

void RfqLineVendorTax::setTaxId(int taxId)
{
    d->tax_id = taxId;
}

double RfqLineVendorTax::taxAmount() const
{
    return d->tax_amount;
}

void RfqLineVendorTax::setTaxAmount(double taxAmount)
{
    d->tax_amount = taxAmount;
}

QDateTime RfqLineVendorTax::createdAt() const
{
    return d->created_at;
}

QString RfqLineVendorTax::createdBy() const
{
    return d->created_by;
}

void RfqLineVendorTax::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqLineVendorTax::updatedAt() const
{
    return d->updated_at;
}

QString RfqLineVendorTax::updatedBy() const
{
    return d->updated_by;
}

void RfqLineVendorTax::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Tax RfqLineVendorTax::taxBytaxId() const
{
 return Tax::get(d->tax_id);
}

RfqLineVendor RfqLineVendorTax::rfqLineVendorByvendorIdrfqIdrfqLineId() const
{
 return RfqLineVendor::get(d->vendor_id, d->rfq_id, d->rfq_line_id);
}

RfqLineVendorTax &RfqLineVendorTax::operator=(const RfqLineVendorTax &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqLineVendorTax RfqLineVendorTax::create(int vendorId, int rfqId, int rfqLineId, int taxId, double taxAmount, const QString &createdBy, const QString &updatedBy)
{
    RfqLineVendorTaxObject obj;
    obj.vendor_id = vendorId;
    obj.rfq_id = rfqId;
    obj.rfq_line_id = rfqLineId;
    obj.tax_id = taxId;
    obj.tax_amount = taxAmount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqLineVendorTax();
    }
    return RfqLineVendorTax(obj);
}

RfqLineVendorTax RfqLineVendorTax::create(const QVariantMap &values)
{
    RfqLineVendorTax model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqLineVendorTax RfqLineVendorTax::get(int vendorId, int rfqId, int rfqLineId)
{
    TSqlORMapper<RfqLineVendorTaxObject> mapper;
    return RfqLineVendorTax(mapper.findByPrimaryKey(QVariantList()<<QVariant(vendorId)<<QVariant(rfqId)<<QVariant(rfqLineId)));
}

int RfqLineVendorTax::count()
{
    TSqlORMapper<RfqLineVendorTaxObject> mapper;
    return mapper.findCount();
}

QList<RfqLineVendorTax> RfqLineVendorTax::getAll()
{
    return tfGetModelListByCriteria<RfqLineVendorTax, RfqLineVendorTaxObject>();
}

TModelObject *RfqLineVendorTax::modelData()
{
    return d.data();
}

const TModelObject *RfqLineVendorTax::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqLineVendorTax &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqLineVendorTax &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqLineVendorTax)
