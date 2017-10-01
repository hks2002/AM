#include <TreeFrogModel>
#include "flightlegstatuslog.h"
#include "flightlegstatuslogobject.h"
#include "userapp.h"
#include "flightleg.h"

FlightLegStatusLog::FlightLegStatusLog()
    : TAbstractModel(), d(new FlightLegStatusLogObject())
{
    d->leg_status_log_id = 0;
    d->leg_id = 0;
    d->log_by = 0;
}

FlightLegStatusLog::FlightLegStatusLog(const FlightLegStatusLog &other)
    : TAbstractModel(), d(new FlightLegStatusLogObject(*other.d))
{ }

FlightLegStatusLog::FlightLegStatusLog(const FlightLegStatusLogObject &object)
    : TAbstractModel(), d(new FlightLegStatusLogObject(object))
{ }

FlightLegStatusLog::~FlightLegStatusLog()
{
    // If the reference count becomes 0,
    // the shared data object 'FlightLegStatusLogObject' is deleted.
}

int FlightLegStatusLog::legStatusLogId() const
{
    return d->leg_status_log_id;
}

int FlightLegStatusLog::legId() const
{
    return d->leg_id;
}

void FlightLegStatusLog::setLegId(int legId)
{
    d->leg_id = legId;
}

QDateTime FlightLegStatusLog::logDt() const
{
    return d->log_dt;
}

void FlightLegStatusLog::setLogDt(const QDateTime &logDt)
{
    d->log_dt = logDt;
}

QString FlightLegStatusLog::flightLegStatusCd() const
{
    return d->flight_leg_status_cd;
}

void FlightLegStatusLog::setFlightLegStatusCd(const QString &flightLegStatusCd)
{
    d->flight_leg_status_cd = flightLegStatusCd;
}

bool FlightLegStatusLog::systemBool() const
{
    return d->system_bool;
}

void FlightLegStatusLog::setSystemBool(bool systemBool)
{
    d->system_bool = systemBool;
}

int FlightLegStatusLog::logBy() const
{
    return d->log_by;
}

void FlightLegStatusLog::setLogBy(int logBy)
{
    d->log_by = logBy;
}

QDateTime FlightLegStatusLog::createdAt() const
{
    return d->created_at;
}

QString FlightLegStatusLog::createdBy() const
{
    return d->created_by;
}

void FlightLegStatusLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FlightLegStatusLog::updatedAt() const
{
    return d->updated_at;
}

QString FlightLegStatusLog::updatedBy() const
{
    return d->updated_by;
}

void FlightLegStatusLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp FlightLegStatusLog::userAppBylogBy() const
{
 return UserApp::get(d->log_by);
}

FlightLeg FlightLegStatusLog::flightLegBylegId() const
{
 return FlightLeg::get(d->leg_id);
}

FlightLegStatusLog &FlightLegStatusLog::operator=(const FlightLegStatusLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FlightLegStatusLog FlightLegStatusLog::create(int legId, const QDateTime &logDt, const QString &flightLegStatusCd, bool systemBool, int logBy, const QString &createdBy, const QString &updatedBy)
{
    FlightLegStatusLogObject obj;
    obj.leg_id = legId;
    obj.log_dt = logDt;
    obj.flight_leg_status_cd = flightLegStatusCd;
    obj.system_bool = systemBool;
    obj.log_by = logBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FlightLegStatusLog();
    }
    return FlightLegStatusLog(obj);
}

FlightLegStatusLog FlightLegStatusLog::create(const QVariantMap &values)
{
    FlightLegStatusLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FlightLegStatusLog FlightLegStatusLog::get(int legStatusLogId)
{
    TSqlORMapper<FlightLegStatusLogObject> mapper;
    return FlightLegStatusLog(mapper.findByPrimaryKey(legStatusLogId));
}

int FlightLegStatusLog::count()
{
    TSqlORMapper<FlightLegStatusLogObject> mapper;
    return mapper.findCount();
}

QList<FlightLegStatusLog> FlightLegStatusLog::getAll()
{
    return tfGetModelListByCriteria<FlightLegStatusLog, FlightLegStatusLogObject>();
}

TModelObject *FlightLegStatusLog::modelData()
{
    return d.data();
}

const TModelObject *FlightLegStatusLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FlightLegStatusLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FlightLegStatusLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FlightLegStatusLog)
