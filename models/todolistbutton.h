#ifndef TODOLISTBUTTON_H
#define TODOLISTBUTTON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TodoListButtonObject;
class Button;
class TodoList;


class T_MODEL_EXPORT TodoListButton : public TAbstractModel
{
public:
    TodoListButton();
    TodoListButton(const TodoListButton &other);
    TodoListButton(const TodoListButtonObject &object);
    ~TodoListButton();

    int todoListId() const;
    void setTodoListId(int todoListId);
    int buttonId() const;
    void setButtonId(int buttonId);
    int buttonOrder() const;
    void setButtonOrder(int buttonOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Button buttonBybuttonId() const;
    TodoList todoListBytodoListId() const;
    TodoListButton &operator=(const TodoListButton &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TodoListButton create(int todoListId, int buttonId, int buttonOrder, const QString &createdBy, const QString &updatedBy);
    static TodoListButton create(const QVariantMap &values);
    static TodoListButton get(int todoListId, int buttonId);
    static int count();
    static QList<TodoListButton> getAll();

private:
    QSharedDataPointer<TodoListButtonObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TodoListButton &model);
    friend QDataStream &operator>>(QDataStream &ds, TodoListButton &model);
};

Q_DECLARE_METATYPE(TodoListButton)
Q_DECLARE_METATYPE(QList<TodoListButton>)

#endif // TODOLISTBUTTON_H
