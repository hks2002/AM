#include <TreeFrogModel>
#include "polinecharge.h"
#include "polinechargeobject.h"
#include "charge.h"
#include "poline.h"

PoLineCharge::PoLineCharge()
    : TAbstractModel(), d(new PoLineChargeObject())
{
    d->po_line_id = 0;
    d->charge_id = 0;
    d->charge_amount = 0;
}

PoLineCharge::PoLineCharge(const PoLineCharge &other)
    : TAbstractModel(), d(new PoLineChargeObject(*other.d))
{ }

PoLineCharge::PoLineCharge(const PoLineChargeObject &object)
    : TAbstractModel(), d(new PoLineChargeObject(object))
{ }

PoLineCharge::~PoLineCharge()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineChargeObject' is deleted.
}

int PoLineCharge::poLineId() const
{
    return d->po_line_id;
}

void PoLineCharge::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoLineCharge::chargeId() const
{
    return d->charge_id;
}

void PoLineCharge::setChargeId(int chargeId)
{
    d->charge_id = chargeId;
}

double PoLineCharge::chargeAmount() const
{
    return d->charge_amount;
}

void PoLineCharge::setChargeAmount(double chargeAmount)
{
    d->charge_amount = chargeAmount;
}

QDateTime PoLineCharge::createdAt() const
{
    return d->created_at;
}

QString PoLineCharge::createdBy() const
{
    return d->created_by;
}

void PoLineCharge::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLineCharge::updatedAt() const
{
    return d->updated_at;
}

QString PoLineCharge::updatedBy() const
{
    return d->updated_by;
}

void PoLineCharge::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Charge PoLineCharge::chargeBychargeId() const
{
 return Charge::get(d->charge_id);
}

PoLine PoLineCharge::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoLineCharge &PoLineCharge::operator=(const PoLineCharge &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLineCharge PoLineCharge::create(int poLineId, int chargeId, double chargeAmount, const QString &createdBy, const QString &updatedBy)
{
    PoLineChargeObject obj;
    obj.po_line_id = poLineId;
    obj.charge_id = chargeId;
    obj.charge_amount = chargeAmount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLineCharge();
    }
    return PoLineCharge(obj);
}

PoLineCharge PoLineCharge::create(const QVariantMap &values)
{
    PoLineCharge model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLineCharge PoLineCharge::get(int poLineId)
{
    TSqlORMapper<PoLineChargeObject> mapper;
    return PoLineCharge(mapper.findByPrimaryKey(poLineId));
}

int PoLineCharge::count()
{
    TSqlORMapper<PoLineChargeObject> mapper;
    return mapper.findCount();
}

QList<PoLineCharge> PoLineCharge::getAll()
{
    return tfGetModelListByCriteria<PoLineCharge, PoLineChargeObject>();
}

TModelObject *PoLineCharge::modelData()
{
    return d.data();
}

const TModelObject *PoLineCharge::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLineCharge &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLineCharge &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLineCharge)
