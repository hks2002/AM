#include <TreeFrogModel>
#include "shipshipmentline.h"
#include "shipshipmentlineobject.h"
#include "refreceivepriority.h"
#include "invinv.h"
#include "refinvcond.h"
#include "eqppartno.h"
#include "poline.h"
#include "poheader.h"
#include "shipshipment.h"

ShipShipmentLine::ShipShipmentLine()
    : TAbstractModel(), d(new ShipShipmentLineObject())
{
    d->shipment_line_id = 0;
    d->shipment_id = 0;
    d->line_no_ord = 0;
    d->po_id = 0;
    d->po_line_id = 0;
    d->part_no_id = 0;
    d->expect_qt = 0;
    d->inv_no_id = 0;
    d->received_qt = 0;
}

ShipShipmentLine::ShipShipmentLine(const ShipShipmentLine &other)
    : TAbstractModel(), d(new ShipShipmentLineObject(*other.d))
{ }

ShipShipmentLine::ShipShipmentLine(const ShipShipmentLineObject &object)
    : TAbstractModel(), d(new ShipShipmentLineObject(object))
{ }

ShipShipmentLine::~ShipShipmentLine()
{
    // If the reference count becomes 0,
    // the shared data object 'ShipShipmentLineObject' is deleted.
}

int ShipShipmentLine::shipmentLineId() const
{
    return d->shipment_line_id;
}

int ShipShipmentLine::shipmentId() const
{
    return d->shipment_id;
}

void ShipShipmentLine::setShipmentId(int shipmentId)
{
    d->shipment_id = shipmentId;
}

int ShipShipmentLine::lineNoOrd() const
{
    return d->line_no_ord;
}

void ShipShipmentLine::setLineNoOrd(int lineNoOrd)
{
    d->line_no_ord = lineNoOrd;
}

int ShipShipmentLine::poId() const
{
    return d->po_id;
}

void ShipShipmentLine::setPoId(int poId)
{
    d->po_id = poId;
}

int ShipShipmentLine::poLineId() const
{
    return d->po_line_id;
}

void ShipShipmentLine::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int ShipShipmentLine::partNoId() const
{
    return d->part_no_id;
}

void ShipShipmentLine::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int ShipShipmentLine::expectQt() const
{
    return d->expect_qt;
}

void ShipShipmentLine::setExpectQt(int expectQt)
{
    d->expect_qt = expectQt;
}

QString ShipShipmentLine::invCondCd() const
{
    return d->inv_cond_cd;
}

void ShipShipmentLine::setInvCondCd(const QString &invCondCd)
{
    d->inv_cond_cd = invCondCd;
}

QString ShipShipmentLine::serialNoOem() const
{
    return d->serial_no_oem;
}

void ShipShipmentLine::setSerialNoOem(const QString &serialNoOem)
{
    d->serial_no_oem = serialNoOem;
}

int ShipShipmentLine::invNoId() const
{
    return d->inv_no_id;
}

void ShipShipmentLine::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QString ShipShipmentLine::rcvPriorityCd() const
{
    return d->rcv_priority_cd;
}

void ShipShipmentLine::setRcvPriorityCd(const QString &rcvPriorityCd)
{
    d->rcv_priority_cd = rcvPriorityCd;
}

bool ShipShipmentLine::receivedDocBool() const
{
    return d->received_doc_bool;
}

void ShipShipmentLine::setReceivedDocBool(bool receivedDocBool)
{
    d->received_doc_bool = receivedDocBool;
}

QString ShipShipmentLine::shipmentLineNotes() const
{
    return d->shipment_line_notes;
}

void ShipShipmentLine::setShipmentLineNotes(const QString &shipmentLineNotes)
{
    d->shipment_line_notes = shipmentLineNotes;
}

int ShipShipmentLine::receivedQt() const
{
    return d->received_qt;
}

void ShipShipmentLine::setReceivedQt(int receivedQt)
{
    d->received_qt = receivedQt;
}

QDateTime ShipShipmentLine::createdAt() const
{
    return d->created_at;
}

QString ShipShipmentLine::createdBy() const
{
    return d->created_by;
}

void ShipShipmentLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ShipShipmentLine::updatedAt() const
{
    return d->updated_at;
}

QString ShipShipmentLine::updatedBy() const
{
    return d->updated_by;
}

void ShipShipmentLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReceivePriority ShipShipmentLine::refReceivePriorityByrcvPriorityCd() const
{
 return RefReceivePriority::get(d->rcv_priority_cd);
}

InvInv ShipShipmentLine::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

RefInvCond ShipShipmentLine::refInvCondByinvCondCd() const
{
 return RefInvCond::get(d->inv_cond_cd);
}

EqpPartNo ShipShipmentLine::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

PoLine ShipShipmentLine::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoHeader ShipShipmentLine::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

ShipShipment ShipShipmentLine::shipShipmentByshipmentId() const
{
 return ShipShipment::get(d->shipment_id);
}

ShipShipmentLine &ShipShipmentLine::operator=(const ShipShipmentLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ShipShipmentLine ShipShipmentLine::create(int shipmentId, int lineNoOrd, int poId, int poLineId, int partNoId, int expectQt, const QString &invCondCd, const QString &serialNoOem, int invNoId, const QString &rcvPriorityCd, bool receivedDocBool, const QString &shipmentLineNotes, int receivedQt, const QString &createdBy, const QString &updatedBy)
{
    ShipShipmentLineObject obj;
    obj.shipment_id = shipmentId;
    obj.line_no_ord = lineNoOrd;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.part_no_id = partNoId;
    obj.expect_qt = expectQt;
    obj.inv_cond_cd = invCondCd;
    obj.serial_no_oem = serialNoOem;
    obj.inv_no_id = invNoId;
    obj.rcv_priority_cd = rcvPriorityCd;
    obj.received_doc_bool = receivedDocBool;
    obj.shipment_line_notes = shipmentLineNotes;
    obj.received_qt = receivedQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ShipShipmentLine();
    }
    return ShipShipmentLine(obj);
}

ShipShipmentLine ShipShipmentLine::create(const QVariantMap &values)
{
    ShipShipmentLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ShipShipmentLine ShipShipmentLine::get(int shipmentLineId)
{
    TSqlORMapper<ShipShipmentLineObject> mapper;
    return ShipShipmentLine(mapper.findByPrimaryKey(shipmentLineId));
}

int ShipShipmentLine::count()
{
    TSqlORMapper<ShipShipmentLineObject> mapper;
    return mapper.findCount();
}

QList<ShipShipmentLine> ShipShipmentLine::getAll()
{
    return tfGetModelListByCriteria<ShipShipmentLine, ShipShipmentLineObject>();
}

TModelObject *ShipShipmentLine::modelData()
{
    return d.data();
}

const TModelObject *ShipShipmentLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ShipShipmentLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ShipShipmentLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ShipShipmentLine)
