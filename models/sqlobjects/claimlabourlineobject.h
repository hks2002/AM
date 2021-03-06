#ifndef CLAIMLABOURLINEOBJECT_H
#define CLAIMLABOURLINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ClaimLabourLineObject : public TSqlObject, public QSharedData
{
public:
    int claim_id {0};
    int warranty_eval_id {0};
    int sched_id {0};
    int labour_id {0};
    QString line_desc;
    int claim_qt {0};
    double unit_price {0};
    double line_price {0};
    QString note;
    bool reject_warranty_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ClaimId = 0,
        WarrantyEvalId,
        SchedId,
        LabourId,
        LineDesc,
        ClaimQt,
        UnitPrice,
        LinePrice,
        Note,
        RejectWarrantyBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ClaimId<<WarrantyEvalId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<WarrantyEvalId<<SchedId<<LabourId<<ClaimId; }
    QString tableName() const override { return QLatin1String("claim_labour_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int claim_id READ getclaim_id WRITE setclaim_id)
    T_DEFINE_PROPERTY(int, claim_id)
    Q_PROPERTY(int warranty_eval_id READ getwarranty_eval_id WRITE setwarranty_eval_id)
    T_DEFINE_PROPERTY(int, warranty_eval_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int labour_id READ getlabour_id WRITE setlabour_id)
    T_DEFINE_PROPERTY(int, labour_id)
    Q_PROPERTY(QString line_desc READ getline_desc WRITE setline_desc)
    T_DEFINE_PROPERTY(QString, line_desc)
    Q_PROPERTY(int claim_qt READ getclaim_qt WRITE setclaim_qt)
    T_DEFINE_PROPERTY(int, claim_qt)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(double line_price READ getline_price WRITE setline_price)
    T_DEFINE_PROPERTY(double, line_price)
    Q_PROPERTY(QString note READ getnote WRITE setnote)
    T_DEFINE_PROPERTY(QString, note)
    Q_PROPERTY(bool reject_warranty_bool READ getreject_warranty_bool WRITE setreject_warranty_bool)
    T_DEFINE_PROPERTY(bool, reject_warranty_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // CLAIMLABOURLINEOBJECT_H
