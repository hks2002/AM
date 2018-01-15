#ifndef REFSTOCKLOWACTNOBJECT_H
#define REFSTOCKLOWACTNOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefStockLowActnObject : public TSqlObject, public QSharedData
{
public:
    QString stock_low_actn_cd;
    QString stock_low_actn_name_en;
    QString stock_low_actn_name_zh;
    QString stock_low_actn_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        StockLowActnCd = 0,
        StockLowActnNameEn,
        StockLowActnNameZh,
        StockLowActnDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<StockLowActnCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_stock_low_actn"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString stock_low_actn_cd READ getstock_low_actn_cd WRITE setstock_low_actn_cd)
    T_DEFINE_PROPERTY(QString, stock_low_actn_cd)
    Q_PROPERTY(QString stock_low_actn_name_en READ getstock_low_actn_name_en WRITE setstock_low_actn_name_en)
    T_DEFINE_PROPERTY(QString, stock_low_actn_name_en)
    Q_PROPERTY(QString stock_low_actn_name_zh READ getstock_low_actn_name_zh WRITE setstock_low_actn_name_zh)
    T_DEFINE_PROPERTY(QString, stock_low_actn_name_zh)
    Q_PROPERTY(QString stock_low_actn_desc READ getstock_low_actn_desc WRITE setstock_low_actn_desc)
    T_DEFINE_PROPERTY(QString, stock_low_actn_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFSTOCKLOWACTNOBJECT_H
