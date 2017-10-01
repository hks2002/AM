#include <TreeFrogModel>
#include "worktype.h"
#include "worktypeobject.h"

WorkType::WorkType()
    : TAbstractModel(), d(new WorkTypeObject())
{
    d->work_type_id = 0;
}

WorkType::WorkType(const WorkType &other)
    : TAbstractModel(), d(new WorkTypeObject(*other.d))
{ }

WorkType::WorkType(const WorkTypeObject &object)
    : TAbstractModel(), d(new WorkTypeObject(object))
{ }

WorkType::~WorkType()
{
    // If the reference count becomes 0,
    // the shared data object 'WorkTypeObject' is deleted.
}

int WorkType::workTypeId() const
{
    return d->work_type_id;
}

QString WorkType::workTypeCd() const
{
    return d->work_type_cd;
}

void WorkType::setWorkTypeCd(const QString &workTypeCd)
{
    d->work_type_cd = workTypeCd;
}

QString WorkType::workTypeNameZh() const
{
    return d->work_type_name_zh;
}

void WorkType::setWorkTypeNameZh(const QString &workTypeNameZh)
{
    d->work_type_name_zh = workTypeNameZh;
}

QString WorkType::workTypeNameEn() const
{
    return d->work_type_name_en;
}

void WorkType::setWorkTypeNameEn(const QString &workTypeNameEn)
{
    d->work_type_name_en = workTypeNameEn;
}

QDateTime WorkType::createdAt() const
{
    return d->created_at;
}

QString WorkType::createdBy() const
{
    return d->created_by;
}

void WorkType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WorkType::updatedAt() const
{
    return d->updated_at;
}

QString WorkType::updatedBy() const
{
    return d->updated_by;
}

void WorkType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

WorkType &WorkType::operator=(const WorkType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WorkType WorkType::create(const QString &workTypeCd, const QString &workTypeNameZh, const QString &workTypeNameEn, const QString &createdBy, const QString &updatedBy)
{
    WorkTypeObject obj;
    obj.work_type_cd = workTypeCd;
    obj.work_type_name_zh = workTypeNameZh;
    obj.work_type_name_en = workTypeNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WorkType();
    }
    return WorkType(obj);
}

WorkType WorkType::create(const QVariantMap &values)
{
    WorkType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WorkType WorkType::get(int workTypeId)
{
    TSqlORMapper<WorkTypeObject> mapper;
    return WorkType(mapper.findByPrimaryKey(workTypeId));
}

int WorkType::count()
{
    TSqlORMapper<WorkTypeObject> mapper;
    return mapper.findCount();
}

QList<WorkType> WorkType::getAll()
{
    return tfGetModelListByCriteria<WorkType, WorkTypeObject>();
}

TModelObject *WorkType::modelData()
{
    return d.data();
}

const TModelObject *WorkType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WorkType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WorkType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WorkType)
