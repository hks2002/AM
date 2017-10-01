#include <TreeFrogModel>
#include "todolistuser.h"
#include "todolistuserobject.h"
#include "userapp.h"
#include "todolist.h"

TodoListUser::TodoListUser()
    : TAbstractModel(), d(new TodoListUserObject())
{
    d->todo_list_id = 0;
    d->user_id = 0;
    d->todo_list_order = 0;
}

TodoListUser::TodoListUser(const TodoListUser &other)
    : TAbstractModel(), d(new TodoListUserObject(*other.d))
{ }

TodoListUser::TodoListUser(const TodoListUserObject &object)
    : TAbstractModel(), d(new TodoListUserObject(object))
{ }

TodoListUser::~TodoListUser()
{
    // If the reference count becomes 0,
    // the shared data object 'TodoListUserObject' is deleted.
}

int TodoListUser::todoListId() const
{
    return d->todo_list_id;
}

void TodoListUser::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

int TodoListUser::userId() const
{
    return d->user_id;
}

void TodoListUser::setUserId(int userId)
{
    d->user_id = userId;
}

int TodoListUser::todoListOrder() const
{
    return d->todo_list_order;
}

void TodoListUser::setTodoListOrder(int todoListOrder)
{
    d->todo_list_order = todoListOrder;
}

QDateTime TodoListUser::createdAt() const
{
    return d->created_at;
}

QString TodoListUser::createdBy() const
{
    return d->created_by;
}

void TodoListUser::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TodoListUser::updatedAt() const
{
    return d->updated_at;
}

QString TodoListUser::updatedBy() const
{
    return d->updated_by;
}

void TodoListUser::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp TodoListUser::userAppByuserId() const
{
 return UserApp::get(d->user_id);
}

TodoList TodoListUser::todoListBytodoListId() const
{
 return TodoList::get(d->todo_list_id);
}

TodoListUser &TodoListUser::operator=(const TodoListUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TodoListUser TodoListUser::create(int todoListId, int userId, int todoListOrder, const QString &createdBy, const QString &updatedBy)
{
    TodoListUserObject obj;
    obj.todo_list_id = todoListId;
    obj.user_id = userId;
    obj.todo_list_order = todoListOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TodoListUser();
    }
    return TodoListUser(obj);
}

TodoListUser TodoListUser::create(const QVariantMap &values)
{
    TodoListUser model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TodoListUser TodoListUser::get(int todoListId, int userId)
{
    TSqlORMapper<TodoListUserObject> mapper;
    return TodoListUser(mapper.findByPrimaryKey(QVariantList()<<QVariant(todoListId)<<QVariant(userId)));
}

int TodoListUser::count()
{
    TSqlORMapper<TodoListUserObject> mapper;
    return mapper.findCount();
}

QList<TodoListUser> TodoListUser::getAll()
{
    return tfGetModelListByCriteria<TodoListUser, TodoListUserObject>();
}

TModelObject *TodoListUser::modelData()
{
    return d.data();
}

const TModelObject *TodoListUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TodoListUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TodoListUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TodoListUser)
