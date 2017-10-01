#include <TreeFrogModel>
#include "schedzone.h"
#include "schedzoneobject.h"
#include "eqpzone.h"
#include "eqpassmbl.h"
#include "schedstask.h"

SchedZone::SchedZone()
    : TAbstractModel(), d(new SchedZoneObject())
{
    d->sched_id = 0;
    d->assmbl_id = 0;
    d->zone_id = 0;
}

SchedZone::SchedZone(const SchedZone &other)
    : TAbstractModel(), d(new SchedZoneObject(*other.d))
{ }

SchedZone::SchedZone(const SchedZoneObject &object)
    : TAbstractModel(), d(new SchedZoneObject(object))
{ }

SchedZone::~SchedZone()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedZoneObject' is deleted.
}

int SchedZone::schedId() const
{
    return d->sched_id;
}

void SchedZone::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedZone::assmblId() const
{
    return d->assmbl_id;
}

void SchedZone::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int SchedZone::zoneId() const
{
    return d->zone_id;
}

void SchedZone::setZoneId(int zoneId)
{
    d->zone_id = zoneId;
}

QDateTime SchedZone::createdAt() const
{
    return d->created_at;
}

QString SchedZone::createdBy() const
{
    return d->created_by;
}

void SchedZone::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedZone::updatedAt() const
{
    return d->updated_at;
}

QString SchedZone::updatedBy() const
{
    return d->updated_by;
}

void SchedZone::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpZone SchedZone::eqpZoneByzoneId() const
{
 return EqpZone::get(d->zone_id);
}

EqpAssmbl SchedZone::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

SchedStask SchedZone::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedZone &SchedZone::operator=(const SchedZone &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedZone SchedZone::create(int schedId, int assmblId, int zoneId, const QString &createdBy, const QString &updatedBy)
{
    SchedZoneObject obj;
    obj.sched_id = schedId;
    obj.assmbl_id = assmblId;
    obj.zone_id = zoneId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedZone();
    }
    return SchedZone(obj);
}

SchedZone SchedZone::create(const QVariantMap &values)
{
    SchedZone model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedZone SchedZone::get(int schedId, int assmblId, int zoneId)
{
    TSqlORMapper<SchedZoneObject> mapper;
    return SchedZone(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(assmblId)<<QVariant(zoneId)));
}

int SchedZone::count()
{
    TSqlORMapper<SchedZoneObject> mapper;
    return mapper.findCount();
}

QList<SchedZone> SchedZone::getAll()
{
    return tfGetModelListByCriteria<SchedZone, SchedZoneObject>();
}

TModelObject *SchedZone::modelData()
{
    return d.data();
}

const TModelObject *SchedZone::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedZone &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedZone &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedZone)
