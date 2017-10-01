#include <TreeFrogModel>
#include "qtyunit.h"
#include "qtyunitobject.h"

QtyUnit::QtyUnit()
    : TAbstractModel(), d(new QtyUnitObject())
{
    d->qty_unit_id = 0;
}

QtyUnit::QtyUnit(const QtyUnit &other)
    : TAbstractModel(), d(new QtyUnitObject(*other.d))
{ }

QtyUnit::QtyUnit(const QtyUnitObject &object)
    : TAbstractModel(), d(new QtyUnitObject(object))
{ }

QtyUnit::~QtyUnit()
{
    // If the reference count becomes 0,
    // the shared data object 'QtyUnitObject' is deleted.
}

int QtyUnit::qtyUnitId() const
{
    return d->qty_unit_id;
}

QString QtyUnit::qtyUnitCd() const
{
    return d->qty_unit_cd;
}

void QtyUnit::setQtyUnitCd(const QString &qtyUnitCd)
{
    d->qty_unit_cd = qtyUnitCd;
}

QString QtyUnit::qtyUnitNameZh() const
{
    return d->qty_unit_name_zh;
}

void QtyUnit::setQtyUnitNameZh(const QString &qtyUnitNameZh)
{
    d->qty_unit_name_zh = qtyUnitNameZh;
}

QString QtyUnit::qtyUnitNameEn() const
{
    return d->qty_unit_name_en;
}

void QtyUnit::setQtyUnitNameEn(const QString &qtyUnitNameEn)
{
    d->qty_unit_name_en = qtyUnitNameEn;
}

QDateTime QtyUnit::createdAt() const
{
    return d->created_at;
}

QString QtyUnit::createdBy() const
{
    return d->created_by;
}

void QtyUnit::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime QtyUnit::updatedAt() const
{
    return d->updated_at;
}

QString QtyUnit::updatedBy() const
{
    return d->updated_by;
}

void QtyUnit::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

QtyUnit &QtyUnit::operator=(const QtyUnit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

QtyUnit QtyUnit::create(const QString &qtyUnitCd, const QString &qtyUnitNameZh, const QString &qtyUnitNameEn, const QString &createdBy, const QString &updatedBy)
{
    QtyUnitObject obj;
    obj.qty_unit_cd = qtyUnitCd;
    obj.qty_unit_name_zh = qtyUnitNameZh;
    obj.qty_unit_name_en = qtyUnitNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return QtyUnit();
    }
    return QtyUnit(obj);
}

QtyUnit QtyUnit::create(const QVariantMap &values)
{
    QtyUnit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

QtyUnit QtyUnit::get(int qtyUnitId)
{
    TSqlORMapper<QtyUnitObject> mapper;
    return QtyUnit(mapper.findByPrimaryKey(qtyUnitId));
}

int QtyUnit::count()
{
    TSqlORMapper<QtyUnitObject> mapper;
    return mapper.findCount();
}

QList<QtyUnit> QtyUnit::getAll()
{
    return tfGetModelListByCriteria<QtyUnit, QtyUnitObject>();
}

TModelObject *QtyUnit::modelData()
{
    return d.data();
}

const TModelObject *QtyUnit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const QtyUnit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, QtyUnit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(QtyUnit)
