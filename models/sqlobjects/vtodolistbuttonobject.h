#ifndef VTODOLISTBUTTONOBJECT_H
#define VTODOLISTBUTTONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VTodoListButtonObject : public TSqlObject, public QSharedData
{
public:
    int todo_list_id {0};
    QString todo_list_cd;
    QString todo_list_name_zh;
    QString todo_list_name_en;
    QString todo_list_tooltip;
    QString todo_list_desc;
    int button_id {0};
    int button_order {0};
    QString button_cd;
    QString button_name_zh;
    QString button_name_en;
    QString button_tooltip;
    QString button_desc;
    QString controller;
    QString action;

    enum PropertyIndex {
        TodoListId = 0,
        TodoListCd,
        TodoListNameZh,
        TodoListNameEn,
        TodoListTooltip,
        TodoListDesc,
        ButtonId,
        ButtonOrder,
        ButtonCd,
        ButtonNameZh,
        ButtonNameEn,
        ButtonTooltip,
        ButtonDesc,
        Controller,
        Action,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList; return fkIdxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_todo_list_button"); }

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
    Q_PROPERTY(int button_id READ getbutton_id WRITE setbutton_id)
    T_DEFINE_PROPERTY(int, button_id)
    Q_PROPERTY(int button_order READ getbutton_order WRITE setbutton_order)
    T_DEFINE_PROPERTY(int, button_order)
    Q_PROPERTY(QString button_cd READ getbutton_cd WRITE setbutton_cd)
    T_DEFINE_PROPERTY(QString, button_cd)
    Q_PROPERTY(QString button_name_zh READ getbutton_name_zh WRITE setbutton_name_zh)
    T_DEFINE_PROPERTY(QString, button_name_zh)
    Q_PROPERTY(QString button_name_en READ getbutton_name_en WRITE setbutton_name_en)
    T_DEFINE_PROPERTY(QString, button_name_en)
    Q_PROPERTY(QString button_tooltip READ getbutton_tooltip WRITE setbutton_tooltip)
    T_DEFINE_PROPERTY(QString, button_tooltip)
    Q_PROPERTY(QString button_desc READ getbutton_desc WRITE setbutton_desc)
    T_DEFINE_PROPERTY(QString, button_desc)
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
};


#endif // VTODOLISTBUTTONOBJECT_H
