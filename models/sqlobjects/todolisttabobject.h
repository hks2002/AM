#ifndef TODOLISTTABOBJECT_H
#define TODOLISTTABOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TodoListTabObject : public TSqlObject, public QSharedData
{
public:
    int todo_list_id {0};
    int tab_id {0};
    int tab_order {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TodoListId = 0,
        TabId,
        TabOrder,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TodoListId<<TabId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TabId<<TodoListId; }
    QString tableName() const override { return QLatin1String("todo_list_tab"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int todo_list_id READ gettodo_list_id WRITE settodo_list_id)
    T_DEFINE_PROPERTY(int, todo_list_id)
    Q_PROPERTY(int tab_id READ gettab_id WRITE settab_id)
    T_DEFINE_PROPERTY(int, tab_id)
    Q_PROPERTY(int tab_order READ gettab_order WRITE settab_order)
    T_DEFINE_PROPERTY(int, tab_order)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TODOLISTTABOBJECT_H
