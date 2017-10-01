#include <TreeFrogModel>
#include "taskfigure.h"
#include "taskfigureobject.h"
#include "tasktask.h"

TaskFigure::TaskFigure()
    : TAbstractModel(), d(new TaskFigureObject())
{
    d->task_id = 0;
    d->figure_ord = 0;
}

TaskFigure::TaskFigure(const TaskFigure &other)
    : TAbstractModel(), d(new TaskFigureObject(*other.d))
{ }

TaskFigure::TaskFigure(const TaskFigureObject &object)
    : TAbstractModel(), d(new TaskFigureObject(object))
{ }

TaskFigure::~TaskFigure()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskFigureObject' is deleted.
}

int TaskFigure::taskId() const
{
    return d->task_id;
}

void TaskFigure::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskFigure::figureOrd() const
{
    return d->figure_ord;
}

void TaskFigure::setFigureOrd(int figureOrd)
{
    d->figure_ord = figureOrd;
}

QString TaskFigure::figureDesc() const
{
    return d->figure_desc;
}

void TaskFigure::setFigureDesc(const QString &figureDesc)
{
    d->figure_desc = figureDesc;
}

QString TaskFigure::figureNote() const
{
    return d->figure_note;
}

void TaskFigure::setFigureNote(const QString &figureNote)
{
    d->figure_note = figureNote;
}

QDateTime TaskFigure::createdAt() const
{
    return d->created_at;
}

QString TaskFigure::createdBy() const
{
    return d->created_by;
}

void TaskFigure::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskFigure::updatedAt() const
{
    return d->updated_at;
}

QString TaskFigure::updatedBy() const
{
    return d->updated_by;
}

void TaskFigure::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskTask TaskFigure::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskFigure &TaskFigure::operator=(const TaskFigure &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskFigure TaskFigure::create(int taskId, int figureOrd, const QString &figureDesc, const QString &figureNote, const QString &createdBy, const QString &updatedBy)
{
    TaskFigureObject obj;
    obj.task_id = taskId;
    obj.figure_ord = figureOrd;
    obj.figure_desc = figureDesc;
    obj.figure_note = figureNote;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskFigure();
    }
    return TaskFigure(obj);
}

TaskFigure TaskFigure::create(const QVariantMap &values)
{
    TaskFigure model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskFigure TaskFigure::get(int taskId, int figureOrd)
{
    TSqlORMapper<TaskFigureObject> mapper;
    return TaskFigure(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(figureOrd)));
}

int TaskFigure::count()
{
    TSqlORMapper<TaskFigureObject> mapper;
    return mapper.findCount();
}

QList<TaskFigure> TaskFigure::getAll()
{
    return tfGetModelListByCriteria<TaskFigure, TaskFigureObject>();
}

TModelObject *TaskFigure::modelData()
{
    return d.data();
}

const TModelObject *TaskFigure::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskFigure &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskFigure &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskFigure)
