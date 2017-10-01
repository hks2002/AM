#include <TreeFrogModel>
#include "vcontrolleractionrole.h"
#include "vcontrolleractionroleobject.h"

VControllerActionRole::VControllerActionRole()
    : TAbstractModel(), d(new VControllerActionRoleObject())
{
    d->role_id = 0;
}

VControllerActionRole::VControllerActionRole(const VControllerActionRole &other)
    : TAbstractModel(), d(new VControllerActionRoleObject(*other.d))
{ }

VControllerActionRole::VControllerActionRole(const VControllerActionRoleObject &object)
    : TAbstractModel(), d(new VControllerActionRoleObject(object))
{ }

VControllerActionRole::~VControllerActionRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleObject' is deleted.
}

QString VControllerActionRole::controller() const
{
    return d->controller;
}

void VControllerActionRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRole::action() const
{
    return d->action;
}

void VControllerActionRole::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRole::roleId() const
{
    return d->role_id;
}

void VControllerActionRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

VControllerActionRole &VControllerActionRole::operator=(const VControllerActionRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRole VControllerActionRole::create(const QString &controller, const QString &action, int roleId)
{
    VControllerActionRoleObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    if (!obj.create()) {
        return VControllerActionRole();
    }
    return VControllerActionRole(obj);
}

VControllerActionRole VControllerActionRole::create(const QVariantMap &values)
{
    VControllerActionRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionRole VControllerActionRole::get(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleObject::Controller, controller);
    cri.add(VControllerActionRoleObject::Action, action);
    cri.add(VControllerActionRoleObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleObject> mapper;
    return VControllerActionRole(mapper.findFirst(cri));
}

int VControllerActionRole::count()
{
    TSqlORMapper<VControllerActionRoleObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRole> VControllerActionRole::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRole, VControllerActionRoleObject>(TCriteria());
}

TModelObject *VControllerActionRole::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRole)
