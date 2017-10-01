#include <TreeFrogModel>
#include "userpoauthlvl.h"
#include "userpoauthlvlobject.h"
#include "currency.h"
#include "userapp.h"

UserPoAuthLvl::UserPoAuthLvl()
    : TAbstractModel(), d(new UserPoAuthLvlObject())
{
    d->user_id = 0;
    d->currency_id = 0;
    d->auth_lvl_limit = 0;
}

UserPoAuthLvl::UserPoAuthLvl(const UserPoAuthLvl &other)
    : TAbstractModel(), d(new UserPoAuthLvlObject(*other.d))
{ }

UserPoAuthLvl::UserPoAuthLvl(const UserPoAuthLvlObject &object)
    : TAbstractModel(), d(new UserPoAuthLvlObject(object))
{ }

UserPoAuthLvl::~UserPoAuthLvl()
{
    // If the reference count becomes 0,
    // the shared data object 'UserPoAuthLvlObject' is deleted.
}

int UserPoAuthLvl::userId() const
{
    return d->user_id;
}

void UserPoAuthLvl::setUserId(int userId)
{
    d->user_id = userId;
}

int UserPoAuthLvl::currencyId() const
{
    return d->currency_id;
}

void UserPoAuthLvl::setCurrencyId(int currencyId)
{
    d->currency_id = currencyId;
}

double UserPoAuthLvl::authLvlLimit() const
{
    return d->auth_lvl_limit;
}

void UserPoAuthLvl::setAuthLvlLimit(double authLvlLimit)
{
    d->auth_lvl_limit = authLvlLimit;
}

bool UserPoAuthLvl::activeBool() const
{
    return d->active_bool;
}

void UserPoAuthLvl::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime UserPoAuthLvl::createdAt() const
{
    return d->created_at;
}

QString UserPoAuthLvl::createdBy() const
{
    return d->created_by;
}

void UserPoAuthLvl::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserPoAuthLvl::updatedAt() const
{
    return d->updated_at;
}

QString UserPoAuthLvl::updatedBy() const
{
    return d->updated_by;
}

void UserPoAuthLvl::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Currency UserPoAuthLvl::currencyBycurrencyId() const
{
 return Currency::get(d->currency_id);
}

UserApp UserPoAuthLvl::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserPoAuthLvl &UserPoAuthLvl::operator=(const UserPoAuthLvl &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserPoAuthLvl UserPoAuthLvl::create(int userId, int currencyId, double authLvlLimit, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    UserPoAuthLvlObject obj;
    obj.user_id = userId;
    obj.currency_id = currencyId;
    obj.auth_lvl_limit = authLvlLimit;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserPoAuthLvl();
    }
    return UserPoAuthLvl(obj);
}

UserPoAuthLvl UserPoAuthLvl::create(const QVariantMap &values)
{
    UserPoAuthLvl model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserPoAuthLvl UserPoAuthLvl::get(int userId, int currencyId)
{
    TSqlORMapper<UserPoAuthLvlObject> mapper;
    return UserPoAuthLvl(mapper.findByPrimaryKey(QVariantList()<<QVariant(userId)<<QVariant(currencyId)));
}

int UserPoAuthLvl::count()
{
    TSqlORMapper<UserPoAuthLvlObject> mapper;
    return mapper.findCount();
}

QList<UserPoAuthLvl> UserPoAuthLvl::getAll()
{
    return tfGetModelListByCriteria<UserPoAuthLvl, UserPoAuthLvlObject>();
}

TModelObject *UserPoAuthLvl::modelData()
{
    return d.data();
}

const TModelObject *UserPoAuthLvl::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserPoAuthLvl &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserPoAuthLvl &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserPoAuthLvl)
