#include <TreeFrogModel>
#include "vmenusgroupmenurole.h"
#include "vmenusgroupmenuroleobject.h"

VMenusGroupMenuRole::VMenusGroupMenuRole()
    : TAbstractModel(), d(new VMenusGroupMenuRoleObject())
{
    d->role_id = 0;
    d->menus_group_order = 0;
    d->menus_group_id = 0;
    d->menu_id = 0;
    d->menu_order = 0;
}

VMenusGroupMenuRole::VMenusGroupMenuRole(const VMenusGroupMenuRole &other)
    : TAbstractModel(), d(new VMenusGroupMenuRoleObject(*other.d))
{ }

VMenusGroupMenuRole::VMenusGroupMenuRole(const VMenusGroupMenuRoleObject &object)
    : TAbstractModel(), d(new VMenusGroupMenuRoleObject(object))
{ }

VMenusGroupMenuRole::~VMenusGroupMenuRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VMenusGroupMenuRoleObject' is deleted.
}

int VMenusGroupMenuRole::roleId() const
{
    return d->role_id;
}

void VMenusGroupMenuRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VMenusGroupMenuRole::menusGroupOrder() const
{
    return d->menus_group_order;
}

void VMenusGroupMenuRole::setMenusGroupOrder(int menusGroupOrder)
{
    d->menus_group_order = menusGroupOrder;
}

int VMenusGroupMenuRole::menusGroupId() const
{
    return d->menus_group_id;
}

void VMenusGroupMenuRole::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

QString VMenusGroupMenuRole::menusGroupCd() const
{
    return d->menus_group_cd;
}

void VMenusGroupMenuRole::setMenusGroupCd(const QString &menusGroupCd)
{
    d->menus_group_cd = menusGroupCd;
}

QString VMenusGroupMenuRole::menusGroupNameZh() const
{
    return d->menus_group_name_zh;
}

void VMenusGroupMenuRole::setMenusGroupNameZh(const QString &menusGroupNameZh)
{
    d->menus_group_name_zh = menusGroupNameZh;
}

QString VMenusGroupMenuRole::menusGroupNameEn() const
{
    return d->menus_group_name_en;
}

void VMenusGroupMenuRole::setMenusGroupNameEn(const QString &menusGroupNameEn)
{
    d->menus_group_name_en = menusGroupNameEn;
}

QString VMenusGroupMenuRole::menusGroupTooltip() const
{
    return d->menus_group_tooltip;
}

void VMenusGroupMenuRole::setMenusGroupTooltip(const QString &menusGroupTooltip)
{
    d->menus_group_tooltip = menusGroupTooltip;
}

QString VMenusGroupMenuRole::menusGroupDesc() const
{
    return d->menus_group_desc;
}

void VMenusGroupMenuRole::setMenusGroupDesc(const QString &menusGroupDesc)
{
    d->menus_group_desc = menusGroupDesc;
}

int VMenusGroupMenuRole::menuId() const
{
    return d->menu_id;
}

void VMenusGroupMenuRole::setMenuId(int menuId)
{
    d->menu_id = menuId;
}

int VMenusGroupMenuRole::menuOrder() const
{
    return d->menu_order;
}

void VMenusGroupMenuRole::setMenuOrder(int menuOrder)
{
    d->menu_order = menuOrder;
}

bool VMenusGroupMenuRole::breakBool() const
{
    return d->break_bool;
}

void VMenusGroupMenuRole::setBreakBool(const bool &breakBool)
{
    d->break_bool = breakBool;
}

QString VMenusGroupMenuRole::menuCd() const
{
    return d->menu_cd;
}

void VMenusGroupMenuRole::setMenuCd(const QString &menuCd)
{
    d->menu_cd = menuCd;
}

QString VMenusGroupMenuRole::menuNameZh() const
{
    return d->menu_name_zh;
}

void VMenusGroupMenuRole::setMenuNameZh(const QString &menuNameZh)
{
    d->menu_name_zh = menuNameZh;
}

QString VMenusGroupMenuRole::menuNameEn() const
{
    return d->menu_name_en;
}

void VMenusGroupMenuRole::setMenuNameEn(const QString &menuNameEn)
{
    d->menu_name_en = menuNameEn;
}

QString VMenusGroupMenuRole::menuTooltip() const
{
    return d->menu_tooltip;
}

void VMenusGroupMenuRole::setMenuTooltip(const QString &menuTooltip)
{
    d->menu_tooltip = menuTooltip;
}

QString VMenusGroupMenuRole::menuDesc() const
{
    return d->menu_desc;
}

void VMenusGroupMenuRole::setMenuDesc(const QString &menuDesc)
{
    d->menu_desc = menuDesc;
}

QString VMenusGroupMenuRole::controller() const
{
    return d->controller;
}

void VMenusGroupMenuRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VMenusGroupMenuRole::action() const
{
    return d->action;
}

void VMenusGroupMenuRole::setAction(const QString &action)
{
    d->action = action;
}

VMenusGroupMenuRole &VMenusGroupMenuRole::operator=(const VMenusGroupMenuRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VMenusGroupMenuRole VMenusGroupMenuRole::create(int roleId, int menusGroupOrder, int menusGroupId, const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, int menuOrder, const bool &breakBool, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action)
{
    VMenusGroupMenuRoleObject obj;
    obj.role_id = roleId;
    obj.menus_group_order = menusGroupOrder;
    obj.menus_group_id = menusGroupId;
    obj.menus_group_cd = menusGroupCd;
    obj.menus_group_name_zh = menusGroupNameZh;
    obj.menus_group_name_en = menusGroupNameEn;
    obj.menus_group_tooltip = menusGroupTooltip;
    obj.menus_group_desc = menusGroupDesc;
    obj.menu_id = menuId;
    obj.menu_order = menuOrder;
    obj.break_bool = breakBool;
    obj.menu_cd = menuCd;
    obj.menu_name_zh = menuNameZh;
    obj.menu_name_en = menuNameEn;
    obj.menu_tooltip = menuTooltip;
    obj.menu_desc = menuDesc;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VMenusGroupMenuRole();
    }
    return VMenusGroupMenuRole(obj);
}

VMenusGroupMenuRole VMenusGroupMenuRole::create(const QVariantMap &values)
{
    VMenusGroupMenuRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VMenusGroupMenuRole VMenusGroupMenuRole::get(int roleId, int menusGroupOrder, int menusGroupId, const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, int menuOrder, const bool &breakBool, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VMenusGroupMenuRoleObject::RoleId, roleId);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupOrder, menusGroupOrder);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupId, menusGroupId);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupCd, menusGroupCd);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupNameZh, menusGroupNameZh);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupNameEn, menusGroupNameEn);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupTooltip, menusGroupTooltip);
    cri.add(VMenusGroupMenuRoleObject::MenusGroupDesc, menusGroupDesc);
    cri.add(VMenusGroupMenuRoleObject::MenuId, menuId);
    cri.add(VMenusGroupMenuRoleObject::MenuOrder, menuOrder);
    cri.add(VMenusGroupMenuRoleObject::BreakBool, breakBool);
    cri.add(VMenusGroupMenuRoleObject::MenuCd, menuCd);
    cri.add(VMenusGroupMenuRoleObject::MenuNameZh, menuNameZh);
    cri.add(VMenusGroupMenuRoleObject::MenuNameEn, menuNameEn);
    cri.add(VMenusGroupMenuRoleObject::MenuTooltip, menuTooltip);
    cri.add(VMenusGroupMenuRoleObject::MenuDesc, menuDesc);
    cri.add(VMenusGroupMenuRoleObject::Controller, controller);
    cri.add(VMenusGroupMenuRoleObject::Action, action);
    TSqlORMapper<VMenusGroupMenuRoleObject> mapper;
    return VMenusGroupMenuRole(mapper.findFirst(cri));
}

int VMenusGroupMenuRole::count()
{
    TSqlORMapper<VMenusGroupMenuRoleObject> mapper;
    return mapper.findCount();
}

QList<VMenusGroupMenuRole> VMenusGroupMenuRole::getAll()
{
    return tfGetModelListByCriteria<VMenusGroupMenuRole, VMenusGroupMenuRoleObject>();
}

TModelObject *VMenusGroupMenuRole::modelData()
{
    return d.data();
}

const TModelObject *VMenusGroupMenuRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VMenusGroupMenuRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VMenusGroupMenuRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VMenusGroupMenuRole)
