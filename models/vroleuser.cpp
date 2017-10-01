#include <TreeFrogModel>
#include "vroleuser.h"
#include "vroleuserobject.h"

VRoleUser::VRoleUser()
    : TAbstractModel(), d(new VRoleUserObject())
{
    d->role_id = 0;
    d->user_id = 0;
}

VRoleUser::VRoleUser(const VRoleUser &other)
    : TAbstractModel(), d(new VRoleUserObject(*other.d))
{ }

VRoleUser::VRoleUser(const VRoleUserObject &object)
    : TAbstractModel(), d(new VRoleUserObject(object))
{ }

VRoleUser::~VRoleUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VRoleUserObject' is deleted.
}

int VRoleUser::roleId() const
{
    return d->role_id;
}

void VRoleUser::setRoleId(int roleId)
{
    d->role_id = roleId;
}

QString VRoleUser::roleCd() const
{
    return d->role_cd;
}

void VRoleUser::setRoleCd(const QString &roleCd)
{
    d->role_cd = roleCd;
}

QString VRoleUser::roleNameZh() const
{
    return d->role_name_zh;
}

void VRoleUser::setRoleNameZh(const QString &roleNameZh)
{
    d->role_name_zh = roleNameZh;
}

QString VRoleUser::roleNameEn() const
{
    return d->role_name_en;
}

void VRoleUser::setRoleNameEn(const QString &roleNameEn)
{
    d->role_name_en = roleNameEn;
}

int VRoleUser::userId() const
{
    return d->user_id;
}

void VRoleUser::setUserId(int userId)
{
    d->user_id = userId;
}

QString VRoleUser::userName() const
{
    return d->user_name;
}

void VRoleUser::setUserName(const QString &userName)
{
    d->user_name = userName;
}

QString VRoleUser::hrCd() const
{
    return d->hr_cd;
}

void VRoleUser::setHrCd(const QString &hrCd)
{
    d->hr_cd = hrCd;
}

QString VRoleUser::fullNameZh() const
{
    return d->full_name_zh;
}

void VRoleUser::setFullNameZh(const QString &fullNameZh)
{
    d->full_name_zh = fullNameZh;
}

QString VRoleUser::fullNameEn() const
{
    return d->full_name_en;
}

void VRoleUser::setFullNameEn(const QString &fullNameEn)
{
    d->full_name_en = fullNameEn;
}

VRoleUser &VRoleUser::operator=(const VRoleUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VRoleUser VRoleUser::create(int roleId, const QString &roleCd, const QString &roleNameZh, const QString &roleNameEn, int userId, const QString &userName, const QString &hrCd, const QString &fullNameZh, const QString &fullNameEn)
{
    VRoleUserObject obj;
    obj.role_id = roleId;
    obj.role_cd = roleCd;
    obj.role_name_zh = roleNameZh;
    obj.role_name_en = roleNameEn;
    obj.user_id = userId;
    obj.user_name = userName;
    obj.hr_cd = hrCd;
    obj.full_name_zh = fullNameZh;
    obj.full_name_en = fullNameEn;
    if (!obj.create()) {
        return VRoleUser();
    }
    return VRoleUser(obj);
}

VRoleUser VRoleUser::create(const QVariantMap &values)
{
    VRoleUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VRoleUser VRoleUser::get(int roleId, const QString &roleCd, const QString &roleNameZh, const QString &roleNameEn, int userId, const QString &userName, const QString &hrCd, const QString &fullNameZh, const QString &fullNameEn)
{
    TCriteria cri;
    cri.add(VRoleUserObject::RoleId, roleId);
    cri.add(VRoleUserObject::RoleCd, roleCd);
    cri.add(VRoleUserObject::RoleNameZh, roleNameZh);
    cri.add(VRoleUserObject::RoleNameEn, roleNameEn);
    cri.add(VRoleUserObject::UserId, userId);
    cri.add(VRoleUserObject::UserName, userName);
    cri.add(VRoleUserObject::HrCd, hrCd);
    cri.add(VRoleUserObject::FullNameZh, fullNameZh);
    cri.add(VRoleUserObject::FullNameEn, fullNameEn);
    TSqlORMapper<VRoleUserObject> mapper;
    return VRoleUser(mapper.findFirst(cri));
}

int VRoleUser::count()
{
    TSqlORMapper<VRoleUserObject> mapper;
    return mapper.findCount();
}

QList<VRoleUser> VRoleUser::getAll()
{
    return tfGetModelListByCriteria<VRoleUser, VRoleUserObject>();
}

TModelObject *VRoleUser::modelData()
{
    return d.data();
}

const TModelObject *VRoleUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VRoleUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VRoleUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VRoleUser)
