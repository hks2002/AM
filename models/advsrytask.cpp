#include <TreeFrogModel>
#include "advsrytask.h"
#include "advsrytaskobject.h"
#include "tasktask.h"
#include "advsry.h"

AdvsryTask::AdvsryTask()
    : TAbstractModel(), d(new AdvsryTaskObject())
{
    d->advsry_task_id = 0;
    d->advsry_id = 0;
    d->task_id = 0;
}

AdvsryTask::AdvsryTask(const AdvsryTask &other)
    : TAbstractModel(), d(new AdvsryTaskObject(*other.d))
{ }

AdvsryTask::AdvsryTask(const AdvsryTaskObject &object)
    : TAbstractModel(), d(new AdvsryTaskObject(object))
{ }

AdvsryTask::~AdvsryTask()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryTaskObject' is deleted.
}

int AdvsryTask::advsryTaskId() const
{
    return d->advsry_task_id;
}

int AdvsryTask::advsryId() const
{
    return d->advsry_id;
}

void AdvsryTask::setAdvsryId(int advsryId)
{
    d->advsry_id = advsryId;
}

int AdvsryTask::taskId() const
{
    return d->task_id;
}

void AdvsryTask::setTaskId(int taskId)
{
    d->task_id = taskId;
}

bool AdvsryTask::activeBool() const
{
    return d->active_bool;
}

void AdvsryTask::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime AdvsryTask::createdAt() const
{
    return d->created_at;
}

QString AdvsryTask::createdBy() const
{
    return d->created_by;
}

void AdvsryTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryTask::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryTask::updatedBy() const
{
    return d->updated_by;
}

void AdvsryTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskTask AdvsryTask::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

Advsry AdvsryTask::advsryByadvsryId() const
{
 return Advsry::get(d->advsry_id);
}

AdvsryTask &AdvsryTask::operator=(const AdvsryTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryTask AdvsryTask::create(int advsryId, int taskId, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    AdvsryTaskObject obj;
    obj.advsry_id = advsryId;
    obj.task_id = taskId;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryTask();
    }
    return AdvsryTask(obj);
}

AdvsryTask AdvsryTask::create(const QVariantMap &values)
{
    AdvsryTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryTask AdvsryTask::get(int advsryTaskId)
{
    TSqlORMapper<AdvsryTaskObject> mapper;
    return AdvsryTask(mapper.findByPrimaryKey(advsryTaskId));
}

int AdvsryTask::count()
{
    TSqlORMapper<AdvsryTaskObject> mapper;
    return mapper.findCount();
}

QList<AdvsryTask> AdvsryTask::getAll()
{
    return tfGetModelListByCriteria<AdvsryTask, AdvsryTaskObject>();
}

TModelObject *AdvsryTask::modelData()
{
    return d.data();
}

const TModelObject *AdvsryTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryTask)
