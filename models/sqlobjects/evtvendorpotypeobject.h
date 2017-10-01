#ifndef EVTVENDORPOTYPEOBJECT_H
#define EVTVENDORPOTYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EvtVendorPoTypeObject : public TSqlObject, public QSharedData
{
public:
    int event_id {0};
    int vendor_id {0};
    int org_id {0};
    QString po_type_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EventId = 0,
        VendorId,
        OrgId,
        PoTypeCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EventId<<VendorId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PoTypeCd<<OrgId<<VendorId<<EventId; }
    QString tableName() const override { return QLatin1String("evt_vendor_po_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int event_id READ getevent_id WRITE setevent_id)
    T_DEFINE_PROPERTY(int, event_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(QString po_type_cd READ getpo_type_cd WRITE setpo_type_cd)
    T_DEFINE_PROPERTY(QString, po_type_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EVTVENDORPOTYPEOBJECT_H
