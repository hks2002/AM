#include <TreeFrogModel>
#include "eqpstock.h"
#include "eqpstockobject.h"
#include "qtyunit.h"

EqpStock::EqpStock()
    : TAbstractModel(), d(new EqpStockObject())
{
    d->stock_id = 0;
    d->qty_unit_id = 0;
    d->monthly_demand_qt = 0;
    d->safety_level_qt = 0;
    d->max_mult_qt = 0;
    d->default_reorder_qt = 0;
    d->default_ship_qt = 0;
}

EqpStock::EqpStock(const EqpStock &other)
    : TAbstractModel(), d(new EqpStockObject(*other.d))
{ }

EqpStock::EqpStock(const EqpStockObject &object)
    : TAbstractModel(), d(new EqpStockObject(object))
{ }

EqpStock::~EqpStock()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpStockObject' is deleted.
}

int EqpStock::stockId() const
{
    return d->stock_id;
}

QString EqpStock::stockNoCd() const
{
    return d->stock_no_cd;
}

void EqpStock::setStockNoCd(const QString &stockNoCd)
{
    d->stock_no_cd = stockNoCd;
}

QString EqpStock::stockNoName() const
{
    return d->stock_no_name;
}

void EqpStock::setStockNoName(const QString &stockNoName)
{
    d->stock_no_name = stockNoName;
}

int EqpStock::qtyUnitId() const
{
    return d->qty_unit_id;
}

void EqpStock::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

int EqpStock::monthlyDemandQt() const
{
    return d->monthly_demand_qt;
}

void EqpStock::setMonthlyDemandQt(int monthlyDemandQt)
{
    d->monthly_demand_qt = monthlyDemandQt;
}

int EqpStock::safetyLevelQt() const
{
    return d->safety_level_qt;
}

void EqpStock::setSafetyLevelQt(int safetyLevelQt)
{
    d->safety_level_qt = safetyLevelQt;
}

int EqpStock::maxMultQt() const
{
    return d->max_mult_qt;
}

void EqpStock::setMaxMultQt(int maxMultQt)
{
    d->max_mult_qt = maxMultQt;
}

int EqpStock::defaultReorderQt() const
{
    return d->default_reorder_qt;
}

void EqpStock::setDefaultReorderQt(int defaultReorderQt)
{
    d->default_reorder_qt = defaultReorderQt;
}

int EqpStock::defaultShipQt() const
{
    return d->default_ship_qt;
}

void EqpStock::setDefaultShipQt(int defaultShipQt)
{
    d->default_ship_qt = defaultShipQt;
}

QDateTime EqpStock::createdAt() const
{
    return d->created_at;
}

QString EqpStock::createdBy() const
{
    return d->created_by;
}

void EqpStock::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpStock::updatedAt() const
{
    return d->updated_at;
}

QString EqpStock::updatedBy() const
{
    return d->updated_by;
}

void EqpStock::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

QtyUnit EqpStock::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

EqpStock &EqpStock::operator=(const EqpStock &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpStock EqpStock::create(const QString &stockNoCd, const QString &stockNoName, int qtyUnitId, int monthlyDemandQt, int safetyLevelQt, int maxMultQt, int defaultReorderQt, int defaultShipQt, const QString &createdBy, const QString &updatedBy)
{
    EqpStockObject obj;
    obj.stock_no_cd = stockNoCd;
    obj.stock_no_name = stockNoName;
    obj.qty_unit_id = qtyUnitId;
    obj.monthly_demand_qt = monthlyDemandQt;
    obj.safety_level_qt = safetyLevelQt;
    obj.max_mult_qt = maxMultQt;
    obj.default_reorder_qt = defaultReorderQt;
    obj.default_ship_qt = defaultShipQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpStock();
    }
    return EqpStock(obj);
}

EqpStock EqpStock::create(const QVariantMap &values)
{
    EqpStock model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpStock EqpStock::get(int stockId)
{
    TSqlORMapper<EqpStockObject> mapper;
    return EqpStock(mapper.findByPrimaryKey(stockId));
}

int EqpStock::count()
{
    TSqlORMapper<EqpStockObject> mapper;
    return mapper.findCount();
}

QList<EqpStock> EqpStock::getAll()
{
    return tfGetModelListByCriteria<EqpStock, EqpStockObject>();
}

TModelObject *EqpStock::modelData()
{
    return d.data();
}

const TModelObject *EqpStock::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpStock &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpStock &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpStock)
