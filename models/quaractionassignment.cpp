#include <TreeFrogModel>
#include "quaractionassignment.h"
#include "quaractionassignmentobject.h"
#include "userapp.h"
#include "quarquar.h"
#include "quaraction.h"

QuarActionAssignment::QuarActionAssignment()
    : TAbstractModel(), d(new QuarActionAssignmentObject())
{
    d->quar_action_id = 0;
    d->quar_id = 0;
    d->user_id = 0;
}

QuarActionAssignment::QuarActionAssignment(const QuarActionAssignment &other)
    : TAbstractModel(), d(new QuarActionAssignmentObject(*other.d))
{ }

QuarActionAssignment::QuarActionAssignment(const QuarActionAssignmentObject &object)
    : TAbstractModel(), d(new QuarActionAssignmentObject(object))
{ }

QuarActionAssignment::~QuarActionAssignment()
{
    // If the reference count becomes 0,
    // the shared data object 'QuarActionAssignmentObject' is deleted.
}

int QuarActionAssignment::quarActionId() const
{
    return d->quar_action_id;
}

void QuarActionAssignment::setQuarActionId(int quarActionId)
{
    d->quar_action_id = quarActionId;
}

int QuarActionAssignment::quarId() const
{
    return d->quar_id;
}

void QuarActionAssignment::setQuarId(int quarId)
{
    d->quar_id = quarId;
}

bool QuarActionAssignment::assignedBool() const
{
    return d->assigned_bool;
}

void QuarActionAssignment::setAssignedBool(bool assignedBool)
{
    d->assigned_bool = assignedBool;
}

QDateTime QuarActionAssignment::assignedDt() const
{
    return d->assigned_dt;
}

void QuarActionAssignment::setAssignedDt(const QDateTime &assignedDt)
{
    d->assigned_dt = assignedDt;
}

int QuarActionAssignment::userId() const
{
    return d->user_id;
}

void QuarActionAssignment::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime QuarActionAssignment::createdAt() const
{
    return d->created_at;
}

QString QuarActionAssignment::createdBy() const
{
    return d->created_by;
}

void QuarActionAssignment::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime QuarActionAssignment::updatedAt() const
{
    return d->updated_at;
}

QString QuarActionAssignment::updatedBy() const
{
    return d->updated_by;
}

void QuarActionAssignment::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp QuarActionAssignment::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

QuarQuar QuarActionAssignment::quarQuarByquarId() const
{
 return QuarQuar::get(d->quar_id);
}

QuarAction QuarActionAssignment::quarActionByquarActionId() const
{
 return QuarAction::get(d->quar_action_id);
}

QuarActionAssignment &QuarActionAssignment::operator=(const QuarActionAssignment &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

QuarActionAssignment QuarActionAssignment::create(int quarActionId, int quarId, bool assignedBool, const QDateTime &assignedDt, int userId, const QString &createdBy, const QString &updatedBy)
{
    QuarActionAssignmentObject obj;
    obj.quar_action_id = quarActionId;
    obj.quar_id = quarId;
    obj.assigned_bool = assignedBool;
    obj.assigned_dt = assignedDt;
    obj.user_id = userId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return QuarActionAssignment();
    }
    return QuarActionAssignment(obj);
}

QuarActionAssignment QuarActionAssignment::create(const QVariantMap &values)
{
    QuarActionAssignment model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

QuarActionAssignment QuarActionAssignment::get(int quarActionId, int quarId)
{
    TSqlORMapper<QuarActionAssignmentObject> mapper;
    return QuarActionAssignment(mapper.findByPrimaryKey(QVariantList()<<QVariant(quarActionId)<<QVariant(quarId)));
}

int QuarActionAssignment::count()
{
    TSqlORMapper<QuarActionAssignmentObject> mapper;
    return mapper.findCount();
}

QList<QuarActionAssignment> QuarActionAssignment::getAll()
{
    return tfGetModelListByCriteria<QuarActionAssignment, QuarActionAssignmentObject>();
}

TModelObject *QuarActionAssignment::modelData()
{
    return d.data();
}

const TModelObject *QuarActionAssignment::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const QuarActionAssignment &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, QuarActionAssignment &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(QuarActionAssignment)
