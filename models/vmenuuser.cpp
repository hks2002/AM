#include <TreeFrogModel>
#include "vmenuuser.h"
#include "vmenuuserobject.h"

VMenuUser::VMenuUser()
    : TAbstractModel(), d(new VMenuUserObject())
{
    d->menu_id = 0;
    d->user_id = 0;
    d->menus_group_id = 0;
    d->menus_group_order = 0;
    d->menu_order = 0;
}

VMenuUser::VMenuUser(const VMenuUser &other)
    : TAbstractModel(), d(new VMenuUserObject(*other.d))
{ }

VMenuUser::VMenuUser(const VMenuUserObject &object)
    : TAbstractModel(), d(new VMenuUserObject(object))
{ }

VMenuUser::~VMenuUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VMenuUserObject' is deleted.
}

QString VMenuUser::menusGroupCd() const
{
    return d->menus_group_cd;
}

void VMenuUser::setMenusGroupCd(const QString &menusGroupCd)
{
    d->menus_group_cd = menusGroupCd;
}

QString VMenuUser::menusGroupNameZh() const
{
    return d->menus_group_name_zh;
}

void VMenuUser::setMenusGroupNameZh(const QString &menusGroupNameZh)
{
    d->menus_group_name_zh = menusGroupNameZh;
}

QString VMenuUser::menusGroupNameEn() const
{
    return d->menus_group_name_en;
}

void VMenuUser::setMenusGroupNameEn(const QString &menusGroupNameEn)
{
    d->menus_group_name_en = menusGroupNameEn;
}

QString VMenuUser::menusGroupTooltip() const
{
    return d->menus_group_tooltip;
}

void VMenuUser::setMenusGroupTooltip(const QString &menusGroupTooltip)
{
    d->menus_group_tooltip = menusGroupTooltip;
}

QString VMenuUser::menusGroupDesc() const
{
    return d->menus_group_desc;
}

void VMenuUser::setMenusGroupDesc(const QString &menusGroupDesc)
{
    d->menus_group_desc = menusGroupDesc;
}

int VMenuUser::menuId() const
{
    return d->menu_id;
}

void VMenuUser::setMenuId(int menuId)
{
    d->menu_id = menuId;
}

QString VMenuUser::menuCd() const
{
    return d->menu_cd;
}

void VMenuUser::setMenuCd(const QString &menuCd)
{
    d->menu_cd = menuCd;
}

QString VMenuUser::menuNameZh() const
{
    return d->menu_name_zh;
}

void VMenuUser::setMenuNameZh(const QString &menuNameZh)
{
    d->menu_name_zh = menuNameZh;
}

QString VMenuUser::menuNameEn() const
{
    return d->menu_name_en;
}

void VMenuUser::setMenuNameEn(const QString &menuNameEn)
{
    d->menu_name_en = menuNameEn;
}

QString VMenuUser::menuTooltip() const
{
    return d->menu_tooltip;
}

void VMenuUser::setMenuTooltip(const QString &menuTooltip)
{
    d->menu_tooltip = menuTooltip;
}

QString VMenuUser::menuDesc() const
{
    return d->menu_desc;
}

void VMenuUser::setMenuDesc(const QString &menuDesc)
{
    d->menu_desc = menuDesc;
}

QString VMenuUser::controller() const
{
    return d->controller;
}

void VMenuUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VMenuUser::action() const
{
    return d->action;
}

void VMenuUser::setAction(const QString &action)
{
    d->action = action;
}

int VMenuUser::userId() const
{
    return d->user_id;
}

void VMenuUser::setUserId(int userId)
{
    d->user_id = userId;
}

int VMenuUser::menusGroupId() const
{
    return d->menus_group_id;
}

void VMenuUser::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

int VMenuUser::menusGroupOrder() const
{
    return d->menus_group_order;
}

void VMenuUser::setMenusGroupOrder(int menusGroupOrder)
{
    d->menus_group_order = menusGroupOrder;
}

int VMenuUser::menuOrder() const
{
    return d->menu_order;
}

void VMenuUser::setMenuOrder(int menuOrder)
{
    d->menu_order = menuOrder;
}

bool VMenuUser::breakBool() const
{
    return d->break_bool;
}

void VMenuUser::setBreakBool(const bool &breakBool)
{
    d->break_bool = breakBool;
}

VMenuUser &VMenuUser::operator=(const VMenuUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VMenuUser VMenuUser::create(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, int userId, int menusGroupId, int menusGroupOrder, int menuOrder, const bool &breakBool)
{
    VMenuUserObject obj;
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
    obj.user_id = userId;
    obj.menus_group_id = menusGroupId;
    obj.menus_group_order = menusGroupOrder;
    obj.menu_order = menuOrder;
    obj.break_bool = breakBool;
    if (!obj.create()) {
        return VMenuUser();
    }
    return VMenuUser(obj);
}

VMenuUser VMenuUser::create(const QVariantMap &values)
{
    VMenuUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VMenuUser VMenuUser::get(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, int userId, int menusGroupId, int menusGroupOrder, int menuOrder, const bool &breakBool)
{
    TCriteria cri;
    cri.add(VMenuUserObject::MenusGroupCd, menusGroupCd);
    cri.add(VMenuUserObject::MenusGroupNameZh, menusGroupNameZh);
    cri.add(VMenuUserObject::MenusGroupNameEn, menusGroupNameEn);
    cri.add(VMenuUserObject::MenusGroupTooltip, menusGroupTooltip);
    cri.add(VMenuUserObject::MenusGroupDesc, menusGroupDesc);
    cri.add(VMenuUserObject::MenuId, menuId);
    cri.add(VMenuUserObject::MenuCd, menuCd);
    cri.add(VMenuUserObject::MenuNameZh, menuNameZh);
    cri.add(VMenuUserObject::MenuNameEn, menuNameEn);
    cri.add(VMenuUserObject::MenuTooltip, menuTooltip);
    cri.add(VMenuUserObject::MenuDesc, menuDesc);
    cri.add(VMenuUserObject::Controller, controller);
    cri.add(VMenuUserObject::Action, action);
    cri.add(VMenuUserObject::UserId, userId);
    cri.add(VMenuUserObject::MenusGroupId, menusGroupId);
    cri.add(VMenuUserObject::MenusGroupOrder, menusGroupOrder);
    cri.add(VMenuUserObject::MenuOrder, menuOrder);
    cri.add(VMenuUserObject::BreakBool, breakBool);
    TSqlORMapper<VMenuUserObject> mapper;
    return VMenuUser(mapper.findFirst(cri));
}

int VMenuUser::count()
{
    TSqlORMapper<VMenuUserObject> mapper;
    return mapper.findCount();
}

QList<VMenuUser> VMenuUser::getAll()
{
    return tfGetModelListByCriteria<VMenuUser, VMenuUserObject>(TCriteria());
}

TModelObject *VMenuUser::modelData()
{
    return d.data();
}

const TModelObject *VMenuUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VMenuUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VMenuUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VMenuUser)
