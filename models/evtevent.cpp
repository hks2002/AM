#include <TreeFrogModel>
#include "evtevent.h"
#include "evteventobject.h"
#include "refeventstatus.h"
#include "refeventreason.h"
#include "refeventtype.h"

EvtEvent::EvtEvent()
    : TAbstractModel(), d(new EvtEventObject())
{
    d->event_id = 0;
    d->nh_event_id = 0;
    d->h_event_id = 0;
    d->sub_event_ord = 0;
}

EvtEvent::EvtEvent(const EvtEvent &other)
    : TAbstractModel(), d(new EvtEventObject(*other.d))
{ }

EvtEvent::EvtEvent(const EvtEventObject &object)
    : TAbstractModel(), d(new EvtEventObject(object))
{ }

EvtEvent::~EvtEvent()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtEventObject' is deleted.
}

int EvtEvent::eventId() const
{
    return d->event_id;
}

QString EvtEvent::eventTypeCd() const
{
    return d->event_type_cd;
}

void EvtEvent::setEventTypeCd(const QString &eventTypeCd)
{
    d->event_type_cd = eventTypeCd;
}

QString EvtEvent::eventReasonCd() const
{
    return d->event_reason_cd;
}

void EvtEvent::setEventReasonCd(const QString &eventReasonCd)
{
    d->event_reason_cd = eventReasonCd;
}

QString EvtEvent::eventStatusCd() const
{
    return d->event_status_cd;
}

void EvtEvent::setEventStatusCd(const QString &eventStatusCd)
{
    d->event_status_cd = eventStatusCd;
}

QString EvtEvent::eventName() const
{
    return d->event_name;
}

void EvtEvent::setEventName(const QString &eventName)
{
    d->event_name = eventName;
}

QString EvtEvent::eventDesc() const
{
    return d->event_desc;
}

void EvtEvent::setEventDesc(const QString &eventDesc)
{
    d->event_desc = eventDesc;
}

QDateTime EvtEvent::eventDt() const
{
    return d->event_dt;
}

void EvtEvent::setEventDt(const QDateTime &eventDt)
{
    d->event_dt = eventDt;
}

int EvtEvent::nhEventId() const
{
    return d->nh_event_id;
}

void EvtEvent::setNhEventId(int nhEventId)
{
    d->nh_event_id = nhEventId;
}

int EvtEvent::hEventId() const
{
    return d->h_event_id;
}

void EvtEvent::setHEventId(int hEventId)
{
    d->h_event_id = hEventId;
}

int EvtEvent::subEventOrd() const
{
    return d->sub_event_ord;
}

void EvtEvent::setSubEventOrd(int subEventOrd)
{
    d->sub_event_ord = subEventOrd;
}

bool EvtEvent::histBool() const
{
    return d->hist_bool;
}

void EvtEvent::setHistBool(bool histBool)
{
    d->hist_bool = histBool;
}

QDateTime EvtEvent::createdAt() const
{
    return d->created_at;
}

QString EvtEvent::createdBy() const
{
    return d->created_by;
}

void EvtEvent::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtEvent::updatedAt() const
{
    return d->updated_at;
}

QString EvtEvent::updatedBy() const
{
    return d->updated_by;
}

void EvtEvent::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEventStatus EvtEvent::refEventStatusByeventStatusCd() const
{
 return RefEventStatus::get(d->event_status_cd);
}

RefEventReason EvtEvent::refEventReasonByeventReasonCd() const
{
 return RefEventReason::get(d->event_reason_cd);
}

RefEventType EvtEvent::refEventTypeByeventTypeCd() const
{
 return RefEventType::get(d->event_type_cd);
}

EvtEvent &EvtEvent::operator=(const EvtEvent &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtEvent EvtEvent::create(const QString &eventTypeCd, const QString &eventReasonCd, const QString &eventStatusCd, const QString &eventName, const QString &eventDesc, const QDateTime &eventDt, int nhEventId, int hEventId, int subEventOrd, bool histBool, const QString &createdBy, const QString &updatedBy)
{
    EvtEventObject obj;
    obj.event_type_cd = eventTypeCd;
    obj.event_reason_cd = eventReasonCd;
    obj.event_status_cd = eventStatusCd;
    obj.event_name = eventName;
    obj.event_desc = eventDesc;
    obj.event_dt = eventDt;
    obj.nh_event_id = nhEventId;
    obj.h_event_id = hEventId;
    obj.sub_event_ord = subEventOrd;
    obj.hist_bool = histBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtEvent();
    }
    return EvtEvent(obj);
}

EvtEvent EvtEvent::create(const QVariantMap &values)
{
    EvtEvent model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtEvent EvtEvent::get(int eventId)
{
    TSqlORMapper<EvtEventObject> mapper;
    return EvtEvent(mapper.findByPrimaryKey(eventId));
}

int EvtEvent::count()
{
    TSqlORMapper<EvtEventObject> mapper;
    return mapper.findCount();
}

QList<EvtEvent> EvtEvent::getAll()
{
    return tfGetModelListByCriteria<EvtEvent, EvtEventObject>();
}

TModelObject *EvtEvent::modelData()
{
    return d.data();
}

const TModelObject *EvtEvent::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtEvent &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtEvent &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtEvent)
