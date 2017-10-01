#include <TreeFrogModel>
#include "advsrytaskdept.h"
#include "advsrytaskdeptobject.h"
#include "dept.h"
#include "advsrytask.h"

AdvsryTaskDept::AdvsryTaskDept()
    : TAbstractModel(), d(new AdvsryTaskDeptObject())
{
    d->advsry_task_id = 0;
    d->dept_id = 0;
}

AdvsryTaskDept::AdvsryTaskDept(const AdvsryTaskDept &other)
    : TAbstractModel(), d(new AdvsryTaskDeptObject(*other.d))
{ }

AdvsryTaskDept::AdvsryTaskDept(const AdvsryTaskDeptObject &object)
    : TAbstractModel(), d(new AdvsryTaskDeptObject(object))
{ }

AdvsryTaskDept::~AdvsryTaskDept()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryTaskDeptObject' is deleted.
}

int AdvsryTaskDept::advsryTaskId() const
{
    return d->advsry_task_id;
}

void AdvsryTaskDept::setAdvsryTaskId(int advsryTaskId)
{
    d->advsry_task_id = advsryTaskId;
}

int AdvsryTaskDept::deptId() const
{
    return d->dept_id;
}

void AdvsryTaskDept::setDeptId(int deptId)
{
    d->dept_id = deptId;
}

QDateTime AdvsryTaskDept::createdAt() const
{
    return d->created_at;
}

QString AdvsryTaskDept::createdBy() const
{
    return d->created_by;
}

void AdvsryTaskDept::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryTaskDept::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryTaskDept::updatedBy() const
{
    return d->updated_by;
}

void AdvsryTaskDept::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Dept AdvsryTaskDept::deptBydeptId() const
{
 return Dept::get(d->dept_id);
}

AdvsryTask AdvsryTaskDept::advsryTaskByadvsryTaskId() const
{
 return AdvsryTask::get(d->advsry_task_id);
}

AdvsryTaskDept &AdvsryTaskDept::operator=(const AdvsryTaskDept &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryTaskDept AdvsryTaskDept::create(int advsryTaskId, int deptId, const QString &createdBy, const QString &updatedBy)
{
    AdvsryTaskDeptObject obj;
    obj.advsry_task_id = advsryTaskId;
    obj.dept_id = deptId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryTaskDept();
    }
    return AdvsryTaskDept(obj);
}

AdvsryTaskDept AdvsryTaskDept::create(const QVariantMap &values)
{
    AdvsryTaskDept model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryTaskDept AdvsryTaskDept::get(int advsryTaskId, int deptId)
{
    TSqlORMapper<AdvsryTaskDeptObject> mapper;
    return AdvsryTaskDept(mapper.findByPrimaryKey(QVariantList()<<QVariant(advsryTaskId)<<QVariant(deptId)));
}

int AdvsryTaskDept::count()
{
    TSqlORMapper<AdvsryTaskDeptObject> mapper;
    return mapper.findCount();
}

QList<AdvsryTaskDept> AdvsryTaskDept::getAll()
{
    return tfGetModelListByCriteria<AdvsryTaskDept, AdvsryTaskDeptObject>();
}

TModelObject *AdvsryTaskDept::modelData()
{
    return d.data();
}

const TModelObject *AdvsryTaskDept::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryTaskDept &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryTaskDept &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryTaskDept)
