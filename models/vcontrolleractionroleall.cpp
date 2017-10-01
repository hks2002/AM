#include <TreeFrogModel>
#include "vcontrolleractionroleall.h"
#include "vcontrolleractionroleallobject.h"

VControllerActionRoleAll::VControllerActionRoleAll()
    : TAbstractModel(), d(new VControllerActionRoleAllObject())
{
    d->role_id = 0;
}

VControllerActionRoleAll::VControllerActionRoleAll(const VControllerActionRoleAll &other)
    : TAbstractModel(), d(new VControllerActionRoleAllObject(*other.d))
{ }

VControllerActionRoleAll::VControllerActionRoleAll(const VControllerActionRoleAllObject &object)
    : TAbstractModel(), d(new VControllerActionRoleAllObject(object))
{ }

VControllerActionRoleAll::~VControllerActionRoleAll()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleAllObject' is deleted.
}

QString VControllerActionRoleAll::controller() const
{
    return d->controller;
}

void VControllerActionRoleAll::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRoleAll::action() const
{
    return d->action;
}

void VControllerActionRoleAll::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRoleAll::roleId() const
{
    return d->role_id;
}

void VControllerActionRoleAll::setRoleId(int roleId)
{
    d->role_id = roleId;
}

VControllerActionRoleAll &VControllerActionRoleAll::operator=(const VControllerActionRoleAll &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRoleAll VControllerActionRoleAll::create(const QString &controller, const QString &action, int roleId)
{
    VControllerActionRoleAllObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    if (!obj.create()) {
        return VControllerActionRoleAll();
    }
    return VControllerActionRoleAll(obj);
}

VControllerActionRoleAll VControllerActionRoleAll::create(const QVariantMap &values)
{
    VControllerActionRoleAll model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionRoleAll VControllerActionRoleAll::get(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleAllObject::Controller, controller);
    cri.add(VControllerActionRoleAllObject::Action, action);
    cri.add(VControllerActionRoleAllObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleAllObject> mapper;
    return VControllerActionRoleAll(mapper.findFirst(cri));
}

int VControllerActionRoleAll::count()
{
    TSqlORMapper<VControllerActionRoleAllObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRoleAll> VControllerActionRoleAll::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRoleAll, VControllerActionRoleAllObject>();
}

TModelObject *VControllerActionRoleAll::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRoleAll::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleAll &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRoleAll &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRoleAll)
