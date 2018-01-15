#ifndef POLINECHARGEOBJECT_H
#define POLINECHARGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoLineChargeObject : public TSqlObject, public QSharedData
{
public:
    int po_line_id {0};
    int charge_id {0};
    double charge_amount {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoLineId = 0,
        ChargeId,
        ChargeAmount,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoLineId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ChargeId<<PoLineId; }
    QString tableName() const override { return QLatin1String("po_line_charge"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int charge_id READ getcharge_id WRITE setcharge_id)
    T_DEFINE_PROPERTY(int, charge_id)
    Q_PROPERTY(double charge_amount READ getcharge_amount WRITE setcharge_amount)
    T_DEFINE_PROPERTY(double, charge_amount)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // POLINECHARGEOBJECT_H
