#ifndef SCHEDTOOLOBJECT_H
#define SCHEDTOOLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedToolObject : public TSqlObject, public QSharedData
{
public:
    int sched_tool_id {0};
    int sched_id {0};
    int assmbl_id {0};
    int assmbl_bom_id {0};
    int part_no_id {0};
    QString part_note;
    int sched_qt {0};
    QString sched_usetime;
    QString actual_usetime;
    int check_out_to_user {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedToolId = 0,
        SchedId,
        AssmblId,
        AssmblBomId,
        PartNoId,
        PartNote,
        SchedQt,
        SchedUsetime,
        ActualUsetime,
        CheckOutToUser,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedToolId; }
    int autoValueIndex() const override { return SchedToolId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CheckOutToUser<<PartNoId<<AssmblBomId<<AssmblId<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_tool"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_tool_id READ getsched_tool_id WRITE setsched_tool_id)
    T_DEFINE_PROPERTY(int, sched_tool_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString part_note READ getpart_note WRITE setpart_note)
    T_DEFINE_PROPERTY(QString, part_note)
    Q_PROPERTY(int sched_qt READ getsched_qt WRITE setsched_qt)
    T_DEFINE_PROPERTY(int, sched_qt)
    Q_PROPERTY(QString sched_usetime READ getsched_usetime WRITE setsched_usetime)
    T_DEFINE_PROPERTY(QString, sched_usetime)
    Q_PROPERTY(QString actual_usetime READ getactual_usetime WRITE setactual_usetime)
    T_DEFINE_PROPERTY(QString, actual_usetime)
    Q_PROPERTY(int check_out_to_user READ getcheck_out_to_user WRITE setcheck_out_to_user)
    T_DEFINE_PROPERTY(int, check_out_to_user)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDTOOLOBJECT_H
