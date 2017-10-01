#include <TreeFrogModel>
#include "advsrytaskrole.h"
#include "advsrytaskroleobject.h"
#include "roleapp.h"
#include "advsrytask.h"

AdvsryTaskRole::AdvsryTaskRole()
    : TAbstractModel(), d(new AdvsryTaskRoleObject())
{
    d->advsry_task_id = 0;
    d->role_id = 0;
}

AdvsryTaskRole::AdvsryTaskRole(const AdvsryTaskRole &other)
    : TAbstractModel(), d(new AdvsryTaskRoleObject(*other.d))
{ }

AdvsryTaskRole::AdvsryTaskRole(const AdvsryTaskRoleObject &object)
    : TAbstractModel(), d(new AdvsryTaskRoleObject(object))
{ }

AdvsryTaskRole::~AdvsryTaskRole()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryTaskRoleObject' is deleted.
}

int AdvsryTaskRole::advsryTaskId() const
{
    return d->advsry_task_id;
}

void AdvsryTaskRole::setAdvsryTaskId(int advsryTaskId)
{
    d->advsry_task_id = advsryTaskId;
}

int AdvsryTaskRole::roleId() const
{
    return d->role_id;
}

void AdvsryTaskRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

QDateTime AdvsryTaskRole::createdAt() const
{
    return d->created_at;
}

QString AdvsryTaskRole::createdBy() const
{
    return d->created_by;
}

void AdvsryTaskRole::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryTaskRole::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryTaskRole::updatedBy() const
{
    return d->updated_by;
}

void AdvsryTaskRole::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RoleApp AdvsryTaskRole::roleAppByroleId() const
{
 return RoleApp::get(d->role_id);
}

AdvsryTask AdvsryTaskRole::advsryTaskByadvsryTaskId() const
{
 return AdvsryTask::get(d->advsry_task_id);
}

AdvsryTaskRole &AdvsryTaskRole::operator=(const AdvsryTaskRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryTaskRole AdvsryTaskRole::create(int advsryTaskId, int roleId, const QString &createdBy, const QString &updatedBy)
{
    AdvsryTaskRoleObject obj;
    obj.advsry_task_id = advsryTaskId;
    obj.role_id = roleId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryTaskRole();
    }
    return AdvsryTaskRole(obj);
}

AdvsryTaskRole AdvsryTaskRole::create(const QVariantMap &values)
{
    AdvsryTaskRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryTaskRole AdvsryTaskRole::get(int advsryTaskId, int roleId)
{
    TSqlORMapper<AdvsryTaskRoleObject> mapper;
    return AdvsryTaskRole(mapper.findByPrimaryKey(QVariantList()<<QVariant(advsryTaskId)<<QVariant(roleId)));
}

int AdvsryTaskRole::count()
{
    TSqlORMapper<AdvsryTaskRoleObject> mapper;
    return mapper.findCount();
}

QList<AdvsryTaskRole> AdvsryTaskRole::getAll()
{
    return tfGetModelListByCriteria<AdvsryTaskRole, AdvsryTaskRoleObject>();
}

TModelObject *AdvsryTaskRole::modelData()
{
    return d.data();
}

const TModelObject *AdvsryTaskRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryTaskRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryTaskRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryTaskRole)
