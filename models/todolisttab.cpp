#include <TreeFrogModel>
#include "todolisttab.h"
#include "todolisttabobject.h"
#include "tab.h"
#include "todolist.h"

TodoListTab::TodoListTab()
    : TAbstractModel(), d(new TodoListTabObject())
{
    d->todo_list_id = 0;
    d->tab_id = 0;
    d->tab_order = 0;
}

TodoListTab::TodoListTab(const TodoListTab &other)
    : TAbstractModel(), d(new TodoListTabObject(*other.d))
{ }

TodoListTab::TodoListTab(const TodoListTabObject &object)
    : TAbstractModel(), d(new TodoListTabObject(object))
{ }

TodoListTab::~TodoListTab()
{
    // If the reference count becomes 0,
    // the shared data object 'TodoListTabObject' is deleted.
}

int TodoListTab::todoListId() const
{
    return d->todo_list_id;
}

void TodoListTab::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

int TodoListTab::tabId() const
{
    return d->tab_id;
}

void TodoListTab::setTabId(int tabId)
{
    d->tab_id = tabId;
}

int TodoListTab::tabOrder() const
{
    return d->tab_order;
}

void TodoListTab::setTabOrder(int tabOrder)
{
    d->tab_order = tabOrder;
}

QDateTime TodoListTab::createdAt() const
{
    return d->created_at;
}

QString TodoListTab::createdBy() const
{
    return d->created_by;
}

void TodoListTab::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TodoListTab::updatedAt() const
{
    return d->updated_at;
}

QString TodoListTab::updatedBy() const
{
    return d->updated_by;
}

void TodoListTab::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Tab TodoListTab::tabBytabId() const
{
 return Tab::get(d->tab_id);
}

TodoList TodoListTab::todoListBytodoListId() const
{
 return TodoList::get(d->todo_list_id);
}

TodoListTab &TodoListTab::operator=(const TodoListTab &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TodoListTab TodoListTab::create(int todoListId, int tabId, int tabOrder, const QString &createdBy, const QString &updatedBy)
{
    TodoListTabObject obj;
    obj.todo_list_id = todoListId;
    obj.tab_id = tabId;
    obj.tab_order = tabOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TodoListTab();
    }
    return TodoListTab(obj);
}

TodoListTab TodoListTab::create(const QVariantMap &values)
{
    TodoListTab model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TodoListTab TodoListTab::get(int todoListId, int tabId)
{
    TSqlORMapper<TodoListTabObject> mapper;
    return TodoListTab(mapper.findByPrimaryKey(QVariantList()<<QVariant(todoListId)<<QVariant(tabId)));
}

int TodoListTab::count()
{
    TSqlORMapper<TodoListTabObject> mapper;
    return mapper.findCount();
}

QList<TodoListTab> TodoListTab::getAll()
{
    return tfGetModelListByCriteria<TodoListTab, TodoListTabObject>();
}

TModelObject *TodoListTab::modelData()
{
    return d.data();
}

const TModelObject *TodoListTab::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TodoListTab &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TodoListTab &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TodoListTab)
