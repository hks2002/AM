#ifndef MENUSGROUPOBJECT_H
#define MENUSGROUPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MenusGroupObject : public TSqlObject, public QSharedData
{
public:
    int menus_group_id {0};
    QString menus_group_cd;
    QString menus_group_name_zh;
    QString menus_group_name_en;
    QString menus_group_tooltip;
    QString menus_group_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MenusGroupId = 0,
        MenusGroupCd,
        MenusGroupNameZh,
        MenusGroupNameEn,
        MenusGroupTooltip,
        MenusGroupDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MenusGroupId; }
    int autoValueIndex() const override { return MenusGroupId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("menus_group"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int menus_group_id READ getmenus_group_id WRITE setmenus_group_id)
    T_DEFINE_PROPERTY(int, menus_group_id)
    Q_PROPERTY(QString menus_group_cd READ getmenus_group_cd WRITE setmenus_group_cd)
    T_DEFINE_PROPERTY(QString, menus_group_cd)
    Q_PROPERTY(QString menus_group_name_zh READ getmenus_group_name_zh WRITE setmenus_group_name_zh)
    T_DEFINE_PROPERTY(QString, menus_group_name_zh)
    Q_PROPERTY(QString menus_group_name_en READ getmenus_group_name_en WRITE setmenus_group_name_en)
    T_DEFINE_PROPERTY(QString, menus_group_name_en)
    Q_PROPERTY(QString menus_group_tooltip READ getmenus_group_tooltip WRITE setmenus_group_tooltip)
    T_DEFINE_PROPERTY(QString, menus_group_tooltip)
    Q_PROPERTY(QString menus_group_desc READ getmenus_group_desc WRITE setmenus_group_desc)
    T_DEFINE_PROPERTY(QString, menus_group_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // MENUSGROUPOBJECT_H
