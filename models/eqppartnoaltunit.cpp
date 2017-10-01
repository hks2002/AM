#include <TreeFrogModel>
#include "eqppartnoaltunit.h"
#include "eqppartnoaltunitobject.h"
#include "qtyunit.h"
#include "eqppartno.h"

EqpPartNoAltUnit::EqpPartNoAltUnit()
    : TAbstractModel(), d(new EqpPartNoAltUnitObject())
{
    d->part_no_id = 0;
    d->qty_unit_id = 0;
    d->alt_unit_id = 0;
    d->qty_convert_qt = 0;
}

EqpPartNoAltUnit::EqpPartNoAltUnit(const EqpPartNoAltUnit &other)
    : TAbstractModel(), d(new EqpPartNoAltUnitObject(*other.d))
{ }

EqpPartNoAltUnit::EqpPartNoAltUnit(const EqpPartNoAltUnitObject &object)
    : TAbstractModel(), d(new EqpPartNoAltUnitObject(object))
{ }

EqpPartNoAltUnit::~EqpPartNoAltUnit()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoAltUnitObject' is deleted.
}

int EqpPartNoAltUnit::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoAltUnit::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoAltUnit::qtyUnitId() const
{
    return d->qty_unit_id;
}

void EqpPartNoAltUnit::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

int EqpPartNoAltUnit::altUnitId() const
{
    return d->alt_unit_id;
}

void EqpPartNoAltUnit::setAltUnitId(int altUnitId)
{
    d->alt_unit_id = altUnitId;
}

double EqpPartNoAltUnit::qtyConvertQt() const
{
    return d->qty_convert_qt;
}

void EqpPartNoAltUnit::setQtyConvertQt(double qtyConvertQt)
{
    d->qty_convert_qt = qtyConvertQt;
}

QDateTime EqpPartNoAltUnit::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoAltUnit::createdBy() const
{
    return d->created_by;
}

void EqpPartNoAltUnit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoAltUnit::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoAltUnit::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoAltUnit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

QtyUnit EqpPartNoAltUnit::qtyUnitByaltUnitId() const
{
 return QtyUnit::get(d->alt_unit_id);
}

EqpPartNo EqpPartNoAltUnit::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoAltUnit &EqpPartNoAltUnit::operator=(const EqpPartNoAltUnit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoAltUnit EqpPartNoAltUnit::create(int partNoId, int qtyUnitId, int altUnitId, double qtyConvertQt, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoAltUnitObject obj;
    obj.part_no_id = partNoId;
    obj.qty_unit_id = qtyUnitId;
    obj.alt_unit_id = altUnitId;
    obj.qty_convert_qt = qtyConvertQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoAltUnit();
    }
    return EqpPartNoAltUnit(obj);
}

EqpPartNoAltUnit EqpPartNoAltUnit::create(const QVariantMap &values)
{
    EqpPartNoAltUnit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoAltUnit EqpPartNoAltUnit::get(int partNoId, int qtyUnitId, int altUnitId)
{
    TSqlORMapper<EqpPartNoAltUnitObject> mapper;
    return EqpPartNoAltUnit(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(qtyUnitId)<<QVariant(altUnitId)));
}

int EqpPartNoAltUnit::count()
{
    TSqlORMapper<EqpPartNoAltUnitObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoAltUnit> EqpPartNoAltUnit::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoAltUnit, EqpPartNoAltUnitObject>();
}

TModelObject *EqpPartNoAltUnit::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoAltUnit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoAltUnit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoAltUnit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoAltUnit)
