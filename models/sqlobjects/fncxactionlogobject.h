#ifndef FNCXACTIONLOGOBJECT_H
#define FNCXACTIONLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FncXactionLogObject : public TSqlObject, public QSharedData
{
public:
    int xaction_id {0};
    QString xaction_type_cd;
    QString xaction_desc;
    QDateTime xaction_dt;
    int po_id {0};
    int po_line_id {0};
    int po_invoice_id {0};
    int po_invoice_line_id {0};
    int part_no_id {0};
    int inv_no_id {0};
    int qty {0};
    double unit_price {0};
    int currency_id {0};
    double exchg_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        XactionId = 0,
        XactionTypeCd,
        XactionDesc,
        XactionDt,
        PoId,
        PoLineId,
        PoInvoiceId,
        PoInvoiceLineId,
        PartNoId,
        InvNoId,
        Qty,
        UnitPrice,
        CurrencyId,
        ExchgQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<XactionId; }
    int autoValueIndex() const override { return XactionId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CurrencyId<<InvNoId<<PartNoId<<PoInvoiceLineId<<PoInvoiceId<<PoLineId<<PoId<<XactionTypeCd; }
    QString tableName() const override { return QLatin1String("fnc_xaction_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int xaction_id READ getxaction_id WRITE setxaction_id)
    T_DEFINE_PROPERTY(int, xaction_id)
    Q_PROPERTY(QString xaction_type_cd READ getxaction_type_cd WRITE setxaction_type_cd)
    T_DEFINE_PROPERTY(QString, xaction_type_cd)
    Q_PROPERTY(QString xaction_desc READ getxaction_desc WRITE setxaction_desc)
    T_DEFINE_PROPERTY(QString, xaction_desc)
    Q_PROPERTY(QDateTime xaction_dt READ getxaction_dt WRITE setxaction_dt)
    T_DEFINE_PROPERTY(QDateTime, xaction_dt)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int po_invoice_id READ getpo_invoice_id WRITE setpo_invoice_id)
    T_DEFINE_PROPERTY(int, po_invoice_id)
    Q_PROPERTY(int po_invoice_line_id READ getpo_invoice_line_id WRITE setpo_invoice_line_id)
    T_DEFINE_PROPERTY(int, po_invoice_line_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int qty READ getqty WRITE setqty)
    T_DEFINE_PROPERTY(int, qty)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(double exchg_qt READ getexchg_qt WRITE setexchg_qt)
    T_DEFINE_PROPERTY(double, exchg_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FNCXACTIONLOGOBJECT_H
