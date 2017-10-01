#ifndef REFWARRANTYPRIORITYOBJECT_H
#define REFWARRANTYPRIORITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefWarrantyPriorityObject : public TSqlObject, public QSharedData
{
public:
    QString warranty_priority_cd;
    QString warranty_priority_name_en;
    QString warranty_priority_name_zh;
    QString warranty_priority_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyPriorityCd = 0,
        WarrantyPriorityNameEn,
        WarrantyPriorityNameZh,
        WarrantyPriorityDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyPriorityCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_warranty_priority"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString warranty_priority_cd READ getwarranty_priority_cd WRITE setwarranty_priority_cd)
    T_DEFINE_PROPERTY(QString, warranty_priority_cd)
    Q_PROPERTY(QString warranty_priority_name_en READ getwarranty_priority_name_en WRITE setwarranty_priority_name_en)
    T_DEFINE_PROPERTY(QString, warranty_priority_name_en)
    Q_PROPERTY(QString warranty_priority_name_zh READ getwarranty_priority_name_zh WRITE setwarranty_priority_name_zh)
    T_DEFINE_PROPERTY(QString, warranty_priority_name_zh)
    Q_PROPERTY(QString warranty_priority_desc READ getwarranty_priority_desc WRITE setwarranty_priority_desc)
    T_DEFINE_PROPERTY(QString, warranty_priority_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFWARRANTYPRIORITYOBJECT_H
