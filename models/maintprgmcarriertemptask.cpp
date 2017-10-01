#include <TreeFrogModel>
#include "maintprgmcarriertemptask.h"
#include "maintprgmcarriertemptaskobject.h"
#include "carrier.h"
#include "tasktask.h"
#include "taskdefn.h"
#include "maintprgmdefn.h"

MaintPrgmCarrierTempTask::MaintPrgmCarrierTempTask()
    : TAbstractModel(), d(new MaintPrgmCarrierTempTaskObject())
{
    d->maint_prgm_defn_id = 0;
    d->task_defn_id = 0;
    d->task_id = 0;
    d->carrier_id = 0;
}

MaintPrgmCarrierTempTask::MaintPrgmCarrierTempTask(const MaintPrgmCarrierTempTask &other)
    : TAbstractModel(), d(new MaintPrgmCarrierTempTaskObject(*other.d))
{ }

MaintPrgmCarrierTempTask::MaintPrgmCarrierTempTask(const MaintPrgmCarrierTempTaskObject &object)
    : TAbstractModel(), d(new MaintPrgmCarrierTempTaskObject(object))
{ }

MaintPrgmCarrierTempTask::~MaintPrgmCarrierTempTask()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmCarrierTempTaskObject' is deleted.
}

int MaintPrgmCarrierTempTask::maintPrgmDefnId() const
{
    return d->maint_prgm_defn_id;
}

void MaintPrgmCarrierTempTask::setMaintPrgmDefnId(int maintPrgmDefnId)
{
    d->maint_prgm_defn_id = maintPrgmDefnId;
}

int MaintPrgmCarrierTempTask::taskDefnId() const
{
    return d->task_defn_id;
}

void MaintPrgmCarrierTempTask::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

int MaintPrgmCarrierTempTask::taskId() const
{
    return d->task_id;
}

void MaintPrgmCarrierTempTask::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int MaintPrgmCarrierTempTask::carrierId() const
{
    return d->carrier_id;
}

void MaintPrgmCarrierTempTask::setCarrierId(int carrierId)
{
    d->carrier_id = carrierId;
}

QDateTime MaintPrgmCarrierTempTask::createdAt() const
{
    return d->created_at;
}

QString MaintPrgmCarrierTempTask::createdBy() const
{
    return d->created_by;
}

void MaintPrgmCarrierTempTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgmCarrierTempTask::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgmCarrierTempTask::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgmCarrierTempTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Carrier MaintPrgmCarrierTempTask::carrierBycarrierId() const
{
 return Carrier::get(d->carrier_id);
}

TaskTask MaintPrgmCarrierTempTask::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskDefn MaintPrgmCarrierTempTask::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

MaintPrgmDefn MaintPrgmCarrierTempTask::maintPrgmDefnBymaintPrgmDefnId() const
{
 return MaintPrgmDefn::get(d->maint_prgm_defn_id);
}

MaintPrgmCarrierTempTask &MaintPrgmCarrierTempTask::operator=(const MaintPrgmCarrierTempTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgmCarrierTempTask MaintPrgmCarrierTempTask::create(int maintPrgmDefnId, int taskDefnId, int taskId, int carrierId, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmCarrierTempTaskObject obj;
    obj.maint_prgm_defn_id = maintPrgmDefnId;
    obj.task_defn_id = taskDefnId;
    obj.task_id = taskId;
    obj.carrier_id = carrierId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgmCarrierTempTask();
    }
    return MaintPrgmCarrierTempTask(obj);
}

MaintPrgmCarrierTempTask MaintPrgmCarrierTempTask::create(const QVariantMap &values)
{
    MaintPrgmCarrierTempTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgmCarrierTempTask MaintPrgmCarrierTempTask::get(int maintPrgmDefnId, int taskDefnId, int taskId, int carrierId)
{
    TSqlORMapper<MaintPrgmCarrierTempTaskObject> mapper;
    return MaintPrgmCarrierTempTask(mapper.findByPrimaryKey(QVariantList()<<QVariant(maintPrgmDefnId)<<QVariant(taskDefnId)<<QVariant(taskId)<<QVariant(carrierId)));
}

int MaintPrgmCarrierTempTask::count()
{
    TSqlORMapper<MaintPrgmCarrierTempTaskObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgmCarrierTempTask> MaintPrgmCarrierTempTask::getAll()
{
    return tfGetModelListByCriteria<MaintPrgmCarrierTempTask, MaintPrgmCarrierTempTaskObject>();
}

TModelObject *MaintPrgmCarrierTempTask::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgmCarrierTempTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgmCarrierTempTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgmCarrierTempTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgmCarrierTempTask)
