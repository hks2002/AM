#ifndef TODOLISTROLEOBJECT_H
#define TODOLISTROLEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TodoListRoleObject : public TSqlObject, public QSharedData
{
public:
    int todo_list_id {0};
    int role_id {0};
    int todo_list_order {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TodoListId = 0,
        RoleId,
        TodoListOrder,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TodoListId<<RoleId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RoleId<<TodoListId; }
    QString tableName() const override { return QLatin1String("todo_list_role"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int todo_list_id READ gettodo_list_id WRITE settodo_list_id)
    T_DEFINE_PROPERTY(int, todo_list_id)
    Q_PROPERTY(int role_id READ getrole_id WRITE setrole_id)
    T_DEFINE_PROPERTY(int, role_id)
    Q_PROPERTY(int todo_list_order READ gettodo_list_order WRITE settodo_list_order)
    T_DEFINE_PROPERTY(int, todo_list_order)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TODOLISTROLEOBJECT_H
