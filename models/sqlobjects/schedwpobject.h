#ifndef SCHEDWPOBJECT_H
#define SCHEDWPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedWpObject : public TSqlObject, public QSharedData
{
public:
    int sched_id {0};
    bool delay_bool;
    bool enforce_nsv_bool;
    bool enforce_workscope_bool;
    bool collection_required_bool;
    bool lrp_bool;
    bool heavy_bool;
    bool init_exp_cost_locked_bool;
    bool exp_cost_locked_bool;
    bool actual_cost_locked_bool;
    bool adjusted_billing_bool;
    double sched_hr_mult_qt {0};
    int vendor_id {0};
    QString vendor_wo_ref_desc;
    QString wo_ref_desc;
    QString release_number;
    QString release_remarks_desc;
    QString receive_cond_cd;
    int ro_issued_by {0};
    QDateTime ro_issued_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedId = 0,
        DelayBool,
        EnforceNsvBool,
        EnforceWorkscopeBool,
        CollectionRequiredBool,
        LrpBool,
        HeavyBool,
        InitExpCostLockedBool,
        ExpCostLockedBool,
        ActualCostLockedBool,
        AdjustedBillingBool,
        SchedHrMultQt,
        VendorId,
        VendorWoRefDesc,
        WoRefDesc,
        ReleaseNumber,
        ReleaseRemarksDesc,
        ReceiveCondCd,
        RoIssuedBy,
        RoIssuedDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RoIssuedBy<<ReceiveCondCd<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_wp"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(bool delay_bool READ getdelay_bool WRITE setdelay_bool)
    T_DEFINE_PROPERTY(bool, delay_bool)
    Q_PROPERTY(bool enforce_nsv_bool READ getenforce_nsv_bool WRITE setenforce_nsv_bool)
    T_DEFINE_PROPERTY(bool, enforce_nsv_bool)
    Q_PROPERTY(bool enforce_workscope_bool READ getenforce_workscope_bool WRITE setenforce_workscope_bool)
    T_DEFINE_PROPERTY(bool, enforce_workscope_bool)
    Q_PROPERTY(bool collection_required_bool READ getcollection_required_bool WRITE setcollection_required_bool)
    T_DEFINE_PROPERTY(bool, collection_required_bool)
    Q_PROPERTY(bool lrp_bool READ getlrp_bool WRITE setlrp_bool)
    T_DEFINE_PROPERTY(bool, lrp_bool)
    Q_PROPERTY(bool heavy_bool READ getheavy_bool WRITE setheavy_bool)
    T_DEFINE_PROPERTY(bool, heavy_bool)
    Q_PROPERTY(bool init_exp_cost_locked_bool READ getinit_exp_cost_locked_bool WRITE setinit_exp_cost_locked_bool)
    T_DEFINE_PROPERTY(bool, init_exp_cost_locked_bool)
    Q_PROPERTY(bool exp_cost_locked_bool READ getexp_cost_locked_bool WRITE setexp_cost_locked_bool)
    T_DEFINE_PROPERTY(bool, exp_cost_locked_bool)
    Q_PROPERTY(bool actual_cost_locked_bool READ getactual_cost_locked_bool WRITE setactual_cost_locked_bool)
    T_DEFINE_PROPERTY(bool, actual_cost_locked_bool)
    Q_PROPERTY(bool adjusted_billing_bool READ getadjusted_billing_bool WRITE setadjusted_billing_bool)
    T_DEFINE_PROPERTY(bool, adjusted_billing_bool)
    Q_PROPERTY(double sched_hr_mult_qt READ getsched_hr_mult_qt WRITE setsched_hr_mult_qt)
    T_DEFINE_PROPERTY(double, sched_hr_mult_qt)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(QString vendor_wo_ref_desc READ getvendor_wo_ref_desc WRITE setvendor_wo_ref_desc)
    T_DEFINE_PROPERTY(QString, vendor_wo_ref_desc)
    Q_PROPERTY(QString wo_ref_desc READ getwo_ref_desc WRITE setwo_ref_desc)
    T_DEFINE_PROPERTY(QString, wo_ref_desc)
    Q_PROPERTY(QString release_number READ getrelease_number WRITE setrelease_number)
    T_DEFINE_PROPERTY(QString, release_number)
    Q_PROPERTY(QString release_remarks_desc READ getrelease_remarks_desc WRITE setrelease_remarks_desc)
    T_DEFINE_PROPERTY(QString, release_remarks_desc)
    Q_PROPERTY(QString receive_cond_cd READ getreceive_cond_cd WRITE setreceive_cond_cd)
    T_DEFINE_PROPERTY(QString, receive_cond_cd)
    Q_PROPERTY(int ro_issued_by READ getro_issued_by WRITE setro_issued_by)
    T_DEFINE_PROPERTY(int, ro_issued_by)
    Q_PROPERTY(QDateTime ro_issued_dt READ getro_issued_dt WRITE setro_issued_dt)
    T_DEFINE_PROPERTY(QDateTime, ro_issued_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDWPOBJECT_H
