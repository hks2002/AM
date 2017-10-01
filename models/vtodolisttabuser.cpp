#include <TreeFrogModel>
#include "vtodolisttabuser.h"
#include "vtodolisttabuserobject.h"

VTodoListTabUser::VTodoListTabUser()
    : TAbstractModel(), d(new VTodoListTabUserObject())
{
    d->user_id = 0;
    d->todo_list_order = 0;
    d->todo_list_id = 0;
    d->tab_id = 0;
    d->tab_order = 0;
}

VTodoListTabUser::VTodoListTabUser(const VTodoListTabUser &other)
    : TAbstractModel(), d(new VTodoListTabUserObject(*other.d))
{ }

VTodoListTabUser::VTodoListTabUser(const VTodoListTabUserObject &object)
    : TAbstractModel(), d(new VTodoListTabUserObject(object))
{ }

VTodoListTabUser::~VTodoListTabUser()
{
    // If the reference count becomes 0,
    // the shared data object 'VTodoListTabUserObject' is deleted.
}

int VTodoListTabUser::userId() const
{
    return d->user_id;
}

void VTodoListTabUser::setUserId(int userId)
{
    d->user_id = userId;
}

int VTodoListTabUser::todoListOrder() const
{
    return d->todo_list_order;
}

void VTodoListTabUser::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

int VTodoListTabUser::todoListId() const
{
    return d->todo_list_id;
}

void VTodoListTabUser::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

QString VTodoListTabUser::todoListCd() const
{
    return d->todo_list_cd;
}

void VTodoListTabUser::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString VTodoListTabUser::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void VTodoListTabUser::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString VTodoListTabUser::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void VTodoListTabUser::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString VTodoListTabUser::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void VTodoListTabUser::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString VTodoListTabUser::todoListDesc() const
{
    return d->todo_list_desc;
}

void VTodoListTabUser::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

int VTodoListTabUser::tabId() const
{
    return d->tab_id;
}

void VTodoListTabUser::setTabId(int tabId)
{
    d->tab_id = tabId;
}

int VTodoListTabUser::tabOrder() const
{
    return d->tab_order;
}

void VTodoListTabUser::setTabOrder(int tabOrder)
{
    d->tab_order = tabOrder;
}

QString VTodoListTabUser::tabCd() const
{
    return d->tab_cd;
}

void VTodoListTabUser::setTabCd(const QString &tabCd)
{
    d->tab_cd = tabCd;
}

QString VTodoListTabUser::tabNameZh() const
{
    return d->tab_name_zh;
}

void VTodoListTabUser::setTabNameZh(const QString &tabNameZh)
{
    d->tab_name_zh = tabNameZh;
}

QString VTodoListTabUser::tabNameEn() const
{
    return d->tab_name_en;
}

void VTodoListTabUser::setTabNameEn(const QString &tabNameEn)
{
    d->tab_name_en = tabNameEn;
}

QString VTodoListTabUser::tabTooltip() const
{
    return d->tab_tooltip;
}

void VTodoListTabUser::setTabTooltip(const QString &tabTooltip)
{
    d->tab_tooltip = tabTooltip;
}

QString VTodoListTabUser::tabDesc() const
{
    return d->tab_desc;
}

void VTodoListTabUser::setTabDesc(const QString &tabDesc)
{
    d->tab_desc = tabDesc;
}

QString VTodoListTabUser::controller() const
{
    return d->controller;
}

void VTodoListTabUser::setController(const QString &controller)
{
    d->controller = controller;
}

QString VTodoListTabUser::action() const
{
    return d->action;
}

void VTodoListTabUser::setAction(const QString &action)
{
    d->action = action;
}

VTodoListTabUser &VTodoListTabUser::operator=(const VTodoListTabUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VTodoListTabUser VTodoListTabUser::create(int userId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action)
{
    VTodoListTabUserObject obj;
    obj.user_id = userId;
    obj.todo_list_order = todoListOrder;
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
        return VTodoListTabUser();
    }
    return VTodoListTabUser(obj);
}

VTodoListTabUser VTodoListTabUser::create(const QVariantMap &values)
{
    VTodoListTabUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VTodoListTabUser VTodoListTabUser::get(int userId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action)
{
    TCriteria cri;
    cri.add(VTodoListTabUserObject::UserId, userId);
    cri.add(VTodoListTabUserObject::TodoListOrder, todoListOrder);
    cri.add(VTodoListTabUserObject::TodoListId, todoListId);
    cri.add(VTodoListTabUserObject::TodoListCd, todoListCd);
    cri.add(VTodoListTabUserObject::TodoListNameZh, todoListNameZh);
    cri.add(VTodoListTabUserObject::TodoListNameEn, todoListNameEn);
    cri.add(VTodoListTabUserObject::TodoListTooltip, todoListTooltip);
    cri.add(VTodoListTabUserObject::TodoListDesc, todoListDesc);
    cri.add(VTodoListTabUserObject::TabId, tabId);
    cri.add(VTodoListTabUserObject::TabOrder, tabOrder);
    cri.add(VTodoListTabUserObject::TabCd, tabCd);
    cri.add(VTodoListTabUserObject::TabNameZh, tabNameZh);
    cri.add(VTodoListTabUserObject::TabNameEn, tabNameEn);
    cri.add(VTodoListTabUserObject::TabTooltip, tabTooltip);
    cri.add(VTodoListTabUserObject::TabDesc, tabDesc);
    cri.add(VTodoListTabUserObject::Controller, controller);
    cri.add(VTodoListTabUserObject::Action, action);
    TSqlORMapper<VTodoListTabUserObject> mapper;
    return VTodoListTabUser(mapper.findFirst(cri));
}

int VTodoListTabUser::count()
{
    TSqlORMapper<VTodoListTabUserObject> mapper;
    return mapper.findCount();
}

QList<VTodoListTabUser> VTodoListTabUser::getAll()
{
    return tfGetModelListByCriteria<VTodoListTabUser, VTodoListTabUserObject>();
}

TModelObject *VTodoListTabUser::modelData()
{
    return d.data();
}

const TModelObject *VTodoListTabUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VTodoListTabUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VTodoListTabUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VTodoListTabUser)
