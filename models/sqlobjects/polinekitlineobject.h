#ifndef POLINEKITLINEOBJECT_H
#define POLINEKITLINEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoLineKitLineObject : public TSqlObject, public QSharedData
{
public:
    int po_line_id {0};
    int kit_part_no_id {0};
    int part_no_id {0};
    int kit_qt {0};
    double value_pct {0};
    double unit_price {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoLineId = 0,
        KitPartNoId,
        PartNoId,
        KitQt,
        ValuePct,
        UnitPrice,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoLineId<<KitPartNoId<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<KitPartNoId<<PartNoId<<PoLineId; }
    QString tableName() const override { return QLatin1String("po_line_kit_line"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int kit_part_no_id READ getkit_part_no_id WRITE setkit_part_no_id)
    T_DEFINE_PROPERTY(int, kit_part_no_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int kit_qt READ getkit_qt WRITE setkit_qt)
    T_DEFINE_PROPERTY(int, kit_qt)
    Q_PROPERTY(double value_pct READ getvalue_pct WRITE setvalue_pct)
    T_DEFINE_PROPERTY(double, value_pct)
    Q_PROPERTY(double unit_price READ getunit_price WRITE setunit_price)
    T_DEFINE_PROPERTY(double, unit_price)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // POLINEKITLINEOBJECT_H
