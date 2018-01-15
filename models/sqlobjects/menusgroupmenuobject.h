#ifndef MENUSGROUPMENUOBJECT_H
#define MENUSGROUPMENUOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MenusGroupMenuObject : public TSqlObject, public QSharedData
{
public:
    int menus_group_id {0};
    int menu_id {0};
    bool break_bool;
    int menu_order {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MenusGroupId = 0,
        MenuId,
        BreakBool,
        MenuOrder,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MenusGroupId<<MenuId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<MenuId<<MenusGroupId; }
    QString tableName() const override { return QLatin1String("menus_group_menu"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int menus_group_id READ getmenus_group_id WRITE setmenus_group_id)
    T_DEFINE_PROPERTY(int, menus_group_id)
    Q_PROPERTY(int menu_id READ getmenu_id WRITE setmenu_id)
    T_DEFINE_PROPERTY(int, menu_id)
    Q_PROPERTY(bool break_bool READ getbreak_bool WRITE setbreak_bool)
    T_DEFINE_PROPERTY(bool, break_bool)
    Q_PROPERTY(int menu_order READ getmenu_order WRITE setmenu_order)
    T_DEFINE_PROPERTY(int, menu_order)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MENUSGROUPMENUOBJECT_H
