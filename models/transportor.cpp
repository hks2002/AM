#include <TreeFrogModel>
#include "transportor.h"
#include "transportorobject.h"

Transportor::Transportor()
    : TAbstractModel(), d(new TransportorObject())
{
    d->transportor_id = 0;
}

Transportor::Transportor(const Transportor &other)
    : TAbstractModel(), d(new TransportorObject(*other.d))
{ }

Transportor::Transportor(const TransportorObject &object)
    : TAbstractModel(), d(new TransportorObject(object))
{ }

Transportor::~Transportor()
{
    // If the reference count becomes 0,
    // the shared data object 'TransportorObject' is deleted.
}

int Transportor::transportorId() const
{
    return d->transportor_id;
}

QString Transportor::transportorCd() const
{
    return d->transportor_cd;
}

void Transportor::setTransportorCd(const QString &transportorCd)
{
    d->transportor_cd = transportorCd;
}

QString Transportor::transportorNameZh() const
{
    return d->transportor_name_zh;
}

void Transportor::setTransportorNameZh(const QString &transportorNameZh)
{
    d->transportor_name_zh = transportorNameZh;
}

QString Transportor::transportorNameEn() const
{
    return d->transportor_name_en;
}

void Transportor::setTransportorNameEn(const QString &transportorNameEn)
{
    d->transportor_name_en = transportorNameEn;
}

QDateTime Transportor::createdAt() const
{
    return d->created_at;
}

QString Transportor::createdBy() const
{
    return d->created_by;
}

void Transportor::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Transportor::updatedAt() const
{
    return d->updated_at;
}

QString Transportor::updatedBy() const
{
    return d->updated_by;
}

void Transportor::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Transportor &Transportor::operator=(const Transportor &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Transportor Transportor::create(const QString &transportorCd, const QString &transportorNameZh, const QString &transportorNameEn, const QString &createdBy, const QString &updatedBy)
{
    TransportorObject obj;
    obj.transportor_cd = transportorCd;
    obj.transportor_name_zh = transportorNameZh;
    obj.transportor_name_en = transportorNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Transportor();
    }
    return Transportor(obj);
}

Transportor Transportor::create(const QVariantMap &values)
{
    Transportor model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Transportor Transportor::get(int transportorId)
{
    TSqlORMapper<TransportorObject> mapper;
    return Transportor(mapper.findByPrimaryKey(transportorId));
}

int Transportor::count()
{
    TSqlORMapper<TransportorObject> mapper;
    return mapper.findCount();
}

QList<Transportor> Transportor::getAll()
{
    return tfGetModelListByCriteria<Transportor, TransportorObject>();
}

TModelObject *Transportor::modelData()
{
    return d.data();
}

const TModelObject *Transportor::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Transportor &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Transportor &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Transportor)
