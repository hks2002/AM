#include <TreeFrogModel>
#include "actionuser.h"
#include "actionuserobject.h"
#include "actionapp.h"
#include "userapp.h"

ActionUser::ActionUser()
    : TAbstractModel(), d(new ActionUserObject())
{
    d->user_id = 0;
    d->action_id = 0;
}

ActionUser::ActionUser(const ActionUser &other)
    : TAbstractModel(), d(new ActionUserObject(*other.d))
{ }

ActionUser::ActionUser(const ActionUserObject &object)
    : TAbstractModel(), d(new ActionUserObject(object))
{ }

ActionUser::~ActionUser()
{
    // If the reference count becomes 0,
    // the shared data object 'ActionUserObject' is deleted.
}

int ActionUser::userId() const
{
    return d->user_id;
}

void ActionUser::setUserId(int userId)
{
    d->user_id = userId;
}

int ActionUser::actionId() const
{
    return d->action_id;
}

void ActionUser::setActionId(int actionId)
{
    d->action_id = actionId;
}

QDateTime ActionUser::createdAt() const
{
    return d->created_at;
}

QString ActionUser::createdBy() const
{
    return d->created_by;
}

void ActionUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ActionUser::updatedAt() const
{
    return d->updated_at;
}

QString ActionUser::updatedBy() const
{
    return d->updated_by;
}

void ActionUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

ActionApp ActionUser::actionAppByactionId() const
{
 return ActionApp::get(d->action_id);
}

UserApp ActionUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

ActionUser &ActionUser::operator=(const ActionUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ActionUser ActionUser::create(int userId, int actionId, const QString &createdBy, const QString &updatedBy)
{
    ActionUserObject obj;
    obj.user_id = userId;
    obj.action_id = actionId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ActionUser();
    }
    return ActionUser(obj);
}

ActionUser ActionUser::create(const QVariantMap &values)
{
    ActionUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ActionUser ActionUser::get(int userId, int actionId)
{
    TSqlORMapper<ActionUserObject> mapper;
    return ActionUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(userId)<<QVariant(actionId)));
}

int ActionUser::count()
{
    TSqlORMapper<ActionUserObject> mapper;
    return mapper.findCount();
}

QList<ActionUser> ActionUser::getAll()
{
    return tfGetModelListByCriteria<ActionUser, ActionUserObject>();
}

TModelObject *ActionUser::modelData()
{
    return d.data();
}

const TModelObject *ActionUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ActionUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ActionUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ActionUser)
