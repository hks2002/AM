#ifndef VTABUSEROBJECT_H
#define VTABUSEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VTabUserObject : public TSqlObject, public QSharedData
{
public:
    int tab_id {0};
    QString tab_cd;
    QString tab_name_zh;
    QString tab_name_en;
    QString tab_tooltip;
    QString tab_desc;
    QString controller;
    QString action;
    int user_id {0};
    int todo_list_order {0};
    int tab_order {0};

    enum PropertyIndex {
        TabId = 0,
        TabCd,
        TabNameZh,
        TabNameEn,
        TabTooltip,
        TabDesc,
        Controller,
        Action,
        UserId,
        TodoListOrder,
        TabOrder,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_tab_user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int tab_id READ gettab_id WRITE settab_id)
    T_DEFINE_PROPERTY(int, tab_id)
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
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int todo_list_order READ gettodo_list_order WRITE settodo_list_order)
    T_DEFINE_PROPERTY(int, todo_list_order)
    Q_PROPERTY(int tab_order READ gettab_order WRITE settab_order)
    T_DEFINE_PROPERTY(int, tab_order)
};

#endif // VTABUSEROBJECT_H
