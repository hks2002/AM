#ifndef TODOLISTOBJECT_H
#define TODOLISTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TodoListObject : public TSqlObject, public QSharedData
{
public:
    int todo_list_id {0};
    QString todo_list_cd;
    QString todo_list_name_zh;
    QString todo_list_name_en;
    QString todo_list_tooltip;
    QString todo_list_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TodoListId = 0,
        TodoListCd,
        TodoListNameZh,
        TodoListNameEn,
        TodoListTooltip,
        TodoListDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TodoListId; }
    int autoValueIndex() const override { return TodoListId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("todo_list"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int todo_list_id READ gettodo_list_id WRITE settodo_list_id)
    T_DEFINE_PROPERTY(int, todo_list_id)
    Q_PROPERTY(QString todo_list_cd READ gettodo_list_cd WRITE settodo_list_cd)
    T_DEFINE_PROPERTY(QString, todo_list_cd)
    Q_PROPERTY(QString todo_list_name_zh READ gettodo_list_name_zh WRITE settodo_list_name_zh)
    T_DEFINE_PROPERTY(QString, todo_list_name_zh)
    Q_PROPERTY(QString todo_list_name_en READ gettodo_list_name_en WRITE settodo_list_name_en)
    T_DEFINE_PROPERTY(QString, todo_list_name_en)
    Q_PROPERTY(QString todo_list_tooltip READ gettodo_list_tooltip WRITE settodo_list_tooltip)
    T_DEFINE_PROPERTY(QString, todo_list_tooltip)
    Q_PROPERTY(QString todo_list_desc READ gettodo_list_desc WRITE settodo_list_desc)
    T_DEFINE_PROPERTY(QString, todo_list_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TODOLISTOBJECT_H
