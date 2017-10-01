#ifndef SCHEDLABOUROBJECT_H
#define SCHEDLABOUROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedLabourObject : public TSqlObject, public QSharedData
{
public:
    int sched_labour_id {0};
    int sched_id {0};
    int labour_skill_id {0};
    int labour_ord {0};
    QString labour_stage_cd;
    bool work_perf_bool;
    bool insp_bool;
    bool rii_bool;
    QString note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedLabourId = 0,
        SchedId,
        LabourSkillId,
        LabourOrd,
        LabourStageCd,
        WorkPerfBool,
        InspBool,
        RiiBool,
        Note,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedLabourId; }
    int autoValueIndex() const override { return SchedLabourId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LabourStageCd<<LabourSkillId<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_labour"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_labour_id READ getsched_labour_id WRITE setsched_labour_id)
    T_DEFINE_PROPERTY(int, sched_labour_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int labour_skill_id READ getlabour_skill_id WRITE setlabour_skill_id)
    T_DEFINE_PROPERTY(int, labour_skill_id)
    Q_PROPERTY(int labour_ord READ getlabour_ord WRITE setlabour_ord)
    T_DEFINE_PROPERTY(int, labour_ord)
    Q_PROPERTY(QString labour_stage_cd READ getlabour_stage_cd WRITE setlabour_stage_cd)
    T_DEFINE_PROPERTY(QString, labour_stage_cd)
    Q_PROPERTY(bool work_perf_bool READ getwork_perf_bool WRITE setwork_perf_bool)
    T_DEFINE_PROPERTY(bool, work_perf_bool)
    Q_PROPERTY(bool insp_bool READ getinsp_bool WRITE setinsp_bool)
    T_DEFINE_PROPERTY(bool, insp_bool)
    Q_PROPERTY(bool rii_bool READ getrii_bool WRITE setrii_bool)
    T_DEFINE_PROPERTY(bool, rii_bool)
    Q_PROPERTY(QString note READ getnote WRITE setnote)
    T_DEFINE_PROPERTY(QString, note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDLABOUROBJECT_H
