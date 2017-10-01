#ifndef TASKLABOURREQOBJECT_H
#define TASKLABOURREQOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskLabourReqObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int labour_skill_id {0};
    QString man_hour;
    int man_ct {0};
    bool insp_bool;
    double insp_hour {0};
    int insp_license {0};
    bool rii_bool;
    double rii_hour {0};
    int rii_license {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        LabourSkillId,
        ManHour,
        ManCt,
        InspBool,
        InspHour,
        InspLicense,
        RiiBool,
        RiiHour,
        RiiLicense,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<LabourSkillId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RiiLicense<<InspLicense<<LabourSkillId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_labour_req"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int labour_skill_id READ getlabour_skill_id WRITE setlabour_skill_id)
    T_DEFINE_PROPERTY(int, labour_skill_id)
    Q_PROPERTY(QString man_hour READ getman_hour WRITE setman_hour)
    T_DEFINE_PROPERTY(QString, man_hour)
    Q_PROPERTY(int man_ct READ getman_ct WRITE setman_ct)
    T_DEFINE_PROPERTY(int, man_ct)
    Q_PROPERTY(bool insp_bool READ getinsp_bool WRITE setinsp_bool)
    T_DEFINE_PROPERTY(bool, insp_bool)
    Q_PROPERTY(double insp_hour READ getinsp_hour WRITE setinsp_hour)
    T_DEFINE_PROPERTY(double, insp_hour)
    Q_PROPERTY(int insp_license READ getinsp_license WRITE setinsp_license)
    T_DEFINE_PROPERTY(int, insp_license)
    Q_PROPERTY(bool rii_bool READ getrii_bool WRITE setrii_bool)
    T_DEFINE_PROPERTY(bool, rii_bool)
    Q_PROPERTY(double rii_hour READ getrii_hour WRITE setrii_hour)
    T_DEFINE_PROPERTY(double, rii_hour)
    Q_PROPERTY(int rii_license READ getrii_license WRITE setrii_license)
    T_DEFINE_PROPERTY(int, rii_license)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKLABOURREQOBJECT_H
