#ifndef VBUTTONUSEROBJECT_H
#define VBUTTONUSEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VButtonUserObject : public TSqlObject, public QSharedData
{
public:
    int button_id {0};
    QString button_cd;
    QString button_name_zh;
    QString button_name_en;
    QString button_tooltip;
    QString button_desc;
    QString controller;
    QString action;
    int user_id {0};
    int todo_list_order {0};
    int button_order {0};

    enum PropertyIndex {
        ButtonId = 0,
        ButtonCd,
        ButtonNameZh,
        ButtonNameEn,
        ButtonTooltip,
        ButtonDesc,
        Controller,
        Action,
        UserId,
        TodoListOrder,
        ButtonOrder,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_button_user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int button_id READ getbutton_id WRITE setbutton_id)
    T_DEFINE_PROPERTY(int, button_id)
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
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int todo_list_order READ gettodo_list_order WRITE settodo_list_order)
    T_DEFINE_PROPERTY(int, todo_list_order)
    Q_PROPERTY(int button_order READ getbutton_order WRITE setbutton_order)
    T_DEFINE_PROPERTY(int, button_order)
};

#endif // VBUTTONUSEROBJECT_H