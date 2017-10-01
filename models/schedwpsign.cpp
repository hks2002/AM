#include <TreeFrogModel>
#include "schedwpsign.h"
#include "schedwpsignobject.h"
#include "userapp.h"
#include "schedwp.h"

SchedWpSign::SchedWpSign()
    : TAbstractModel(), d(new SchedWpSignObject())
{
    d->sched_wp_sign_id = 0;
    d->sched_id = 0;
    d->signed_by = 0;
}

SchedWpSign::SchedWpSign(const SchedWpSign &other)
    : TAbstractModel(), d(new SchedWpSignObject(*other.d))
{ }

SchedWpSign::SchedWpSign(const SchedWpSignObject &object)
    : TAbstractModel(), d(new SchedWpSignObject(object))
{ }

SchedWpSign::~SchedWpSign()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedWpSignObject' is deleted.
}

int SchedWpSign::schedWpSignId() const
{
    return d->sched_wp_sign_id;
}

int SchedWpSign::schedId() const
{
    return d->sched_id;
}

void SchedWpSign::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

bool SchedWpSign::signedBool() const
{
    return d->signed_bool;
}

void SchedWpSign::setSignedBool(bool signedBool)
{
    d->signed_bool = signedBool;
}

int SchedWpSign::signedBy() const
{
    return d->signed_by;
}

void SchedWpSign::setSignedBy(int signedBy)
{
    d->signed_by = signedBy;
}

QDateTime SchedWpSign::signoffDt() const
{
    return d->signoff_dt;
}

void SchedWpSign::setSignoffDt(const QDateTime &signoffDt)
{
    d->signoff_dt = signoffDt;
}

QDateTime SchedWpSign::createdAt() const
{
    return d->created_at;
}

QString SchedWpSign::createdBy() const
{
    return d->created_by;
}

void SchedWpSign::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedWpSign::updatedAt() const
{
    return d->updated_at;
}

QString SchedWpSign::updatedBy() const
{
    return d->updated_by;
}

void SchedWpSign::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedWpSign::userAppBysignedBy() const
{
 return UserApp::get(d->signed_by);
}

SchedWp SchedWpSign::schedWpByschedId() const
{
 return SchedWp::get(d->sched_id);
}

SchedWpSign &SchedWpSign::operator=(const SchedWpSign &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedWpSign SchedWpSign::create(int schedId, bool signedBool, int signedBy, const QDateTime &signoffDt, const QString &createdBy, const QString &updatedBy)
{
    SchedWpSignObject obj;
    obj.sched_id = schedId;
    obj.signed_bool = signedBool;
    obj.signed_by = signedBy;
    obj.signoff_dt = signoffDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedWpSign();
    }
    return SchedWpSign(obj);
}

SchedWpSign SchedWpSign::create(const QVariantMap &values)
{
    SchedWpSign model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedWpSign SchedWpSign::get(int schedWpSignId)
{
    TSqlORMapper<SchedWpSignObject> mapper;
    return SchedWpSign(mapper.findByPrimaryKey(schedWpSignId));
}

int SchedWpSign::count()
{
    TSqlORMapper<SchedWpSignObject> mapper;
    return mapper.findCount();
}

QList<SchedWpSign> SchedWpSign::getAll()
{
    return tfGetModelListByCriteria<SchedWpSign, SchedWpSignObject>();
}

TModelObject *SchedWpSign::modelData()
{
    return d.data();
}

const TModelObject *SchedWpSign::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedWpSign &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedWpSign &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedWpSign)
