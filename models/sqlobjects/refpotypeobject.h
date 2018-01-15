#ifndef REFPOTYPEOBJECT_H
#define REFPOTYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefPoTypeObject : public TSqlObject, public QSharedData
{
public:
    QString po_type_cd;
    QString po_type_name_en;
    QString po_type_name_zh;
    QString po_type_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PoTypeCd = 0,
        PoTypeNameEn,
        PoTypeNameZh,
        PoTypeDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PoTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_po_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString po_type_cd READ getpo_type_cd WRITE setpo_type_cd)
    T_DEFINE_PROPERTY(QString, po_type_cd)
    Q_PROPERTY(QString po_type_name_en READ getpo_type_name_en WRITE setpo_type_name_en)
    T_DEFINE_PROPERTY(QString, po_type_name_en)
    Q_PROPERTY(QString po_type_name_zh READ getpo_type_name_zh WRITE setpo_type_name_zh)
    T_DEFINE_PROPERTY(QString, po_type_name_zh)
    Q_PROPERTY(QString po_type_desc READ getpo_type_desc WRITE setpo_type_desc)
    T_DEFINE_PROPERTY(QString, po_type_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFPOTYPEOBJECT_H
