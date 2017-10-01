#include <TreeFrogModel>
#include "tasklaboursummary.h"
#include "tasklaboursummaryobject.h"
#include "labourskill.h"
#include "schedstask.h"
#include "taskdefn.h"
#include "tasktask.h"

TaskLabourSummary::TaskLabourSummary()
    : TAbstractModel(), d(new TaskLabourSummaryObject())
{
    d->task_id = 0;
    d->task_defn_id = 0;
    d->sched_id = 0;
    d->labour_skill_id = 0;
    d->sched_man_hr = 0;
    d->sched_man_pwr_ct = 0;
    d->actual_total_man_hr = 0;
    d->actual_man_pwr_ct = 0;
}

TaskLabourSummary::TaskLabourSummary(const TaskLabourSummary &other)
    : TAbstractModel(), d(new TaskLabourSummaryObject(*other.d))
{ }

TaskLabourSummary::TaskLabourSummary(const TaskLabourSummaryObject &object)
    : TAbstractModel(), d(new TaskLabourSummaryObject(object))
{ }

TaskLabourSummary::~TaskLabourSummary()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskLabourSummaryObject' is deleted.
}

int TaskLabourSummary::taskId() const
{
    return d->task_id;
}

void TaskLabourSummary::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskLabourSummary::taskDefnId() const
{
    return d->task_defn_id;
}

void TaskLabourSummary::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

int TaskLabourSummary::schedId() const
{
    return d->sched_id;
}

void TaskLabourSummary::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int TaskLabourSummary::labourSkillId() const
{
    return d->labour_skill_id;
}

void TaskLabourSummary::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

double TaskLabourSummary::schedManHr() const
{
    return d->sched_man_hr;
}

void TaskLabourSummary::setSchedManHr(double schedManHr)
{
    d->sched_man_hr = schedManHr;
}

int TaskLabourSummary::schedManPwrCt() const
{
    return d->sched_man_pwr_ct;
}

void TaskLabourSummary::setSchedManPwrCt(int schedManPwrCt)
{
    d->sched_man_pwr_ct = schedManPwrCt;
}

double TaskLabourSummary::actualTotalManHr() const
{
    return d->actual_total_man_hr;
}

void TaskLabourSummary::setActualTotalManHr(double actualTotalManHr)
{
    d->actual_total_man_hr = actualTotalManHr;
}

int TaskLabourSummary::actualManPwrCt() const
{
    return d->actual_man_pwr_ct;
}

void TaskLabourSummary::setActualManPwrCt(int actualManPwrCt)
{
    d->actual_man_pwr_ct = actualManPwrCt;
}

QDateTime TaskLabourSummary::createdAt() const
{
    return d->created_at;
}

QString TaskLabourSummary::createdBy() const
{
    return d->created_by;
}

void TaskLabourSummary::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskLabourSummary::updatedAt() const
{
    return d->updated_at;
}

QString TaskLabourSummary::updatedBy() const
{
    return d->updated_by;
}

void TaskLabourSummary::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

LabourSkill TaskLabourSummary::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

SchedStask TaskLabourSummary::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

TaskDefn TaskLabourSummary::taskDefnBytaskDefnId() const
{
 return TaskDefn::get(d->task_defn_id);
}

TaskTask TaskLabourSummary::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskLabourSummary &TaskLabourSummary::operator=(const TaskLabourSummary &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskLabourSummary TaskLabourSummary::create(int taskId, int taskDefnId, int schedId, int labourSkillId, double schedManHr, int schedManPwrCt, double actualTotalManHr, int actualManPwrCt, const QString &createdBy, const QString &updatedBy)
{
    TaskLabourSummaryObject obj;
    obj.task_id = taskId;
    obj.task_defn_id = taskDefnId;
    obj.sched_id = schedId;
    obj.labour_skill_id = labourSkillId;
    obj.sched_man_hr = schedManHr;
    obj.sched_man_pwr_ct = schedManPwrCt;
    obj.actual_total_man_hr = actualTotalManHr;
    obj.actual_man_pwr_ct = actualManPwrCt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskLabourSummary();
    }
    return TaskLabourSummary(obj);
}

TaskLabourSummary TaskLabourSummary::create(const QVariantMap &values)
{
    TaskLabourSummary model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskLabourSummary TaskLabourSummary::get(int taskId, int taskDefnId, int schedId, int labourSkillId)
{
    TSqlORMapper<TaskLabourSummaryObject> mapper;
    return TaskLabourSummary(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(taskDefnId)<<QVariant(schedId)<<QVariant(labourSkillId)));
}

int TaskLabourSummary::count()
{
    TSqlORMapper<TaskLabourSummaryObject> mapper;
    return mapper.findCount();
}

QList<TaskLabourSummary> TaskLabourSummary::getAll()
{
    return tfGetModelListByCriteria<TaskLabourSummary, TaskLabourSummaryObject>();
}

TModelObject *TaskLabourSummary::modelData()
{
    return d.data();
}

const TModelObject *TaskLabourSummary::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskLabourSummary &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskLabourSummary &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskLabourSummary)
