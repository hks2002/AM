#include <TreeFrogModel>
#include "evthr.h"
#include "evthrobject.h"
#include "userapp.h"
#include "evtevent.h"

EvtHr::EvtHr()
    : TAbstractModel(), d(new EvtHrObject())
{
    d->event_id = 0;
    d->user_id = 0;
}

EvtHr::EvtHr(const EvtHr &other)
    : TAbstractModel(), d(new EvtHrObject(*other.d))
{ }

EvtHr::EvtHr(const EvtHrObject &object)
    : TAbstractModel(), d(new EvtHrObject(object))
{ }

EvtHr::~EvtHr()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtHrObject' is deleted.
}

int EvtHr::eventId() const
{
    return d->event_id;
}

void EvtHr::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtHr::userId() const
{
    return d->user_id;
}

void EvtHr::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime EvtHr::createdAt() const
{
    return d->created_at;
}

QString EvtHr::createdBy() const
{
    return d->created_by;
}

void EvtHr::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtHr::updatedAt() const
{
    return d->updated_at;
}

QString EvtHr::updatedBy() const
{
    return d->updated_by;
}

void EvtHr::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp EvtHr::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

EvtEvent EvtHr::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtHr &EvtHr::operator=(const EvtHr &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtHr EvtHr::create(int eventId, int userId, const QString &createdBy, const QString &updatedBy)
{
    EvtHrObject obj;
    obj.event_id = eventId;
    obj.user_id = userId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtHr();
    }
    return EvtHr(obj);
}

EvtHr EvtHr::create(const QVariantMap &values)
{
    EvtHr model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtHr EvtHr::get(int eventId, int userId)
{
    TSqlORMapper<EvtHrObject> mapper;
    return EvtHr(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(userId)));
}

int EvtHr::count()
{
    TSqlORMapper<EvtHrObject> mapper;
    return mapper.findCount();
}

QList<EvtHr> EvtHr::getAll()
{
    return tfGetModelListByCriteria<EvtHr, EvtHrObject>();
}

TModelObject *EvtHr::modelData()
{
    return d.data();
}

const TModelObject *EvtHr::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtHr &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtHr &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtHr)
