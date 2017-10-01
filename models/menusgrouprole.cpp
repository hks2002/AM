#include <TreeFrogModel>
#include "menusgrouprole.h"
#include "menusgrouproleobject.h"
#include "roleapp.h"
#include "menusgroup.h"

MenusGroupRole::MenusGroupRole()
    : TAbstractModel(), d(new MenusGroupRoleObject())
{
    d->menus_group_id = 0;
    d->role_id = 0;
    d->menus_group_order = 0;
}

MenusGroupRole::MenusGroupRole(const MenusGroupRole &other)
    : TAbstractModel(), d(new MenusGroupRoleObject(*other.d))
{ }

MenusGroupRole::MenusGroupRole(const MenusGroupRoleObject &object)
    : TAbstractModel(), d(new MenusGroupRoleObject(object))
{ }

MenusGroupRole::~MenusGroupRole()
{
    // If the reference count becomes 0,
    // the shared data object 'MenusGroupRoleObject' is deleted.
}

int MenusGroupRole::menusGroupId() const
{
    return d->menus_group_id;
}

void MenusGroupRole::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

int MenusGroupRole::roleId() const
{
    return d->role_id;
}

void MenusGroupRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int MenusGroupRole::menusGroupOrder() const
{
    return d->menus_group_order;
}

void MenusGroupRole::setMenusGroupOrder(int menusGroupOrder)
{
    d->menus_group_order = menusGroupOrder;
}

QDateTime MenusGroupRole::createdAt() const
{
    return d->created_at;
}

QString MenusGroupRole::createdBy() const
{
    return d->created_by;
}

void MenusGroupRole::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MenusGroupRole::updatedAt() const
{
    return d->updated_at;
}

QString MenusGroupRole::updatedBy() const
{
    return d->updated_by;
}

void MenusGroupRole::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RoleApp MenusGroupRole::roleAppByroleId() const
{
 return RoleApp::get(d->role_id);
}

MenusGroup MenusGroupRole::menusGroupBymenusGroupId() const
{
 return MenusGroup::get(d->menus_group_id);
}

MenusGroupRole &MenusGroupRole::operator=(const MenusGroupRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MenusGroupRole MenusGroupRole::create(int menusGroupId, int roleId, int menusGroupOrder, const QString &createdBy, const QString &updatedBy)
{
    MenusGroupRoleObject obj;
    obj.menus_group_id = menusGroupId;
    obj.role_id = roleId;
    obj.menus_group_order = menusGroupOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MenusGroupRole();
    }
    return MenusGroupRole(obj);
}

MenusGroupRole MenusGroupRole::create(const QVariantMap &values)
{
    MenusGroupRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MenusGroupRole MenusGroupRole::get(int menusGroupId, int roleId)
{
    TSqlORMapper<MenusGroupRoleObject> mapper;
    return MenusGroupRole(mapper.findByPrimaryKey(QVariantList()<<QVariant(menusGroupId)<<QVariant(roleId)));
}

int MenusGroupRole::count()
{
    TSqlORMapper<MenusGroupRoleObject> mapper;
    return mapper.findCount();
}

QList<MenusGroupRole> MenusGroupRole::getAll()
{
    return tfGetModelListByCriteria<MenusGroupRole, MenusGroupRoleObject>();
}

TModelObject *MenusGroupRole::modelData()
{
    return d.data();
}

const TModelObject *MenusGroupRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MenusGroupRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MenusGroupRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MenusGroupRole)
