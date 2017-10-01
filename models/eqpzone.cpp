#include <TreeFrogModel>
#include "eqpzone.h"
#include "eqpzoneobject.h"
#include "eqpassmbl.h"

EqpZone::EqpZone()
    : TAbstractModel(), d(new EqpZoneObject())
{
    d->zone_id = 0;
    d->assmbl_id = 0;
}

EqpZone::EqpZone(const EqpZone &other)
    : TAbstractModel(), d(new EqpZoneObject(*other.d))
{ }

EqpZone::EqpZone(const EqpZoneObject &object)
    : TAbstractModel(), d(new EqpZoneObject(object))
{ }

EqpZone::~EqpZone()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpZoneObject' is deleted.
}

int EqpZone::zoneId() const
{
    return d->zone_id;
}

int EqpZone::assmblId() const
{
    return d->assmbl_id;
}

void EqpZone::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

QString EqpZone::zoneCd() const
{
    return d->zone_cd;
}

void EqpZone::setZoneCd(const QString &zoneCd)
{
    d->zone_cd = zoneCd;
}

QString EqpZone::descDesc() const
{
    return d->desc_desc;
}

void EqpZone::setDescDesc(const QString &descDesc)
{
    d->desc_desc = descDesc;
}

QDateTime EqpZone::createdAt() const
{
    return d->created_at;
}

QString EqpZone::createdBy() const
{
    return d->created_by;
}

void EqpZone::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpZone::updatedAt() const
{
    return d->updated_at;
}

QString EqpZone::updatedBy() const
{
    return d->updated_by;
}

void EqpZone::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpAssmbl EqpZone::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

EqpZone &EqpZone::operator=(const EqpZone &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpZone EqpZone::create(int assmblId, const QString &zoneCd, const QString &descDesc, const QString &createdBy, const QString &updatedBy)
{
    EqpZoneObject obj;
    obj.assmbl_id = assmblId;
    obj.zone_cd = zoneCd;
    obj.desc_desc = descDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpZone();
    }
    return EqpZone(obj);
}

EqpZone EqpZone::create(const QVariantMap &values)
{
    EqpZone model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpZone EqpZone::get(int zoneId)
{
    TSqlORMapper<EqpZoneObject> mapper;
    return EqpZone(mapper.findByPrimaryKey(zoneId));
}

int EqpZone::count()
{
    TSqlORMapper<EqpZoneObject> mapper;
    return mapper.findCount();
}

QList<EqpZone> EqpZone::getAll()
{
    return tfGetModelListByCriteria<EqpZone, EqpZoneObject>();
}

TModelObject *EqpZone::modelData()
{
    return d.data();
}

const TModelObject *EqpZone::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpZone &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpZone &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpZone)
