#ifndef INVADJUSTOBJECT_H
#define INVADJUSTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvAdjustObject : public TSqlObject, public QSharedData
{
public:
    int inv_adjust_id {0};
    int event_id {0};
    int inv_no_id {0};
    int part_no_id {0};
    int po_id {0};
    int po_line_id {0};
    QString xaction_type_cd;
    int adjust_by {0};
    QDateTime adjust_dt;
    int adjust_qt {0};
    QString user_note;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvAdjustId = 0,
        EventId,
        InvNoId,
        PartNoId,
        PoId,
        PoLineId,
        XactionTypeCd,
        AdjustBy,
        AdjustDt,
        AdjustQt,
        UserNote,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvAdjustId; }
    int autoValueIndex() const override { return InvAdjustId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AdjustBy<<XactionTypeCd<<PoLineId<<PoId<<PartNoId<<InvNoId<<EventId; }
    QString tableName() const override { return QLatin1String("inv_adjust"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_adjust_id READ getinv_adjust_id WRITE setinv_adjust_id)
    T_DEFINE_PROPERTY(int, inv_adjust_id)
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(QString xaction_type_cd READ getxaction_type_cd WRITE setxaction_type_cd)
    T_DEFINE_PROPERTY(QString, xaction_type_cd)
    Q_PROPERTY(int adjust_by READ getadjust_by WRITE setadjust_by)
    T_DEFINE_PROPERTY(int, adjust_by)
    Q_PROPERTY(QDateTime adjust_dt READ getadjust_dt WRITE setadjust_dt)
    T_DEFINE_PROPERTY(QDateTime, adjust_dt)
    Q_PROPERTY(int adjust_qt READ getadjust_qt WRITE setadjust_qt)
    T_DEFINE_PROPERTY(int, adjust_qt)
    Q_PROPERTY(QString user_note READ getuser_note WRITE setuser_note)
    T_DEFINE_PROPERTY(QString, user_note)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // INVADJUSTOBJECT_H
