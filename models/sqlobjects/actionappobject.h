#ifndef ACTIONAPPOBJECT_H
#define ACTIONAPPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ActionAppObject : public TSqlObject, public QSharedData
{
public:
    int action_id {0};
    QString action_cd;
    QString action_name_zh;
    QString action_name_en;
    QString action_tooltip;
    QString action_desc;
    QString action_type_zh;
    QString action_type_en;
    QString controller;
    QString action;
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ActionId = 0,
        ActionCd,
        ActionNameZh,
        ActionNameEn,
        ActionTooltip,
        ActionDesc,
        ActionTypeZh,
        ActionTypeEn,
        Controller,
        Action,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ActionId; }
    int autoValueIndex() const override { return ActionId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("action_app"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int action_id READ getaction_id WRITE setaction_id)
    T_DEFINE_PROPERTY(int, action_id)
    Q_PROPERTY(QString action_cd READ getaction_cd WRITE setaction_cd)
    T_DEFINE_PROPERTY(QString, action_cd)
    Q_PROPERTY(QString action_name_zh READ getaction_name_zh WRITE setaction_name_zh)
    T_DEFINE_PROPERTY(QString, action_name_zh)
    Q_PROPERTY(QString action_name_en READ getaction_name_en WRITE setaction_name_en)
    T_DEFINE_PROPERTY(QString, action_name_en)
    Q_PROPERTY(QString action_tooltip READ getaction_tooltip WRITE setaction_tooltip)
    T_DEFINE_PROPERTY(QString, action_tooltip)
    Q_PROPERTY(QString action_desc READ getaction_desc WRITE setaction_desc)
    T_DEFINE_PROPERTY(QString, action_desc)
    Q_PROPERTY(QString action_type_zh READ getaction_type_zh WRITE setaction_type_zh)
    T_DEFINE_PROPERTY(QString, action_type_zh)
    Q_PROPERTY(QString action_type_en READ getaction_type_en WRITE setaction_type_en)
    T_DEFINE_PROPERTY(QString, action_type_en)
    Q_PROPERTY(QString controller READ getcontroller WRITE setcontroller)
    T_DEFINE_PROPERTY(QString, controller)
    Q_PROPERTY(QString action READ getaction WRITE setaction)
    T_DEFINE_PROPERTY(QString, action)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ACTIONAPPOBJECT_H
