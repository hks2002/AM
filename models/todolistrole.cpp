#include <TreeFrogModel>
#include "todolistrole.h"
#include "todolistroleobject.h"
#include "roleapp.h"
#include "todolist.h"

TodoListRole::TodoListRole()
    : TAbstractModel(), d(new TodoListRoleObject())
{
    d->todo_list_id = 0;
    d->role_id = 0;
    d->todo_list_order = 0;
}

TodoListRole::TodoListRole(const TodoListRole &other)
    : TAbstractModel(), d(new TodoListRoleObject(*other.d))
{ }

TodoListRole::TodoListRole(const TodoListRoleObject &object)
    : TAbstractModel(), d(new TodoListRoleObject(object))
{ }

TodoListRole::~TodoListRole()
{
    // If the reference count becomes 0,
    // the shared data object 'TodoListRoleObject' is deleted.
}

int TodoListRole::todoListId() const
{
    return d->todo_list_id;
}

void TodoListRole::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

int TodoListRole::roleId() const
{
    return d->role_id;
}

void TodoListRole::setRoleId(int roleId)
{
    d->role_id = roleId;
}

int TodoListRole::todoListOrder() const
{
    return d->todo_list_order;
}

void TodoListRole::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

QDateTime TodoListRole::createdAt() const
{
    return d->created_at;
}

QString TodoListRole::createdBy() const
{
    return d->created_by;
}

void TodoListRole::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TodoListRole::updatedAt() const
{
    return d->updated_at;
}

QString TodoListRole::updatedBy() const
{
    return d->updated_by;
}

void TodoListRole::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RoleApp TodoListRole::roleAppByroleId() const
{
 return RoleApp::get(d->role_id);
}

TodoList TodoListRole::todoListBytodoListId() const
{
 return TodoList::get(d->todo_list_id);
}

TodoListRole &TodoListRole::operator=(const TodoListRole &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TodoListRole TodoListRole::create(int todoListId, int roleId, int todoListOrder, const QString &createdBy, const QString &updatedBy)
{
    TodoListRoleObject obj;
    obj.todo_list_id = todoListId;
    obj.role_id = roleId;
    obj.todo_list_order = todoListOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TodoListRole();
    }
    return TodoListRole(obj);
}

TodoListRole TodoListRole::create(const QVariantMap &values)
{
    TodoListRole model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TodoListRole TodoListRole::get(int todoListId, int roleId)
{
    TSqlORMapper<TodoListRoleObject> mapper;
    return TodoListRole(mapper.findByPrimaryKey(QVariantList()<<QVariant(todoListId)<<QVariant(roleId)));
}

int TodoListRole::count()
{
    TSqlORMapper<TodoListRoleObject> mapper;
    return mapper.findCount();
}

QList<TodoListRole> TodoListRole::getAll()
{
    return tfGetModelListByCriteria<TodoListRole, TodoListRoleObject>();
}

TModelObject *TodoListRole::modelData()
{
    return d.data();
}

const TModelObject *TodoListRole::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TodoListRole &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TodoListRole &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TodoListRole)
