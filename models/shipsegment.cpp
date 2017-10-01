#include <TreeFrogModel>
#include "shipsegment.h"
#include "shipsegmentobject.h"
#include "userapp.h"
#include "loc.h"
#include "refsegmentstatus.h"
#include "shipshipment.h"

ShipSegment::ShipSegment()
    : TAbstractModel(), d(new ShipSegmentObject())
{
    d->segment_id = 0;
    d->shipment_id = 0;
    d->segment_ord = 0;
    d->ship_from_id = 0;
    d->ship_to_id = 0;
    d->complete_by = 0;
}

ShipSegment::ShipSegment(const ShipSegment &other)
    : TAbstractModel(), d(new ShipSegmentObject(*other.d))
{ }

ShipSegment::ShipSegment(const ShipSegmentObject &object)
    : TAbstractModel(), d(new ShipSegmentObject(object))
{ }

ShipSegment::~ShipSegment()
{
    // If the reference count becomes 0,
    // the shared data object 'ShipSegmentObject' is deleted.
}

int ShipSegment::segmentId() const
{
    return d->segment_id;
}

int ShipSegment::shipmentId() const
{
    return d->shipment_id;
}

void ShipSegment::setShipmentId(int shipmentId)
{
    d->shipment_id = shipmentId;
}

int ShipSegment::segmentOrd() const
{
    return d->segment_ord;
}

void ShipSegment::setSegmentOrd(int segmentOrd)
{
    d->segment_ord = segmentOrd;
}

QString ShipSegment::segmentStatusCd() const
{
    return d->segment_status_cd;
}

void ShipSegment::setSegmentStatusCd(const QString &segmentStatusCd)
{
    d->segment_status_cd = segmentStatusCd;
}

QString ShipSegment::waybillNo() const
{
    return d->waybill_no;
}

void ShipSegment::setWaybillNo(const QString &waybillNo)
{
    d->waybill_no = waybillNo;
}

QString ShipSegment::customsDesc() const
{
    return d->customs_desc;
}

void ShipSegment::setCustomsDesc(const QString &customsDesc)
{
    d->customs_desc = customsDesc;
}

int ShipSegment::shipFromId() const
{
    return d->ship_from_id;
}

void ShipSegment::setShipFromId(int shipFromId)
{
    d->ship_from_id = shipFromId;
}

int ShipSegment::shipToId() const
{
    return d->ship_to_id;
}

void ShipSegment::setShipToId(int shipToId)
{
    d->ship_to_id = shipToId;
}

int ShipSegment::completeBy() const
{
    return d->complete_by;
}

void ShipSegment::setCompleteBy(int completeBy)
{
    d->complete_by = completeBy;
}

QDateTime ShipSegment::completeDt() const
{
    return d->complete_dt;
}

void ShipSegment::setCompleteDt(const QDateTime &completeDt)
{
    d->complete_dt = completeDt;
}

QDateTime ShipSegment::createdAt() const
{
    return d->created_at;
}

QString ShipSegment::createdBy() const
{
    return d->created_by;
}

void ShipSegment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ShipSegment::updatedAt() const
{
    return d->updated_at;
}

QString ShipSegment::updatedBy() const
{
    return d->updated_by;
}

void ShipSegment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp ShipSegment::userAppBycompleteBy() const
{
 return UserApp::get(d->complete_by);
}

Loc ShipSegment::locByshipToId() const
{
 return Loc::get(d->ship_to_id);
}

RefSegmentStatus ShipSegment::refSegmentStatusBysegmentStatusCd() const
{
 return RefSegmentStatus::get(d->segment_status_cd);
}

ShipShipment ShipSegment::shipShipmentByshipmentId() const
{
 return ShipShipment::get(d->shipment_id);
}

ShipSegment &ShipSegment::operator=(const ShipSegment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ShipSegment ShipSegment::create(int shipmentId, int segmentOrd, const QString &segmentStatusCd, const QString &waybillNo, const QString &customsDesc, int shipFromId, int shipToId, int completeBy, const QDateTime &completeDt, const QString &createdBy, const QString &updatedBy)
{
    ShipSegmentObject obj;
    obj.shipment_id = shipmentId;
    obj.segment_ord = segmentOrd;
    obj.segment_status_cd = segmentStatusCd;
    obj.waybill_no = waybillNo;
    obj.customs_desc = customsDesc;
    obj.ship_from_id = shipFromId;
    obj.ship_to_id = shipToId;
    obj.complete_by = completeBy;
    obj.complete_dt = completeDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ShipSegment();
    }
    return ShipSegment(obj);
}

ShipSegment ShipSegment::create(const QVariantMap &values)
{
    ShipSegment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ShipSegment ShipSegment::get(int segmentId)
{
    TSqlORMapper<ShipSegmentObject> mapper;
    return ShipSegment(mapper.findByPrimaryKey(segmentId));
}

int ShipSegment::count()
{
    TSqlORMapper<ShipSegmentObject> mapper;
    return mapper.findCount();
}

QList<ShipSegment> ShipSegment::getAll()
{
    return tfGetModelListByCriteria<ShipSegment, ShipSegmentObject>();
}

TModelObject *ShipSegment::modelData()
{
    return d.data();
}

const TModelObject *ShipSegment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ShipSegment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ShipSegment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ShipSegment)
