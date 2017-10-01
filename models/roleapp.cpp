#include <TreeFrogModel>
#include "roleapp.h"
#include "roleappobject.h"

RoleApp::RoleApp()
    : TAbstractModel(), d(new RoleAppObject())
{
    d->role_id = 0;
}

RoleApp::RoleApp(const RoleApp &other)
    : TAbstractModel(), d(new RoleAppObject(*other.d))
{ }

RoleApp::RoleApp(const RoleAppObject &object)
    : TAbstractModel(), d(new RoleAppObject(object))
{ }

RoleApp::~RoleApp()
{
    // If the reference count becomes 0,
    // the shared data object 'RoleAppObject' is deleted.
}

int RoleApp::roleId() const
{
    return d->role_id;
}

QString RoleApp::roleCd() const
{
    return d->role_cd;
}

void RoleApp::setRoleCd(const QString &roleCd)
{
    d->role_cd = roleCd;
}

QString RoleApp::roleNameZh() const
{
    return d->role_name_zh;
}

void RoleApp::setRoleNameZh(const QString &roleNameZh)
{
    d->role_name_zh = roleNameZh;
}

QString RoleApp::roleNameEn() const
{
    return d->role_name_en;
}

void RoleApp::setRoleNameEn(const QString &roleNameEn)
{
    d->role_name_en = roleNameEn;
}

QDateTime RoleApp::createdAt() const
{
    return d->created_at;
}

QString RoleApp::createdBy() const
{
    return d->created_by;
}

void RoleApp::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RoleApp::updatedAt() const
{
    return d->updated_at;
}

QString RoleApp::updatedBy() const
{
    return d->updated_by;
}

void RoleApp::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RoleApp &RoleApp::operator=(const RoleApp &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RoleApp RoleApp::create(const QString &roleCd, const QString &roleNameZh, const QString &roleNameEn, const QString &createdBy, const QString &updatedBy)
{
    RoleAppObject obj;
    obj.role_cd = roleCd;
    obj.role_name_zh = roleNameZh;
    obj.role_name_en = roleNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RoleApp();
    }
    return RoleApp(obj);
}

RoleApp RoleApp::create(const QVariantMap &values)
{
    RoleApp model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RoleApp RoleApp::get(int roleId)
{
    TSqlORMapper<RoleAppObject> mapper;
    return RoleApp(mapper.findByPrimaryKey(roleId));
}

int RoleApp::count()
{
    TSqlORMapper<RoleAppObject> mapper;
    return mapper.findCount();
}

QList<RoleApp> RoleApp::getAll()
{
    return tfGetModelListByCriteria<RoleApp, RoleAppObject>();
}

TModelObject *RoleApp::modelData()
{
    return d.data();
}

const TModelObject *RoleApp::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RoleApp &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RoleApp &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RoleApp)
