#include <TreeFrogModel>
#include "refeventstatus.h"
#include "refeventstatusobject.h"

RefEventStatus::RefEventStatus()
    : TAbstractModel(), d(new RefEventStatusObject())
{ }

RefEventStatus::RefEventStatus(const RefEventStatus &other)
    : TAbstractModel(), d(new RefEventStatusObject(*other.d))
{ }

RefEventStatus::RefEventStatus(const RefEventStatusObject &object)
    : TAbstractModel(), d(new RefEventStatusObject(object))
{ }

RefEventStatus::~RefEventStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefEventStatusObject' is deleted.
}

QString RefEventStatus::eventStatusCd() const
{
    return d->event_status_cd;
}

void RefEventStatus::setEventStatusCd(const QString &eventStatusCd)
{
    d->event_status_cd = eventStatusCd;
}

QString RefEventStatus::eventStatusNameEn() const
{
    return d->event_status_name_en;
}

void RefEventStatus::setEventStatusNameEn(const QString &eventStatusNameEn)
{
    d->event_status_name_en = eventStatusNameEn;
}

QString RefEventStatus::eventStatusNameZh() const
{
    return d->event_status_name_zh;
}

void RefEventStatus::setEventStatusNameZh(const QString &eventStatusNameZh)
{
    d->event_status_name_zh = eventStatusNameZh;
}

QString RefEventStatus::eventStatusDesc() const
{
    return d->event_status_desc;
}

void RefEventStatus::setEventStatusDesc(const QString &eventStatusDesc)
{
    d->event_status_desc = eventStatusDesc;
}

QDateTime RefEventStatus::createdAt() const
{
    return d->created_at;
}

QString RefEventStatus::createdBy() const
{
    return d->created_by;
}

void RefEventStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefEventStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefEventStatus::updatedBy() const
{
    return d->updated_by;
}

void RefEventStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEventStatus &RefEventStatus::operator=(const RefEventStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefEventStatus RefEventStatus::create(const QString &eventStatusCd, const QString &eventStatusNameEn, const QString &eventStatusNameZh, const QString &eventStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefEventStatusObject obj;
    obj.event_status_cd = eventStatusCd;
    obj.event_status_name_en = eventStatusNameEn;
    obj.event_status_name_zh = eventStatusNameZh;
    obj.event_status_desc = eventStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefEventStatus();
    }
    return RefEventStatus(obj);
}

RefEventStatus RefEventStatus::create(const QVariantMap &values)
{
    RefEventStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefEventStatus RefEventStatus::get(const QString &eventStatusCd)
{
    TSqlORMapper<RefEventStatusObject> mapper;
    return RefEventStatus(mapper.findByPrimaryKey(eventStatusCd));
}

int RefEventStatus::count()
{
    TSqlORMapper<RefEventStatusObject> mapper;
    return mapper.findCount();
}

QList<RefEventStatus> RefEventStatus::getAll()
{
    return tfGetModelListByCriteria<RefEventStatus, RefEventStatusObject>();
}

TModelObject *RefEventStatus::modelData()
{
    return d.data();
}

const TModelObject *RefEventStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefEventStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefEventStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefEventStatus)
