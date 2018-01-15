#ifndef INVINVOBJECT_H
#define INVINVOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvInvObject : public TSqlObject, public QSharedData
{
public:
    int inv_no_id {0};
    QString inv_class_cd;
    int assmbl_id {0};
    int assmbl_bom_id {0};
    int assmbl_bom_pos_id {0};
    QString config_pos_desc;
    int part_no_id {0};
    QString serial_no_oem;
    QString batch_no_oem;
    QString icn_no_desc;
    QString appl_eff_cd;
    QString inv_no_desc;
    QString lot_oem_tag;
    QString mod_status_note;
    QString barcode_desc;
    int loc_id {0};
    int authority_id {0};
    int h_inv_no_id {0};
    int nh_inv_no_id {0};
    int assmbl_inv_no_id {0};
    int vendor_id {0};
    QString inv_cond_cd;
    QString receive_cond_cd;
    QString orig_assmbl_cd;
    int orig_assmbl_inv_no_id {0};
    QDateTime manufact_dt;
    QDateTime received_dt;
    QDateTime install_dt;
    int owner_id {0};
    QString own_by_cd;
    bool not_found_bool;
    bool complete_bool;
    bool issued_bool;
    bool locked_bool;
    bool picked_bool;
    bool used_bool;
    QString shelf_expiry_dt;
    QString note;
    int bin_qt {0};
    int reserve_bin_qt {0};
    bool reserved_bool;
    int po_id {0};
    int po_line_id {0};
    int account_id {0};
    QString release_number;
    QString release_remarks_desc;
    QDateTime release_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvNoId = 0,
        InvClassCd,
        AssmblId,
        AssmblBomId,
        AssmblBomPosId,
        ConfigPosDesc,
        PartNoId,
        SerialNoOem,
        BatchNoOem,
        IcnNoDesc,
        ApplEffCd,
        InvNoDesc,
        LotOemTag,
        ModStatusNote,
        BarcodeDesc,
        LocId,
        AuthorityId,
        HInvNoId,
        NhInvNoId,
        AssmblInvNoId,
        VendorId,
        InvCondCd,
        ReceiveCondCd,
        OrigAssmblCd,
        OrigAssmblInvNoId,
        ManufactDt,
        ReceivedDt,
        InstallDt,
        OwnerId,
        OwnByCd,
        NotFoundBool,
        CompleteBool,
        IssuedBool,
        LockedBool,
        PickedBool,
        UsedBool,
        ShelfExpiryDt,
        Note,
        BinQt,
        ReserveBinQt,
        ReservedBool,
        PoId,
        PoLineId,
        AccountId,
        ReleaseNumber,
        ReleaseRemarksDesc,
        ReleaseDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvNoId; }
    int autoValueIndex() const override { return InvNoId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<InvClassCd<<AssmblId<<AssmblBomId<<AssmblBomPosId<<PartNoId<<LocId<<AuthorityId<<HInvNoId<<NhInvNoId<<AssmblInvNoId<<VendorId<<InvCondCd<<ReceiveCondCd<<OrigAssmblInvNoId<<OwnerId<<OwnByCd<<PoId<<PoLineId<<AccountId; }
    QString tableName() const override { return QLatin1String("inv_inv"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QString inv_class_cd READ getinv_class_cd WRITE setinv_class_cd)
    T_DEFINE_PROPERTY(QString, inv_class_cd)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int assmbl_bom_pos_id READ getassmbl_bom_pos_id WRITE setassmbl_bom_pos_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_pos_id)
    Q_PROPERTY(QString config_pos_desc READ getconfig_pos_desc WRITE setconfig_pos_desc)
    T_DEFINE_PROPERTY(QString, config_pos_desc)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString serial_no_oem READ getserial_no_oem WRITE setserial_no_oem)
    T_DEFINE_PROPERTY(QString, serial_no_oem)
    Q_PROPERTY(QString batch_no_oem READ getbatch_no_oem WRITE setbatch_no_oem)
    T_DEFINE_PROPERTY(QString, batch_no_oem)
    Q_PROPERTY(QString icn_no_desc READ geticn_no_desc WRITE seticn_no_desc)
    T_DEFINE_PROPERTY(QString, icn_no_desc)
    Q_PROPERTY(QString appl_eff_cd READ getappl_eff_cd WRITE setappl_eff_cd)
    T_DEFINE_PROPERTY(QString, appl_eff_cd)
    Q_PROPERTY(QString inv_no_desc READ getinv_no_desc WRITE setinv_no_desc)
    T_DEFINE_PROPERTY(QString, inv_no_desc)
    Q_PROPERTY(QString lot_oem_tag READ getlot_oem_tag WRITE setlot_oem_tag)
    T_DEFINE_PROPERTY(QString, lot_oem_tag)
    Q_PROPERTY(QString mod_status_note READ getmod_status_note WRITE setmod_status_note)
    T_DEFINE_PROPERTY(QString, mod_status_note)
    Q_PROPERTY(QString barcode_desc READ getbarcode_desc WRITE setbarcode_desc)
    T_DEFINE_PROPERTY(QString, barcode_desc)
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int authority_id READ getauthority_id WRITE setauthority_id)
    T_DEFINE_PROPERTY(int, authority_id)
    Q_PROPERTY(int h_inv_no_id READ geth_inv_no_id WRITE seth_inv_no_id)
    T_DEFINE_PROPERTY(int, h_inv_no_id)
    Q_PROPERTY(int nh_inv_no_id READ getnh_inv_no_id WRITE setnh_inv_no_id)
    T_DEFINE_PROPERTY(int, nh_inv_no_id)
    Q_PROPERTY(int assmbl_inv_no_id READ getassmbl_inv_no_id WRITE setassmbl_inv_no_id)
    T_DEFINE_PROPERTY(int, assmbl_inv_no_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(QString inv_cond_cd READ getinv_cond_cd WRITE setinv_cond_cd)
    T_DEFINE_PROPERTY(QString, inv_cond_cd)
    Q_PROPERTY(QString receive_cond_cd READ getreceive_cond_cd WRITE setreceive_cond_cd)
    T_DEFINE_PROPERTY(QString, receive_cond_cd)
    Q_PROPERTY(QString orig_assmbl_cd READ getorig_assmbl_cd WRITE setorig_assmbl_cd)
    T_DEFINE_PROPERTY(QString, orig_assmbl_cd)
    Q_PROPERTY(int orig_assmbl_inv_no_id READ getorig_assmbl_inv_no_id WRITE setorig_assmbl_inv_no_id)
    T_DEFINE_PROPERTY(int, orig_assmbl_inv_no_id)
    Q_PROPERTY(QDateTime manufact_dt READ getmanufact_dt WRITE setmanufact_dt)
    T_DEFINE_PROPERTY(QDateTime, manufact_dt)
    Q_PROPERTY(QDateTime received_dt READ getreceived_dt WRITE setreceived_dt)
    T_DEFINE_PROPERTY(QDateTime, received_dt)
    Q_PROPERTY(QDateTime install_dt READ getinstall_dt WRITE setinstall_dt)
    T_DEFINE_PROPERTY(QDateTime, install_dt)
    Q_PROPERTY(int owner_id READ getowner_id WRITE setowner_id)
    T_DEFINE_PROPERTY(int, owner_id)
    Q_PROPERTY(QString own_by_cd READ getown_by_cd WRITE setown_by_cd)
    T_DEFINE_PROPERTY(QString, own_by_cd)
    Q_PROPERTY(bool not_found_bool READ getnot_found_bool WRITE setnot_found_bool)
    T_DEFINE_PROPERTY(bool, not_found_bool)
    Q_PROPERTY(bool complete_bool READ getcomplete_bool WRITE setcomplete_bool)
    T_DEFINE_PROPERTY(bool, complete_bool)
    Q_PROPERTY(bool issued_bool READ getissued_bool WRITE setissued_bool)
    T_DEFINE_PROPERTY(bool, issued_bool)
    Q_PROPERTY(bool locked_bool READ getlocked_bool WRITE setlocked_bool)
    T_DEFINE_PROPERTY(bool, locked_bool)
    Q_PROPERTY(bool picked_bool READ getpicked_bool WRITE setpicked_bool)
    T_DEFINE_PROPERTY(bool, picked_bool)
    Q_PROPERTY(bool used_bool READ getused_bool WRITE setused_bool)
    T_DEFINE_PROPERTY(bool, used_bool)
    Q_PROPERTY(QString shelf_expiry_dt READ getshelf_expiry_dt WRITE setshelf_expiry_dt)
    T_DEFINE_PROPERTY(QString, shelf_expiry_dt)
    Q_PROPERTY(QString note READ getnote WRITE setnote)
    T_DEFINE_PROPERTY(QString, note)
    Q_PROPERTY(int bin_qt READ getbin_qt WRITE setbin_qt)
    T_DEFINE_PROPERTY(int, bin_qt)
    Q_PROPERTY(int reserve_bin_qt READ getreserve_bin_qt WRITE setreserve_bin_qt)
    T_DEFINE_PROPERTY(int, reserve_bin_qt)
    Q_PROPERTY(bool reserved_bool READ getreserved_bool WRITE setreserved_bool)
    T_DEFINE_PROPERTY(bool, reserved_bool)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(QString release_number READ getrelease_number WRITE setrelease_number)
    T_DEFINE_PROPERTY(QString, release_number)
    Q_PROPERTY(QString release_remarks_desc READ getrelease_remarks_desc WRITE setrelease_remarks_desc)
    T_DEFINE_PROPERTY(QString, release_remarks_desc)
    Q_PROPERTY(QDateTime release_dt READ getrelease_dt WRITE setrelease_dt)
    T_DEFINE_PROPERTY(QDateTime, release_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // INVINVOBJECT_H
