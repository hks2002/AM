#include <TreeFrogModel>
#include "eqppartnovendorprice.h"
#include "eqppartnovendorpriceobject.h"
#include "qtyunit.h"
#include "refpricetype.h"
#include "eqppartno.h"
#include "vendor.h"

EqpPartNoVendorPrice::EqpPartNoVendorPrice()
    : TAbstractModel(), d(new EqpPartNoVendorPriceObject())
{
    d->part_no_vendor_price_id = 0;
    d->vendor_id = 0;
    d->part_no_id = 0;
    d->unit_price = 0;
    d->min_order_qt = 0;
    d->discount_pct = 0;
    d->std_sale_qt = 0;
    d->qty_unit_id = 0;
}

EqpPartNoVendorPrice::EqpPartNoVendorPrice(const EqpPartNoVendorPrice &other)
    : TAbstractModel(), d(new EqpPartNoVendorPriceObject(*other.d))
{ }

EqpPartNoVendorPrice::EqpPartNoVendorPrice(const EqpPartNoVendorPriceObject &object)
    : TAbstractModel(), d(new EqpPartNoVendorPriceObject(object))
{ }

EqpPartNoVendorPrice::~EqpPartNoVendorPrice()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoVendorPriceObject' is deleted.
}

int EqpPartNoVendorPrice::partNoVendorPriceId() const
{
    return d->part_no_vendor_price_id;
}

int EqpPartNoVendorPrice::vendorId() const
{
    return d->vendor_id;
}

void EqpPartNoVendorPrice::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int EqpPartNoVendorPrice::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoVendorPrice::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString EqpPartNoVendorPrice::priceTypeCd() const
{
    return d->price_type_cd;
}

void EqpPartNoVendorPrice::setPriceTypeCd(const QString &priceTypeCd)
{
    d->price_type_cd = priceTypeCd;
}

double EqpPartNoVendorPrice::unitPrice() const
{
    return d->unit_price;
}

void EqpPartNoVendorPrice::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

int EqpPartNoVendorPrice::minOrderQt() const
{
    return d->min_order_qt;
}

void EqpPartNoVendorPrice::setMinOrderQt(int minOrderQt)
{
    d->min_order_qt = minOrderQt;
}

double EqpPartNoVendorPrice::discountPct() const
{
    return d->discount_pct;
}

void EqpPartNoVendorPrice::setDiscountPct(double discountPct)
{
    d->discount_pct = discountPct;
}

int EqpPartNoVendorPrice::stdSaleQt() const
{
    return d->std_sale_qt;
}

void EqpPartNoVendorPrice::setStdSaleQt(int stdSaleQt)
{
    d->std_sale_qt = stdSaleQt;
}

int EqpPartNoVendorPrice::qtyUnitId() const
{
    return d->qty_unit_id;
}

void EqpPartNoVendorPrice::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

QString EqpPartNoVendorPrice::leadTime() const
{
    return d->lead_time;
}

void EqpPartNoVendorPrice::setLeadTime(const QString &leadTime)
{
    d->lead_time = leadTime;
}

QDateTime EqpPartNoVendorPrice::quoteDt() const
{
    return d->quote_dt;
}

void EqpPartNoVendorPrice::setQuoteDt(const QDateTime &quoteDt)
{
    d->quote_dt = quoteDt;
}

QDateTime EqpPartNoVendorPrice::effectiveFromDt() const
{
    return d->effective_from_dt;
}

void EqpPartNoVendorPrice::setEffectiveFromDt(const QDateTime &effectiveFromDt)
{
    d->effective_from_dt = effectiveFromDt;
}

QDateTime EqpPartNoVendorPrice::effectiveToDt() const
{
    return d->effective_to_dt;
}

void EqpPartNoVendorPrice::setEffectiveToDt(const QDateTime &effectiveToDt)
{
    d->effective_to_dt = effectiveToDt;
}

QString EqpPartNoVendorPrice::vendorNote() const
{
    return d->vendor_note;
}

void EqpPartNoVendorPrice::setVendorNote(const QString &vendorNote)
{
    d->vendor_note = vendorNote;
}

QString EqpPartNoVendorPrice::docRefDesc() const
{
    return d->doc_ref_desc;
}

void EqpPartNoVendorPrice::setDocRefDesc(const QString &docRefDesc)
{
    d->doc_ref_desc = docRefDesc;
}

bool EqpPartNoVendorPrice::histBool() const
{
    return d->hist_bool;
}

void EqpPartNoVendorPrice::setHistBool(bool histBool)
{
    d->hist_bool = histBool;
}

QDateTime EqpPartNoVendorPrice::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoVendorPrice::createdBy() const
{
    return d->created_by;
}

void EqpPartNoVendorPrice::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoVendorPrice::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoVendorPrice::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoVendorPrice::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

QtyUnit EqpPartNoVendorPrice::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

RefPriceType EqpPartNoVendorPrice::refPriceTypeBypriceTypeCd() const
{
 return RefPriceType::get(d->price_type_cd);
}

EqpPartNo EqpPartNoVendorPrice::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Vendor EqpPartNoVendorPrice::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

EqpPartNoVendorPrice &EqpPartNoVendorPrice::operator=(const EqpPartNoVendorPrice &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoVendorPrice EqpPartNoVendorPrice::create(int vendorId, int partNoId, const QString &priceTypeCd, double unitPrice, int minOrderQt, double discountPct, int stdSaleQt, int qtyUnitId, const QString &leadTime, const QDateTime &quoteDt, const QDateTime &effectiveFromDt, const QDateTime &effectiveToDt, const QString &vendorNote, const QString &docRefDesc, bool histBool, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoVendorPriceObject obj;
    obj.vendor_id = vendorId;
    obj.part_no_id = partNoId;
    obj.price_type_cd = priceTypeCd;
    obj.unit_price = unitPrice;
    obj.min_order_qt = minOrderQt;
    obj.discount_pct = discountPct;
    obj.std_sale_qt = stdSaleQt;
    obj.qty_unit_id = qtyUnitId;
    obj.lead_time = leadTime;
    obj.quote_dt = quoteDt;
    obj.effective_from_dt = effectiveFromDt;
    obj.effective_to_dt = effectiveToDt;
    obj.vendor_note = vendorNote;
    obj.doc_ref_desc = docRefDesc;
    obj.hist_bool = histBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoVendorPrice();
    }
    return EqpPartNoVendorPrice(obj);
}

EqpPartNoVendorPrice EqpPartNoVendorPrice::create(const QVariantMap &values)
{
    EqpPartNoVendorPrice model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoVendorPrice EqpPartNoVendorPrice::get(int partNoVendorPriceId)
{
    TSqlORMapper<EqpPartNoVendorPriceObject> mapper;
    return EqpPartNoVendorPrice(mapper.findByPrimaryKey(partNoVendorPriceId));
}

int EqpPartNoVendorPrice::count()
{
    TSqlORMapper<EqpPartNoVendorPriceObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoVendorPrice> EqpPartNoVendorPrice::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoVendorPrice, EqpPartNoVendorPriceObject>();
}

TModelObject *EqpPartNoVendorPrice::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoVendorPrice::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorPrice &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorPrice &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoVendorPrice)
