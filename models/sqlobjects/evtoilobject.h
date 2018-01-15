#ifndef EVTOILOBJECT_H
#define EVTOILOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtOilObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    int mesur_unit_id {0};
    double fill_qty {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        MesurUnitId,
        FillQty,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<MesurUnitId<<EventId; }
    QString tableName() const override { return QLatin1String("evt_oil"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int mesur_unit_id READ getmesur_unit_id WRITE setmesur_unit_id)
    T_DEFINE_PROPERTY(int, mesur_unit_id)
    Q_PROPERTY(double fill_qty READ getfill_qty WRITE setfill_qty)
    T_DEFINE_PROPERTY(double, fill_qty)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EVTOILOBJECT_H
