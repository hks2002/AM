#include <TreeFrogModel>
#include "eqppartnovendorexchg.h"
#include "eqppartnovendorexchgobject.h"
#include "vendor.h"
#include "eqppartno.h"

EqpPartNoVendorExchg::EqpPartNoVendorExchg()
    : TAbstractModel(), d(new EqpPartNoVendorExchgObject())
{
    d->part_no_id = 0;
    d->vendor_id = 0;
    d->base_price = 0;
    d->exchg_cost = 0;
}

EqpPartNoVendorExchg::EqpPartNoVendorExchg(const EqpPartNoVendorExchg &other)
    : TAbstractModel(), d(new EqpPartNoVendorExchgObject(*other.d))
{ }

EqpPartNoVendorExchg::EqpPartNoVendorExchg(const EqpPartNoVendorExchgObject &object)
    : TAbstractModel(), d(new EqpPartNoVendorExchgObject(object))
{ }

EqpPartNoVendorExchg::~EqpPartNoVendorExchg()
{
    // If the reference count becomes 0,
    // the shared data object 'EqpPartNoVendorExchgObject' is deleted.
}

int EqpPartNoVendorExchg::partNoId() const
{
    return d->part_no_id;
}

void EqpPartNoVendorExchg::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EqpPartNoVendorExchg::vendorId() const
{
    return d->vendor_id;
}

void EqpPartNoVendorExchg::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

double EqpPartNoVendorExchg::basePrice() const
{
    return d->base_price;
}

void EqpPartNoVendorExchg::setBasePrice(double basePrice)
{
    d->base_price = basePrice;
}

double EqpPartNoVendorExchg::exchgCost() const
{
    return d->exchg_cost;
}

void EqpPartNoVendorExchg::setExchgCost(double exchgCost)
{
    d->exchg_cost = exchgCost;
}

QString EqpPartNoVendorExchg::leadTime() const
{
    return d->lead_time;
}

void EqpPartNoVendorExchg::setLeadTime(const QString &leadTime)
{
    d->lead_time = leadTime;
}

bool EqpPartNoVendorExchg::prefBool() const
{
    return d->pref_bool;
}

void EqpPartNoVendorExchg::setPrefBool(bool prefBool)
{
    d->pref_bool = prefBool;
}

QDateTime EqpPartNoVendorExchg::returnTime() const
{
    return d->return_time;
}

void EqpPartNoVendorExchg::setReturnTime(const QDateTime &returnTime)
{
    d->return_time = returnTime;
}

QDateTime EqpPartNoVendorExchg::createdAt() const
{
    return d->created_at;
}

QString EqpPartNoVendorExchg::createdBy() const
{
    return d->created_by;
}

void EqpPartNoVendorExchg::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EqpPartNoVendorExchg::updatedAt() const
{
    return d->updated_at;
}

QString EqpPartNoVendorExchg::updatedBy() const
{
    return d->updated_by;
}

void EqpPartNoVendorExchg::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor EqpPartNoVendorExchg::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

EqpPartNo EqpPartNoVendorExchg::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpPartNoVendorExchg &EqpPartNoVendorExchg::operator=(const EqpPartNoVendorExchg &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EqpPartNoVendorExchg EqpPartNoVendorExchg::create(int partNoId, int vendorId, double basePrice, double exchgCost, const QString &leadTime, bool prefBool, const QDateTime &returnTime, const QString &createdBy, const QString &updatedBy)
{
    EqpPartNoVendorExchgObject obj;
    obj.part_no_id = partNoId;
    obj.vendor_id = vendorId;
    obj.base_price = basePrice;
    obj.exchg_cost = exchgCost;
    obj.lead_time = leadTime;
    obj.pref_bool = prefBool;
    obj.return_time = returnTime;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EqpPartNoVendorExchg();
    }
    return EqpPartNoVendorExchg(obj);
}

EqpPartNoVendorExchg EqpPartNoVendorExchg::create(const QVariantMap &values)
{
    EqpPartNoVendorExchg model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EqpPartNoVendorExchg EqpPartNoVendorExchg::get(int partNoId, int vendorId)
{
    TSqlORMapper<EqpPartNoVendorExchgObject> mapper;
    return EqpPartNoVendorExchg(mapper.findByPrimaryKey(QVariantList()<<QVariant(partNoId)<<QVariant(vendorId)));
}

int EqpPartNoVendorExchg::count()
{
    TSqlORMapper<EqpPartNoVendorExchgObject> mapper;
    return mapper.findCount();
}

QList<EqpPartNoVendorExchg> EqpPartNoVendorExchg::getAll()
{
    return tfGetModelListByCriteria<EqpPartNoVendorExchg, EqpPartNoVendorExchgObject>();
}

TModelObject *EqpPartNoVendorExchg::modelData()
{
    return d.data();
}

const TModelObject *EqpPartNoVendorExchg::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorExchg &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorExchg &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EqpPartNoVendorExchg)
