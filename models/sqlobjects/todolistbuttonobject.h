#ifndef TODOLISTBUTTONOBJECT_H
#define TODOLISTBUTTONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TodoListButtonObject : public TSqlObject, public QSharedData
{
public:
    int todo_list_id {0};
    int button_id {0};
    int button_order {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TodoListId = 0,
        ButtonId,
        ButtonOrder,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TodoListId<<ButtonId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ButtonId<<TodoListId; }
    QString tableName() const override { return QLatin1String("todo_list_button"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int todo_list_id READ gettodo_list_id WRITE settodo_list_id)
    T_DEFINE_PROPERTY(int, todo_list_id)
    Q_PROPERTY(int button_id READ getbutton_id WRITE setbutton_id)
    T_DEFINE_PROPERTY(int, button_id)
    Q_PROPERTY(int button_order READ getbutton_order WRITE setbutton_order)
    T_DEFINE_PROPERTY(int, button_order)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TODOLISTBUTTONOBJECT_H
