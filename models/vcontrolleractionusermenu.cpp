#include <TreeFrogModel>
#include "vcontrolleractionusermenu.h"
#include "vcontrolleractionusermenuobject.h"

VControllerActionUserMenu::VControllerActionUserMenu()
    : TAbstractModel(), d(new VControllerActionUserMenuObject())
{
    d->user_id = 0;
}

VControllerActionUserMenu::VControllerActionUserMenu(const VControllerActionUserMenu &other)
    : TAbstractModel(), d(new VControllerActionUserMenuObject(*other.d))
{ }

VControllerActionUserMenu::VControllerActionUserMenu(const VControllerActionUserMenuObject &object)
    : TAbstractModel(), d(new VControllerActionUserMenuObject(object))
{ }

VControllerActionUserMenu::~VControllerActionUserMenu()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionUserMenuObject' is deleted.
}

QString VControllerActionUserMenu::controller() const
{
    return d->controller;
}

void VControllerActionUserMenu::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionUserMenu::action() const
{
    return d->action;
}

void VControllerActionUserMenu::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionUserMenu::userId() const
{
    return d->user_id;
}

void VControllerActionUserMenu::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionUserMenu &VControllerActionUserMenu::operator=(const VControllerActionUserMenu &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionUserMenu VControllerActionUserMenu::create(const QString &controller, const QString &action, int userId)
{
    VControllerActionUserMenuObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    if (!obj.create()) {
        return VControllerActionUserMenu();
    }
    return VControllerActionUserMenu(obj);
}

VControllerActionUserMenu VControllerActionUserMenu::create(const QVariantMap &values)
{
    VControllerActionUserMenu model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionUserMenu VControllerActionUserMenu::get(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionUserMenuObject::Controller, controller);
    cri.add(VControllerActionUserMenuObject::Action, action);
    cri.add(VControllerActionUserMenuObject::UserId, userId);
    TSqlORMapper<VControllerActionUserMenuObject> mapper;
    return VControllerActionUserMenu(mapper.findFirst(cri));
}

int VControllerActionUserMenu::count()
{
    TSqlORMapper<VControllerActionUserMenuObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionUserMenu> VControllerActionUserMenu::getAll()
{
    return tfGetModelListByCriteria<VControllerActionUserMenu, VControllerActionUserMenuObject>();
}

TModelObject *VControllerActionUserMenu::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionUserMenu::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionUserMenu &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionUserMenu &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionUserMenu)
