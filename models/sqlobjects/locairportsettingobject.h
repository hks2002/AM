#ifndef LOCAIRPORTSETTINGOBJECT_H
#define LOCAIRPORTSETTINGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocAirportSettingObject : public TSqlObject, public QSharedData
{
public:
    int loc_id {0};
    QString timezone_cd;
    bool supply_bool;
    int inbound_flight_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocId = 0,
        TimezoneCd,
        SupplyBool,
        InboundFlightQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LocId; }
    QString tableName() const override { return QLatin1String("loc_airport_setting"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(QString timezone_cd READ gettimezone_cd WRITE settimezone_cd)
    T_DEFINE_PROPERTY(QString, timezone_cd)
    Q_PROPERTY(bool supply_bool READ getsupply_bool WRITE setsupply_bool)
    T_DEFINE_PROPERTY(bool, supply_bool)
    Q_PROPERTY(int inbound_flight_qt READ getinbound_flight_qt WRITE setinbound_flight_qt)
    T_DEFINE_PROPERTY(int, inbound_flight_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // LOCAIRPORTSETTINGOBJECT_H
