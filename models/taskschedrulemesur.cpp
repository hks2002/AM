#include <TreeFrogModel>
#include "taskschedrulemesur.h"
#include "taskschedrulemesurobject.h"
#include "mesurunit.h"
#include "datatype.h"
#include "tasktask.h"

TaskSchedRuleMesur::TaskSchedRuleMesur()
    : TAbstractModel(), d(new TaskSchedRuleMesurObject())
{
    d->task_id = 0;
    d->data_type_id = 0;
    d->mesur_unit_id = 0;
    d->mesur_form_qt = 0;
    d->mesur_to_qt = 0;
    d->deviation_qt = 0;
    d->initial_qt = 0;
    d->interval_qt = 0;
    d->notify_qt = 0;
    d->prefixed_qt = 0;
    d->postfixed_qt = 0;
    d->min_plan_qt = 0;
}

TaskSchedRuleMesur::TaskSchedRuleMesur(const TaskSchedRuleMesur &other)
    : TAbstractModel(), d(new TaskSchedRuleMesurObject(*other.d))
{ }

TaskSchedRuleMesur::TaskSchedRuleMesur(const TaskSchedRuleMesurObject &object)
    : TAbstractModel(), d(new TaskSchedRuleMesurObject(object))
{ }

TaskSchedRuleMesur::~TaskSchedRuleMesur()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskSchedRuleMesurObject' is deleted.
}

int TaskSchedRuleMesur::taskId() const
{
    return d->task_id;
}

void TaskSchedRuleMesur::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskSchedRuleMesur::dataTypeId() const
{
    return d->data_type_id;
}

void TaskSchedRuleMesur::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

int TaskSchedRuleMesur::mesurUnitId() const
{
    return d->mesur_unit_id;
}

void TaskSchedRuleMesur::setMesurUnitId(int mesurUnitId)
{
    d->mesur_unit_id = mesurUnitId;
}

int TaskSchedRuleMesur::mesurFormQt() const
{
    return d->mesur_form_qt;
}

void TaskSchedRuleMesur::setMesurFormQt(int mesurFormQt)
{
    d->mesur_form_qt = mesurFormQt;
}

int TaskSchedRuleMesur::mesurToQt() const
{
    return d->mesur_to_qt;
}

void TaskSchedRuleMesur::setMesurToQt(int mesurToQt)
{
    d->mesur_to_qt = mesurToQt;
}

double TaskSchedRuleMesur::deviationQt() const
{
    return d->deviation_qt;
}

void TaskSchedRuleMesur::setDeviationQt(double deviationQt)
{
    d->deviation_qt = deviationQt;
}

double TaskSchedRuleMesur::initialQt() const
{
    return d->initial_qt;
}

void TaskSchedRuleMesur::setInitialQt(double initialQt)
{
    d->initial_qt = initialQt;
}

double TaskSchedRuleMesur::intervalQt() const
{
    return d->interval_qt;
}

void TaskSchedRuleMesur::setIntervalQt(double intervalQt)
{
    d->interval_qt = intervalQt;
}

double TaskSchedRuleMesur::notifyQt() const
{
    return d->notify_qt;
}

void TaskSchedRuleMesur::setNotifyQt(double notifyQt)
{
    d->notify_qt = notifyQt;
}

double TaskSchedRuleMesur::prefixedQt() const
{
    return d->prefixed_qt;
}

void TaskSchedRuleMesur::setPrefixedQt(double prefixedQt)
{
    d->prefixed_qt = prefixedQt;
}

double TaskSchedRuleMesur::postfixedQt() const
{
    return d->postfixed_qt;
}

void TaskSchedRuleMesur::setPostfixedQt(double postfixedQt)
{
    d->postfixed_qt = postfixedQt;
}

double TaskSchedRuleMesur::minPlanQt() const
{
    return d->min_plan_qt;
}

void TaskSchedRuleMesur::setMinPlanQt(double minPlanQt)
{
    d->min_plan_qt = minPlanQt;
}

bool TaskSchedRuleMesur::postfixedMandBool() const
{
    return d->postfixed_mand_bool;
}

void TaskSchedRuleMesur::setPostfixedMandBool(bool postfixedMandBool)
{
    d->postfixed_mand_bool = postfixedMandBool;
}

QDateTime TaskSchedRuleMesur::createdAt() const
{
    return d->created_at;
}

QString TaskSchedRuleMesur::createdBy() const
{
    return d->created_by;
}

void TaskSchedRuleMesur::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskSchedRuleMesur::updatedAt() const
{
    return d->updated_at;
}

QString TaskSchedRuleMesur::updatedBy() const
{
    return d->updated_by;
}

void TaskSchedRuleMesur::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

MesurUnit TaskSchedRuleMesur::mesurUnitBymesurUnitId() const
{
 return MesurUnit::get(d->mesur_unit_id);
}

DataType TaskSchedRuleMesur::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

TaskTask TaskSchedRuleMesur::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskSchedRuleMesur &TaskSchedRuleMesur::operator=(const TaskSchedRuleMesur &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskSchedRuleMesur TaskSchedRuleMesur::create(int taskId, int dataTypeId, int mesurUnitId, int mesurFormQt, int mesurToQt, double deviationQt, double initialQt, double intervalQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy)
{
    TaskSchedRuleMesurObject obj;
    obj.task_id = taskId;
    obj.data_type_id = dataTypeId;
    obj.mesur_unit_id = mesurUnitId;
    obj.mesur_form_qt = mesurFormQt;
    obj.mesur_to_qt = mesurToQt;
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
        return TaskSchedRuleMesur();
    }
    return TaskSchedRuleMesur(obj);
}

TaskSchedRuleMesur TaskSchedRuleMesur::create(const QVariantMap &values)
{
    TaskSchedRuleMesur model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskSchedRuleMesur TaskSchedRuleMesur::get(int taskId, int dataTypeId, int mesurUnitId)
{
    TSqlORMapper<TaskSchedRuleMesurObject> mapper;
    return TaskSchedRuleMesur(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(dataTypeId)<<QVariant(mesurUnitId)));
}

int TaskSchedRuleMesur::count()
{
    TSqlORMapper<TaskSchedRuleMesurObject> mapper;
    return mapper.findCount();
}

QList<TaskSchedRuleMesur> TaskSchedRuleMesur::getAll()
{
    return tfGetModelListByCriteria<TaskSchedRuleMesur, TaskSchedRuleMesurObject>();
}

TModelObject *TaskSchedRuleMesur::modelData()
{
    return d.data();
}

const TModelObject *TaskSchedRuleMesur::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskSchedRuleMesur &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskSchedRuleMesur &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskSchedRuleMesur)
