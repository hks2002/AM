#include <TreeFrogModel>
#include "evtpartno.h"
#include "evtpartnoobject.h"
#include "eqppartno.h"
#include "evtevent.h"

EvtPartNo::EvtPartNo()
    : TAbstractModel(), d(new EvtPartNoObject())
{
    d->event_id = 0;
    d->part_no_id = 0;
}

EvtPartNo::EvtPartNo(const EvtPartNo &other)
    : TAbstractModel(), d(new EvtPartNoObject(*other.d))
{ }

EvtPartNo::EvtPartNo(const EvtPartNoObject &object)
    : TAbstractModel(), d(new EvtPartNoObject(object))
{ }

EvtPartNo::~EvtPartNo()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtPartNoObject' is deleted.
}

int EvtPartNo::eventId() const
{
    return d->event_id;
}

void EvtPartNo::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtPartNo::partNoId() const
{
    return d->part_no_id;
}

void EvtPartNo::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QDateTime EvtPartNo::createdAt() const
{
    return d->created_at;
}

QString EvtPartNo::createdBy() const
{
    return d->created_by;
}

void EvtPartNo::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtPartNo::updatedAt() const
{
    return d->updated_at;
}

QString EvtPartNo::updatedBy() const
{
    return d->updated_by;
}

void EvtPartNo::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EvtPartNo::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EvtEvent EvtPartNo::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtPartNo &EvtPartNo::operator=(const EvtPartNo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtPartNo EvtPartNo::create(int eventId, int partNoId, const QString &createdBy, const QString &updatedBy)
{
    EvtPartNoObject obj;
    obj.event_id = eventId;
    obj.part_no_id = partNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtPartNo();
    }
    return EvtPartNo(obj);
}

EvtPartNo EvtPartNo::create(const QVariantMap &values)
{
    EvtPartNo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtPartNo EvtPartNo::get(int eventId, int partNoId)
{
    TSqlORMapper<EvtPartNoObject> mapper;
    return EvtPartNo(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(partNoId)));
}

int EvtPartNo::count()
{
    TSqlORMapper<EvtPartNoObject> mapper;
    return mapper.findCount();
}

QList<EvtPartNo> EvtPartNo::getAll()
{
    return tfGetModelListByCriteria<EvtPartNo, EvtPartNoObject>();
}

TModelObject *EvtPartNo::modelData()
{
    return d.data();
}

const TModelObject *EvtPartNo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtPartNo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtPartNo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtPartNo)
