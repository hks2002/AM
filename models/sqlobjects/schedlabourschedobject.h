#ifndef SCHEDLABOURSCHEDOBJECT_H
#define SCHEDLABOURSCHEDOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedLabourSchedObject : public TSqlObject, public QSharedData
{
public:
    int sched_labour_id {0};
    QString labour_role_type_cd;
    int sched_to {0};
    QString labour_role_status_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedLabourId = 0,
        LabourRoleTypeCd,
        SchedTo,
        LabourRoleStatusCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedLabourId<<LabourRoleTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LabourRoleStatusCd<<SchedTo<<LabourRoleTypeCd<<SchedLabourId; }
    QString tableName() const override { return QLatin1String("sched_labour_sched"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_labour_id READ getsched_labour_id WRITE setsched_labour_id)
    T_DEFINE_PROPERTY(int, sched_labour_id)
    Q_PROPERTY(QString labour_role_type_cd READ getlabour_role_type_cd WRITE setlabour_role_type_cd)
    T_DEFINE_PROPERTY(QString, labour_role_type_cd)
    Q_PROPERTY(int sched_to READ getsched_to WRITE setsched_to)
    T_DEFINE_PROPERTY(int, sched_to)
    Q_PROPERTY(QString labour_role_status_cd READ getlabour_role_status_cd WRITE setlabour_role_status_cd)
    T_DEFINE_PROPERTY(QString, labour_role_status_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // SCHEDLABOURSCHEDOBJECT_H
