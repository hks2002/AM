#include <TreeFrogModel>
#include "menusgroup.h"
#include "menusgroupobject.h"

MenusGroup::MenusGroup()
    : TAbstractModel(), d(new MenusGroupObject())
{
    d->menus_group_id = 0;
}

MenusGroup::MenusGroup(const MenusGroup &other)
    : TAbstractModel(), d(new MenusGroupObject(*other.d))
{ }

MenusGroup::MenusGroup(const MenusGroupObject &object)
    : TAbstractModel(), d(new MenusGroupObject(object))
{ }

MenusGroup::~MenusGroup()
{
    // If the reference count becomes 0,
    // the shared data object 'MenusGroupObject' is deleted.
}

int MenusGroup::menusGroupId() const
{
    return d->menus_group_id;
}

QString MenusGroup::menusGroupCd() const
{
    return d->menus_group_cd;
}

void MenusGroup::setMenusGroupCd(const QString &menusGroupCd)
{
    d->menus_group_cd = menusGroupCd;
}

QString MenusGroup::menusGroupNameZh() const
{
    return d->menus_group_name_zh;
}

void MenusGroup::setMenusGroupNameZh(const QString &menusGroupNameZh)
{
    d->menus_group_name_zh = menusGroupNameZh;
}

QString MenusGroup::menusGroupNameEn() const
{
    return d->menus_group_name_en;
}

void MenusGroup::setMenusGroupNameEn(const QString &menusGroupNameEn)
{
    d->menus_group_name_en = menusGroupNameEn;
}

QString MenusGroup::menusGroupTooltip() const
{
    return d->menus_group_tooltip;
}

void MenusGroup::setMenusGroupTooltip(const QString &menusGroupTooltip)
{
    d->menus_group_tooltip = menusGroupTooltip;
}

QString MenusGroup::menusGroupDesc() const
{
    return d->menus_group_desc;
}

void MenusGroup::setMenusGroupDesc(const QString &menusGroupDesc)
{
    d->menus_group_desc = menusGroupDesc;
}

QDateTime MenusGroup::createdAt() const
{
    return d->created_at;
}

QString MenusGroup::createdBy() const
{
    return d->created_by;
}

void MenusGroup::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MenusGroup::updatedAt() const
{
    return d->updated_at;
}

QString MenusGroup::updatedBy() const
{
    return d->updated_by;
}

void MenusGroup::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MenusGroup &MenusGroup::operator=(const MenusGroup &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MenusGroup MenusGroup::create(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, const QString &createdBy, const QString &updatedBy)
{
    MenusGroupObject obj;
    obj.menus_group_cd = menusGroupCd;
    obj.menus_group_name_zh = menusGroupNameZh;
    obj.menus_group_name_en = menusGroupNameEn;
    obj.menus_group_tooltip = menusGroupTooltip;
    obj.menus_group_desc = menusGroupDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MenusGroup();
    }
    return MenusGroup(obj);
}

MenusGroup MenusGroup::create(const QVariantMap &values)
{
    MenusGroup model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MenusGroup MenusGroup::get(int menusGroupId)
{
    TSqlORMapper<MenusGroupObject> mapper;
    return MenusGroup(mapper.findByPrimaryKey(menusGroupId));
}

int MenusGroup::count()
{
    TSqlORMapper<MenusGroupObject> mapper;
    return mapper.findCount();
}

QList<MenusGroup> MenusGroup::getAll()
{
    return tfGetModelListByCriteria<MenusGroup, MenusGroupObject>();
}

TModelObject *MenusGroup::modelData()
{
    return d.data();
}

const TModelObject *MenusGroup::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MenusGroup &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MenusGroup &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MenusGroup)
