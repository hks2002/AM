#include <TreeFrogModel>
#include "actionapp.h"
#include "actionappobject.h"

ActionApp::ActionApp()
    : TAbstractModel(), d(new ActionAppObject())
{
    d->action_id = 0;
}

ActionApp::ActionApp(const ActionApp &other)
    : TAbstractModel(), d(new ActionAppObject(*other.d))
{ }

ActionApp::ActionApp(const ActionAppObject &object)
    : TAbstractModel(), d(new ActionAppObject(object))
{ }

ActionApp::~ActionApp()
{
    // If the reference count becomes 0,
    // the shared data object 'ActionAppObject' is deleted.
}

int ActionApp::actionId() const
{
    return d->action_id;
}

QString ActionApp::actionCd() const
{
    return d->action_cd;
}

void ActionApp::setActionCd(const QString &actionCd)
{
    d->action_cd = actionCd;
}

QString ActionApp::actionNameZh() const
{
    return d->action_name_zh;
}

void ActionApp::setActionNameZh(const QString &actionNameZh)
{
    d->action_name_zh = actionNameZh;
}

QString ActionApp::actionNameEn() const
{
    return d->action_name_en;
}

void ActionApp::setActionNameEn(const QString &actionNameEn)
{
    d->action_name_en = actionNameEn;
}

QString ActionApp::actionTooltip() const
{
    return d->action_tooltip;
}

void ActionApp::setActionTooltip(const QString &actionTooltip)
{
    d->action_tooltip = actionTooltip;
}

QString ActionApp::actionDesc() const
{
    return d->action_desc;
}

void ActionApp::setActionDesc(const QString &actionDesc)
{
    d->action_desc = actionDesc;
}

QString ActionApp::actionTypeZh() const
{
    return d->action_type_zh;
}

void ActionApp::setActionTypeZh(const QString &actionTypeZh)
{
    d->action_type_zh = actionTypeZh;
}

QString ActionApp::actionTypeEn() const
{
    return d->action_type_en;
}

void ActionApp::setActionTypeEn(const QString &actionTypeEn)
{
    d->action_type_en = actionTypeEn;
}

QString ActionApp::controller() const
{
    return d->controller;
}

void ActionApp::setController(const QString &controller)
{
    d->controller = controller;
}

QString ActionApp::action() const
{
    return d->action;
}

void ActionApp::setAction(const QString &action)
{
    d->action = action;
}

bool ActionApp::activeBool() const
{
    return d->active_bool;
}

void ActionApp::setActiveBool(bool activeBool)
{
    d->active_bool = activeBool;
}

QDateTime ActionApp::createdAt() const
{
    return d->created_at;
}

QString ActionApp::createdBy() const
{
    return d->created_by;
}

void ActionApp::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ActionApp::updatedAt() const
{
    return d->updated_at;
}

QString ActionApp::updatedBy() const
{
    return d->updated_by;
}

void ActionApp::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

ActionApp &ActionApp::operator=(const ActionApp &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ActionApp ActionApp::create(const QString &actionCd, const QString &actionNameZh, const QString &actionNameEn, const QString &actionTooltip, const QString &actionDesc, const QString &actionTypeZh, const QString &actionTypeEn, const QString &controller, const QString &action, bool activeBool, const QString &createdBy, const QString &updatedBy)
{
    ActionAppObject obj;
    obj.action_cd = actionCd;
    obj.action_name_zh = actionNameZh;
    obj.action_name_en = actionNameEn;
    obj.action_tooltip = actionTooltip;
    obj.action_desc = actionDesc;
    obj.action_type_zh = actionTypeZh;
    obj.action_type_en = actionTypeEn;
    obj.controller = controller;
    obj.action = action;
    obj.active_bool = activeBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ActionApp();
    }
    return ActionApp(obj);
}

ActionApp ActionApp::create(const QVariantMap &values)
{
    ActionApp model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ActionApp ActionApp::get(int actionId)
{
    TSqlORMapper<ActionAppObject> mapper;
    return ActionApp(mapper.findByPrimaryKey(actionId));
}

int ActionApp::count()
{
    TSqlORMapper<ActionAppObject> mapper;
    return mapper.findCount();
}

QList<ActionApp> ActionApp::getAll()
{
    return tfGetModelListByCriteria<ActionApp, ActionAppObject>();
}

TModelObject *ActionApp::modelData()
{
    return d.data();
}

const TModelObject *ActionApp::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ActionApp &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ActionApp &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ActionApp)
