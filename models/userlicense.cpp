#include <TreeFrogModel>
#include "userlicense.h"
#include "userlicenseobject.h"
#include "license.h"
#include "userapp.h"

UserLicense::UserLicense()
    : TAbstractModel(), d(new UserLicenseObject())
{
    d->user_id = 0;
    d->license_id = 0;
}

UserLicense::UserLicense(const UserLicense &other)
    : TAbstractModel(), d(new UserLicenseObject(*other.d))
{ }

UserLicense::UserLicense(const UserLicenseObject &object)
    : TAbstractModel(), d(new UserLicenseObject(object))
{ }

UserLicense::~UserLicense()
{
    // If the reference count becomes 0,
    // the shared data object 'UserLicenseObject' is deleted.
}

int UserLicense::userId() const
{
    return d->user_id;
}

void UserLicense::setUserId(int userId)
{
    d->user_id = userId;
}

int UserLicense::licenseId() const
{
    return d->license_id;
}

void UserLicense::setLicenseId(int licenseId)
{
    d->license_id = licenseId;
}

QDateTime UserLicense::expiryDt() const
{
    return d->expiry_dt;
}

void UserLicense::setExpiryDt(const QDateTime &expiryDt)
{
    d->expiry_dt = expiryDt;
}

bool UserLicense::suspendedBool() const
{
    return d->suspended_bool;
}

void UserLicense::setSuspendedBool(bool suspendedBool)
{
    d->suspended_bool = suspendedBool;
}

bool UserLicense::activeBool() const
{
    return d->active_bool;
}

void UserLicense::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime UserLicense::createdAt() const
{
    return d->created_at;
}

QString UserLicense::createdBy() const
{
    return d->created_by;
}

void UserLicense::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserLicense::updatedAt() const
{
    return d->updated_at;
}

QString UserLicense::updatedBy() const
{
    return d->updated_by;
}

void UserLicense::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

License UserLicense::licenseBylicenseId() const
{
 return License::get(d->license_id);
}

UserApp UserLicense::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserLicense &UserLicense::operator=(const UserLicense &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserLicense UserLicense::create(int userId, int licenseId, const QDateTime &expiryDt, bool suspendedBool, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    UserLicenseObject obj;
    obj.user_id = userId;
    obj.license_id = licenseId;
    obj.expiry_dt = expiryDt;
    obj.suspended_bool = suspendedBool;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserLicense();
    }
    return UserLicense(obj);
}

UserLicense UserLicense::create(const QVariantMap &values)
{
    UserLicense model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserLicense UserLicense::get(int userId, int licenseId)
{
    TSqlORMapper<UserLicenseObject> mapper;
    return UserLicense(mapper.findByPrimaryKey(QVariantList()<<QVariant(userId)<<QVariant(licenseId)));
}

int UserLicense::count()
{
    TSqlORMapper<UserLicenseObject> mapper;
    return mapper.findCount();
}

QList<UserLicense> UserLicense::getAll()
{
    return tfGetModelListByCriteria<UserLicense, UserLicenseObject>();
}

TModelObject *UserLicense::modelData()
{
    return d.data();
}

const TModelObject *UserLicense::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserLicense &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserLicense &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserLicense)
