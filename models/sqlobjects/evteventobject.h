#ifndef EVTEVENTOBJECT_H
#define EVTEVENTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtEventObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    QString event_type_cd;
    QString event_reason_cd;
    QString event_status_cd;
    QString event_name;
    QString event_desc;
    QDateTime event_dt;
    int nh_event_id {0};
    int h_event_id {0};
    int sub_event_ord {0};
    bool hist_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        EventTypeCd,
        EventReasonCd,
        EventStatusCd,
        EventName,
        EventDesc,
        EventDt,
        NhEventId,
        HEventId,
        SubEventOrd,
        HistBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId; }
    int autoValueIndex() const override { return EventId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<HEventId<<NhEventId<<EventStatusCd<<EventReasonCd<<EventTypeCd; }
    QString tableName() const override { return QLatin1String("evt_event"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(QString event_type_cd READ getevent_type_cd WRITE setevent_type_cd)
    T_DEFINE_PROPERTY(QString, event_type_cd)
    Q_PROPERTY(QString event_reason_cd READ getevent_reason_cd WRITE setevent_reason_cd)
    T_DEFINE_PROPERTY(QString, event_reason_cd)
    Q_PROPERTY(QString event_status_cd READ getevent_status_cd WRITE setevent_status_cd)
    T_DEFINE_PROPERTY(QString, event_status_cd)
    Q_PROPERTY(QString event_name READ getevent_name WRITE setevent_name)
    T_DEFINE_PROPERTY(QString, event_name)
    Q_PROPERTY(QString event_desc READ getevent_desc WRITE setevent_desc)
    T_DEFINE_PROPERTY(QString, event_desc)
    Q_PROPERTY(QDateTime event_dt READ getevent_dt WRITE setevent_dt)
    T_DEFINE_PROPERTY(QDateTime, event_dt)
    Q_PROPERTY(int nh_event_id READ getnh_event_id WRITE setnh_event_id)
    T_DEFINE_PROPERTY(int, nh_event_id)
    Q_PROPERTY(int h_event_id READ geth_event_id WRITE seth_event_id)
    T_DEFINE_PROPERTY(int, h_event_id)
    Q_PROPERTY(int sub_event_ord READ getsub_event_ord WRITE setsub_event_ord)
    T_DEFINE_PROPERTY(int, sub_event_ord)
    Q_PROPERTY(bool hist_bool READ gethist_bool WRITE sethist_bool)
    T_DEFINE_PROPERTY(bool, hist_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EVTEVENTOBJECT_H
