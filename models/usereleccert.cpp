#include <TreeFrogModel>
#include "usereleccert.h"
#include "usereleccertobject.h"
#include "userapp.h"

UserElecCert::UserElecCert()
    : TAbstractModel(), d(new UserElecCertObject())
{
    d->user_elec_cert_id = 0;
    d->user_id = 0;
}

UserElecCert::UserElecCert(const UserElecCert &other)
    : TAbstractModel(), d(new UserElecCertObject(*other.d))
{ }

UserElecCert::UserElecCert(const UserElecCertObject &object)
    : TAbstractModel(), d(new UserElecCertObject(object))
{ }

UserElecCert::~UserElecCert()
{
    // If the reference count becomes 0,
    // the shared data object 'UserElecCertObject' is deleted.
}

int UserElecCert::userElecCertId() const
{
    return d->user_elec_cert_id;
}

int UserElecCert::userId() const
{
    return d->user_id;
}

void UserElecCert::setUserId(int userId)
{
    d->user_id = userId;
}

QByteArray UserElecCert::handSignImg() const
{
    return d->hand_sign_img;
}

void UserElecCert::setHandSignImg(const QByteArray &handSignImg)
{
    d->hand_sign_img = handSignImg;
}

QString UserElecCert::publicKey() const
{
    return d->public_key;
}

void UserElecCert::setPublicKey(const QString &publicKey)
{
    d->public_key = publicKey;
}

QDateTime UserElecCert::issueDt() const
{
    return d->issue_dt;
}

void UserElecCert::setIssueDt(const QDateTime &issueDt)
{
    d->issue_dt = issueDt;
}

QDateTime UserElecCert::expireDt() const
{
    return d->expire_dt;
}

void UserElecCert::setExpireDt(const QDateTime &expireDt)
{
    d->expire_dt = expireDt;
}

bool UserElecCert::activeBool() const
{
    return d->active_bool;
}

void UserElecCert::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime UserElecCert::createdAt() const
{
    return d->created_at;
}

QString UserElecCert::createdBy() const
{
    return d->created_by;
}

void UserElecCert::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserElecCert::updatedAt() const
{
    return d->updated_at;
}

QString UserElecCert::updatedBy() const
{
    return d->updated_by;
}

void UserElecCert::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp UserElecCert::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

UserElecCert &UserElecCert::operator=(const UserElecCert &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserElecCert UserElecCert::create(int userId, const QByteArray &handSignImg, const QString &publicKey, const QDateTime &issueDt, const QDateTime &expireDt, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    UserElecCertObject obj;
    obj.user_id = userId;
    obj.hand_sign_img = handSignImg;
    obj.public_key = publicKey;
    obj.issue_dt = issueDt;
    obj.expire_dt = expireDt;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return UserElecCert();
    }
    return UserElecCert(obj);
}

UserElecCert UserElecCert::create(const QVariantMap &values)
{
    UserElecCert model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

UserElecCert UserElecCert::get(int userElecCertId)
{
    TSqlORMapper<UserElecCertObject> mapper;
    return UserElecCert(mapper.findByPrimaryKey(userElecCertId));
}

int UserElecCert::count()
{
    TSqlORMapper<UserElecCertObject> mapper;
    return mapper.findCount();
}

QList<UserElecCert> UserElecCert::getAll()
{
    return tfGetModelListByCriteria<UserElecCert, UserElecCertObject>();
}

TModelObject *UserElecCert::modelData()
{
    return d.data();
}

const TModelObject *UserElecCert::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserElecCert &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserElecCert &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserElecCert)
