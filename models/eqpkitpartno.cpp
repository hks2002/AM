#include <TreeFrogModel>
#include "eqpkitpartno.h"
#include "eqpkitpartnoobject.h"
#include "eqppartno.h"

EqpKitPartNo::EqpKitPartNo()
    : TAbstractModel(), d(new EqpKitPartNoObject())
{
    d->kit_part_no_id = 0;
    d->part_no_id = 0;
    d->part_order = 0;
    d->qty = 0;
}

EqpKitPartNo::EqpKitPartNo(const EqpKitPartNo &other)
    : TAbstractModel(), d(new EqpKitPartNoObject(*other.d))
{ }

EqpKitPartNo::EqpKitPartNo(const EqpKitPartNoObject &object)
    : TAbstractModel(), d(new EqpKitPartNoObject(object))
{ }

EqpKitPartNo::~EqpKitPartNo()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpKitPartNoObject' is deleted.
}

int EqpKitPartNo::kitPartNoId() const
{
    return d->kit_part_no_id;
}

void EqpKitPartNo::setKitPartNoId(int kitPartNoId)
{
    d->kit_part_no_id = kitPartNoId;
}

int EqpKitPartNo::partNoId() const
{
    return d->part_no_id;
}

void EqpKitPartNo::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpKitPartNo::partOrder() const
{
    return d->part_order;
}

void EqpKitPartNo::setPartOrder(int partOrder)
{
    d->part_order = partOrder;
}

double EqpKitPartNo::qty() const
{
    return d->qty;
}

void EqpKitPartNo::setQty(double qty)
{
    d->qty = qty;
}

QDateTime EqpKitPartNo::createdAt() const
{
    return d->created_at;
}

QString EqpKitPartNo::createdBy() const
{
    return d->created_by;
}

void EqpKitPartNo::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpKitPartNo::updatedAt() const
{
    return d->updated_at;
}

QString EqpKitPartNo::updatedBy() const
{
    return d->updated_by;
}

void EqpKitPartNo::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo EqpKitPartNo::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpKitPartNo &EqpKitPartNo::operator=(const EqpKitPartNo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpKitPartNo EqpKitPartNo::create(int kitPartNoId, int partNoId, int partOrder, double qty, const QString &createdBy, const QString &updatedBy)
{
    EqpKitPartNoObject obj;
    obj.kit_part_no_id = kitPartNoId;
    obj.part_no_id = partNoId;
    obj.part_order = partOrder;
    obj.qty = qty;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpKitPartNo();
    }
    return EqpKitPartNo(obj);
}

EqpKitPartNo EqpKitPartNo::create(const QVariantMap &values)
{
    EqpKitPartNo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpKitPartNo EqpKitPartNo::get(int kitPartNoId, int partNoId)
{
    TSqlORMapper<EqpKitPartNoObject> mapper;
    return EqpKitPartNo(mapper.findByPrimaryKey(QVariantList()<<QVariant(kitPartNoId)<<QVariant(partNoId)));
}

int EqpKitPartNo::count()
{
    TSqlORMapper<EqpKitPartNoObject> mapper;
    return mapper.findCount();
}

QList<EqpKitPartNo> EqpKitPartNo::getAll()
{
    return tfGetModelListByCriteria<EqpKitPartNo, EqpKitPartNoObject>();
}

TModelObject *EqpKitPartNo::modelData()
{
    return d.data();
}

const TModelObject *EqpKitPartNo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpKitPartNo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpKitPartNo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpKitPartNo)
