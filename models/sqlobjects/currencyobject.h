#ifndef CURRENCYOBJECT_H
#define CURRENCYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CurrencyObject : public TSqlObject, public QSharedData
{
public:
    int currency_id {0};
    QString currency_cd;
    QString currency_name_zh;
    QString currency_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CurrencyId = 0,
        CurrencyCd,
        CurrencyNameZh,
        CurrencyNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CurrencyId; }
    int autoValueIndex() const override { return CurrencyId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("currency"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(QString currency_cd READ getcurrency_cd WRITE setcurrency_cd)
    T_DEFINE_PROPERTY(QString, currency_cd)
    Q_PROPERTY(QString currency_name_zh READ getcurrency_name_zh WRITE setcurrency_name_zh)
    T_DEFINE_PROPERTY(QString, currency_name_zh)
    Q_PROPERTY(QString currency_name_en READ getcurrency_name_en WRITE setcurrency_name_en)
    T_DEFINE_PROPERTY(QString, currency_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // CURRENCYOBJECT_H
