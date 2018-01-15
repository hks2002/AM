#ifndef TASKSUBCLASSOBJECT_H
#define TASKSUBCLASSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskSubclassObject : public TSqlObject, public QSharedData
{
public:
    int task_subclass_id {0};
    QString task_subclass_cd;
    QString task_subclass_name_zh;
    QString task_subclass_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskSubclassId = 0,
        TaskSubclassCd,
        TaskSubclassNameZh,
        TaskSubclassNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskSubclassId; }
    int autoValueIndex() const override { return TaskSubclassId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("task_subclass"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_subclass_id READ gettask_subclass_id WRITE settask_subclass_id)
    T_DEFINE_PROPERTY(int, task_subclass_id)
    Q_PROPERTY(QString task_subclass_cd READ gettask_subclass_cd WRITE settask_subclass_cd)
    T_DEFINE_PROPERTY(QString, task_subclass_cd)
    Q_PROPERTY(QString task_subclass_name_zh READ gettask_subclass_name_zh WRITE settask_subclass_name_zh)
    T_DEFINE_PROPERTY(QString, task_subclass_name_zh)
    Q_PROPERTY(QString task_subclass_name_en READ gettask_subclass_name_en WRITE settask_subclass_name_en)
    T_DEFINE_PROPERTY(QString, task_subclass_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKSUBCLASSOBJECT_H
