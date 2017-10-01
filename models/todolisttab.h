#ifndef TODOLISTTAB_H
#define TODOLISTTAB_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TodoListTabObject;
class Tab;
class TodoList;


class T_MODEL_EXPORT TodoListTab : public TAbstractModel
{
public:
    TodoListTab();
    TodoListTab(const TodoListTab &other);
    TodoListTab(const TodoListTabObject &object);
    ~TodoListTab();

    int todoListId() const;
    void setTodoListId(int todoListId);
    int tabId() const;
    void setTabId(int tabId);
    int tabOrder() const;
    void setTabOrder(int tabOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Tab tabBytabId() const;
    TodoList todoListBytodoListId() const;
    TodoListTab &operator=(const TodoListTab &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TodoListTab create(int todoListId, int tabId, int tabOrder, const QString &createdBy, const QString &updatedBy);
    static TodoListTab create(const QVariantMap &values);
    static TodoListTab get(int todoListId, int tabId);
    static int count();
    static QList<TodoListTab> getAll();

private:
    QSharedDataPointer<TodoListTabObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TodoListTab &model);
    friend QDataStream &operator>>(QDataStream &ds, TodoListTab &model);
};

Q_DECLARE_METATYPE(TodoListTab)
Q_DECLARE_METATYPE(QList<TodoListTab>)

#endif // TODOLISTTAB_H
