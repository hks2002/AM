#ifndef TODOLISTROLE_H
#define TODOLISTROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TodoListRoleObject;
class RoleApp;
class TodoList;


class T_MODEL_EXPORT TodoListRole : public TAbstractModel
{
public:
    TodoListRole();
    TodoListRole(const TodoListRole &other);
    TodoListRole(const TodoListRoleObject &object);
    ~TodoListRole();

    int todoListId() const;
    void setTodoListId(int todoListId);
    int roleId() const;
    void setRoleId(int roleId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RoleApp roleAppByroleId() const;
    TodoList todoListBytodoListId() const;
    TodoListRole &operator=(const TodoListRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TodoListRole create(int todoListId, int roleId, int todoListOrder, const QString &createdBy, const QString &updatedBy);
    static TodoListRole create(const QVariantMap &values);
    static TodoListRole get(int todoListId, int roleId);
    static int count();
    static QList<TodoListRole> getAll();

private:
    QSharedDataPointer<TodoListRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TodoListRole &model);
    friend QDataStream &operator>>(QDataStream &ds, TodoListRole &model);
};

Q_DECLARE_METATYPE(TodoListRole)
Q_DECLARE_METATYPE(QList<TodoListRole>)

#endif // TODOLISTROLE_H
