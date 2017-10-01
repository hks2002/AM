#include <TreeFrogModel>
#include "vcontrolleractionall.h"
#include "vcontrolleractionallobject.h"

VControllerActionAll::VControllerActionAll()
    : TAbstractModel(), d(new VControllerActionAllObject())
{ }

VControllerActionAll::VControllerActionAll(const VControllerActionAll &other)
    : TAbstractModel(), d(new VControllerActionAllObject(*other.d))
{ }

VControllerActionAll::VControllerActionAll(const VControllerActionAllObject &object)
    : TAbstractModel(), d(new VControllerActionAllObject(object))
{ }

VControllerActionAll::~VControllerActionAll()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionAllObject' is deleted.
}

QString VControllerActionAll::controller() const
{
    return d->controller;
}

void VControllerActionAll::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionAll::action() const
{
    return d->action;
}

void VControllerActionAll::setAction(const QString &action)
{
    d->action = action;
}

VControllerActionAll &VControllerActionAll::operator=(const VControllerActionAll &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionAll VControllerActionAll::create(const QString &controller, const QString &action)
{
    VControllerActionAllObject obj;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VControllerActionAll();
    }
    return VControllerActionAll(obj);
}

VControllerActionAll VControllerActionAll::create(const QVariantMap &values)
{
    VControllerActionAll model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionAll VControllerActionAll::get(const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VControllerActionAllObject::Controller, controller);
    cri.add(VControllerActionAllObject::Action, action);
    TSqlORMapper<VControllerActionAllObject> mapper;
    return VControllerActionAll(mapper.findFirst(cri));
}

int VControllerActionAll::count()
{
    TSqlORMapper<VControllerActionAllObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionAll> VControllerActionAll::getAll()
{
    return tfGetModelListByCriteria<VControllerActionAll, VControllerActionAllObject>();
}

TModelObject *VControllerActionAll::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionAll::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionAll &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionAll &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionAll)
