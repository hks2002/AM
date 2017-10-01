#ifndef SCHEDPARTOBJECT_H
#define SCHEDPARTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedPartObject : public TSqlObject, public QSharedData
{
public:
    int sched_part_id {0};
    int sched_id {0};
    int assmbl_id {0};
    int assmbl_bom_id {0};
    int part_no_id {0};
    int assmbl_bom_pos_id {0};
    QString part_note;
    int sched_qt {0};
    QString req_action_cd;
    QString sched_part_status_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedPartId = 0,
        SchedId,
        AssmblId,
        AssmblBomId,
        PartNoId,
        AssmblBomPosId,
        PartNote,
        SchedQt,
        ReqActionCd,
        SchedPartStatusCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedPartId; }
    int autoValueIndex() const override { return SchedPartId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SchedPartStatusCd<<ReqActionCd<<AssmblBomPosId<<PartNoId<<AssmblBomId<<AssmblId<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_part"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_part_id READ getsched_part_id WRITE setsched_part_id)
    T_DEFINE_PROPERTY(int, sched_part_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int assmbl_bom_pos_id READ getassmbl_bom_pos_id WRITE setassmbl_bom_pos_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_pos_id)
    Q_PROPERTY(QString part_note READ getpart_note WRITE setpart_note)
    T_DEFINE_PROPERTY(QString, part_note)
    Q_PROPERTY(int sched_qt READ getsched_qt WRITE setsched_qt)
    T_DEFINE_PROPERTY(int, sched_qt)
    Q_PROPERTY(QString req_action_cd READ getreq_action_cd WRITE setreq_action_cd)
    T_DEFINE_PROPERTY(QString, req_action_cd)
    Q_PROPERTY(QString sched_part_status_cd READ getsched_part_status_cd WRITE setsched_part_status_cd)
    T_DEFINE_PROPERTY(QString, sched_part_status_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDPARTOBJECT_H
