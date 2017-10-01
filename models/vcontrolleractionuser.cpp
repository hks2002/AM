#include <TreeFrogModel>
#include "vcontrolleractionuser.h"
#include "vcontrolleractionuserobject.h"

VControllerActionUser::VControllerActionUser()
    : TAbstractModel(), d(new VControllerActionUserObject())
{
    d->user_id = 0;
}

VControllerActionUser::VControllerActionUser(const VControllerActionUser &other)
    : TAbstractModel(), d(new VControllerActionUserObject(*other.d))
{ }

VControllerActionUser::VControllerActionUser(const VControllerActionUserObject &object)
    : TAbstractModel(), d(new VControllerActionUserObject(object))
{ }

VControllerActionUser::~VControllerActionUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionUserObject' is deleted.
}

QString VControllerActionUser::controller() const
{
    return d->controller;
}

void VControllerActionUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionUser::action() const
{
    return d->action;
}

void VControllerActionUser::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionUser::userId() const
{
    return d->user_id;
}

void VControllerActionUser::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionUser &VControllerActionUser::operator=(const VControllerActionUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionUser VControllerActionUser::create(const QString &controller, const QString &action, int userId)
{
    VControllerActionUserObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    if (!obj.create()) {
        return VControllerActionUser();
    }
    return VControllerActionUser(obj);
}

VControllerActionUser VControllerActionUser::create(const QVariantMap &values)
{
    VControllerActionUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionUser VControllerActionUser::get(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionUserObject::Controller, controller);
    cri.add(VControllerActionUserObject::Action, action);
    cri.add(VControllerActionUserObject::UserId, userId);
    TSqlORMapper<VControllerActionUserObject> mapper;
    return VControllerActionUser(mapper.findFirst(cri));
}

int VControllerActionUser::count()
{
    TSqlORMapper<VControllerActionUserObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionUser> VControllerActionUser::getAll()
{
    return tfGetModelListByCriteria<VControllerActionUser, VControllerActionUserObject>(TCriteria());
}

TModelObject *VControllerActionUser::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionUser)
