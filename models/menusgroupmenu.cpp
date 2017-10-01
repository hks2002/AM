#include <TreeFrogModel>
#include "menusgroupmenu.h"
#include "menusgroupmenuobject.h"
#include "menu.h"
#include "menusgroup.h"

MenusGroupMenu::MenusGroupMenu()
    : TAbstractModel(), d(new MenusGroupMenuObject())
{
    d->menus_group_id = 0;
    d->menu_id = 0;
    d->menu_order = 0;
}

MenusGroupMenu::MenusGroupMenu(const MenusGroupMenu &other)
    : TAbstractModel(), d(new MenusGroupMenuObject(*other.d))
{ }

MenusGroupMenu::MenusGroupMenu(const MenusGroupMenuObject &object)
    : TAbstractModel(), d(new MenusGroupMenuObject(object))
{ }

MenusGroupMenu::~MenusGroupMenu()
{
    // If the reference count becomes 0,
    // the shared data object 'MenusGroupMenuObject' is deleted.
}

int MenusGroupMenu::menusGroupId() const
{
    return d->menus_group_id;
}

void MenusGroupMenu::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

int MenusGroupMenu::menuId() const
{
    return d->menu_id;
}

void MenusGroupMenu::setMenuId(int menuId)
{
    d->menu_id = menuId;
}

bool MenusGroupMenu::breakBool() const
{
    return d->break_bool;
}

void MenusGroupMenu::setBreakBool(bool breakBool)
{
    d->break_bool = breakBool;
}

int MenusGroupMenu::menuOrder() const
{
    return d->menu_order;
}

void MenusGroupMenu::setMenuOrder(int menuOrder)
{
    d->menu_order = menuOrder;
}

QDateTime MenusGroupMenu::createdAt() const
{
    return d->created_at;
}

QString MenusGroupMenu::createdBy() const
{
    return d->created_by;
}

void MenusGroupMenu::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MenusGroupMenu::updatedAt() const
{
    return d->updated_at;
}

QString MenusGroupMenu::updatedBy() const
{
    return d->updated_by;
}

void MenusGroupMenu::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Menu MenusGroupMenu::menuBymenuId() const
{
 return Menu::get(d->menu_id);
}

MenusGroup MenusGroupMenu::menusGroupBymenusGroupId() const
{
 return MenusGroup::get(d->menus_group_id);
}

MenusGroupMenu &MenusGroupMenu::operator=(const MenusGroupMenu &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MenusGroupMenu MenusGroupMenu::create(int menusGroupId, int menuId, bool breakBool, int menuOrder, const QString &createdBy, const QString &updatedBy)
{
    MenusGroupMenuObject obj;
    obj.menus_group_id = menusGroupId;
    obj.menu_id = menuId;
    obj.break_bool = breakBool;
    obj.menu_order = menuOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MenusGroupMenu();
    }
    return MenusGroupMenu(obj);
}

MenusGroupMenu MenusGroupMenu::create(const QVariantMap &values)
{
    MenusGroupMenu model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MenusGroupMenu MenusGroupMenu::get(int menusGroupId, int menuId)
{
    TSqlORMapper<MenusGroupMenuObject> mapper;
    return MenusGroupMenu(mapper.findByPrimaryKey(QVariantList()<<QVariant(menusGroupId)<<QVariant(menuId)));
}

int MenusGroupMenu::count()
{
    TSqlORMapper<MenusGroupMenuObject> mapper;
    return mapper.findCount();
}

QList<MenusGroupMenu> MenusGroupMenu::getAll()
{
    return tfGetModelListByCriteria<MenusGroupMenu, MenusGroupMenuObject>();
}

TModelObject *MenusGroupMenu::modelData()
{
    return d.data();
}

const TModelObject *MenusGroupMenu::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MenusGroupMenu &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MenusGroupMenu &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MenusGroupMenu)
