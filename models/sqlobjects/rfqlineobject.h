#ifndef RFQLINEOBJECT_H
#define RFQLINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RfqLineObject : public TSqlObject, public QSharedData
{
public:
    int rfq_line_id {0};
    int rfq_id {0};
    int line_no_ord {0};
    QString line_desc;
    QString note_to_vendor;
    int rfq_qt {0};
    int qty_unit_id {0};
    int ship_to_loc_id {0};
    int part_no_id {0};
    QString req_priority_cd;
    int po_id {0};
    int po_line_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        RfqLineId = 0,
        RfqId,
        LineNoOrd,
        LineDesc,
        NoteToVendor,
        RfqQt,
        QtyUnitId,
        ShipToLocId,
        PartNoId,
        ReqPriorityCd,
        PoId,
        PoLineId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<RfqLineId; }
    int autoValueIndex() const override { return RfqLineId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PoLineId<<PoId<<ReqPriorityCd<<PartNoId<<ShipToLocId<<QtyUnitId<<RfqId; }
    QString tableName() const override { return QLatin1String("rfq_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int rfq_line_id READ getrfq_line_id WRITE setrfq_line_id)
    T_DEFINE_PROPERTY(int, rfq_line_id)
    Q_PROPERTY(int rfq_id READ getrfq_id WRITE setrfq_id)
    T_DEFINE_PROPERTY(int, rfq_id)
    Q_PROPERTY(int line_no_ord READ getline_no_ord WRITE setline_no_ord)
    T_DEFINE_PROPERTY(int, line_no_ord)
    Q_PROPERTY(QString line_desc READ getline_desc WRITE setline_desc)
    T_DEFINE_PROPERTY(QString, line_desc)
    Q_PROPERTY(QString note_to_vendor READ getnote_to_vendor WRITE setnote_to_vendor)
    T_DEFINE_PROPERTY(QString, note_to_vendor)
    Q_PROPERTY(int rfq_qt READ getrfq_qt WRITE setrfq_qt)
    T_DEFINE_PROPERTY(int, rfq_qt)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(int ship_to_loc_id READ getship_to_loc_id WRITE setship_to_loc_id)
    T_DEFINE_PROPERTY(int, ship_to_loc_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(QString req_priority_cd READ getreq_priority_cd WRITE setreq_priority_cd)
    T_DEFINE_PROPERTY(QString, req_priority_cd)
    Q_PROPERTY(int po_id READ getpo_id WRITE setpo_id)
    T_DEFINE_PROPERTY(int, po_id)
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // RFQLINEOBJECT_H
