#ifndef EVTINVOBJECT_H
#define EVTINVOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtInvObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    int inv_no_id {0};
    int nh_inv_no_id {0};
    int assmbl_inv_no_id {0};
    int h_inv_no_id {0};
    int assmbl_bom_id {0};
    int assmbl_id {0};
    int assmbl_bom_pos_id {0};
    int part_no_id {0};
    bool main_inv_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        InvNoId,
        NhInvNoId,
        AssmblInvNoId,
        HInvNoId,
        AssmblBomId,
        AssmblId,
        AssmblBomPosId,
        PartNoId,
        MainInvBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId<<InvNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<AssmblBomPosId<<AssmblId<<AssmblBomId<<HInvNoId<<AssmblInvNoId<<NhInvNoId<<InvNoId<<EventId; }
    QString tableName() const override { return QLatin1String("evt_inv"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int nh_inv_no_id READ getnh_inv_no_id WRITE setnh_inv_no_id)
    T_DEFINE_PROPERTY(int, nh_inv_no_id)
    Q_PROPERTY(int assmbl_inv_no_id READ getassmbl_inv_no_id WRITE setassmbl_inv_no_id)
    T_DEFINE_PROPERTY(int, assmbl_inv_no_id)
    Q_PROPERTY(int h_inv_no_id READ geth_inv_no_id WRITE seth_inv_no_id)
    T_DEFINE_PROPERTY(int, h_inv_no_id)
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(int assmbl_bom_pos_id READ getassmbl_bom_pos_id WRITE setassmbl_bom_pos_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_pos_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(bool main_inv_bool READ getmain_inv_bool WRITE setmain_inv_bool)
    T_DEFINE_PROPERTY(bool, main_inv_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EVTINVOBJECT_H
