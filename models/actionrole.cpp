#include <TreeFrogModel>
#include "actionrole.h"
#include "actionroleobject.h"
#include "roleapp.h"
#include "actionapp.h"

ActionRole::ActionRole()
    : TAbstractModel(), d(new ActionRoleObject())
{
    d->action_id = 0;
    d->role_id = 0;
}

ActionRole::ActionRole(const ActionRole &other)
    : TAbstractModel(), d(new ActionRoleObject(*other.d))
{ }

ActionRole::ActionRole(const ActionRoleObject &object)
    : TAbstractModel(), d(new ActionRoleObject(object))
{ }

ActionRole::~ActionRole()
{
    // If the reference count becomes 0,
    // the shared data object 'ActionRoleObject' is deleted.
}

int ActionRole::actionId() const
{
    return d->action_id;
}

void ActionRole::setActionId(int actionId)
{
    d->action_id = actionId;
}

int ActionRole::roleId() const
{
    return d->role_id;
}

void ActionRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

QDateTime ActionRole::createdAt() const
{
    return d->created_at;
}

QString ActionRole::createdBy() const
{
    return d->created_by;
}

void ActionRole::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ActionRole::updatedAt() const
{
    return d->updated_at;
}

QString ActionRole::updatedBy() const
{
    return d->updated_by;
}

void ActionRole::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RoleApp ActionRole::roleAppByroleId() const
{
 return RoleApp::get(d->role_id);
}

ActionApp ActionRole::actionAppByactionId() const
{
 return ActionApp::get(d->action_id);
}

ActionRole &ActionRole::operator=(const ActionRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ActionRole ActionRole::create(int actionId, int roleId, const QString &createdBy, const QString &updatedBy)
{
    ActionRoleObject obj;
    obj.action_id = actionId;
    obj.role_id = roleId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ActionRole();
    }
    return ActionRole(obj);
}

ActionRole ActionRole::create(const QVariantMap &values)
{
    ActionRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ActionRole ActionRole::get(int actionId, int roleId)
{
    TSqlORMapper<ActionRoleObject> mapper;
    return ActionRole(mapper.findByPrimaryKey(QVariantList()<<QVariant(actionId)<<QVariant(roleId)));
}

int ActionRole::count()
{
    TSqlORMapper<ActionRoleObject> mapper;
    return mapper.findCount();
}

QList<ActionRole> ActionRole::getAll()
{
    return tfGetModelListByCriteria<ActionRole, ActionRoleObject>();
}

TModelObject *ActionRole::modelData()
{
    return d.data();
}

const TModelObject *ActionRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ActionRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ActionRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ActionRole)
