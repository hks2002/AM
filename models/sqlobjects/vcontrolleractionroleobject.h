#ifndef VCONTROLLERACTIONROLEOBJECT_H
#define VCONTROLLERACTIONROLEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VControllerActionRoleObject : public TSqlObject, public QSharedData
{
public:
    QString controller;
    QString action;
    int role_id {0};

    enum PropertyIndex {
        Controller = 0,
        Action,
        RoleId,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_controller_action_role"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
    Q_PROPERTY(int role_id READ getrole_id WRITE setrole_id)
    T_DEFINE_PROPERTY(int, role_id)
};

#endif // VCONTROLLERACTIONROLEOBJECT_H
