#include <TreeFrogModel>
#include "vcontrolleractionuserbutton.h"
#include "vcontrolleractionuserbuttonobject.h"

VControllerActionUserButton::VControllerActionUserButton()
    : TAbstractModel(), d(new VControllerActionUserButtonObject())
{
    d->user_id = 0;
}

VControllerActionUserButton::VControllerActionUserButton(const VControllerActionUserButton &other)
    : TAbstractModel(), d(new VControllerActionUserButtonObject(*other.d))
{ }

VControllerActionUserButton::VControllerActionUserButton(const VControllerActionUserButtonObject &object)
    : TAbstractModel(), d(new VControllerActionUserButtonObject(object))
{ }

VControllerActionUserButton::~VControllerActionUserButton()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionUserButtonObject' is deleted.
}

QString VControllerActionUserButton::controller() const
{
    return d->controller;
}

void VControllerActionUserButton::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionUserButton::action() const
{
    return d->action;
}

void VControllerActionUserButton::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionUserButton::userId() const
{
    return d->user_id;
}

void VControllerActionUserButton::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionUserButton &VControllerActionUserButton::operator=(const VControllerActionUserButton &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionUserButton VControllerActionUserButton::create(const QString &controller, const QString &action, int userId)
{
    VControllerActionUserButtonObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    if (!obj.create()) {
        return VControllerActionUserButton();
    }
    return VControllerActionUserButton(obj);
}

VControllerActionUserButton VControllerActionUserButton::create(const QVariantMap &values)
{
    VControllerActionUserButton model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionUserButton VControllerActionUserButton::get(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionUserButtonObject::Controller, controller);
    cri.add(VControllerActionUserButtonObject::Action, action);
    cri.add(VControllerActionUserButtonObject::UserId, userId);
    TSqlORMapper<VControllerActionUserButtonObject> mapper;
    return VControllerActionUserButton(mapper.findFirst(cri));
}

int VControllerActionUserButton::count()
{
    TSqlORMapper<VControllerActionUserButtonObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionUserButton> VControllerActionUserButton::getAll()
{
    return tfGetModelListByCriteria<VControllerActionUserButton, VControllerActionUserButtonObject>();
}

TModelObject *VControllerActionUserButton::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionUserButton::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionUserButton &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionUserButton &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionUserButton)
