#ifndef REQPARTOBJECT_H
#define REQPARTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ReqPartObject : public TSqlObject, public QSharedData
{
public:
    int req_part_id {0};
    QString req_type_cd;
    QString req_priority_cd;
    int part_no_id {0};
    int assmbl_id {0};
    int assmbl_bom_id {0};
    int stock_id {0};
    int loc_id {0};
    bool lock_reserve_bool;
    int inv_no_id {0};
    QDateTime est_arrival_dt;
    QString part_provider_type_cd;
    bool ma_track_bool;
    int account_id {0};
    double issue_unit_price {0};
    QString req_master_id;
    QString req_note;
    QDateTime req_qt;
    QDateTime req_dt;
    int sched_id {0};
    int sched_inst_part_id {0};
    int sched_part_id {0};
    int shipment_line_id {0};
    int po_id {0};
    int po_line_id {0};
    int csgn_vendor_id {0};
    int csgn_owed_qt {0};
    int assigned_to {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ReqPartId = 0,
        ReqTypeCd,
        ReqPriorityCd,
        PartNoId,
        AssmblId,
        AssmblBomId,
        StockId,
        LocId,
        LockReserveBool,
        InvNoId,
        EstArrivalDt,
        PartProviderTypeCd,
        MaTrackBool,
        AccountId,
        IssueUnitPrice,
        ReqMasterId,
        ReqNote,
        ReqQt,
        ReqDt,
        SchedId,
        SchedInstPartId,
        SchedPartId,
        ShipmentLineId,
        PoId,
        PoLineId,
        CsgnVendorId,
        CsgnOwedQt,
        AssignedTo,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ReqPartId; }
    int autoValueIndex() const override { return ReqPartId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ReqTypeCd<<ReqPriorityCd<<PartNoId<<AssmblId<<AssmblBomId<<StockId<<LocId<<InvNoId<<PartProviderTypeCd<<AccountId<<SchedId<<SchedInstPartId<<SchedPartId<<ShipmentLineId<<PoId<<PoLineId<<CsgnVendorId<<AssignedTo; }
    QString tableName() const override { return QLatin1String("req_part"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int req_part_id READ getreq_part_id WRITE setreq_part_id)
    T_DEFINE_PROPERTY(int, req_part_id)
    Q_PROPERTY(QString req_type_cd READ getreq_type_cd WRITE setreq_type_cd)
    T_DEFINE_PROPERTY(QString, req_type_cd)
    Q_PROPERTY(QString req_priority_cd READ getreq_priority_cd WRITE setreq_priority_cd)
    T_DEFINE_PROPERTY(QString, req_priority_cd)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int stock_id READ getstock_id WRITE setstock_id)
    T_DEFINE_PROPERTY(int, stock_id)
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(bool lock_reserve_bool READ getlock_reserve_bool WRITE setlock_reserve_bool)
    T_DEFINE_PROPERTY(bool, lock_reserve_bool)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QDateTime est_arrival_dt READ getest_arrival_dt WRITE setest_arrival_dt)
    T_DEFINE_PROPERTY(QDateTime, est_arrival_dt)
    Q_PROPERTY(QString part_provider_type_cd READ getpart_provider_type_cd WRITE setpart_provider_type_cd)
    T_DEFINE_PROPERTY(QString, part_provider_type_cd)
    Q_PROPERTY(bool ma_track_bool READ getma_track_bool WRITE setma_track_bool)
    T_DEFINE_PROPERTY(bool, ma_track_bool)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(double issue_unit_price READ getissue_unit_price WRITE setissue_unit_price)
    T_DEFINE_PROPERTY(double, issue_unit_price)
    Q_PROPERTY(QString req_master_id READ getreq_master_id WRITE setreq_master_id)
    T_DEFINE_PROPERTY(QString, req_master_id)
    Q_PROPERTY(QString req_note READ getreq_note WRITE setreq_note)
    T_DEFINE_PROPERTY(QString, req_note)
    Q_PROPERTY(QDateTime req_qt READ getreq_qt WRITE setreq_qt)
    T_DEFINE_PROPERTY(QDateTime, req_qt)
    Q_PROPERTY(QDateTime req_dt READ getreq_dt WRITE setreq_dt)
    T_DEFINE_PROPERTY(QDateTime, req_dt)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int sched_inst_part_id READ getsched_inst_part_id WRITE setsched_inst_part_id)
    T_DEFINE_PROPERTY(int, sched_inst_part_id)
    Q_PROPERTY(int sched_part_id READ getsched_part_id WRITE setsched_part_id)
    T_DEFINE_PROPERTY(int, sched_part_id)
    Q_PROPERTY(int shipment_line_id READ getshipment_line_id WRITE setshipment_line_id)
    T_DEFINE_PROPERTY(int, shipment_line_id)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int csgn_vendor_id READ getcsgn_vendor_id WRITE setcsgn_vendor_id)
    T_DEFINE_PROPERTY(int, csgn_vendor_id)
    Q_PROPERTY(int csgn_owed_qt READ getcsgn_owed_qt WRITE setcsgn_owed_qt)
    T_DEFINE_PROPERTY(int, csgn_owed_qt)
    Q_PROPERTY(int assigned_to READ getassigned_to WRITE setassigned_to)
    T_DEFINE_PROPERTY(int, assigned_to)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REQPARTOBJECT_H
