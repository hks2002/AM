#include <TreeFrogModel>
#include "dept.h"
#include "deptobject.h"

Dept::Dept()
    : TAbstractModel(), d(new DeptObject())
{
    d->dept_id = 0;
}

Dept::Dept(const Dept &other)
    : TAbstractModel(), d(new DeptObject(*other.d))
{ }

Dept::Dept(const DeptObject &object)
    : TAbstractModel(), d(new DeptObject(object))
{ }

Dept::~Dept()
{
    // If the reference count becomes 0,
    // the shared data object 'DeptObject' is deleted.
}

int Dept::deptId() const
{
    return d->dept_id;
}

QString Dept::deptCd() const
{
    return d->dept_cd;
}

void Dept::setDeptCd(const QString &deptCd)
{
    d->dept_cd = deptCd;
}

QString Dept::deptNameZh() const
{
    return d->dept_name_zh;
}

void Dept::setDeptNameZh(const QString &deptNameZh)
{
    d->dept_name_zh = deptNameZh;
}

QString Dept::deptNameEn() const
{
    return d->dept_name_en;
}

void Dept::setDeptNameEn(const QString &deptNameEn)
{
    d->dept_name_en = deptNameEn;
}

QString Dept::deptDesc() const
{
    return d->dept_desc;
}

void Dept::setDeptDesc(const QString &deptDesc)
{
    d->dept_desc = deptDesc;
}

QDateTime Dept::createdAt() const
{
    return d->created_at;
}

QString Dept::createdBy() const
{
    return d->created_by;
}

void Dept::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Dept::updatedAt() const
{
    return d->updated_at;
}

QString Dept::updatedBy() const
{
    return d->updated_by;
}

void Dept::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Dept &Dept::operator=(const Dept &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Dept Dept::create(const QString &deptCd, const QString &deptNameZh, const QString &deptNameEn, const QString &deptDesc, const QString &createdBy, const QString &updatedBy)
{
    DeptObject obj;
    obj.dept_cd = deptCd;
    obj.dept_name_zh = deptNameZh;
    obj.dept_name_en = deptNameEn;
    obj.dept_desc = deptDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Dept();
    }
    return Dept(obj);
}

Dept Dept::create(const QVariantMap &values)
{
    Dept model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Dept Dept::get(int deptId)
{
    TSqlORMapper<DeptObject> mapper;
    return Dept(mapper.findByPrimaryKey(deptId));
}

int Dept::count()
{
    TSqlORMapper<DeptObject> mapper;
    return mapper.findCount();
}

QList<Dept> Dept::getAll()
{
    return tfGetModelListByCriteria<Dept, DeptObject>();
}

TModelObject *Dept::modelData()
{
    return d.data();
}

const TModelObject *Dept::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Dept &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Dept &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Dept)
