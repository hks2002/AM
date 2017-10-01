#include <TreeFrogModel>
#include "vtodolisttabrole.h"
#include "vtodolisttabroleobject.h"

VTodoListTabRole::VTodoListTabRole()
    : TAbstractModel(), d(new VTodoListTabRoleObject())
{
    d->role_id = 0;
    d->todo_list_order = 0;
    d->todo_list_id = 0;
    d->tab_id = 0;
    d->tab_order = 0;
}

VTodoListTabRole::VTodoListTabRole(const VTodoListTabRole &other)
    : TAbstractModel(), d(new VTodoListTabRoleObject(*other.d))
{ }

VTodoListTabRole::VTodoListTabRole(const VTodoListTabRoleObject &object)
    : TAbstractModel(), d(new VTodoListTabRoleObject(object))
{ }

VTodoListTabRole::~VTodoListTabRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VTodoListTabRoleObject' is deleted.
}

int VTodoListTabRole::roleId() const
{
    return d->role_id;
}

void VTodoListTabRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VTodoListTabRole::todoListOrder() const
{
    return d->todo_list_order;
}

void VTodoListTabRole::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VTodoListTabRole::todoListId() const
{
    return d->todo_list_id;
}

void VTodoListTabRole::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

QString VTodoListTabRole::todoListCd() const
{
    return d->todo_list_cd;
}

void VTodoListTabRole::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString VTodoListTabRole::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void VTodoListTabRole::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString VTodoListTabRole::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void VTodoListTabRole::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString VTodoListTabRole::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void VTodoListTabRole::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString VTodoListTabRole::todoListDesc() const
{
    return d->todo_list_desc;
}

void VTodoListTabRole::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

int VTodoListTabRole::tabId() const
{
    return d->tab_id;
}

void VTodoListTabRole::setTabId(int tabId)
{
    d->tab_id = tabId;
}

int VTodoListTabRole::tabOrder() const
{
    return d->tab_order;
}

void VTodoListTabRole::setTabOrder(int tabOrder)
{
    d->tab_order = tabOrder;
}

QString VTodoListTabRole::tabCd() const
{
    return d->tab_cd;
}

void VTodoListTabRole::setTabCd(const QString &tabCd)
{
    d->tab_cd = tabCd;
}

QString VTodoListTabRole::tabNameZh() const
{
    return d->tab_name_zh;
}

void VTodoListTabRole::setTabNameZh(const QString &tabNameZh)
{
    d->tab_name_zh = tabNameZh;
}

QString VTodoListTabRole::tabNameEn() const
{
    return d->tab_name_en;
}

void VTodoListTabRole::setTabNameEn(const QString &tabNameEn)
{
    d->tab_name_en = tabNameEn;
}

QString VTodoListTabRole::tabTooltip() const
{
    return d->tab_tooltip;
}

void VTodoListTabRole::setTabTooltip(const QString &tabTooltip)
{
    d->tab_tooltip = tabTooltip;
}

QString VTodoListTabRole::tabDesc() const
{
    return d->tab_desc;
}

void VTodoListTabRole::setTabDesc(const QString &tabDesc)
{
    d->tab_desc = tabDesc;
}

QString VTodoListTabRole::controller() const
{
    return d->controller;
}

void VTodoListTabRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTodoListTabRole::action() const
{
    return d->action;
}

void VTodoListTabRole::setAction(const QString &action)
{
    d->action = action;
}

VTodoListTabRole &VTodoListTabRole::operator=(const VTodoListTabRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTodoListTabRole VTodoListTabRole::create(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action)
{
    VTodoListTabRoleObject obj;
    obj.role_id = roleId;
    obj.todo_list_order = todoListOrder;
    obj.todo_list_id = todoListId;
    obj.todo_list_cd = todoListCd;
    obj.todo_list_name_zh = todoListNameZh;
    obj.todo_list_name_en = todoListNameEn;
    obj.todo_list_tooltip = todoListTooltip;
    obj.todo_list_desc = todoListDesc;
    obj.tab_id = tabId;
    obj.tab_order = tabOrder;
    obj.tab_cd = tabCd;
    obj.tab_name_zh = tabNameZh;
    obj.tab_name_en = tabNameEn;
    obj.tab_tooltip = tabTooltip;
    obj.tab_desc = tabDesc;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VTodoListTabRole();
    }
    return VTodoListTabRole(obj);
}

VTodoListTabRole VTodoListTabRole::create(const QVariantMap &values)
{
    VTodoListTabRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTodoListTabRole VTodoListTabRole::get(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VTodoListTabRoleObject::RoleId, roleId);
    cri.add(VTodoListTabRoleObject::TodoListOrder, todoListOrder);
    cri.add(VTodoListTabRoleObject::TodoListId, todoListId);
    cri.add(VTodoListTabRoleObject::TodoListCd, todoListCd);
    cri.add(VTodoListTabRoleObject::TodoListNameZh, todoListNameZh);
    cri.add(VTodoListTabRoleObject::TodoListNameEn, todoListNameEn);
    cri.add(VTodoListTabRoleObject::TodoListTooltip, todoListTooltip);
    cri.add(VTodoListTabRoleObject::TodoListDesc, todoListDesc);
    cri.add(VTodoListTabRoleObject::TabId, tabId);
    cri.add(VTodoListTabRoleObject::TabOrder, tabOrder);
    cri.add(VTodoListTabRoleObject::TabCd, tabCd);
    cri.add(VTodoListTabRoleObject::TabNameZh, tabNameZh);
    cri.add(VTodoListTabRoleObject::TabNameEn, tabNameEn);
    cri.add(VTodoListTabRoleObject::TabTooltip, tabTooltip);
    cri.add(VTodoListTabRoleObject::TabDesc, tabDesc);
    cri.add(VTodoListTabRoleObject::Controller, controller);
    cri.add(VTodoListTabRoleObject::Action, action);
    TSqlORMapper<VTodoListTabRoleObject> mapper;
    return VTodoListTabRole(mapper.findFirst(cri));
}

int VTodoListTabRole::count()
{
    TSqlORMapper<VTodoListTabRoleObject> mapper;
    return mapper.findCount();
}

QList<VTodoListTabRole> VTodoListTabRole::getAll()
{
    return tfGetModelListByCriteria<VTodoListTabRole, VTodoListTabRoleObject>();
}

TModelObject *VTodoListTabRole::modelData()
{
    return d.data();
}

const TModelObject *VTodoListTabRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTodoListTabRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTodoListTabRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTodoListTabRole)
