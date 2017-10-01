#ifndef EQPPARTNOVENDORPRICEOBJECT_H
#define EQPPARTNOVENDORPRICEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoVendorPriceObject : public TSqlObject, public QSharedData
{
public:
    int part_no_vendor_price_id {0};
    int vendor_id {0};
    int part_no_id {0};
    QString price_type_cd;
    double unit_price {0};
    int min_order_qt {0};
    double discount_pct {0};
    int std_sale_qt {0};
    int qty_unit_id {0};
    QString lead_time;
    QDateTime quote_dt;
    QDateTime effective_from_dt;
    QDateTime effective_to_dt;
    QString vendor_note;
    QString doc_ref_desc;
    bool hist_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoVendorPriceId = 0,
        VendorId,
        PartNoId,
        PriceTypeCd,
        UnitPrice,
        MinOrderQt,
        DiscountPct,
        StdSaleQt,
        QtyUnitId,
        LeadTime,
        QuoteDt,
        EffectiveFromDt,
        EffectiveToDt,
        VendorNote,
        DocRefDesc,
        HistBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoVendorPriceId; }
    int autoValueIndex() const override { return PartNoVendorPriceId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<QtyUnitId<<PriceTypeCd<<PartNoId<<VendorId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_vendor_price"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_vendor_price_id READ getpart_no_vendor_price_id WRITE setpart_no_vendor_price_id)
    T_DEFINE_PROPERTY(int, part_no_vendor_price_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString price_type_cd READ getprice_type_cd WRITE setprice_type_cd)
    T_DEFINE_PROPERTY(QString, price_type_cd)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(int min_order_qt READ getmin_order_qt WRITE setmin_order_qt)
    T_DEFINE_PROPERTY(int, min_order_qt)
    Q_PROPERTY(double discount_pct READ getdiscount_pct WRITE setdiscount_pct)
    T_DEFINE_PROPERTY(double, discount_pct)
    Q_PROPERTY(int std_sale_qt READ getstd_sale_qt WRITE setstd_sale_qt)
    T_DEFINE_PROPERTY(int, std_sale_qt)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(QString lead_time READ getlead_time WRITE setlead_time)
    T_DEFINE_PROPERTY(QString, lead_time)
    Q_PROPERTY(QDateTime quote_dt READ getquote_dt WRITE setquote_dt)
    T_DEFINE_PROPERTY(QDateTime, quote_dt)
    Q_PROPERTY(QDateTime effective_from_dt READ geteffective_from_dt WRITE seteffective_from_dt)
    T_DEFINE_PROPERTY(QDateTime, effective_from_dt)
    Q_PROPERTY(QDateTime effective_to_dt READ geteffective_to_dt WRITE seteffective_to_dt)
    T_DEFINE_PROPERTY(QDateTime, effective_to_dt)
    Q_PROPERTY(QString vendor_note READ getvendor_note WRITE setvendor_note)
    T_DEFINE_PROPERTY(QString, vendor_note)
    Q_PROPERTY(QString doc_ref_desc READ getdoc_ref_desc WRITE setdoc_ref_desc)
    T_DEFINE_PROPERTY(QString, doc_ref_desc)
    Q_PROPERTY(bool hist_bool READ gethist_bool WRITE sethist_bool)
    T_DEFINE_PROPERTY(bool, hist_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPARTNOVENDORPRICEOBJECT_H
