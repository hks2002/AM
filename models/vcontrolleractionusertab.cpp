#include <TreeFrogModel>
#include "vcontrolleractionusertab.h"
#include "vcontrolleractionusertabobject.h"

VControllerActionUserTab::VControllerActionUserTab()
    : TAbstractModel(), d(new VControllerActionUserTabObject())
{
    d->user_id = 0;
}

VControllerActionUserTab::VControllerActionUserTab(const VControllerActionUserTab &other)
    : TAbstractModel(), d(new VControllerActionUserTabObject(*other.d))
{ }

VControllerActionUserTab::VControllerActionUserTab(const VControllerActionUserTabObject &object)
    : TAbstractModel(), d(new VControllerActionUserTabObject(object))
{ }

VControllerActionUserTab::~VControllerActionUserTab()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionUserTabObject' is deleted.
}

QString VControllerActionUserTab::controller() const
{
    return d->controller;
}

void VControllerActionUserTab::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionUserTab::action() const
{
    return d->action;
}

void VControllerActionUserTab::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionUserTab::userId() const
{
    return d->user_id;
}

void VControllerActionUserTab::setUserId(int userId)
{
    d->user_id = userId;
}

VControllerActionUserTab &VControllerActionUserTab::operator=(const VControllerActionUserTab &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionUserTab VControllerActionUserTab::create(const QString &controller, const QString &action, int userId)
{
    VControllerActionUserTabObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    if (!obj.create()) {
        return VControllerActionUserTab();
    }
    return VControllerActionUserTab(obj);
}

VControllerActionUserTab VControllerActionUserTab::create(const QVariantMap &values)
{
    VControllerActionUserTab model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionUserTab VControllerActionUserTab::get(const QString &controller, const QString &action, int userId)
{
    TCriteria cri;
    cri.add(VControllerActionUserTabObject::Controller, controller);
    cri.add(VControllerActionUserTabObject::Action, action);
    cri.add(VControllerActionUserTabObject::UserId, userId);
    TSqlORMapper<VControllerActionUserTabObject> mapper;
    return VControllerActionUserTab(mapper.findFirst(cri));
}

int VControllerActionUserTab::count()
{
    TSqlORMapper<VControllerActionUserTabObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionUserTab> VControllerActionUserTab::getAll()
{
    return tfGetModelListByCriteria<VControllerActionUserTab, VControllerActionUserTabObject>();
}

TModelObject *VControllerActionUserTab::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionUserTab::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionUserTab &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionUserTab &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionUserTab)
