#include <TreeFrogModel>
#include "userauthority.h"
#include "userauthorityobject.h"
#include "authority.h"
#include "userapp.h"

UserAuthority::UserAuthority()
    : TAbstractModel(), d(new UserAuthorityObject())
{
    d->user_id = 0;
    d->authority_id = 0;
}

UserAuthority::UserAuthority(const UserAuthority &other)
    : TAbstractModel(), d(new UserAuthorityObject(*other.d))
{ }

UserAuthority::UserAuthority(const UserAuthorityObject &object)
    : TAbstractModel(), d(new UserAuthorityObject(object))
{ }

UserAuthority::~UserAuthority()
{
    // If the reference count becomes 0,
    // the shared data object 'UserAuthorityObject' is deleted.
}

int UserAuthority::userId() const
{
    return d->user_id;
}

void UserAuthority::setUserId(int userId)
{
    d->user_id = userId;
}

int UserAuthority::authorityId() const
{
    return d->authority_id;
}

void UserAuthority::setAuthorityId(int authorityId)
{
    d->authority_id = authorityId;
}

QDateTime UserAuthority::createdAt() const
{
    return d->created_at;
}

QString UserAuthority::createdBy() const
{
    return d->created_by;
}

void UserAuthority::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserAuthority::updatedAt() const
{
    return d->updated_at;
}

QString UserAuthority::updatedBy() const
{
    return d->updated_by;
}

void UserAuthority::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Authority UserAuthority::authorityByauthorityId() const
{
 return Authority::get(d->authority_id);
}

UserApp UserAuthority::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserAuthority &UserAuthority::operator=(const UserAuthority &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserAuthority UserAuthority::create(int userId, int authorityId, const QString &createdBy, const QString &updatedBy)
{
    UserAuthorityObject obj;
    obj.user_id = userId;
    obj.authority_id = authorityId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserAuthority();
    }
    return UserAuthority(obj);
}

UserAuthority UserAuthority::create(const QVariantMap &values)
{
    UserAuthority model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserAuthority UserAuthority::get(int userId, int authorityId)
{
    TSqlORMapper<UserAuthorityObject> mapper;
    return UserAuthority(mapper.findByPrimaryKey(QVariantList()<<QVariant(userId)<<QVariant(authorityId)));
}

int UserAuthority::count()
{
    TSqlORMapper<UserAuthorityObject> mapper;
    return mapper.findCount();
}

QList<UserAuthority> UserAuthority::getAll()
{
    return tfGetModelListByCriteria<UserAuthority, UserAuthorityObject>();
}

TModelObject *UserAuthority::modelData()
{
    return d.data();
}

const TModelObject *UserAuthority::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserAuthority &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserAuthority &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserAuthority)
