#ifndef TASKLABOURSUMMARYOBJECT_H
#define TASKLABOURSUMMARYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskLabourSummaryObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int task_defn_id {0};
    int sched_id {0};
    int labour_skill_id {0};
    double sched_man_hr {0};
    int sched_man_pwr_ct {0};
    double actual_total_man_hr {0};
    int actual_man_pwr_ct {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        TaskDefnId,
        SchedId,
        LabourSkillId,
        SchedManHr,
        SchedManPwrCt,
        ActualTotalManHr,
        ActualManPwrCt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<TaskDefnId<<SchedId<<LabourSkillId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LabourSkillId<<SchedId<<TaskDefnId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_labour_summary"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int task_defn_id READ gettask_defn_id WRITE settask_defn_id)
    T_DEFINE_PROPERTY(int, task_defn_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int labour_skill_id READ getlabour_skill_id WRITE setlabour_skill_id)
    T_DEFINE_PROPERTY(int, labour_skill_id)
    Q_PROPERTY(double sched_man_hr READ getsched_man_hr WRITE setsched_man_hr)
    T_DEFINE_PROPERTY(double, sched_man_hr)
    Q_PROPERTY(int sched_man_pwr_ct READ getsched_man_pwr_ct WRITE setsched_man_pwr_ct)
    T_DEFINE_PROPERTY(int, sched_man_pwr_ct)
    Q_PROPERTY(double actual_total_man_hr READ getactual_total_man_hr WRITE setactual_total_man_hr)
    T_DEFINE_PROPERTY(double, actual_total_man_hr)
    Q_PROPERTY(int actual_man_pwr_ct READ getactual_man_pwr_ct WRITE setactual_man_pwr_ct)
    T_DEFINE_PROPERTY(int, actual_man_pwr_ct)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKLABOURSUMMARYOBJECT_H
