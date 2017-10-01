#ifndef RFQVENDOROBJECT_H
#define RFQVENDOROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RfqVendorObject : public TSqlObject, public QSharedData
{
public:
    int rfq_id {0};
    int vendor_id {0};
    int currency_id {0};
    double exchg_qt {0};
    int transportor_id {0};
    QString payment_terms_cd;
    QString trade_term_cd;
    QString vendor_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RfqId = 0,
        VendorId,
        CurrencyId,
        ExchgQt,
        TransportorId,
        PaymentTermsCd,
        TradeTermCd,
        VendorNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RfqId<<VendorId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TradeTermCd<<PaymentTermsCd<<TransportorId<<CurrencyId<<VendorId<<RfqId; }
    QString tableName() const override { return QLatin1String("rfq_vendor"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int rfq_id READ getrfq_id WRITE setrfq_id)
    T_DEFINE_PROPERTY(int, rfq_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(double exchg_qt READ getexchg_qt WRITE setexchg_qt)
    T_DEFINE_PROPERTY(double, exchg_qt)
    Q_PROPERTY(int transportor_id READ gettransportor_id WRITE settransportor_id)
    T_DEFINE_PROPERTY(int, transportor_id)
    Q_PROPERTY(QString payment_terms_cd READ getpayment_terms_cd WRITE setpayment_terms_cd)
    T_DEFINE_PROPERTY(QString, payment_terms_cd)
    Q_PROPERTY(QString trade_term_cd READ gettrade_term_cd WRITE settrade_term_cd)
    T_DEFINE_PROPERTY(QString, trade_term_cd)
    Q_PROPERTY(QString vendor_note READ getvendor_note WRITE setvendor_note)
    T_DEFINE_PROPERTY(QString, vendor_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // RFQVENDOROBJECT_H
