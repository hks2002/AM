#include <TreeFrogModel>
#include "vbuttonuser.h"
#include "vbuttonuserobject.h"

VButtonUser::VButtonUser()
    : TAbstractModel(), d(new VButtonUserObject())
{
    d->button_id = 0;
    d->user_id = 0;
    d->todo_list_order = 0;
    d->button_order = 0;
}

VButtonUser::VButtonUser(const VButtonUser &other)
    : TAbstractModel(), d(new VButtonUserObject(*other.d))
{ }

VButtonUser::VButtonUser(const VButtonUserObject &object)
    : TAbstractModel(), d(new VButtonUserObject(object))
{ }

VButtonUser::~VButtonUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VButtonUserObject' is deleted.
}

int VButtonUser::buttonId() const
{
    return d->button_id;
}

void VButtonUser::setButtonId(int buttonId)
{
    d->button_id = buttonId;
}

QString VButtonUser::buttonCd() const
{
    return d->button_cd;
}

void VButtonUser::setButtonCd(const QString &buttonCd)
{
    d->button_cd = buttonCd;
}

QString VButtonUser::buttonNameZh() const
{
    return d->button_name_zh;
}

void VButtonUser::setButtonNameZh(const QString &buttonNameZh)
{
    d->button_name_zh = buttonNameZh;
}

QString VButtonUser::buttonNameEn() const
{
    return d->button_name_en;
}

void VButtonUser::setButtonNameEn(const QString &buttonNameEn)
{
    d->button_name_en = buttonNameEn;
}

QString VButtonUser::buttonTooltip() const
{
    return d->button_tooltip;
}

void VButtonUser::setButtonTooltip(const QString &buttonTooltip)
{
    d->button_tooltip = buttonTooltip;
}

QString VButtonUser::buttonDesc() const
{
    return d->button_desc;
}

void VButtonUser::setButtonDesc(const QString &buttonDesc)
{
    d->button_desc = buttonDesc;
}

QString VButtonUser::controller() const
{
    return d->controller;
}

void VButtonUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VButtonUser::action() const
{
    return d->action;
}

void VButtonUser::setAction(const QString &action)
{
    d->action = action;
}

int VButtonUser::userId() const
{
    return d->user_id;
}

void VButtonUser::setUserId(int userId)
{
    d->user_id = userId;
}

int VButtonUser::todoListOrder() const
{
    return d->todo_list_order;
}

void VButtonUser::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VButtonUser::buttonOrder() const
{
    return d->button_order;
}

void VButtonUser::setButtonOrder(int buttonOrder)
{
    d->button_order = buttonOrder;
}

VButtonUser &VButtonUser::operator=(const VButtonUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VButtonUser VButtonUser::create(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int buttonOrder)
{
    VButtonUserObject obj;
    obj.button_id = buttonId;
    obj.button_cd = buttonCd;
    obj.button_name_zh = buttonNameZh;
    obj.button_name_en = buttonNameEn;
    obj.button_tooltip = buttonTooltip;
    obj.button_desc = buttonDesc;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    obj.todo_list_order = todoListOrder;
    obj.button_order = buttonOrder;
    if (!obj.create()) {
        return VButtonUser();
    }
    return VButtonUser(obj);
}

VButtonUser VButtonUser::create(const QVariantMap &values)
{
    VButtonUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VButtonUser VButtonUser::get(int buttonId, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int buttonOrder)
{
    TCriteria cri;
    cri.add(VButtonUserObject::ButtonId, buttonId);
    cri.add(VButtonUserObject::ButtonCd, buttonCd);
    cri.add(VButtonUserObject::ButtonNameZh, buttonNameZh);
    cri.add(VButtonUserObject::ButtonNameEn, buttonNameEn);
    cri.add(VButtonUserObject::ButtonTooltip, buttonTooltip);
    cri.add(VButtonUserObject::ButtonDesc, buttonDesc);
    cri.add(VButtonUserObject::Controller, controller);
    cri.add(VButtonUserObject::Action, action);
    cri.add(VButtonUserObject::UserId, userId);
    cri.add(VButtonUserObject::TodoListOrder, todoListOrder);
    cri.add(VButtonUserObject::ButtonOrder, buttonOrder);
    TSqlORMapper<VButtonUserObject> mapper;
    return VButtonUser(mapper.findFirst(cri));
}

int VButtonUser::count()
{
    TSqlORMapper<VButtonUserObject> mapper;
    return mapper.findCount();
}

QList<VButtonUser> VButtonUser::getAll()
{
    return tfGetModelListByCriteria<VButtonUser, VButtonUserObject>(TCriteria());
}

TModelObject *VButtonUser::modelData()
{
    return d.data();
}

const TModelObject *VButtonUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VButtonUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VButtonUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VButtonUser)
