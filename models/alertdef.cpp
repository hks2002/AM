#include <TreeFrogModel>
#include "alertdef.h"
#include "alertdefobject.h"

AlertDef::AlertDef()
    : TAbstractModel(), d(new AlertDefObject())
{
    d->alert_def_id = 0;
    d->priority = 0;
}

AlertDef::AlertDef(const AlertDef &other)
    : TAbstractModel(), d(new AlertDefObject(*other.d))
{ }

AlertDef::AlertDef(const AlertDefObject &object)
    : TAbstractModel(), d(new AlertDefObject(object))
{ }

AlertDef::~AlertDef()
{
    // If the reference count becomes 0,
    // the shared data object 'AlertDefObject' is deleted.
}

int AlertDef::alertDefId() const
{
    return d->alert_def_id;
}

QString AlertDef::alertName() const
{
    return d->alert_name;
}

void AlertDef::setAlertName(const QString &alertName)
{
    d->alert_name = alertName;
}

QString AlertDef::alertDesc() const
{
    return d->alert_desc;
}

void AlertDef::setAlertDesc(const QString &alertDesc)
{
    d->alert_desc = alertDesc;
}

bool AlertDef::activeBool() const
{
    return d->active_bool;
}

void AlertDef::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QString AlertDef::category() const
{
    return d->category;
}

void AlertDef::setCategory(const QString &category)
{
    d->category = category;
}

QString AlertDef::notifyCd() const
{
    return d->notify_cd;
}

void AlertDef::setNotifyCd(const QString &notifyCd)
{
    d->notify_cd = notifyCd;
}

int AlertDef::priority() const
{
    return d->priority;
}

void AlertDef::setPriority(int priority)
{
    d->priority = priority;
}

QString AlertDef::msgTitle() const
{
    return d->msg_title;
}

void AlertDef::setMsgTitle(const QString &msgTitle)
{
    d->msg_title = msgTitle;
}

QString AlertDef::message() const
{
    return d->message;
}

void AlertDef::setMessage(const QString &message)
{
    d->message = message;
}

QDateTime AlertDef::createdAt() const
{
    return d->created_at;
}

QString AlertDef::createdBy() const
{
    return d->created_by;
}

void AlertDef::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AlertDef::updatedAt() const
{
    return d->updated_at;
}

QString AlertDef::updatedBy() const
{
    return d->updated_by;
}

void AlertDef::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

AlertDef &AlertDef::operator=(const AlertDef &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AlertDef AlertDef::create(const QString &alertName, const QString &alertDesc, bool activeBool, const QString &category, const QString &notifyCd, int priority, const QString &msgTitle, const QString &message, const QString &createdBy, const QString &updatedBy)
{
    AlertDefObject obj;
    obj.alert_name = alertName;
    obj.alert_desc = alertDesc;
    obj.active_bool = activeBool;
    obj.category = category;
    obj.notify_cd = notifyCd;
    obj.priority = priority;
    obj.msg_title = msgTitle;
    obj.message = message;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AlertDef();
    }
    return AlertDef(obj);
}

AlertDef AlertDef::create(const QVariantMap &values)
{
    AlertDef model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AlertDef AlertDef::get(int alertDefId)
{
    TSqlORMapper<AlertDefObject> mapper;
    return AlertDef(mapper.findByPrimaryKey(alertDefId));
}

int AlertDef::count()
{
    TSqlORMapper<AlertDefObject> mapper;
    return mapper.findCount();
}

QList<AlertDef> AlertDef::getAll()
{
    return tfGetModelListByCriteria<AlertDef, AlertDefObject>();
}

TModelObject *AlertDef::modelData()
{
    return d.data();
}

const TModelObject *AlertDef::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AlertDef &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AlertDef &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AlertDef)
