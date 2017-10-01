#include <TreeFrogModel>
#include "todolistbutton.h"
#include "todolistbuttonobject.h"
#include "button.h"
#include "todolist.h"

TodoListButton::TodoListButton()
    : TAbstractModel(), d(new TodoListButtonObject())
{
    d->todo_list_id = 0;
    d->button_id = 0;
    d->button_order = 0;
}

TodoListButton::TodoListButton(const TodoListButton &other)
    : TAbstractModel(), d(new TodoListButtonObject(*other.d))
{ }

TodoListButton::TodoListButton(const TodoListButtonObject &object)
    : TAbstractModel(), d(new TodoListButtonObject(object))
{ }

TodoListButton::~TodoListButton()
{
    // If the reference count becomes 0,
    // the shared data object 'TodoListButtonObject' is deleted.
}

int TodoListButton::todoListId() const
{
    return d->todo_list_id;
}

void TodoListButton::setTodoListId(int todoListId)
{
    d->todo_list_id = todoListId;
}

int TodoListButton::buttonId() const
{
    return d->button_id;
}

void TodoListButton::setButtonId(int buttonId)
{
    d->button_id = buttonId;
}

int TodoListButton::buttonOrder() const
{
    return d->button_order;
}

void TodoListButton::setButtonOrder(int buttonOrder)
{
    d->button_order = buttonOrder;
}

QDateTime TodoListButton::createdAt() const
{
    return d->created_at;
}

QString TodoListButton::createdBy() const
{
    return d->created_by;
}

void TodoListButton::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TodoListButton::updatedAt() const
{
    return d->updated_at;
}

QString TodoListButton::updatedBy() const
{
    return d->updated_by;
}

void TodoListButton::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Button TodoListButton::buttonBybuttonId() const
{
 return Button::get(d->button_id);
}

TodoList TodoListButton::todoListBytodoListId() const
{
 return TodoList::get(d->todo_list_id);
}

TodoListButton &TodoListButton::operator=(const TodoListButton &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TodoListButton TodoListButton::create(int todoListId, int buttonId, int buttonOrder, const QString &createdBy, const QString &updatedBy)
{
    TodoListButtonObject obj;
    obj.todo_list_id = todoListId;
    obj.button_id = buttonId;
    obj.button_order = buttonOrder;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TodoListButton();
    }
    return TodoListButton(obj);
}

TodoListButton TodoListButton::create(const QVariantMap &values)
{
    TodoListButton model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TodoListButton TodoListButton::get(int todoListId, int buttonId)
{
    TSqlORMapper<TodoListButtonObject> mapper;
    return TodoListButton(mapper.findByPrimaryKey(QVariantList()<<QVariant(todoListId)<<QVariant(buttonId)));
}

int TodoListButton::count()
{
    TSqlORMapper<TodoListButtonObject> mapper;
    return mapper.findCount();
}

QList<TodoListButton> TodoListButton::getAll()
{
    return tfGetModelListByCriteria<TodoListButton, TodoListButtonObject>();
}

TModelObject *TodoListButton::modelData()
{
    return d.data();
}

const TModelObject *TodoListButton::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TodoListButton &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TodoListButton &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TodoListButton)
