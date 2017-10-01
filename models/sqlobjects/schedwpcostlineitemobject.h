#ifndef SCHEDWPCOSTLINEITEMOBJECT_H
#define SCHEDWPCOSTLINEITEMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedWpCostLineItemObject : public TSqlObject, public QSharedData
{
public:
    int sched_id {0};
    QString cost_line_item_type_cd;
    double init_exp_cost {0};
    double exp_cost {0};
    double actual_cost {0};
    int currency_id {0};
    QString item_note;
    int invoice_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedId = 0,
        CostLineItemTypeCd,
        InitExpCost,
        ExpCost,
        ActualCost,
        CurrencyId,
        ItemNote,
        InvoiceId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedId<<CostLineItemTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<InvoiceId<<CurrencyId<<CostLineItemTypeCd<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_wp_cost_line_item"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(QString cost_line_item_type_cd READ getcost_line_item_type_cd WRITE setcost_line_item_type_cd)
    T_DEFINE_PROPERTY(QString, cost_line_item_type_cd)
    Q_PROPERTY(double init_exp_cost READ getinit_exp_cost WRITE setinit_exp_cost)
    T_DEFINE_PROPERTY(double, init_exp_cost)
    Q_PROPERTY(double exp_cost READ getexp_cost WRITE setexp_cost)
    T_DEFINE_PROPERTY(double, exp_cost)
    Q_PROPERTY(double actual_cost READ getactual_cost WRITE setactual_cost)
    T_DEFINE_PROPERTY(double, actual_cost)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(QString item_note READ getitem_note WRITE setitem_note)
    T_DEFINE_PROPERTY(QString, item_note)
    Q_PROPERTY(int invoice_id READ getinvoice_id WRITE setinvoice_id)
    T_DEFINE_PROPERTY(int, invoice_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDWPCOSTLINEITEMOBJECT_H
