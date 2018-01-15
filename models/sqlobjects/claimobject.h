#ifndef CLAIMOBJECT_H
#define CLAIMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ClaimObject : public TSqlObject, public QSharedData
{
public:
    int claim_id {0};
    QString claim_to_cd;
    int transportor_id {0};
    int warranty_eval_id {0};
    int vendor_id {0};
    int inv_no_id {0};
    int contact_to {0};
    QString credit_ref_desc;
    int total_requested_qt {0};
    int total_recovered_qt {0};
    QString claim_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ClaimId = 0,
        ClaimToCd,
        TransportorId,
        WarrantyEvalId,
        VendorId,
        InvNoId,
        ContactTo,
        CreditRefDesc,
        TotalRequestedQt,
        TotalRecoveredQt,
        ClaimNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ClaimId; }
    int autoValueIndex() const override { return ClaimId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ContactTo<<InvNoId<<VendorId<<WarrantyEvalId<<TransportorId<<ClaimToCd; }
    QString tableName() const override { return QLatin1String("claim"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int claim_id READ getclaim_id WRITE setclaim_id)
    T_DEFINE_PROPERTY(int, claim_id)
    Q_PROPERTY(QString claim_to_cd READ getclaim_to_cd WRITE setclaim_to_cd)
    T_DEFINE_PROPERTY(QString, claim_to_cd)
    Q_PROPERTY(int transportor_id READ gettransportor_id WRITE settransportor_id)
    T_DEFINE_PROPERTY(int, transportor_id)
    Q_PROPERTY(int warranty_eval_id READ getwarranty_eval_id WRITE setwarranty_eval_id)
    T_DEFINE_PROPERTY(int, warranty_eval_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int contact_to READ getcontact_to WRITE setcontact_to)
    T_DEFINE_PROPERTY(int, contact_to)
    Q_PROPERTY(QString credit_ref_desc READ getcredit_ref_desc WRITE setcredit_ref_desc)
    T_DEFINE_PROPERTY(QString, credit_ref_desc)
    Q_PROPERTY(int total_requested_qt READ gettotal_requested_qt WRITE settotal_requested_qt)
    T_DEFINE_PROPERTY(int, total_requested_qt)
    Q_PROPERTY(int total_recovered_qt READ gettotal_recovered_qt WRITE settotal_recovered_qt)
    T_DEFINE_PROPERTY(int, total_recovered_qt)
    Q_PROPERTY(QString claim_note READ getclaim_note WRITE setclaim_note)
    T_DEFINE_PROPERTY(QString, claim_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // CLAIMOBJECT_H
