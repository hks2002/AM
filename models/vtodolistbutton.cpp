#include <TreeFrogModel>
#include "vtodolistbutton.h"
#include "vtodolistbuttonobject.h"

VTodoListButton::VTodoListButton()
    : TAbstractModel(), d(new VTodoListButtonObject())
{
    d->todo_list_id = 0;
    d->button_id = 0;
    d->button_order = 0;
}

VTodoListButton::VTodoListButton(const VTodoListButton &other)
    : TAbstractModel(), d(new VTodoListButtonObject(*other.d))
{ }

VTodoListButton::VTodoListButton(const VTodoListButtonObject &object)
    : TAbstractModel(), d(new VTodoListButtonObject(object))
{ }

VTodoListButton::~VTodoListButton()
{
    // If the reference count becomes 0,
    // the shared data object 'VTodoListButtonObject' is deleted.
}

int VTodoListButton::todoListId() const
{
    return d->todo_list_id;
}

void VTodoListButton::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

QString VTodoListButton::todoListCd() const
{
    return d->todo_list_cd;
}

void VTodoListButton::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString VTodoListButton::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void VTodoListButton::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString VTodoListButton::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void VTodoListButton::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString VTodoListButton::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void VTodoListButton::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString VTodoListButton::todoListDesc() const
{
    return d->todo_list_desc;
}

void VTodoListButton::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

int VTodoListButton::buttonId() const
{
    return d->button_id;
}

void VTodoListButton::setButtonId(int buttonId)
{
    d->button_id = buttonId;
}

int VTodoListButton::buttonOrder() const
{
    return d->button_order;
}

void VTodoListButton::setButtonOrder(int buttonOrder)
{
    d->button_order = buttonOrder;
}

QString VTodoListButton::buttonCd() const
{
    return d->button_cd;
}

void VTodoListButton::setButtonCd(const QString &buttonCd)
{
    d->button_cd = buttonCd;
}

QString VTodoListButton::buttonNameZh() const
{
    return d->button_name_zh;
}

void VTodoListButton::setButtonNameZh(const QString &buttonNameZh)
{
    d->button_name_zh = buttonNameZh;
}

QString VTodoListButton::buttonNameEn() const
{
    return d->button_name_en;
}

void VTodoListButton::setButtonNameEn(const QString &buttonNameEn)
{
    d->button_name_en = buttonNameEn;
}

QString VTodoListButton::buttonTooltip() const
{
    return d->button_tooltip;
}

void VTodoListButton::setButtonTooltip(const QString &buttonTooltip)
{
    d->button_tooltip = buttonTooltip;
}

QString VTodoListButton::buttonDesc() const
{
    return d->button_desc;
}

void VTodoListButton::setButtonDesc(const QString &buttonDesc)
{
    d->button_desc = buttonDesc;
}

QString VTodoListButton::controller() const
{
    return d->controller;
}

void VTodoListButton::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTodoListButton::action() const
{
    return d->action;
}

void VTodoListButton::setAction(const QString &action)
{
    d->action = action;
}

VTodoListButton &VTodoListButton::operator=(const VTodoListButton &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTodoListButton VTodoListButton::create(int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action)
{
    VTodoListButtonObject obj;
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
        return VTodoListButton();
    }
    return VTodoListButton(obj);
}

VTodoListButton VTodoListButton::create(const QVariantMap &values)
{
    VTodoListButton model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTodoListButton VTodoListButton::get(int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int buttonId, int buttonOrder, const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VTodoListButtonObject::TodoListId, todoListId);
    cri.add(VTodoListButtonObject::TodoListCd, todoListCd);
    cri.add(VTodoListButtonObject::TodoListNameZh, todoListNameZh);
    cri.add(VTodoListButtonObject::TodoListNameEn, todoListNameEn);
    cri.add(VTodoListButtonObject::TodoListTooltip, todoListTooltip);
    cri.add(VTodoListButtonObject::TodoListDesc, todoListDesc);
    cri.add(VTodoListButtonObject::ButtonId, buttonId);
    cri.add(VTodoListButtonObject::ButtonOrder, buttonOrder);
    cri.add(VTodoListButtonObject::ButtonCd, buttonCd);
    cri.add(VTodoListButtonObject::ButtonNameZh, buttonNameZh);
    cri.add(VTodoListButtonObject::ButtonNameEn, buttonNameEn);
    cri.add(VTodoListButtonObject::ButtonTooltip, buttonTooltip);
    cri.add(VTodoListButtonObject::ButtonDesc, buttonDesc);
    cri.add(VTodoListButtonObject::Controller, controller);
    cri.add(VTodoListButtonObject::Action, action);
    TSqlORMapper<VTodoListButtonObject> mapper;
    return VTodoListButton(mapper.findFirst(cri));
}

int VTodoListButton::count()
{
    TSqlORMapper<VTodoListButtonObject> mapper;
    return mapper.findCount();
}

QList<VTodoListButton> VTodoListButton::getAll()
{
    return tfGetModelListByCriteria<VTodoListButton, VTodoListButtonObject>();
}

TModelObject *VTodoListButton::modelData()
{
    return d.data();
}

const TModelObject *VTodoListButton::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTodoListButton &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTodoListButton &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTodoListButton)
