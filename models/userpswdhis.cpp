#include <TreeFrogModel>
#include "userpswdhis.h"
#include "userpswdhisobject.h"
#include "userapp.h"

UserPswdHis::UserPswdHis()
    : TAbstractModel(), d(new UserPswdHisObject())
{
    d->user_pswd_his_id = 0;
    d->user_id = 0;
}

UserPswdHis::UserPswdHis(const UserPswdHis &other)
    : TAbstractModel(), d(new UserPswdHisObject(*other.d))
{ }

UserPswdHis::UserPswdHis(const UserPswdHisObject &object)
    : TAbstractModel(), d(new UserPswdHisObject(object))
{ }

UserPswdHis::~UserPswdHis()
{
    // If the reference count becomes 0,
    // the shared data object 'UserPswdHisObject' is deleted.
}

int UserPswdHis::userPswdHisId() const
{
    return d->user_pswd_his_id;
}

int UserPswdHis::userId() const
{
    return d->user_id;
}

void UserPswdHis::setUserId(int userId)
{
    d->user_id = userId;
}

QString UserPswdHis::password() const
{
    return d->password;
}

void UserPswdHis::setPassword(const QString &password)
{
    d->password = password;
}

QDateTime UserPswdHis::createdAt() const
{
    return d->created_at;
}

QString UserPswdHis::createdBy() const
{
    return d->created_by;
}

void UserPswdHis::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserPswdHis::updatedAt() const
{
    return d->updated_at;
}

QString UserPswdHis::updatedBy() const
{
    return d->updated_by;
}

void UserPswdHis::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp UserPswdHis::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserPswdHis &UserPswdHis::operator=(const UserPswdHis &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserPswdHis UserPswdHis::create(int userId, const QString &password, const QString &createdBy, const QString &updatedBy)
{
    UserPswdHisObject obj;
    obj.user_id = userId;
    obj.password = password;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserPswdHis();
    }
    return UserPswdHis(obj);
}

UserPswdHis UserPswdHis::create(const QVariantMap &values)
{
    UserPswdHis model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserPswdHis UserPswdHis::get(int userPswdHisId)
{
    TSqlORMapper<UserPswdHisObject> mapper;
    return UserPswdHis(mapper.findByPrimaryKey(userPswdHisId));
}

int UserPswdHis::count()
{
    TSqlORMapper<UserPswdHisObject> mapper;
    return mapper.findCount();
}

QList<UserPswdHis> UserPswdHis::getAll()
{
    return tfGetModelListByCriteria<UserPswdHis, UserPswdHisObject>();
}

TModelObject *UserPswdHis::modelData()
{
    return d.data();
}

const TModelObject *UserPswdHis::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserPswdHis &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserPswdHis &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserPswdHis)
