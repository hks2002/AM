#ifndef POINVOICEOBJECT_H
#define POINVOICEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoInvoiceObject : public TSqlObject, public QSharedData
{
public:
    int po_invoice_id {0};
    QString po_invoice_cd;
    int vendor_id {0};
    int vendor_account_id {0};
    double total_invoice {0};
    int currency_id {0};
    double exchg_qt {0};
    QString payment_terms_cd;
    QString invoice_note;
    double cash_discount_pct {0};
    QDateTime cash_discount_exp_dt;
    QDateTime invoice_dt;
    int po_invoice_pay_by {0};
    QDateTime po_invoice_pay_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoInvoiceId = 0,
        PoInvoiceCd,
        VendorId,
        VendorAccountId,
        TotalInvoice,
        CurrencyId,
        ExchgQt,
        PaymentTermsCd,
        InvoiceNote,
        CashDiscountPct,
        CashDiscountExpDt,
        InvoiceDt,
        PoInvoicePayBy,
        PoInvoicePayDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoInvoiceId; }
    int autoValueIndex() const override { return PoInvoiceId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PoInvoicePayBy<<PaymentTermsCd<<CurrencyId<<VendorAccountId<<VendorId; }
    QString tableName() const override { return QLatin1String("po_invoice"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_invoice_id READ getpo_invoice_id WRITE setpo_invoice_id)
    T_DEFINE_PROPERTY(int, po_invoice_id)
    Q_PROPERTY(QString po_invoice_cd READ getpo_invoice_cd WRITE setpo_invoice_cd)
    T_DEFINE_PROPERTY(QString, po_invoice_cd)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int vendor_account_id READ getvendor_account_id WRITE setvendor_account_id)
    T_DEFINE_PROPERTY(int, vendor_account_id)
    Q_PROPERTY(double total_invoice READ gettotal_invoice WRITE settotal_invoice)
    T_DEFINE_PROPERTY(double, total_invoice)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(double exchg_qt READ getexchg_qt WRITE setexchg_qt)
    T_DEFINE_PROPERTY(double, exchg_qt)
    Q_PROPERTY(QString payment_terms_cd READ getpayment_terms_cd WRITE setpayment_terms_cd)
    T_DEFINE_PROPERTY(QString, payment_terms_cd)
    Q_PROPERTY(QString invoice_note READ getinvoice_note WRITE setinvoice_note)
    T_DEFINE_PROPERTY(QString, invoice_note)
    Q_PROPERTY(double cash_discount_pct READ getcash_discount_pct WRITE setcash_discount_pct)
    T_DEFINE_PROPERTY(double, cash_discount_pct)
    Q_PROPERTY(QDateTime cash_discount_exp_dt READ getcash_discount_exp_dt WRITE setcash_discount_exp_dt)
    T_DEFINE_PROPERTY(QDateTime, cash_discount_exp_dt)
    Q_PROPERTY(QDateTime invoice_dt READ getinvoice_dt WRITE setinvoice_dt)
    T_DEFINE_PROPERTY(QDateTime, invoice_dt)
    Q_PROPERTY(int po_invoice_pay_by READ getpo_invoice_pay_by WRITE setpo_invoice_pay_by)
    T_DEFINE_PROPERTY(int, po_invoice_pay_by)
    Q_PROPERTY(QDateTime po_invoice_pay_dt READ getpo_invoice_pay_dt WRITE setpo_invoice_pay_dt)
    T_DEFINE_PROPERTY(QDateTime, po_invoice_pay_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // POINVOICEOBJECT_H
