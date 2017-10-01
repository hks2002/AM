#include <TreeFrogModel>
#include "menu.h"
#include "menuobject.h"

Menu::Menu()
    : TAbstractModel(), d(new MenuObject())
{
    d->menu_id = 0;
}

Menu::Menu(const Menu &other)
    : TAbstractModel(), d(new MenuObject(*other.d))
{ }

Menu::Menu(const MenuObject &object)
    : TAbstractModel(), d(new MenuObject(object))
{ }

Menu::~Menu()
{
    // If the reference count becomes 0,
    // the shared data object 'MenuObject' is deleted.
}

int Menu::menuId() const
{
    return d->menu_id;
}

QString Menu::menuCd() const
{
    return d->menu_cd;
}

void Menu::setMenuCd(const QString &menuCd)
{
    d->menu_cd = menuCd;
}

QString Menu::menuNameZh() const
{
    return d->menu_name_zh;
}

void Menu::setMenuNameZh(const QString &menuNameZh)
{
    d->menu_name_zh = menuNameZh;
}

QString Menu::menuNameEn() const
{
    return d->menu_name_en;
}

void Menu::setMenuNameEn(const QString &menuNameEn)
{
    d->menu_name_en = menuNameEn;
}

QString Menu::menuTooltip() const
{
    return d->menu_tooltip;
}

void Menu::setMenuTooltip(const QString &menuTooltip)
{
    d->menu_tooltip = menuTooltip;
}

QString Menu::menuDesc() const
{
    return d->menu_desc;
}

void Menu::setMenuDesc(const QString &menuDesc)
{
    d->menu_desc = menuDesc;
}

QString Menu::controller() const
{
    return d->controller;
}

void Menu::setController(const QString &controller)
{
    d->controller = controller;
}

QString Menu::action() const
{
    return d->action;
}

void Menu::setAction(const QString &action)
{
    d->action = action;
}

QDateTime Menu::createdAt() const
{
    return d->created_at;
}

QString Menu::createdBy() const
{
    return d->created_by;
}

void Menu::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Menu::updatedAt() const
{
    return d->updated_at;
}

QString Menu::updatedBy() const
{
    return d->updated_by;
}

void Menu::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Menu &Menu::operator=(const Menu &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Menu Menu::create(const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, const QString &createdBy, const QString &updatedBy)
{
    MenuObject obj;
    obj.menu_cd = menuCd;
    obj.menu_name_zh = menuNameZh;
    obj.menu_name_en = menuNameEn;
    obj.menu_tooltip = menuTooltip;
    obj.menu_desc = menuDesc;
    obj.controller = controller;
    obj.action = action;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Menu();
    }
    return Menu(obj);
}

Menu Menu::create(const QVariantMap &values)
{
    Menu model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Menu Menu::get(int menuId)
{
    TSqlORMapper<MenuObject> mapper;
    return Menu(mapper.findByPrimaryKey(menuId));
}

int Menu::count()
{
    TSqlORMapper<MenuObject> mapper;
    return mapper.findCount();
}

QList<Menu> Menu::getAll()
{
    return tfGetModelListByCriteria<Menu, MenuObject>();
}

TModelObject *Menu::modelData()
{
    return d.data();
}

const TModelObject *Menu::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Menu &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Menu &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Menu)
