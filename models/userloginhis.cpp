#include <TreeFrogModel>
#include "userloginhis.h"
#include "userloginhisobject.h"
#include "userapp.h"

UserLoginHis::UserLoginHis()
    : TAbstractModel(), d(new UserLoginHisObject())
{
    d->user_login_his_id = 0;
    d->user_id = 0;
}

UserLoginHis::UserLoginHis(const UserLoginHis &other)
    : TAbstractModel(), d(new UserLoginHisObject(*other.d))
{ }

UserLoginHis::UserLoginHis(const UserLoginHisObject &object)
    : TAbstractModel(), d(new UserLoginHisObject(object))
{ }

UserLoginHis::~UserLoginHis()
{
    // If the reference count becomes 0,
    // the shared data object 'UserLoginHisObject' is deleted.
}

int UserLoginHis::userLoginHisId() const
{
    return d->user_login_his_id;
}

int UserLoginHis::userId() const
{
    return d->user_id;
}

void UserLoginHis::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime UserLoginHis::loginDt() const
{
    return d->login_dt;
}

void UserLoginHis::setLoginDt(const QDateTime &loginDt)
{
    d->login_dt = loginDt;
}

QString UserLoginHis::loginIp() const
{
    return d->login_ip;
}

void UserLoginHis::setLoginIp(const QString &loginIp)
{
    d->login_ip = loginIp;
}

QString UserLoginHis::loginMac() const
{
    return d->login_mac;
}

void UserLoginHis::setLoginMac(const QString &loginMac)
{
    d->login_mac = loginMac;
}

QString UserLoginHis::loginComputer() const
{
    return d->login_computer;
}

void UserLoginHis::setLoginComputer(const QString &loginComputer)
{
    d->login_computer = loginComputer;
}

QDateTime UserLoginHis::createdAt() const
{
    return d->created_at;
}

QString UserLoginHis::createdBy() const
{
    return d->created_by;
}

void UserLoginHis::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserLoginHis::updatedAt() const
{
    return d->updated_at;
}

QString UserLoginHis::updatedBy() const
{
    return d->updated_by;
}

void UserLoginHis::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp UserLoginHis::userAppByuserId() const
{
    return UserApp::get(d->user_id);
}

UserLoginHis &UserLoginHis::operator=(const UserLoginHis &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserLoginHis UserLoginHis::create(int userId, const QDateTime &loginDt, const QString &loginIp, const QString &loginMac, const QString &loginComputer)
{
    UserLoginHisObject obj;
    obj.user_id = userId;
    obj.login_dt = loginDt;
    obj.login_ip = loginIp;
    obj.login_mac = loginMac;
    obj.login_computer = loginComputer;

    if (!obj.create()) {
        return UserLoginHis();
    }

    return UserLoginHis(obj);
}

UserLoginHis UserLoginHis::create(const QVariantMap &values)
{
    UserLoginHis model;
    model.setProperties(values);

    if (!model.d->create()) {
        model.d->clear();
    }

    return model;
}

UserLoginHis UserLoginHis::get(int userLoginHisId)
{
    TSqlORMapper<UserLoginHisObject> mapper;
    return UserLoginHis(mapper.findByPrimaryKey(userLoginHisId));
}

int UserLoginHis::count()
{
    TSqlORMapper<UserLoginHisObject> mapper;
    return mapper.findCount();
}

QList<UserLoginHis> UserLoginHis::getAll()
{
    return tfGetModelListByCriteria<UserLoginHis, UserLoginHisObject>();
}

TModelObject *UserLoginHis::modelData()
{
    return d.data();
}

const TModelObject *UserLoginHis::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserLoginHis &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserLoginHis &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserLoginHis)
