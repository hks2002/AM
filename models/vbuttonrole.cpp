#include <TreeFrogModel>
#include "vbuttonrole.h"
#include "vbuttonroleobject.h"

VButtonRole::VButtonRole()
    : TAbstractModel(), d(new VButtonRoleObject())
{
    d->button_id = 0;
    d->role_id = 0;
    d->todo_list_order = 0;
    d->button_order = 0;
}

VButtonRole::VButtonRole(const VButtonRole &other)
    : TAbstractModel(), d(new VButtonRoleObject(*other.d))
{ }

VButtonRole::VButtonRole(const VButtonRoleObject &object)
    : TAbstractModel(), d(new VButtonRoleObject(object))
{ }

VButtonRole::~VButtonRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VButtonRoleObject' is deleted.
}

int VButtonRole::buttonId() const
{
    return d->button_id;
}

void VButtonRole::setButtonId(int buttonId)
{
    d->button_id = buttonId;
}

QString VButtonRole::buttonCd() const
{
    return d->button_cd;
}

void VButtonRole::setButtonCd(const QString &buttonCd)
{
    d->button_cd = buttonCd;
}

QString VButtonRole::buttonNameZh() const
{
    return d->button_name_zh;
}

void VButtonRole::setButtonNameZh(const QString &buttonNameZh)
{
    d->button_name_zh = buttonNameZh;
}

QString VButtonRole::buttonNameEn() const
{
    return d->button_name_en;
}

void VButtonRole::setButtonNameEn(const QString &buttonNameEn)
{
    d->button_name_en = buttonNameEn;
}

QString VButtonRole::buttonTooltip() const
{
    return d->button_tooltip;
}

void VButtonRole::setButtonTooltip(const QString &buttonTooltip)
{
    d->button_tooltip = buttonTooltip;
}

QString VButtonRole::buttonDesc() const
{
    return d->button_desc;
}

void VButtonRole::setButtonDesc(const QString &buttonDesc)
{
    d->button_desc = buttonDesc;
}

QString VButtonRole::controller() const
{
    return d->controller;
}

void VButtonRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VButtonRole::action() const
{
    return d->action;
}

void VButtonRole::setAction(const QString &action)
{
    d->action = action;
}

int VButtonRole::roleId() const
{
    return d->role_id;
}

void VButtonRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VButtonRole::todoListOrder() const
{
    return d->todo_list_order;
}

void VButtonRole::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VButtonRole::buttonOrder() const
{
    return d->button_order;
}

void VButtonRole::setButtonOrder(int buttonOrder)
{
    d->button_order = buttonOrder;
}

VButtonRole &VButtonRole::operator=(const VButtonRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VButtonRole VButtonRole::create(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int buttonOrder)
{
    VButtonRoleObject obj;
    obj.button_id = buttonId;
    obj.button_cd = buttonCd;
    obj.button_name_zh = buttonNameZh;
    obj.button_name_en = buttonNameEn;
    obj.button_tooltip = buttonTooltip;
    obj.button_desc = buttonDesc;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    obj.todo_list_order = todoListOrder;
    obj.button_order = buttonOrder;
    if (!obj.create()) {
        return VButtonRole();
    }
    return VButtonRole(obj);
}

VButtonRole VButtonRole::create(const QVariantMap &values)
{
    VButtonRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VButtonRole VButtonRole::get(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int buttonOrder)
{
    TCriteria cri;
    cri.add(VButtonRoleObject::ButtonId, buttonId);
    cri.add(VButtonRoleObject::ButtonCd, buttonCd);
    cri.add(VButtonRoleObject::ButtonNameZh, buttonNameZh);
    cri.add(VButtonRoleObject::ButtonNameEn, buttonNameEn);
    cri.add(VButtonRoleObject::ButtonTooltip, buttonTooltip);
    cri.add(VButtonRoleObject::ButtonDesc, buttonDesc);
    cri.add(VButtonRoleObject::Controller, controller);
    cri.add(VButtonRoleObject::Action, action);
    cri.add(VButtonRoleObject::RoleId, roleId);
    cri.add(VButtonRoleObject::TodoListOrder, todoListOrder);
    cri.add(VButtonRoleObject::ButtonOrder, buttonOrder);
    TSqlORMapper<VButtonRoleObject> mapper;
    return VButtonRole(mapper.findFirst(cri));
}

int VButtonRole::count()
{
    TSqlORMapper<VButtonRoleObject> mapper;
    return mapper.findCount();
}

QList<VButtonRole> VButtonRole::getAll()
{
    return tfGetModelListByCriteria<VButtonRole, VButtonRoleObject>(TCriteria());
}

TModelObject *VButtonRole::modelData()
{
    return d.data();
}

const TModelObject *VButtonRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VButtonRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VButtonRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VButtonRole)
