#include <TreeFrogModel>
#include "locshoprepair.h"
#include "locshoprepairobject.h"
#include "eqppartno.h"
#include "loc.h"

LocShopRepair::LocShopRepair()
    : TAbstractModel(), d(new LocShopRepairObject())
{
    d->loc_id = 0;
    d->part_no_id = 0;
}

LocShopRepair::LocShopRepair(const LocShopRepair &other)
    : TAbstractModel(), d(new LocShopRepairObject(*other.d))
{ }

LocShopRepair::LocShopRepair(const LocShopRepairObject &object)
    : TAbstractModel(), d(new LocShopRepairObject(object))
{ }

LocShopRepair::~LocShopRepair()
{
    // If the reference count becomes 0,
    // the shared data object 'LocShopRepairObject' is deleted.
}

int LocShopRepair::locId() const
{
    return d->loc_id;
}

void LocShopRepair::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocShopRepair::partNoId() const
{
    return d->part_no_id;
}

void LocShopRepair::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QDateTime LocShopRepair::createdAt() const
{
    return d->created_at;
}

QString LocShopRepair::createdBy() const
{
    return d->created_by;
}

void LocShopRepair::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocShopRepair::updatedAt() const
{
    return d->updated_at;
}

QString LocShopRepair::updatedBy() const
{
    return d->updated_by;
}

void LocShopRepair::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

EqpPartNo LocShopRepair::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

Loc LocShopRepair::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocShopRepair &LocShopRepair::operator=(const LocShopRepair &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocShopRepair LocShopRepair::create(int locId, int partNoId, const QString &createdBy, const QString &updatedBy)
{
    LocShopRepairObject obj;
    obj.loc_id = locId;
    obj.part_no_id = partNoId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocShopRepair();
    }
    return LocShopRepair(obj);
}

LocShopRepair LocShopRepair::create(const QVariantMap &values)
{
    LocShopRepair model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocShopRepair LocShopRepair::get(int locId, int partNoId)
{
    TSqlORMapper<LocShopRepairObject> mapper;
    return LocShopRepair(mapper.findByPrimaryKey(QVariantList()<<QVariant(locId)<<QVariant(partNoId)));
}

int LocShopRepair::count()
{
    TSqlORMapper<LocShopRepairObject> mapper;
    return mapper.findCount();
}

QList<LocShopRepair> LocShopRepair::getAll()
{
    return tfGetModelListByCriteria<LocShopRepair, LocShopRepairObject>();
}

TModelObject *LocShopRepair::modelData()
{
    return d.data();
}

const TModelObject *LocShopRepair::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocShopRepair &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocShopRepair &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocShopRepair)
