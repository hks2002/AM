#ifndef EQPSTOCKPARTNOOBJECT_H
#define EQPSTOCKPARTNOOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpStockPartNoObject : public TSqlObject, public QSharedData
{
public:
    int stock_id {0};
    int part_no_id {0};
    double part_no_pct {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        StockId = 0,
        PartNoId,
        PartNoPct,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<StockId<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<StockId; }
    QString tableName() const override { return QLatin1String("eqp_stock_part_no"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int stock_id READ getstock_id WRITE setstock_id)
    T_DEFINE_PROPERTY(int, stock_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(double part_no_pct READ getpart_no_pct WRITE setpart_no_pct)
    T_DEFINE_PROPERTY(double, part_no_pct)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPSTOCKPARTNOOBJECT_H
