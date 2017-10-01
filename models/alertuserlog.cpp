#include <TreeFrogModel>
#include "alertuserlog.h"
#include "alertuserlogobject.h"
#include "refalertstatus.h"
#include "userapp.h"
#include "alert.h"

AlertUserLog::AlertUserLog()
    : TAbstractModel(), d(new AlertUserLogObject())
{
    d->alert_id = 0;
    d->user_id = 0;
}

AlertUserLog::AlertUserLog(const AlertUserLog &other)
    : TAbstractModel(), d(new AlertUserLogObject(*other.d))
{ }

AlertUserLog::AlertUserLog(const AlertUserLogObject &object)
    : TAbstractModel(), d(new AlertUserLogObject(object))
{ }

AlertUserLog::~AlertUserLog()
{
    // If the reference count becomes 0,
    // the shared data object 'AlertUserLogObject' is deleted.
}

int AlertUserLog::alertId() const
{
    return d->alert_id;
}

void AlertUserLog::setAlertId(int alertId)
{
    d->alert_id = alertId;
}

int AlertUserLog::userId() const
{
    return d->user_id;
}

void AlertUserLog::setUserId(int userId)
{
    d->user_id = userId;
}

QString AlertUserLog::alertStatusCd() const
{
    return d->alert_status_cd;
}

void AlertUserLog::setAlertStatusCd(const QString &alertStatusCd)
{
    d->alert_status_cd = alertStatusCd;
}

QString AlertUserLog::userNote() const
{
    return d->user_note;
}

void AlertUserLog::setUserNote(const QString &userNote)
{
    d->user_note = userNote;
}

QDateTime AlertUserLog::createdAt() const
{
    return d->created_at;
}

QString AlertUserLog::createdBy() const
{
    return d->created_by;
}

void AlertUserLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AlertUserLog::updatedAt() const
{
    return d->updated_at;
}

QString AlertUserLog::updatedBy() const
{
    return d->updated_by;
}

void AlertUserLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAlertStatus AlertUserLog::refAlertStatusByalertStatusCd() const
{
 return RefAlertStatus::get(d->alert_status_cd);
}

UserApp AlertUserLog::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

Alert AlertUserLog::alertByalertId() const
{
 return Alert::get(d->alert_id);
}

AlertUserLog &AlertUserLog::operator=(const AlertUserLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AlertUserLog AlertUserLog::create(int alertId, int userId, const QString &alertStatusCd, const QString &userNote, const QString &createdBy, const QString &updatedBy)
{
    AlertUserLogObject obj;
    obj.alert_id = alertId;
    obj.user_id = userId;
    obj.alert_status_cd = alertStatusCd;
    obj.user_note = userNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AlertUserLog();
    }
    return AlertUserLog(obj);
}

AlertUserLog AlertUserLog::create(const QVariantMap &values)
{
    AlertUserLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AlertUserLog AlertUserLog::get(int alertId, int userId)
{
    TSqlORMapper<AlertUserLogObject> mapper;
    return AlertUserLog(mapper.findByPrimaryKey(QVariantList()<<QVariant(alertId)<<QVariant(userId)));
}

int AlertUserLog::count()
{
    TSqlORMapper<AlertUserLogObject> mapper;
    return mapper.findCount();
}

QList<AlertUserLog> AlertUserLog::getAll()
{
    return tfGetModelListByCriteria<AlertUserLog, AlertUserLogObject>();
}

TModelObject *AlertUserLog::modelData()
{
    return d.data();
}

const TModelObject *AlertUserLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AlertUserLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AlertUserLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AlertUserLog)
