#ifndef REFWARRANTYTYPESUBTYPEOBJECT_H
#define REFWARRANTYTYPESUBTYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefWarrantyTypeSubtypeObject : public TSqlObject, public QSharedData
{
public:
    QString warranty_type_cd;
    QString warranty_subtype_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyTypeCd = 0,
        WarrantySubtypeCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyTypeCd<<WarrantySubtypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_warranty_type_subtype"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString warranty_type_cd READ getwarranty_type_cd WRITE setwarranty_type_cd)
    T_DEFINE_PROPERTY(QString, warranty_type_cd)
    Q_PROPERTY(QString warranty_subtype_cd READ getwarranty_subtype_cd WRITE setwarranty_subtype_cd)
    T_DEFINE_PROPERTY(QString, warranty_subtype_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFWARRANTYTYPESUBTYPEOBJECT_H
