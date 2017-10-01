#ifndef TODOLISTUSER_H
#define TODOLISTUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TodoListUserObject;
class UserApp;
class TodoList;


class T_MODEL_EXPORT TodoListUser : public TAbstractModel
{
public:
    TodoListUser();
    TodoListUser(const TodoListUser &other);
    TodoListUser(const TodoListUserObject &object);
    ~TodoListUser();

    int todoListId() const;
    void setTodoListId(int todoListId);
    int userId() const;
    void setUserId(int userId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    TodoList todoListBytodoListId() const;
    TodoListUser &operator=(const TodoListUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TodoListUser create(int todoListId, int userId, int todoListOrder, const QString &createdBy, const QString &updatedBy);
    static TodoListUser create(const QVariantMap &values);
    static TodoListUser get(int todoListId, int userId);
    static int count();
    static QList<TodoListUser> getAll();

private:
    QSharedDataPointer<TodoListUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TodoListUser &model);
    friend QDataStream &operator>>(QDataStream &ds, TodoListUser &model);
};

Q_DECLARE_METATYPE(TodoListUser)
Q_DECLARE_METATYPE(QList<TodoListUser>)

#endif // TODOLISTUSER_H
