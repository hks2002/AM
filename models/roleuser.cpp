#include <TreeFrogModel>
#include "roleuser.h"
#include "roleuserobject.h"
#include "userapp.h"
#include "roleapp.h"

RoleUser::RoleUser()
    : TAbstractModel(), d(new RoleUserObject())
{
    d->role_id = 0;
    d->user_id = 0;
    d->role_order = 0;
}

RoleUser::RoleUser(const RoleUser &other)
    : TAbstractModel(), d(new RoleUserObject(*other.d))
{ }

RoleUser::RoleUser(const RoleUserObject &object)
    : TAbstractModel(), d(new RoleUserObject(object))
{ }

RoleUser::~RoleUser()
{
    // If the reference count becomes 0,
    // the shared data object 'RoleUserObject' is deleted.
}

int RoleUser::roleId() const
{
    return d->role_id;
}

void RoleUser::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int RoleUser::userId() const
{
    return d->user_id;
}

void RoleUser::setUserId(int userId)
{
    d->user_id = userId;
}

int RoleUser::roleOrder() const
{
    return d->role_order;
}

void RoleUser::setRoleOrder(int roleOrder)
{
    d->role_order = roleOrder;
}

QDateTime RoleUser::createdAt() const
{
    return d->created_at;
}

QString RoleUser::createdBy() const
{
    return d->created_by;
}

void RoleUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RoleUser::updatedAt() const
{
    return d->updated_at;
}

QString RoleUser::updatedBy() const
{
    return d->updated_by;
}

void RoleUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp RoleUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

RoleApp RoleUser::roleAppByroleId() const
{
 return RoleApp::get(d->role_id);
}

RoleUser &RoleUser::operator=(const RoleUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RoleUser RoleUser::create(int roleId, int userId, int roleOrder, const QString &createdBy, const QString &updatedBy)
{
    RoleUserObject obj;
    obj.role_id = roleId;
    obj.user_id = userId;
    obj.role_order = roleOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RoleUser();
    }
    return RoleUser(obj);
}

RoleUser RoleUser::create(const QVariantMap &values)
{
    RoleUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RoleUser RoleUser::get(int roleId, int userId)
{
    TSqlORMapper<RoleUserObject> mapper;
    return RoleUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(roleId)<<QVariant(userId)));
}

int RoleUser::count()
{
    TSqlORMapper<RoleUserObject> mapper;
    return mapper.findCount();
}

QList<RoleUser> RoleUser::getAll()
{
    return tfGetModelListByCriteria<RoleUser, RoleUserObject>();
}

TModelObject *RoleUser::modelData()
{
    return d.data();
}

const TModelObject *RoleUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RoleUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RoleUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RoleUser)
