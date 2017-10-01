#include <TreeFrogModel>
#include "evtinv.h"
#include "evtinvobject.h"
#include "eqppartno.h"
#include "eqpassmblbompos.h"
#include "eqpassmbl.h"
#include "eqpassmblbom.h"
#include "invinv.h"
#include "evtevent.h"

EvtInv::EvtInv()
    : TAbstractModel(), d(new EvtInvObject())
{
    d->event_id = 0;
    d->inv_no_id = 0;
    d->nh_inv_no_id = 0;
    d->assmbl_inv_no_id = 0;
    d->h_inv_no_id = 0;
    d->assmbl_bom_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_pos_id = 0;
    d->part_no_id = 0;
}

EvtInv::EvtInv(const EvtInv &other)
    : TAbstractModel(), d(new EvtInvObject(*other.d))
{ }

EvtInv::EvtInv(const EvtInvObject &object)
    : TAbstractModel(), d(new EvtInvObject(object))
{ }

EvtInv::~EvtInv()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtInvObject' is deleted.
}

int EvtInv::eventId() const
{
    return d->event_id;
}

void EvtInv::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtInv::invNoId() const
{
    return d->inv_no_id;
}

void EvtInv::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int EvtInv::nhInvNoId() const
{
    return d->nh_inv_no_id;
}

void EvtInv::setNhInvNoId(int nhInvNoId)
{
    d->nh_inv_no_id = nhInvNoId;
}

int EvtInv::assmblInvNoId() const
{
    return d->assmbl_inv_no_id;
}

void EvtInv::setAssmblInvNoId(int assmblInvNoId)
{
    d->assmbl_inv_no_id = assmblInvNoId;
}

int EvtInv::hInvNoId() const
{
    return d->h_inv_no_id;
}

void EvtInv::setHInvNoId(int hInvNoId)
{
    d->h_inv_no_id = hInvNoId;
}

int EvtInv::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EvtInv::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int EvtInv::assmblId() const
{
    return d->assmbl_id;
}

void EvtInv::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int EvtInv::assmblBomPosId() const
{
    return d->assmbl_bom_pos_id;
}

void EvtInv::setAssmblBomPosId(int assmblBomPosId)
{
    d->assmbl_bom_pos_id = assmblBomPosId;
}

int EvtInv::partNoId() const
{
    return d->part_no_id;
}

void EvtInv::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

bool EvtInv::mainInvBool() const
{
    return d->main_inv_bool;
}

void EvtInv::setMainInvBool(bool mainInvBool)
{
    d->main_inv_bool = mainInvBool;
}

QDateTime EvtInv::createdAt() const
{
    return d->created_at;
}

QString EvtInv::createdBy() const
{
    return d->created_by;
}

void EvtInv::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtInv::updatedAt() const
{
    return d->updated_at;
}

QString EvtInv::updatedBy() const
{
    return d->updated_by;
}

void EvtInv::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EvtInv::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBomPos EvtInv::eqpAssmblBomPosByassmblBomPosId() const
{
 return EqpAssmblBomPos::get(d->assmbl_bom_pos_id);
}

EqpAssmbl EvtInv::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpAssmblBom EvtInv::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

InvInv EvtInv::invInvByhInvNoId() const
{
 return InvInv::get(d->h_inv_no_id);
}

EvtEvent EvtInv::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtInv &EvtInv::operator=(const EvtInv &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtInv EvtInv::create(int eventId, int invNoId, int nhInvNoId, int assmblInvNoId, int hInvNoId, int assmblBomId, int assmblId, int assmblBomPosId, int partNoId, bool mainInvBool, const QString &createdBy, const QString &updatedBy)
{
    EvtInvObject obj;
    obj.event_id = eventId;
    obj.inv_no_id = invNoId;
    obj.nh_inv_no_id = nhInvNoId;
    obj.assmbl_inv_no_id = assmblInvNoId;
    obj.h_inv_no_id = hInvNoId;
    obj.assmbl_bom_id = assmblBomId;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_pos_id = assmblBomPosId;
    obj.part_no_id = partNoId;
    obj.main_inv_bool = mainInvBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtInv();
    }
    return EvtInv(obj);
}

EvtInv EvtInv::create(const QVariantMap &values)
{
    EvtInv model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtInv EvtInv::get(int eventId, int invNoId)
{
    TSqlORMapper<EvtInvObject> mapper;
    return EvtInv(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(invNoId)));
}

int EvtInv::count()
{
    TSqlORMapper<EvtInvObject> mapper;
    return mapper.findCount();
}

QList<EvtInv> EvtInv::getAll()
{
    return tfGetModelListByCriteria<EvtInv, EvtInvObject>();
}

TModelObject *EvtInv::modelData()
{
    return d.data();
}

const TModelObject *EvtInv::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtInv &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtInv &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtInv)
