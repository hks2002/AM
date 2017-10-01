#include <TreeFrogModel>
#include "shipshipment.h"
#include "shipshipmentobject.h"
#include "fncaccount.h"
#include "schedstask.h"
#include "poheader.h"
#include "mesurunit.h"
#include "org.h"
#include "transportor.h"
#include "refshipmenttype.h"

ShipShipment::ShipShipment()
    : TAbstractModel(), d(new ShipShipmentObject())
{
    d->shipment_id = 0;
    d->transportor_id = 0;
    d->org_id = 0;
    d->return_price = 0;
    d->weight_qt = 0;
    d->weight_unit_id = 0;
    d->height_qt = 0;
    d->height_unit_id = 0;
    d->length_qt = 0;
    d->length_unit_id = 0;
    d->width_qt = 0;
    d->width_unit_id = 0;
    d->po_id = 0;
    d->sched_id = 0;
    d->account_id = 0;
}

ShipShipment::ShipShipment(const ShipShipment &other)
    : TAbstractModel(), d(new ShipShipmentObject(*other.d))
{ }

ShipShipment::ShipShipment(const ShipShipmentObject &object)
    : TAbstractModel(), d(new ShipShipmentObject(object))
{ }

ShipShipment::~ShipShipment()
{
    // If the reference count becomes 0,
    // the shared data object 'ShipShipmentObject' is deleted.
}

int ShipShipment::shipmentId() const
{
    return d->shipment_id;
}

QString ShipShipment::shipmentTypeCd() const
{
    return d->shipment_type_cd;
}

void ShipShipment::setShipmentTypeCd(const QString &shipmentTypeCd)
{
    d->shipment_type_cd = shipmentTypeCd;
}

int ShipShipment::transportorId() const
{
    return d->transportor_id;
}

void ShipShipment::setTransportorId(int transportorId)
{
    d->transportor_id = transportorId;
}

int ShipShipment::orgId() const
{
    return d->org_id;
}

void ShipShipment::setOrgId(int orgId)
{
    d->org_id = orgId;
}

QString ShipShipment::waybillNo() const
{
    return d->waybill_no;
}

void ShipShipment::setWaybillNo(const QString &waybillNo)
{
    d->waybill_no = waybillNo;
}

QString ShipShipment::flightNo() const
{
    return d->flight_no;
}

void ShipShipment::setFlightNo(const QString &flightNo)
{
    d->flight_no = flightNo;
}

QString ShipShipment::customsDeclaration() const
{
    return d->customs_declaration;
}

void ShipShipment::setCustomsDeclaration(const QString &customsDeclaration)
{
    d->customs_declaration = customsDeclaration;
}

QString ShipShipment::customsDesc() const
{
    return d->customs_desc;
}

void ShipShipment::setCustomsDesc(const QString &customsDesc)
{
    d->customs_desc = customsDesc;
}

bool ShipShipment::confirmReceiptBool() const
{
    return d->confirm_receipt_bool;
}

void ShipShipment::setConfirmReceiptBool(bool confirmReceiptBool)
{
    d->confirm_receipt_bool = confirmReceiptBool;
}

QDateTime ShipShipment::shipAfterDt() const
{
    return d->ship_after_dt;
}

void ShipShipment::setShipAfterDt(const QDateTime &shipAfterDt)
{
    d->ship_after_dt = shipAfterDt;
}

QDateTime ShipShipment::shipDt() const
{
    return d->ship_dt;
}

void ShipShipment::setShipDt(const QDateTime &shipDt)
{
    d->ship_dt = shipDt;
}

QString ShipShipment::returnAuthNo() const
{
    return d->return_auth_no;
}

void ShipShipment::setReturnAuthNo(const QString &returnAuthNo)
{
    d->return_auth_no = returnAuthNo;
}

double ShipShipment::returnPrice() const
{
    return d->return_price;
}

void ShipShipment::setReturnPrice(double returnPrice)
{
    d->return_price = returnPrice;
}

QString ShipShipment::returnDesc() const
{
    return d->return_desc;
}

void ShipShipment::setReturnDesc(const QString &returnDesc)
{
    d->return_desc = returnDesc;
}

double ShipShipment::weightQt() const
{
    return d->weight_qt;
}

void ShipShipment::setWeightQt(double weightQt)
{
    d->weight_qt = weightQt;
}

int ShipShipment::weightUnitId() const
{
    return d->weight_unit_id;
}

void ShipShipment::setWeightUnitId(int weightUnitId)
{
    d->weight_unit_id = weightUnitId;
}

double ShipShipment::heightQt() const
{
    return d->height_qt;
}

void ShipShipment::setHeightQt(double heightQt)
{
    d->height_qt = heightQt;
}

int ShipShipment::heightUnitId() const
{
    return d->height_unit_id;
}

void ShipShipment::setHeightUnitId(int heightUnitId)
{
    d->height_unit_id = heightUnitId;
}

double ShipShipment::lengthQt() const
{
    return d->length_qt;
}

void ShipShipment::setLengthQt(double lengthQt)
{
    d->length_qt = lengthQt;
}

int ShipShipment::lengthUnitId() const
{
    return d->length_unit_id;
}

void ShipShipment::setLengthUnitId(int lengthUnitId)
{
    d->length_unit_id = lengthUnitId;
}

double ShipShipment::widthQt() const
{
    return d->width_qt;
}

void ShipShipment::setWidthQt(double widthQt)
{
    d->width_qt = widthQt;
}

int ShipShipment::widthUnitId() const
{
    return d->width_unit_id;
}

void ShipShipment::setWidthUnitId(int widthUnitId)
{
    d->width_unit_id = widthUnitId;
}

int ShipShipment::poId() const
{
    return d->po_id;
}

void ShipShipment::setPoId(int poId)
{
    d->po_id = poId;
}

int ShipShipment::schedId() const
{
    return d->sched_id;
}

void ShipShipment::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int ShipShipment::accountId() const
{
    return d->account_id;
}

void ShipShipment::setAccountId(int accountId)
{
    d->account_id = accountId;
}

QDateTime ShipShipment::createdAt() const
{
    return d->created_at;
}

QString ShipShipment::createdBy() const
{
    return d->created_by;
}

void ShipShipment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ShipShipment::updatedAt() const
{
    return d->updated_at;
}

QString ShipShipment::updatedBy() const
{
    return d->updated_by;
}

void ShipShipment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount ShipShipment::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

SchedStask ShipShipment::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

PoHeader ShipShipment::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

MesurUnit ShipShipment::mesurUnitBywidthUnitId() const
{
 return MesurUnit::get(d->width_unit_id);
}

Org ShipShipment::orgByorgId() const
{
 return Org::get(d->org_id);
}

Transportor ShipShipment::transportorBytransportorId() const
{
 return Transportor::get(d->transportor_id);
}

RefShipmentType ShipShipment::refShipmentTypeByshipmentTypeCd() const
{
 return RefShipmentType::get(d->shipment_type_cd);
}

ShipShipment &ShipShipment::operator=(const ShipShipment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ShipShipment ShipShipment::create(const QString &shipmentTypeCd, int transportorId, int orgId, const QString &waybillNo, const QString &flightNo, const QString &customsDeclaration, const QString &customsDesc, bool confirmReceiptBool, const QDateTime &shipAfterDt, const QDateTime &shipDt, const QString &returnAuthNo, double returnPrice, const QString &returnDesc, double weightQt, int weightUnitId, double heightQt, int heightUnitId, double lengthQt, int lengthUnitId, double widthQt, int widthUnitId, int poId, int schedId, int accountId, const QString &createdBy, const QString &updatedBy)
{
    ShipShipmentObject obj;
    obj.shipment_type_cd = shipmentTypeCd;
    obj.transportor_id = transportorId;
    obj.org_id = orgId;
    obj.waybill_no = waybillNo;
    obj.flight_no = flightNo;
    obj.customs_declaration = customsDeclaration;
    obj.customs_desc = customsDesc;
    obj.confirm_receipt_bool = confirmReceiptBool;
    obj.ship_after_dt = shipAfterDt;
    obj.ship_dt = shipDt;
    obj.return_auth_no = returnAuthNo;
    obj.return_price = returnPrice;
    obj.return_desc = returnDesc;
    obj.weight_qt = weightQt;
    obj.weight_unit_id = weightUnitId;
    obj.height_qt = heightQt;
    obj.height_unit_id = heightUnitId;
    obj.length_qt = lengthQt;
    obj.length_unit_id = lengthUnitId;
    obj.width_qt = widthQt;
    obj.width_unit_id = widthUnitId;
    obj.po_id = poId;
    obj.sched_id = schedId;
    obj.account_id = accountId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ShipShipment();
    }
    return ShipShipment(obj);
}

ShipShipment ShipShipment::create(const QVariantMap &values)
{
    ShipShipment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ShipShipment ShipShipment::get(int shipmentId)
{
    TSqlORMapper<ShipShipmentObject> mapper;
    return ShipShipment(mapper.findByPrimaryKey(shipmentId));
}

int ShipShipment::count()
{
    TSqlORMapper<ShipShipmentObject> mapper;
    return mapper.findCount();
}

QList<ShipShipment> ShipShipment::getAll()
{
    return tfGetModelListByCriteria<ShipShipment, ShipShipmentObject>();
}

TModelObject *ShipShipment::modelData()
{
    return d.data();
}

const TModelObject *ShipShipment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ShipShipment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ShipShipment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ShipShipment)
