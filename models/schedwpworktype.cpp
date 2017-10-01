#include <TreeFrogModel>
#include "schedwpworktype.h"
#include "schedwpworktypeobject.h"
#include "worktype.h"
#include "schedwp.h"

SchedWpWorkType::SchedWpWorkType()
    : TAbstractModel(), d(new SchedWpWorkTypeObject())
{
    d->sched_id = 0;
    d->work_type_id = 0;
}

SchedWpWorkType::SchedWpWorkType(const SchedWpWorkType &other)
    : TAbstractModel(), d(new SchedWpWorkTypeObject(*other.d))
{ }

SchedWpWorkType::SchedWpWorkType(const SchedWpWorkTypeObject &object)
    : TAbstractModel(), d(new SchedWpWorkTypeObject(object))
{ }

SchedWpWorkType::~SchedWpWorkType()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedWpWorkTypeObject' is deleted.
}

int SchedWpWorkType::schedId() const
{
    return d->sched_id;
}

void SchedWpWorkType::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedWpWorkType::workTypeId() const
{
    return d->work_type_id;
}

void SchedWpWorkType::setWorkTypeId(int workTypeId)
{
    d->work_type_id = workTypeId;
}

QDateTime SchedWpWorkType::createdAt() const
{
    return d->created_at;
}

QString SchedWpWorkType::createdBy() const
{
    return d->created_by;
}

void SchedWpWorkType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedWpWorkType::updatedAt() const
{
    return d->updated_at;
}

QString SchedWpWorkType::updatedBy() const
{
    return d->updated_by;
}

void SchedWpWorkType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

WorkType SchedWpWorkType::workTypeByworkTypeId() const
{
 return WorkType::get(d->work_type_id);
}

SchedWp SchedWpWorkType::schedWpByschedId() const
{
 return SchedWp::get(d->sched_id);
}

SchedWpWorkType &SchedWpWorkType::operator=(const SchedWpWorkType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedWpWorkType SchedWpWorkType::create(int schedId, int workTypeId, const QString &createdBy, const QString &updatedBy)
{
    SchedWpWorkTypeObject obj;
    obj.sched_id = schedId;
    obj.work_type_id = workTypeId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedWpWorkType();
    }
    return SchedWpWorkType(obj);
}

SchedWpWorkType SchedWpWorkType::create(const QVariantMap &values)
{
    SchedWpWorkType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedWpWorkType SchedWpWorkType::get(int schedId, int workTypeId)
{
    TSqlORMapper<SchedWpWorkTypeObject> mapper;
    return SchedWpWorkType(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(workTypeId)));
}

int SchedWpWorkType::count()
{
    TSqlORMapper<SchedWpWorkTypeObject> mapper;
    return mapper.findCount();
}

QList<SchedWpWorkType> SchedWpWorkType::getAll()
{
    return tfGetModelListByCriteria<SchedWpWorkType, SchedWpWorkTypeObject>();
}

TModelObject *SchedWpWorkType::modelData()
{
    return d.data();
}

const TModelObject *SchedWpWorkType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedWpWorkType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedWpWorkType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedWpWorkType)
