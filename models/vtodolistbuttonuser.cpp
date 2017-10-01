#include <TreeFrogModel>
#include "vtodolistbuttonuser.h"
#include "vtodolistbuttonuserobject.h"

VTodoListButtonUser::VTodoListButtonUser()
    : TAbstractModel(), d(new VTodoListButtonUserObject())
{
    d->user_id = 0;
    d->todo_list_order = 0;
    d->todo_list_id = 0;
    d->button_id = 0;
    d->button_order = 0;
}

VTodoListButtonUser::VTodoListButtonUser(const VTodoListButtonUser &other)
    : TAbstractModel(), d(new VTodoListButtonUserObject(*other.d))
{ }

VTodoListButtonUser::VTodoListButtonUser(const VTodoListButtonUserObject &object)
    : TAbstractModel(), d(new VTodoListButtonUserObject(object))
{ }

VTodoListButtonUser::~VTodoListButtonUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VTodoListButtonUserObject' is deleted.
}

int VTodoListButtonUser::userId() const
{
    return d->user_id;
}

void VTodoListButtonUser::setUserId(int userId)
{
    d->user_id = userId;
}

int VTodoListButtonUser::todoListOrder() const
{
    return d->todo_list_order;
}

void VTodoListButtonUser::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VTodoListButtonUser::todoListId() const
{
    return d->todo_list_id;
}

void VTodoListButtonUser::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

QString VTodoListButtonUser::todoListCd() const
{
    return d->todo_list_cd;
}

void VTodoListButtonUser::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString VTodoListButtonUser::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void VTodoListButtonUser::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString VTodoListButtonUser::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void VTodoListButtonUser::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString VTodoListButtonUser::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void VTodoListButtonUser::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString VTodoListButtonUser::todoListDesc() const
{
    return d->todo_list_desc;
}

void VTodoListButtonUser::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

int VTodoListButtonUser::buttonId() const
{
    return d->button_id;
}

void VTodoListButtonUser::setButtonId(int buttonId)
{
    d->button_id = buttonId;
}

int VTodoListButtonUser::buttonOrder() const
{
    return d->button_order;
}

void VTodoListButtonUser::setButtonOrder(int buttonOrder)
{
    d->button_order = buttonOrder;
}

QString VTodoListButtonUser::buttonCd() const
{
    return d->button_cd;
}

void VTodoListButtonUser::setButtonCd(const QString &buttonCd)
{
    d->button_cd = buttonCd;
}

QString VTodoListButtonUser::buttonNameZh() const
{
    return d->button_name_zh;
}

void VTodoListButtonUser::setButtonNameZh(const QString &buttonNameZh)
{
    d->button_name_zh = buttonNameZh;
}

QString VTodoListButtonUser::buttonNameEn() const
{
    return d->button_name_en;
}

void VTodoListButtonUser::setButtonNameEn(const QString &buttonNameEn)
{
    d->button_name_en = buttonNameEn;
}

QString VTodoListButtonUser::buttonTooltip() const
{
    return d->button_tooltip;
}

void VTodoListButtonUser::setButtonTooltip(const QString &buttonTooltip)
{
    d->button_tooltip = buttonTooltip;
}

QString VTodoListButtonUser::buttonDesc() const
{
    return d->button_desc;
}

void VTodoListButtonUser::setButtonDesc(const QString &buttonDesc)
{
    d->button_desc = buttonDesc;
}

QString VTodoListButtonUser::controller() const
{
    return d->controller;
}

void VTodoListButtonUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTodoListButtonUser::action() const
{
    return d->action;
}

void VTodoListButtonUser::setAction(const QString &action)
{
    d->action = action;
}

VTodoListButtonUser &VTodoListButtonUser::operator=(const VTodoListButtonUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTodoListButtonUser VTodoListButtonUser::create(int userId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action)
{
    VTodoListButtonUserObject obj;
    obj.user_id = userId;
    obj.todo_list_order = todoListOrder;
    obj.todo_list_id = todoListId;
    obj.todo_list_cd = todoListCd;
    obj.todo_list_name_zh = todoListNameZh;
    obj.todo_list_name_en = todoListNameEn;
    obj.todo_list_tooltip = todoListTooltip;
    obj.todo_list_desc = todoListDesc;
    obj.button_id = buttonId;
    obj.button_order = buttonOrder;
    obj.button_cd = buttonCd;
    obj.button_name_zh = buttonNameZh;
    obj.button_name_en = buttonNameEn;
    obj.button_tooltip = buttonTooltip;
    obj.button_desc = buttonDesc;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VTodoListButtonUser();
    }
    return VTodoListButtonUser(obj);
}

VTodoListButtonUser VTodoListButtonUser::create(const QVariantMap &values)
{
    VTodoListButtonUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTodoListButtonUser VTodoListButtonUser::get(int userId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VTodoListButtonUserObject::UserId, userId);
    cri.add(VTodoListButtonUserObject::TodoListOrder, todoListOrder);
    cri.add(VTodoListButtonUserObject::TodoListId, todoListId);
    cri.add(VTodoListButtonUserObject::TodoListCd, todoListCd);
    cri.add(VTodoListButtonUserObject::TodoListNameZh, todoListNameZh);
    cri.add(VTodoListButtonUserObject::TodoListNameEn, todoListNameEn);
    cri.add(VTodoListButtonUserObject::TodoListTooltip, todoListTooltip);
    cri.add(VTodoListButtonUserObject::TodoListDesc, todoListDesc);
    cri.add(VTodoListButtonUserObject::ButtonId, buttonId);
    cri.add(VTodoListButtonUserObject::ButtonOrder, buttonOrder);
    cri.add(VTodoListButtonUserObject::ButtonCd, buttonCd);
    cri.add(VTodoListButtonUserObject::ButtonNameZh, buttonNameZh);
    cri.add(VTodoListButtonUserObject::ButtonNameEn, buttonNameEn);
    cri.add(VTodoListButtonUserObject::ButtonTooltip, buttonTooltip);
    cri.add(VTodoListButtonUserObject::ButtonDesc, buttonDesc);
    cri.add(VTodoListButtonUserObject::Controller, controller);
    cri.add(VTodoListButtonUserObject::Action, action);
    TSqlORMapper<VTodoListButtonUserObject> mapper;
    return VTodoListButtonUser(mapper.findFirst(cri));
}

int VTodoListButtonUser::count()
{
    TSqlORMapper<VTodoListButtonUserObject> mapper;
    return mapper.findCount();
}

QList<VTodoListButtonUser> VTodoListButtonUser::getAll()
{
    return tfGetModelListByCriteria<VTodoListButtonUser, VTodoListButtonUserObject>();
}

TModelObject *VTodoListButtonUser::modelData()
{
    return d.data();
}

const TModelObject *VTodoListButtonUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTodoListButtonUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTodoListButtonUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTodoListButtonUser)
