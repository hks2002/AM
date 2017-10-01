#include <TreeFrogModel>
#include "evtloc.h"
#include "evtlocobject.h"
#include "loc.h"
#include "evtevent.h"

EvtLoc::EvtLoc()
    : TAbstractModel(), d(new EvtLocObject())
{
    d->event_id = 0;
    d->loc_id = 0;
}

EvtLoc::EvtLoc(const EvtLoc &other)
    : TAbstractModel(), d(new EvtLocObject(*other.d))
{ }

EvtLoc::EvtLoc(const EvtLocObject &object)
    : TAbstractModel(), d(new EvtLocObject(object))
{ }

EvtLoc::~EvtLoc()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtLocObject' is deleted.
}

int EvtLoc::eventId() const
{
    return d->event_id;
}

void EvtLoc::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtLoc::locId() const
{
    return d->loc_id;
}

void EvtLoc::setLocId(int locId)
{
    d->loc_id = locId;
}

QDateTime EvtLoc::createdAt() const
{
    return d->created_at;
}

QString EvtLoc::createdBy() const
{
    return d->created_by;
}

void EvtLoc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtLoc::updatedAt() const
{
    return d->updated_at;
}

QString EvtLoc::updatedBy() const
{
    return d->updated_by;
}

void EvtLoc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Loc EvtLoc::locBylocId() const
{
 return Loc::get(d->loc_id);
}

EvtEvent EvtLoc::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtLoc &EvtLoc::operator=(const EvtLoc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtLoc EvtLoc::create(int eventId, int locId, const QString &createdBy, const QString &updatedBy)
{
    EvtLocObject obj;
    obj.event_id = eventId;
    obj.loc_id = locId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtLoc();
    }
    return EvtLoc(obj);
}

EvtLoc EvtLoc::create(const QVariantMap &values)
{
    EvtLoc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtLoc EvtLoc::get(int eventId, int locId)
{
    TSqlORMapper<EvtLocObject> mapper;
    return EvtLoc(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(locId)));
}

int EvtLoc::count()
{
    TSqlORMapper<EvtLocObject> mapper;
    return mapper.findCount();
}

QList<EvtLoc> EvtLoc::getAll()
{
    return tfGetModelListByCriteria<EvtLoc, EvtLocObject>();
}

TModelObject *EvtLoc::modelData()
{
    return d.data();
}

const TModelObject *EvtLoc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtLoc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtLoc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtLoc)
