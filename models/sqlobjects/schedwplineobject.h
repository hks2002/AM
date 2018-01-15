#ifndef SCHEDWPLINEOBJECT_H
#define SCHEDWPLINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedWpLineObject : public TSqlObject, public QSharedData
{
public:
    int sched_wp_id {0};
    int sched_id {0};
    int workscope_order {0};
    QString vendor_line_no;
    bool unassign_bool;
    QDateTime assign_dt;
    int assign_by {0};
    QDateTime unassign_dt;
    int unassign_by {0};
    bool collected_bool;
    int collected_by {0};
    QDateTime collected_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedWpId = 0,
        SchedId,
        WorkscopeOrder,
        VendorLineNo,
        UnassignBool,
        AssignDt,
        AssignBy,
        UnassignDt,
        UnassignBy,
        CollectedBool,
        CollectedBy,
        CollectedDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedWpId<<SchedId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CollectedBy<<UnassignBy<<AssignBy<<SchedId<<SchedWpId; }
    QString tableName() const override { return QLatin1String("sched_wp_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_wp_id READ getsched_wp_id WRITE setsched_wp_id)
    T_DEFINE_PROPERTY(int, sched_wp_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int workscope_order READ getworkscope_order WRITE setworkscope_order)
    T_DEFINE_PROPERTY(int, workscope_order)
    Q_PROPERTY(QString vendor_line_no READ getvendor_line_no WRITE setvendor_line_no)
    T_DEFINE_PROPERTY(QString, vendor_line_no)
    Q_PROPERTY(bool unassign_bool READ getunassign_bool WRITE setunassign_bool)
    T_DEFINE_PROPERTY(bool, unassign_bool)
    Q_PROPERTY(QDateTime assign_dt READ getassign_dt WRITE setassign_dt)
    T_DEFINE_PROPERTY(QDateTime, assign_dt)
    Q_PROPERTY(int assign_by READ getassign_by WRITE setassign_by)
    T_DEFINE_PROPERTY(int, assign_by)
    Q_PROPERTY(QDateTime unassign_dt READ getunassign_dt WRITE setunassign_dt)
    T_DEFINE_PROPERTY(QDateTime, unassign_dt)
    Q_PROPERTY(int unassign_by READ getunassign_by WRITE setunassign_by)
    T_DEFINE_PROPERTY(int, unassign_by)
    Q_PROPERTY(bool collected_bool READ getcollected_bool WRITE setcollected_bool)
    T_DEFINE_PROPERTY(bool, collected_bool)
    Q_PROPERTY(int collected_by READ getcollected_by WRITE setcollected_by)
    T_DEFINE_PROPERTY(int, collected_by)
    Q_PROPERTY(QDateTime collected_dt READ getcollected_dt WRITE setcollected_dt)
    T_DEFINE_PROPERTY(QDateTime, collected_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // SCHEDWPLINEOBJECT_H
