#include <TreeFrogModel>
#include "warrantyinittask.h"
#include "warrantyinittaskobject.h"
#include "schedstask.h"
#include "warrantyinit.h"

WarrantyInitTask::WarrantyInitTask()
    : TAbstractModel(), d(new WarrantyInitTaskObject())
{
    d->warranty_init_id = 0;
    d->sched_id = 0;
}

WarrantyInitTask::WarrantyInitTask(const WarrantyInitTask &other)
    : TAbstractModel(), d(new WarrantyInitTaskObject(*other.d))
{ }

WarrantyInitTask::WarrantyInitTask(const WarrantyInitTaskObject &object)
    : TAbstractModel(), d(new WarrantyInitTaskObject(object))
{ }

WarrantyInitTask::~WarrantyInitTask()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyInitTaskObject' is deleted.
}

int WarrantyInitTask::warrantyInitId() const
{
    return d->warranty_init_id;
}

void WarrantyInitTask::setWarrantyInitId(int warrantyInitId)
{
    d->warranty_init_id = warrantyInitId;
}

int WarrantyInitTask::schedId() const
{
    return d->sched_id;
}

void WarrantyInitTask::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

bool WarrantyInitTask::mainBool() const
{
    return d->main_bool;
}

void WarrantyInitTask::setMainBool(bool mainBool)
{
    d->main_bool = mainBool;
}

QDateTime WarrantyInitTask::createdAt() const
{
    return d->created_at;
}

QString WarrantyInitTask::createdBy() const
{
    return d->created_by;
}

void WarrantyInitTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyInitTask::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyInitTask::updatedBy() const
{
    return d->updated_by;
}

void WarrantyInitTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

SchedStask WarrantyInitTask::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

WarrantyInit WarrantyInitTask::warrantyInitBywarrantyInitId() const
{
 return WarrantyInit::get(d->warranty_init_id);
}

WarrantyInitTask &WarrantyInitTask::operator=(const WarrantyInitTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyInitTask WarrantyInitTask::create(int warrantyInitId, int schedId, bool mainBool, const QString &createdBy, const QString &updatedBy)
{
    WarrantyInitTaskObject obj;
    obj.warranty_init_id = warrantyInitId;
    obj.sched_id = schedId;
    obj.main_bool = mainBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyInitTask();
    }
    return WarrantyInitTask(obj);
}

WarrantyInitTask WarrantyInitTask::create(const QVariantMap &values)
{
    WarrantyInitTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyInitTask WarrantyInitTask::get(int warrantyInitId, int schedId)
{
    TSqlORMapper<WarrantyInitTaskObject> mapper;
    return WarrantyInitTask(mapper.findByPrimaryKey(QVariantList()<<QVariant(warrantyInitId)<<QVariant(schedId)));
}

int WarrantyInitTask::count()
{
    TSqlORMapper<WarrantyInitTaskObject> mapper;
    return mapper.findCount();
}

QList<WarrantyInitTask> WarrantyInitTask::getAll()
{
    return tfGetModelListByCriteria<WarrantyInitTask, WarrantyInitTaskObject>();
}

TModelObject *WarrantyInitTask::modelData()
{
    return d.data();
}

const TModelObject *WarrantyInitTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyInitTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyInitTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyInitTask)
