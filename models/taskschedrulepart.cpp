#include <TreeFrogModel>
#include "taskschedrulepart.h"
#include "taskschedrulepartobject.h"
#include "eqppartno.h"
#include "datatype.h"
#include "tasktask.h"

TaskSchedRulePart::TaskSchedRulePart()
    : TAbstractModel(), d(new TaskSchedRulePartObject())
{
    d->task_id = 0;
    d->data_type_id = 0;
    d->part_no_id = 0;
    d->deviation_qt = 0;
    d->initial_qt = 0;
    d->interval_qt = 0;
    d->notify_qt = 0;
    d->prefixed_qt = 0;
    d->postfixed_qt = 0;
    d->min_plan_qt = 0;
}

TaskSchedRulePart::TaskSchedRulePart(const TaskSchedRulePart &other)
    : TAbstractModel(), d(new TaskSchedRulePartObject(*other.d))
{ }

TaskSchedRulePart::TaskSchedRulePart(const TaskSchedRulePartObject &object)
    : TAbstractModel(), d(new TaskSchedRulePartObject(object))
{ }

TaskSchedRulePart::~TaskSchedRulePart()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskSchedRulePartObject' is deleted.
}

int TaskSchedRulePart::taskId() const
{
    return d->task_id;
}

void TaskSchedRulePart::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskSchedRulePart::dataTypeId() const
{
    return d->data_type_id;
}

void TaskSchedRulePart::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

int TaskSchedRulePart::partNoId() const
{
    return d->part_no_id;
}

void TaskSchedRulePart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

double TaskSchedRulePart::deviationQt() const
{
    return d->deviation_qt;
}

void TaskSchedRulePart::setDeviationQt(double deviationQt)
{
    d->deviation_qt = deviationQt;
}

double TaskSchedRulePart::initialQt() const
{
    return d->initial_qt;
}

void TaskSchedRulePart::setInitialQt(double initialQt)
{
    d->initial_qt = initialQt;
}

double TaskSchedRulePart::intervalQt() const
{
    return d->interval_qt;
}

void TaskSchedRulePart::setIntervalQt(double intervalQt)
{
    d->interval_qt = intervalQt;
}

double TaskSchedRulePart::notifyQt() const
{
    return d->notify_qt;
}

void TaskSchedRulePart::setNotifyQt(double notifyQt)
{
    d->notify_qt = notifyQt;
}

double TaskSchedRulePart::prefixedQt() const
{
    return d->prefixed_qt;
}

void TaskSchedRulePart::setPrefixedQt(double prefixedQt)
{
    d->prefixed_qt = prefixedQt;
}

double TaskSchedRulePart::postfixedQt() const
{
    return d->postfixed_qt;
}

void TaskSchedRulePart::setPostfixedQt(double postfixedQt)
{
    d->postfixed_qt = postfixedQt;
}

double TaskSchedRulePart::minPlanQt() const
{
    return d->min_plan_qt;
}

void TaskSchedRulePart::setMinPlanQt(double minPlanQt)
{
    d->min_plan_qt = minPlanQt;
}

bool TaskSchedRulePart::postfixedMandBool() const
{
    return d->postfixed_mand_bool;
}

void TaskSchedRulePart::setPostfixedMandBool(bool postfixedMandBool)
{
    d->postfixed_mand_bool = postfixedMandBool;
}

QDateTime TaskSchedRulePart::createdAt() const
{
    return d->created_at;
}

QString TaskSchedRulePart::createdBy() const
{
    return d->created_by;
}

void TaskSchedRulePart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskSchedRulePart::updatedAt() const
{
    return d->updated_at;
}

QString TaskSchedRulePart::updatedBy() const
{
    return d->updated_by;
}

void TaskSchedRulePart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo TaskSchedRulePart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

DataType TaskSchedRulePart::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

TaskTask TaskSchedRulePart::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskSchedRulePart &TaskSchedRulePart::operator=(const TaskSchedRulePart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskSchedRulePart TaskSchedRulePart::create(int taskId, int dataTypeId, int partNoId, double deviationQt, double initialQt, double intervalQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy)
{
    TaskSchedRulePartObject obj;
    obj.task_id = taskId;
    obj.data_type_id = dataTypeId;
    obj.part_no_id = partNoId;
    obj.deviation_qt = deviationQt;
    obj.initial_qt = initialQt;
    obj.interval_qt = intervalQt;
    obj.notify_qt = notifyQt;
    obj.prefixed_qt = prefixedQt;
    obj.postfixed_qt = postfixedQt;
    obj.min_plan_qt = minPlanQt;
    obj.postfixed_mand_bool = postfixedMandBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskSchedRulePart();
    }
    return TaskSchedRulePart(obj);
}

TaskSchedRulePart TaskSchedRulePart::create(const QVariantMap &values)
{
    TaskSchedRulePart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskSchedRulePart TaskSchedRulePart::get(int taskId, int dataTypeId, int partNoId)
{
    TSqlORMapper<TaskSchedRulePartObject> mapper;
    return TaskSchedRulePart(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(dataTypeId)<<QVariant(partNoId)));
}

int TaskSchedRulePart::count()
{
    TSqlORMapper<TaskSchedRulePartObject> mapper;
    return mapper.findCount();
}

QList<TaskSchedRulePart> TaskSchedRulePart::getAll()
{
    return tfGetModelListByCriteria<TaskSchedRulePart, TaskSchedRulePartObject>();
}

TModelObject *TaskSchedRulePart::modelData()
{
    return d.data();
}

const TModelObject *TaskSchedRulePart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskSchedRulePart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskSchedRulePart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskSchedRulePart)
