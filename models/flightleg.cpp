#include <TreeFrogModel>
#include "flightleg.h"
#include "flightlegobject.h"
#include "invacreg.h"
#include "loc.h"
#include "refflightlegstatus.h"

FlightLeg::FlightLeg()
    : TAbstractModel(), d(new FlightLegObject())
{
    d->leg_id = 0;
    d->departure_loc_id = 0;
    d->arrival_loc_id = 0;
    d->aircraft_id = 0;
}

FlightLeg::FlightLeg(const FlightLeg &other)
    : TAbstractModel(), d(new FlightLegObject(*other.d))
{ }

FlightLeg::FlightLeg(const FlightLegObject &object)
    : TAbstractModel(), d(new FlightLegObject(object))
{ }

FlightLeg::~FlightLeg()
{
    // If the reference count becomes 0,
    // the shared data object 'FlightLegObject' is deleted.
}

int FlightLeg::legId() const
{
    return d->leg_id;
}

QString FlightLeg::legNo() const
{
    return d->leg_no;
}

void FlightLeg::setLegNo(const QString &legNo)
{
    d->leg_no = legNo;
}

bool FlightLeg::histBool() const
{
    return d->hist_bool;
}

void FlightLeg::setHistBool(bool histBool)
{
    d->hist_bool = histBool;
}

QString FlightLeg::flightLegStatusCd() const
{
    return d->flight_leg_status_cd;
}

void FlightLeg::setFlightLegStatusCd(const QString &flightLegStatusCd)
{
    d->flight_leg_status_cd = flightLegStatusCd;
}

QDateTime FlightLeg::actualDepartureDt() const
{
    return d->actual_departure_dt;
}

void FlightLeg::setActualDepartureDt(const QDateTime &actualDepartureDt)
{
    d->actual_departure_dt = actualDepartureDt;
}

int FlightLeg::departureLocId() const
{
    return d->departure_loc_id;
}

void FlightLeg::setDepartureLocId(int departureLocId)
{
    d->departure_loc_id = departureLocId;
}

int FlightLeg::arrivalLocId() const
{
    return d->arrival_loc_id;
}

void FlightLeg::setArrivalLocId(int arrivalLocId)
{
    d->arrival_loc_id = arrivalLocId;
}

QDateTime FlightLeg::actualArrivalDt() const
{
    return d->actual_arrival_dt;
}

void FlightLeg::setActualArrivalDt(const QDateTime &actualArrivalDt)
{
    d->actual_arrival_dt = actualArrivalDt;
}

QDateTime FlightLeg::recordedDt() const
{
    return d->recorded_dt;
}

void FlightLeg::setRecordedDt(const QDateTime &recordedDt)
{
    d->recorded_dt = recordedDt;
}

QString FlightLeg::legDesc() const
{
    return d->leg_desc;
}

void FlightLeg::setLegDesc(const QString &legDesc)
{
    d->leg_desc = legDesc;
}

QString FlightLeg::masterFlightNo() const
{
    return d->master_flight_no;
}

void FlightLeg::setMasterFlightNo(const QString &masterFlightNo)
{
    d->master_flight_no = masterFlightNo;
}

QString FlightLeg::extKey() const
{
    return d->ext_key;
}

void FlightLeg::setExtKey(const QString &extKey)
{
    d->ext_key = extKey;
}

int FlightLeg::aircraftId() const
{
    return d->aircraft_id;
}

void FlightLeg::setAircraftId(int aircraftId)
{
    d->aircraft_id = aircraftId;
}

QString FlightLeg::logbookRef() const
{
    return d->logbook_ref;
}

void FlightLeg::setLogbookRef(const QString &logbookRef)
{
    d->logbook_ref = logbookRef;
}

QString FlightLeg::departureGateCd() const
{
    return d->departure_gate_cd;
}

void FlightLeg::setDepartureGateCd(const QString &departureGateCd)
{
    d->departure_gate_cd = departureGateCd;
}

QString FlightLeg::arrivalGateCd() const
{
    return d->arrival_gate_cd;
}

void FlightLeg::setArrivalGateCd(const QString &arrivalGateCd)
{
    d->arrival_gate_cd = arrivalGateCd;
}

QDateTime FlightLeg::schedDepartureDt() const
{
    return d->sched_departure_dt;
}

void FlightLeg::setSchedDepartureDt(const QDateTime &schedDepartureDt)
{
    d->sched_departure_dt = schedDepartureDt;
}

QDateTime FlightLeg::schedArrivalDt() const
{
    return d->sched_arrival_dt;
}

void FlightLeg::setSchedArrivalDt(const QDateTime &schedArrivalDt)
{
    d->sched_arrival_dt = schedArrivalDt;
}

QDateTime FlightLeg::offDt() const
{
    return d->off_dt;
}

void FlightLeg::setOffDt(const QDateTime &offDt)
{
    d->off_dt = offDt;
}

QDateTime FlightLeg::onDt() const
{
    return d->on_dt;
}

void FlightLeg::setOnDt(const QDateTime &onDt)
{
    d->on_dt = onDt;
}

QDateTime FlightLeg::createdAt() const
{
    return d->created_at;
}

QString FlightLeg::createdBy() const
{
    return d->created_by;
}

void FlightLeg::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime FlightLeg::updatedAt() const
{
    return d->updated_at;
}

QString FlightLeg::updatedBy() const
{
    return d->updated_by;
}

void FlightLeg::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvAcReg FlightLeg::invAcRegByaircraftId() const
{
 return InvAcReg::get(d->aircraft_id);
}

Loc FlightLeg::locByarrivalLocId() const
{
 return Loc::get(d->arrival_loc_id);
}

RefFlightLegStatus FlightLeg::refFlightLegStatusByflightLegStatusCd() const
{
 return RefFlightLegStatus::get(d->flight_leg_status_cd);
}

FlightLeg &FlightLeg::operator=(const FlightLeg &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FlightLeg FlightLeg::create(const QString &legNo, bool histBool, const QString &flightLegStatusCd, const QDateTime &actualDepartureDt, int departureLocId, int arrivalLocId, const QDateTime &actualArrivalDt, const QDateTime &recordedDt, const QString &legDesc, const QString &masterFlightNo, const QString &extKey, int aircraftId, const QString &logbookRef, const QString &departureGateCd, const QString &arrivalGateCd, const QDateTime &schedDepartureDt, const QDateTime &schedArrivalDt, const QDateTime &offDt, const QDateTime &onDt, const QString &createdBy, const QString &updatedBy)
{
    FlightLegObject obj;
    obj.leg_no = legNo;
    obj.hist_bool = histBool;
    obj.flight_leg_status_cd = flightLegStatusCd;
    obj.actual_departure_dt = actualDepartureDt;
    obj.departure_loc_id = departureLocId;
    obj.arrival_loc_id = arrivalLocId;
    obj.actual_arrival_dt = actualArrivalDt;
    obj.recorded_dt = recordedDt;
    obj.leg_desc = legDesc;
    obj.master_flight_no = masterFlightNo;
    obj.ext_key = extKey;
    obj.aircraft_id = aircraftId;
    obj.logbook_ref = logbookRef;
    obj.departure_gate_cd = departureGateCd;
    obj.arrival_gate_cd = arrivalGateCd;
    obj.sched_departure_dt = schedDepartureDt;
    obj.sched_arrival_dt = schedArrivalDt;
    obj.off_dt = offDt;
    obj.on_dt = onDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return FlightLeg();
    }
    return FlightLeg(obj);
}

FlightLeg FlightLeg::create(const QVariantMap &values)
{
    FlightLeg model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FlightLeg FlightLeg::get(int legId)
{
    TSqlORMapper<FlightLegObject> mapper;
    return FlightLeg(mapper.findByPrimaryKey(legId));
}

int FlightLeg::count()
{
    TSqlORMapper<FlightLegObject> mapper;
    return mapper.findCount();
}

QList<FlightLeg> FlightLeg::getAll()
{
    return tfGetModelListByCriteria<FlightLeg, FlightLegObject>();
}

TModelObject *FlightLeg::modelData()
{
    return d.data();
}

const TModelObject *FlightLeg::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FlightLeg &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FlightLeg &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FlightLeg)
