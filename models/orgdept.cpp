#include <TreeFrogModel>
#include "orgdept.h"
#include "orgdeptobject.h"
#include "org.h"
#include "dept.h"

OrgDept::OrgDept()
    : TAbstractModel(), d(new OrgDeptObject())
{
    d->dept_id = 0;
    d->org_id = 0;
}

OrgDept::OrgDept(const OrgDept &other)
    : TAbstractModel(), d(new OrgDeptObject(*other.d))
{ }

OrgDept::OrgDept(const OrgDeptObject &object)
    : TAbstractModel(), d(new OrgDeptObject(object))
{ }

OrgDept::~OrgDept()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgDeptObject' is deleted.
}

int OrgDept::deptId() const
{
    return d->dept_id;
}

void OrgDept::setDeptId(int deptId)
{
    d->dept_id = deptId;
}

int OrgDept::orgId() const
{
    return d->org_id;
}

void OrgDept::setOrgId(int orgId)
{
    d->org_id = orgId;
}

bool OrgDept::primaryBool() const
{
    return d->primary_bool;
}

void OrgDept::setPrimaryBool(bool primaryBool)
{
    d->primary_bool = primaryBool;
}

QDateTime OrgDept::createdAt() const
{
    return d->created_at;
}

QString OrgDept::createdBy() const
{
    return d->created_by;
}

void OrgDept::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OrgDept::updatedAt() const
{
    return d->updated_at;
}

QString OrgDept::updatedBy() const
{
    return d->updated_by;
}

void OrgDept::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Org OrgDept::orgByorgId() const
{
 return Org::get(d->org_id);
}

Dept OrgDept::deptBydeptId() const
{
 return Dept::get(d->dept_id);
}

OrgDept &OrgDept::operator=(const OrgDept &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OrgDept OrgDept::create(int deptId, int orgId, bool primaryBool, const QString &createdBy, const QString &updatedBy)
{
    OrgDeptObject obj;
    obj.dept_id = deptId;
    obj.org_id = orgId;
    obj.primary_bool = primaryBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OrgDept();
    }
    return OrgDept(obj);
}

OrgDept OrgDept::create(const QVariantMap &values)
{
    OrgDept model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OrgDept OrgDept::get(int deptId, int orgId)
{
    TSqlORMapper<OrgDeptObject> mapper;
    return OrgDept(mapper.findByPrimaryKey(QVariantList()<<QVariant(deptId)<<QVariant(orgId)));
}

int OrgDept::count()
{
    TSqlORMapper<OrgDeptObject> mapper;
    return mapper.findCount();
}

QList<OrgDept> OrgDept::getAll()
{
    return tfGetModelListByCriteria<OrgDept, OrgDeptObject>();
}

TModelObject *OrgDept::modelData()
{
    return d.data();
}

const TModelObject *OrgDept::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OrgDept &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OrgDept &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OrgDept)
