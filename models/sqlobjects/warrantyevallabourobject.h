#ifndef WARRANTYEVALLABOUROBJECT_H
#define WARRANTYEVALLABOUROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyEvalLabourObject : public TSqlObject, public QSharedData
{
public:
    int warranty_eval_id {0};
    int sched_id {0};
    int labour_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyEvalId = 0,
        SchedId,
        LabourId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyEvalId<<SchedId<<LabourId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LabourId<<WarrantyEvalId<<SchedId; }
    QString tableName() const override { return QLatin1String("warranty_eval_labour"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_eval_id READ getwarranty_eval_id WRITE setwarranty_eval_id)
    T_DEFINE_PROPERTY(int, warranty_eval_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int labour_id READ getlabour_id WRITE setlabour_id)
    T_DEFINE_PROPERTY(int, labour_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // WARRANTYEVALLABOUROBJECT_H
