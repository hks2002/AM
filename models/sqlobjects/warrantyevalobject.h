#ifndef WARRANTYEVALOBJECT_H
#define WARRANTYEVALOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyEvalObject : public TSqlObject, public QSharedData
{
public:
    int warranty_eval_id {0};
    int warranty_init_id {0};
    QString warranty_eval_status_cd;
    int reject_by {0};
    QDateTime reject_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyEvalId = 0,
        WarrantyInitId,
        WarrantyEvalStatusCd,
        RejectBy,
        RejectDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyEvalId; }
    int autoValueIndex() const override { return WarrantyEvalId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RejectBy<<WarrantyEvalStatusCd<<WarrantyInitId; }
    QString tableName() const override { return QLatin1String("warranty_eval"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_eval_id READ getwarranty_eval_id WRITE setwarranty_eval_id)
    T_DEFINE_PROPERTY(int, warranty_eval_id)
    Q_PROPERTY(int warranty_init_id READ getwarranty_init_id WRITE setwarranty_init_id)
    T_DEFINE_PROPERTY(int, warranty_init_id)
    Q_PROPERTY(QString warranty_eval_status_cd READ getwarranty_eval_status_cd WRITE setwarranty_eval_status_cd)
    T_DEFINE_PROPERTY(QString, warranty_eval_status_cd)
    Q_PROPERTY(int reject_by READ getreject_by WRITE setreject_by)
    T_DEFINE_PROPERTY(int, reject_by)
    Q_PROPERTY(QDateTime reject_dt READ getreject_dt WRITE setreject_dt)
    T_DEFINE_PROPERTY(QDateTime, reject_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // WARRANTYEVALOBJECT_H
