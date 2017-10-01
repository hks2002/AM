#include <TreeFrogModel>
#include "taskschedruleac.h"
#include "taskschedruleacobject.h"
#include "invinv.h"
#include "datatype.h"
#include "tasktask.h"

TaskSchedRuleAc::TaskSchedRuleAc()
    : TAbstractModel(), d(new TaskSchedRuleAcObject())
{
    d->task_id = 0;
    d->data_type_id = 0;
    d->inv_no_id = 0;
    d->initial_qt = 0;
    d->interval_qt = 0;
    d->deviation_qt = 0;
    d->notify_qt = 0;
    d->prefixed_qt = 0;
    d->postfixed_qt = 0;
    d->min_plan_qt = 0;
}

TaskSchedRuleAc::TaskSchedRuleAc(const TaskSchedRuleAc &other)
    : TAbstractModel(), d(new TaskSchedRuleAcObject(*other.d))
{ }

TaskSchedRuleAc::TaskSchedRuleAc(const TaskSchedRuleAcObject &object)
    : TAbstractModel(), d(new TaskSchedRuleAcObject(object))
{ }

TaskSchedRuleAc::~TaskSchedRuleAc()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskSchedRuleAcObject' is deleted.
}

int TaskSchedRuleAc::taskId() const
{
    return d->task_id;
}

void TaskSchedRuleAc::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskSchedRuleAc::dataTypeId() const
{
    return d->data_type_id;
}

void TaskSchedRuleAc::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

int TaskSchedRuleAc::invNoId() const
{
    return d->inv_no_id;
}

void TaskSchedRuleAc::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

double TaskSchedRuleAc::initialQt() const
{
    return d->initial_qt;
}

void TaskSchedRuleAc::setInitialQt(double initialQt)
{
    d->initial_qt = initialQt;
}

double TaskSchedRuleAc::intervalQt() const
{
    return d->interval_qt;
}

void TaskSchedRuleAc::setIntervalQt(double intervalQt)
{
    d->interval_qt = intervalQt;
}

double TaskSchedRuleAc::deviationQt() const
{
    return d->deviation_qt;
}

void TaskSchedRuleAc::setDeviationQt(double deviationQt)
{
    d->deviation_qt = deviationQt;
}

double TaskSchedRuleAc::notifyQt() const
{
    return d->notify_qt;
}

void TaskSchedRuleAc::setNotifyQt(double notifyQt)
{
    d->notify_qt = notifyQt;
}

double TaskSchedRuleAc::prefixedQt() const
{
    return d->prefixed_qt;
}

void TaskSchedRuleAc::setPrefixedQt(double prefixedQt)
{
    d->prefixed_qt = prefixedQt;
}

double TaskSchedRuleAc::postfixedQt() const
{
    return d->postfixed_qt;
}

void TaskSchedRuleAc::setPostfixedQt(double postfixedQt)
{
    d->postfixed_qt = postfixedQt;
}

double TaskSchedRuleAc::minPlanQt() const
{
    return d->min_plan_qt;
}

void TaskSchedRuleAc::setMinPlanQt(double minPlanQt)
{
    d->min_plan_qt = minPlanQt;
}

bool TaskSchedRuleAc::postfixedMandBool() const
{
    return d->postfixed_mand_bool;
}

void TaskSchedRuleAc::setPostfixedMandBool(bool postfixedMandBool)
{
    d->postfixed_mand_bool = postfixedMandBool;
}

QDateTime TaskSchedRuleAc::createdAt() const
{
    return d->created_at;
}

QString TaskSchedRuleAc::createdBy() const
{
    return d->created_by;
}

void TaskSchedRuleAc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskSchedRuleAc::updatedAt() const
{
    return d->updated_at;
}

QString TaskSchedRuleAc::updatedBy() const
{
    return d->updated_by;
}

void TaskSchedRuleAc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

InvInv TaskSchedRuleAc::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

DataType TaskSchedRuleAc::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

TaskTask TaskSchedRuleAc::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskSchedRuleAc &TaskSchedRuleAc::operator=(const TaskSchedRuleAc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskSchedRuleAc TaskSchedRuleAc::create(int taskId, int dataTypeId, int invNoId, double initialQt, double intervalQt, double deviationQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy)
{
    TaskSchedRuleAcObject obj;
    obj.task_id = taskId;
    obj.data_type_id = dataTypeId;
    obj.inv_no_id = invNoId;
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
        return TaskSchedRuleAc();
    }
    return TaskSchedRuleAc(obj);
}

TaskSchedRuleAc TaskSchedRuleAc::create(const QVariantMap &values)
{
    TaskSchedRuleAc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskSchedRuleAc TaskSchedRuleAc::get(int taskId, int dataTypeId, int invNoId)
{
    TSqlORMapper<TaskSchedRuleAcObject> mapper;
    return TaskSchedRuleAc(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(dataTypeId)<<QVariant(invNoId)));
}

int TaskSchedRuleAc::count()
{
    TSqlORMapper<TaskSchedRuleAcObject> mapper;
    return mapper.findCount();
}

QList<TaskSchedRuleAc> TaskSchedRuleAc::getAll()
{
    return tfGetModelListByCriteria<TaskSchedRuleAc, TaskSchedRuleAcObject>();
}

TModelObject *TaskSchedRuleAc::modelData()
{
    return d.data();
}

const TModelObject *TaskSchedRuleAc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskSchedRuleAc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskSchedRuleAc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskSchedRuleAc)
