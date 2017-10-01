#include <TreeFrogModel>
#include "charge.h"
#include "chargeobject.h"
#include "fncaccount.h"

Charge::Charge()
    : TAbstractModel(), d(new ChargeObject())
{
    d->charge_id = 0;
    d->account_id = 0;
}

Charge::Charge(const Charge &other)
    : TAbstractModel(), d(new ChargeObject(*other.d))
{ }

Charge::Charge(const ChargeObject &object)
    : TAbstractModel(), d(new ChargeObject(object))
{ }

Charge::~Charge()
{
    // If the reference count becomes 0,
    // the shared data object 'ChargeObject' is deleted.
}

int Charge::chargeId() const
{
    return d->charge_id;
}

QString Charge::chargeCd() const
{
    return d->charge_cd;
}

void Charge::setChargeCd(const QString &chargeCd)
{
    d->charge_cd = chargeCd;
}

QString Charge::chargeName() const
{
    return d->charge_name;
}

void Charge::setChargeName(const QString &chargeName)
{
    d->charge_name = chargeName;
}

int Charge::accountId() const
{
    return d->account_id;
}

void Charge::setAccountId(int accountId)
{
    d->account_id = accountId;
}

bool Charge::recoverableBool() const
{
    return d->recoverable_bool;
}

void Charge::setRecoverableBool(bool recoverableBool)
{
    d->recoverable_bool = recoverableBool;
}

bool Charge::archiveBool() const
{
    return d->archive_bool;
}

void Charge::setArchiveBool(bool archiveBool)
{
    d->archive_bool = archiveBool;
}

QDateTime Charge::createdAt() const
{
    return d->created_at;
}

QString Charge::createdBy() const
{
    return d->created_by;
}

void Charge::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Charge::updatedAt() const
{
    return d->updated_at;
}

QString Charge::updatedBy() const
{
    return d->updated_by;
}

void Charge::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount Charge::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

Charge &Charge::operator=(const Charge &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Charge Charge::create(const QString &chargeCd, const QString &chargeName, int accountId, bool recoverableBool, bool archiveBool, const QString &createdBy, const QString &updatedBy)
{
    ChargeObject obj;
    obj.charge_cd = chargeCd;
    obj.charge_name = chargeName;
    obj.account_id = accountId;
    obj.recoverable_bool = recoverableBool;
    obj.archive_bool = archiveBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Charge();
    }
    return Charge(obj);
}

Charge Charge::create(const QVariantMap &values)
{
    Charge model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Charge Charge::get(int chargeId)
{
    TSqlORMapper<ChargeObject> mapper;
    return Charge(mapper.findByPrimaryKey(chargeId));
}

int Charge::count()
{
    TSqlORMapper<ChargeObject> mapper;
    return mapper.findCount();
}

QList<Charge> Charge::getAll()
{
    return tfGetModelListByCriteria<Charge, ChargeObject>();
}

TModelObject *Charge::modelData()
{
    return d.data();
}

const TModelObject *Charge::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Charge &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Charge &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Charge)
