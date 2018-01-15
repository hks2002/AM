#ifndef TASKORIGINATOROBJECT_H
#define TASKORIGINATOROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskOriginatorObject : public TSqlObject, public QSharedData
{
public:
    int task_originator_id {0};
    QString task_originator_cd;
    QString task_originator_name_zh;
    QString task_originator_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskOriginatorId = 0,
        TaskOriginatorCd,
        TaskOriginatorNameZh,
        TaskOriginatorNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskOriginatorId; }
    int autoValueIndex() const override { return TaskOriginatorId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("task_originator"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_originator_id READ gettask_originator_id WRITE settask_originator_id)
    T_DEFINE_PROPERTY(int, task_originator_id)
    Q_PROPERTY(QString task_originator_cd READ gettask_originator_cd WRITE settask_originator_cd)
    T_DEFINE_PROPERTY(QString, task_originator_cd)
    Q_PROPERTY(QString task_originator_name_zh READ gettask_originator_name_zh WRITE settask_originator_name_zh)
    T_DEFINE_PROPERTY(QString, task_originator_name_zh)
    Q_PROPERTY(QString task_originator_name_en READ gettask_originator_name_en WRITE settask_originator_name_en)
    T_DEFINE_PROPERTY(QString, task_originator_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // TASKORIGINATOROBJECT_H
