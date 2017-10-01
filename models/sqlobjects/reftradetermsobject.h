#ifndef REFTRADETERMSOBJECT_H
#define REFTRADETERMSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefTradeTermsObject : public TSqlObject, public QSharedData
{
public:
    QString trade_term_cd;
    QString trade_term_name_en;
    QString trade_term_name_zh;
    QString trade_term_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TradeTermCd = 0,
        TradeTermNameEn,
        TradeTermNameZh,
        TradeTermDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TradeTermCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_trade_terms"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString trade_term_cd READ gettrade_term_cd WRITE settrade_term_cd)
    T_DEFINE_PROPERTY(QString, trade_term_cd)
    Q_PROPERTY(QString trade_term_name_en READ gettrade_term_name_en WRITE settrade_term_name_en)
    T_DEFINE_PROPERTY(QString, trade_term_name_en)
    Q_PROPERTY(QString trade_term_name_zh READ gettrade_term_name_zh WRITE settrade_term_name_zh)
    T_DEFINE_PROPERTY(QString, trade_term_name_zh)
    Q_PROPERTY(QString trade_term_desc READ gettrade_term_desc WRITE settrade_term_desc)
    T_DEFINE_PROPERTY(QString, trade_term_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFTRADETERMSOBJECT_H
