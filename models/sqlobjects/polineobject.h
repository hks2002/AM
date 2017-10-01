#ifndef POLINEOBJECT_H
#define POLINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoLineObject : public TSqlObject, public QSharedData
{
public:
    int po_line_id {0};
    int po_id {0};
    int line_no_ord {0};
    QString line_desc;
    int part_no_id {0};
    QString po_line_type_cd;
    int order_qt {0};
    int qty_unit_id {0};
    QString price_type_cd;
    double base_unit_price {0};
    double unit_price {0};
    double orig_unit_price {0};
    double line_price {0};
    double accrued_value {0};
    QDateTime promise_dt;
    bool confirm_promise_by_bool;
    int received_qt {0};
    int invoice_qt {0};
    int pre_insp_qt {0};
    QDateTime orig_promise_dt;
    bool maint_pickup_bool;
    QDateTime received_dt;
    QDateTime return_dt;
    QString note_to_vendor;
    QString note_to_receiver;
    bool warranty_bool;
    bool line_deleted_bool;
    int owner_id {0};
    int sched_id {0};
    int shipment_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoLineId = 0,
        PoId,
        LineNoOrd,
        LineDesc,
        PartNoId,
        PoLineTypeCd,
        OrderQt,
        QtyUnitId,
        PriceTypeCd,
        BaseUnitPrice,
        UnitPrice,
        OrigUnitPrice,
        LinePrice,
        AccruedValue,
        PromiseDt,
        ConfirmPromiseByBool,
        ReceivedQt,
        InvoiceQt,
        PreInspQt,
        OrigPromiseDt,
        MaintPickupBool,
        ReceivedDt,
        ReturnDt,
        NoteToVendor,
        NoteToReceiver,
        WarrantyBool,
        LineDeletedBool,
        OwnerId,
        SchedId,
        ShipmentId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoLineId; }
    int autoValueIndex() const override { return PoLineId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ShipmentId<<SchedId<<OwnerId<<PriceTypeCd<<QtyUnitId<<PoLineTypeCd<<PartNoId<<PoId; }
    QString tableName() const override { return QLatin1String("po_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int line_no_ord READ getline_no_ord WRITE setline_no_ord)
    T_DEFINE_PROPERTY(int, line_no_ord)
    Q_PROPERTY(QString line_desc READ getline_desc WRITE setline_desc)
    T_DEFINE_PROPERTY(QString, line_desc)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString po_line_type_cd READ getpo_line_type_cd WRITE setpo_line_type_cd)
    T_DEFINE_PROPERTY(QString, po_line_type_cd)
    Q_PROPERTY(int order_qt READ getorder_qt WRITE setorder_qt)
    T_DEFINE_PROPERTY(int, order_qt)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(QString price_type_cd READ getprice_type_cd WRITE setprice_type_cd)
    T_DEFINE_PROPERTY(QString, price_type_cd)
    Q_PROPERTY(double base_unit_price READ getbase_unit_price WRITE setbase_unit_price)
    T_DEFINE_PROPERTY(double, base_unit_price)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(double orig_unit_price READ getorig_unit_price WRITE setorig_unit_price)
    T_DEFINE_PROPERTY(double, orig_unit_price)
    Q_PROPERTY(double line_price READ getline_price WRITE setline_price)
    T_DEFINE_PROPERTY(double, line_price)
    Q_PROPERTY(double accrued_value READ getaccrued_value WRITE setaccrued_value)
    T_DEFINE_PROPERTY(double, accrued_value)
    Q_PROPERTY(QDateTime promise_dt READ getpromise_dt WRITE setpromise_dt)
    T_DEFINE_PROPERTY(QDateTime, promise_dt)
    Q_PROPERTY(bool confirm_promise_by_bool READ getconfirm_promise_by_bool WRITE setconfirm_promise_by_bool)
    T_DEFINE_PROPERTY(bool, confirm_promise_by_bool)
    Q_PROPERTY(int received_qt READ getreceived_qt WRITE setreceived_qt)
    T_DEFINE_PROPERTY(int, received_qt)
    Q_PROPERTY(int invoice_qt READ getinvoice_qt WRITE setinvoice_qt)
    T_DEFINE_PROPERTY(int, invoice_qt)
    Q_PROPERTY(int pre_insp_qt READ getpre_insp_qt WRITE setpre_insp_qt)
    T_DEFINE_PROPERTY(int, pre_insp_qt)
    Q_PROPERTY(QDateTime orig_promise_dt READ getorig_promise_dt WRITE setorig_promise_dt)
    T_DEFINE_PROPERTY(QDateTime, orig_promise_dt)
    Q_PROPERTY(bool maint_pickup_bool READ getmaint_pickup_bool WRITE setmaint_pickup_bool)
    T_DEFINE_PROPERTY(bool, maint_pickup_bool)
    Q_PROPERTY(QDateTime received_dt READ getreceived_dt WRITE setreceived_dt)
    T_DEFINE_PROPERTY(QDateTime, received_dt)
    Q_PROPERTY(QDateTime return_dt READ getreturn_dt WRITE setreturn_dt)
    T_DEFINE_PROPERTY(QDateTime, return_dt)
    Q_PROPERTY(QString note_to_vendor READ getnote_to_vendor WRITE setnote_to_vendor)
    T_DEFINE_PROPERTY(QString, note_to_vendor)
    Q_PROPERTY(QString note_to_receiver READ getnote_to_receiver WRITE setnote_to_receiver)
    T_DEFINE_PROPERTY(QString, note_to_receiver)
    Q_PROPERTY(bool warranty_bool READ getwarranty_bool WRITE setwarranty_bool)
    T_DEFINE_PROPERTY(bool, warranty_bool)
    Q_PROPERTY(bool line_deleted_bool READ getline_deleted_bool WRITE setline_deleted_bool)
    T_DEFINE_PROPERTY(bool, line_deleted_bool)
    Q_PROPERTY(int owner_id READ getowner_id WRITE setowner_id)
    T_DEFINE_PROPERTY(int, owner_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int shipment_id READ getshipment_id WRITE setshipment_id)
    T_DEFINE_PROPERTY(int, shipment_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // POLINEOBJECT_H
