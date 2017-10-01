#ifndef QTYUNITOBJECT_H
#define QTYUNITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT QtyUnitObject : public TSqlObject, public QSharedData
{
public:
    int qty_unit_id {0};
    QString qty_unit_cd;
    QString qty_unit_name_zh;
    QString qty_unit_name_en;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        QtyUnitId = 0,
        QtyUnitCd,
        QtyUnitNameZh,
        QtyUnitNameEn,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<QtyUnitId; }
    int autoValueIndex() const override { return QtyUnitId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("qty_unit"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(QString qty_unit_cd READ getqty_unit_cd WRITE setqty_unit_cd)
    T_DEFINE_PROPERTY(QString, qty_unit_cd)
    Q_PROPERTY(QString qty_unit_name_zh READ getqty_unit_name_zh WRITE setqty_unit_name_zh)
    T_DEFINE_PROPERTY(QString, qty_unit_name_zh)
    Q_PROPERTY(QString qty_unit_name_en READ getqty_unit_name_en WRITE setqty_unit_name_en)
    T_DEFINE_PROPERTY(QString, qty_unit_name_en)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // QTYUNITOBJECT_H
