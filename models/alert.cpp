#include <TreeFrogModel>
#include "alert.h"
#include "alertobject.h"
#include "refalertstatus.h"
#include "alertdef.h"

Alert::Alert()
    : TAbstractModel(), d(new AlertObject())
{
    d->alert_id = 0;
    d->alert_def_id = 0;
}

Alert::Alert(const Alert &other)
    : TAbstractModel(), d(new AlertObject(*other.d))
{ }

Alert::Alert(const AlertObject &object)
    : TAbstractModel(), d(new AlertObject(object))
{ }

Alert::~Alert()
{
    // If the reference count becomes 0,
    // the shared data object 'AlertObject' is deleted.
}

int Alert::alertId() const
{
    return d->alert_id;
}

int Alert::alertDefId() const
{
    return d->alert_def_id;
}

void Alert::setAlertDefId(int alertDefId)
{
    d->alert_def_id = alertDefId;
}

QString Alert::alertStatusCd() const
{
    return d->alert_status_cd;
}

void Alert::setAlertStatusCd(const QString &alertStatusCd)
{
    d->alert_status_cd = alertStatusCd;
}

QString Alert::msgTitle() const
{
    return d->msg_title;
}

void Alert::setMsgTitle(const QString &msgTitle)
{
    d->msg_title = msgTitle;
}

QString Alert::message() const
{
    return d->message;
}

void Alert::setMessage(const QString &message)
{
    d->message = message;
}

QDateTime Alert::createdAt() const
{
    return d->created_at;
}

QString Alert::createdBy() const
{
    return d->created_by;
}

void Alert::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Alert::updatedAt() const
{
    return d->updated_at;
}

QString Alert::updatedBy() const
{
    return d->updated_by;
}

void Alert::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefAlertStatus Alert::refAlertStatusByalertStatusCd() const
{
 return RefAlertStatus::get(d->alert_status_cd);
}

AlertDef Alert::alertDefByalertDefId() const
{
 return AlertDef::get(d->alert_def_id);
}

Alert &Alert::operator=(const Alert &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Alert Alert::create(int alertDefId, const QString &alertStatusCd, const QString &msgTitle, const QString &message, const QString &createdBy, const QString &updatedBy)
{
    AlertObject obj;
    obj.alert_def_id = alertDefId;
    obj.alert_status_cd = alertStatusCd;
    obj.msg_title = msgTitle;
    obj.message = message;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Alert();
    }
    return Alert(obj);
}

Alert Alert::create(const QVariantMap &values)
{
    Alert model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Alert Alert::get(int alertId)
{
    TSqlORMapper<AlertObject> mapper;
    return Alert(mapper.findByPrimaryKey(alertId));
}

int Alert::count()
{
    TSqlORMapper<AlertObject> mapper;
    return mapper.findCount();
}

QList<Alert> Alert::getAll()
{
    return tfGetModelListByCriteria<Alert, AlertObject>();
}

TModelObject *Alert::modelData()
{
    return d.data();
}

const TModelObject *Alert::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Alert &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Alert &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Alert)
