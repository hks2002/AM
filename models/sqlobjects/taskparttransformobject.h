#ifndef TASKPARTTRANSFORMOBJECT_H
#define TASKPARTTRANSFORMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskPartTransformObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int old_part_no_id {0};
    int new_part_no_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        OldPartNoId,
        NewPartNoId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<OldPartNoId<<NewPartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<NewPartNoId<<OldPartNoId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_part_transform"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int old_part_no_id READ getold_part_no_id WRITE setold_part_no_id)
    T_DEFINE_PROPERTY(int, old_part_no_id)
    Q_PROPERTY(int new_part_no_id READ getnew_part_no_id WRITE setnew_part_no_id)
    T_DEFINE_PROPERTY(int, new_part_no_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKPARTTRANSFORMOBJECT_H
