#include <TreeFrogModel>
#include "schedwpmpc.h"
#include "schedwpmpcobject.h"
#include "tasktask.h"
#include "schedwp.h"

SchedWpMpc::SchedWpMpc()
    : TAbstractModel(), d(new SchedWpMpcObject())
{
    d->sched_id = 0;
    d->task_id = 0;
}

SchedWpMpc::SchedWpMpc(const SchedWpMpc &other)
    : TAbstractModel(), d(new SchedWpMpcObject(*other.d))
{ }

SchedWpMpc::SchedWpMpc(const SchedWpMpcObject &object)
    : TAbstractModel(), d(new SchedWpMpcObject(object))
{ }

SchedWpMpc::~SchedWpMpc()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedWpMpcObject' is deleted.
}

int SchedWpMpc::schedId() const
{
    return d->sched_id;
}

void SchedWpMpc::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedWpMpc::taskId() const
{
    return d->task_id;
}

void SchedWpMpc::setTaskId(int taskId)
{
    d->task_id = taskId;
}

QDateTime SchedWpMpc::createdAt() const
{
    return d->created_at;
}

QString SchedWpMpc::createdBy() const
{
    return d->created_by;
}

void SchedWpMpc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedWpMpc::updatedAt() const
{
    return d->updated_at;
}

QString SchedWpMpc::updatedBy() const
{
    return d->updated_by;
}

void SchedWpMpc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskTask SchedWpMpc::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

SchedWp SchedWpMpc::schedWpByschedId() const
{
 return SchedWp::get(d->sched_id);
}

SchedWpMpc &SchedWpMpc::operator=(const SchedWpMpc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedWpMpc SchedWpMpc::create(int schedId, int taskId, const QString &createdBy, const QString &updatedBy)
{
    SchedWpMpcObject obj;
    obj.sched_id = schedId;
    obj.task_id = taskId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedWpMpc();
    }
    return SchedWpMpc(obj);
}

SchedWpMpc SchedWpMpc::create(const QVariantMap &values)
{
    SchedWpMpc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedWpMpc SchedWpMpc::get(int schedId, int taskId)
{
    TSqlORMapper<SchedWpMpcObject> mapper;
    return SchedWpMpc(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedId)<<QVariant(taskId)));
}

int SchedWpMpc::count()
{
    TSqlORMapper<SchedWpMpcObject> mapper;
    return mapper.findCount();
}

QList<SchedWpMpc> SchedWpMpc::getAll()
{
    return tfGetModelListByCriteria<SchedWpMpc, SchedWpMpcObject>();
}

TModelObject *SchedWpMpc::modelData()
{
    return d.data();
}

const TModelObject *SchedWpMpc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedWpMpc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedWpMpc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedWpMpc)
