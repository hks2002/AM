#ifndef VTODOLISTTABROLEOBJECT_H
#define VTODOLISTTABROLEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VTodoListTabRoleObject : public TSqlObject, public QSharedData
{
public:
    int role_id {0};
    int todo_list_order {0};
    int todo_list_id {0};
    QString todo_list_cd;
    QString todo_list_name_zh;
    QString todo_list_name_en;
    QString todo_list_tooltip;
    QString todo_list_desc;
    int tab_id {0};
    int tab_order {0};
    QString tab_cd;
    QString tab_name_zh;
    QString tab_name_en;
    QString tab_tooltip;
    QString tab_desc;
    QString controller;
    QString action;

    enum PropertyIndex {
        RoleId = 0,
        TodoListOrder,
        TodoListId,
        TodoListCd,
        TodoListNameZh,
        TodoListNameEn,
        TodoListTooltip,
        TodoListDesc,
        TabId,
        TabOrder,
        TabCd,
        TabNameZh,
        TabNameEn,
        TabTooltip,
        TabDesc,
        Controller,
        Action,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList; return fkIdxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_todo_list_tab_role"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int role_id READ getrole_id WRITE setrole_id)
    T_DEFINE_PROPERTY(int, role_id)
    Q_PROPERTY(int todo_list_order READ gettodo_list_order WRITE settodo_list_order)
    T_DEFINE_PROPERTY(int, todo_list_order)
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
    Q_PROPERTY(int tab_id READ gettab_id WRITE settab_id)
    T_DEFINE_PROPERTY(int, tab_id)
    Q_PROPERTY(int tab_order READ gettab_order WRITE settab_order)
    T_DEFINE_PROPERTY(int, tab_order)
    Q_PROPERTY(QString tab_cd READ gettab_cd WRITE settab_cd)
    T_DEFINE_PROPERTY(QString, tab_cd)
    Q_PROPERTY(QString tab_name_zh READ gettab_name_zh WRITE settab_name_zh)
    T_DEFINE_PROPERTY(QString, tab_name_zh)
    Q_PROPERTY(QString tab_name_en READ gettab_name_en WRITE settab_name_en)
    T_DEFINE_PROPERTY(QString, tab_name_en)
    Q_PROPERTY(QString tab_tooltip READ gettab_tooltip WRITE settab_tooltip)
    T_DEFINE_PROPERTY(QString, tab_tooltip)
    Q_PROPERTY(QString tab_desc READ gettab_desc WRITE settab_desc)
    T_DEFINE_PROPERTY(QString, tab_desc)
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
};


#endif // VTODOLISTTABROLEOBJECT_H
