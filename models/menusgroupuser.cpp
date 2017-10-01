#include <TreeFrogModel>
#include "menusgroupuser.h"
#include "menusgroupuserobject.h"
#include "userapp.h"
#include "menusgroup.h"

MenusGroupUser::MenusGroupUser()
    : TAbstractModel(), d(new MenusGroupUserObject())
{
    d->menus_group_id = 0;
    d->user_id = 0;
    d->menus_group_order = 0;
}

MenusGroupUser::MenusGroupUser(const MenusGroupUser &other)
    : TAbstractModel(), d(new MenusGroupUserObject(*other.d))
{ }

MenusGroupUser::MenusGroupUser(const MenusGroupUserObject &object)
    : TAbstractModel(), d(new MenusGroupUserObject(object))
{ }

MenusGroupUser::~MenusGroupUser()
{
    // If the reference count becomes 0,
    // the shared data object 'MenusGroupUserObject' is deleted.
}

int MenusGroupUser::menusGroupId() const
{
    return d->menus_group_id;
}

void MenusGroupUser::setMenusGroupId(int menusGroupId)
{
    d->menus_group_id = menusGroupId;
}

int MenusGroupUser::userId() const
{
    return d->user_id;
}

void MenusGroupUser::setUserId(int userId)
{
    d->user_id = userId;
}

int MenusGroupUser::menusGroupOrder() const
{
    return d->menus_group_order;
}

void MenusGroupUser::setMenusGroupOrder(int menusGroupOrder)
{
    d->menus_group_order = menusGroupOrder;
}

QDateTime MenusGroupUser::createdAt() const
{
    return d->created_at;
}

QString MenusGroupUser::createdBy() const
{
    return d->created_by;
}

void MenusGroupUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MenusGroupUser::updatedAt() const
{
    return d->updated_at;
}

QString MenusGroupUser::updatedBy() const
{
    return d->updated_by;
}

void MenusGroupUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp MenusGroupUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

MenusGroup MenusGroupUser::menusGroupBymenusGroupId() const
{
 return MenusGroup::get(d->menus_group_id);
}

MenusGroupUser &MenusGroupUser::operator=(const MenusGroupUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MenusGroupUser MenusGroupUser::create(int menusGroupId, int userId, int menusGroupOrder, const QString &createdBy, const QString &updatedBy)
{
    MenusGroupUserObject obj;
    obj.menus_group_id = menusGroupId;
    obj.user_id = userId;
    obj.menus_group_order = menusGroupOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MenusGroupUser();
    }
    return MenusGroupUser(obj);
}

MenusGroupUser MenusGroupUser::create(const QVariantMap &values)
{
    MenusGroupUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MenusGroupUser MenusGroupUser::get(int menusGroupId, int userId)
{
    TSqlORMapper<MenusGroupUserObject> mapper;
    return MenusGroupUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(menusGroupId)<<QVariant(userId)));
}

int MenusGroupUser::count()
{
    TSqlORMapper<MenusGroupUserObject> mapper;
    return mapper.findCount();
}

QList<MenusGroupUser> MenusGroupUser::getAll()
{
    return tfGetModelListByCriteria<MenusGroupUser, MenusGroupUserObject>();
}

TModelObject *MenusGroupUser::modelData()
{
    return d.data();
}

const TModelObject *MenusGroupUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MenusGroupUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MenusGroupUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MenusGroupUser)
