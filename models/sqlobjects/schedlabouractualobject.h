#ifndef SCHEDLABOURACTUALOBJECT_H
#define SCHEDLABOURACTUALOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedLabourActualObject : public TSqlObject, public QSharedData
{
public:
    int sched_labour_id {0};
    QString labour_role_type_cd;
    int actual_by {0};
    double adjusted_billing_hr {0};
    QString labour_time_cd;
    double labour_cost {0};
    QDateTime actual_start_dt;
    QDateTime actual_end_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedLabourId = 0,
        LabourRoleTypeCd,
        ActualBy,
        AdjustedBillingHr,
        LabourTimeCd,
        LabourCost,
        ActualStartDt,
        ActualEndDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedLabourId<<LabourRoleTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ActualBy<<LabourRoleTypeCd<<SchedLabourId; }
    QString tableName() const override { return QLatin1String("sched_labour_actual"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_labour_id READ getsched_labour_id WRITE setsched_labour_id)
    T_DEFINE_PROPERTY(int, sched_labour_id)
    Q_PROPERTY(QString labour_role_type_cd READ getlabour_role_type_cd WRITE setlabour_role_type_cd)
    T_DEFINE_PROPERTY(QString, labour_role_type_cd)
    Q_PROPERTY(int actual_by READ getactual_by WRITE setactual_by)
    T_DEFINE_PROPERTY(int, actual_by)
    Q_PROPERTY(double adjusted_billing_hr READ getadjusted_billing_hr WRITE setadjusted_billing_hr)
    T_DEFINE_PROPERTY(double, adjusted_billing_hr)
    Q_PROPERTY(QString labour_time_cd READ getlabour_time_cd WRITE setlabour_time_cd)
    T_DEFINE_PROPERTY(QString, labour_time_cd)
    Q_PROPERTY(double labour_cost READ getlabour_cost WRITE setlabour_cost)
    T_DEFINE_PROPERTY(double, labour_cost)
    Q_PROPERTY(QDateTime actual_start_dt READ getactual_start_dt WRITE setactual_start_dt)
    T_DEFINE_PROPERTY(QDateTime, actual_start_dt)
    Q_PROPERTY(QDateTime actual_end_dt READ getactual_end_dt WRITE setactual_end_dt)
    T_DEFINE_PROPERTY(QDateTime, actual_end_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDLABOURACTUALOBJECT_H
