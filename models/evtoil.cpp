#include <TreeFrogModel>
#include "evtoil.h"
#include "evtoilobject.h"
#include "mesurunit.h"
#include "evtevent.h"

EvtOil::EvtOil()
    : TAbstractModel(), d(new EvtOilObject())
{
    d->event_id = 0;
    d->mesur_unit_id = 0;
    d->fill_qty = 0;
}

EvtOil::EvtOil(const EvtOil &other)
    : TAbstractModel(), d(new EvtOilObject(*other.d))
{ }

EvtOil::EvtOil(const EvtOilObject &object)
    : TAbstractModel(), d(new EvtOilObject(object))
{ }

EvtOil::~EvtOil()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtOilObject' is deleted.
}

int EvtOil::eventId() const
{
    return d->event_id;
}

void EvtOil::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtOil::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void EvtOil::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

double EvtOil::fillQty() const
{
    return d->fill_qty;
}

void EvtOil::setFillQty(double fillQty)
{
    d->fill_qty = fillQty;
}

QDateTime EvtOil::createdAt() const
{
    return d->created_at;
}

QString EvtOil::createdBy() const
{
    return d->created_by;
}

void EvtOil::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtOil::updatedAt() const
{
    return d->updated_at;
}

QString EvtOil::updatedBy() const
{
    return d->updated_by;
}

void EvtOil::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit EvtOil::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

EvtEvent EvtOil::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtOil &EvtOil::operator=(const EvtOil &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtOil EvtOil::create(int eventId, int mesurUnitId, double fillQty, const QString &createdBy, const QString &updatedBy)
{
    EvtOilObject obj;
    obj.event_id = eventId;
    obj.mesur_unit_id = mesurUnitId;
    obj.fill_qty = fillQty;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtOil();
    }
    return EvtOil(obj);
}

EvtOil EvtOil::create(const QVariantMap &values)
{
    EvtOil model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtOil EvtOil::get(int eventId)
{
    TSqlORMapper<EvtOilObject> mapper;
    return EvtOil(mapper.findByPrimaryKey(eventId));
}

int EvtOil::count()
{
    TSqlORMapper<EvtOilObject> mapper;
    return mapper.findCount();
}

QList<EvtOil> EvtOil::getAll()
{
    return tfGetModelListByCriteria<EvtOil, EvtOilObject>();
}

TModelObject *EvtOil::modelData()
{
    return d.data();
}

const TModelObject *EvtOil::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtOil &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtOil &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtOil)
