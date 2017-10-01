#include <TreeFrogModel>
#include "button.h"
#include "buttonobject.h"

Button::Button()
    : TAbstractModel(), d(new ButtonObject())
{
    d->button_id = 0;
}

Button::Button(const Button &other)
    : TAbstractModel(), d(new ButtonObject(*other.d))
{ }

Button::Button(const ButtonObject &object)
    : TAbstractModel(), d(new ButtonObject(object))
{ }

Button::~Button()
{
    // If the reference count becomes 0,
    // the shared data object 'ButtonObject' is deleted.
}

int Button::buttonId() const
{
    return d->button_id;
}

QString Button::buttonCd() const
{
    return d->button_cd;
}

void Button::setButtonCd(const QString &buttonCd)
{
    d->button_cd = buttonCd;
}

QString Button::buttonNameZh() const
{
    return d->button_name_zh;
}

void Button::setButtonNameZh(const QString &buttonNameZh)
{
    d->button_name_zh = buttonNameZh;
}

QString Button::buttonNameEn() const
{
    return d->button_name_en;
}

void Button::setButtonNameEn(const QString &buttonNameEn)
{
    d->button_name_en = buttonNameEn;
}

QString Button::buttonTooltip() const
{
    return d->button_tooltip;
}

void Button::setButtonTooltip(const QString &buttonTooltip)
{
    d->button_tooltip = buttonTooltip;
}

QString Button::buttonDesc() const
{
    return d->button_desc;
}

void Button::setButtonDesc(const QString &buttonDesc)
{
    d->button_desc = buttonDesc;
}

QString Button::controller() const
{
    return d->controller;
}

void Button::setController(const QString &controller)
{
    d->controller = controller;
}

QString Button::action() const
{
    return d->action;
}

void Button::setAction(const QString &action)
{
    d->action = action;
}

QDateTime Button::createdAt() const
{
    return d->created_at;
}

QString Button::createdBy() const
{
    return d->created_by;
}

void Button::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Button::updatedAt() const
{
    return d->updated_at;
}

QString Button::updatedBy() const
{
    return d->updated_by;
}

void Button::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Button &Button::operator=(const Button &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Button Button::create(const QString &buttonCd, const QString &buttonNameZh, const QString &buttonNameEn, const QString &buttonTooltip, const QString &buttonDesc, const QString &controller, const QString &action, const QString &createdBy, const QString &updatedBy)
{
    ButtonObject obj;
    obj.button_cd = buttonCd;
    obj.button_name_zh = buttonNameZh;
    obj.button_name_en = buttonNameEn;
    obj.button_tooltip = buttonTooltip;
    obj.button_desc = buttonDesc;
    obj.controller = controller;
    obj.action = action;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Button();
    }
    return Button(obj);
}

Button Button::create(const QVariantMap &values)
{
    Button model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Button Button::get(int buttonId)
{
    TSqlORMapper<ButtonObject> mapper;
    return Button(mapper.findByPrimaryKey(buttonId));
}

int Button::count()
{
    TSqlORMapper<ButtonObject> mapper;
    return mapper.findCount();
}

QList<Button> Button::getAll()
{
    return tfGetModelListByCriteria<Button, ButtonObject>();
}

TModelObject *Button::modelData()
{
    return d.data();
}

const TModelObject *Button::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Button &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Button &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Button)
