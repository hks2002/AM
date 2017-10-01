#include <TreeFrogModel>
#include "schedstaskflags.h"
#include "schedstaskflagsobject.h"
#include "schedstask.h"

SchedStaskFlags::SchedStaskFlags()
    : TAbstractModel(), d(new SchedStaskFlagsObject())
{
    d->sched_id = 0;
}

SchedStaskFlags::SchedStaskFlags(const SchedStaskFlags &other)
    : TAbstractModel(), d(new SchedStaskFlagsObject(*other.d))
{ }

SchedStaskFlags::SchedStaskFlags(const SchedStaskFlagsObject &object)
    : TAbstractModel(), d(new SchedStaskFlagsObject(object))
{ }

SchedStaskFlags::~SchedStaskFlags()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedStaskFlagsObject' is deleted.
}

int SchedStaskFlags::schedId() const
{
    return d->sched_id;
}

void SchedStaskFlags::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

bool SchedStaskFlags::preventExeBool() const
{
    return d->prevent_exe_bool;
}

void SchedStaskFlags::setPreventExeBool(bool preventExeBool)
{
    d->prevent_exe_bool = preventExeBool;
}

QDateTime SchedStaskFlags::preventExeReviewDt() const
{
    return d->prevent_exe_review_dt;
}

void SchedStaskFlags::setPreventExeReviewDt(const QDateTime &preventExeReviewDt)
{
    d->prevent_exe_review_dt = preventExeReviewDt;
}

bool SchedStaskFlags::etopsBool() const
{
    return d->etops_bool;
}

void SchedStaskFlags::setEtopsBool(bool etopsBool)
{
    d->etops_bool = etopsBool;
}

bool SchedStaskFlags::rvsmBool() const
{
    return d->rvsm_bool;
}

void SchedStaskFlags::setRvsmBool(bool rvsmBool)
{
    d->rvsm_bool = rvsmBool;
}

bool SchedStaskFlags::recurBool() const
{
    return d->recur_bool;
}

void SchedStaskFlags::setRecurBool(bool recurBool)
{
    d->recur_bool = recurBool;
}

bool SchedStaskFlags::corrFixBool() const
{
    return d->corr_fix_bool;
}

void SchedStaskFlags::setCorrFixBool(bool corrFixBool)
{
    d->corr_fix_bool = corrFixBool;
}

bool SchedStaskFlags::orphanFrctBool() const
{
    return d->orphan_frct_bool;
}

void SchedStaskFlags::setOrphanFrctBool(bool orphanFrctBool)
{
    d->orphan_frct_bool = orphanFrctBool;
}

bool SchedStaskFlags::partsReadyBool() const
{
    return d->parts_ready_bool;
}

void SchedStaskFlags::setPartsReadyBool(bool partsReadyBool)
{
    d->parts_ready_bool = partsReadyBool;
}

bool SchedStaskFlags::softDeadlineBool() const
{
    return d->soft_deadline_bool;
}

void SchedStaskFlags::setSoftDeadlineBool(bool softDeadlineBool)
{
    d->soft_deadline_bool = softDeadlineBool;
}

bool SchedStaskFlags::routineBool() const
{
    return d->routine_bool;
}

void SchedStaskFlags::setRoutineBool(bool routineBool)
{
    d->routine_bool = routineBool;
}

bool SchedStaskFlags::requestPartsBool() const
{
    return d->request_parts_bool;
}

void SchedStaskFlags::setRequestPartsBool(bool requestPartsBool)
{
    d->request_parts_bool = requestPartsBool;
}

bool SchedStaskFlags::resourceSumBool() const
{
    return d->resource_sum_bool;
}

void SchedStaskFlags::setResourceSumBool(bool resourceSumBool)
{
    d->resource_sum_bool = resourceSumBool;
}

bool SchedStaskFlags::toolsReadyBool() const
{
    return d->tools_ready_bool;
}

void SchedStaskFlags::setToolsReadyBool(bool toolsReadyBool)
{
    d->tools_ready_bool = toolsReadyBool;
}

bool SchedStaskFlags::taskLockBool() const
{
    return d->task_lock_bool;
}

void SchedStaskFlags::setTaskLockBool(bool taskLockBool)
{
    d->task_lock_bool = taskLockBool;
}

bool SchedStaskFlags::manualSchedBool() const
{
    return d->manual_sched_bool;
}

void SchedStaskFlags::setManualSchedBool(bool manualSchedBool)
{
    d->manual_sched_bool = manualSchedBool;
}

QDateTime SchedStaskFlags::createdAt() const
{
    return d->created_at;
}

QString SchedStaskFlags::createdBy() const
{
    return d->created_by;
}

void SchedStaskFlags::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedStaskFlags::updatedAt() const
{
    return d->updated_at;
}

QString SchedStaskFlags::updatedBy() const
{
    return d->updated_by;
}

void SchedStaskFlags::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

SchedStask SchedStaskFlags::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedStaskFlags &SchedStaskFlags::operator=(const SchedStaskFlags &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedStaskFlags SchedStaskFlags::create(int schedId, bool preventExeBool, const QDateTime &preventExeReviewDt, bool etopsBool, bool rvsmBool, bool recurBool, bool corrFixBool, bool orphanFrctBool, bool partsReadyBool, bool softDeadlineBool, bool routineBool, bool requestPartsBool, bool resourceSumBool, bool toolsReadyBool, bool taskLockBool, bool manualSchedBool, const QString &createdBy, const QString &updatedBy)
{
    SchedStaskFlagsObject obj;
    obj.sched_id = schedId;
    obj.prevent_exe_bool = preventExeBool;
    obj.prevent_exe_review_dt = preventExeReviewDt;
    obj.etops_bool = etopsBool;
    obj.rvsm_bool = rvsmBool;
    obj.recur_bool = recurBool;
    obj.corr_fix_bool = corrFixBool;
    obj.orphan_frct_bool = orphanFrctBool;
    obj.parts_ready_bool = partsReadyBool;
    obj.soft_deadline_bool = softDeadlineBool;
    obj.routine_bool = routineBool;
    obj.request_parts_bool = requestPartsBool;
    obj.resource_sum_bool = resourceSumBool;
    obj.tools_ready_bool = toolsReadyBool;
    obj.task_lock_bool = taskLockBool;
    obj.manual_sched_bool = manualSchedBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedStaskFlags();
    }
    return SchedStaskFlags(obj);
}

SchedStaskFlags SchedStaskFlags::create(const QVariantMap &values)
{
    SchedStaskFlags model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedStaskFlags SchedStaskFlags::get(int schedId)
{
    TSqlORMapper<SchedStaskFlagsObject> mapper;
    return SchedStaskFlags(mapper.findByPrimaryKey(schedId));
}

int SchedStaskFlags::count()
{
    TSqlORMapper<SchedStaskFlagsObject> mapper;
    return mapper.findCount();
}

QList<SchedStaskFlags> SchedStaskFlags::getAll()
{
    return tfGetModelListByCriteria<SchedStaskFlags, SchedStaskFlagsObject>();
}

TModelObject *SchedStaskFlags::modelData()
{
    return d.data();
}

const TModelObject *SchedStaskFlags::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedStaskFlags &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedStaskFlags &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedStaskFlags)
