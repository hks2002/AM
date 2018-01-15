#ifndef MAINTPRGMTASKTEMPISSUELOGOBJECT_H
#define MAINTPRGMTASKTEMPISSUELOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MaintPrgmTaskTempIssueLogObject : public TSqlObject, public QSharedData
{
public:
    int task_temp_issue_log_id {0};
    int maint_prgm_id {0};
    int task_id {0};
    int temp_issue_by {0};
    QDateTime temp_issue_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskTempIssueLogId = 0,
        MaintPrgmId,
        TaskId,
        TempIssueBy,
        TempIssueDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskTempIssueLogId; }
    int autoValueIndex() const override { return TaskTempIssueLogId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TempIssueBy<<TaskId<<MaintPrgmId; }
    QString tableName() const override { return QLatin1String("maint_prgm_task_temp_issue_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_temp_issue_log_id READ gettask_temp_issue_log_id WRITE settask_temp_issue_log_id)
    T_DEFINE_PROPERTY(int, task_temp_issue_log_id)
    Q_PROPERTY(int maint_prgm_id READ getmaint_prgm_id WRITE setmaint_prgm_id)
    T_DEFINE_PROPERTY(int, maint_prgm_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int temp_issue_by READ gettemp_issue_by WRITE settemp_issue_by)
    T_DEFINE_PROPERTY(int, temp_issue_by)
    Q_PROPERTY(QDateTime temp_issue_dt READ gettemp_issue_dt WRITE settemp_issue_dt)
    T_DEFINE_PROPERTY(QDateTime, temp_issue_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MAINTPRGMTASKTEMPISSUELOGOBJECT_H
