#include <TreeFrogModel>
#include "shipshipmentlinedoc.h"
#include "shipshipmentlinedocobject.h"
#include "regbodydoc.h"
#include "shipshipmentline.h"

ShipShipmentLineDoc::ShipShipmentLineDoc()
    : TAbstractModel(), d(new ShipShipmentLineDocObject())
{
    d->shipment_line_id = 0;
    d->reg_body_doc_id = 0;
}

ShipShipmentLineDoc::ShipShipmentLineDoc(const ShipShipmentLineDoc &other)
    : TAbstractModel(), d(new ShipShipmentLineDocObject(*other.d))
{ }

ShipShipmentLineDoc::ShipShipmentLineDoc(const ShipShipmentLineDocObject &object)
    : TAbstractModel(), d(new ShipShipmentLineDocObject(object))
{ }

ShipShipmentLineDoc::~ShipShipmentLineDoc()
{
    // If the reference count becomes 0,
    // the shared data object 'ShipShipmentLineDocObject' is deleted.
}

int ShipShipmentLineDoc::shipmentLineId() const
{
    return d->shipment_line_id;
}

void ShipShipmentLineDoc::setShipmentLineId(int shipmentLineId)
{
    d->shipment_line_id = shipmentLineId;
}

int ShipShipmentLineDoc::regBodyDocId() const
{
    return d->reg_body_doc_id;
}

void ShipShipmentLineDoc::setRegBodyDocId(int regBodyDocId)
{
    d->reg_body_doc_id = regBodyDocId;
}

bool ShipShipmentLineDoc::receivedDocBool() const
{
    return d->received_doc_bool;
}

void ShipShipmentLineDoc::setReceivedDocBool(bool receivedDocBool)
{
    d->received_doc_bool = receivedDocBool;
}

QDateTime ShipShipmentLineDoc::createdAt() const
{
    return d->created_at;
}

QString ShipShipmentLineDoc::createdBy() const
{
    return d->created_by;
}

void ShipShipmentLineDoc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ShipShipmentLineDoc::updatedAt() const
{
    return d->updated_at;
}

QString ShipShipmentLineDoc::updatedBy() const
{
    return d->updated_by;
}

void ShipShipmentLineDoc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RegBodyDoc ShipShipmentLineDoc::regBodyDocByregBodyDocId() const
{
 return RegBodyDoc::get(d->reg_body_doc_id);
}

ShipShipmentLine ShipShipmentLineDoc::shipShipmentLineByshipmentLineId() const
{
 return ShipShipmentLine::get(d->shipment_line_id);
}

ShipShipmentLineDoc &ShipShipmentLineDoc::operator=(const ShipShipmentLineDoc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ShipShipmentLineDoc ShipShipmentLineDoc::create(int shipmentLineId, int regBodyDocId, bool receivedDocBool, const QString &createdBy, const QString &updatedBy)
{
    ShipShipmentLineDocObject obj;
    obj.shipment_line_id = shipmentLineId;
    obj.reg_body_doc_id = regBodyDocId;
    obj.received_doc_bool = receivedDocBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ShipShipmentLineDoc();
    }
    return ShipShipmentLineDoc(obj);
}

ShipShipmentLineDoc ShipShipmentLineDoc::create(const QVariantMap &values)
{
    ShipShipmentLineDoc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ShipShipmentLineDoc ShipShipmentLineDoc::get(int shipmentLineId, int regBodyDocId)
{
    TSqlORMapper<ShipShipmentLineDocObject> mapper;
    return ShipShipmentLineDoc(mapper.findByPrimaryKey(QVariantList()<<QVariant(shipmentLineId)<<QVariant(regBodyDocId)));
}

int ShipShipmentLineDoc::count()
{
    TSqlORMapper<ShipShipmentLineDocObject> mapper;
    return mapper.findCount();
}

QList<ShipShipmentLineDoc> ShipShipmentLineDoc::getAll()
{
    return tfGetModelListByCriteria<ShipShipmentLineDoc, ShipShipmentLineDocObject>();
}

TModelObject *ShipShipmentLineDoc::modelData()
{
    return d.data();
}

const TModelObject *ShipShipmentLineDoc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ShipShipmentLineDoc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ShipShipmentLineDoc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ShipShipmentLineDoc)
