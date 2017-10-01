#ifndef FLIGHTLEGOBJECT_H
#define FLIGHTLEGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FlightLegObject : public TSqlObject, public QSharedData
{
public:
    int leg_id {0};
    QString leg_no;
    bool hist_bool;
    QString flight_leg_status_cd;
    QDateTime actual_departure_dt;
    int departure_loc_id {0};
    int arrival_loc_id {0};
    QDateTime actual_arrival_dt;
    QDateTime recorded_dt;
    QString leg_desc;
    QString master_flight_no;
    QString ext_key;
    int aircraft_id {0};
    QString logbook_ref;
    QString departure_gate_cd;
    QString arrival_gate_cd;
    QDateTime sched_departure_dt;
    QDateTime sched_arrival_dt;
    QDateTime off_dt;
    QDateTime on_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LegId = 0,
        LegNo,
        HistBool,
        FlightLegStatusCd,
        ActualDepartureDt,
        DepartureLocId,
        ArrivalLocId,
        ActualArrivalDt,
        RecordedDt,
        LegDesc,
        MasterFlightNo,
        ExtKey,
        AircraftId,
        LogbookRef,
        DepartureGateCd,
        ArrivalGateCd,
        SchedDepartureDt,
        SchedArrivalDt,
        OffDt,
        OnDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LegId; }
    int autoValueIndex() const override { return LegId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AircraftId<<ArrivalLocId<<DepartureLocId<<FlightLegStatusCd; }
    QString tableName() const override { return QLatin1String("flight_leg"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int leg_id READ getleg_id WRITE setleg_id)
    T_DEFINE_PROPERTY(int, leg_id)
    Q_PROPERTY(QString leg_no READ getleg_no WRITE setleg_no)
    T_DEFINE_PROPERTY(QString, leg_no)
    Q_PROPERTY(bool hist_bool READ gethist_bool WRITE sethist_bool)
    T_DEFINE_PROPERTY(bool, hist_bool)
    Q_PROPERTY(QString flight_leg_status_cd READ getflight_leg_status_cd WRITE setflight_leg_status_cd)
    T_DEFINE_PROPERTY(QString, flight_leg_status_cd)
    Q_PROPERTY(QDateTime actual_departure_dt READ getactual_departure_dt WRITE setactual_departure_dt)
    T_DEFINE_PROPERTY(QDateTime, actual_departure_dt)
    Q_PROPERTY(int departure_loc_id READ getdeparture_loc_id WRITE setdeparture_loc_id)
    T_DEFINE_PROPERTY(int, departure_loc_id)
    Q_PROPERTY(int arrival_loc_id READ getarrival_loc_id WRITE setarrival_loc_id)
    T_DEFINE_PROPERTY(int, arrival_loc_id)
    Q_PROPERTY(QDateTime actual_arrival_dt READ getactual_arrival_dt WRITE setactual_arrival_dt)
    T_DEFINE_PROPERTY(QDateTime, actual_arrival_dt)
    Q_PROPERTY(QDateTime recorded_dt READ getrecorded_dt WRITE setrecorded_dt)
    T_DEFINE_PROPERTY(QDateTime, recorded_dt)
    Q_PROPERTY(QString leg_desc READ getleg_desc WRITE setleg_desc)
    T_DEFINE_PROPERTY(QString, leg_desc)
    Q_PROPERTY(QString master_flight_no READ getmaster_flight_no WRITE setmaster_flight_no)
    T_DEFINE_PROPERTY(QString, master_flight_no)
    Q_PROPERTY(QString ext_key READ getext_key WRITE setext_key)
    T_DEFINE_PROPERTY(QString, ext_key)
    Q_PROPERTY(int aircraft_id READ getaircraft_id WRITE setaircraft_id)
    T_DEFINE_PROPERTY(int, aircraft_id)
    Q_PROPERTY(QString logbook_ref READ getlogbook_ref WRITE setlogbook_ref)
    T_DEFINE_PROPERTY(QString, logbook_ref)
    Q_PROPERTY(QString departure_gate_cd READ getdeparture_gate_cd WRITE setdeparture_gate_cd)
    T_DEFINE_PROPERTY(QString, departure_gate_cd)
    Q_PROPERTY(QString arrival_gate_cd READ getarrival_gate_cd WRITE setarrival_gate_cd)
    T_DEFINE_PROPERTY(QString, arrival_gate_cd)
    Q_PROPERTY(QDateTime sched_departure_dt READ getsched_departure_dt WRITE setsched_departure_dt)
    T_DEFINE_PROPERTY(QDateTime, sched_departure_dt)
    Q_PROPERTY(QDateTime sched_arrival_dt READ getsched_arrival_dt WRITE setsched_arrival_dt)
    T_DEFINE_PROPERTY(QDateTime, sched_arrival_dt)
    Q_PROPERTY(QDateTime off_dt READ getoff_dt WRITE setoff_dt)
    T_DEFINE_PROPERTY(QDateTime, off_dt)
    Q_PROPERTY(QDateTime on_dt READ geton_dt WRITE seton_dt)
    T_DEFINE_PROPERTY(QDateTime, on_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FLIGHTLEGOBJECT_H
