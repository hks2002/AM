#ifndef SHIPSHIPMENTLINEOBJECT_H
#define SHIPSHIPMENTLINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ShipShipmentLineObject : public TSqlObject, public QSharedData
{
public:
    int shipment_line_id {0};
    int shipment_id {0};
    int line_no_ord {0};
    int po_id {0};
    int po_line_id {0};
    int part_no_id {0};
    int expect_qt {0};
    QString inv_cond_cd;
    QString serial_no_oem;
    int inv_no_id {0};
    QString rcv_priority_cd;
    bool received_doc_bool;
    QString shipment_line_notes;
    int received_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ShipmentLineId = 0,
        ShipmentId,
        LineNoOrd,
        PoId,
        PoLineId,
        PartNoId,
        ExpectQt,
        InvCondCd,
        SerialNoOem,
        InvNoId,
        RcvPriorityCd,
        ReceivedDocBool,
        ShipmentLineNotes,
        ReceivedQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ShipmentLineId; }
    int autoValueIndex() const override { return ShipmentLineId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<RcvPriorityCd<<InvNoId<<InvCondCd<<PartNoId<<PoLineId<<PoId<<ShipmentId; }
    QString tableName() const override { return QLatin1String("ship_shipment_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int shipment_line_id READ getshipment_line_id WRITE setshipment_line_id)
    T_DEFINE_PROPERTY(int, shipment_line_id)
    Q_PROPERTY(int shipment_id READ getshipment_id WRITE setshipment_id)
    T_DEFINE_PROPERTY(int, shipment_id)
    Q_PROPERTY(int line_no_ord READ getline_no_ord WRITE setline_no_ord)
    T_DEFINE_PROPERTY(int, line_no_ord)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int expect_qt READ getexpect_qt WRITE setexpect_qt)
    T_DEFINE_PROPERTY(int, expect_qt)
    Q_PROPERTY(QString inv_cond_cd READ getinv_cond_cd WRITE setinv_cond_cd)
    T_DEFINE_PROPERTY(QString, inv_cond_cd)
    Q_PROPERTY(QString serial_no_oem READ getserial_no_oem WRITE setserial_no_oem)
    T_DEFINE_PROPERTY(QString, serial_no_oem)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QString rcv_priority_cd READ getrcv_priority_cd WRITE setrcv_priority_cd)
    T_DEFINE_PROPERTY(QString, rcv_priority_cd)
    Q_PROPERTY(bool received_doc_bool READ getreceived_doc_bool WRITE setreceived_doc_bool)
    T_DEFINE_PROPERTY(bool, received_doc_bool)
    Q_PROPERTY(QString shipment_line_notes READ getshipment_line_notes WRITE setshipment_line_notes)
    T_DEFINE_PROPERTY(QString, shipment_line_notes)
    Q_PROPERTY(int received_qt READ getreceived_qt WRITE setreceived_qt)
    T_DEFINE_PROPERTY(int, received_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // SHIPSHIPMENTLINEOBJECT_H
