#include <TreeFrogModel>
#include "refeventreason.h"
#include "refeventreasonobject.h"

RefEventReason::RefEventReason()
    : TAbstractModel(), d(new RefEventReasonObject())
{ }

RefEventReason::RefEventReason(const RefEventReason &other)
    : TAbstractModel(), d(new RefEventReasonObject(*other.d))
{ }

RefEventReason::RefEventReason(const RefEventReasonObject &object)
    : TAbstractModel(), d(new RefEventReasonObject(object))
{ }

RefEventReason::~RefEventReason()
{
    // If the reference count becomes 0,
    // the shared data object 'RefEventReasonObject' is deleted.
}

QString RefEventReason::eventReasonCd() const
{
    return d->event_reason_cd;
}

void RefEventReason::setEventReasonCd(const QString &eventReasonCd)
{
    d->event_reason_cd = eventReasonCd;
}

QString RefEventReason::eventReasonNameEn() const
{
    return d->event_reason_name_en;
}

void RefEventReason::setEventReasonNameEn(const QString &eventReasonNameEn)
{
    d->event_reason_name_en = eventReasonNameEn;
}

QString RefEventReason::eventReasonNameZh() const
{
    return d->event_reason_name_zh;
}

void RefEventReason::setEventReasonNameZh(const QString &eventReasonNameZh)
{
    d->event_reason_name_zh = eventReasonNameZh;
}

QString RefEventReason::eventReasonDesc() const
{
    return d->event_reason_desc;
}

void RefEventReason::setEventReasonDesc(const QString &eventReasonDesc)
{
    d->event_reason_desc = eventReasonDesc;
}

QDateTime RefEventReason::createdAt() const
{
    return d->created_at;
}

QString RefEventReason::createdBy() const
{
    return d->created_by;
}

void RefEventReason::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefEventReason::updatedAt() const
{
    return d->updated_at;
}

QString RefEventReason::updatedBy() const
{
    return d->updated_by;
}

void RefEventReason::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEventReason &RefEventReason::operator=(const RefEventReason &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefEventReason RefEventReason::create(const QString &eventReasonCd, const QString &eventReasonNameEn, const QString &eventReasonNameZh, const QString &eventReasonDesc, const QString &createdBy, const QString &updatedBy)
{
    RefEventReasonObject obj;
    obj.event_reason_cd = eventReasonCd;
    obj.event_reason_name_en = eventReasonNameEn;
    obj.event_reason_name_zh = eventReasonNameZh;
    obj.event_reason_desc = eventReasonDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefEventReason();
    }
    return RefEventReason(obj);
}

RefEventReason RefEventReason::create(const QVariantMap &values)
{
    RefEventReason model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefEventReason RefEventReason::get(const QString &eventReasonCd)
{
    TSqlORMapper<RefEventReasonObject> mapper;
    return RefEventReason(mapper.findByPrimaryKey(eventReasonCd));
}

int RefEventReason::count()
{
    TSqlORMapper<RefEventReasonObject> mapper;
    return mapper.findCount();
}

QList<RefEventReason> RefEventReason::getAll()
{
    return tfGetModelListByCriteria<RefEventReason, RefEventReasonObject>();
}

TModelObject *RefEventReason::modelData()
{
    return d.data();
}

const TModelObject *RefEventReason::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefEventReason &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefEventReason &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefEventReason)
