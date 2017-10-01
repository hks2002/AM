#include <TreeFrogModel>
#include "advsrypart.h"
#include "advsrypartobject.h"
#include "eqppartno.h"
#include "manufact.h"
#include "advsry.h"

AdvsryPart::AdvsryPart()
    : TAbstractModel(), d(new AdvsryPartObject())
{
    d->advsry_id = 0;
    d->manufact_id = 0;
    d->part_no_id = 0;
}

AdvsryPart::AdvsryPart(const AdvsryPart &other)
    : TAbstractModel(), d(new AdvsryPartObject(*other.d))
{ }

AdvsryPart::AdvsryPart(const AdvsryPartObject &object)
    : TAbstractModel(), d(new AdvsryPartObject(object))
{ }

AdvsryPart::~AdvsryPart()
{
    // If the reference count becomes 0,
    // the shared data object 'AdvsryPartObject' is deleted.
}

int AdvsryPart::advsryId() const
{
    return d->advsry_id;
}

void AdvsryPart::setAdvsryId(int advsryId)
{
    d->advsry_id = advsryId;
}

int AdvsryPart::manufactId() const
{
    return d->manufact_id;
}

void AdvsryPart::setManufactId(int manufactId)
{
    d->manufact_id = manufactId;
}

int AdvsryPart::partNoId() const
{
    return d->part_no_id;
}

void AdvsryPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString AdvsryPart::lotNoRange() const
{
    return d->lot_no_range;
}

void AdvsryPart::setLotNoRange(const QString &lotNoRange)
{
    d->lot_no_range = lotNoRange;
}

QString AdvsryPart::serialNoRange() const
{
    return d->serial_no_range;
}

void AdvsryPart::setSerialNoRange(const QString &serialNoRange)
{
    d->serial_no_range = serialNoRange;
}

bool AdvsryPart::activeBool() const
{
    return d->active_bool;
}

void AdvsryPart::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime AdvsryPart::createdAt() const
{
    return d->created_at;
}

QString AdvsryPart::createdBy() const
{
    return d->created_by;
}

void AdvsryPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime AdvsryPart::updatedAt() const
{
    return d->updated_at;
}

QString AdvsryPart::updatedBy() const
{
    return d->updated_by;
}

void AdvsryPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo AdvsryPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Manufact AdvsryPart::manufactBymanufactId() const
{
 return Manufact::get(d->manufact_id);
}

Advsry AdvsryPart::advsryByadvsryId() const
{
 return Advsry::get(d->advsry_id);
}

AdvsryPart &AdvsryPart::operator=(const AdvsryPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AdvsryPart AdvsryPart::create(int advsryId, int manufactId, int partNoId, const QString &lotNoRange, const QString &serialNoRange, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    AdvsryPartObject obj;
    obj.advsry_id = advsryId;
    obj.manufact_id = manufactId;
    obj.part_no_id = partNoId;
    obj.lot_no_range = lotNoRange;
    obj.serial_no_range = serialNoRange;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return AdvsryPart();
    }
    return AdvsryPart(obj);
}

AdvsryPart AdvsryPart::create(const QVariantMap &values)
{
    AdvsryPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AdvsryPart AdvsryPart::get(int advsryId, int manufactId, int partNoId)
{
    TSqlORMapper<AdvsryPartObject> mapper;
    return AdvsryPart(mapper.findByPrimaryKey(QVariantList()<<QVariant(advsryId)<<QVariant(manufactId)<<QVariant(partNoId)));
}

int AdvsryPart::count()
{
    TSqlORMapper<AdvsryPartObject> mapper;
    return mapper.findCount();
}

QList<AdvsryPart> AdvsryPart::getAll()
{
    return tfGetModelListByCriteria<AdvsryPart, AdvsryPartObject>();
}

TModelObject *AdvsryPart::modelData()
{
    return d.data();
}

const TModelObject *AdvsryPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AdvsryPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AdvsryPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AdvsryPart)
