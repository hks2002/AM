#ifndef SCHEDRMVDPARTOBJECT_H
#define SCHEDRMVDPARTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedRmvdPartObject : public TSqlObject, public QSharedData
{
public:
    int sched_part_id {0};
    int inv_no_id {0};
    int part_no_id {0};
    QString serial_no_oem;
    QString remove_reason_cd;
    int rmvd_qt {0};
    int rmvd_by {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedPartId = 0,
        InvNoId,
        PartNoId,
        SerialNoOem,
        RemoveReasonCd,
        RmvdQt,
        RmvdBy,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedPartId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RmvdBy<<RemoveReasonCd<<PartNoId<<InvNoId<<SchedPartId; }
    QString tableName() const override { return QLatin1String("sched_rmvd_part"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_part_id READ getsched_part_id WRITE setsched_part_id)
    T_DEFINE_PROPERTY(int, sched_part_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString serial_no_oem READ getserial_no_oem WRITE setserial_no_oem)
    T_DEFINE_PROPERTY(QString, serial_no_oem)
    Q_PROPERTY(QString remove_reason_cd READ getremove_reason_cd WRITE setremove_reason_cd)
    T_DEFINE_PROPERTY(QString, remove_reason_cd)
    Q_PROPERTY(int rmvd_qt READ getrmvd_qt WRITE setrmvd_qt)
    T_DEFINE_PROPERTY(int, rmvd_qt)
    Q_PROPERTY(int rmvd_by READ getrmvd_by WRITE setrmvd_by)
    T_DEFINE_PROPERTY(int, rmvd_by)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDRMVDPARTOBJECT_H
