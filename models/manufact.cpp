#include <TreeFrogModel>
#include "manufact.h"
#include "manufactobject.h"

Manufact::Manufact()
    : TAbstractModel(), d(new ManufactObject())
{
    d->manufact_id = 0;
}

Manufact::Manufact(const Manufact &other)
    : TAbstractModel(), d(new ManufactObject(*other.d))
{ }

Manufact::Manufact(const ManufactObject &object)
    : TAbstractModel(), d(new ManufactObject(object))
{ }

Manufact::~Manufact()
{
    // If the reference count becomes 0,
    // the shared data object 'ManufactObject' is deleted.
}

int Manufact::manufactId() const
{
    return d->manufact_id;
}

QString Manufact::manufactCd() const
{
    return d->manufact_cd;
}

void Manufact::setManufactCd(const QString &manufactCd)
{
    d->manufact_cd = manufactCd;
}

QString Manufact::manufactName() const
{
    return d->manufact_name;
}

void Manufact::setManufactName(const QString &manufactName)
{
    d->manufact_name = manufactName;
}

QDateTime Manufact::createdAt() const
{
    return d->created_at;
}

QString Manufact::createdBy() const
{
    return d->created_by;
}

void Manufact::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Manufact::updatedAt() const
{
    return d->updated_at;
}

QString Manufact::updatedBy() const
{
    return d->updated_by;
}

void Manufact::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Manufact &Manufact::operator=(const Manufact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Manufact Manufact::create(const QString &manufactCd, const QString &manufactName, const QString &createdBy, const QString &updatedBy)
{
    ManufactObject obj;
    obj.manufact_cd = manufactCd;
    obj.manufact_name = manufactName;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Manufact();
    }
    return Manufact(obj);
}

Manufact Manufact::create(const QVariantMap &values)
{
    Manufact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Manufact Manufact::get(int manufactId)
{
    TSqlORMapper<ManufactObject> mapper;
    return Manufact(mapper.findByPrimaryKey(manufactId));
}

int Manufact::count()
{
    TSqlORMapper<ManufactObject> mapper;
    return mapper.findCount();
}

QList<Manufact> Manufact::getAll()
{
    return tfGetModelListByCriteria<Manufact, ManufactObject>();
}

TModelObject *Manufact::modelData()
{
    return d.data();
}

const TModelObject *Manufact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Manufact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Manufact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Manufact)
