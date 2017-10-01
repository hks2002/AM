#include <TreeFrogModel>
#include "refschedpartstatus.h"
#include "refschedpartstatusobject.h"

RefSchedPartStatus::RefSchedPartStatus()
    : TAbstractModel(), d(new RefSchedPartStatusObject())
{ }

RefSchedPartStatus::RefSchedPartStatus(const RefSchedPartStatus &other)
    : TAbstractModel(), d(new RefSchedPartStatusObject(*other.d))
{ }

RefSchedPartStatus::RefSchedPartStatus(const RefSchedPartStatusObject &object)
    : TAbstractModel(), d(new RefSchedPartStatusObject(object))
{ }

RefSchedPartStatus::~RefSchedPartStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefSchedPartStatusObject' is deleted.
}

QString RefSchedPartStatus::schedPartStatusCd() const
{
    return d->sched_part_status_cd;
}

void RefSchedPartStatus::setSchedPartStatusCd(const QString &schedPartStatusCd)
{
    d->sched_part_status_cd = schedPartStatusCd;
}

QString RefSchedPartStatus::schedPartStatusNameEn() const
{
    return d->sched_part_status_name_en;
}

void RefSchedPartStatus::setSchedPartStatusNameEn(const QString &schedPartStatusNameEn)
{
    d->sched_part_status_name_en = schedPartStatusNameEn;
}

QString RefSchedPartStatus::schedPartStatusNameZh() const
{
    return d->sched_part_status_name_zh;
}

void RefSchedPartStatus::setSchedPartStatusNameZh(const QString &schedPartStatusNameZh)
{
    d->sched_part_status_name_zh = schedPartStatusNameZh;
}

QString RefSchedPartStatus::schedPartStatusDesc() const
{
    return d->sched_part_status_desc;
}

void RefSchedPartStatus::setSchedPartStatusDesc(const QString &schedPartStatusDesc)
{
    d->sched_part_status_desc = schedPartStatusDesc;
}

QDateTime RefSchedPartStatus::createdAt() const
{
    return d->created_at;
}

QString RefSchedPartStatus::createdBy() const
{
    return d->created_by;
}

void RefSchedPartStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefSchedPartStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefSchedPartStatus::updatedBy() const
{
    return d->updated_by;
}

void RefSchedPartStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefSchedPartStatus &RefSchedPartStatus::operator=(const RefSchedPartStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefSchedPartStatus RefSchedPartStatus::create(const QString &schedPartStatusCd, const QString &schedPartStatusNameEn, const QString &schedPartStatusNameZh, const QString &schedPartStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefSchedPartStatusObject obj;
    obj.sched_part_status_cd = schedPartStatusCd;
    obj.sched_part_status_name_en = schedPartStatusNameEn;
    obj.sched_part_status_name_zh = schedPartStatusNameZh;
    obj.sched_part_status_desc = schedPartStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefSchedPartStatus();
    }
    return RefSchedPartStatus(obj);
}

RefSchedPartStatus RefSchedPartStatus::create(const QVariantMap &values)
{
    RefSchedPartStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefSchedPartStatus RefSchedPartStatus::get(const QString &schedPartStatusCd)
{
    TSqlORMapper<RefSchedPartStatusObject> mapper;
    return RefSchedPartStatus(mapper.findByPrimaryKey(schedPartStatusCd));
}

int RefSchedPartStatus::count()
{
    TSqlORMapper<RefSchedPartStatusObject> mapper;
    return mapper.findCount();
}

QList<RefSchedPartStatus> RefSchedPartStatus::getAll()
{
    return tfGetModelListByCriteria<RefSchedPartStatus, RefSchedPartStatusObject>();
}

TModelObject *RefSchedPartStatus::modelData()
{
    return d.data();
}

const TModelObject *RefSchedPartStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefSchedPartStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefSchedPartStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefSchedPartStatus)
