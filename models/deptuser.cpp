#include <TreeFrogModel>
#include "deptuser.h"
#include "deptuserobject.h"
#include "userapp.h"
#include "dept.h"

DeptUser::DeptUser()
    : TAbstractModel(), d(new DeptUserObject())
{
    d->dept_id = 0;
    d->user_id = 0;
}

DeptUser::DeptUser(const DeptUser &other)
    : TAbstractModel(), d(new DeptUserObject(*other.d))
{ }

DeptUser::DeptUser(const DeptUserObject &object)
    : TAbstractModel(), d(new DeptUserObject(object))
{ }

DeptUser::~DeptUser()
{
    // If the reference count becomes 0,
    // the shared data object 'DeptUserObject' is deleted.
}

int DeptUser::deptId() const
{
    return d->dept_id;
}

void DeptUser::setDeptId(int deptId)
{
    d->dept_id = deptId;
}

int DeptUser::userId() const
{
    return d->user_id;
}

void DeptUser::setUserId(int userId)
{
    d->user_id = userId;
}

bool DeptUser::defaultBool() const
{
    return d->default_bool;
}

void DeptUser::setDefaultBool(bool defaultBool)
{
    d->default_bool = defaultBool;
}

QDateTime DeptUser::createdAt() const
{
    return d->created_at;
}

QString DeptUser::createdBy() const
{
    return d->created_by;
}

void DeptUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime DeptUser::updatedAt() const
{
    return d->updated_at;
}

QString DeptUser::updatedBy() const
{
    return d->updated_by;
}

void DeptUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp DeptUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

Dept DeptUser::deptBydeptId() const
{
 return Dept::get(d->dept_id);
}

DeptUser &DeptUser::operator=(const DeptUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

DeptUser DeptUser::create(int deptId, int userId, bool defaultBool, const QString &createdBy, const QString &updatedBy)
{
    DeptUserObject obj;
    obj.dept_id = deptId;
    obj.user_id = userId;
    obj.default_bool = defaultBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return DeptUser();
    }
    return DeptUser(obj);
}

DeptUser DeptUser::create(const QVariantMap &values)
{
    DeptUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

DeptUser DeptUser::get(int deptId, int userId)
{
    TSqlORMapper<DeptUserObject> mapper;
    return DeptUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(deptId)<<QVariant(userId)));
}

int DeptUser::count()
{
    TSqlORMapper<DeptUserObject> mapper;
    return mapper.findCount();
}

QList<DeptUser> DeptUser::getAll()
{
    return tfGetModelListByCriteria<DeptUser, DeptUserObject>();
}

TModelObject *DeptUser::modelData()
{
    return d.data();
}

const TModelObject *DeptUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const DeptUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, DeptUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(DeptUser)
