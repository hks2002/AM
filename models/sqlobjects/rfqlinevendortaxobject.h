#ifndef RFQLINEVENDORTAXOBJECT_H
#define RFQLINEVENDORTAXOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RfqLineVendorTaxObject : public TSqlObject, public QSharedData
{
public:
    int vendor_id {0};
    int rfq_id {0};
    int rfq_line_id {0};
    int tax_id {0};
    double tax_amount {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        VendorId = 0,
        RfqId,
        RfqLineId,
        TaxId,
        TaxAmount,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<VendorId<<RfqId<<RfqLineId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaxId<<VendorId<<RfqId<<RfqLineId; }
    QString tableName() const override { return QLatin1String("rfq_line_vendor_tax"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int rfq_id READ getrfq_id WRITE setrfq_id)
    T_DEFINE_PROPERTY(int, rfq_id)
    Q_PROPERTY(int rfq_line_id READ getrfq_line_id WRITE setrfq_line_id)
    T_DEFINE_PROPERTY(int, rfq_line_id)
    Q_PROPERTY(int tax_id READ gettax_id WRITE settax_id)
    T_DEFINE_PROPERTY(int, tax_id)
    Q_PROPERTY(double tax_amount READ gettax_amount WRITE settax_amount)
    T_DEFINE_PROPERTY(double, tax_amount)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // RFQLINEVENDORTAXOBJECT_H
