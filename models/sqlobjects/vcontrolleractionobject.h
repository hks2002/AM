#ifndef VCONTROLLERACTIONOBJECT_H
#define VCONTROLLERACTIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VControllerActionObject : public TSqlObject, public QSharedData
{
public:
    QString controller;
    QString action;

    enum PropertyIndex {
        Controller = 0,
        Action,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("v_controller_action"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
};

#endif // VCONTROLLERACTIONOBJECT_H
