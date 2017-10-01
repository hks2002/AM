#include <TreeFrogModel>
#include "schedwp.h"
#include "schedwpobject.h"
#include "userapp.h"
#include "refreceivecond.h"
#include "schedstask.h"

SchedWp::SchedWp()
    : TAbstractModel(), d(new SchedWpObject())
{
    d->sched_id = 0;
    d->sched_hr_mult_qt = 0;
    d->vendor_id = 0;
    d->ro_issued_by = 0;
}

SchedWp::SchedWp(const SchedWp &other)
    : TAbstractModel(), d(new SchedWpObject(*other.d))
{ }

SchedWp::SchedWp(const SchedWpObject &object)
    : TAbstractModel(), d(new SchedWpObject(object))
{ }

SchedWp::~SchedWp()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedWpObject' is deleted.
}

int SchedWp::schedId() const
{
    return d->sched_id;
}

void SchedWp::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

bool SchedWp::delayBool() const
{
    return d->delay_bool;
}

void SchedWp::setDelayBool(bool delayBool)
{
    d->delay_bool = delayBool;
}

bool SchedWp::enforceNsvBool() const
{
    return d->enforce_nsv_bool;
}

void SchedWp::setEnforceNsvBool(bool enforceNsvBool)
{
    d->enforce_nsv_bool = enforceNsvBool;
}

bool SchedWp::enforceWorkscopeBool() const
{
    return d->enforce_workscope_bool;
}

void SchedWp::setEnforceWorkscopeBool(bool enforceWorkscopeBool)
{
    d->enforce_workscope_bool = enforceWorkscopeBool;
}

bool SchedWp::collectionRequiredBool() const
{
    return d->collection_required_bool;
}

void SchedWp::setCollectionRequiredBool(bool collectionRequiredBool)
{
    d->collection_required_bool = collectionRequiredBool;
}

bool SchedWp::lrpBool() const
{
    return d->lrp_bool;
}

void SchedWp::setLrpBool(bool lrpBool)
{
    d->lrp_bool = lrpBool;
}

bool SchedWp::heavyBool() const
{
    return d->heavy_bool;
}

void SchedWp::setHeavyBool(bool heavyBool)
{
    d->heavy_bool = heavyBool;
}

bool SchedWp::initExpCostLockedBool() const
{
    return d->init_exp_cost_locked_bool;
}

void SchedWp::setInitExpCostLockedBool(bool initExpCostLockedBool)
{
    d->init_exp_cost_locked_bool = initExpCostLockedBool;
}

bool SchedWp::expCostLockedBool() const
{
    return d->exp_cost_locked_bool;
}

void SchedWp::setExpCostLockedBool(bool expCostLockedBool)
{
    d->exp_cost_locked_bool = expCostLockedBool;
}

bool SchedWp::actualCostLockedBool() const
{
    return d->actual_cost_locked_bool;
}

void SchedWp::setActualCostLockedBool(bool actualCostLockedBool)
{
    d->actual_cost_locked_bool = actualCostLockedBool;
}

bool SchedWp::adjustedBillingBool() const
{
    return d->adjusted_billing_bool;
}

void SchedWp::setAdjustedBillingBool(bool adjustedBillingBool)
{
    d->adjusted_billing_bool = adjustedBillingBool;
}

double SchedWp::schedHrMultQt() const
{
    return d->sched_hr_mult_qt;
}

void SchedWp::setSchedHrMultQt(double schedHrMultQt)
{
    d->sched_hr_mult_qt = schedHrMultQt;
}

int SchedWp::vendorId() const
{
    return d->vendor_id;
}

void SchedWp::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QString SchedWp::vendorWoRefDesc() const
{
    return d->vendor_wo_ref_desc;
}

void SchedWp::setVendorWoRefDesc(const QString &vendorWoRefDesc)
{
    d->vendor_wo_ref_desc = vendorWoRefDesc;
}

QString SchedWp::woRefDesc() const
{
    return d->wo_ref_desc;
}

void SchedWp::setWoRefDesc(const QString &woRefDesc)
{
    d->wo_ref_desc = woRefDesc;
}

QString SchedWp::releaseNumber() const
{
    return d->release_number;
}

void SchedWp::setReleaseNumber(const QString &releaseNumber)
{
    d->release_number = releaseNumber;
}

QString SchedWp::releaseRemarksDesc() const
{
    return d->release_remarks_desc;
}

void SchedWp::setReleaseRemarksDesc(const QString &releaseRemarksDesc)
{
    d->release_remarks_desc = releaseRemarksDesc;
}

QString SchedWp::receiveCondCd() const
{
    return d->receive_cond_cd;
}

void SchedWp::setReceiveCondCd(const QString &receiveCondCd)
{
    d->receive_cond_cd = receiveCondCd;
}

int SchedWp::roIssuedBy() const
{
    return d->ro_issued_by;
}

void SchedWp::setRoIssuedBy(int roIssuedBy)
{
    d->ro_issued_by = roIssuedBy;
}

QDateTime SchedWp::roIssuedDt() const
{
    return d->ro_issued_dt;
}

void SchedWp::setRoIssuedDt(const QDateTime &roIssuedDt)
{
    d->ro_issued_dt = roIssuedDt;
}

QDateTime SchedWp::createdAt() const
{
    return d->created_at;
}

QString SchedWp::createdBy() const
{
    return d->created_by;
}

void SchedWp::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedWp::updatedAt() const
{
    return d->updated_at;
}

QString SchedWp::updatedBy() const
{
    return d->updated_by;
}

void SchedWp::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedWp::userAppByroIssuedBy() const
{
 return UserApp::get(d->ro_issued_by);
}

RefReceiveCond SchedWp::refReceiveCondByreceiveCondCd() const
{
 return RefReceiveCond::get(d->receive_cond_cd);
}

SchedStask SchedWp::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedWp &SchedWp::operator=(const SchedWp &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedWp SchedWp::create(int schedId, bool delayBool, bool enforceNsvBool, bool enforceWorkscopeBool, bool collectionRequiredBool, bool lrpBool, bool heavyBool, bool initExpCostLockedBool, bool expCostLockedBool, bool actualCostLockedBool, bool adjustedBillingBool, double schedHrMultQt, int vendorId, const QString &vendorWoRefDesc, const QString &woRefDesc, const QString &releaseNumber, const QString &releaseRemarksDesc, const QString &receiveCondCd, int roIssuedBy, const QDateTime &roIssuedDt, const QString &createdBy, const QString &updatedBy)
{
    SchedWpObject obj;
    obj.sched_id = schedId;
    obj.delay_bool = delayBool;
    obj.enforce_nsv_bool = enforceNsvBool;
    obj.enforce_workscope_bool = enforceWorkscopeBool;
    obj.collection_required_bool = collectionRequiredBool;
    obj.lrp_bool = lrpBool;
    obj.heavy_bool = heavyBool;
    obj.init_exp_cost_locked_bool = initExpCostLockedBool;
    obj.exp_cost_locked_bool = expCostLockedBool;
    obj.actual_cost_locked_bool = actualCostLockedBool;
    obj.adjusted_billing_bool = adjustedBillingBool;
    obj.sched_hr_mult_qt = schedHrMultQt;
    obj.vendor_id = vendorId;
    obj.vendor_wo_ref_desc = vendorWoRefDesc;
    obj.wo_ref_desc = woRefDesc;
    obj.release_number = releaseNumber;
    obj.release_remarks_desc = releaseRemarksDesc;
    obj.receive_cond_cd = receiveCondCd;
    obj.ro_issued_by = roIssuedBy;
    obj.ro_issued_dt = roIssuedDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedWp();
    }
    return SchedWp(obj);
}

SchedWp SchedWp::create(const QVariantMap &values)
{
    SchedWp model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedWp SchedWp::get(int schedId)
{
    TSqlORMapper<SchedWpObject> mapper;
    return SchedWp(mapper.findByPrimaryKey(schedId));
}

int SchedWp::count()
{
    TSqlORMapper<SchedWpObject> mapper;
    return mapper.findCount();
}

QList<SchedWp> SchedWp::getAll()
{
    return tfGetModelListByCriteria<SchedWp, SchedWpObject>();
}

TModelObject *SchedWp::modelData()
{
    return d.data();
}

const TModelObject *SchedWp::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedWp &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedWp &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedWp)
