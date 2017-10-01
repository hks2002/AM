#include <TreeFrogModel>
#include "schedsteplabour.h"
#include "schedsteplabourobject.h"
#include "userapp.h"
#include "reflabourroletype.h"
#include "schedstep.h"

SchedStepLabour::SchedStepLabour()
    : TAbstractModel(), d(new SchedStepLabourObject())
{
    d->step_id = 0;
    d->actual_by = 0;
}

SchedStepLabour::SchedStepLabour(const SchedStepLabour &other)
    : TAbstractModel(), d(new SchedStepLabourObject(*other.d))
{ }

SchedStepLabour::SchedStepLabour(const SchedStepLabourObject &object)
    : TAbstractModel(), d(new SchedStepLabourObject(object))
{ }

SchedStepLabour::~SchedStepLabour()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedStepLabourObject' is deleted.
}

int SchedStepLabour::stepId() const
{
    return d->step_id;
}

void SchedStepLabour::setStepId(int stepId)
{
    d->step_id = stepId;
}

QString SchedStepLabour::labourRoleTypeCd() const
{
    return d->labour_role_type_cd;
}

void SchedStepLabour::setLabourRoleTypeCd(const QString &labourRoleTypeCd)
{
    d->labour_role_type_cd = labourRoleTypeCd;
}

int SchedStepLabour::actualBy() const
{
    return d->actual_by;
}

void SchedStepLabour::setActualBy(int actualBy)
{
    d->actual_by = actualBy;
}

QDateTime SchedStepLabour::actualStartDt() const
{
    return d->actual_start_dt;
}

void SchedStepLabour::setActualStartDt(const QDateTime &actualStartDt)
{
    d->actual_start_dt = actualStartDt;
}

QDateTime SchedStepLabour::actualEndDt() const
{
    return d->actual_end_dt;
}

void SchedStepLabour::setActualEndDt(const QDateTime &actualEndDt)
{
    d->actual_end_dt = actualEndDt;
}

QDateTime SchedStepLabour::createdAt() const
{
    return d->created_at;
}

QString SchedStepLabour::createdBy() const
{
    return d->created_by;
}

void SchedStepLabour::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedStepLabour::updatedAt() const
{
    return d->updated_at;
}

QString SchedStepLabour::updatedBy() const
{
    return d->updated_by;
}

void SchedStepLabour::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedStepLabour::userAppByactualBy() const
{
 return UserApp::get(d->actual_by);
}

RefLabourRoleType SchedStepLabour::refLabourRoleTypeBylabourRoleTypeCd() const
{
 return RefLabourRoleType::get(d->labour_role_type_cd);
}

SchedStep SchedStepLabour::schedStepBystepId() const
{
 return SchedStep::get(d->step_id);
}

SchedStepLabour &SchedStepLabour::operator=(const SchedStepLabour &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedStepLabour SchedStepLabour::create(int stepId, const QString &labourRoleTypeCd, int actualBy, const QDateTime &actualStartDt, const QDateTime &actualEndDt, const QString &createdBy, const QString &updatedBy)
{
    SchedStepLabourObject obj;
    obj.step_id = stepId;
    obj.labour_role_type_cd = labourRoleTypeCd;
    obj.actual_by = actualBy;
    obj.actual_start_dt = actualStartDt;
    obj.actual_end_dt = actualEndDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedStepLabour();
    }
    return SchedStepLabour(obj);
}

SchedStepLabour SchedStepLabour::create(const QVariantMap &values)
{
    SchedStepLabour model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedStepLabour SchedStepLabour::get(int stepId, const QString &labourRoleTypeCd)
{
    TSqlORMapper<SchedStepLabourObject> mapper;
    return SchedStepLabour(mapper.findByPrimaryKey(QVariantList()<<QVariant(stepId)<<QVariant(labourRoleTypeCd)));
}

int SchedStepLabour::count()
{
    TSqlORMapper<SchedStepLabourObject> mapper;
    return mapper.findCount();
}

QList<SchedStepLabour> SchedStepLabour::getAll()
{
    return tfGetModelListByCriteria<SchedStepLabour, SchedStepLabourObject>();
}

TModelObject *SchedStepLabour::modelData()
{
    return d.data();
}

const TModelObject *SchedStepLabour::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedStepLabour &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedStepLabour &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedStepLabour)
