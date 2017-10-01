#include <TreeFrogModel>
#include "todolist.h"
#include "todolistobject.h"

TodoList::TodoList()
    : TAbstractModel(), d(new TodoListObject())
{
    d->todo_list_id = 0;
}

TodoList::TodoList(const TodoList &other)
    : TAbstractModel(), d(new TodoListObject(*other.d))
{ }

TodoList::TodoList(const TodoListObject &object)
    : TAbstractModel(), d(new TodoListObject(object))
{ }

TodoList::~TodoList()
{
    // If the reference count becomes 0,
    // the shared data object 'TodoListObject' is deleted.
}

int TodoList::todoListId() const
{
    return d->todo_list_id;
}

QString TodoList::todoListCd() const
{
    return d->todo_list_cd;
}

void TodoList::setTodoListCd(const QString &todoListCd)
{
    d->todo_list_cd = todoListCd;
}

QString TodoList::todoListNameZh() const
{
    return d->todo_list_name_zh;
}

void TodoList::setTodoListNameZh(const QString &todoListNameZh)
{
    d->todo_list_name_zh = todoListNameZh;
}

QString TodoList::todoListNameEn() const
{
    return d->todo_list_name_en;
}

void TodoList::setTodoListNameEn(const QString &todoListNameEn)
{
    d->todo_list_name_en = todoListNameEn;
}

QString TodoList::todoListTooltip() const
{
    return d->todo_list_tooltip;
}

void TodoList::setTodoListTooltip(const QString &todoListTooltip)
{
    d->todo_list_tooltip = todoListTooltip;
}

QString TodoList::todoListDesc() const
{
    return d->todo_list_desc;
}

void TodoList::setTodoListDesc(const QString &todoListDesc)
{
    d->todo_list_desc = todoListDesc;
}

QDateTime TodoList::createdAt() const
{
    return d->created_at;
}

QString TodoList::createdBy() const
{
    return d->created_by;
}

void TodoList::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TodoList::updatedAt() const
{
    return d->updated_at;
}

QString TodoList::updatedBy() const
{
    return d->updated_by;
}

void TodoList::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TodoList &TodoList::operator=(const TodoList &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TodoList TodoList::create(const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, const QString &createdBy, const QString &updatedBy)
{
    TodoListObject obj;
    obj.todo_list_cd = todoListCd;
    obj.todo_list_name_zh = todoListNameZh;
    obj.todo_list_name_en = todoListNameEn;
    obj.todo_list_tooltip = todoListTooltip;
    obj.todo_list_desc = todoListDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TodoList();
    }
    return TodoList(obj);
}

TodoList TodoList::create(const QVariantMap &values)
{
    TodoList model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TodoList TodoList::get(int todoListId)
{
    TSqlORMapper<TodoListObject> mapper;
    return TodoList(mapper.findByPrimaryKey(todoListId));
}

int TodoList::count()
{
    TSqlORMapper<TodoListObject> mapper;
    return mapper.findCount();
}

QList<TodoList> TodoList::getAll()
{
    return tfGetModelListByCriteria<TodoList, TodoListObject>();
}

TModelObject *TodoList::modelData()
{
    return d.data();
}

const TModelObject *TodoList::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TodoList &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TodoList &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TodoList)
