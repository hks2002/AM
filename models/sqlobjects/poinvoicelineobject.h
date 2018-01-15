#ifndef POINVOICELINEOBJECT_H
#define POINVOICELINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoInvoiceLineObject : public TSqlObject, public QSharedData
{
public:
    int po_invoice_line_id {0};
    int po_invoice_id {0};
    int line_no_ord {0};
    QString line_desc;
    int part_no_id {0};
    int invoice_qt {0};
    int qty_unit_id {0};
    double unit_price {0};
    double line_price {0};
    QString invoice_line_note;
    bool csgn_bool;
    int account_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoInvoiceLineId = 0,
        PoInvoiceId,
        LineNoOrd,
        LineDesc,
        PartNoId,
        InvoiceQt,
        QtyUnitId,
        UnitPrice,
        LinePrice,
        InvoiceLineNote,
        CsgnBool,
        AccountId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoInvoiceLineId; }
    int autoValueIndex() const override { return PoInvoiceLineId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AccountId<<QtyUnitId<<PartNoId<<PoInvoiceId; }
    QString tableName() const override { return QLatin1String("po_invoice_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_invoice_line_id READ getpo_invoice_line_id WRITE setpo_invoice_line_id)
    T_DEFINE_PROPERTY(int, po_invoice_line_id)
    Q_PROPERTY(int po_invoice_id READ getpo_invoice_id WRITE setpo_invoice_id)
    T_DEFINE_PROPERTY(int, po_invoice_id)
    Q_PROPERTY(int line_no_ord READ getline_no_ord WRITE setline_no_ord)
    T_DEFINE_PROPERTY(int, line_no_ord)
    Q_PROPERTY(QString line_desc READ getline_desc WRITE setline_desc)
    T_DEFINE_PROPERTY(QString, line_desc)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int invoice_qt READ getinvoice_qt WRITE setinvoice_qt)
    T_DEFINE_PROPERTY(int, invoice_qt)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(double line_price READ getline_price WRITE setline_price)
    T_DEFINE_PROPERTY(double, line_price)
    Q_PROPERTY(QString invoice_line_note READ getinvoice_line_note WRITE setinvoice_line_note)
    T_DEFINE_PROPERTY(QString, invoice_line_note)
    Q_PROPERTY(bool csgn_bool READ getcsgn_bool WRITE setcsgn_bool)
    T_DEFINE_PROPERTY(bool, csgn_bool)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // POINVOICELINEOBJECT_H
