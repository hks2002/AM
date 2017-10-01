#include <TreeFrogModel>
#include "alertdefrole.h"
#include "alertdefroleobject.h"
#include "roleapp.h"
#include "alertdef.h"

AlertDefRole::AlertDefRole()
    : TAbstractModel(), d(new AlertDefRoleObject())
{
    d->alert_def_id = 0;
    d->role_id = 0;
}

AlertDefRole::AlertDefRole(const AlertDefRole &other)
    : TAbstractModel(), d(new AlertDefRoleObject(*other.d))
{ }

AlertDefRole::AlertDefRole(const AlertDefRoleObject &object)
    : TAbstractModel(), d(new AlertDefRoleObject(object))
{ }

AlertDefRole::~AlertDefRole()
{
    // If the reference count becomes 0,
    // the shared data object 'AlertDefRoleObject' is deleted.
}

int AlertDefRole::alertDefId() const
{
    return d->alert_def_id;
}

void AlertDefRole::setAlertDefId(int alertDefId)
{
    d->alert_def_id = alertDefId;
}

int AlertDefRole::roleId() const
{
    return d->role_id;
}

void AlertDefRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

bool AlertDefRole::activeBool() const
{
    return d->active_bool;
}

void AlertDefRole::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime AlertDefRole::createdAt() const
{
    return d->created_at;
}

QString AlertDefRole::createdBy() const
{
    return d->created_by;
}

void AlertDefRole::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AlertDefRole::updatedAt() const
{
    return d->updated_at;
}

QString AlertDefRole::updatedBy() const
{
    return d->updated_by;
}

void AlertDefRole::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RoleApp AlertDefRole::roleAppByroleId() const
{
 return RoleApp::get(d->role_id);
}

AlertDef AlertDefRole::alertDefByalertDefId() const
{
 return AlertDef::get(d->alert_def_id);
}

AlertDefRole &AlertDefRole::operator=(const AlertDefRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AlertDefRole AlertDefRole::create(int alertDefId, int roleId, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    AlertDefRoleObject obj;
    obj.alert_def_id = alertDefId;
    obj.role_id = roleId;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AlertDefRole();
    }
    return AlertDefRole(obj);
}

AlertDefRole AlertDefRole::create(const QVariantMap &values)
{
    AlertDefRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AlertDefRole AlertDefRole::get(int alertDefId, int roleId)
{
    TSqlORMapper<AlertDefRoleObject> mapper;
    return AlertDefRole(mapper.findByPrimaryKey(QVariantList()<<QVariant(alertDefId)<<QVariant(roleId)));
}

int AlertDefRole::count()
{
    TSqlORMapper<AlertDefRoleObject> mapper;
    return mapper.findCount();
}

QList<AlertDefRole> AlertDefRole::getAll()
{
    return tfGetModelListByCriteria<AlertDefRole, AlertDefRoleObject>();
}

TModelObject *AlertDefRole::modelData()
{
    return d.data();
}

const TModelObject *AlertDefRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AlertDefRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AlertDefRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AlertDefRole)
