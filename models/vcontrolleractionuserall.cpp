#include <TreeFrogModel>
#include "vcontrolleractionuserall.h"
#include "vcontrolleractionuserallobject.h"

VControllerActionUserAll::VControllerActionUserAll()
    : TAbstractModel(), d(new VControllerActionUserAllObject())
{
    d->user_id = 0;
}

VControllerActionUserAll::VControllerActionUserAll(const VControllerActionUserAll &other)
    : TAbstractModel(), d(new VControllerActionUserAllObject(*other.d))
{ }

VControllerActionUserAll::VControllerActionUserAll(const VControllerActionUserAllObject &object)
    : TAbstractModel(), d(new VControllerActionUserAllObject(object))
{ }

VControllerActionUserAll::~VControllerActionUserAll()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionUserAllObject' is deleted.
}

QString VControllerActionUserAll::controller() const
{
    return d->controller;
}

void VControllerActionUserAll::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionUserAll::action() const
{
    return d->action;
}

void VControllerActionUserAll::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionUserAll::userId() const
{
    return d->user_id;
}

void VControllerActionUserAll::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionUserAll &VControllerActionUserAll::operator=(const VControllerActionUserAll &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionUserAll VControllerActionUserAll::create(const QString &controller, const QString &action, int userId)
{
    VControllerActionUserAllObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    if (!obj.create()) {
        return VControllerActionUserAll();
    }
    return VControllerActionUserAll(obj);
}

VControllerActionUserAll VControllerActionUserAll::create(const QVariantMap &values)
{
    VControllerActionUserAll model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionUserAll VControllerActionUserAll::get(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionUserAllObject::Controller, controller);
    cri.add(VControllerActionUserAllObject::Action, action);
    cri.add(VControllerActionUserAllObject::UserId, userId);
    TSqlORMapper<VControllerActionUserAllObject> mapper;
    return VControllerActionUserAll(mapper.findFirst(cri));
}

int VControllerActionUserAll::count()
{
    TSqlORMapper<VControllerActionUserAllObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionUserAll> VControllerActionUserAll::getAll()
{
    return tfGetModelListByCriteria<VControllerActionUserAll, VControllerActionUserAllObject>();
}

TModelObject *VControllerActionUserAll::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionUserAll::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionUserAll &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionUserAll &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionUserAll)
