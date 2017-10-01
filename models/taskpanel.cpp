#include <TreeFrogModel>
#include "taskpanel.h"
#include "taskpanelobject.h"
#include "eqppanel.h"
#include "tasktask.h"

TaskPanel::TaskPanel()
    : TAbstractModel(), d(new TaskPanelObject())
{
    d->task_id = 0;
    d->panel_id = 0;
}

TaskPanel::TaskPanel(const TaskPanel &other)
    : TAbstractModel(), d(new TaskPanelObject(*other.d))
{ }

TaskPanel::TaskPanel(const TaskPanelObject &object)
    : TAbstractModel(), d(new TaskPanelObject(object))
{ }

TaskPanel::~TaskPanel()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskPanelObject' is deleted.
}

int TaskPanel::taskId() const
{
    return d->task_id;
}

void TaskPanel::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskPanel::panelId() const
{
    return d->panel_id;
}

void TaskPanel::setPanelId(int panelId)
{
    d->panel_id = panelId;
}

QDateTime TaskPanel::createdAt() const
{
    return d->created_at;
}

QString TaskPanel::createdBy() const
{
    return d->created_by;
}

void TaskPanel::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskPanel::updatedAt() const
{
    return d->updated_at;
}

QString TaskPanel::updatedBy() const
{
    return d->updated_by;
}

void TaskPanel::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPanel TaskPanel::eqpPanelBypanelId() const
{
 return EqpPanel::get(d->panel_id);
}

TaskTask TaskPanel::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskPanel &TaskPanel::operator=(const TaskPanel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskPanel TaskPanel::create(int taskId, int panelId, const QString &createdBy, const QString &updatedBy)
{
    TaskPanelObject obj;
    obj.task_id = taskId;
    obj.panel_id = panelId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskPanel();
    }
    return TaskPanel(obj);
}

TaskPanel TaskPanel::create(const QVariantMap &values)
{
    TaskPanel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskPanel TaskPanel::get(int taskId, int panelId)
{
    TSqlORMapper<TaskPanelObject> mapper;
    return TaskPanel(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(panelId)));
}

int TaskPanel::count()
{
    TSqlORMapper<TaskPanelObject> mapper;
    return mapper.findCount();
}

QList<TaskPanel> TaskPanel::getAll()
{
    return tfGetModelListByCriteria<TaskPanel, TaskPanelObject>();
}

TModelObject *TaskPanel::modelData()
{
    return d.data();
}

const TModelObject *TaskPanel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskPanel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskPanel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskPanel)
