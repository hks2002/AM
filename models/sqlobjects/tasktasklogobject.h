#ifndef TASKTASKLOGOBJECT_H
#define TASKTASKLOGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskTaskLogObject : public TSqlObject, public QSharedData
{
public:
    int task_task_log_id {0};
    int task_id {0};
    QString log_action_cd;
    QDateTime log_dt;
    QString user_note;
    QString system_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskTaskLogId = 0,
        TaskId,
        LogActionCd,
        LogDt,
        UserNote,
        SystemNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskTaskLogId; }
    int autoValueIndex() const override { return TaskTaskLogId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LogActionCd<<TaskId; }
    QString tableName() const override { return QLatin1String("task_task_log"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_task_log_id READ gettask_task_log_id WRITE settask_task_log_id)
    T_DEFINE_PROPERTY(int, task_task_log_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(QString log_action_cd READ getlog_action_cd WRITE setlog_action_cd)
    T_DEFINE_PROPERTY(QString, log_action_cd)
    Q_PROPERTY(QDateTime log_dt READ getlog_dt WRITE setlog_dt)
    T_DEFINE_PROPERTY(QDateTime, log_dt)
    Q_PROPERTY(QString user_note READ getuser_note WRITE setuser_note)
    T_DEFINE_PROPERTY(QString, user_note)
    Q_PROPERTY(QString system_note READ getsystem_note WRITE setsystem_note)
    T_DEFINE_PROPERTY(QString, system_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKTASKLOGOBJECT_H
