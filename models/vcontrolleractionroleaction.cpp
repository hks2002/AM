#include <TreeFrogModel>
#include "vcontrolleractionroleaction.h"
#include "vcontrolleractionroleactionobject.h"

VControllerActionRoleAction::VControllerActionRoleAction()
    : TAbstractModel(), d(new VControllerActionRoleActionObject())
{
    d->role_id = 0;
}

VControllerActionRoleAction::VControllerActionRoleAction(const VControllerActionRoleAction &other)
    : TAbstractModel(), d(new VControllerActionRoleActionObject(*other.d))
{ }

VControllerActionRoleAction::VControllerActionRoleAction(const VControllerActionRoleActionObject &object)
    : TAbstractModel(), d(new VControllerActionRoleActionObject(object))
{ }

VControllerActionRoleAction::~VControllerActionRoleAction()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleActionObject' is deleted.
}

QString VControllerActionRoleAction::controller() const
{
    return d->controller;
}

void VControllerActionRoleAction::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRoleAction::action() const
{
    return d->action;
}

void VControllerActionRoleAction::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRoleAction::roleId() const
{
    return d->role_id;
}

void VControllerActionRoleAction::setRoleId(int roleId)
{
    d->role_id = roleId;
}

VControllerActionRoleAction &VControllerActionRoleAction::operator=(const VControllerActionRoleAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRoleAction VControllerActionRoleAction::create(const QString &controller, const QString &action, int roleId)
{
    VControllerActionRoleActionObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    if (!obj.create()) {
        return VControllerActionRoleAction();
    }
    return VControllerActionRoleAction(obj);
}

VControllerActionRoleAction VControllerActionRoleAction::create(const QVariantMap &values)
{
    VControllerActionRoleAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionRoleAction VControllerActionRoleAction::get(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleActionObject::Controller, controller);
    cri.add(VControllerActionRoleActionObject::Action, action);
    cri.add(VControllerActionRoleActionObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleActionObject> mapper;
    return VControllerActionRoleAction(mapper.findFirst(cri));
}

int VControllerActionRoleAction::count()
{
    TSqlORMapper<VControllerActionRoleActionObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRoleAction> VControllerActionRoleAction::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRoleAction, VControllerActionRoleActionObject>();
}

TModelObject *VControllerActionRoleAction::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRoleAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRoleAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRoleAction)
