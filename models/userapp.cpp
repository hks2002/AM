#include <TreeFrogModel>
#include "userapp.h"
#include "userappobject.h"

UserApp::UserApp()
    : TAbstractUser(), TAbstractModel(), d(new UserAppObject())
{
    d->user_id = 0;
}

UserApp::UserApp(const UserApp &other)
    : TAbstractUser(), TAbstractModel(), d(new UserAppObject(*other.d))
{ }

UserApp::UserApp(const UserAppObject &object)
    : TAbstractUser(), TAbstractModel(), d(new UserAppObject(object))
{ }


UserApp::~UserApp()
{
    // If the reference count becomes 0,
    // the shared data object 'UserAppObject' is deleted.
}

int UserApp::userId() const
{
    return d->user_id;
}

QString UserApp::userName() const
{
    return d->user_name;
}

void UserApp::setUserName(const QString &userName)
{
    d->user_name = userName;
}

QString UserApp::fullNameZh() const
{
    return d->full_name_zh;
}

void UserApp::setFullNameZh(const QString &fullNameZh)
{
    d->full_name_zh = fullNameZh;
}

QString UserApp::fullNameEn() const
{
    return d->full_name_en;
}

void UserApp::setFullNameEn(const QString &fullNameEn)
{
    d->full_name_en = fullNameEn;
}

QString UserApp::hrCd() const
{
    return d->hr_cd;
}

void UserApp::setHrCd(const QString &hrCd)
{
    d->hr_cd = hrCd;
}

QString UserApp::password() const
{
    return d->password;
}

void UserApp::setPassword(const QString &password)
{
    d->password = password;
}

QString UserApp::emailAddr() const
{
    return d->email_addr;
}

void UserApp::setEmailAddr(const QString &emailAddr)
{
    d->email_addr = emailAddr;
}

bool UserApp::lockedBool() const
{
    return d->locked_bool;
}

void UserApp::setLockedBool(bool lockedBool)
{
    d->locked_bool = lockedBool;
}

QDateTime UserApp::createdAt() const
{
    return d->created_at;
}

QString UserApp::createdBy() const
{
    return d->created_by;
}

void UserApp::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime UserApp::updatedAt() const
{
    return d->updated_at;
}

QString UserApp::updatedBy() const
{
    return d->updated_by;
}

void UserApp::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp &UserApp::operator=(const UserApp &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

UserApp UserApp::authenticate(const QString &userName, const QString &password)
{
    if (userName.isEmpty() || password.isEmpty())
    { return UserApp(); }

    TSqlORMapper<UserAppObject> mapper;
    UserAppObject obj = mapper.findFirst(TCriteria(UserAppObject::UserName, userName));

    if (obj.isNull() || obj.password != password) {
        obj.clear();
    }

    return UserApp(obj);
}

UserApp UserApp::create(const QString &userName, const QString &fullNameZh, const QString &fullNameEn, const QString &hrCd, const QString &password, const QString &emailAddr, bool lockedBool, const QString &createdBy, const QString &updatedBy)
{
    UserAppObject obj;
    obj.user_name = userName;
    obj.full_name_zh = fullNameZh;
    obj.full_name_en = fullNameEn;
    obj.hr_cd = hrCd;
    obj.password = password;
    obj.email_addr = emailAddr;
    obj.locked_bool = lockedBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;

    if (!obj.create()) {
        return UserApp();
    }

    return UserApp(obj);
}

UserApp UserApp::create(const QVariantMap &values)
{
    UserApp model;
    model.setProperties(values);

    if (!model.d->create()) {
        model.d->clear();
    }

    return model;
}

UserApp UserApp::get(int userId)
{
    TSqlORMapper<UserAppObject> mapper;
    return UserApp(mapper.findByPrimaryKey(userId));
}

UserApp UserApp::getByIdentityKey(const QString &userName)
{
    TSqlORMapper<UserAppObject> mapper;
    TCriteria cri(UserAppObject::UserName, userName);
    return UserApp(mapper.findFirst(cri));
}

int UserApp::count()
{
    TSqlORMapper<UserAppObject> mapper;
    return mapper.findCount();
}

QList<UserApp> UserApp::getAll()
{
    return tfGetModelListByCriteria<UserApp, UserAppObject>();
}

TModelObject *UserApp::modelData()
{
    return d.data();
}

const TModelObject *UserApp::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const UserApp &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, UserApp &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(UserApp)
