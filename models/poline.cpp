#include <TreeFrogModel>
#include "poline.h"
#include "polineobject.h"
#include "shipshipment.h"
#include "schedstask.h"
#include "ownerapp.h"
#include "refpricetype.h"
#include "qtyunit.h"
#include "refpolinetype.h"
#include "eqppartno.h"
#include "poheader.h"

PoLine::PoLine()
    : TAbstractModel(), d(new PoLineObject())
{
    d->po_line_id = 0;
    d->po_id = 0;
    d->line_no_ord = 0;
    d->part_no_id = 0;
    d->order_qt = 0;
    d->qty_unit_id = 0;
    d->base_unit_price = 0;
    d->unit_price = 0;
    d->orig_unit_price = 0;
    d->line_price = 0;
    d->accrued_value = 0;
    d->received_qt = 0;
    d->invoice_qt = 0;
    d->pre_insp_qt = 0;
    d->owner_id = 0;
    d->sched_id = 0;
    d->shipment_id = 0;
}

PoLine::PoLine(const PoLine &other)
    : TAbstractModel(), d(new PoLineObject(*other.d))
{ }

PoLine::PoLine(const PoLineObject &object)
    : TAbstractModel(), d(new PoLineObject(object))
{ }

PoLine::~PoLine()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineObject' is deleted.
}

int PoLine::poLineId() const
{
    return d->po_line_id;
}

int PoLine::poId() const
{
    return d->po_id;
}

void PoLine::setPoId(int poId)
{
    d->po_id = poId;
}

int PoLine::lineNoOrd() const
{
    return d->line_no_ord;
}

void PoLine::setLineNoOrd(int lineNoOrd)
{
    d->line_no_ord = lineNoOrd;
}

QString PoLine::lineDesc() const
{
    return d->line_desc;
}

void PoLine::setLineDesc(const QString &lineDesc)
{
    d->line_desc = lineDesc;
}

int PoLine::partNoId() const
{
    return d->part_no_id;
}

void PoLine::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString PoLine::poLineTypeCd() const
{
    return d->po_line_type_cd;
}

void PoLine::setPoLineTypeCd(const QString &poLineTypeCd)
{
    d->po_line_type_cd = poLineTypeCd;
}

int PoLine::orderQt() const
{
    return d->order_qt;
}

void PoLine::setOrderQt(int orderQt)
{
    d->order_qt = orderQt;
}

int PoLine::qtyUnitId() const
{
    return d->qty_unit_id;
}

void PoLine::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

QString PoLine::priceTypeCd() const
{
    return d->price_type_cd;
}

void PoLine::setPriceTypeCd(const QString &priceTypeCd)
{
    d->price_type_cd = priceTypeCd;
}

double PoLine::baseUnitPrice() const
{
    return d->base_unit_price;
}

void PoLine::setBaseUnitPrice(double baseUnitPrice)
{
    d->base_unit_price = baseUnitPrice;
}

double PoLine::unitPrice() const
{
    return d->unit_price;
}

void PoLine::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

double PoLine::origUnitPrice() const
{
    return d->orig_unit_price;
}

void PoLine::setOrigUnitPrice(double origUnitPrice)
{
    d->orig_unit_price = origUnitPrice;
}

double PoLine::linePrice() const
{
    return d->line_price;
}

void PoLine::setLinePrice(double linePrice)
{
    d->line_price = linePrice;
}

double PoLine::accruedValue() const
{
    return d->accrued_value;
}

void PoLine::setAccruedValue(double accruedValue)
{
    d->accrued_value = accruedValue;
}

QDateTime PoLine::promiseDt() const
{
    return d->promise_dt;
}

void PoLine::setPromiseDt(const QDateTime &promiseDt)
{
    d->promise_dt = promiseDt;
}

bool PoLine::confirmPromiseByBool() const
{
    return d->confirm_promise_by_bool;
}

void PoLine::setConfirmPromiseByBool(bool confirmPromiseByBool)
{
    d->confirm_promise_by_bool = confirmPromiseByBool;
}

int PoLine::receivedQt() const
{
    return d->received_qt;
}

void PoLine::setReceivedQt(int receivedQt)
{
    d->received_qt = receivedQt;
}

int PoLine::invoiceQt() const
{
    return d->invoice_qt;
}

void PoLine::setInvoiceQt(int invoiceQt)
{
    d->invoice_qt = invoiceQt;
}

int PoLine::preInspQt() const
{
    return d->pre_insp_qt;
}

void PoLine::setPreInspQt(int preInspQt)
{
    d->pre_insp_qt = preInspQt;
}

QDateTime PoLine::origPromiseDt() const
{
    return d->orig_promise_dt;
}

void PoLine::setOrigPromiseDt(const QDateTime &origPromiseDt)
{
    d->orig_promise_dt = origPromiseDt;
}

bool PoLine::maintPickupBool() const
{
    return d->maint_pickup_bool;
}

void PoLine::setMaintPickupBool(bool maintPickupBool)
{
    d->maint_pickup_bool = maintPickupBool;
}

QDateTime PoLine::receivedDt() const
{
    return d->received_dt;
}

void PoLine::setReceivedDt(const QDateTime &receivedDt)
{
    d->received_dt = receivedDt;
}

QDateTime PoLine::returnDt() const
{
    return d->return_dt;
}

void PoLine::setReturnDt(const QDateTime &returnDt)
{
    d->return_dt = returnDt;
}

QString PoLine::noteToVendor() const
{
    return d->note_to_vendor;
}

void PoLine::setNoteToVendor(const QString &noteToVendor)
{
    d->note_to_vendor = noteToVendor;
}

QString PoLine::noteToReceiver() const
{
    return d->note_to_receiver;
}

void PoLine::setNoteToReceiver(const QString &noteToReceiver)
{
    d->note_to_receiver = noteToReceiver;
}

bool PoLine::warrantyBool() const
{
    return d->warranty_bool;
}

void PoLine::setWarrantyBool(bool warrantyBool)
{
    d->warranty_bool = warrantyBool;
}

bool PoLine::lineDeletedBool() const
{
    return d->line_deleted_bool;
}

void PoLine::setLineDeletedBool(bool lineDeletedBool)
{
    d->line_deleted_bool = lineDeletedBool;
}

int PoLine::ownerId() const
{
    return d->owner_id;
}

void PoLine::setOwnerId(int ownerId)
{
    d->owner_id = ownerId;
}

int PoLine::schedId() const
{
    return d->sched_id;
}

void PoLine::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int PoLine::shipmentId() const
{
    return d->shipment_id;
}

void PoLine::setShipmentId(int shipmentId)
{
    d->shipment_id = shipmentId;
}

QDateTime PoLine::createdAt() const
{
    return d->created_at;
}

QString PoLine::createdBy() const
{
    return d->created_by;
}

void PoLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLine::updatedAt() const
{
    return d->updated_at;
}

QString PoLine::updatedBy() const
{
    return d->updated_by;
}

void PoLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

ShipShipment PoLine::shipShipmentByshipmentId() const
{
 return ShipShipment::get(d->shipment_id);
}

SchedStask PoLine::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

OwnerApp PoLine::ownerAppByownerId() const
{
 return OwnerApp::get(d->owner_id);
}

RefPriceType PoLine::refPriceTypeBypriceTypeCd() const
{
 return RefPriceType::get(d->price_type_cd);
}

QtyUnit PoLine::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

RefPoLineType PoLine::refPoLineTypeBypoLineTypeCd() const
{
 return RefPoLineType::get(d->po_line_type_cd);
}

EqpPartNo PoLine::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

PoHeader PoLine::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

PoLine &PoLine::operator=(const PoLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLine PoLine::create(int poId, int lineNoOrd, const QString &lineDesc, int partNoId, const QString &poLineTypeCd, int orderQt, int qtyUnitId, const QString &priceTypeCd, double baseUnitPrice, double unitPrice, double origUnitPrice, double linePrice, double accruedValue, const QDateTime &promiseDt, bool confirmPromiseByBool, int receivedQt, int invoiceQt, int preInspQt, const QDateTime &origPromiseDt, bool maintPickupBool, const QDateTime &receivedDt, const QDateTime &returnDt, const QString &noteToVendor, const QString &noteToReceiver, bool warrantyBool, bool lineDeletedBool, int ownerId, int schedId, int shipmentId, const QString &createdBy, const QString &updatedBy)
{
    PoLineObject obj;
    obj.po_id = poId;
    obj.line_no_ord = lineNoOrd;
    obj.line_desc = lineDesc;
    obj.part_no_id = partNoId;
    obj.po_line_type_cd = poLineTypeCd;
    obj.order_qt = orderQt;
    obj.qty_unit_id = qtyUnitId;
    obj.price_type_cd = priceTypeCd;
    obj.base_unit_price = baseUnitPrice;
    obj.unit_price = unitPrice;
    obj.orig_unit_price = origUnitPrice;
    obj.line_price = linePrice;
    obj.accrued_value = accruedValue;
    obj.promise_dt = promiseDt;
    obj.confirm_promise_by_bool = confirmPromiseByBool;
    obj.received_qt = receivedQt;
    obj.invoice_qt = invoiceQt;
    obj.pre_insp_qt = preInspQt;
    obj.orig_promise_dt = origPromiseDt;
    obj.maint_pickup_bool = maintPickupBool;
    obj.received_dt = receivedDt;
    obj.return_dt = returnDt;
    obj.note_to_vendor = noteToVendor;
    obj.note_to_receiver = noteToReceiver;
    obj.warranty_bool = warrantyBool;
    obj.line_deleted_bool = lineDeletedBool;
    obj.owner_id = ownerId;
    obj.sched_id = schedId;
    obj.shipment_id = shipmentId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLine();
    }
    return PoLine(obj);
}

PoLine PoLine::create(const QVariantMap &values)
{
    PoLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLine PoLine::get(int poLineId)
{
    TSqlORMapper<PoLineObject> mapper;
    return PoLine(mapper.findByPrimaryKey(poLineId));
}

int PoLine::count()
{
    TSqlORMapper<PoLineObject> mapper;
    return mapper.findCount();
}

QList<PoLine> PoLine::getAll()
{
    return tfGetModelListByCriteria<PoLine, PoLineObject>();
}

TModelObject *PoLine::modelData()
{
    return d.data();
}

const TModelObject *PoLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLine)
