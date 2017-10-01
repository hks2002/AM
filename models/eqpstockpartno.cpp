#include <TreeFrogModel>
#include "eqpstockpartno.h"
#include "eqpstockpartnoobject.h"
#include "eqppartno.h"
#include "eqpstock.h"

EqpStockPartNo::EqpStockPartNo()
    : TAbstractModel(), d(new EqpStockPartNoObject())
{
    d->stock_id = 0;
    d->part_no_id = 0;
    d->part_no_pct = 0;
}

EqpStockPartNo::EqpStockPartNo(const EqpStockPartNo &other)
    : TAbstractModel(), d(new EqpStockPartNoObject(*other.d))
{ }

EqpStockPartNo::EqpStockPartNo(const EqpStockPartNoObject &object)
    : TAbstractModel(), d(new EqpStockPartNoObject(object))
{ }

EqpStockPartNo::~EqpStockPartNo()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpStockPartNoObject' is deleted.
}

int EqpStockPartNo::stockId() const
{
    return d->stock_id;
}

void EqpStockPartNo::setStockId(int stockId)
{
    d->stock_id = stockId;
}

int EqpStockPartNo::partNoId() const
{
    return d->part_no_id;
}

void EqpStockPartNo::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

double EqpStockPartNo::partNoPct() const
{
    return d->part_no_pct;
}

void EqpStockPartNo::setPartNoPct(double partNoPct)
{
    d->part_no_pct = partNoPct;
}

QDateTime EqpStockPartNo::createdAt() const
{
    return d->created_at;
}

QString EqpStockPartNo::createdBy() const
{
    return d->created_by;
}

void EqpStockPartNo::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpStockPartNo::updatedAt() const
{
    return d->updated_at;
}

QString EqpStockPartNo::updatedBy() const
{
    return d->updated_by;
}

void EqpStockPartNo::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EqpStockPartNo::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpStock EqpStockPartNo::eqpStockBystockId() const
{
 return EqpStock::get(d->stock_id);
}

EqpStockPartNo &EqpStockPartNo::operator=(const EqpStockPartNo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpStockPartNo EqpStockPartNo::create(int stockId, int partNoId, double partNoPct, const QString &createdBy, const QString &updatedBy)
{
    EqpStockPartNoObject obj;
    obj.stock_id = stockId;
    obj.part_no_id = partNoId;
    obj.part_no_pct = partNoPct;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpStockPartNo();
    }
    return EqpStockPartNo(obj);
}

EqpStockPartNo EqpStockPartNo::create(const QVariantMap &values)
{
    EqpStockPartNo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpStockPartNo EqpStockPartNo::get(int stockId, int partNoId)
{
    TSqlORMapper<EqpStockPartNoObject> mapper;
    return EqpStockPartNo(mapper.findByPrimaryKey(QVariantList()<<QVariant(stockId)<<QVariant(partNoId)));
}

int EqpStockPartNo::count()
{
    TSqlORMapper<EqpStockPartNoObject> mapper;
    return mapper.findCount();
}

QList<EqpStockPartNo> EqpStockPartNo::getAll()
{
    return tfGetModelListByCriteria<EqpStockPartNo, EqpStockPartNoObject>();
}

TModelObject *EqpStockPartNo::modelData()
{
    return d.data();
}

const TModelObject *EqpStockPartNo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpStockPartNo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpStockPartNo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpStockPartNo)
