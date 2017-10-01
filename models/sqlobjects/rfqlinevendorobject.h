#ifndef RFQLINEVENDOROBJECT_H
#define RFQLINEVENDOROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RfqLineVendorObject : public TSqlObject, public QSharedData
{
public:
    int rfq_id {0};
    int rfq_line_id {0};
    int vendor_id {0};
    bool no_quote_bool;
    bool no_supply_bool;
    int part_no_id {0};
    QString receive_cond_cd;
    int quote_qt {0};
    QDateTime quote_dt;
    double unit_price {0};
    int qty_unit_id {0};
    double line_price {0};
    QString lead_time;
    QDateTime effective_to_dt;
    bool responded_bool;
    QString note_to_vendor;
    QString doc_ref_desc;
    QDateTime respond_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RfqId = 0,
        RfqLineId,
        VendorId,
        NoQuoteBool,
        NoSupplyBool,
        PartNoId,
        ReceiveCondCd,
        QuoteQt,
        QuoteDt,
        UnitPrice,
        QtyUnitId,
        LinePrice,
        LeadTime,
        EffectiveToDt,
        RespondedBool,
        NoteToVendor,
        DocRefDesc,
        RespondDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RfqId<<RfqLineId<<VendorId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<QtyUnitId<<ReceiveCondCd<<PartNoId<<RfqLineId<<RfqId<<VendorId; }
    QString tableName() const override { return QLatin1String("rfq_line_vendor"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int rfq_id READ getrfq_id WRITE setrfq_id)
    T_DEFINE_PROPERTY(int, rfq_id)
    Q_PROPERTY(int rfq_line_id READ getrfq_line_id WRITE setrfq_line_id)
    T_DEFINE_PROPERTY(int, rfq_line_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(bool no_quote_bool READ getno_quote_bool WRITE setno_quote_bool)
    T_DEFINE_PROPERTY(bool, no_quote_bool)
    Q_PROPERTY(bool no_supply_bool READ getno_supply_bool WRITE setno_supply_bool)
    T_DEFINE_PROPERTY(bool, no_supply_bool)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString receive_cond_cd READ getreceive_cond_cd WRITE setreceive_cond_cd)
    T_DEFINE_PROPERTY(QString, receive_cond_cd)
    Q_PROPERTY(int quote_qt READ getquote_qt WRITE setquote_qt)
    T_DEFINE_PROPERTY(int, quote_qt)
    Q_PROPERTY(QDateTime quote_dt READ getquote_dt WRITE setquote_dt)
    T_DEFINE_PROPERTY(QDateTime, quote_dt)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(double line_price READ getline_price WRITE setline_price)
    T_DEFINE_PROPERTY(double, line_price)
    Q_PROPERTY(QString lead_time READ getlead_time WRITE setlead_time)
    T_DEFINE_PROPERTY(QString, lead_time)
    Q_PROPERTY(QDateTime effective_to_dt READ geteffective_to_dt WRITE seteffective_to_dt)
    T_DEFINE_PROPERTY(QDateTime, effective_to_dt)
    Q_PROPERTY(bool responded_bool READ getresponded_bool WRITE setresponded_bool)
    T_DEFINE_PROPERTY(bool, responded_bool)
    Q_PROPERTY(QString note_to_vendor READ getnote_to_vendor WRITE setnote_to_vendor)
    T_DEFINE_PROPERTY(QString, note_to_vendor)
    Q_PROPERTY(QString doc_ref_desc READ getdoc_ref_desc WRITE setdoc_ref_desc)
    T_DEFINE_PROPERTY(QString, doc_ref_desc)
    Q_PROPERTY(QDateTime respond_dt READ getrespond_dt WRITE setrespond_dt)
    T_DEFINE_PROPERTY(QDateTime, respond_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // RFQLINEVENDOROBJECT_H
