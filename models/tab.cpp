#include <TreeFrogModel>
#include "tab.h"
#include "tabobject.h"

Tab::Tab()
    : TAbstractModel(), d(new TabObject())
{
    d->tab_id = 0;
}

Tab::Tab(const Tab &other)
    : TAbstractModel(), d(new TabObject(*other.d))
{ }

Tab::Tab(const TabObject &object)
    : TAbstractModel(), d(new TabObject(object))
{ }

Tab::~Tab()
{
    // If the reference count becomes 0,
    // the shared data object 'TabObject' is deleted.
}

int Tab::tabId() const
{
    return d->tab_id;
}

QString Tab::tabCd() const
{
    return d->tab_cd;
}

void Tab::setTabCd(const QString &tabCd)
{
    d->tab_cd = tabCd;
}

QString Tab::tabNameZh() const
{
    return d->tab_name_zh;
}

void Tab::setTabNameZh(const QString &tabNameZh)
{
    d->tab_name_zh = tabNameZh;
}

QString Tab::tabNameEn() const
{
    return d->tab_name_en;
}

void Tab::setTabNameEn(const QString &tabNameEn)
{
    d->tab_name_en = tabNameEn;
}

QString Tab::tabTooltip() const
{
    return d->tab_tooltip;
}

void Tab::setTabTooltip(const QString &tabTooltip)
{
    d->tab_tooltip = tabTooltip;
}

QString Tab::tabDesc() const
{
    return d->tab_desc;
}

void Tab::setTabDesc(const QString &tabDesc)
{
    d->tab_desc = tabDesc;
}

QString Tab::controller() const
{
    return d->controller;
}

void Tab::setController(const QString &controller)
{
    d->controller = controller;
}

QString Tab::action() const
{
    return d->action;
}

void Tab::setAction(const QString &action)
{
    d->action = action;
}

QDateTime Tab::createdAt() const
{
    return d->created_at;
}

QString Tab::createdBy() const
{
    return d->created_by;
}

void Tab::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Tab::updatedAt() const
{
    return d->updated_at;
}

QString Tab::updatedBy() const
{
    return d->updated_by;
}

void Tab::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Tab &Tab::operator=(const Tab &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Tab Tab::create(const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, const QString &createdBy, const QString &updatedBy)
{
    TabObject obj;
    obj.tab_cd = tabCd;
    obj.tab_name_zh = tabNameZh;
    obj.tab_name_en = tabNameEn;
    obj.tab_tooltip = tabTooltip;
    obj.tab_desc = tabDesc;
    obj.controller = controller;
    obj.action = action;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Tab();
    }
    return Tab(obj);
}

Tab Tab::create(const QVariantMap &values)
{
    Tab model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Tab Tab::get(int tabId)
{
    TSqlORMapper<TabObject> mapper;
    return Tab(mapper.findByPrimaryKey(tabId));
}

int Tab::count()
{
    TSqlORMapper<TabObject> mapper;
    return mapper.findCount();
}

QList<Tab> Tab::getAll()
{
    return tfGetModelListByCriteria<Tab, TabObject>();
}

TModelObject *Tab::modelData()
{
    return d.data();
}

const TModelObject *Tab::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Tab &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Tab &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Tab)
