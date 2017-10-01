#include <TreeFrogModel>
#include "vtabrole.h"
#include "vtabroleobject.h"

VTabRole::VTabRole()
    : TAbstractModel(), d(new VTabRoleObject())
{
    d->tab_id = 0;
    d->role_id = 0;
    d->todo_list_order = 0;
    d->tab_order = 0;
}

VTabRole::VTabRole(const VTabRole &other)
    : TAbstractModel(), d(new VTabRoleObject(*other.d))
{ }

VTabRole::VTabRole(const VTabRoleObject &object)
    : TAbstractModel(), d(new VTabRoleObject(object))
{ }

VTabRole::~VTabRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VTabRoleObject' is deleted.
}

int VTabRole::tabId() const
{
    return d->tab_id;
}

void VTabRole::setTabId(int tabId)
{
    d->tab_id = tabId;
}

QString VTabRole::tabCd() const
{
    return d->tab_cd;
}

void VTabRole::setTabCd(const QString &tabCd)
{
    d->tab_cd = tabCd;
}

QString VTabRole::tabNameZh() const
{
    return d->tab_name_zh;
}

void VTabRole::setTabNameZh(const QString &tabNameZh)
{
    d->tab_name_zh = tabNameZh;
}

QString VTabRole::tabNameEn() const
{
    return d->tab_name_en;
}

void VTabRole::setTabNameEn(const QString &tabNameEn)
{
    d->tab_name_en = tabNameEn;
}

QString VTabRole::tabTooltip() const
{
    return d->tab_tooltip;
}

void VTabRole::setTabTooltip(const QString &tabTooltip)
{
    d->tab_tooltip = tabTooltip;
}

QString VTabRole::tabDesc() const
{
    return d->tab_desc;
}

void VTabRole::setTabDesc(const QString &tabDesc)
{
    d->tab_desc = tabDesc;
}

QString VTabRole::controller() const
{
    return d->controller;
}

void VTabRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTabRole::action() const
{
    return d->action;
}

void VTabRole::setAction(const QString &action)
{
    d->action = action;
}

int VTabRole::roleId() const
{
    return d->role_id;
}

void VTabRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VTabRole::todoListOrder() const
{
    return d->todo_list_order;
}

void VTabRole::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VTabRole::tabOrder() const
{
    return d->tab_order;
}

void VTabRole::setTabOrder(int tabOrder)
{
    d->tab_order = tabOrder;
}

VTabRole &VTabRole::operator=(const VTabRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTabRole VTabRole::create(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int tabOrder)
{
    VTabRoleObject obj;
    obj.tab_id = tabId;
    obj.tab_cd = tabCd;
    obj.tab_name_zh = tabNameZh;
    obj.tab_name_en = tabNameEn;
    obj.tab_tooltip = tabTooltip;
    obj.tab_desc = tabDesc;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    obj.todo_list_order = todoListOrder;
    obj.tab_order = tabOrder;
    if (!obj.create()) {
        return VTabRole();
    }
    return VTabRole(obj);
}

VTabRole VTabRole::create(const QVariantMap &values)
{
    VTabRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTabRole VTabRole::get(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int tabOrder)
{
    TCriteria cri;
    cri.add(VTabRoleObject::TabId, tabId);
    cri.add(VTabRoleObject::TabCd, tabCd);
    cri.add(VTabRoleObject::TabNameZh, tabNameZh);
    cri.add(VTabRoleObject::TabNameEn, tabNameEn);
    cri.add(VTabRoleObject::TabTooltip, tabTooltip);
    cri.add(VTabRoleObject::TabDesc, tabDesc);
    cri.add(VTabRoleObject::Controller, controller);
    cri.add(VTabRoleObject::Action, action);
    cri.add(VTabRoleObject::RoleId, roleId);
    cri.add(VTabRoleObject::TodoListOrder, todoListOrder);
    cri.add(VTabRoleObject::TabOrder, tabOrder);
    TSqlORMapper<VTabRoleObject> mapper;
    return VTabRole(mapper.findFirst(cri));
}

int VTabRole::count()
{
    TSqlORMapper<VTabRoleObject> mapper;
    return mapper.findCount();
}

QList<VTabRole> VTabRole::getAll()
{
    return tfGetModelListByCriteria<VTabRole, VTabRoleObject>(TCriteria());
}

TModelObject *VTabRole::modelData()
{
    return d.data();
}

const TModelObject *VTabRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTabRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTabRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTabRole)
