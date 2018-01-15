#ifndef REFSCHEDPARTSTATUSOBJECT_H
#define REFSCHEDPARTSTATUSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefSchedPartStatusObject : public TSqlObject, public QSharedData
{
public:
    QString sched_part_status_cd;
    QString sched_part_status_name_en;
    QString sched_part_status_name_zh;
    QString sched_part_status_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedPartStatusCd = 0,
        SchedPartStatusNameEn,
        SchedPartStatusNameZh,
        SchedPartStatusDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedPartStatusCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_sched_part_status"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString sched_part_status_cd READ getsched_part_status_cd WRITE setsched_part_status_cd)
    T_DEFINE_PROPERTY(QString, sched_part_status_cd)
    Q_PROPERTY(QString sched_part_status_name_en READ getsched_part_status_name_en WRITE setsched_part_status_name_en)
    T_DEFINE_PROPERTY(QString, sched_part_status_name_en)
    Q_PROPERTY(QString sched_part_status_name_zh READ getsched_part_status_name_zh WRITE setsched_part_status_name_zh)
    T_DEFINE_PROPERTY(QString, sched_part_status_name_zh)
    Q_PROPERTY(QString sched_part_status_desc READ getsched_part_status_desc WRITE setsched_part_status_desc)
    T_DEFINE_PROPERTY(QString, sched_part_status_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFSCHEDPARTSTATUSOBJECT_H
