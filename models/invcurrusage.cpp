#include <TreeFrogModel>
#include "invcurrusage.h"
#include "invcurrusageobject.h"
#include "refengunit.h"
#include "invinv.h"

InvCurrUsage::InvCurrUsage()
    : TAbstractModel(), d(new InvCurrUsageObject())
{
    d->inv_no_id = 0;
    d->tsi_qt = 0;
    d->tsn_qt = 0;
    d->tso_qt = 0;
}

InvCurrUsage::InvCurrUsage(const InvCurrUsage &other)
    : TAbstractModel(), d(new InvCurrUsageObject(*other.d))
{ }

InvCurrUsage::InvCurrUsage(const InvCurrUsageObject &object)
    : TAbstractModel(), d(new InvCurrUsageObject(object))
{ }

InvCurrUsage::~InvCurrUsage()
{
    // If the reference count becomes 0,
    // the shared data object 'InvCurrUsageObject' is deleted.
}

int InvCurrUsage::invNoId() const
{
    return d->inv_no_id;
}

void InvCurrUsage::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QString InvCurrUsage::engUnitCd() const
{
    return d->eng_unit_cd;
}

void InvCurrUsage::setEngUnitCd(const QString &engUnitCd)
{
    d->eng_unit_cd = engUnitCd;
}

double InvCurrUsage::tsiQt() const
{
    return d->tsi_qt;
}

void InvCurrUsage::setTsiQt(double tsiQt)
{
    d->tsi_qt = tsiQt;
}

double InvCurrUsage::tsnQt() const
{
    return d->tsn_qt;
}

void InvCurrUsage::setTsnQt(double tsnQt)
{
    d->tsn_qt = tsnQt;
}

double InvCurrUsage::tsoQt() const
{
    return d->tso_qt;
}

void InvCurrUsage::setTsoQt(double tsoQt)
{
    d->tso_qt = tsoQt;
}

QDateTime InvCurrUsage::createdAt() const
{
    return d->created_at;
}

QString InvCurrUsage::createdBy() const
{
    return d->created_by;
}

void InvCurrUsage::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime InvCurrUsage::updatedAt() const
{
    return d->updated_at;
}

QString InvCurrUsage::updatedBy() const
{
    return d->updated_by;
}

void InvCurrUsage::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefEngUnit InvCurrUsage::refEngUnitByengUnitCd() const
{
 return RefEngUnit::get(d->eng_unit_cd);
}

InvInv InvCurrUsage::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

InvCurrUsage &InvCurrUsage::operator=(const InvCurrUsage &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

InvCurrUsage InvCurrUsage::create(int invNoId, const QString &engUnitCd, double tsiQt, double tsnQt, double tsoQt, const QString &createdBy, const QString &updatedBy)
{
    InvCurrUsageObject obj;
    obj.inv_no_id = invNoId;
    obj.eng_unit_cd = engUnitCd;
    obj.tsi_qt = tsiQt;
    obj.tsn_qt = tsnQt;
    obj.tso_qt = tsoQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return InvCurrUsage();
    }
    return InvCurrUsage(obj);
}

InvCurrUsage InvCurrUsage::create(const QVariantMap &values)
{
    InvCurrUsage model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

InvCurrUsage InvCurrUsage::get(int invNoId, const QString &engUnitCd)
{
    TSqlORMapper<InvCurrUsageObject> mapper;
    return InvCurrUsage(mapper.findByPrimaryKey(QVariantList()<<QVariant(invNoId)<<QVariant(engUnitCd)));
}

int InvCurrUsage::count()
{
    TSqlORMapper<InvCurrUsageObject> mapper;
    return mapper.findCount();
}

QList<InvCurrUsage> InvCurrUsage::getAll()
{
    return tfGetModelListByCriteria<InvCurrUsage, InvCurrUsageObject>();
}

TModelObject *InvCurrUsage::modelData()
{
    return d.data();
}

const TModelObject *InvCurrUsage::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const InvCurrUsage &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, InvCurrUsage &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(InvCurrUsage)
