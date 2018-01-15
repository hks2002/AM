#ifndef TASKTASKDEPOBJECT_H
#define TASKTASKDEPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskTaskDepObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int task_dep_id {0};
    QString task_dep_action_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        TaskDepId,
        TaskDepActionCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<TaskDepId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskDepActionCd<<TaskDepId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_task_dep"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int task_dep_id READ gettask_dep_id WRITE settask_dep_id)
    T_DEFINE_PROPERTY(int, task_dep_id)
    Q_PROPERTY(QString task_dep_action_cd READ gettask_dep_action_cd WRITE settask_dep_action_cd)
    T_DEFINE_PROPERTY(QString, task_dep_action_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKTASKDEPOBJECT_H
