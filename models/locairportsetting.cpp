#include <TreeFrogModel>
#include "locairportsetting.h"
#include "locairportsettingobject.h"
#include "loc.h"

LocAirportSetting::LocAirportSetting()
    : TAbstractModel(), d(new LocAirportSettingObject())
{
    d->loc_id = 0;
    d->inbound_flight_qt = 0;
}

LocAirportSetting::LocAirportSetting(const LocAirportSetting &other)
    : TAbstractModel(), d(new LocAirportSettingObject(*other.d))
{ }

LocAirportSetting::LocAirportSetting(const LocAirportSettingObject &object)
    : TAbstractModel(), d(new LocAirportSettingObject(object))
{ }

LocAirportSetting::~LocAirportSetting()
{
    // If the reference count becomes 0,
    // the shared data object 'LocAirportSettingObject' is deleted.
}

int LocAirportSetting::locId() const
{
    return d->loc_id;
}

void LocAirportSetting::setLocId(int locId)
{
    d->loc_id = locId;
}

QString LocAirportSetting::timezoneCd() const
{
    return d->timezone_cd;
}

void LocAirportSetting::setTimezoneCd(const QString &timezoneCd)
{
    d->timezone_cd = timezoneCd;
}

bool LocAirportSetting::supplyBool() const
{
    return d->supply_bool;
}

void LocAirportSetting::setSupplyBool(bool supplyBool)
{
    d->supply_bool = supplyBool;
}

int LocAirportSetting::inboundFlightQt() const
{
    return d->inbound_flight_qt;
}

void LocAirportSetting::setInboundFlightQt(int inboundFlightQt)
{
    d->inbound_flight_qt = inboundFlightQt;
}

QDateTime LocAirportSetting::createdAt() const
{
    return d->created_at;
}

QString LocAirportSetting::createdBy() const
{
    return d->created_by;
}

void LocAirportSetting::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocAirportSetting::updatedAt() const
{
    return d->updated_at;
}

QString LocAirportSetting::updatedBy() const
{
    return d->updated_by;
}

void LocAirportSetting::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Loc LocAirportSetting::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocAirportSetting &LocAirportSetting::operator=(const LocAirportSetting &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocAirportSetting LocAirportSetting::create(int locId, const QString &timezoneCd, bool supplyBool, int inboundFlightQt, const QString &createdBy, const QString &updatedBy)
{
    LocAirportSettingObject obj;
    obj.loc_id = locId;
    obj.timezone_cd = timezoneCd;
    obj.supply_bool = supplyBool;
    obj.inbound_flight_qt = inboundFlightQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocAirportSetting();
    }
    return LocAirportSetting(obj);
}

LocAirportSetting LocAirportSetting::create(const QVariantMap &values)
{
    LocAirportSetting model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocAirportSetting LocAirportSetting::get(int locId)
{
    TSqlORMapper<LocAirportSettingObject> mapper;
    return LocAirportSetting(mapper.findByPrimaryKey(locId));
}

int LocAirportSetting::count()
{
    TSqlORMapper<LocAirportSettingObject> mapper;
    return mapper.findCount();
}

QList<LocAirportSetting> LocAirportSetting::getAll()
{
    return tfGetModelListByCriteria<LocAirportSetting, LocAirportSettingObject>();
}

TModelObject *LocAirportSetting::modelData()
{
    return d.data();
}

const TModelObject *LocAirportSetting::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocAirportSetting &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocAirportSetting &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocAirportSetting)
