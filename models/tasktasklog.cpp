#include <TreeFrogModel>
#include "tasktasklog.h"
#include "tasktasklogobject.h"
#include "reflogaction.h"
#include "tasktask.h"

TaskTaskLog::TaskTaskLog()
    : TAbstractModel(), d(new TaskTaskLogObject())
{
    d->task_task_log_id = 0;
    d->task_id = 0;
}

TaskTaskLog::TaskTaskLog(const TaskTaskLog &other)
    : TAbstractModel(), d(new TaskTaskLogObject(*other.d))
{ }

TaskTaskLog::TaskTaskLog(const TaskTaskLogObject &object)
    : TAbstractModel(), d(new TaskTaskLogObject(object))
{ }

TaskTaskLog::~TaskTaskLog()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskTaskLogObject' is deleted.
}

int TaskTaskLog::taskTaskLogId() const
{
    return d->task_task_log_id;
}

int TaskTaskLog::taskId() const
{
    return d->task_id;
}

void TaskTaskLog::setTaskId(int taskId)
{
    d->task_id = taskId;
}

QString TaskTaskLog::logActionCd() const
{
    return d->log_action_cd;
}

void TaskTaskLog::setLogActionCd(const QString &logActionCd)
{
    d->log_action_cd = logActionCd;
}

QDateTime TaskTaskLog::logDt() const
{
    return d->log_dt;
}

void TaskTaskLog::setLogDt(const QDateTime &logDt)
{
    d->log_dt = logDt;
}

QString TaskTaskLog::userNote() const
{
    return d->user_note;
}

void TaskTaskLog::setUserNote(const QString &userNote)
{
    d->user_note = userNote;
}

QString TaskTaskLog::systemNote() const
{
    return d->system_note;
}

void TaskTaskLog::setSystemNote(const QString &systemNote)
{
    d->system_note = systemNote;
}

QDateTime TaskTaskLog::createdAt() const
{
    return d->created_at;
}

QString TaskTaskLog::createdBy() const
{
    return d->created_by;
}

void TaskTaskLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskTaskLog::updatedAt() const
{
    return d->updated_at;
}

QString TaskTaskLog::updatedBy() const
{
    return d->updated_by;
}

void TaskTaskLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLogAction TaskTaskLog::refLogActionBylogActionCd() const
{
 return RefLogAction::get(d->log_action_cd);
}

TaskTask TaskTaskLog::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskTaskLog &TaskTaskLog::operator=(const TaskTaskLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskTaskLog TaskTaskLog::create(int taskId, const QString &logActionCd, const QDateTime &logDt, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy)
{
    TaskTaskLogObject obj;
    obj.task_id = taskId;
    obj.log_action_cd = logActionCd;
    obj.log_dt = logDt;
    obj.user_note = userNote;
    obj.system_note = systemNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskTaskLog();
    }
    return TaskTaskLog(obj);
}

TaskTaskLog TaskTaskLog::create(const QVariantMap &values)
{
    TaskTaskLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskTaskLog TaskTaskLog::get(int taskTaskLogId)
{
    TSqlORMapper<TaskTaskLogObject> mapper;
    return TaskTaskLog(mapper.findByPrimaryKey(taskTaskLogId));
}

int TaskTaskLog::count()
{
    TSqlORMapper<TaskTaskLogObject> mapper;
    return mapper.findCount();
}

QList<TaskTaskLog> TaskTaskLog::getAll()
{
    return tfGetModelListByCriteria<TaskTaskLog, TaskTaskLogObject>();
}

TModelObject *TaskTaskLog::modelData()
{
    return d.data();
}

const TModelObject *TaskTaskLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskTaskLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskTaskLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskTaskLog)
