#ifndef SHIPSHIPMENTOBJECT_H
#define SHIPSHIPMENTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ShipShipmentObject : public TSqlObject, public QSharedData
{
public:
    int shipment_id {0};
    QString shipment_type_cd;
    int transportor_id {0};
    int org_id {0};
    QString waybill_no;
    QString flight_no;
    QString customs_declaration;
    QString customs_desc;
    bool confirm_receipt_bool;
    QDateTime ship_after_dt;
    QDateTime ship_dt;
    QString return_auth_no;
    double return_price {0};
    QString return_desc;
    double weight_qt {0};
    int weight_unit_id {0};
    double height_qt {0};
    int height_unit_id {0};
    double length_qt {0};
    int length_unit_id {0};
    double width_qt {0};
    int width_unit_id {0};
    int po_id {0};
    int sched_id {0};
    int account_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ShipmentId = 0,
        ShipmentTypeCd,
        TransportorId,
        OrgId,
        WaybillNo,
        FlightNo,
        CustomsDeclaration,
        CustomsDesc,
        ConfirmReceiptBool,
        ShipAfterDt,
        ShipDt,
        ReturnAuthNo,
        ReturnPrice,
        ReturnDesc,
        WeightQt,
        WeightUnitId,
        HeightQt,
        HeightUnitId,
        LengthQt,
        LengthUnitId,
        WidthQt,
        WidthUnitId,
        PoId,
        SchedId,
        AccountId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ShipmentId; }
    int autoValueIndex() const override { return ShipmentId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AccountId<<SchedId<<PoId<<WidthUnitId<<LengthUnitId<<HeightUnitId<<WeightUnitId<<OrgId<<TransportorId<<ShipmentTypeCd; }
    QString tableName() const override { return QLatin1String("ship_shipment"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int shipment_id READ getshipment_id WRITE setshipment_id)
    T_DEFINE_PROPERTY(int, shipment_id)
    Q_PROPERTY(QString shipment_type_cd READ getshipment_type_cd WRITE setshipment_type_cd)
    T_DEFINE_PROPERTY(QString, shipment_type_cd)
    Q_PROPERTY(int transportor_id READ gettransportor_id WRITE settransportor_id)
    T_DEFINE_PROPERTY(int, transportor_id)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(QString waybill_no READ getwaybill_no WRITE setwaybill_no)
    T_DEFINE_PROPERTY(QString, waybill_no)
    Q_PROPERTY(QString flight_no READ getflight_no WRITE setflight_no)
    T_DEFINE_PROPERTY(QString, flight_no)
    Q_PROPERTY(QString customs_declaration READ getcustoms_declaration WRITE setcustoms_declaration)
    T_DEFINE_PROPERTY(QString, customs_declaration)
    Q_PROPERTY(QString customs_desc READ getcustoms_desc WRITE setcustoms_desc)
    T_DEFINE_PROPERTY(QString, customs_desc)
    Q_PROPERTY(bool confirm_receipt_bool READ getconfirm_receipt_bool WRITE setconfirm_receipt_bool)
    T_DEFINE_PROPERTY(bool, confirm_receipt_bool)
    Q_PROPERTY(QDateTime ship_after_dt READ getship_after_dt WRITE setship_after_dt)
    T_DEFINE_PROPERTY(QDateTime, ship_after_dt)
    Q_PROPERTY(QDateTime ship_dt READ getship_dt WRITE setship_dt)
    T_DEFINE_PROPERTY(QDateTime, ship_dt)
    Q_PROPERTY(QString return_auth_no READ getreturn_auth_no WRITE setreturn_auth_no)
    T_DEFINE_PROPERTY(QString, return_auth_no)
    Q_PROPERTY(double return_price READ getreturn_price WRITE setreturn_price)
    T_DEFINE_PROPERTY(double, return_price)
    Q_PROPERTY(QString return_desc READ getreturn_desc WRITE setreturn_desc)
    T_DEFINE_PROPERTY(QString, return_desc)
    Q_PROPERTY(double weight_qt READ getweight_qt WRITE setweight_qt)
    T_DEFINE_PROPERTY(double, weight_qt)
    Q_PROPERTY(int weight_unit_id READ getweight_unit_id WRITE setweight_unit_id)
    T_DEFINE_PROPERTY(int, weight_unit_id)
    Q_PROPERTY(double height_qt READ getheight_qt WRITE setheight_qt)
    T_DEFINE_PROPERTY(double, height_qt)
    Q_PROPERTY(int height_unit_id READ getheight_unit_id WRITE setheight_unit_id)
    T_DEFINE_PROPERTY(int, height_unit_id)
    Q_PROPERTY(double length_qt READ getlength_qt WRITE setlength_qt)
    T_DEFINE_PROPERTY(double, length_qt)
    Q_PROPERTY(int length_unit_id READ getlength_unit_id WRITE setlength_unit_id)
    T_DEFINE_PROPERTY(int, length_unit_id)
    Q_PROPERTY(double width_qt READ getwidth_qt WRITE setwidth_qt)
    T_DEFINE_PROPERTY(double, width_qt)
    Q_PROPERTY(int width_unit_id READ getwidth_unit_id WRITE setwidth_unit_id)
    T_DEFINE_PROPERTY(int, width_unit_id)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SHIPSHIPMENTOBJECT_H
