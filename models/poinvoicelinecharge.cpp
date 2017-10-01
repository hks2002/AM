#include <TreeFrogModel>
#include "poinvoicelinecharge.h"
#include "poinvoicelinechargeobject.h"
#include "charge.h"
#include "poinvoiceline.h"

PoInvoiceLineCharge::PoInvoiceLineCharge()
    : TAbstractModel(), d(new PoInvoiceLineChargeObject())
{
    d->po_invoice_line_id = 0;
    d->charge_id = 0;
    d->charge_amount = 0;
}

PoInvoiceLineCharge::PoInvoiceLineCharge(const PoInvoiceLineCharge &other)
    : TAbstractModel(), d(new PoInvoiceLineChargeObject(*other.d))
{ }

PoInvoiceLineCharge::PoInvoiceLineCharge(const PoInvoiceLineChargeObject &object)
    : TAbstractModel(), d(new PoInvoiceLineChargeObject(object))
{ }

PoInvoiceLineCharge::~PoInvoiceLineCharge()
{
    // If the reference count becomes 0,
    // the shared data object 'PoInvoiceLineChargeObject' is deleted.
}

int PoInvoiceLineCharge::poInvoiceLineId() const
{
    return d->po_invoice_line_id;
}

void PoInvoiceLineCharge::setPoInvoiceLineId(int poInvoiceLineId)
{
    d->po_invoice_line_id = poInvoiceLineId;
}

int PoInvoiceLineCharge::chargeId() const
{
    return d->charge_id;
}

void PoInvoiceLineCharge::setChargeId(int chargeId)
{
    d->charge_id = chargeId;
}

double PoInvoiceLineCharge::chargeAmount() const
{
    return d->charge_amount;
}

void PoInvoiceLineCharge::setChargeAmount(double chargeAmount)
{
    d->charge_amount = chargeAmount;
}

QDateTime PoInvoiceLineCharge::createdAt() const
{
    return d->created_at;
}

QString PoInvoiceLineCharge::createdBy() const
{
    return d->created_by;
}

void PoInvoiceLineCharge::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoInvoiceLineCharge::updatedAt() const
{
    return d->updated_at;
}

QString PoInvoiceLineCharge::updatedBy() const
{
    return d->updated_by;
}

void PoInvoiceLineCharge::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Charge PoInvoiceLineCharge::chargeBychargeId() const
{
 return Charge::get(d->charge_id);
}

PoInvoiceLine PoInvoiceLineCharge::poInvoiceLineBypoInvoiceLineId() const
{
 return PoInvoiceLine::get(d->po_invoice_line_id);
}

PoInvoiceLineCharge &PoInvoiceLineCharge::operator=(const PoInvoiceLineCharge &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoInvoiceLineCharge PoInvoiceLineCharge::create(int poInvoiceLineId, int chargeId, double chargeAmount, const QString &createdBy, const QString &updatedBy)
{
    PoInvoiceLineChargeObject obj;
    obj.po_invoice_line_id = poInvoiceLineId;
    obj.charge_id = chargeId;
    obj.charge_amount = chargeAmount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoInvoiceLineCharge();
    }
    return PoInvoiceLineCharge(obj);
}

PoInvoiceLineCharge PoInvoiceLineCharge::create(const QVariantMap &values)
{
    PoInvoiceLineCharge model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoInvoiceLineCharge PoInvoiceLineCharge::get(int poInvoiceLineId)
{
    TSqlORMapper<PoInvoiceLineChargeObject> mapper;
    return PoInvoiceLineCharge(mapper.findByPrimaryKey(poInvoiceLineId));
}

int PoInvoiceLineCharge::count()
{
    TSqlORMapper<PoInvoiceLineChargeObject> mapper;
    return mapper.findCount();
}

QList<PoInvoiceLineCharge> PoInvoiceLineCharge::getAll()
{
    return tfGetModelListByCriteria<PoInvoiceLineCharge, PoInvoiceLineChargeObject>();
}

TModelObject *PoInvoiceLineCharge::modelData()
{
    return d.data();
}

const TModelObject *PoInvoiceLineCharge::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoInvoiceLineCharge &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoInvoiceLineCharge &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoInvoiceLineCharge)
