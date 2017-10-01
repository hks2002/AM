#ifndef TASKPANELOBJECT_H
#define TASKPANELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskPanelObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int panel_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        PanelId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<PanelId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PanelId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_panel"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int panel_id READ getpanel_id WRITE setpanel_id)
    T_DEFINE_PROPERTY(int, panel_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKPANELOBJECT_H
