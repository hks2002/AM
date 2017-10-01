#include <TreeFrogModel>
#include "taskschedruledef.h"
#include "taskschedruledefobject.h"
#include "datatype.h"
#include "tasktask.h"

TaskSchedRuleDef::TaskSchedRuleDef()
    : TAbstractModel(), d(new TaskSchedRuleDefObject())
{
    d->task_id = 0;
    d->data_type_id = 0;
    d->initial_qt = 0;
    d->interval_qt = 0;
    d->deviation_qt = 0;
    d->notify_qt = 0;
    d->prefixed_qt = 0;
    d->postfixed_qt = 0;
    d->min_plan_qt = 0;
}

TaskSchedRuleDef::TaskSchedRuleDef(const TaskSchedRuleDef &other)
    : TAbstractModel(), d(new TaskSchedRuleDefObject(*other.d))
{ }

TaskSchedRuleDef::TaskSchedRuleDef(const TaskSchedRuleDefObject &object)
    : TAbstractModel(), d(new TaskSchedRuleDefObject(object))
{ }

TaskSchedRuleDef::~TaskSchedRuleDef()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskSchedRuleDefObject' is deleted.
}

int TaskSchedRuleDef::taskId() const
{
    return d->task_id;
}

void TaskSchedRuleDef::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskSchedRuleDef::dataTypeId() const
{
    return d->data_type_id;
}

void TaskSchedRuleDef::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

double TaskSchedRuleDef::initialQt() const
{
    return d->initial_qt;
}

void TaskSchedRuleDef::setInitialQt(double initialQt)
{
    d->initial_qt = initialQt;
}

double TaskSchedRuleDef::intervalQt() const
{
    return d->interval_qt;
}

void TaskSchedRuleDef::setIntervalQt(double intervalQt)
{
    d->interval_qt = intervalQt;
}

double TaskSchedRuleDef::deviationQt() const
{
    return d->deviation_qt;
}

void TaskSchedRuleDef::setDeviationQt(double deviationQt)
{
    d->deviation_qt = deviationQt;
}

double TaskSchedRuleDef::notifyQt() const
{
    return d->notify_qt;
}

void TaskSchedRuleDef::setNotifyQt(double notifyQt)
{
    d->notify_qt = notifyQt;
}

double TaskSchedRuleDef::prefixedQt() const
{
    return d->prefixed_qt;
}

void TaskSchedRuleDef::setPrefixedQt(double prefixedQt)
{
    d->prefixed_qt = prefixedQt;
}

double TaskSchedRuleDef::postfixedQt() const
{
    return d->postfixed_qt;
}

void TaskSchedRuleDef::setPostfixedQt(double postfixedQt)
{
    d->postfixed_qt = postfixedQt;
}

double TaskSchedRuleDef::minPlanQt() const
{
    return d->min_plan_qt;
}

void TaskSchedRuleDef::setMinPlanQt(double minPlanQt)
{
    d->min_plan_qt = minPlanQt;
}

bool TaskSchedRuleDef::postfixedMandBool() const
{
    return d->postfixed_mand_bool;
}

void TaskSchedRuleDef::setPostfixedMandBool(bool postfixedMandBool)
{
    d->postfixed_mand_bool = postfixedMandBool;
}

QDateTime TaskSchedRuleDef::createdAt() const
{
    return d->created_at;
}

QString TaskSchedRuleDef::createdBy() const
{
    return d->created_by;
}

void TaskSchedRuleDef::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskSchedRuleDef::updatedAt() const
{
    return d->updated_at;
}

QString TaskSchedRuleDef::updatedBy() const
{
    return d->updated_by;
}

void TaskSchedRuleDef::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

DataType TaskSchedRuleDef::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

TaskTask TaskSchedRuleDef::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskSchedRuleDef &TaskSchedRuleDef::operator=(const TaskSchedRuleDef &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskSchedRuleDef TaskSchedRuleDef::create(int taskId, int dataTypeId, double initialQt, double intervalQt, double deviationQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy)
{
    TaskSchedRuleDefObject obj;
    obj.task_id = taskId;
    obj.data_type_id = dataTypeId;
    obj.initial_qt = initialQt;
    obj.interval_qt = intervalQt;
    obj.deviation_qt = deviationQt;
    obj.notify_qt = notifyQt;
    obj.prefixed_qt = prefixedQt;
    obj.postfixed_qt = postfixedQt;
    obj.min_plan_qt = minPlanQt;
    obj.postfixed_mand_bool = postfixedMandBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskSchedRuleDef();
    }
    return TaskSchedRuleDef(obj);
}

TaskSchedRuleDef TaskSchedRuleDef::create(const QVariantMap &values)
{
    TaskSchedRuleDef model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskSchedRuleDef TaskSchedRuleDef::get(int taskId, int dataTypeId)
{
    TSqlORMapper<TaskSchedRuleDefObject> mapper;
    return TaskSchedRuleDef(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(dataTypeId)));
}

int TaskSchedRuleDef::count()
{
    TSqlORMapper<TaskSchedRuleDefObject> mapper;
    return mapper.findCount();
}

QList<TaskSchedRuleDef> TaskSchedRuleDef::getAll()
{
    return tfGetModelListByCriteria<TaskSchedRuleDef, TaskSchedRuleDefObject>();
}

TModelObject *TaskSchedRuleDef::modelData()
{
    return d.data();
}

const TModelObject *TaskSchedRuleDef::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskSchedRuleDef &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskSchedRuleDef &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskSchedRuleDef)
