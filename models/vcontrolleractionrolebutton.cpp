#include <TreeFrogModel>
#include "vcontrolleractionrolebutton.h"
#include "vcontrolleractionrolebuttonobject.h"

VControllerActionRoleButton::VControllerActionRoleButton()
    : TAbstractModel(), d(new VControllerActionRoleButtonObject())
{
    d->role_id = 0;
}

VControllerActionRoleButton::VControllerActionRoleButton(const VControllerActionRoleButton &other)
    : TAbstractModel(), d(new VControllerActionRoleButtonObject(*other.d))
{ }

VControllerActionRoleButton::VControllerActionRoleButton(const VControllerActionRoleButtonObject &object)
    : TAbstractModel(), d(new VControllerActionRoleButtonObject(object))
{ }

VControllerActionRoleButton::~VControllerActionRoleButton()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleButtonObject' is deleted.
}

QString VControllerActionRoleButton::controller() const
{
    return d->controller;
}

void VControllerActionRoleButton::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRoleButton::action() const
{
    return d->action;
}

void VControllerActionRoleButton::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRoleButton::roleId() const
{
    return d->role_id;
}

void VControllerActionRoleButton::setRoleId(int roleId)
{
    d->role_id = roleId;
}

VControllerActionRoleButton &VControllerActionRoleButton::operator=(const VControllerActionRoleButton &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRoleButton VControllerActionRoleButton::create(const QString &controller, const QString &action, int roleId)
{
    VControllerActionRoleButtonObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    if (!obj.create()) {
        return VControllerActionRoleButton();
    }
    return VControllerActionRoleButton(obj);
}

VControllerActionRoleButton VControllerActionRoleButton::create(const QVariantMap &values)
{
    VControllerActionRoleButton model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionRoleButton VControllerActionRoleButton::get(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleButtonObject::Controller, controller);
    cri.add(VControllerActionRoleButtonObject::Action, action);
    cri.add(VControllerActionRoleButtonObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleButtonObject> mapper;
    return VControllerActionRoleButton(mapper.findFirst(cri));
}

int VControllerActionRoleButton::count()
{
    TSqlORMapper<VControllerActionRoleButtonObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRoleButton> VControllerActionRoleButton::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRoleButton, VControllerActionRoleButtonObject>();
}

TModelObject *VControllerActionRoleButton::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRoleButton::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleButton &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRoleButton &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRoleButton)
