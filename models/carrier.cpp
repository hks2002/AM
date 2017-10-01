#include <TreeFrogModel>
#include "carrier.h"
#include "carrierobject.h"

Carrier::Carrier()
    : TAbstractModel(), d(new CarrierObject())
{
    d->carrier_id = 0;
}

Carrier::Carrier(const Carrier &other)
    : TAbstractModel(), d(new CarrierObject(*other.d))
{ }

Carrier::Carrier(const CarrierObject &object)
    : TAbstractModel(), d(new CarrierObject(object))
{ }

Carrier::~Carrier()
{
    // If the reference count becomes 0,
    // the shared data object 'CarrierObject' is deleted.
}

int Carrier::carrierId() const
{
    return d->carrier_id;
}

QString Carrier::carrierCd() const
{
    return d->carrier_cd;
}

void Carrier::setCarrierCd(const QString &carrierCd)
{
    d->carrier_cd = carrierCd;
}

QString Carrier::carrierName() const
{
    return d->carrier_name;
}

void Carrier::setCarrierName(const QString &carrierName)
{
    d->carrier_name = carrierName;
}

QDateTime Carrier::createdAt() const
{
    return d->created_at;
}

QString Carrier::createdBy() const
{
    return d->created_by;
}

void Carrier::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Carrier::updatedAt() const
{
    return d->updated_at;
}

QString Carrier::updatedBy() const
{
    return d->updated_by;
}

void Carrier::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Carrier &Carrier::operator=(const Carrier &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Carrier Carrier::create(const QString &carrierCd, const QString &carrierName, const QString &createdBy, const QString &updatedBy)
{
    CarrierObject obj;
    obj.carrier_cd = carrierCd;
    obj.carrier_name = carrierName;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Carrier();
    }
    return Carrier(obj);
}

Carrier Carrier::create(const QVariantMap &values)
{
    Carrier model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Carrier Carrier::get(int carrierId)
{
    TSqlORMapper<CarrierObject> mapper;
    return Carrier(mapper.findByPrimaryKey(carrierId));
}

int Carrier::count()
{
    TSqlORMapper<CarrierObject> mapper;
    return mapper.findCount();
}

QList<Carrier> Carrier::getAll()
{
    return tfGetModelListByCriteria<Carrier, CarrierObject>();
}

TModelObject *Carrier::modelData()
{
    return d.data();
}

const TModelObject *Carrier::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Carrier &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Carrier &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Carrier)
