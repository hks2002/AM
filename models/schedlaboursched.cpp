#include <TreeFrogModel>
#include "schedlaboursched.h"
#include "schedlabourschedobject.h"
#include "reflabourrolestatus.h"
#include "userapp.h"
#include "reflabourroletype.h"
#include "schedlabour.h"

SchedLabourSched::SchedLabourSched()
    : TAbstractModel(), d(new SchedLabourSchedObject())
{
    d->sched_labour_id = 0;
    d->sched_to = 0;
}

SchedLabourSched::SchedLabourSched(const SchedLabourSched &other)
    : TAbstractModel(), d(new SchedLabourSchedObject(*other.d))
{ }

SchedLabourSched::SchedLabourSched(const SchedLabourSchedObject &object)
    : TAbstractModel(), d(new SchedLabourSchedObject(object))
{ }

SchedLabourSched::~SchedLabourSched()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedLabourSchedObject' is deleted.
}

int SchedLabourSched::schedLabourId() const
{
    return d->sched_labour_id;
}

void SchedLabourSched::setSchedLabourId(int schedLabourId)
{
    d->sched_labour_id = schedLabourId;
}

QString SchedLabourSched::labourRoleTypeCd() const
{
    return d->labour_role_type_cd;
}

void SchedLabourSched::setLabourRoleTypeCd(const QString &labourRoleTypeCd)
{
    d->labour_role_type_cd = labourRoleTypeCd;
}

int SchedLabourSched::schedTo() const
{
    return d->sched_to;
}

void SchedLabourSched::setSchedTo(int schedTo)
{
    d->sched_to = schedTo;
}

QString SchedLabourSched::labourRoleStatusCd() const
{
    return d->labour_role_status_cd;
}

void SchedLabourSched::setLabourRoleStatusCd(const QString &labourRoleStatusCd)
{
    d->labour_role_status_cd = labourRoleStatusCd;
}

QDateTime SchedLabourSched::createdAt() const
{
    return d->created_at;
}

QString SchedLabourSched::createdBy() const
{
    return d->created_by;
}

void SchedLabourSched::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedLabourSched::updatedAt() const
{
    return d->updated_at;
}

QString SchedLabourSched::updatedBy() const
{
    return d->updated_by;
}

void SchedLabourSched::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLabourRoleStatus SchedLabourSched::refLabourRoleStatusBylabourRoleStatusCd() const
{
 return RefLabourRoleStatus::get(d->labour_role_status_cd);
}

UserApp SchedLabourSched::userAppByschedTo() const
{
 return UserApp::get(d->sched_to);
}

RefLabourRoleType SchedLabourSched::refLabourRoleTypeBylabourRoleTypeCd() const
{
 return RefLabourRoleType::get(d->labour_role_type_cd);
}

SchedLabour SchedLabourSched::schedLabourByschedLabourId() const
{
 return SchedLabour::get(d->sched_labour_id);
}

SchedLabourSched &SchedLabourSched::operator=(const SchedLabourSched &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedLabourSched SchedLabourSched::create(int schedLabourId, const QString &labourRoleTypeCd, int schedTo, const QString &labourRoleStatusCd, const QString &createdBy, const QString &updatedBy)
{
    SchedLabourSchedObject obj;
    obj.sched_labour_id = schedLabourId;
    obj.labour_role_type_cd = labourRoleTypeCd;
    obj.sched_to = schedTo;
    obj.labour_role_status_cd = labourRoleStatusCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedLabourSched();
    }
    return SchedLabourSched(obj);
}

SchedLabourSched SchedLabourSched::create(const QVariantMap &values)
{
    SchedLabourSched model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedLabourSched SchedLabourSched::get(int schedLabourId, const QString &labourRoleTypeCd)
{
    TSqlORMapper<SchedLabourSchedObject> mapper;
    return SchedLabourSched(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedLabourId)<<QVariant(labourRoleTypeCd)));
}

int SchedLabourSched::count()
{
    TSqlORMapper<SchedLabourSchedObject> mapper;
    return mapper.findCount();
}

QList<SchedLabourSched> SchedLabourSched::getAll()
{
    return tfGetModelListByCriteria<SchedLabourSched, SchedLabourSchedObject>();
}

TModelObject *SchedLabourSched::modelData()
{
    return d.data();
}

const TModelObject *SchedLabourSched::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedLabourSched &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedLabourSched &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedLabourSched)
