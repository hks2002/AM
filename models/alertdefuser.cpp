#include <TreeFrogModel>
#include "alertdefuser.h"
#include "alertdefuserobject.h"
#include "userapp.h"
#include "alertdef.h"

AlertDefUser::AlertDefUser()
    : TAbstractModel(), d(new AlertDefUserObject())
{
    d->alert_def_id = 0;
    d->user_id = 0;
}

AlertDefUser::AlertDefUser(const AlertDefUser &other)
    : TAbstractModel(), d(new AlertDefUserObject(*other.d))
{ }

AlertDefUser::AlertDefUser(const AlertDefUserObject &object)
    : TAbstractModel(), d(new AlertDefUserObject(object))
{ }

AlertDefUser::~AlertDefUser()
{
    // If the reference count becomes 0,
    // the shared data object 'AlertDefUserObject' is deleted.
}

int AlertDefUser::alertDefId() const
{
    return d->alert_def_id;
}

void AlertDefUser::setAlertDefId(int alertDefId)
{
    d->alert_def_id = alertDefId;
}

int AlertDefUser::userId() const
{
    return d->user_id;
}

void AlertDefUser::setUserId(int userId)
{
    d->user_id = userId;
}

bool AlertDefUser::activeBool() const
{
    return d->active_bool;
}

void AlertDefUser::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime AlertDefUser::createdAt() const
{
    return d->created_at;
}

QString AlertDefUser::createdBy() const
{
    return d->created_by;
}

void AlertDefUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AlertDefUser::updatedAt() const
{
    return d->updated_at;
}

QString AlertDefUser::updatedBy() const
{
    return d->updated_by;
}

void AlertDefUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp AlertDefUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

AlertDef AlertDefUser::alertDefByalertDefId() const
{
 return AlertDef::get(d->alert_def_id);
}

AlertDefUser &AlertDefUser::operator=(const AlertDefUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AlertDefUser AlertDefUser::create(int alertDefId, int userId, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    AlertDefUserObject obj;
    obj.alert_def_id = alertDefId;
    obj.user_id = userId;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AlertDefUser();
    }
    return AlertDefUser(obj);
}

AlertDefUser AlertDefUser::create(const QVariantMap &values)
{
    AlertDefUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AlertDefUser AlertDefUser::get(int alertDefId, int userId)
{
    TSqlORMapper<AlertDefUserObject> mapper;
    return AlertDefUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(alertDefId)<<QVariant(userId)));
}

int AlertDefUser::count()
{
    TSqlORMapper<AlertDefUserObject> mapper;
    return mapper.findCount();
}

QList<AlertDefUser> AlertDefUser::getAll()
{
    return tfGetModelListByCriteria<AlertDefUser, AlertDefUserObject>();
}

TModelObject *AlertDefUser::modelData()
{
    return d.data();
}

const TModelObject *AlertDefUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AlertDefUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AlertDefUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AlertDefUser)
