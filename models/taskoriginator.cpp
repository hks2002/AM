#include <TreeFrogModel>
#include "taskoriginator.h"
#include "taskoriginatorobject.h"

TaskOriginator::TaskOriginator()
    : TAbstractModel(), d(new TaskOriginatorObject())
{
    d->task_originator_id = 0;
}

TaskOriginator::TaskOriginator(const TaskOriginator &other)
    : TAbstractModel(), d(new TaskOriginatorObject(*other.d))
{ }

TaskOriginator::TaskOriginator(const TaskOriginatorObject &object)
    : TAbstractModel(), d(new TaskOriginatorObject(object))
{ }

TaskOriginator::~TaskOriginator()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskOriginatorObject' is deleted.
}

int TaskOriginator::taskOriginatorId() const
{
    return d->task_originator_id;
}

QString TaskOriginator::taskOriginatorCd() const
{
    return d->task_originator_cd;
}

void TaskOriginator::setTaskOriginatorCd(const QString &taskOriginatorCd)
{
    d->task_originator_cd = taskOriginatorCd;
}

QString TaskOriginator::taskOriginatorNameZh() const
{
    return d->task_originator_name_zh;
}

void TaskOriginator::setTaskOriginatorNameZh(const QString &taskOriginatorNameZh)
{
    d->task_originator_name_zh = taskOriginatorNameZh;
}

QString TaskOriginator::taskOriginatorNameEn() const
{
    return d->task_originator_name_en;
}

void TaskOriginator::setTaskOriginatorNameEn(const QString &taskOriginatorNameEn)
{
    d->task_originator_name_en = taskOriginatorNameEn;
}

QDateTime TaskOriginator::createdAt() const
{
    return d->created_at;
}

QString TaskOriginator::createdBy() const
{
    return d->created_by;
}

void TaskOriginator::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskOriginator::updatedAt() const
{
    return d->updated_at;
}

QString TaskOriginator::updatedBy() const
{
    return d->updated_by;
}

void TaskOriginator::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskOriginator &TaskOriginator::operator=(const TaskOriginator &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskOriginator TaskOriginator::create(const QString &taskOriginatorCd, const QString &taskOriginatorNameZh, const QString &taskOriginatorNameEn, const QString &createdBy, const QString &updatedBy)
{
    TaskOriginatorObject obj;
    obj.task_originator_cd = taskOriginatorCd;
    obj.task_originator_name_zh = taskOriginatorNameZh;
    obj.task_originator_name_en = taskOriginatorNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskOriginator();
    }
    return TaskOriginator(obj);
}

TaskOriginator TaskOriginator::create(const QVariantMap &values)
{
    TaskOriginator model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskOriginator TaskOriginator::get(int taskOriginatorId)
{
    TSqlORMapper<TaskOriginatorObject> mapper;
    return TaskOriginator(mapper.findByPrimaryKey(taskOriginatorId));
}

int TaskOriginator::count()
{
    TSqlORMapper<TaskOriginatorObject> mapper;
    return mapper.findCount();
}

QList<TaskOriginator> TaskOriginator::getAll()
{
    return tfGetModelListByCriteria<TaskOriginator, TaskOriginatorObject>();
}

TModelObject *TaskOriginator::modelData()
{
    return d.data();
}

const TModelObject *TaskOriginator::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskOriginator &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskOriginator &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskOriginator)
