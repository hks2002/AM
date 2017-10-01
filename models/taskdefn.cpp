#include <TreeFrogModel>
#include "taskdefn.h"
#include "taskdefnobject.h"

TaskDefn::TaskDefn()
    : TAbstractModel(), d(new TaskDefnObject())
{
    d->task_defn_id = 0;
    d->last_revision_ord = 0;
}

TaskDefn::TaskDefn(const TaskDefn &other)
    : TAbstractModel(), d(new TaskDefnObject(*other.d))
{ }

TaskDefn::TaskDefn(const TaskDefnObject &object)
    : TAbstractModel(), d(new TaskDefnObject(object))
{ }

TaskDefn::~TaskDefn()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskDefnObject' is deleted.
}

int TaskDefn::taskDefnId() const
{
    return d->task_defn_id;
}

int TaskDefn::lastRevisionOrd() const
{
    return d->last_revision_ord;
}

void TaskDefn::setLastRevisionOrd(int lastRevisionOrd)
{
    d->last_revision_ord = lastRevisionOrd;
}

bool TaskDefn::newRevisionBool() const
{
    return d->new_revision_bool;
}

void TaskDefn::setNewRevisionBool(bool newRevisionBool)
{
    d->new_revision_bool = newRevisionBool;
}

QDateTime TaskDefn::createdAt() const
{
    return d->created_at;
}

QString TaskDefn::createdBy() const
{
    return d->created_by;
}

void TaskDefn::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskDefn::updatedAt() const
{
    return d->updated_at;
}

QString TaskDefn::updatedBy() const
{
    return d->updated_by;
}

void TaskDefn::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskDefn &TaskDefn::operator=(const TaskDefn &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskDefn TaskDefn::create(int lastRevisionOrd, bool newRevisionBool, const QString &createdBy, const QString &updatedBy)
{
    TaskDefnObject obj;
    obj.last_revision_ord = lastRevisionOrd;
    obj.new_revision_bool = newRevisionBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskDefn();
    }
    return TaskDefn(obj);
}

TaskDefn TaskDefn::create(const QVariantMap &values)
{
    TaskDefn model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskDefn TaskDefn::get(int taskDefnId)
{
    TSqlORMapper<TaskDefnObject> mapper;
    return TaskDefn(mapper.findByPrimaryKey(taskDefnId));
}

int TaskDefn::count()
{
    TSqlORMapper<TaskDefnObject> mapper;
    return mapper.findCount();
}

QList<TaskDefn> TaskDefn::getAll()
{
    return tfGetModelListByCriteria<TaskDefn, TaskDefnObject>();
}

TModelObject *TaskDefn::modelData()
{
    return d.data();
}

const TModelObject *TaskDefn::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskDefn &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskDefn &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskDefn)
