#include <TreeFrogModel>
#include "reqpart.h"
#include "reqpartobject.h"
#include "refreqtype.h"
#include "refreqpriority.h"
#include "eqppartno.h"
#include "eqpassmbl.h"
#include "eqpassmblbom.h"
#include "eqpstock.h"
#include "loc.h"
#include "invinv.h"
#include "refpartprovidertype.h"
#include "fncaccount.h"
#include "schedstask.h"
#include "schedinstpart.h"
#include "schedpart.h"
#include "shipshipmentline.h"
#include "poheader.h"
#include "poline.h"
#include "vendor.h"
#include "userapp.h"

ReqPart::ReqPart()
    : TAbstractModel(), d(new ReqPartObject())
{
    d->req_part_id = 0;
    d->part_no_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
    d->stock_id = 0;
    d->loc_id = 0;
    d->inv_no_id = 0;
    d->account_id = 0;
    d->issue_unit_price = 0;
    d->sched_id = 0;
    d->sched_inst_part_id = 0;
    d->sched_part_id = 0;
    d->shipment_line_id = 0;
    d->po_id = 0;
    d->po_line_id = 0;
    d->csgn_vendor_id = 0;
    d->csgn_owed_qt = 0;
    d->assigned_to = 0;
}

ReqPart::ReqPart(const ReqPart &other)
    : TAbstractModel(), d(new ReqPartObject(*other.d))
{ }

ReqPart::ReqPart(const ReqPartObject &object)
    : TAbstractModel(), d(new ReqPartObject(object))
{ }

ReqPart::~ReqPart()
{
    // If the reference count becomes 0,
    // the shared data object 'ReqPartObject' is deleted.
}

int ReqPart::reqPartId() const
{
    return d->req_part_id;
}

QString ReqPart::reqTypeCd() const
{
    return d->req_type_cd;
}

void ReqPart::setReqTypeCd(const QString &reqTypeCd)
{
    d->req_type_cd = reqTypeCd;
}

QString ReqPart::reqPriorityCd() const
{
    return d->req_priority_cd;
}

void ReqPart::setReqPriorityCd(const QString &reqPriorityCd)
{
    d->req_priority_cd = reqPriorityCd;
}

int ReqPart::partNoId() const
{
    return d->part_no_id;
}

void ReqPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int ReqPart::assmblId() const
{
    return d->assmbl_id;
}

void ReqPart::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int ReqPart::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void ReqPart::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int ReqPart::stockId() const
{
    return d->stock_id;
}

void ReqPart::setStockId(int stockId)
{
    d->stock_id = stockId;
}

int ReqPart::locId() const
{
    return d->loc_id;
}

void ReqPart::setLocId(int locId)
{
    d->loc_id = locId;
}

bool ReqPart::lockReserveBool() const
{
    return d->lock_reserve_bool;
}

void ReqPart::setLockReserveBool(bool lockReserveBool)
{
    d->lock_reserve_bool = lockReserveBool;
}

int ReqPart::invNoId() const
{
    return d->inv_no_id;
}

void ReqPart::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QDateTime ReqPart::estArrivalDt() const
{
    return d->est_arrival_dt;
}

void ReqPart::setEstArrivalDt(const QDateTime &estArrivalDt)
{
    d->est_arrival_dt = estArrivalDt;
}

QString ReqPart::partProviderTypeCd() const
{
    return d->part_provider_type_cd;
}

void ReqPart::setPartProviderTypeCd(const QString &partProviderTypeCd)
{
    d->part_provider_type_cd = partProviderTypeCd;
}

bool ReqPart::maTrackBool() const
{
    return d->ma_track_bool;
}

void ReqPart::setMaTrackBool(bool maTrackBool)
{
    d->ma_track_bool = maTrackBool;
}

int ReqPart::accountId() const
{
    return d->account_id;
}

void ReqPart::setAccountId(int accountId)
{
    d->account_id = accountId;
}

double ReqPart::issueUnitPrice() const
{
    return d->issue_unit_price;
}

void ReqPart::setIssueUnitPrice(double issueUnitPrice)
{
    d->issue_unit_price = issueUnitPrice;
}

QString ReqPart::reqMasterId() const
{
    return d->req_master_id;
}

void ReqPart::setReqMasterId(const QString &reqMasterId)
{
    d->req_master_id = reqMasterId;
}

QString ReqPart::reqNote() const
{
    return d->req_note;
}

void ReqPart::setReqNote(const QString &reqNote)
{
    d->req_note = reqNote;
}

QDateTime ReqPart::reqQt() const
{
    return d->req_qt;
}

void ReqPart::setReqQt(const QDateTime &reqQt)
{
    d->req_qt = reqQt;
}

QDateTime ReqPart::reqDt() const
{
    return d->req_dt;
}

void ReqPart::setReqDt(const QDateTime &reqDt)
{
    d->req_dt = reqDt;
}

int ReqPart::schedId() const
{
    return d->sched_id;
}

void ReqPart::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int ReqPart::schedInstPartId() const
{
    return d->sched_inst_part_id;
}

void ReqPart::setSchedInstPartId(int schedInstPartId)
{
    d->sched_inst_part_id = schedInstPartId;
}

int ReqPart::schedPartId() const
{
    return d->sched_part_id;
}

void ReqPart::setSchedPartId(int schedPartId)
{
    d->sched_part_id = schedPartId;
}

int ReqPart::shipmentLineId() const
{
    return d->shipment_line_id;
}

void ReqPart::setShipmentLineId(int shipmentLineId)
{
    d->shipment_line_id = shipmentLineId;
}

int ReqPart::poId() const
{
    return d->po_id;
}

void ReqPart::setPoId(int poId)
{
    d->po_id = poId;
}

int ReqPart::poLineId() const
{
    return d->po_line_id;
}

void ReqPart::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int ReqPart::csgnVendorId() const
{
    return d->csgn_vendor_id;
}

void ReqPart::setCsgnVendorId(int csgnVendorId)
{
    d->csgn_vendor_id = csgnVendorId;
}

int ReqPart::csgnOwedQt() const
{
    return d->csgn_owed_qt;
}

void ReqPart::setCsgnOwedQt(int csgnOwedQt)
{
    d->csgn_owed_qt = csgnOwedQt;
}

int ReqPart::assignedTo() const
{
    return d->assigned_to;
}

void ReqPart::setAssignedTo(int assignedTo)
{
    d->assigned_to = assignedTo;
}

QDateTime ReqPart::createdAt() const
{
    return d->created_at;
}

QString ReqPart::createdBy() const
{
    return d->created_by;
}

void ReqPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ReqPart::updatedAt() const
{
    return d->updated_at;
}

QString ReqPart::updatedBy() const
{
    return d->updated_by;
}

void ReqPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReqType ReqPart::refReqTypeByreqTypeCd() const
{
 return RefReqType::get(d->req_type_cd);
}

RefReqPriority ReqPart::refReqPriorityByreqPriorityCd() const
{
 return RefReqPriority::get(d->req_priority_cd);
}

EqpPartNo ReqPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmbl ReqPart::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblBom ReqPart::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpStock ReqPart::eqpStockBystockId() const
{
 return EqpStock::get(d->stock_id);
}

Loc ReqPart::locBylocId() const
{
 return Loc::get(d->loc_id);
}

InvInv ReqPart::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

RefPartProviderType ReqPart::refPartProviderTypeBypartProviderTypeCd() const
{
 return RefPartProviderType::get(d->part_provider_type_cd);
}

FncAccount ReqPart::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

SchedStask ReqPart::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedInstPart ReqPart::schedInstPartByschedInstPartId() const
{
 return SchedInstPart::get(d->sched_inst_part_id);
}

SchedPart ReqPart::schedPartByschedPartId() const
{
 return SchedPart::get(d->sched_part_id);
}

ShipShipmentLine ReqPart::shipShipmentLineByshipmentLineId() const
{
 return ShipShipmentLine::get(d->shipment_line_id);
}

PoHeader ReqPart::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

PoLine ReqPart::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

Vendor ReqPart::vendorBycsgnVendorId() const
{
 return Vendor::get(d->csgn_vendor_id);
}

UserApp ReqPart::userAppByassignedTo() const
{
 return UserApp::get(d->assigned_to);
}

ReqPart &ReqPart::operator=(const ReqPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ReqPart ReqPart::create(const QString &reqTypeCd, const QString &reqPriorityCd, int partNoId, int assmblId, int assmblBomId, int stockId, int locId, bool lockReserveBool, int invNoId, const QDateTime &estArrivalDt, const QString &partProviderTypeCd, bool maTrackBool, int accountId, double issueUnitPrice, const QString &reqMasterId, const QString &reqNote, const QDateTime &reqQt, const QDateTime &reqDt, int schedId, int schedInstPartId, int schedPartId, int shipmentLineId, int poId, int poLineId, int csgnVendorId, int csgnOwedQt, int assignedTo, const QString &createdBy, const QString &updatedBy)
{
    ReqPartObject obj;
    obj.req_type_cd = reqTypeCd;
    obj.req_priority_cd = reqPriorityCd;
    obj.part_no_id = partNoId;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.stock_id = stockId;
    obj.loc_id = locId;
    obj.lock_reserve_bool = lockReserveBool;
    obj.inv_no_id = invNoId;
    obj.est_arrival_dt = estArrivalDt;
    obj.part_provider_type_cd = partProviderTypeCd;
    obj.ma_track_bool = maTrackBool;
    obj.account_id = accountId;
    obj.issue_unit_price = issueUnitPrice;
    obj.req_master_id = reqMasterId;
    obj.req_note = reqNote;
    obj.req_qt = reqQt;
    obj.req_dt = reqDt;
    obj.sched_id = schedId;
    obj.sched_inst_part_id = schedInstPartId;
    obj.sched_part_id = schedPartId;
    obj.shipment_line_id = shipmentLineId;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.csgn_vendor_id = csgnVendorId;
    obj.csgn_owed_qt = csgnOwedQt;
    obj.assigned_to = assignedTo;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ReqPart();
    }
    return ReqPart(obj);
}

ReqPart ReqPart::create(const QVariantMap &values)
{
    ReqPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ReqPart ReqPart::get(int reqPartId)
{
    TSqlORMapper<ReqPartObject> mapper;
    return ReqPart(mapper.findByPrimaryKey(reqPartId));
}

int ReqPart::count()
{
    TSqlORMapper<ReqPartObject> mapper;
    return mapper.findCount();
}

QList<ReqPart> ReqPart::getAll()
{
    return tfGetModelListByCriteria<ReqPart, ReqPartObject>();
}

TModelObject *ReqPart::modelData()
{
    return d.data();
}

const TModelObject *ReqPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ReqPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ReqPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ReqPart)
