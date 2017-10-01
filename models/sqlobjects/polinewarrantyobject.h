#ifndef POLINEWARRANTYOBJECT_H
#define POLINEWARRANTYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PoLineWarrantyObject : public TSqlObject, public QSharedData
{
public:
    int po_line_id {0};
    int warranty_defn_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoLineId = 0,
        WarrantyDefnId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoLineId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<WarrantyDefnId<<PoLineId; }
    QString tableName() const override { return QLatin1String("po_line_warranty"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int po_line_id READ getpo_line_id WRITE setpo_line_id)
    T_DEFINE_PROPERTY(int, po_line_id)
    Q_PROPERTY(int warranty_defn_id READ getwarranty_defn_id WRITE setwarranty_defn_id)
    T_DEFINE_PROPERTY(int, warranty_defn_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // POLINEWARRANTYOBJECT_H
