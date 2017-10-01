#include <TreeFrogModel>
#include "rfqline.h"
#include "rfqlineobject.h"
#include "poline.h"
#include "poheader.h"
#include "refreqpriority.h"
#include "eqppartno.h"
#include "loc.h"
#include "qtyunit.h"
#include "rfqheader.h"

RfqLine::RfqLine()
    : TAbstractModel(), d(new RfqLineObject())
{
    d->rfq_line_id = 0;
    d->rfq_id = 0;
    d->line_no_ord = 0;
    d->rfq_qt = 0;
    d->qty_unit_id = 0;
    d->ship_to_loc_id = 0;
    d->part_no_id = 0;
    d->po_id = 0;
    d->po_line_id = 0;
}

RfqLine::RfqLine(const RfqLine &other)
    : TAbstractModel(), d(new RfqLineObject(*other.d))
{ }

RfqLine::RfqLine(const RfqLineObject &object)
    : TAbstractModel(), d(new RfqLineObject(object))
{ }

RfqLine::~RfqLine()
{
    // If the reference count becomes 0,
    // the shared data object 'RfqLineObject' is deleted.
}

int RfqLine::rfqLineId() const
{
    return d->rfq_line_id;
}

int RfqLine::rfqId() const
{
    return d->rfq_id;
}

void RfqLine::setRfqId(int rfqId)
{
    d->rfq_id = rfqId;
}

int RfqLine::lineNoOrd() const
{
    return d->line_no_ord;
}

void RfqLine::setLineNoOrd(int lineNoOrd)
{
    d->line_no_ord = lineNoOrd;
}

QString RfqLine::lineDesc() const
{
    return d->line_desc;
}

void RfqLine::setLineDesc(const QString &lineDesc)
{
    d->line_desc = lineDesc;
}

QString RfqLine::noteToVendor() const
{
    return d->note_to_vendor;
}

void RfqLine::setNoteToVendor(const QString &noteToVendor)
{
    d->note_to_vendor = noteToVendor;
}

int RfqLine::rfqQt() const
{
    return d->rfq_qt;
}

void RfqLine::setRfqQt(int rfqQt)
{
    d->rfq_qt = rfqQt;
}

int RfqLine::qtyUnitId() const
{
    return d->qty_unit_id;
}

void RfqLine::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

int RfqLine::shipToLocId() const
{
    return d->ship_to_loc_id;
}

void RfqLine::setShipToLocId(int shipToLocId)
{
    d->ship_to_loc_id = shipToLocId;
}

int RfqLine::partNoId() const
{
    return d->part_no_id;
}

void RfqLine::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString RfqLine::reqPriorityCd() const
{
    return d->req_priority_cd;
}

void RfqLine::setReqPriorityCd(const QString &reqPriorityCd)
{
    d->req_priority_cd = reqPriorityCd;
}

int RfqLine::poId() const
{
    return d->po_id;
}

void RfqLine::setPoId(int poId)
{
    d->po_id = poId;
}

int RfqLine::poLineId() const
{
    return d->po_line_id;
}

void RfqLine::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

QDateTime RfqLine::createdAt() const
{
    return d->created_at;
}

QString RfqLine::createdBy() const
{
    return d->created_by;
}

void RfqLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RfqLine::updatedAt() const
{
    return d->updated_at;
}

QString RfqLine::updatedBy() const
{
    return d->updated_by;
}

void RfqLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

PoLine RfqLine::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoHeader RfqLine::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

RefReqPriority RfqLine::refReqPriorityByreqPriorityCd() const
{
 return RefReqPriority::get(d->req_priority_cd);
}

EqpPartNo RfqLine::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Loc RfqLine::locByshipToLocId() const
{
 return Loc::get(d->ship_to_loc_id);
}

QtyUnit RfqLine::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

RfqHeader RfqLine::rfqHeaderByrfqId() const
{
 return RfqHeader::get(d->rfq_id);
}

RfqLine &RfqLine::operator=(const RfqLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RfqLine RfqLine::create(int rfqId, int lineNoOrd, const QString &lineDesc, const QString &noteToVendor, int rfqQt, int qtyUnitId, int shipToLocId, int partNoId, const QString &reqPriorityCd, int poId, int poLineId, const QString &createdBy, const QString &updatedBy)
{
    RfqLineObject obj;
    obj.rfq_id = rfqId;
    obj.line_no_ord = lineNoOrd;
    obj.line_desc = lineDesc;
    obj.note_to_vendor = noteToVendor;
    obj.rfq_qt = rfqQt;
    obj.qty_unit_id = qtyUnitId;
    obj.ship_to_loc_id = shipToLocId;
    obj.part_no_id = partNoId;
    obj.req_priority_cd = reqPriorityCd;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RfqLine();
    }
    return RfqLine(obj);
}

RfqLine RfqLine::create(const QVariantMap &values)
{
    RfqLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RfqLine RfqLine::get(int rfqLineId)
{
    TSqlORMapper<RfqLineObject> mapper;
    return RfqLine(mapper.findByPrimaryKey(rfqLineId));
}

int RfqLine::count()
{
    TSqlORMapper<RfqLineObject> mapper;
    return mapper.findCount();
}

QList<RfqLine> RfqLine::getAll()
{
    return tfGetModelListByCriteria<RfqLine, RfqLineObject>();
}

TModelObject *RfqLine::modelData()
{
    return d.data();
}

const TModelObject *RfqLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RfqLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RfqLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RfqLine)
