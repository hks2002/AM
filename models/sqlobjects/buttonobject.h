#ifndef BUTTONOBJECT_H
#define BUTTONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ButtonObject : public TSqlObject, public QSharedData
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
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ButtonId = 0,
        ButtonCd,
        ButtonNameZh,
        ButtonNameEn,
        ButtonTooltip,
        ButtonDesc,
        Controller,
        Action,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ButtonId; }
    int autoValueIndex() const override { return ButtonId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("button"); }

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
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // BUTTONOBJECT_H
