#include <TreeFrogModel>
#include "vmenusgroupmenuuser.h"
#include "vmenusgroupmenuuserobject.h"

VMenusGroupMenuUser::VMenusGroupMenuUser()
    : TAbstractModel(), d(new VMenusGroupMenuUserObject())
{
    d->user_id = 0;
    d->menus_group_order = 0;
    d->menus_group_id = 0;
    d->menu_id = 0;
    d->menu_order = 0;
}

VMenusGroupMenuUser::VMenusGroupMenuUser(const VMenusGroupMenuUser &other)
    : TAbstractModel(), d(new VMenusGroupMenuUserObject(*other.d))
{ }

VMenusGroupMenuUser::VMenusGroupMenuUser(const VMenusGroupMenuUserObject &object)
    : TAbstractModel(), d(new VMenusGroupMenuUserObject(object))
{ }

VMenusGroupMenuUser::~VMenusGroupMenuUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VMenusGroupMenuUserObject' is deleted.
}

int VMenusGroupMenuUser::userId() const
{
    return d->user_id;
}

void VMenusGroupMenuUser::setUserId(int userId)
{
    d->user_id = userId;
}

int VMenusGroupMenuUser::menusGroupOrder() const
{
    return d->menus_group_order;
}

void VMenusGroupMenuUser::setMenusGroupOrder(int menusGroupOrder)
{
    d->menus_group_order = menusGroupOrder;
}

int VMenusGroupMenuUser::menusGroupId() const
{
    return d->menus_group_id;
}

void VMenusGroupMenuUser::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

QString VMenusGroupMenuUser::menusGroupCd() const
{
    return d->menus_group_cd;
}

void VMenusGroupMenuUser::setMenusGroupCd(const QString &menusGroupCd)
{
    d->menus_group_cd = menusGroupCd;
}

QString VMenusGroupMenuUser::menusGroupNameZh() const
{
    return d->menus_group_name_zh;
}

void VMenusGroupMenuUser::setMenusGroupNameZh(const QString &menusGroupNameZh)
{
    d->menus_group_name_zh = menusGroupNameZh;
}

QString VMenusGroupMenuUser::menusGroupNameEn() const
{
    return d->menus_group_name_en;
}

void VMenusGroupMenuUser::setMenusGroupNameEn(const QString &menusGroupNameEn)
{
    d->menus_group_name_en = menusGroupNameEn;
}

QString VMenusGroupMenuUser::menusGroupTooltip() const
{
    return d->menus_group_tooltip;
}

void VMenusGroupMenuUser::setMenusGroupTooltip(const QString &menusGroupTooltip)
{
    d->menus_group_tooltip = menusGroupTooltip;
}

QString VMenusGroupMenuUser::menusGroupDesc() const
{
    return d->menus_group_desc;
}

void VMenusGroupMenuUser::setMenusGroupDesc(const QString &menusGroupDesc)
{
    d->menus_group_desc = menusGroupDesc;
}

int VMenusGroupMenuUser::menuId() const
{
    return d->menu_id;
}

void VMenusGroupMenuUser::setMenuId(int menuId)
{
    d->menu_id = menuId;
}

int VMenusGroupMenuUser::menuOrder() const
{
    return d->menu_order;
}

void VMenusGroupMenuUser::setMenuOrder(int menuOrder)
{
    d->menu_order = menuOrder;
}

bool VMenusGroupMenuUser::breakBool() const
{
    return d->break_bool;
}

void VMenusGroupMenuUser::setBreakBool(const bool &breakBool)
{
    d->break_bool = breakBool;
}

QString VMenusGroupMenuUser::menuCd() const
{
    return d->menu_cd;
}

void VMenusGroupMenuUser::setMenuCd(const QString &menuCd)
{
    d->menu_cd = menuCd;
}

QString VMenusGroupMenuUser::menuNameZh() const
{
    return d->menu_name_zh;
}

void VMenusGroupMenuUser::setMenuNameZh(const QString &menuNameZh)
{
    d->menu_name_zh = menuNameZh;
}

QString VMenusGroupMenuUser::menuNameEn() const
{
    return d->menu_name_en;
}

void VMenusGroupMenuUser::setMenuNameEn(const QString &menuNameEn)
{
    d->menu_name_en = menuNameEn;
}

QString VMenusGroupMenuUser::menuTooltip() const
{
    return d->menu_tooltip;
}

void VMenusGroupMenuUser::setMenuTooltip(const QString &menuTooltip)
{
    d->menu_tooltip = menuTooltip;
}

QString VMenusGroupMenuUser::menuDesc() const
{
    return d->menu_desc;
}

void VMenusGroupMenuUser::setMenuDesc(const QString &menuDesc)
{
    d->menu_desc = menuDesc;
}

QString VMenusGroupMenuUser::controller() const
{
    return d->controller;
}

void VMenusGroupMenuUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VMenusGroupMenuUser::action() const
{
    return d->action;
}

void VMenusGroupMenuUser::setAction(const QString &action)
{
    d->action = action;
}

VMenusGroupMenuUser &VMenusGroupMenuUser::operator=(const VMenusGroupMenuUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VMenusGroupMenuUser VMenusGroupMenuUser::create(int userId, int menusGroupOrder, int menusGroupId, const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, int menuOrder, const bool &breakBool, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action)
{
    VMenusGroupMenuUserObject obj;
    obj.user_id = userId;
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
        return VMenusGroupMenuUser();
    }
    return VMenusGroupMenuUser(obj);
}

VMenusGroupMenuUser VMenusGroupMenuUser::create(const QVariantMap &values)
{
    VMenusGroupMenuUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VMenusGroupMenuUser VMenusGroupMenuUser::get(int userId, int menusGroupOrder, int menusGroupId, const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, int menuOrder, const bool &breakBool, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VMenusGroupMenuUserObject::UserId, userId);
    cri.add(VMenusGroupMenuUserObject::MenusGroupOrder, menusGroupOrder);
    cri.add(VMenusGroupMenuUserObject::MenusGroupId, menusGroupId);
    cri.add(VMenusGroupMenuUserObject::MenusGroupCd, menusGroupCd);
    cri.add(VMenusGroupMenuUserObject::MenusGroupNameZh, menusGroupNameZh);
    cri.add(VMenusGroupMenuUserObject::MenusGroupNameEn, menusGroupNameEn);
    cri.add(VMenusGroupMenuUserObject::MenusGroupTooltip, menusGroupTooltip);
    cri.add(VMenusGroupMenuUserObject::MenusGroupDesc, menusGroupDesc);
    cri.add(VMenusGroupMenuUserObject::MenuId, menuId);
    cri.add(VMenusGroupMenuUserObject::MenuOrder, menuOrder);
    cri.add(VMenusGroupMenuUserObject::BreakBool, breakBool);
    cri.add(VMenusGroupMenuUserObject::MenuCd, menuCd);
    cri.add(VMenusGroupMenuUserObject::MenuNameZh, menuNameZh);
    cri.add(VMenusGroupMenuUserObject::MenuNameEn, menuNameEn);
    cri.add(VMenusGroupMenuUserObject::MenuTooltip, menuTooltip);
    cri.add(VMenusGroupMenuUserObject::MenuDesc, menuDesc);
    cri.add(VMenusGroupMenuUserObject::Controller, controller);
    cri.add(VMenusGroupMenuUserObject::Action, action);
    TSqlORMapper<VMenusGroupMenuUserObject> mapper;
    return VMenusGroupMenuUser(mapper.findFirst(cri));
}

int VMenusGroupMenuUser::count()
{
    TSqlORMapper<VMenusGroupMenuUserObject> mapper;
    return mapper.findCount();
}

QList<VMenusGroupMenuUser> VMenusGroupMenuUser::getAll()
{
    return tfGetModelListByCriteria<VMenusGroupMenuUser, VMenusGroupMenuUserObject>();
}

TModelObject *VMenusGroupMenuUser::modelData()
{
    return d.data();
}

const TModelObject *VMenusGroupMenuUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VMenusGroupMenuUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VMenusGroupMenuUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VMenusGroupMenuUser)
