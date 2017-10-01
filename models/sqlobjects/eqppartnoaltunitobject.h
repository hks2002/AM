#ifndef EQPPARTNOALTUNITOBJECT_H
#define EQPPARTNOALTUNITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoAltUnitObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    int qty_unit_id {0};
    int alt_unit_id {0};
    double qty_convert_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        QtyUnitId,
        AltUnitId,
        QtyConvertQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId<<QtyUnitId<<AltUnitId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AltUnitId<<QtyUnitId<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_alt_unit"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(int alt_unit_id READ getalt_unit_id WRITE setalt_unit_id)
    T_DEFINE_PROPERTY(int, alt_unit_id)
    Q_PROPERTY(double qty_convert_qt READ getqty_convert_qt WRITE setqty_convert_qt)
    T_DEFINE_PROPERTY(double, qty_convert_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPARTNOALTUNITOBJECT_H
