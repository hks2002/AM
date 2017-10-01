#include <TreeFrogModel>
#include "vcontrolleractionroleuser.h"
#include "vcontrolleractionroleuserobject.h"

VControllerActionRoleUser::VControllerActionRoleUser()
    : TAbstractModel(), d(new VControllerActionRoleUserObject())
{
    d->role_id = 0;
    d->user_id = 0;
}

VControllerActionRoleUser::VControllerActionRoleUser(const VControllerActionRoleUser &other)
    : TAbstractModel(), d(new VControllerActionRoleUserObject(*other.d))
{ }

VControllerActionRoleUser::VControllerActionRoleUser(const VControllerActionRoleUserObject &object)
    : TAbstractModel(), d(new VControllerActionRoleUserObject(object))
{ }

VControllerActionRoleUser::~VControllerActionRoleUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleUserObject' is deleted.
}

QString VControllerActionRoleUser::controller() const
{
    return d->controller;
}

void VControllerActionRoleUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRoleUser::action() const
{
    return d->action;
}

void VControllerActionRoleUser::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRoleUser::roleId() const
{
    return d->role_id;
}

void VControllerActionRoleUser::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VControllerActionRoleUser::userId() const
{
    return d->user_id;
}

void VControllerActionRoleUser::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionRoleUser &VControllerActionRoleUser::operator=(const VControllerActionRoleUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRoleUser VControllerActionRoleUser::create(const QString &controller, const QString &action, int roleId, int userId)
{
    VControllerActionRoleUserObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    obj.user_id = userId;

    if (!obj.create()) {
        return VControllerActionRoleUser();
    }

    return VControllerActionRoleUser(obj);
}

VControllerActionRoleUser VControllerActionRoleUser::create(const QVariantMap &values)
{
    VControllerActionRoleUser model;
    model.setProperties(values);

    if (!model.d->create()) {
        model.d->clear();
    }

    return model;
}

VControllerActionRoleUser VControllerActionRoleUser::get(const QString &controller, const QString &action, int roleId, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleUserObject::Controller, controller);
    cri.add(VControllerActionRoleUserObject::Action, action);
    cri.add(VControllerActionRoleUserObject::RoleId, roleId);
    cri.add(VControllerActionRoleUserObject::UserId, userId);
    TSqlORMapper<VControllerActionRoleUserObject> mapper;
    return VControllerActionRoleUser(mapper.findFirst(cri));
}

VControllerActionRoleUser VControllerActionRoleUser::getByRole(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleUserObject::Controller, controller);
    cri.add(VControllerActionRoleUserObject::Action, action);
    cri.add(VControllerActionRoleUserObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleUserObject> mapper;
    return VControllerActionRoleUser(mapper.findFirst(cri));
}

VControllerActionRoleUser VControllerActionRoleUser::getByUser(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleUserObject::Controller, controller);
    cri.add(VControllerActionRoleUserObject::Action, action);
    cri.add(VControllerActionRoleUserObject::UserId, userId);
    TSqlORMapper<VControllerActionRoleUserObject> mapper;
    return VControllerActionRoleUser(mapper.findFirst(cri));
}

int VControllerActionRoleUser::count()
{
    TSqlORMapper<VControllerActionRoleUserObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRoleUser> VControllerActionRoleUser::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRoleUser, VControllerActionRoleUserObject>();
}

TModelObject *VControllerActionRoleUser::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRoleUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRoleUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRoleUser)
