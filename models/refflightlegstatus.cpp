#include <TreeFrogModel>
#include "refflightlegstatus.h"
#include "refflightlegstatusobject.h"

RefFlightLegStatus::RefFlightLegStatus()
    : TAbstractModel(), d(new RefFlightLegStatusObject())
{ }

RefFlightLegStatus::RefFlightLegStatus(const RefFlightLegStatus &other)
    : TAbstractModel(), d(new RefFlightLegStatusObject(*other.d))
{ }

RefFlightLegStatus::RefFlightLegStatus(const RefFlightLegStatusObject &object)
    : TAbstractModel(), d(new RefFlightLegStatusObject(object))
{ }

RefFlightLegStatus::~RefFlightLegStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefFlightLegStatusObject' is deleted.
}

QString RefFlightLegStatus::flightLegStatusCd() const
{
    return d->flight_leg_status_cd;
}

void RefFlightLegStatus::setFlightLegStatusCd(const QString &flightLegStatusCd)
{
    d->flight_leg_status_cd = flightLegStatusCd;
}

QString RefFlightLegStatus::flightLegStatusNameEn() const
{
    return d->flight_leg_status_name_en;
}

void RefFlightLegStatus::setFlightLegStatusNameEn(const QString &flightLegStatusNameEn)
{
    d->flight_leg_status_name_en = flightLegStatusNameEn;
}

QString RefFlightLegStatus::flightLegStatusNameZh() const
{
    return d->flight_leg_status_name_zh;
}

void RefFlightLegStatus::setFlightLegStatusNameZh(const QString &flightLegStatusNameZh)
{
    d->flight_leg_status_name_zh = flightLegStatusNameZh;
}

QString RefFlightLegStatus::flightLegStatusDesc() const
{
    return d->flight_leg_status_desc;
}

void RefFlightLegStatus::setFlightLegStatusDesc(const QString &flightLegStatusDesc)
{
    d->flight_leg_status_desc = flightLegStatusDesc;
}

QDateTime RefFlightLegStatus::createdAt() const
{
    return d->created_at;
}

QString RefFlightLegStatus::createdBy() const
{
    return d->created_by;
}

void RefFlightLegStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefFlightLegStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefFlightLegStatus::updatedBy() const
{
    return d->updated_by;
}

void RefFlightLegStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefFlightLegStatus &RefFlightLegStatus::operator=(const RefFlightLegStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefFlightLegStatus RefFlightLegStatus::create(const QString &flightLegStatusCd, const QString &flightLegStatusNameEn, const QString &flightLegStatusNameZh, const QString &flightLegStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefFlightLegStatusObject obj;
    obj.flight_leg_status_cd = flightLegStatusCd;
    obj.flight_leg_status_name_en = flightLegStatusNameEn;
    obj.flight_leg_status_name_zh = flightLegStatusNameZh;
    obj.flight_leg_status_desc = flightLegStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefFlightLegStatus();
    }
    return RefFlightLegStatus(obj);
}

RefFlightLegStatus RefFlightLegStatus::create(const QVariantMap &values)
{
    RefFlightLegStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefFlightLegStatus RefFlightLegStatus::get(const QString &flightLegStatusCd)
{
    TSqlORMapper<RefFlightLegStatusObject> mapper;
    return RefFlightLegStatus(mapper.findByPrimaryKey(flightLegStatusCd));
}

int RefFlightLegStatus::count()
{
    TSqlORMapper<RefFlightLegStatusObject> mapper;
    return mapper.findCount();
}

QList<RefFlightLegStatus> RefFlightLegStatus::getAll()
{
    return tfGetModelListByCriteria<RefFlightLegStatus, RefFlightLegStatusObject>();
}

TModelObject *RefFlightLegStatus::modelData()
{
    return d.data();
}

const TModelObject *RefFlightLegStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefFlightLegStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefFlightLegStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefFlightLegStatus)
