#ifndef MENUOBJECT_H
#define MENUOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MenuObject : public TSqlObject, public QSharedData
{
public:
    int menu_id {0};
    QString menu_cd;
    QString menu_name_zh;
    QString menu_name_en;
    QString menu_tooltip;
    QString menu_desc;
    QString controller;
    QString action;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MenuId = 0,
        MenuCd,
        MenuNameZh,
        MenuNameEn,
        MenuTooltip,
        MenuDesc,
        Controller,
        Action,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MenuId; }
    int autoValueIndex() const override { return MenuId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("menu"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int menu_id READ getmenu_id WRITE setmenu_id)
    T_DEFINE_PROPERTY(int, menu_id)
    Q_PROPERTY(QString menu_cd READ getmenu_cd WRITE setmenu_cd)
    T_DEFINE_PROPERTY(QString, menu_cd)
    Q_PROPERTY(QString menu_name_zh READ getmenu_name_zh WRITE setmenu_name_zh)
    T_DEFINE_PROPERTY(QString, menu_name_zh)
    Q_PROPERTY(QString menu_name_en READ getmenu_name_en WRITE setmenu_name_en)
    T_DEFINE_PROPERTY(QString, menu_name_en)
    Q_PROPERTY(QString menu_tooltip READ getmenu_tooltip WRITE setmenu_tooltip)
    T_DEFINE_PROPERTY(QString, menu_tooltip)
    Q_PROPERTY(QString menu_desc READ getmenu_desc WRITE setmenu_desc)
    T_DEFINE_PROPERTY(QString, menu_desc)
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MENUOBJECT_H
