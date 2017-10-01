#include <TreeFrogModel>
#include "polinetax.h"
#include "polinetaxobject.h"
#include "tax.h"
#include "poline.h"

PoLineTax::PoLineTax()
    : TAbstractModel(), d(new PoLineTaxObject())
{
    d->po_line_id = 0;
    d->tax_id = 0;
    d->tax_amount = 0;
}

PoLineTax::PoLineTax(const PoLineTax &other)
    : TAbstractModel(), d(new PoLineTaxObject(*other.d))
{ }

PoLineTax::PoLineTax(const PoLineTaxObject &object)
    : TAbstractModel(), d(new PoLineTaxObject(object))
{ }

PoLineTax::~PoLineTax()
{
    // If the reference count becomes 0,
    // the shared data object 'PoLineTaxObject' is deleted.
}

int PoLineTax::poLineId() const
{
    return d->po_line_id;
}

void PoLineTax::setPoLineId(int poLineId)
{
    d->po_line_id = poLineId;
}

int PoLineTax::taxId() const
{
    return d->tax_id;
}

void PoLineTax::setTaxId(int taxId)
{
    d->tax_id = taxId;
}

double PoLineTax::taxAmount() const
{
    return d->tax_amount;
}

void PoLineTax::setTaxAmount(double taxAmount)
{
    d->tax_amount = taxAmount;
}

QDateTime PoLineTax::createdAt() const
{
    return d->created_at;
}

QString PoLineTax::createdBy() const
{
    return d->created_by;
}

void PoLineTax::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime PoLineTax::updatedAt() const
{
    return d->updated_at;
}

QString PoLineTax::updatedBy() const
{
    return d->updated_by;
}

void PoLineTax::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Tax PoLineTax::taxBytaxId() const
{
 return Tax::get(d->tax_id);
}

PoLine PoLineTax::poLineBypoLineId() const
{
 return PoLine::get(d->po_line_id);
}

PoLineTax &PoLineTax::operator=(const PoLineTax &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PoLineTax PoLineTax::create(int poLineId, int taxId, double taxAmount, const QString &createdBy, const QString &updatedBy)
{
    PoLineTaxObject obj;
    obj.po_line_id = poLineId;
    obj.tax_id = taxId;
    obj.tax_amount = taxAmount;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return PoLineTax();
    }
    return PoLineTax(obj);
}

PoLineTax PoLineTax::create(const QVariantMap &values)
{
    PoLineTax model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PoLineTax PoLineTax::get(int poLineId)
{
    TSqlORMapper<PoLineTaxObject> mapper;
    return PoLineTax(mapper.findByPrimaryKey(poLineId));
}

int PoLineTax::count()
{
    TSqlORMapper<PoLineTaxObject> mapper;
    return mapper.findCount();
}

QList<PoLineTax> PoLineTax::getAll()
{
    return tfGetModelListByCriteria<PoLineTax, PoLineTaxObject>();
}

TModelObject *PoLineTax::modelData()
{
    return d.data();
}

const TModelObject *PoLineTax::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PoLineTax &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PoLineTax &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PoLineTax)
