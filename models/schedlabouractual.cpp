#include <TreeFrogModel>
#include "schedlabouractual.h"
#include "schedlabouractualobject.h"
#include "userapp.h"
#include "reflabourroletype.h"
#include "schedlabour.h"

SchedLabourActual::SchedLabourActual()
    : TAbstractModel(), d(new SchedLabourActualObject())
{
    d->sched_labour_id = 0;
    d->actual_by = 0;
    d->adjusted_billing_hr = 0;
    d->labour_cost = 0;
}

SchedLabourActual::SchedLabourActual(const SchedLabourActual &other)
    : TAbstractModel(), d(new SchedLabourActualObject(*other.d))
{ }

SchedLabourActual::SchedLabourActual(const SchedLabourActualObject &object)
    : TAbstractModel(), d(new SchedLabourActualObject(object))
{ }

SchedLabourActual::~SchedLabourActual()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedLabourActualObject' is deleted.
}

int SchedLabourActual::schedLabourId() const
{
    return d->sched_labour_id;
}

void SchedLabourActual::setSchedLabourId(int schedLabourId)
{
    d->sched_labour_id = schedLabourId;
}

QString SchedLabourActual::labourRoleTypeCd() const
{
    return d->labour_role_type_cd;
}

void SchedLabourActual::setLabourRoleTypeCd(const QString &labourRoleTypeCd)
{
    d->labour_role_type_cd = labourRoleTypeCd;
}

int SchedLabourActual::actualBy() const
{
    return d->actual_by;
}

void SchedLabourActual::setActualBy(int actualBy)
{
    d->actual_by = actualBy;
}

double SchedLabourActual::adjustedBillingHr() const
{
    return d->adjusted_billing_hr;
}

void SchedLabourActual::setAdjustedBillingHr(double adjustedBillingHr)
{
    d->adjusted_billing_hr = adjustedBillingHr;
}

QString SchedLabourActual::labourTimeCd() const
{
    return d->labour_time_cd;
}

void SchedLabourActual::setLabourTimeCd(const QString &labourTimeCd)
{
    d->labour_time_cd = labourTimeCd;
}

double SchedLabourActual::labourCost() const
{
    return d->labour_cost;
}

void SchedLabourActual::setLabourCost(double labourCost)
{
    d->labour_cost = labourCost;
}

QDateTime SchedLabourActual::actualStartDt() const
{
    return d->actual_start_dt;
}

void SchedLabourActual::setActualStartDt(const QDateTime &actualStartDt)
{
    d->actual_start_dt = actualStartDt;
}

QDateTime SchedLabourActual::actualEndDt() const
{
    return d->actual_end_dt;
}

void SchedLabourActual::setActualEndDt(const QDateTime &actualEndDt)
{
    d->actual_end_dt = actualEndDt;
}

QDateTime SchedLabourActual::createdAt() const
{
    return d->created_at;
}

QString SchedLabourActual::createdBy() const
{
    return d->created_by;
}

void SchedLabourActual::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedLabourActual::updatedAt() const
{
    return d->updated_at;
}

QString SchedLabourActual::updatedBy() const
{
    return d->updated_by;
}

void SchedLabourActual::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedLabourActual::userAppByactualBy() const
{
 return UserApp::get(d->actual_by);
}

RefLabourRoleType SchedLabourActual::refLabourRoleTypeBylabourRoleTypeCd() const
{
 return RefLabourRoleType::get(d->labour_role_type_cd);
}

SchedLabour SchedLabourActual::schedLabourByschedLabourId() const
{
 return SchedLabour::get(d->sched_labour_id);
}

SchedLabourActual &SchedLabourActual::operator=(const SchedLabourActual &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedLabourActual SchedLabourActual::create(int schedLabourId, const QString &labourRoleTypeCd, int actualBy, double adjustedBillingHr, const QString &labourTimeCd, double labourCost, const QDateTime &actualStartDt, const QDateTime &actualEndDt, const QString &createdBy, const QString &updatedBy)
{
    SchedLabourActualObject obj;
    obj.sched_labour_id = schedLabourId;
    obj.labour_role_type_cd = labourRoleTypeCd;
    obj.actual_by = actualBy;
    obj.adjusted_billing_hr = adjustedBillingHr;
    obj.labour_time_cd = labourTimeCd;
    obj.labour_cost = labourCost;
    obj.actual_start_dt = actualStartDt;
    obj.actual_end_dt = actualEndDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedLabourActual();
    }
    return SchedLabourActual(obj);
}

SchedLabourActual SchedLabourActual::create(const QVariantMap &values)
{
    SchedLabourActual model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedLabourActual SchedLabourActual::get(int schedLabourId, const QString &labourRoleTypeCd)
{
    TSqlORMapper<SchedLabourActualObject> mapper;
    return SchedLabourActual(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedLabourId)<<QVariant(labourRoleTypeCd)));
}

int SchedLabourActual::count()
{
    TSqlORMapper<SchedLabourActualObject> mapper;
    return mapper.findCount();
}

QList<SchedLabourActual> SchedLabourActual::getAll()
{
    return tfGetModelListByCriteria<SchedLabourActual, SchedLabourActualObject>();
}

TModelObject *SchedLabourActual::modelData()
{
    return d.data();
}

const TModelObject *SchedLabourActual::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedLabourActual &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedLabourActual &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedLabourActual)
