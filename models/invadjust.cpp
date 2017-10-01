#include <TreeFrogModel>
#include "invadjust.h"
#include "invadjustobject.h"
#include "userapp.h"
#include "refxactiontype.h"
#include "poline.h"
#include "poheader.h"
#include "eqppartno.h"
#include "invinv.h"
#include "evtevent.h"

InvAdjust::InvAdjust()
    : TAbstractModel(), d(new InvAdjustObject())
{
    d->inv_adjust_id = 0;
    d->event_id = 0;
    d->inv_no_id = 0;
    d->part_no_id = 0;
    d->po_id = 0;
    d->po_line_id = 0;
    d->adjust_by = 0;
    d->adjust_qt = 0;
}

InvAdjust::InvAdjust(const InvAdjust &other)
    : TAbstractModel(), d(new InvAdjustObject(*other.d))
{ }

InvAdjust::InvAdjust(const InvAdjustObject &object)
    : TAbstractModel(), d(new InvAdjustObject(object))
{ }

InvAdjust::~InvAdjust()
{
    // If the reference count becomes 0,
    // the shared data object 'InvAdjustObject' is deleted.
}

int InvAdjust::invAdjustId() const
{
    return d->inv_adjust_id;
}

int InvAdjust::eventId() const
{
    return d->event_id;
}

void InvAdjust::setEventId(int eventId)
{
    d->event_id = eventId;
}

int InvAdjust::invNoId() const
{
    return d->inv_no_id;
}

void InvAdjust::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int InvAdjust::partNoId() const
{
    return d->part_no_id;
}

void InvAdjust::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int InvAdjust::poId() const
{
    return d->po_id;
}

void InvAdjust::setPoId(int poId)
{
    d->po_id = poId;
}

int InvAdjust::poLineId() const
{
    return d->po_line_id;
}

void InvAdjust::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

QString InvAdjust::xactionTypeCd() const
{
    return d->xaction_type_cd;
}

void InvAdjust::setXactionTypeCd(const QString &xactionTypeCd)
{
    d->xaction_type_cd = xactionTypeCd;
}

int InvAdjust::adjustBy() const
{
    return d->adjust_by;
}

void InvAdjust::setAdjustBy(int adjustBy)
{
    d->adjust_by = adjustBy;
}

QDateTime InvAdjust::adjustDt() const
{
    return d->adjust_dt;
}

void InvAdjust::setAdjustDt(const QDateTime &adjustDt)
{
    d->adjust_dt = adjustDt;
}

int InvAdjust::adjustQt() const
{
    return d->adjust_qt;
}

void InvAdjust::setAdjustQt(int adjustQt)
{
    d->adjust_qt = adjustQt;
}

QString InvAdjust::userNote() const
{
    return d->user_note;
}

void InvAdjust::setUserNote(const QString &userNote)
{
    d->user_note = userNote;
}

QDateTime InvAdjust::createdAt() const
{
    return d->created_at;
}

QString InvAdjust::createdBy() const
{
    return d->created_by;
}

void InvAdjust::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvAdjust::updatedAt() const
{
    return d->updated_at;
}

QString InvAdjust::updatedBy() const
{
    return d->updated_by;
}

void InvAdjust::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp InvAdjust::userAppByadjustBy() const
{
 return UserApp::get(d->adjust_by);
}

RefXactionType InvAdjust::refXactionTypeByxactionTypeCd() const
{
 return RefXactionType::get(d->xaction_type_cd);
}

PoLine InvAdjust::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoHeader InvAdjust::poHeaderBypoId() const
{
 return PoHeader::get(d->po_id);
}

EqpPartNo InvAdjust::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

InvInv InvAdjust::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

EvtEvent InvAdjust::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

InvAdjust &InvAdjust::operator=(const InvAdjust &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvAdjust InvAdjust::create(int eventId, int invNoId, int partNoId, int poId, int poLineId, const QString &xactionTypeCd, int adjustBy, const QDateTime &adjustDt, int adjustQt, const QString &userNote, const QString &createdBy, const QString &updatedBy)
{
    InvAdjustObject obj;
    obj.event_id = eventId;
    obj.inv_no_id = invNoId;
    obj.part_no_id = partNoId;
    obj.po_id = poId;
    obj.po_line_id = poLineId;
    obj.xaction_type_cd = xactionTypeCd;
    obj.adjust_by = adjustBy;
    obj.adjust_dt = adjustDt;
    obj.adjust_qt = adjustQt;
    obj.user_note = userNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvAdjust();
    }
    return InvAdjust(obj);
}

InvAdjust InvAdjust::create(const QVariantMap &values)
{
    InvAdjust model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvAdjust InvAdjust::get(int invAdjustId)
{
    TSqlORMapper<InvAdjustObject> mapper;
    return InvAdjust(mapper.findByPrimaryKey(invAdjustId));
}

int InvAdjust::count()
{
    TSqlORMapper<InvAdjustObject> mapper;
    return mapper.findCount();
}

QList<InvAdjust> InvAdjust::getAll()
{
    return tfGetModelListByCriteria<InvAdjust, InvAdjustObject>();
}

TModelObject *InvAdjust::modelData()
{
    return d.data();
}

const TModelObject *InvAdjust::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvAdjust &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvAdjust &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvAdjust)
