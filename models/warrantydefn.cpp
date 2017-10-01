#include <TreeFrogModel>
#include "warrantydefn.h"
#include "warrantydefnobject.h"
#include "vendor.h"
#include "refwarrantypriority.h"
#include "refwarrantystatus.h"

WarrantyDefn::WarrantyDefn()
    : TAbstractModel(), d(new WarrantyDefnObject())
{
    d->warranty_defn_id = 0;
    d->vendor_id = 0;
    d->unit_price_threshold_qt = 0;
    d->turn_in_price_threshold_qt = 0;
    d->duration_qt = 0;
    d->hours_qt = 0;
    d->cycles_qt = 0;
}

WarrantyDefn::WarrantyDefn(const WarrantyDefn &other)
    : TAbstractModel(), d(new WarrantyDefnObject(*other.d))
{ }

WarrantyDefn::WarrantyDefn(const WarrantyDefnObject &object)
    : TAbstractModel(), d(new WarrantyDefnObject(object))
{ }

WarrantyDefn::~WarrantyDefn()
{
    // If the reference count becomes 0,
    // the shared data object 'WarrantyDefnObject' is deleted.
}

int WarrantyDefn::warrantyDefnId() const
{
    return d->warranty_defn_id;
}

QString WarrantyDefn::warrantyCd() const
{
    return d->warranty_cd;
}

void WarrantyDefn::setWarrantyCd(const QString &warrantyCd)
{
    d->warranty_cd = warrantyCd;
}

QString WarrantyDefn::warrantyStatusCd() const
{
    return d->warranty_status_cd;
}

void WarrantyDefn::setWarrantyStatusCd(const QString &warrantyStatusCd)
{
    d->warranty_status_cd = warrantyStatusCd;
}

QString WarrantyDefn::priorityCd() const
{
    return d->priority_cd;
}

void WarrantyDefn::setPriorityCd(const QString &priorityCd)
{
    d->priority_cd = priorityCd;
}

int WarrantyDefn::vendorId() const
{
    return d->vendor_id;
}

void WarrantyDefn::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QString WarrantyDefn::warrantyDesc() const
{
    return d->warranty_desc;
}

void WarrantyDefn::setWarrantyDesc(const QString &warrantyDesc)
{
    d->warranty_desc = warrantyDesc;
}

QString WarrantyDefn::summaryDesc() const
{
    return d->summary_desc;
}

void WarrantyDefn::setSummaryDesc(const QString &summaryDesc)
{
    d->summary_desc = summaryDesc;
}

QDateTime WarrantyDefn::expireDt() const
{
    return d->expire_dt;
}

void WarrantyDefn::setExpireDt(const QDateTime &expireDt)
{
    d->expire_dt = expireDt;
}

bool WarrantyDefn::expiresFirstBool() const
{
    return d->expires_first_bool;
}

void WarrantyDefn::setExpiresFirstBool(bool expiresFirstBool)
{
    d->expires_first_bool = expiresFirstBool;
}

bool WarrantyDefn::routineBool() const
{
    return d->routine_bool;
}

void WarrantyDefn::setRoutineBool(bool routineBool)
{
    d->routine_bool = routineBool;
}

bool WarrantyDefn::labourBool() const
{
    return d->labour_bool;
}

void WarrantyDefn::setLabourBool(bool labourBool)
{
    d->labour_bool = labourBool;
}

bool WarrantyDefn::origEqpOnlyBool() const
{
    return d->orig_eqp_only_bool;
}

void WarrantyDefn::setOrigEqpOnlyBool(bool origEqpOnlyBool)
{
    d->orig_eqp_only_bool = origEqpOnlyBool;
}

double WarrantyDefn::unitPriceThresholdQt() const
{
    return d->unit_price_threshold_qt;
}

void WarrantyDefn::setUnitPriceThresholdQt(double unitPriceThresholdQt)
{
    d->unit_price_threshold_qt = unitPriceThresholdQt;
}

double WarrantyDefn::turnInPriceThresholdQt() const
{
    return d->turn_in_price_threshold_qt;
}

void WarrantyDefn::setTurnInPriceThresholdQt(double turnInPriceThresholdQt)
{
    d->turn_in_price_threshold_qt = turnInPriceThresholdQt;
}

int WarrantyDefn::durationQt() const
{
    return d->duration_qt;
}

void WarrantyDefn::setDurationQt(int durationQt)
{
    d->duration_qt = durationQt;
}

double WarrantyDefn::hoursQt() const
{
    return d->hours_qt;
}

void WarrantyDefn::setHoursQt(double hoursQt)
{
    d->hours_qt = hoursQt;
}

int WarrantyDefn::cyclesQt() const
{
    return d->cycles_qt;
}

void WarrantyDefn::setCyclesQt(int cyclesQt)
{
    d->cycles_qt = cyclesQt;
}

QDateTime WarrantyDefn::createdAt() const
{
    return d->created_at;
}

QString WarrantyDefn::createdBy() const
{
    return d->created_by;
}

void WarrantyDefn::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime WarrantyDefn::updatedAt() const
{
    return d->updated_at;
}

QString WarrantyDefn::updatedBy() const
{
    return d->updated_by;
}

void WarrantyDefn::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor WarrantyDefn::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

RefWarrantyPriority WarrantyDefn::refWarrantyPriorityBypriorityCd() const
{
 return RefWarrantyPriority::get(d->priority_cd);
}

RefWarrantyStatus WarrantyDefn::refWarrantyStatusBywarrantyStatusCd() const
{
 return RefWarrantyStatus::get(d->warranty_status_cd);
}

WarrantyDefn &WarrantyDefn::operator=(const WarrantyDefn &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

WarrantyDefn WarrantyDefn::create(const QString &warrantyCd, const QString &warrantyStatusCd, const QString &priorityCd, int vendorId, const QString &warrantyDesc, const QString &summaryDesc, const QDateTime &expireDt, bool expiresFirstBool, bool routineBool, bool labourBool, bool origEqpOnlyBool, double unitPriceThresholdQt, double turnInPriceThresholdQt, int durationQt, double hoursQt, int cyclesQt, const QString &createdBy, const QString &updatedBy)
{
    WarrantyDefnObject obj;
    obj.warranty_cd = warrantyCd;
    obj.warranty_status_cd = warrantyStatusCd;
    obj.priority_cd = priorityCd;
    obj.vendor_id = vendorId;
    obj.warranty_desc = warrantyDesc;
    obj.summary_desc = summaryDesc;
    obj.expire_dt = expireDt;
    obj.expires_first_bool = expiresFirstBool;
    obj.routine_bool = routineBool;
    obj.labour_bool = labourBool;
    obj.orig_eqp_only_bool = origEqpOnlyBool;
    obj.unit_price_threshold_qt = unitPriceThresholdQt;
    obj.turn_in_price_threshold_qt = turnInPriceThresholdQt;
    obj.duration_qt = durationQt;
    obj.hours_qt = hoursQt;
    obj.cycles_qt = cyclesQt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return WarrantyDefn();
    }
    return WarrantyDefn(obj);
}

WarrantyDefn WarrantyDefn::create(const QVariantMap &values)
{
    WarrantyDefn model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

WarrantyDefn WarrantyDefn::get(int warrantyDefnId)
{
    TSqlORMapper<WarrantyDefnObject> mapper;
    return WarrantyDefn(mapper.findByPrimaryKey(warrantyDefnId));
}

int WarrantyDefn::count()
{
    TSqlORMapper<WarrantyDefnObject> mapper;
    return mapper.findCount();
}

QList<WarrantyDefn> WarrantyDefn::getAll()
{
    return tfGetModelListByCriteria<WarrantyDefn, WarrantyDefnObject>();
}

TModelObject *WarrantyDefn::modelData()
{
    return d.data();
}

const TModelObject *WarrantyDefn::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const WarrantyDefn &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, WarrantyDefn &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(WarrantyDefn)
