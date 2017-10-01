#include <TreeFrogModel>
#include "alertdefdept.h"
#include "alertdefdeptobject.h"
#include "dept.h"
#include "alertdef.h"

AlertDefDept::AlertDefDept()
    : TAbstractModel(), d(new AlertDefDeptObject())
{
    d->alert_def_id = 0;
    d->dept_id = 0;
}

AlertDefDept::AlertDefDept(const AlertDefDept &other)
    : TAbstractModel(), d(new AlertDefDeptObject(*other.d))
{ }

AlertDefDept::AlertDefDept(const AlertDefDeptObject &object)
    : TAbstractModel(), d(new AlertDefDeptObject(object))
{ }

AlertDefDept::~AlertDefDept()
{
    // If the reference count becomes 0,
    // the shared data object 'AlertDefDeptObject' is deleted.
}

int AlertDefDept::alertDefId() const
{
    return d->alert_def_id;
}

void AlertDefDept::setAlertDefId(int alertDefId)
{
    d->alert_def_id = alertDefId;
}

int AlertDefDept::deptId() const
{
    return d->dept_id;
}

void AlertDefDept::setDeptId(int deptId)
{
    d->dept_id = deptId;
}

bool AlertDefDept::activeBool() const
{
    return d->active_bool;
}

void AlertDefDept::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime AlertDefDept::createdAt() const
{
    return d->created_at;
}

QString AlertDefDept::createdBy() const
{
    return d->created_by;
}

void AlertDefDept::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AlertDefDept::updatedAt() const
{
    return d->updated_at;
}

QString AlertDefDept::updatedBy() const
{
    return d->updated_by;
}

void AlertDefDept::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Dept AlertDefDept::deptBydeptId() const
{
 return Dept::get(d->dept_id);
}

AlertDef AlertDefDept::alertDefByalertDefId() const
{
 return AlertDef::get(d->alert_def_id);
}

AlertDefDept &AlertDefDept::operator=(const AlertDefDept &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AlertDefDept AlertDefDept::create(int alertDefId, int deptId, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    AlertDefDeptObject obj;
    obj.alert_def_id = alertDefId;
    obj.dept_id = deptId;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AlertDefDept();
    }
    return AlertDefDept(obj);
}

AlertDefDept AlertDefDept::create(const QVariantMap &values)
{
    AlertDefDept model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AlertDefDept AlertDefDept::get(int alertDefId, int deptId)
{
    TSqlORMapper<AlertDefDeptObject> mapper;
    return AlertDefDept(mapper.findByPrimaryKey(QVariantList()<<QVariant(alertDefId)<<QVariant(deptId)));
}

int AlertDefDept::count()
{
    TSqlORMapper<AlertDefDeptObject> mapper;
    return mapper.findCount();
}

QList<AlertDefDept> AlertDefDept::getAll()
{
    return tfGetModelListByCriteria<AlertDefDept, AlertDefDeptObject>();
}

TModelObject *AlertDefDept::modelData()
{
    return d.data();
}

const TModelObject *AlertDefDept::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AlertDefDept &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AlertDefDept &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AlertDefDept)
