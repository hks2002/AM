#ifndef TABOBJECT_H
#define TABOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TabObject : public TSqlObject, public QSharedData
{
public:
    int tab_id {0};
    QString tab_cd;
    QString tab_name_zh;
    QString tab_name_en;
    QString tab_tooltip;
    QString tab_desc;
    QString controller;
    QString action;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TabId = 0,
        TabCd,
        TabNameZh,
        TabNameEn,
        TabTooltip,
        TabDesc,
        Controller,
        Action,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TabId; }
    int autoValueIndex() const override { return TabId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("tab"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int tab_id READ gettab_id WRITE settab_id)
    T_DEFINE_PROPERTY(int, tab_id)
    Q_PROPERTY(QString tab_cd READ gettab_cd WRITE settab_cd)
    T_DEFINE_PROPERTY(QString, tab_cd)
    Q_PROPERTY(QString tab_name_zh READ gettab_name_zh WRITE settab_name_zh)
    T_DEFINE_PROPERTY(QString, tab_name_zh)
    Q_PROPERTY(QString tab_name_en READ gettab_name_en WRITE settab_name_en)
    T_DEFINE_PROPERTY(QString, tab_name_en)
    Q_PROPERTY(QString tab_tooltip READ gettab_tooltip WRITE settab_tooltip)
    T_DEFINE_PROPERTY(QString, tab_tooltip)
    Q_PROPERTY(QString tab_desc READ gettab_desc WRITE settab_desc)
    T_DEFINE_PROPERTY(QString, tab_desc)
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

#endif // TABOBJECT_H
