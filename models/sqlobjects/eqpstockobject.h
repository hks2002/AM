#ifndef EQPSTOCKOBJECT_H
#define EQPSTOCKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpStockObject : public TSqlObject, public QSharedData
{
public:
    int stock_id {0};
    QString stock_no_cd;
    QString stock_no_name;
    int qty_unit_id {0};
    int monthly_demand_qt {0};
    int safety_level_qt {0};
    int max_mult_qt {0};
    int default_reorder_qt {0};
    int default_ship_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        StockId = 0,
        StockNoCd,
        StockNoName,
        QtyUnitId,
        MonthlyDemandQt,
        SafetyLevelQt,
        MaxMultQt,
        DefaultReorderQt,
        DefaultShipQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<StockId; }
    int autoValueIndex() const override { return StockId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<QtyUnitId; }
    QString tableName() const override { return QLatin1String("eqp_stock"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int stock_id READ getstock_id WRITE setstock_id)
    T_DEFINE_PROPERTY(int, stock_id)
    Q_PROPERTY(QString stock_no_cd READ getstock_no_cd WRITE setstock_no_cd)
    T_DEFINE_PROPERTY(QString, stock_no_cd)
    Q_PROPERTY(QString stock_no_name READ getstock_no_name WRITE setstock_no_name)
    T_DEFINE_PROPERTY(QString, stock_no_name)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(int monthly_demand_qt READ getmonthly_demand_qt WRITE setmonthly_demand_qt)
    T_DEFINE_PROPERTY(int, monthly_demand_qt)
    Q_PROPERTY(int safety_level_qt READ getsafety_level_qt WRITE setsafety_level_qt)
    T_DEFINE_PROPERTY(int, safety_level_qt)
    Q_PROPERTY(int max_mult_qt READ getmax_mult_qt WRITE setmax_mult_qt)
    T_DEFINE_PROPERTY(int, max_mult_qt)
    Q_PROPERTY(int default_reorder_qt READ getdefault_reorder_qt WRITE setdefault_reorder_qt)
    T_DEFINE_PROPERTY(int, default_reorder_qt)
    Q_PROPERTY(int default_ship_qt READ getdefault_ship_qt WRITE setdefault_ship_qt)
    T_DEFINE_PROPERTY(int, default_ship_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPSTOCKOBJECT_H
