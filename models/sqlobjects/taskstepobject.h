#ifndef TASKSTEPOBJECT_H
#define TASKSTEPOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskStepObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int step_ord {0};
    QString step_desc;
    bool sign_bool;
    bool insp_bool;
    bool rii_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        StepOrd,
        StepDesc,
        SignBool,
        InspBool,
        RiiBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<StepOrd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<TaskId; }
    QString tableName() const override { return QLatin1String("task_step"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int step_ord READ getstep_ord WRITE setstep_ord)
    T_DEFINE_PROPERTY(int, step_ord)
    Q_PROPERTY(QString step_desc READ getstep_desc WRITE setstep_desc)
    T_DEFINE_PROPERTY(QString, step_desc)
    Q_PROPERTY(bool sign_bool READ getsign_bool WRITE setsign_bool)
    T_DEFINE_PROPERTY(bool, sign_bool)
    Q_PROPERTY(bool insp_bool READ getinsp_bool WRITE setinsp_bool)
    T_DEFINE_PROPERTY(bool, insp_bool)
    Q_PROPERTY(bool rii_bool READ getrii_bool WRITE setrii_bool)
    T_DEFINE_PROPERTY(bool, rii_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKSTEPOBJECT_H
