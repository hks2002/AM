#ifndef SCHEDSTEPLABOUROBJECT_H
#define SCHEDSTEPLABOUROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedStepLabourObject : public TSqlObject, public QSharedData
{
public:
    int step_id {0};
    QString labour_role_type_cd;
    int actual_by {0};
    QDateTime actual_start_dt;
    QDateTime actual_end_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        StepId = 0,
        LabourRoleTypeCd,
        ActualBy,
        ActualStartDt,
        ActualEndDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<StepId<<LabourRoleTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ActualBy<<LabourRoleTypeCd<<StepId; }
    QString tableName() const override { return QLatin1String("sched_step_labour"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int step_id READ getstep_id WRITE setstep_id)
    T_DEFINE_PROPERTY(int, step_id)
    Q_PROPERTY(QString labour_role_type_cd READ getlabour_role_type_cd WRITE setlabour_role_type_cd)
    T_DEFINE_PROPERTY(QString, labour_role_type_cd)
    Q_PROPERTY(int actual_by READ getactual_by WRITE setactual_by)
    T_DEFINE_PROPERTY(int, actual_by)
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


#endif // SCHEDSTEPLABOUROBJECT_H
