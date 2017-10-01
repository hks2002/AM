#include <TreeFrogModel>
#include "invxfer.h"
#include "invxferobject.h"
#include "userapp.h"
#include "refxfertype.h"
#include "evtevent.h"
#include "invinv.h"

InvXfer::InvXfer()
    : TAbstractModel(), d(new InvXferObject())
{
    d->inv_xfer_id = 0;
    d->inv_no_id = 0;
    d->event_id = 0;
    d->xfer_qt = 0;
    d->unit_price = 0;
    d->received_by = 0;
}

InvXfer::InvXfer(const InvXfer &other)
    : TAbstractModel(), d(new InvXferObject(*other.d))
{ }

InvXfer::InvXfer(const InvXferObject &object)
    : TAbstractModel(), d(new InvXferObject(object))
{ }

InvXfer::~InvXfer()
{
    // If the reference count becomes 0,
    // the shared data object 'InvXferObject' is deleted.
}

int InvXfer::invXferId() const
{
    return d->inv_xfer_id;
}

int InvXfer::invNoId() const
{
    return d->inv_no_id;
}

void InvXfer::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int InvXfer::eventId() const
{
    return d->event_id;
}

void InvXfer::setEventId(int eventId)
{
    d->event_id = eventId;
}

QString InvXfer::xferTypeCd() const
{
    return d->xfer_type_cd;
}

void InvXfer::setXferTypeCd(const QString &xferTypeCd)
{
    d->xfer_type_cd = xferTypeCd;
}

int InvXfer::xferQt() const
{
    return d->xfer_qt;
}

void InvXfer::setXferQt(int xferQt)
{
    d->xfer_qt = xferQt;
}

double InvXfer::unitPrice() const
{
    return d->unit_price;
}

void InvXfer::setUnitPrice(double unitPrice)
{
    d->unit_price = unitPrice;
}

int InvXfer::receivedBy() const
{
    return d->received_by;
}

void InvXfer::setReceivedBy(int receivedBy)
{
    d->received_by = receivedBy;
}

QDateTime InvXfer::createdAt() const
{
    return d->created_at;
}

QString InvXfer::createdBy() const
{
    return d->created_by;
}

void InvXfer::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvXfer::updatedAt() const
{
    return d->updated_at;
}

QString InvXfer::updatedBy() const
{
    return d->updated_by;
}

void InvXfer::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp InvXfer::userAppByreceivedBy() const
{
 return UserApp::get(d->received_by);
}

RefXferType InvXfer::refXferTypeByxferTypeCd() const
{
 return RefXferType::get(d->xfer_type_cd);
}

EvtEvent InvXfer::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

InvInv InvXfer::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvXfer &InvXfer::operator=(const InvXfer &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvXfer InvXfer::create(int invNoId, int eventId, const QString &xferTypeCd, int xferQt, double unitPrice, int receivedBy, const QString &createdBy, const QString &updatedBy)
{
    InvXferObject obj;
    obj.inv_no_id = invNoId;
    obj.event_id = eventId;
    obj.xfer_type_cd = xferTypeCd;
    obj.xfer_qt = xferQt;
    obj.unit_price = unitPrice;
    obj.received_by = receivedBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvXfer();
    }
    return InvXfer(obj);
}

InvXfer InvXfer::create(const QVariantMap &values)
{
    InvXfer model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvXfer InvXfer::get(int invXferId)
{
    TSqlORMapper<InvXferObject> mapper;
    return InvXfer(mapper.findByPrimaryKey(invXferId));
}

int InvXfer::count()
{
    TSqlORMapper<InvXferObject> mapper;
    return mapper.findCount();
}

QList<InvXfer> InvXfer::getAll()
{
    return tfGetModelListByCriteria<InvXfer, InvXferObject>();
}

TModelObject *InvXfer::modelData()
{
    return d.data();
}

const TModelObject *InvXfer::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvXfer &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvXfer &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvXfer)
