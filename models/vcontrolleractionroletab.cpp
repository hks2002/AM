#include <TreeFrogModel>
#include "vcontrolleractionroletab.h"
#include "vcontrolleractionroletabobject.h"

VControllerActionRoleTab::VControllerActionRoleTab()
    : TAbstractModel(), d(new VControllerActionRoleTabObject())
{
    d->role_id = 0;
}

VControllerActionRoleTab::VControllerActionRoleTab(const VControllerActionRoleTab &other)
    : TAbstractModel(), d(new VControllerActionRoleTabObject(*other.d))
{ }

VControllerActionRoleTab::VControllerActionRoleTab(const VControllerActionRoleTabObject &object)
    : TAbstractModel(), d(new VControllerActionRoleTabObject(object))
{ }

VControllerActionRoleTab::~VControllerActionRoleTab()
{
    // If the reference count becomes 0,
    // the shared data object 'VControllerActionRoleTabObject' is deleted.
}

QString VControllerActionRoleTab::controller() const
{
    return d->controller;
}

void VControllerActionRoleTab::setController(const QString &controller)
{
    d->controller = controller;
}

QString VControllerActionRoleTab::action() const
{
    return d->action;
}

void VControllerActionRoleTab::setAction(const QString &action)
{
    d->action = action;
}

int VControllerActionRoleTab::roleId() const
{
    return d->role_id;
}

void VControllerActionRoleTab::setRoleId(int roleId)
{
    d->role_id = roleId;
}

VControllerActionRoleTab &VControllerActionRoleTab::operator=(const VControllerActionRoleTab &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VControllerActionRoleTab VControllerActionRoleTab::create(const QString &controller, const QString &action, int roleId)
{
    VControllerActionRoleTabObject obj;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    if (!obj.create()) {
        return VControllerActionRoleTab();
    }
    return VControllerActionRoleTab(obj);
}

VControllerActionRoleTab VControllerActionRoleTab::create(const QVariantMap &values)
{
    VControllerActionRoleTab model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VControllerActionRoleTab VControllerActionRoleTab::get(const QString &controller, const QString &action, int roleId)
{
    TCriteria cri;
    cri.add(VControllerActionRoleTabObject::Controller, controller);
    cri.add(VControllerActionRoleTabObject::Action, action);
    cri.add(VControllerActionRoleTabObject::RoleId, roleId);
    TSqlORMapper<VControllerActionRoleTabObject> mapper;
    return VControllerActionRoleTab(mapper.findFirst(cri));
}

int VControllerActionRoleTab::count()
{
    TSqlORMapper<VControllerActionRoleTabObject> mapper;
    return mapper.findCount();
}

QList<VControllerActionRoleTab> VControllerActionRoleTab::getAll()
{
    return tfGetModelListByCriteria<VControllerActionRoleTab, VControllerActionRoleTabObject>();
}

TModelObject *VControllerActionRoleTab::modelData()
{
    return d.data();
}

const TModelObject *VControllerActionRoleTab::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleTab &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VControllerActionRoleTab &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VControllerActionRoleTab)
