#include <TreeFrogModel>
#include "deptsubdept.h"
#include "deptsubdeptobject.h"
#include "dept.h"

DeptSubdept::DeptSubdept()
    : TAbstractModel(), d(new DeptSubdeptObject())
{
    d->dept_id = 0;
    d->sub_dept_id = 0;
}

DeptSubdept::DeptSubdept(const DeptSubdept &other)
    : TAbstractModel(), d(new DeptSubdeptObject(*other.d))
{ }

DeptSubdept::DeptSubdept(const DeptSubdeptObject &object)
    : TAbstractModel(), d(new DeptSubdeptObject(object))
{ }

DeptSubdept::~DeptSubdept()
{
    // If the reference count becomes 0,
    // the shared data object 'DeptSubdeptObject' is deleted.
}

int DeptSubdept::deptId() const
{
    return d->dept_id;
}

void DeptSubdept::setDeptId(int deptId)
{
    d->dept_id = deptId;
}

int DeptSubdept::subDeptId() const
{
    return d->sub_dept_id;
}

void DeptSubdept::setSubDeptId(int subDeptId)
{
    d->sub_dept_id = subDeptId;
}

QDateTime DeptSubdept::createdAt() const
{
    return d->created_at;
}

QString DeptSubdept::createdBy() const
{
    return d->created_by;
}

void DeptSubdept::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime DeptSubdept::updatedAt() const
{
    return d->updated_at;
}

QString DeptSubdept::updatedBy() const
{
    return d->updated_by;
}

void DeptSubdept::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Dept DeptSubdept::deptBysubDeptId() const
{
 return Dept::get(d->sub_dept_id);
}

DeptSubdept &DeptSubdept::operator=(const DeptSubdept &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

DeptSubdept DeptSubdept::create(int deptId, int subDeptId, const QString &createdBy, const QString &updatedBy)
{
    DeptSubdeptObject obj;
    obj.dept_id = deptId;
    obj.sub_dept_id = subDeptId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return DeptSubdept();
    }
    return DeptSubdept(obj);
}

DeptSubdept DeptSubdept::create(const QVariantMap &values)
{
    DeptSubdept model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

DeptSubdept DeptSubdept::get(int deptId, int subDeptId)
{
    TSqlORMapper<DeptSubdeptObject> mapper;
    return DeptSubdept(mapper.findByPrimaryKey(QVariantList()<<QVariant(deptId)<<QVariant(subDeptId)));
}

int DeptSubdept::count()
{
    TSqlORMapper<DeptSubdeptObject> mapper;
    return mapper.findCount();
}

QList<DeptSubdept> DeptSubdept::getAll()
{
    return tfGetModelListByCriteria<DeptSubdept, DeptSubdeptObject>();
}

TModelObject *DeptSubdept::modelData()
{
    return d.data();
}

const TModelObject *DeptSubdept::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const DeptSubdept &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, DeptSubdept &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(DeptSubdept)
