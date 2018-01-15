#ifndef EQPPARTNOCONTROLOBJECT_H
#define EQPPARTNOCONTROLOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoControlObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    bool control_reserve_bool;
    bool no_auto_reserve_bool;
    bool receipt_insp_bool;
    bool purchasable_bool;
    bool repair_bool;
    int shelf_life_qt {0};
    QString shelf_life_unit;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        ControlReserveBool,
        NoAutoReserveBool,
        ReceiptInspBool,
        PurchasableBool,
        RepairBool,
        ShelfLifeQt,
        ShelfLifeUnit,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_control"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(bool control_reserve_bool READ getcontrol_reserve_bool WRITE setcontrol_reserve_bool)
    T_DEFINE_PROPERTY(bool, control_reserve_bool)
    Q_PROPERTY(bool no_auto_reserve_bool READ getno_auto_reserve_bool WRITE setno_auto_reserve_bool)
    T_DEFINE_PROPERTY(bool, no_auto_reserve_bool)
    Q_PROPERTY(bool receipt_insp_bool READ getreceipt_insp_bool WRITE setreceipt_insp_bool)
    T_DEFINE_PROPERTY(bool, receipt_insp_bool)
    Q_PROPERTY(bool purchasable_bool READ getpurchasable_bool WRITE setpurchasable_bool)
    T_DEFINE_PROPERTY(bool, purchasable_bool)
    Q_PROPERTY(bool repair_bool READ getrepair_bool WRITE setrepair_bool)
    T_DEFINE_PROPERTY(bool, repair_bool)
    Q_PROPERTY(int shelf_life_qt READ getshelf_life_qt WRITE setshelf_life_qt)
    T_DEFINE_PROPERTY(int, shelf_life_qt)
    Q_PROPERTY(QString shelf_life_unit READ getshelf_life_unit WRITE setshelf_life_unit)
    T_DEFINE_PROPERTY(QString, shelf_life_unit)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPPARTNOCONTROLOBJECT_H
