#include <TreeFrogModel>
#include "tasktask.h"
#include "tasktaskobject.h"
#include "taskdefn.h"
#include "reftaskdefstatus.h"
#include "taskoriginator.h"
#include "reftaskclass.h"
#include "tasksubclass.h"
#include "reffirstschedfrom.h"
#include "refreschedfrom.h"
#include "refcreatewhen.h"
#include "refcancelwhen.h"
#include "userapp.h"

TaskTask::TaskTask()
    : TAbstractModel(), d(new TaskTaskObject())
{
    d->task_id = 0;
    d->task_defn_id = 0;
    d->task_originator_id = 0;
    d->task_subclass_id = 0;
    d->revision_ord = 0;
    d->prepared_by = 0;
    d->reviewed_by = 0;
    d->approved_by = 0;
    d->actived_by = 0;
    d->locked_by = 0;
}

TaskTask::TaskTask(const TaskTask &other)
    : TAbstractModel(), d(new TaskTaskObject(*other.d))
{ }

TaskTask::TaskTask(const TaskTaskObject &object)
    : TAbstractModel(), d(new TaskTaskObject(object))
{ }

TaskTask::~TaskTask()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskTaskObject' is deleted.
}

int TaskTask::taskId() const
{
    return d->task_id;
}

int TaskTask::taskDefnId() const
{
    return d->task_defn_id;
}

void TaskTask::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

QString TaskTask::taskDefStatusCd() const
{
    return d->task_def_status_cd;
}

void TaskTask::setTaskDefStatusCd(const QString &taskDefStatusCd)
{
    d->task_def_status_cd = taskDefStatusCd;
}

QString TaskTask::taskCd() const
{
    return d->task_cd;
}

void TaskTask::setTaskCd(const QString &taskCd)
{
    d->task_cd = taskCd;
}

QString TaskTask::taskName() const
{
    return d->task_name;
}

void TaskTask::setTaskName(const QString &taskName)
{
    d->task_name = taskName;
}

QString TaskTask::taskRefDesc() const
{
    return d->task_ref_desc;
}

void TaskTask::setTaskRefDesc(const QString &taskRefDesc)
{
    d->task_ref_desc = taskRefDesc;
}

QString TaskTask::taskDesc() const
{
    return d->task_desc;
}

void TaskTask::setTaskDesc(const QString &taskDesc)
{
    d->task_desc = taskDesc;
}

QString TaskTask::instructionDesc() const
{
    return d->instruction_desc;
}

void TaskTask::setInstructionDesc(const QString &instructionDesc)
{
    d->instruction_desc = instructionDesc;
}

QString TaskTask::engineeringDesc() const
{
    return d->engineering_desc;
}

void TaskTask::setEngineeringDesc(const QString &engineeringDesc)
{
    d->engineering_desc = engineeringDesc;
}

int TaskTask::taskOriginatorId() const
{
    return d->task_originator_id;
}

void TaskTask::setTaskOriginatorId(int taskOriginatorId)
{
    d->task_originator_id = taskOriginatorId;
}

QString TaskTask::taskClassCd() const
{
    return d->task_class_cd;
}

void TaskTask::setTaskClassCd(const QString &taskClassCd)
{
    d->task_class_cd = taskClassCd;
}

int TaskTask::taskSubclassId() const
{
    return d->task_subclass_id;
}

void TaskTask::setTaskSubclassId(int taskSubclassId)
{
    d->task_subclass_id = taskSubclassId;
}

bool TaskTask::taskMustRemoveCd() const
{
    return d->task_must_remove_cd;
}

void TaskTask::setTaskMustRemoveCd(bool taskMustRemoveCd)
{
    d->task_must_remove_cd = taskMustRemoveCd;
}

bool TaskTask::recurBool() const
{
    return d->recur_bool;
}

void TaskTask::setRecurBool(bool recurBool)
{
    d->recur_bool = recurBool;
}

QString TaskTask::firstSchedFromCd() const
{
    return d->first_sched_from_cd;
}

void TaskTask::setFirstSchedFromCd(const QString &firstSchedFromCd)
{
    d->first_sched_from_cd = firstSchedFromCd;
}

QString TaskTask::reschedFromCd() const
{
    return d->resched_from_cd;
}

void TaskTask::setReschedFromCd(const QString &reschedFromCd)
{
    d->resched_from_cd = reschedFromCd;
}

QString TaskTask::createWhenCd() const
{
    return d->create_when_cd;
}

void TaskTask::setCreateWhenCd(const QString &createWhenCd)
{
    d->create_when_cd = createWhenCd;
}

QString TaskTask::cancelWhenCd() const
{
    return d->cancel_when_cd;
}

void TaskTask::setCancelWhenCd(const QString &cancelWhenCd)
{
    d->cancel_when_cd = cancelWhenCd;
}

bool TaskTask::schedFromLatestBool() const
{
    return d->sched_from_latest_bool;
}

void TaskTask::setSchedFromLatestBool(bool schedFromLatestBool)
{
    d->sched_from_latest_bool = schedFromLatestBool;
}

bool TaskTask::lastSchedDeadBool() const
{
    return d->last_sched_dead_bool;
}

void TaskTask::setLastSchedDeadBool(bool lastSchedDeadBool)
{
    d->last_sched_dead_bool = lastSchedDeadBool;
}

QDate TaskTask::effectiveDt() const
{
    return d->effective_dt;
}

void TaskTask::setEffectiveDt(const QDate &effectiveDt)
{
    d->effective_dt = effectiveDt;
}

QString TaskTask::estDurationQt() const
{
    return d->est_duration_qt;
}

void TaskTask::setEstDurationQt(const QString &estDurationQt)
{
    d->est_duration_qt = estDurationQt;
}

QString TaskTask::taskApplEffDesc() const
{
    return d->task_appl_eff_desc;
}

void TaskTask::setTaskApplEffDesc(const QString &taskApplEffDesc)
{
    d->task_appl_eff_desc = taskApplEffDesc;
}

QString TaskTask::taskApplDesc() const
{
    return d->task_appl_desc;
}

void TaskTask::setTaskApplDesc(const QString &taskApplDesc)
{
    d->task_appl_desc = taskApplDesc;
}

QString TaskTask::taskApplSqlDesc() const
{
    return d->task_appl_sql_desc;
}

void TaskTask::setTaskApplSqlDesc(const QString &taskApplSqlDesc)
{
    d->task_appl_sql_desc = taskApplSqlDesc;
}

int TaskTask::revisionOrd() const
{
    return d->revision_ord;
}

void TaskTask::setRevisionOrd(int revisionOrd)
{
    d->revision_ord = revisionOrd;
}

QString TaskTask::revNote() const
{
    return d->rev_note;
}

void TaskTask::setRevNote(const QString &revNote)
{
    d->rev_note = revNote;
}

int TaskTask::preparedBy() const
{
    return d->prepared_by;
}

void TaskTask::setPreparedBy(int preparedBy)
{
    d->prepared_by = preparedBy;
}

QDateTime TaskTask::preparedDt() const
{
    return d->prepared_dt;
}

void TaskTask::setPreparedDt(const QDateTime &preparedDt)
{
    d->prepared_dt = preparedDt;
}

int TaskTask::reviewedBy() const
{
    return d->reviewed_by;
}

void TaskTask::setReviewedBy(int reviewedBy)
{
    d->reviewed_by = reviewedBy;
}

QDateTime TaskTask::reviewedDt() const
{
    return d->reviewed_dt;
}

void TaskTask::setReviewedDt(const QDateTime &reviewedDt)
{
    d->reviewed_dt = reviewedDt;
}

int TaskTask::approvedBy() const
{
    return d->approved_by;
}

void TaskTask::setApprovedBy(int approvedBy)
{
    d->approved_by = approvedBy;
}

QDateTime TaskTask::approvedDt() const
{
    return d->approved_dt;
}

void TaskTask::setApprovedDt(const QDateTime &approvedDt)
{
    d->approved_dt = approvedDt;
}

int TaskTask::activedBy() const
{
    return d->actived_by;
}

void TaskTask::setActivedBy(int activedBy)
{
    d->actived_by = activedBy;
}

QDateTime TaskTask::activedDt() const
{
    return d->actived_dt;
}

void TaskTask::setActivedDt(const QDateTime &activedDt)
{
    d->actived_dt = activedDt;
}

int TaskTask::lockedBy() const
{
    return d->locked_by;
}

void TaskTask::setLockedBy(int lockedBy)
{
    d->locked_by = lockedBy;
}

QDateTime TaskTask::lockedDt() const
{
    return d->locked_dt;
}

void TaskTask::setLockedDt(const QDateTime &lockedDt)
{
    d->locked_dt = lockedDt;
}

QDateTime TaskTask::createdAt() const
{
    return d->created_at;
}

QString TaskTask::createdBy() const
{
    return d->created_by;
}

void TaskTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskTask::updatedAt() const
{
    return d->updated_at;
}

QString TaskTask::updatedBy() const
{
    return d->updated_by;
}

void TaskTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn TaskTask::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

RefTaskDefStatus TaskTask::refTaskDefStatusBytaskDefStatusCd() const
{
 return RefTaskDefStatus::get(d->task_def_status_cd);
}

TaskOriginator TaskTask::taskOriginatorBytaskOriginatorId() const
{
 return TaskOriginator::get(d->task_originator_id);
}

RefTaskClass TaskTask::refTaskClassBytaskClassCd() const
{
 return RefTaskClass::get(d->task_class_cd);
}

TaskSubclass TaskTask::taskSubclassBytaskSubclassId() const
{
 return TaskSubclass::get(d->task_subclass_id);
}

RefFirstSchedFrom TaskTask::refFirstSchedFromByfirstSchedFromCd() const
{
 return RefFirstSchedFrom::get(d->first_sched_from_cd);
}

RefReschedFrom TaskTask::refReschedFromByreschedFromCd() const
{
 return RefReschedFrom::get(d->resched_from_cd);
}

RefCreateWhen TaskTask::refCreateWhenBycreateWhenCd() const
{
 return RefCreateWhen::get(d->create_when_cd);
}

RefCancelWhen TaskTask::refCancelWhenBycancelWhenCd() const
{
 return RefCancelWhen::get(d->cancel_when_cd);
}

UserApp TaskTask::userAppBypreparedBy() const
{
 return UserApp::get(d->prepared_by);
}

TaskTask &TaskTask::operator=(const TaskTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskTask TaskTask::create(int taskDefnId, const QString &taskDefStatusCd, const QString &taskCd, const QString &taskName, const QString &taskRefDesc, const QString &taskDesc, const QString &instructionDesc, const QString &engineeringDesc, int taskOriginatorId, const QString &taskClassCd, int taskSubclassId, bool taskMustRemoveCd, bool recurBool, const QString &firstSchedFromCd, const QString &reschedFromCd, const QString &createWhenCd, const QString &cancelWhenCd, bool schedFromLatestBool, bool lastSchedDeadBool, const QDate &effectiveDt, const QString &estDurationQt, const QString &taskApplEffDesc, const QString &taskApplDesc, const QString &taskApplSqlDesc, int revisionOrd, const QString &revNote, int preparedBy, const QDateTime &preparedDt, int reviewedBy, const QDateTime &reviewedDt, int approvedBy, const QDateTime &approvedDt, int activedBy, const QDateTime &activedDt, int lockedBy, const QDateTime &lockedDt, const QString &createdBy, const QString &updatedBy)
{
    TaskTaskObject obj;
    obj.task_defn_id = taskDefnId;
    obj.task_def_status_cd = taskDefStatusCd;
    obj.task_cd = taskCd;
    obj.task_name = taskName;
    obj.task_ref_desc = taskRefDesc;
    obj.task_desc = taskDesc;
    obj.instruction_desc = instructionDesc;
    obj.engineering_desc = engineeringDesc;
    obj.task_originator_id = taskOriginatorId;
    obj.task_class_cd = taskClassCd;
    obj.task_subclass_id = taskSubclassId;
    obj.task_must_remove_cd = taskMustRemoveCd;
    obj.recur_bool = recurBool;
    obj.first_sched_from_cd = firstSchedFromCd;
    obj.resched_from_cd = reschedFromCd;
    obj.create_when_cd = createWhenCd;
    obj.cancel_when_cd = cancelWhenCd;
    obj.sched_from_latest_bool = schedFromLatestBool;
    obj.last_sched_dead_bool = lastSchedDeadBool;
    obj.effective_dt = effectiveDt;
    obj.est_duration_qt = estDurationQt;
    obj.task_appl_eff_desc = taskApplEffDesc;
    obj.task_appl_desc = taskApplDesc;
    obj.task_appl_sql_desc = taskApplSqlDesc;
    obj.revision_ord = revisionOrd;
    obj.rev_note = revNote;
    obj.prepared_by = preparedBy;
    obj.prepared_dt = preparedDt;
    obj.reviewed_by = reviewedBy;
    obj.reviewed_dt = reviewedDt;
    obj.approved_by = approvedBy;
    obj.approved_dt = approvedDt;
    obj.actived_by = activedBy;
    obj.actived_dt = activedDt;
    obj.locked_by = lockedBy;
    obj.locked_dt = lockedDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskTask();
    }
    return TaskTask(obj);
}

TaskTask TaskTask::create(const QVariantMap &values)
{
    TaskTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskTask TaskTask::get(int taskId)
{
    TSqlORMapper<TaskTaskObject> mapper;
    return TaskTask(mapper.findByPrimaryKey(taskId));
}

int TaskTask::count()
{
    TSqlORMapper<TaskTaskObject> mapper;
    return mapper.findCount();
}

QList<TaskTask> TaskTask::getAll()
{
    return tfGetModelListByCriteria<TaskTask, TaskTaskObject>();
}

TModelObject *TaskTask::modelData()
{
    return d.data();
}

const TModelObject *TaskTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskTask)
