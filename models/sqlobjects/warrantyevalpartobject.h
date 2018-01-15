#ifndef WARRANTYEVALPARTOBJECT_H
#define WARRANTYEVALPARTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyEvalPartObject : public TSqlObject, public QSharedData
{
public:
    int warranty_eval_id {0};
    int sched_id {0};
    int sched_part_id {0};
    bool rtrn_req_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyEvalId = 0,
        SchedId,
        SchedPartId,
        RtrnReqBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyEvalId<<SchedId<<SchedPartId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SchedPartId<<WarrantyEvalId<<SchedId; }
    QString tableName() const override { return QLatin1String("warranty_eval_part"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_eval_id READ getwarranty_eval_id WRITE setwarranty_eval_id)
    T_DEFINE_PROPERTY(int, warranty_eval_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int sched_part_id READ getsched_part_id WRITE setsched_part_id)
    T_DEFINE_PROPERTY(int, sched_part_id)
    Q_PROPERTY(bool rtrn_req_bool READ getrtrn_req_bool WRITE setrtrn_req_bool)
    T_DEFINE_PROPERTY(bool, rtrn_req_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // WARRANTYEVALPARTOBJECT_H
