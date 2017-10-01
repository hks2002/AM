#include <TreeFrogModel>
#include "vmenurole.h"
#include "vmenuroleobject.h"

VMenuRole::VMenuRole()
    : TAbstractModel(), d(new VMenuRoleObject())
{
    d->menu_id = 0;
    d->role_id = 0;
    d->menus_group_id = 0;
    d->menus_group_order = 0;
    d->menu_order = 0;
}

VMenuRole::VMenuRole(const VMenuRole &other)
    : TAbstractModel(), d(new VMenuRoleObject(*other.d))
{ }

VMenuRole::VMenuRole(const VMenuRoleObject &object)
    : TAbstractModel(), d(new VMenuRoleObject(object))
{ }

VMenuRole::~VMenuRole()
{
    // If the reference count becomes 0,
    // the shared data object 'VMenuRoleObject' is deleted.
}

QString VMenuRole::menusGroupCd() const
{
    return d->menus_group_cd;
}

void VMenuRole::setMenusGroupCd(const QString &menusGroupCd)
{
    d->menus_group_cd = menusGroupCd;
}

QString VMenuRole::menusGroupNameZh() const
{
    return d->menus_group_name_zh;
}

void VMenuRole::setMenusGroupNameZh(const QString &menusGroupNameZh)
{
    d->menus_group_name_zh = menusGroupNameZh;
}

QString VMenuRole::menusGroupNameEn() const
{
    return d->menus_group_name_en;
}

void VMenuRole::setMenusGroupNameEn(const QString &menusGroupNameEn)
{
    d->menus_group_name_en = menusGroupNameEn;
}

QString VMenuRole::menusGroupTooltip() const
{
    return d->menus_group_tooltip;
}

void VMenuRole::setMenusGroupTooltip(const QString &menusGroupTooltip)
{
    d->menus_group_tooltip = menusGroupTooltip;
}

QString VMenuRole::menusGroupDesc() const
{
    return d->menus_group_desc;
}

void VMenuRole::setMenusGroupDesc(const QString &menusGroupDesc)
{
    d->menus_group_desc = menusGroupDesc;
}

int VMenuRole::menuId() const
{
    return d->menu_id;
}

void VMenuRole::setMenuId(int menuId)
{
    d->menu_id = menuId;
}

QString VMenuRole::menuCd() const
{
    return d->menu_cd;
}

void VMenuRole::setMenuCd(const QString &menuCd)
{
    d->menu_cd = menuCd;
}

QString VMenuRole::menuNameZh() const
{
    return d->menu_name_zh;
}

void VMenuRole::setMenuNameZh(const QString &menuNameZh)
{
    d->menu_name_zh = menuNameZh;
}

QString VMenuRole::menuNameEn() const
{
    return d->menu_name_en;
}

void VMenuRole::setMenuNameEn(const QString &menuNameEn)
{
    d->menu_name_en = menuNameEn;
}

QString VMenuRole::menuTooltip() const
{
    return d->menu_tooltip;
}

void VMenuRole::setMenuTooltip(const QString &menuTooltip)
{
    d->menu_tooltip = menuTooltip;
}

QString VMenuRole::menuDesc() const
{
    return d->menu_desc;
}

void VMenuRole::setMenuDesc(const QString &menuDesc)
{
    d->menu_desc = menuDesc;
}

QString VMenuRole::controller() const
{
    return d->controller;
}

void VMenuRole::setController(const QString &controller)
{
    d->controller = controller;
}

QString VMenuRole::action() const
{
    return d->action;
}

void VMenuRole::setAction(const QString &action)
{
    d->action = action;
}

int VMenuRole::roleId() const
{
    return d->role_id;
}

void VMenuRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int VMenuRole::menusGroupId() const
{
    return d->menus_group_id;
}

void VMenuRole::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

int VMenuRole::menusGroupOrder() const
{
    return d->menus_group_order;
}

void VMenuRole::setMenusGroupOrder(int menusGroupOrder)
{
    d->menus_group_order = menusGroupOrder;
}

int VMenuRole::menuOrder() const
{
    return d->menu_order;
}

void VMenuRole::setMenuOrder(int menuOrder)
{
    d->menu_order = menuOrder;
}

bool VMenuRole::breakBool() const
{
    return d->break_bool;
}

void VMenuRole::setBreakBool(const bool &breakBool)
{
    d->break_bool = breakBool;
}

VMenuRole &VMenuRole::operator=(const VMenuRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VMenuRole VMenuRole::create(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, int roleId, int menusGroupId, int menusGroupOrder, int menuOrder, const bool &breakBool)
{
    VMenuRoleObject obj;
    obj.menus_group_cd = menusGroupCd;
    obj.menus_group_name_zh = menusGroupNameZh;
    obj.menus_group_name_en = menusGroupNameEn;
    obj.menus_group_tooltip = menusGroupTooltip;
    obj.menus_group_desc = menusGroupDesc;
    obj.menu_id = menuId;
    obj.menu_cd = menuCd;
    obj.menu_name_zh = menuNameZh;
    obj.menu_name_en = menuNameEn;
    obj.menu_tooltip = menuTooltip;
    obj.menu_desc = menuDesc;
    obj.controller = controller;
    obj.action = action;
    obj.role_id = roleId;
    obj.menus_group_id = menusGroupId;
    obj.menus_group_order = menusGroupOrder;
    obj.menu_order = menuOrder;
    obj.break_bool = breakBool;
    if (!obj.create()) {
        return VMenuRole();
    }
    return VMenuRole(obj);
}

VMenuRole VMenuRole::create(const QVariantMap &values)
{
    VMenuRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VMenuRole VMenuRole::get(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, int roleId, int menusGroupId, int menusGroupOrder, int menuOrder, const bool &breakBool)
{
    TCriteria cri;
    cri.add(VMenuRoleObject::MenusGroupCd, menusGroupCd);
    cri.add(VMenuRoleObject::MenusGroupNameZh, menusGroupNameZh);
    cri.add(VMenuRoleObject::MenusGroupNameEn, menusGroupNameEn);
    cri.add(VMenuRoleObject::MenusGroupTooltip, menusGroupTooltip);
    cri.add(VMenuRoleObject::MenusGroupDesc, menusGroupDesc);
    cri.add(VMenuRoleObject::MenuId, menuId);
    cri.add(VMenuRoleObject::MenuCd, menuCd);
    cri.add(VMenuRoleObject::MenuNameZh, menuNameZh);
    cri.add(VMenuRoleObject::MenuNameEn, menuNameEn);
    cri.add(VMenuRoleObject::MenuTooltip, menuTooltip);
    cri.add(VMenuRoleObject::MenuDesc, menuDesc);
    cri.add(VMenuRoleObject::Controller, controller);
    cri.add(VMenuRoleObject::Action, action);
    cri.add(VMenuRoleObject::RoleId, roleId);
    cri.add(VMenuRoleObject::MenusGroupId, menusGroupId);
    cri.add(VMenuRoleObject::MenusGroupOrder, menusGroupOrder);
    cri.add(VMenuRoleObject::MenuOrder, menuOrder);
    cri.add(VMenuRoleObject::BreakBool, breakBool);
    TSqlORMapper<VMenuRoleObject> mapper;
    return VMenuRole(mapper.findFirst(cri));
}

int VMenuRole::count()
{
    TSqlORMapper<VMenuRoleObject> mapper;
    return mapper.findCount();
}

QList<VMenuRole> VMenuRole::getAll()
{
    return tfGetModelListByCriteria<VMenuRole, VMenuRoleObject>(TCriteria());
}

TModelObject *VMenuRole::modelData()
{
    return d.data();
}

const TModelObject *VMenuRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VMenuRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VMenuRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VMenuRole)
