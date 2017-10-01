#include <TreeFrogModel>
#include "vtodolistbuttonrole.h"
#include "vtodolistbuttonroleobject.h"

VTodoListButtonRole::VTodoListButtonRole()
    : TAbstractModel(), d(new VTodoListButtonRoleObject())
{
    d->role_id = 0;
    d->todo_list_order = 0;
    d->todo_list_id = 0;
    d->button_id = 0;
    d->button_order = 0;
}

VTodoListButtonRole::VTodoListButtonRole(const VTodoListButtonRole &other)
    : TAbstractModel(), d(new VTodoListButtonRoleObject(*other.d))
{ }

VTodoListButtonRole::VTodoListButtonRole(const VTodoListButtonRoleObject &object)
    : TAbstractModel(), d(new VTodoListButtonRoleObject(object))
{ }

VTodoListButtonRole::~VTodoListButtonRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VTodoListButtonRoleObject' is deleted.
}

int VTodoListButtonRole::roleId() const
{
    return d->role_id;
}

void VTodoListButtonRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VTodoListButtonRole::todoListOrder() const
{
    return d->todo_list_order;
}

void VTodoListButtonRole::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VTodoListButtonRole::todoListId() const
{
    return d->todo_list_id;
}

void VTodoListButtonRole::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

QString VTodoListButtonRole::todoListCd() const
{
    return d->todo_list_cd;
}

void VTodoListButtonRole::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString VTodoListButtonRole::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void VTodoListButtonRole::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString VTodoListButtonRole::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void VTodoListButtonRole::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString VTodoListButtonRole::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void VTodoListButtonRole::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString VTodoListButtonRole::todoListDesc() const
{
    return d->todo_list_desc;
}

void VTodoListButtonRole::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

int VTodoListButtonRole::buttonId() const
{
    return d->button_id;
}

void VTodoListButtonRole::setButtonId(int buttonId)
{
    d->button_id = buttonId;
}

int VTodoListButtonRole::buttonOrder() const
{
    return d->button_order;
}

void VTodoListButtonRole::setButtonOrder(int buttonOrder)
{
    d->button_order = buttonOrder;
}

QString VTodoListButtonRole::buttonCd() const
{
    return d->button_cd;
}

void VTodoListButtonRole::setButtonCd(const QString &buttonCd)
{
    d->button_cd = buttonCd;
}

QString VTodoListButtonRole::buttonNameZh() const
{
    return d->button_name_zh;
}

void VTodoListButtonRole::setButtonNameZh(const QString &buttonNameZh)
{
    d->button_name_zh = buttonNameZh;
}

QString VTodoListButtonRole::buttonNameEn() const
{
    return d->button_name_en;
}

void VTodoListButtonRole::setButtonNameEn(const QString &buttonNameEn)
{
    d->button_name_en = buttonNameEn;
}

QString VTodoListButtonRole::buttonTooltip() const
{
    return d->button_tooltip;
}

void VTodoListButtonRole::setButtonTooltip(const QString &buttonTooltip)
{
    d->button_tooltip = buttonTooltip;
}

QString VTodoListButtonRole::buttonDesc() const
{
    return d->button_desc;
}

void VTodoListButtonRole::setButtonDesc(const QString &buttonDesc)
{
    d->button_desc = buttonDesc;
}

QString VTodoListButtonRole::controller() const
{
    return d->controller;
}

void VTodoListButtonRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTodoListButtonRole::action() const
{
    return d->action;
}

void VTodoListButtonRole::setAction(const QString &action)
{
    d->action = action;
}

VTodoListButtonRole &VTodoListButtonRole::operator=(const VTodoListButtonRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTodoListButtonRole VTodoListButtonRole::create(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action)
{
    VTodoListButtonRoleObject obj;
    obj.role_id = roleId;
    obj.todo_list_order = todoListOrder;
    obj.todo_list_id = todoListId;
    obj.todo_list_cd = todoListCd;
    obj.todo_list_name_zh = todoListNameZh;
    obj.todo_list_name_en = todoListNameEn;
    obj.todo_list_tooltip = todoListTooltip;
    obj.todo_list_desc = todoListDesc;
    obj.button_id = buttonId;
    obj.button_order = buttonOrder;
    obj.button_cd = buttonCd;
    obj.button_name_zh = buttonNameZh;
    obj.button_name_en = buttonNameEn;
    obj.button_tooltip = buttonTooltip;
    obj.button_desc = buttonDesc;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VTodoListButtonRole();
    }
    return VTodoListButtonRole(obj);
}

VTodoListButtonRole VTodoListButtonRole::create(const QVariantMap &values)
{
    VTodoListButtonRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTodoListButtonRole VTodoListButtonRole::get(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VTodoListButtonRoleObject::RoleId, roleId);
    cri.add(VTodoListButtonRoleObject::TodoListOrder, todoListOrder);
    cri.add(VTodoListButtonRoleObject::TodoListId, todoListId);
    cri.add(VTodoListButtonRoleObject::TodoListCd, todoListCd);
    cri.add(VTodoListButtonRoleObject::TodoListNameZh, todoListNameZh);
    cri.add(VTodoListButtonRoleObject::TodoListNameEn, todoListNameEn);
    cri.add(VTodoListButtonRoleObject::TodoListTooltip, todoListTooltip);
    cri.add(VTodoListButtonRoleObject::TodoListDesc, todoListDesc);
    cri.add(VTodoListButtonRoleObject::ButtonId, buttonId);
    cri.add(VTodoListButtonRoleObject::ButtonOrder, buttonOrder);
    cri.add(VTodoListButtonRoleObject::ButtonCd, buttonCd);
    cri.add(VTodoListButtonRoleObject::ButtonNameZh, buttonNameZh);
    cri.add(VTodoListButtonRoleObject::ButtonNameEn, buttonNameEn);
    cri.add(VTodoListButtonRoleObject::ButtonTooltip, buttonTooltip);
    cri.add(VTodoListButtonRoleObject::ButtonDesc, buttonDesc);
    cri.add(VTodoListButtonRoleObject::Controller, controller);
    cri.add(VTodoListButtonRoleObject::Action, action);
    TSqlORMapper<VTodoListButtonRoleObject> mapper;
    return VTodoListButtonRole(mapper.findFirst(cri));
}

int VTodoListButtonRole::count()
{
    TSqlORMapper<VTodoListButtonRoleObject> mapper;
    return mapper.findCount();
}

QList<VTodoListButtonRole> VTodoListButtonRole::getAll()
{
    return tfGetModelListByCriteria<VTodoListButtonRole, VTodoListButtonRoleObject>();
}

TModelObject *VTodoListButtonRole::modelData()
{
    return d.data();
}

const TModelObject *VTodoListButtonRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTodoListButtonRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTodoListButtonRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTodoListButtonRole)
