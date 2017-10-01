#include <TreeFrogModel>
#include "tasksubclass.h"
#include "tasksubclassobject.h"

TaskSubclass::TaskSubclass()
    : TAbstractModel(), d(new TaskSubclassObject())
{
    d->task_subclass_id = 0;
}

TaskSubclass::TaskSubclass(const TaskSubclass &other)
    : TAbstractModel(), d(new TaskSubclassObject(*other.d))
{ }

TaskSubclass::TaskSubclass(const TaskSubclassObject &object)
    : TAbstractModel(), d(new TaskSubclassObject(object))
{ }

TaskSubclass::~TaskSubclass()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskSubclassObject' is deleted.
}

int TaskSubclass::taskSubclassId() const
{
    return d->task_subclass_id;
}

QString TaskSubclass::taskSubclassCd() const
{
    return d->task_subclass_cd;
}

void TaskSubclass::setTaskSubclassCd(const QString &taskSubclassCd)
{
    d->task_subclass_cd = taskSubclassCd;
}

QString TaskSubclass::taskSubclassNameZh() const
{
    return d->task_subclass_name_zh;
}

void TaskSubclass::setTaskSubclassNameZh(const QString &taskSubclassNameZh)
{
    d->task_subclass_name_zh = taskSubclassNameZh;
}

QString TaskSubclass::taskSubclassNameEn() const
{
    return d->task_subclass_name_en;
}

void TaskSubclass::setTaskSubclassNameEn(const QString &taskSubclassNameEn)
{
    d->task_subclass_name_en = taskSubclassNameEn;
}

QDateTime TaskSubclass::createdAt() const
{
    return d->created_at;
}

QString TaskSubclass::createdBy() const
{
    return d->created_by;
}

void TaskSubclass::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskSubclass::updatedAt() const
{
    return d->updated_at;
}

QString TaskSubclass::updatedBy() const
{
    return d->updated_by;
}

void TaskSubclass::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskSubclass &TaskSubclass::operator=(const TaskSubclass &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskSubclass TaskSubclass::create(const QString &taskSubclassCd, const QString &taskSubclassNameZh, const QString &taskSubclassNameEn, const QString &createdBy, const QString &updatedBy)
{
    TaskSubclassObject obj;
    obj.task_subclass_cd = taskSubclassCd;
    obj.task_subclass_name_zh = taskSubclassNameZh;
    obj.task_subclass_name_en = taskSubclassNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskSubclass();
    }
    return TaskSubclass(obj);
}

TaskSubclass TaskSubclass::create(const QVariantMap &values)
{
    TaskSubclass model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskSubclass TaskSubclass::get(int taskSubclassId)
{
    TSqlORMapper<TaskSubclassObject> mapper;
    return TaskSubclass(mapper.findByPrimaryKey(taskSubclassId));
}

int TaskSubclass::count()
{
    TSqlORMapper<TaskSubclassObject> mapper;
    return mapper.findCount();
}

QList<TaskSubclass> TaskSubclass::getAll()
{
    return tfGetModelListByCriteria<TaskSubclass, TaskSubclassObject>();
}

TModelObject *TaskSubclass::modelData()
{
    return d.data();
}

const TModelObject *TaskSubclass::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskSubclass &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskSubclass &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskSubclass)
