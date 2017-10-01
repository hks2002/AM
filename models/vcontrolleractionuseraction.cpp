#include <TreeFrogModel>
#include "vcontrolleractionuseraction.h"
#include "vcontrolleractionuseractionobject.h"

VControllerActionUserAction::VControllerActionUserAction()
    : TAbstractModel(), d(new VControllerActionUserActionObject())
{
    d->user_id = 0;
}

VControllerActionUserAction::VControllerActionUserAction(const VControllerActionUserAction &other)
    : TAbstractModel(), d(new VControllerActionUserActionObject(*other.d))
{ }

VControllerActionUserAction::VControllerActionUserAction(const VControllerActionUserActionObject &object)
    : TAbstractModel(), d(new VControllerActionUserActionObject(object))
{ }

VControllerActionUserAction::~VControllerActionUserAction()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionUserActionObject' is deleted.
}

QString VControllerActionUserAction::controller() const
{
    return d->controller;
}

void VControllerActionUserAction::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionUserAction::action() const
{
    return d->action;
}

void VControllerActionUserAction::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionUserAction::userId() const
{
    return d->user_id;
}

void VControllerActionUserAction::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionUserAction &VControllerActionUserAction::operator=(const VControllerActionUserAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionUserAction VControllerActionUserAction::create(const QString &controller, const QString &action, int userId)
{
    VControllerActionUserActionObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    if (!obj.create()) {
        return VControllerActionUserAction();
    }
    return VControllerActionUserAction(obj);
}

VControllerActionUserAction VControllerActionUserAction::create(const QVariantMap &values)
{
    VControllerActionUserAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionUserAction VControllerActionUserAction::get(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionUserActionObject::Controller, controller);
    cri.add(VControllerActionUserActionObject::Action, action);
    cri.add(VControllerActionUserActionObject::UserId, userId);
    TSqlORMapper<VControllerActionUserActionObject> mapper;
    return VControllerActionUserAction(mapper.findFirst(cri));
}

int VControllerActionUserAction::count()
{
    TSqlORMapper<VControllerActionUserActionObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionUserAction> VControllerActionUserAction::getAll()
{
    return tfGetModelListByCriteria<VControllerActionUserAction, VControllerActionUserActionObject>();
}

TModelObject *VControllerActionUserAction::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionUserAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionUserAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionUserAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionUserAction)
