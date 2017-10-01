#include <TreeFrogModel>
#include "vcontrolleraction.h"
#include "vcontrolleractionobject.h"

VControllerAction::VControllerAction()
    : TAbstractModel(), d(new VControllerActionObject())
{ }

VControllerAction::VControllerAction(const VControllerAction &other)
    : TAbstractModel(), d(new VControllerActionObject(*other.d))
{ }

VControllerAction::VControllerAction(const VControllerActionObject &object)
    : TAbstractModel(), d(new VControllerActionObject(object))
{ }

VControllerAction::~VControllerAction()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionObject' is deleted.
}

QString VControllerAction::controller() const
{
    return d->controller;
}

void VControllerAction::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerAction::action() const
{
    return d->action;
}

void VControllerAction::setAction(const QString &action)
{
    d->action = action;
}

VControllerAction &VControllerAction::operator=(const VControllerAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerAction VControllerAction::create(const QString &controller, const QString &action)
{
    VControllerActionObject obj;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VControllerAction();
    }
    return VControllerAction(obj);
}

VControllerAction VControllerAction::create(const QVariantMap &values)
{
    VControllerAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerAction VControllerAction::get(const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VControllerActionObject::Controller, controller);
    cri.add(VControllerActionObject::Action, action);
    TSqlORMapper<VControllerActionObject> mapper;
    return VControllerAction(mapper.findFirst(cri));
}

int VControllerAction::count()
{
    TSqlORMapper<VControllerActionObject> mapper;
    return mapper.findCount();
}

QList<VControllerAction> VControllerAction::getAll()
{
    return tfGetModelListByCriteria<VControllerAction, VControllerActionObject>(TCriteria());
}

TModelObject *VControllerAction::modelData()
{
    return d.data();
}

const TModelObject *VControllerAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerAction)
