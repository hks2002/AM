#ifndef SCHEDTASKDEADLINEEXTOBJECT_H
#define SCHEDTASKDEADLINEEXTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedTaskDeadlineExtObject : public TSqlObject, public QSharedData
{
public:
    int sched_id {0};
    int data_type_id {0};
    int deviation_qt {0};
    QString extend_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedId = 0,
        DataTypeId,
        DeviationQt,
        ExtendNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedId<<DataTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<DataTypeId<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_task_deadline_ext"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(int deviation_qt READ getdeviation_qt WRITE setdeviation_qt)
    T_DEFINE_PROPERTY(int, deviation_qt)
    Q_PROPERTY(QString extend_note READ getextend_note WRITE setextend_note)
    T_DEFINE_PROPERTY(QString, extend_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDTASKDEADLINEEXTOBJECT_H
