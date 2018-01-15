#ifndef INVXFEROBJECT_H
#define INVXFEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvXferObject : public TSqlObject, public QSharedData
{
public:
    int inv_xfer_id {0};
    int inv_no_id {0};
    int event_id {0};
    QString xfer_type_cd;
    int xfer_qt {0};
    double unit_price {0};
    int received_by {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvXferId = 0,
        InvNoId,
        EventId,
        XferTypeCd,
        XferQt,
        UnitPrice,
        ReceivedBy,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvXferId; }
    int autoValueIndex() const override { return InvXferId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ReceivedBy<<XferTypeCd<<EventId<<InvNoId; }
    QString tableName() const override { return QLatin1String("inv_xfer"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_xfer_id READ getinv_xfer_id WRITE setinv_xfer_id)
    T_DEFINE_PROPERTY(int, inv_xfer_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(QString xfer_type_cd READ getxfer_type_cd WRITE setxfer_type_cd)
    T_DEFINE_PROPERTY(QString, xfer_type_cd)
    Q_PROPERTY(int xfer_qt READ getxfer_qt WRITE setxfer_qt)
    T_DEFINE_PROPERTY(int, xfer_qt)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(int received_by READ getreceived_by WRITE setreceived_by)
    T_DEFINE_PROPERTY(int, received_by)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // INVXFEROBJECT_H
