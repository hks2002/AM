#include <TreeFrogModel>
#include "eqppartnovendorrep.h"
#include "eqppartnovendorrepobject.h"
#include "vendor.h"
#include "eqppartno.h"

EqpPartNoVendorRep::EqpPartNoVendorRep()
    : TAbstractModel(), d(new EqpPartNoVendorRepObject())
{
    d->part_no_id = 0;
    d->vendor_id = 0;
    d->repair_cost = 0;
}

EqpPartNoVendorRep::EqpPartNoVendorRep(const EqpPartNoVendorRep &other)
    : TAbstractModel(), d(new EqpPartNoVendorRepObject(*other.d))
{ }

EqpPartNoVendorRep::EqpPartNoVendorRep(const EqpPartNoVendorRepObject &object)
    : TAbstractModel(), d(new EqpPartNoVendorRepObject(object))
{ }

EqpPartNoVendorRep::~EqpPartNoVendorRep()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoVendorRepObject' is deleted.
}

int EqpPartNoVendorRep::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoVendorRep::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoVendorRep::vendorId() const
{
    return d->vendor_id;
}

void EqpPartNoVendorRep::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

double EqpPartNoVendorRep::repairCost() const
{
    return d->repair_cost;
}

void EqpPartNoVendorRep::setRepairCost(double repairCost)
{
    d->repair_cost = repairCost;
}

QString EqpPartNoVendorRep::leadTime() const
{
    return d->lead_time;
}

void EqpPartNoVendorRep::setLeadTime(const QString &leadTime)
{
    d->lead_time = leadTime;
}

bool EqpPartNoVendorRep::prefBool() const
{
    return d->pref_bool;
}

void EqpPartNoVendorRep::setPrefBool(bool prefBool)
{
    d->pref_bool = prefBool;
}

QDateTime EqpPartNoVendorRep::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoVendorRep::createdBy() const
{
    return d->created_by;
}

void EqpPartNoVendorRep::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoVendorRep::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoVendorRep::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoVendorRep::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor EqpPartNoVendorRep::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

EqpPartNo EqpPartNoVendorRep::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoVendorRep &EqpPartNoVendorRep::operator=(const EqpPartNoVendorRep &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoVendorRep EqpPartNoVendorRep::create(int partNoId, int vendorId, double repairCost, const QString &leadTime, bool prefBool, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoVendorRepObject obj;
    obj.part_no_id = partNoId;
    obj.vendor_id = vendorId;
    obj.repair_cost = repairCost;
    obj.lead_time = leadTime;
    obj.pref_bool = prefBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoVendorRep();
    }
    return EqpPartNoVendorRep(obj);
}

EqpPartNoVendorRep EqpPartNoVendorRep::create(const QVariantMap &values)
{
    EqpPartNoVendorRep model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoVendorRep EqpPartNoVendorRep::get(int partNoId, int vendorId)
{
    TSqlORMapper<EqpPartNoVendorRepObject> mapper;
    return EqpPartNoVendorRep(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(vendorId)));
}

int EqpPartNoVendorRep::count()
{
    TSqlORMapper<EqpPartNoVendorRepObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoVendorRep> EqpPartNoVendorRep::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoVendorRep, EqpPartNoVendorRepObject>();
}

TModelObject *EqpPartNoVendorRep::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoVendorRep::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorRep &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorRep &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoVendorRep)
