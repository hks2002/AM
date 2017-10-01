#ifndef TODOLIST_H
#define TODOLIST_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TodoListObject;


class T_MODEL_EXPORT TodoList : public TAbstractModel
{
public:
    TodoList();
    TodoList(const TodoList &other);
    TodoList(const TodoListObject &object);
    ~TodoList();

    int todoListId() const;
    QString todoListCd() const;
    void setTodoListCd(const QString &todoListCd);
    QString todoListNameZh() const;
    void setTodoListNameZh(const QString &todoListNameZh);
    QString todoListNameEn() const;
    void setTodoListNameEn(const QString &todoListNameEn);
    QString todoListTooltip() const;
    void setTodoListTooltip(const QString &todoListTooltip);
    QString todoListDesc() const;
    void setTodoListDesc(const QString &todoListDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TodoList &operator=(const TodoList &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TodoList create(const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, const QString &createdBy, const QString &updatedBy);
    static TodoList create(const QVariantMap &values);
    static TodoList get(int todoListId);
    static int count();
    static QList<TodoList> getAll();

private:
    QSharedDataPointer<TodoListObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TodoList &model);
    friend QDataStream &operator>>(QDataStream &ds, TodoList &model);
};

Q_DECLARE_METATYPE(TodoList)
Q_DECLARE_METATYPE(QList<TodoList>)

#endif // TODOLIST_H
