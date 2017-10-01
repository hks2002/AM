#include <TreeFrogModel>
#include "refeventtype.h"
#include "refeventtypeobject.h"

RefEventType::RefEventType()
    : TAbstractModel(), d(new RefEventTypeObject())
{ }

RefEventType::RefEventType(const RefEventType &other)
    : TAbstractModel(), d(new RefEventTypeObject(*other.d))
{ }

RefEventType::RefEventType(const RefEventTypeObject &object)
    : TAbstractModel(), d(new RefEventTypeObject(object))
{ }

RefEventType::~RefEventType()
{
    // If the reference count becomes 0,
    // the shared data object 'RefEventTypeObject' is deleted.
}

QString RefEventType::eventTypeCd() const
{
    return d->event_type_cd;
}

void RefEventType::setEventTypeCd(const QString &eventTypeCd)
{
    d->event_type_cd = eventTypeCd;
}

QString RefEventType::eventTypeNameEn() const
{
    return d->event_type_name_en;
}

void RefEventType::setEventTypeNameEn(const QString &eventTypeNameEn)
{
    d->event_type_name_en = eventTypeNameEn;
}

QString RefEventType::eventTypeNameZh() const
{
    return d->event_type_name_zh;
}

void RefEventType::setEventTypeNameZh(const QString &eventTypeNameZh)
{
    d->event_type_name_zh = eventTypeNameZh;
}

QString RefEventType::eventTypeDesc() const
{
    return d->event_type_desc;
}

void RefEventType::setEventTypeDesc(const QString &eventTypeDesc)
{
    d->event_type_desc = eventTypeDesc;
}

QDateTime RefEventType::createdAt() const
{
    return d->created_at;
}

QString RefEventType::createdBy() const
{
    return d->created_by;
}

void RefEventType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefEventType::updatedAt() const
{
    return d->updated_at;
}

QString RefEventType::updatedBy() const
{
    return d->updated_by;
}

void RefEventType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEventType &RefEventType::operator=(const RefEventType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefEventType RefEventType::create(const QString &eventTypeCd, const QString &eventTypeNameEn, const QString &eventTypeNameZh, const QString &eventTypeDesc, const QString &createdBy, const QString &updatedBy)
{
    RefEventTypeObject obj;
    obj.event_type_cd = eventTypeCd;
    obj.event_type_name_en = eventTypeNameEn;
    obj.event_type_name_zh = eventTypeNameZh;
    obj.event_type_desc = eventTypeDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefEventType();
    }
    return RefEventType(obj);
}

RefEventType RefEventType::create(const QVariantMap &values)
{
    RefEventType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefEventType RefEventType::get(const QString &eventTypeCd)
{
    TSqlORMapper<RefEventTypeObject> mapper;
    return RefEventType(mapper.findByPrimaryKey(eventTypeCd));
}

int RefEventType::count()
{
    TSqlORMapper<RefEventTypeObject> mapper;
    return mapper.findCount();
}

QList<RefEventType> RefEventType::getAll()
{
    return tfGetModelListByCriteria<RefEventType, RefEventTypeObject>();
}

TModelObject *RefEventType::modelData()
{
    return d.data();
}

const TModelObject *RefEventType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefEventType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefEventType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefEventType)
