#include <TreeFrogModel>
#include "reftaskdefstatus.h"
#include "reftaskdefstatusobject.h"

RefTaskDefStatus::RefTaskDefStatus()
    : TAbstractModel(), d(new RefTaskDefStatusObject())
{ }

RefTaskDefStatus::RefTaskDefStatus(const RefTaskDefStatus &other)
    : TAbstractModel(), d(new RefTaskDefStatusObject(*other.d))
{ }

RefTaskDefStatus::RefTaskDefStatus(const RefTaskDefStatusObject &object)
    : TAbstractModel(), d(new RefTaskDefStatusObject(object))
{ }

RefTaskDefStatus::~RefTaskDefStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefTaskDefStatusObject' is deleted.
}

QString RefTaskDefStatus::taskDefStatusCd() const
{
    return d->task_def_status_cd;
}

void RefTaskDefStatus::setTaskDefStatusCd(const QString &taskDefStatusCd)
{
    d->task_def_status_cd = taskDefStatusCd;
}

QString RefTaskDefStatus::taskDefStatusNameEn() const
{
    return d->task_def_status_name_en;
}

void RefTaskDefStatus::setTaskDefStatusNameEn(const QString &taskDefStatusNameEn)
{
    d->task_def_status_name_en = taskDefStatusNameEn;
}

QString RefTaskDefStatus::taskDefStatusNameZh() const
{
    return d->task_def_status_name_zh;
}

void RefTaskDefStatus::setTaskDefStatusNameZh(const QString &taskDefStatusNameZh)
{
    d->task_def_status_name_zh = taskDefStatusNameZh;
}

QString RefTaskDefStatus::taskDefStatusDesc() const
{
    return d->task_def_status_desc;
}

void RefTaskDefStatus::setTaskDefStatusDesc(const QString &taskDefStatusDesc)
{
    d->task_def_status_desc = taskDefStatusDesc;
}

QDateTime RefTaskDefStatus::createdAt() const
{
    return d->created_at;
}

QString RefTaskDefStatus::createdBy() const
{
    return d->created_by;
}

void RefTaskDefStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefTaskDefStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefTaskDefStatus::updatedBy() const
{
    return d->updated_by;
}

void RefTaskDefStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefTaskDefStatus &RefTaskDefStatus::operator=(const RefTaskDefStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefTaskDefStatus RefTaskDefStatus::create(const QString &taskDefStatusCd, const QString &taskDefStatusNameEn, const QString &taskDefStatusNameZh, const QString &taskDefStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefTaskDefStatusObject obj;
    obj.task_def_status_cd = taskDefStatusCd;
    obj.task_def_status_name_en = taskDefStatusNameEn;
    obj.task_def_status_name_zh = taskDefStatusNameZh;
    obj.task_def_status_desc = taskDefStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefTaskDefStatus();
    }
    return RefTaskDefStatus(obj);
}

RefTaskDefStatus RefTaskDefStatus::create(const QVariantMap &values)
{
    RefTaskDefStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefTaskDefStatus RefTaskDefStatus::get(const QString &taskDefStatusCd)
{
    TSqlORMapper<RefTaskDefStatusObject> mapper;
    return RefTaskDefStatus(mapper.findByPrimaryKey(taskDefStatusCd));
}

int RefTaskDefStatus::count()
{
    TSqlORMapper<RefTaskDefStatusObject> mapper;
    return mapper.findCount();
}

QList<RefTaskDefStatus> RefTaskDefStatus::getAll()
{
    return tfGetModelListByCriteria<RefTaskDefStatus, RefTaskDefStatusObject>();
}

TModelObject *RefTaskDefStatus::modelData()
{
    return d.data();
}

const TModelObject *RefTaskDefStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefTaskDefStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefTaskDefStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefTaskDefStatus)
