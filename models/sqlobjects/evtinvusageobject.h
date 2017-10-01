#ifndef EVTINVUSAGEOBJECT_H
#define EVTINVUSAGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtInvUsageObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    int inv_no_id {0};
    int data_type_id {0};
    int leg_id {0};
    double tsi_qt {0};
    double tsn_qt {0};
    double tso_qt {0};
    double h_tsn_qt {0};
    double h_tso_qt {0};
    double nh_tsn_qt {0};
    double nh_tso_qt {0};
    double assmbl_tsn_qt {0};
    double assmbl_tso_qt {0};
    bool negated_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        InvNoId,
        DataTypeId,
        LegId,
        TsiQt,
        TsnQt,
        TsoQt,
        HTsnQt,
        HTsoQt,
        NhTsnQt,
        NhTsoQt,
        AssmblTsnQt,
        AssmblTsoQt,
        NegatedBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId<<InvNoId<<DataTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LegId<<DataTypeId<<InvNoId<<EventId; }
    QString tableName() const override { return QLatin1String("evt_inv_usage"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(int leg_id READ getleg_id WRITE setleg_id)
    T_DEFINE_PROPERTY(int, leg_id)
    Q_PROPERTY(double tsi_qt READ gettsi_qt WRITE settsi_qt)
    T_DEFINE_PROPERTY(double, tsi_qt)
    Q_PROPERTY(double tsn_qt READ gettsn_qt WRITE settsn_qt)
    T_DEFINE_PROPERTY(double, tsn_qt)
    Q_PROPERTY(double tso_qt READ gettso_qt WRITE settso_qt)
    T_DEFINE_PROPERTY(double, tso_qt)
    Q_PROPERTY(double h_tsn_qt READ geth_tsn_qt WRITE seth_tsn_qt)
    T_DEFINE_PROPERTY(double, h_tsn_qt)
    Q_PROPERTY(double h_tso_qt READ geth_tso_qt WRITE seth_tso_qt)
    T_DEFINE_PROPERTY(double, h_tso_qt)
    Q_PROPERTY(double nh_tsn_qt READ getnh_tsn_qt WRITE setnh_tsn_qt)
    T_DEFINE_PROPERTY(double, nh_tsn_qt)
    Q_PROPERTY(double nh_tso_qt READ getnh_tso_qt WRITE setnh_tso_qt)
    T_DEFINE_PROPERTY(double, nh_tso_qt)
    Q_PROPERTY(double assmbl_tsn_qt READ getassmbl_tsn_qt WRITE setassmbl_tsn_qt)
    T_DEFINE_PROPERTY(double, assmbl_tsn_qt)
    Q_PROPERTY(double assmbl_tso_qt READ getassmbl_tso_qt WRITE setassmbl_tso_qt)
    T_DEFINE_PROPERTY(double, assmbl_tso_qt)
    Q_PROPERTY(bool negated_bool READ getnegated_bool WRITE setnegated_bool)
    T_DEFINE_PROPERTY(bool, negated_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EVTINVUSAGEOBJECT_H
