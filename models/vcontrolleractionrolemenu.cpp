#include <TreeFrogModel>
#include "vcontrolleractionrolemenu.h"
#include "vcontrolleractionrolemenuobject.h"

VControllerActionRoleMenu::VControllerActionRoleMenu()
    : TAbstractModel(), d(new VControllerActionRoleMenuObject())
{
    d->role_id = 0;
}

VControllerActionRoleMenu::VControllerActionRoleMenu(const VControllerActionRoleMenu &other)
    : TAbstractModel(), d(new VControllerActionRoleMenuObject(*other.d))
{ }

VControllerActionRoleMenu::VControllerActionRoleMenu(const VControllerActionRoleMenuObject &object)
    : TAbstractModel(), d(new VControllerActionRoleMenuObject(object))
{ }

VControllerActionRoleMenu::~VControllerActionRoleMenu()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleMenuObject' is deleted.
}

QString VControllerActionRoleMenu::controller() const
{
    return d->controller;
}

void VControllerActionRoleMenu::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRoleMenu::action() const
{
    return d->action;
}

void VControllerActionRoleMenu::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRoleMenu::roleId() const
{
    return d->role_id;
}

void VControllerActionRoleMenu::setRoleId(int roleId)
{
    d->role_id = roleId;
}

VControllerActionRoleMenu &VControllerActionRoleMenu::operator=(const VControllerActionRoleMenu &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRoleMenu VControllerActionRoleMenu::create(const QString &controller, const QString &action, int roleId)
{
    VControllerActionRoleMenuObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    if (!obj.create()) {
        return VControllerActionRoleMenu();
    }
    return VControllerActionRoleMenu(obj);
}

VControllerActionRoleMenu VControllerActionRoleMenu::create(const QVariantMap &values)
{
    VControllerActionRoleMenu model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionRoleMenu VControllerActionRoleMenu::get(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleMenuObject::Controller, controller);
    cri.add(VControllerActionRoleMenuObject::Action, action);
    cri.add(VControllerActionRoleMenuObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleMenuObject> mapper;
    return VControllerActionRoleMenu(mapper.findFirst(cri));
}

int VControllerActionRoleMenu::count()
{
    TSqlORMapper<VControllerActionRoleMenuObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRoleMenu> VControllerActionRoleMenu::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRoleMenu, VControllerActionRoleMenuObject>();
}

TModelObject *VControllerActionRoleMenu::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRoleMenu::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleMenu &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRoleMenu &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRoleMenu)
