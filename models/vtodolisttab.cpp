#include <TreeFrogModel>
#include "vtodolisttab.h"
#include "vtodolisttabobject.h"

VTodoListTab::VTodoListTab()
    : TAbstractModel(), d(new VTodoListTabObject())
{
    d->todo_list_id = 0;
    d->tab_id = 0;
    d->tab_order = 0;
}

VTodoListTab::VTodoListTab(const VTodoListTab &other)
    : TAbstractModel(), d(new VTodoListTabObject(*other.d))
{ }

VTodoListTab::VTodoListTab(const VTodoListTabObject &object)
    : TAbstractModel(), d(new VTodoListTabObject(object))
{ }

VTodoListTab::~VTodoListTab()
{
    // If the reference count becomes 0,
    // the shared data object 'VTodoListTabObject' is deleted.
}

int VTodoListTab::todoListId() const
{
    return d->todo_list_id;
}

void VTodoListTab::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

QString VTodoListTab::todoListCd() const
{
    return d->todo_list_cd;
}

void VTodoListTab::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString VTodoListTab::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void VTodoListTab::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString VTodoListTab::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void VTodoListTab::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString VTodoListTab::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void VTodoListTab::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString VTodoListTab::todoListDesc() const
{
    return d->todo_list_desc;
}

void VTodoListTab::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

int VTodoListTab::tabId() const
{
    return d->tab_id;
}

void VTodoListTab::setTabId(int tabId)
{
    d->tab_id = tabId;
}

int VTodoListTab::tabOrder() const
{
    return d->tab_order;
}

void VTodoListTab::setTabOrder(int tabOrder)
{
    d->tab_order = tabOrder;
}

QString VTodoListTab::tabCd() const
{
    return d->tab_cd;
}

void VTodoListTab::setTabCd(const QString &tabCd)
{
    d->tab_cd = tabCd;
}

QString VTodoListTab::tabNameZh() const
{
    return d->tab_name_zh;
}

void VTodoListTab::setTabNameZh(const QString &tabNameZh)
{
    d->tab_name_zh = tabNameZh;
}

QString VTodoListTab::tabNameEn() const
{
    return d->tab_name_en;
}

void VTodoListTab::setTabNameEn(const QString &tabNameEn)
{
    d->tab_name_en = tabNameEn;
}

QString VTodoListTab::tabTooltip() const
{
    return d->tab_tooltip;
}

void VTodoListTab::setTabTooltip(const QString &tabTooltip)
{
    d->tab_tooltip = tabTooltip;
}

QString VTodoListTab::tabDesc() const
{
    return d->tab_desc;
}

void VTodoListTab::setTabDesc(const QString &tabDesc)
{
    d->tab_desc = tabDesc;
}

QString VTodoListTab::controller() const
{
    return d->controller;
}

void VTodoListTab::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTodoListTab::action() const
{
    return d->action;
}

void VTodoListTab::setAction(const QString &action)
{
    d->action = action;
}

VTodoListTab &VTodoListTab::operator=(const VTodoListTab &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTodoListTab VTodoListTab::create(int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action)
{
    VTodoListTabObject obj;
    obj.todo_list_id = todoListId;
    obj.todo_list_cd = todoListCd;
    obj.todo_list_name_zh = todoListNameZh;
    obj.todo_list_name_en = todoListNameEn;
    obj.todo_list_tooltip = todoListTooltip;
    obj.todo_list_desc = todoListDesc;
    obj.tab_id = tabId;
    obj.tab_order = tabOrder;
    obj.tab_cd = tabCd;
    obj.tab_name_zh = tabNameZh;
    obj.tab_name_en = tabNameEn;
    obj.tab_tooltip = tabTooltip;
    obj.tab_desc = tabDesc;
    obj.controller = controller;
    obj.action = action;
    if (!obj.create()) {
        return VTodoListTab();
    }
    return VTodoListTab(obj);
}

VTodoListTab VTodoListTab::create(const QVariantMap &values)
{
    VTodoListTab model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTodoListTab VTodoListTab::get(int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VTodoListTabObject::TodoListId, todoListId);
    cri.add(VTodoListTabObject::TodoListCd, todoListCd);
    cri.add(VTodoListTabObject::TodoListNameZh, todoListNameZh);
    cri.add(VTodoListTabObject::TodoListNameEn, todoListNameEn);
    cri.add(VTodoListTabObject::TodoListTooltip, todoListTooltip);
    cri.add(VTodoListTabObject::TodoListDesc, todoListDesc);
    cri.add(VTodoListTabObject::TabId, tabId);
    cri.add(VTodoListTabObject::TabOrder, tabOrder);
    cri.add(VTodoListTabObject::TabCd, tabCd);
    cri.add(VTodoListTabObject::TabNameZh, tabNameZh);
    cri.add(VTodoListTabObject::TabNameEn, tabNameEn);
    cri.add(VTodoListTabObject::TabTooltip, tabTooltip);
    cri.add(VTodoListTabObject::TabDesc, tabDesc);
    cri.add(VTodoListTabObject::Controller, controller);
    cri.add(VTodoListTabObject::Action, action);
    TSqlORMapper<VTodoListTabObject> mapper;
    return VTodoListTab(mapper.findFirst(cri));
}

int VTodoListTab::count()
{
    TSqlORMapper<VTodoListTabObject> mapper;
    return mapper.findCount();
}

QList<VTodoListTab> VTodoListTab::getAll()
{
    return tfGetModelListByCriteria<VTodoListTab, VTodoListTabObject>();
}

TModelObject *VTodoListTab::modelData()
{
    return d.data();
}

const TModelObject *VTodoListTab::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTodoListTab &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTodoListTab &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTodoListTab)
