#ifndef EQPPANELOBJECT_H
#define EQPPANELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPanelObject : public TSqlObject, public QSharedData
{
public:
    int panel_id {0};
    int assmbl_id {0};
    QString panel_cd;
    QString desc_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PanelId = 0,
        AssmblId,
        PanelCd,
        DescDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PanelId; }
    int autoValueIndex() const override { return PanelId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AssmblId; }
    QString tableName() const override { return QLatin1String("eqp_panel"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int panel_id READ getpanel_id WRITE setpanel_id)
    T_DEFINE_PROPERTY(int, panel_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(QString panel_cd READ getpanel_cd WRITE setpanel_cd)
    T_DEFINE_PROPERTY(QString, panel_cd)
    Q_PROPERTY(QString desc_desc READ getdesc_desc WRITE setdesc_desc)
    T_DEFINE_PROPERTY(QString, desc_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPANELOBJECT_H
