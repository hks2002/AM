#ifndef EQPZONEPANELOBJECT_H
#define EQPZONEPANELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpZonePanelObject : public TSqlObject, public QSharedData
{
public:
    int zone_panel_id {0};
    int assmbl_id {0};
    int zone_id {0};
    int panel_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ZonePanelId = 0,
        AssmblId,
        ZoneId,
        PanelId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ZonePanelId; }
    int autoValueIndex() const override { return ZonePanelId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PanelId<<ZoneId<<AssmblId; }
    QString tableName() const override { return QLatin1String("eqp_zone_panel"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int zone_panel_id READ getzone_panel_id WRITE setzone_panel_id)
    T_DEFINE_PROPERTY(int, zone_panel_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int zone_id READ getzone_id WRITE setzone_id)
    T_DEFINE_PROPERTY(int, zone_id)
    Q_PROPERTY(int panel_id READ getpanel_id WRITE setpanel_id)
    T_DEFINE_PROPERTY(int, panel_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPZONEPANELOBJECT_H
