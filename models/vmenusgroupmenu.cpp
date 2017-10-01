#include <TreeFrogModel>
#include "vmenusgroupmenu.h"
#include "vmenusgroupmenuobject.h"

VMenusGroupMenu::VMenusGroupMenu()
    : TAbstractModel(), d(new VMenusGroupMenuObject())
{
    d->menus_group_id = 0;
    d->menu_id = 0;
    d->menu_order = 0;
}

VMenusGroupMenu::VMenusGroupMenu(const VMenusGroupMenu &other)
    : TAbstractModel(), d(new VMenusGroupMenuObject(*other.d))
{ }

VMenusGroupMenu::VMenusGroupMenu(const VMenusGroupMenuObject &object)
    : TAbstractModel(), d(new VMenusGroupMenuObject(object))
{ }

VMenusGroupMenu::~VMenusGroupMenu()
{
    // If the reference count becomes 0,
    // the shared data object 'VMenusGroupMenuObject' is deleted.
}

int VMenusGroupMenu::menusGroupId() const
{
    return d->menus_group_id;
}

void VMenusGroupMenu::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

QString VMenusGroupMenu::menusGroupCd() const
{
    return d->menus_group_cd;
}

void VMenusGroupMenu::setMenusGroupCd(const QString &menusGroupCd)
{
    d->menus_group_cd = menusGroupCd;
}

QString VMenusGroupMenu::menusGroupNameZh() const
{
    return d->menus_group_name_zh;
}

void VMenusGroupMenu::setMenusGroupNameZh(const QString &menusGroupNameZh)
{
    d->menus_group_name_zh = menusGroupNameZh;
}

QString VMenusGroupMenu::menusGroupNameEn() const
{
    return d->menus_group_name_en;
}

void VMenusGroupMenu::setMenusGroupNameEn(const QString &menusGroupNameEn)
{
    d->menus_group_name_en = menusGroupNameEn;
}

QString VMenusGroupMenu::menusGroupTooltip() const
{
    return d->menus_group_tooltip;
}

void VMenusGroupMenu::setMenusGroupTooltip(const QString &menusGroupTooltip)
{
    d->menus_group_tooltip = menusGroupTooltip;
}

QString VMenusGroupMenu::menusGroupDesc() const
{
    return d->menus_group_desc;
}

void VMenusGroupMenu::setMenusGroupDesc(const QString &menusGroupDesc)
{
    d->menus_group_desc = menusGroupDesc;
}

int VMenusGroupMenu::menuId() const
{
    return d->menu_id;
}

void VMenusGroupMenu::setMenuId(int menuId)
{
    d->menu_id = menuId;
}

int VMenusGroupMenu::menuOrder() const
{
    return d->menu_order;
}

void VMenusGroupMenu::setMenuOrder(int menuOrder)
{
    d->menu_order = menuOrder;
}

bool VMenusGroupMenu::breakBool() const
{
    return d->break_bool;
}

void VMenusGroupMenu::setBreakBool(const bool &breakBool)
{
    d->break_bool = breakBool;
}

QString VMenusGroupMenu::menuCd() const
{
    return d->menu_cd;
}

void VMenusGroupMenu::setMenuCd(const QString &menuCd)
{
    d->menu_cd = menuCd;
}

QString VMenusGroupMenu::menuNameZh() const
{
    return d->menu_name_zh;
}

void VMenusGroupMenu::setMenuNameZh(const QString &menuNameZh)
{
    d->menu_name_zh = menuNameZh;
}

QString VMenusGroupMenu::menuNameEn() const
{
    return d->menu_name_en;
}

void VMenusGroupMenu::setMenuNameEn(const QString &menuNameEn)
{
    d->menu_name_en = menuNameEn;
}

QString VMenusGroupMenu::menuTooltip() const
{
    return d->menu_tooltip;
}

void VMenusGroupMenu::setMenuTooltip(const QString &menuTooltip)
{
    d->menu_tooltip = menuTooltip;
}

QString VMenusGroupMenu::menuDesc() const
{
    return d->menu_desc;
}

void VMenusGroupMenu::setMenuDesc(const QString &menuDesc)
{
    d->menu_desc = menuDesc;
}

QString VMenusGroupMenu::controller() const
{
    return d->controller;
}

void VMenusGroupMenu::setController(const QString &controller)
{
    d->controller = controller;
}

QString VMenusGroupMenu::action() const
{
    return d->action;
}

void VMenusGroupMenu::setAction(const QString &action)
{
    d->action = action;
}

VMenusGroupMenu &VMenusGroupMenu::operator=(const VMenusGroupMenu &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VMenusGroupMenu VMenusGroupMenu::create(int menusGroupId, const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, int menuOrder, const bool &breakBool, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action)
{
    VMenusGroupMenuObject obj;
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
        return VMenusGroupMenu();
    }
    return VMenusGroupMenu(obj);
}

VMenusGroupMenu VMenusGroupMenu::create(const QVariantMap &values)
{
    VMenusGroupMenu model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VMenusGroupMenu VMenusGroupMenu::get(int menusGroupId, const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, int menuOrder, const bool &breakBool, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VMenusGroupMenuObject::MenusGroupId, menusGroupId);
    cri.add(VMenusGroupMenuObject::MenusGroupCd, menusGroupCd);
    cri.add(VMenusGroupMenuObject::MenusGroupNameZh, menusGroupNameZh);
    cri.add(VMenusGroupMenuObject::MenusGroupNameEn, menusGroupNameEn);
    cri.add(VMenusGroupMenuObject::MenusGroupTooltip, menusGroupTooltip);
    cri.add(VMenusGroupMenuObject::MenusGroupDesc, menusGroupDesc);
    cri.add(VMenusGroupMenuObject::MenuId, menuId);
    cri.add(VMenusGroupMenuObject::MenuOrder, menuOrder);
    cri.add(VMenusGroupMenuObject::BreakBool, breakBool);
    cri.add(VMenusGroupMenuObject::MenuCd, menuCd);
    cri.add(VMenusGroupMenuObject::MenuNameZh, menuNameZh);
    cri.add(VMenusGroupMenuObject::MenuNameEn, menuNameEn);
    cri.add(VMenusGroupMenuObject::MenuTooltip, menuTooltip);
    cri.add(VMenusGroupMenuObject::MenuDesc, menuDesc);
    cri.add(VMenusGroupMenuObject::Controller, controller);
    cri.add(VMenusGroupMenuObject::Action, action);
    TSqlORMapper<VMenusGroupMenuObject> mapper;
    return VMenusGroupMenu(mapper.findFirst(cri));
}

int VMenusGroupMenu::count()
{
    TSqlORMapper<VMenusGroupMenuObject> mapper;
    return mapper.findCount();
}

QList<VMenusGroupMenu> VMenusGroupMenu::getAll()
{
    return tfGetModelListByCriteria<VMenusGroupMenu, VMenusGroupMenuObject>();
}

TModelObject *VMenusGroupMenu::modelData()
{
    return d.data();
}

const TModelObject *VMenusGroupMenu::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VMenusGroupMenu &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VMenusGroupMenu &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VMenusGroupMenu)
