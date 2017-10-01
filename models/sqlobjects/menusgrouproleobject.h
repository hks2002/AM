#ifndef MENUSGROUPROLEOBJECT_H
#define MENUSGROUPROLEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MenusGroupRoleObject : public TSqlObject, public QSharedData
{
public:
    int menus_group_id {0};
    int role_id {0};
    int menus_group_order {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MenusGroupId = 0,
        RoleId,
        MenusGroupOrder,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MenusGroupId<<RoleId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RoleId<<MenusGroupId; }
    QString tableName() const override { return QLatin1String("menus_group_role"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int menus_group_id READ getmenus_group_id WRITE setmenus_group_id)
    T_DEFINE_PROPERTY(int, menus_group_id)
    Q_PROPERTY(int role_id READ getrole_id WRITE setrole_id)
    T_DEFINE_PROPERTY(int, role_id)
    Q_PROPERTY(int menus_group_order READ getmenus_group_order WRITE setmenus_group_order)
    T_DEFINE_PROPERTY(int, menus_group_order)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // MENUSGROUPROLEOBJECT_H
