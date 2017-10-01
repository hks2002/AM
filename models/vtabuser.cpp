#include <TreeFrogModel>
#include "vtabuser.h"
#include "vtabuserobject.h"

VTabUser::VTabUser()
    : TAbstractModel(), d(new VTabUserObject())
{
    d->tab_id = 0;
    d->user_id = 0;
    d->todo_list_order = 0;
    d->tab_order = 0;
}

VTabUser::VTabUser(const VTabUser &other)
    : TAbstractModel(), d(new VTabUserObject(*other.d))
{ }

VTabUser::VTabUser(const VTabUserObject &object)
    : TAbstractModel(), d(new VTabUserObject(object))
{ }

VTabUser::~VTabUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VTabUserObject' is deleted.
}

int VTabUser::tabId() const
{
    return d->tab_id;
}

void VTabUser::setTabId(int tabId)
{
    d->tab_id = tabId;
}

QString VTabUser::tabCd() const
{
    return d->tab_cd;
}

void VTabUser::setTabCd(const QString &tabCd)
{
    d->tab_cd = tabCd;
}

QString VTabUser::tabNameZh() const
{
    return d->tab_name_zh;
}

void VTabUser::setTabNameZh(const QString &tabNameZh)
{
    d->tab_name_zh = tabNameZh;
}

QString VTabUser::tabNameEn() const
{
    return d->tab_name_en;
}

void VTabUser::setTabNameEn(const QString &tabNameEn)
{
    d->tab_name_en = tabNameEn;
}

QString VTabUser::tabTooltip() const
{
    return d->tab_tooltip;
}

void VTabUser::setTabTooltip(const QString &tabTooltip)
{
    d->tab_tooltip = tabTooltip;
}

QString VTabUser::tabDesc() const
{
    return d->tab_desc;
}

void VTabUser::setTabDesc(const QString &tabDesc)
{
    d->tab_desc = tabDesc;
}

QString VTabUser::controller() const
{
    return d->controller;
}

void VTabUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTabUser::action() const
{
    return d->action;
}

void VTabUser::setAction(const QString &action)
{
    d->action = action;
}

int VTabUser::userId() const
{
    return d->user_id;
}

void VTabUser::setUserId(int userId)
{
    d->user_id = userId;
}

int VTabUser::todoListOrder() const
{
    return d->todo_list_order;
}

void VTabUser::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VTabUser::tabOrder() const
{
    return d->tab_order;
}

void VTabUser::setTabOrder(int tabOrder)
{
    d->tab_order = tabOrder;
}

VTabUser &VTabUser::operator=(const VTabUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTabUser VTabUser::create(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int tabOrder)
{
    VTabUserObject obj;
    obj.tab_id = tabId;
    obj.tab_cd = tabCd;
    obj.tab_name_zh = tabNameZh;
    obj.tab_name_en = tabNameEn;
    obj.tab_tooltip = tabTooltip;
    obj.tab_desc = tabDesc;
    obj.controller = controller;
    obj.action = action;
    obj.user_id = userId;
    obj.todo_list_order = todoListOrder;
    obj.tab_order = tabOrder;
    if (!obj.create()) {
        return VTabUser();
    }
    return VTabUser(obj);
}

VTabUser VTabUser::create(const QVariantMap &values)
{
    VTabUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTabUser VTabUser::get(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int tabOrder)
{
    TCriteria cri;
    cri.add(VTabUserObject::TabId, tabId);
    cri.add(VTabUserObject::TabCd, tabCd);
    cri.add(VTabUserObject::TabNameZh, tabNameZh);
    cri.add(VTabUserObject::TabNameEn, tabNameEn);
    cri.add(VTabUserObject::TabTooltip, tabTooltip);
    cri.add(VTabUserObject::TabDesc, tabDesc);
    cri.add(VTabUserObject::Controller, controller);
    cri.add(VTabUserObject::Action, action);
    cri.add(VTabUserObject::UserId, userId);
    cri.add(VTabUserObject::TodoListOrder, todoListOrder);
    cri.add(VTabUserObject::TabOrder, tabOrder);
    TSqlORMapper<VTabUserObject> mapper;
    return VTabUser(mapper.findFirst(cri));
}

int VTabUser::count()
{
    TSqlORMapper<VTabUserObject> mapper;
    return mapper.findCount();
}

QList<VTabUser> VTabUser::getAll()
{
    return tfGetModelListByCriteria<VTabUser, VTabUserObject>(TCriteria());
}

TModelObject *VTabUser::modelData()
{
    return d.data();
}

const TModelObject *VTabUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTabUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTabUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTabUser)
