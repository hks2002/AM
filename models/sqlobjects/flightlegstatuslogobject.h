#ifndef FLIGHTLEGSTATUSLOGOBJECT_H
#define FLIGHTLEGSTATUSLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FlightLegStatusLogObject : public TSqlObject, public QSharedData
{
public:
    int leg_status_log_id {0};
    int leg_id {0};
    QDateTime log_dt;
    QString flight_leg_status_cd;
    bool system_bool;
    int log_by {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LegStatusLogId = 0,
        LegId,
        LogDt,
        FlightLegStatusCd,
        SystemBool,
        LogBy,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LegStatusLogId; }
    int autoValueIndex() const override { return LegStatusLogId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LogBy<<LegId; }
    QString tableName() const override { return QLatin1String("flight_leg_status_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int leg_status_log_id READ getleg_status_log_id WRITE setleg_status_log_id)
    T_DEFINE_PROPERTY(int, leg_status_log_id)
    Q_PROPERTY(int leg_id READ getleg_id WRITE setleg_id)
    T_DEFINE_PROPERTY(int, leg_id)
    Q_PROPERTY(QDateTime log_dt READ getlog_dt WRITE setlog_dt)
    T_DEFINE_PROPERTY(QDateTime, log_dt)
    Q_PROPERTY(QString flight_leg_status_cd READ getflight_leg_status_cd WRITE setflight_leg_status_cd)
    T_DEFINE_PROPERTY(QString, flight_leg_status_cd)
    Q_PROPERTY(bool system_bool READ getsystem_bool WRITE setsystem_bool)
    T_DEFINE_PROPERTY(bool, system_bool)
    Q_PROPERTY(int log_by READ getlog_by WRITE setlog_by)
    T_DEFINE_PROPERTY(int, log_by)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FLIGHTLEGSTATUSLOGOBJECT_H
