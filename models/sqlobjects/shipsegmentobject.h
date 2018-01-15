#ifndef SHIPSEGMENTOBJECT_H
#define SHIPSEGMENTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ShipSegmentObject : public TSqlObject, public QSharedData
{
public:
    int segment_id {0};
    int shipment_id {0};
    int segment_ord {0};
    QString segment_status_cd;
    QString waybill_no;
    QString customs_desc;
    int ship_from_id {0};
    int ship_to_id {0};
    int complete_by {0};
    QDateTime complete_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SegmentId = 0,
        ShipmentId,
        SegmentOrd,
        SegmentStatusCd,
        WaybillNo,
        CustomsDesc,
        ShipFromId,
        ShipToId,
        CompleteBy,
        CompleteDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SegmentId; }
    int autoValueIndex() const override { return SegmentId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CompleteBy<<ShipToId<<ShipFromId<<SegmentStatusCd<<ShipmentId; }
    QString tableName() const override { return QLatin1String("ship_segment"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int segment_id READ getsegment_id WRITE setsegment_id)
    T_DEFINE_PROPERTY(int, segment_id)
    Q_PROPERTY(int shipment_id READ getshipment_id WRITE setshipment_id)
    T_DEFINE_PROPERTY(int, shipment_id)
    Q_PROPERTY(int segment_ord READ getsegment_ord WRITE setsegment_ord)
    T_DEFINE_PROPERTY(int, segment_ord)
    Q_PROPERTY(QString segment_status_cd READ getsegment_status_cd WRITE setsegment_status_cd)
    T_DEFINE_PROPERTY(QString, segment_status_cd)
    Q_PROPERTY(QString waybill_no READ getwaybill_no WRITE setwaybill_no)
    T_DEFINE_PROPERTY(QString, waybill_no)
    Q_PROPERTY(QString customs_desc READ getcustoms_desc WRITE setcustoms_desc)
    T_DEFINE_PROPERTY(QString, customs_desc)
    Q_PROPERTY(int ship_from_id READ getship_from_id WRITE setship_from_id)
    T_DEFINE_PROPERTY(int, ship_from_id)
    Q_PROPERTY(int ship_to_id READ getship_to_id WRITE setship_to_id)
    T_DEFINE_PROPERTY(int, ship_to_id)
    Q_PROPERTY(int complete_by READ getcomplete_by WRITE setcomplete_by)
    T_DEFINE_PROPERTY(int, complete_by)
    Q_PROPERTY(QDateTime complete_dt READ getcomplete_dt WRITE setcomplete_dt)
    T_DEFINE_PROPERTY(QDateTime, complete_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // SHIPSEGMENTOBJECT_H
