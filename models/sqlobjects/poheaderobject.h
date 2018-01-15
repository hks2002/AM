#ifndef POHEADEROBJECT_H
#define POHEADEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoHeaderObject : public TSqlObject, public QSharedData
{
public:
    int po_id {0};
    QString po_type_cd;
    QString req_priority_cd;
    QString req_type_cd;
    int vendor_id {0};
    int vendor_account_id {0};
    int currency_id {0};
    QString borrow_rate_cd;
    QString payment_terms_cd;
    QString trade_term_cd;
    QString shipping_point;
    int final_loc_id {0};
    int re_expedite_to_loc_id {0};
    int transportor_id {0};
    bool receipt_insp_bool;
    QString note_to_vendor;
    QString note_to_receiver;
    bool auth_bool;
    int org_id {0};
    int contact_to {0};
    int po_created_by {0};
    QDateTime po_created_dt;
    int po_issued_by {0};
    QDateTime po_issued_dt;
    int po_closed_by {0};
    QDateTime po_closed_dt;
    int po_invoice_created_by {0};
    QDateTime po_invoice_created_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoId = 0,
        PoTypeCd,
        ReqPriorityCd,
        ReqTypeCd,
        VendorId,
        VendorAccountId,
        CurrencyId,
        BorrowRateCd,
        PaymentTermsCd,
        TradeTermCd,
        ShippingPoint,
        FinalLocId,
        ReExpediteToLocId,
        TransportorId,
        ReceiptInspBool,
        NoteToVendor,
        NoteToReceiver,
        AuthBool,
        OrgId,
        ContactTo,
        PoCreatedBy,
        PoCreatedDt,
        PoIssuedBy,
        PoIssuedDt,
        PoClosedBy,
        PoClosedDt,
        PoInvoiceCreatedBy,
        PoInvoiceCreatedDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoId; }
    int autoValueIndex() const override { return PoId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PoTypeCd<<ReqPriorityCd<<ReqTypeCd<<VendorId<<VendorAccountId<<CurrencyId<<BorrowRateCd<<PaymentTermsCd<<TradeTermCd<<FinalLocId<<ReExpediteToLocId<<TransportorId<<OrgId<<ContactTo<<PoCreatedBy<<PoIssuedBy<<PoClosedBy<<PoInvoiceCreatedBy; }
    QString tableName() const override { return QLatin1String("po_header"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(QString po_type_cd READ getpo_type_cd WRITE setpo_type_cd)
    T_DEFINE_PROPERTY(QString, po_type_cd)
    Q_PROPERTY(QString req_priority_cd READ getreq_priority_cd WRITE setreq_priority_cd)
    T_DEFINE_PROPERTY(QString, req_priority_cd)
    Q_PROPERTY(QString req_type_cd READ getreq_type_cd WRITE setreq_type_cd)
    T_DEFINE_PROPERTY(QString, req_type_cd)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int vendor_account_id READ getvendor_account_id WRITE setvendor_account_id)
    T_DEFINE_PROPERTY(int, vendor_account_id)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(QString borrow_rate_cd READ getborrow_rate_cd WRITE setborrow_rate_cd)
    T_DEFINE_PROPERTY(QString, borrow_rate_cd)
    Q_PROPERTY(QString payment_terms_cd READ getpayment_terms_cd WRITE setpayment_terms_cd)
    T_DEFINE_PROPERTY(QString, payment_terms_cd)
    Q_PROPERTY(QString trade_term_cd READ gettrade_term_cd WRITE settrade_term_cd)
    T_DEFINE_PROPERTY(QString, trade_term_cd)
    Q_PROPERTY(QString shipping_point READ getshipping_point WRITE setshipping_point)
    T_DEFINE_PROPERTY(QString, shipping_point)
    Q_PROPERTY(int final_loc_id READ getfinal_loc_id WRITE setfinal_loc_id)
    T_DEFINE_PROPERTY(int, final_loc_id)
    Q_PROPERTY(int re_expedite_to_loc_id READ getre_expedite_to_loc_id WRITE setre_expedite_to_loc_id)
    T_DEFINE_PROPERTY(int, re_expedite_to_loc_id)
    Q_PROPERTY(int transportor_id READ gettransportor_id WRITE settransportor_id)
    T_DEFINE_PROPERTY(int, transportor_id)
    Q_PROPERTY(bool receipt_insp_bool READ getreceipt_insp_bool WRITE setreceipt_insp_bool)
    T_DEFINE_PROPERTY(bool, receipt_insp_bool)
    Q_PROPERTY(QString note_to_vendor READ getnote_to_vendor WRITE setnote_to_vendor)
    T_DEFINE_PROPERTY(QString, note_to_vendor)
    Q_PROPERTY(QString note_to_receiver READ getnote_to_receiver WRITE setnote_to_receiver)
    T_DEFINE_PROPERTY(QString, note_to_receiver)
    Q_PROPERTY(bool auth_bool READ getauth_bool WRITE setauth_bool)
    T_DEFINE_PROPERTY(bool, auth_bool)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(int contact_to READ getcontact_to WRITE setcontact_to)
    T_DEFINE_PROPERTY(int, contact_to)
    Q_PROPERTY(int po_created_by READ getpo_created_by WRITE setpo_created_by)
    T_DEFINE_PROPERTY(int, po_created_by)
    Q_PROPERTY(QDateTime po_created_dt READ getpo_created_dt WRITE setpo_created_dt)
    T_DEFINE_PROPERTY(QDateTime, po_created_dt)
    Q_PROPERTY(int po_issued_by READ getpo_issued_by WRITE setpo_issued_by)
    T_DEFINE_PROPERTY(int, po_issued_by)
    Q_PROPERTY(QDateTime po_issued_dt READ getpo_issued_dt WRITE setpo_issued_dt)
    T_DEFINE_PROPERTY(QDateTime, po_issued_dt)
    Q_PROPERTY(int po_closed_by READ getpo_closed_by WRITE setpo_closed_by)
    T_DEFINE_PROPERTY(int, po_closed_by)
    Q_PROPERTY(QDateTime po_closed_dt READ getpo_closed_dt WRITE setpo_closed_dt)
    T_DEFINE_PROPERTY(QDateTime, po_closed_dt)
    Q_PROPERTY(int po_invoice_created_by READ getpo_invoice_created_by WRITE setpo_invoice_created_by)
    T_DEFINE_PROPERTY(int, po_invoice_created_by)
    Q_PROPERTY(QDateTime po_invoice_created_dt READ getpo_invoice_created_dt WRITE setpo_invoice_created_dt)
    T_DEFINE_PROPERTY(QDateTime, po_invoice_created_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // POHEADEROBJECT_H
