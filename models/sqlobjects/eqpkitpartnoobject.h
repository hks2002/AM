#ifndef EQPKITPARTNOOBJECT_H
#define EQPKITPARTNOOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpKitPartNoObject : public TSqlObject, public QSharedData
{
public:
    int kit_part_no_id {0};
    int part_no_id {0};
    int part_order {0};
    double qty {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        KitPartNoId = 0,
        PartNoId,
        PartOrder,
        Qty,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<KitPartNoId<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<KitPartNoId; }
    QString tableName() const override { return QLatin1String("eqp_kit_part_no"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int kit_part_no_id READ getkit_part_no_id WRITE setkit_part_no_id)
    T_DEFINE_PROPERTY(int, kit_part_no_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int part_order READ getpart_order WRITE setpart_order)
    T_DEFINE_PROPERTY(int, part_order)
    Q_PROPERTY(double qty READ getqty WRITE setqty)
    T_DEFINE_PROPERTY(double, qty)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPKITPARTNOOBJECT_H
