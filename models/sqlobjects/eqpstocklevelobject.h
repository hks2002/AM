#ifndef EQPSTOCKLEVELOBJECT_H
#define EQPSTOCKLEVELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpStockLevelObject : public TSqlObject, public QSharedData
{
public:
    int stock_id {0};
    int loc_id {0};
    int owner_id {0};
    int max_qt {0};
    int min_reorder_qt {0};
    int reorder_qt {0};
    QString stock_low_actn_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        StockId = 0,
        LocId,
        OwnerId,
        MaxQt,
        MinReorderQt,
        ReorderQt,
        StockLowActnCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<StockId<<LocId<<OwnerId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<StockLowActnCd<<OwnerId<<LocId<<StockId; }
    QString tableName() const override { return QLatin1String("eqp_stock_level"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int stock_id READ getstock_id WRITE setstock_id)
    T_DEFINE_PROPERTY(int, stock_id)
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int owner_id READ getowner_id WRITE setowner_id)
    T_DEFINE_PROPERTY(int, owner_id)
    Q_PROPERTY(int max_qt READ getmax_qt WRITE setmax_qt)
    T_DEFINE_PROPERTY(int, max_qt)
    Q_PROPERTY(int min_reorder_qt READ getmin_reorder_qt WRITE setmin_reorder_qt)
    T_DEFINE_PROPERTY(int, min_reorder_qt)
    Q_PROPERTY(int reorder_qt READ getreorder_qt WRITE setreorder_qt)
    T_DEFINE_PROPERTY(int, reorder_qt)
    Q_PROPERTY(QString stock_low_actn_cd READ getstock_low_actn_cd WRITE setstock_low_actn_cd)
    T_DEFINE_PROPERTY(QString, stock_low_actn_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPSTOCKLEVELOBJECT_H
