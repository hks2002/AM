#include <TreeFrogModel>
#include "quaraction.h"
#include "quaractionobject.h"
#include "userapp.h"
#include "quarquar.h"

QuarAction::QuarAction()
    : TAbstractModel(), d(new QuarActionObject())
{
    d->quar_action_id = 0;
    d->quar_id = 0;
    d->quar_action_seq = 0;
    d->user_id = 0;
}

QuarAction::QuarAction(const QuarAction &other)
    : TAbstractModel(), d(new QuarActionObject(*other.d))
{ }

QuarAction::QuarAction(const QuarActionObject &object)
    : TAbstractModel(), d(new QuarActionObject(object))
{ }

QuarAction::~QuarAction()
{
    // If the reference count becomes 0,
    // the shared data object 'QuarActionObject' is deleted.
}

int QuarAction::quarActionId() const
{
    return d->quar_action_id;
}

int QuarAction::quarId() const
{
    return d->quar_id;
}

void QuarAction::setQuarId(int quarId)
{
    d->quar_id = quarId;
}

QString QuarAction::actionDesc() const
{
    return d->action_desc;
}

void QuarAction::setActionDesc(const QString &actionDesc)
{
    d->action_desc = actionDesc;
}

QString QuarAction::actionNote() const
{
    return d->action_note;
}

void QuarAction::setActionNote(const QString &actionNote)
{
    d->action_note = actionNote;
}

bool QuarAction::quarActionOpenBool() const
{
    return d->quar_action_open_bool;
}

void QuarAction::setQuarActionOpenBool(bool quarActionOpenBool)
{
    d->quar_action_open_bool = quarActionOpenBool;
}

QString QuarAction::discrepancyDesc() const
{
    return d->discrepancy_desc;
}

void QuarAction::setDiscrepancyDesc(const QString &discrepancyDesc)
{
    d->discrepancy_desc = discrepancyDesc;
}

int QuarAction::quarActionSeq() const
{
    return d->quar_action_seq;
}

void QuarAction::setQuarActionSeq(int quarActionSeq)
{
    d->quar_action_seq = quarActionSeq;
}

int QuarAction::userId() const
{
    return d->user_id;
}

void QuarAction::setUserId(int userId)
{
    d->user_id = userId;
}

QDateTime QuarAction::createdAt() const
{
    return d->created_at;
}

QString QuarAction::createdBy() const
{
    return d->created_by;
}

void QuarAction::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime QuarAction::updatedAt() const
{
    return d->updated_at;
}

QString QuarAction::updatedBy() const
{
    return d->updated_by;
}

void QuarAction::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp QuarAction::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

QuarQuar QuarAction::quarQuarByquarId() const
{
 return QuarQuar::get(d->quar_id);
}

QuarAction &QuarAction::operator=(const QuarAction &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

QuarAction QuarAction::create(int quarId, const QString &actionDesc, const QString &actionNote, bool quarActionOpenBool, const QString &discrepancyDesc, int quarActionSeq, int userId, const QString &createdBy, const QString &updatedBy)
{
    QuarActionObject obj;
    obj.quar_id = quarId;
    obj.action_desc = actionDesc;
    obj.action_note = actionNote;
    obj.quar_action_open_bool = quarActionOpenBool;
    obj.discrepancy_desc = discrepancyDesc;
    obj.quar_action_seq = quarActionSeq;
    obj.user_id = userId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return QuarAction();
    }
    return QuarAction(obj);
}

QuarAction QuarAction::create(const QVariantMap &values)
{
    QuarAction model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

QuarAction QuarAction::get(int quarActionId)
{
    TSqlORMapper<QuarActionObject> mapper;
    return QuarAction(mapper.findByPrimaryKey(quarActionId));
}

int QuarAction::count()
{
    TSqlORMapper<QuarActionObject> mapper;
    return mapper.findCount();
}

QList<QuarAction> QuarAction::getAll()
{
    return tfGetModelListByCriteria<QuarAction, QuarActionObject>();
}

TModelObject *QuarAction::modelData()
{
    return d.data();
}

const TModelObject *QuarAction::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const QuarAction &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, QuarAction &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(QuarAction)
