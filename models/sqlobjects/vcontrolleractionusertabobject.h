#ifndef VCONTROLLERACTIONUSERTABOBJECT_H
#define VCONTROLLERACTIONUSERTABOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VControllerActionUserTabObject : public TSqlObject, public QSharedData
{
public:
    QString controller;
    QString action;
    int user_id {0};

    enum PropertyIndex {
        Controller = 0,
        Action,
        UserId,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_controller_action_user_tab"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
};


#endif // VCONTROLLERACTIONUSERTABOBJECT_H
