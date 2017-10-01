#ifndef REFBOMCLASSOBJECT_H
#define REFBOMCLASSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefBomClassObject : public TSqlObject, public QSharedData
{
public:
    QString bom_class_cd;
    QString bom_class_name_en;
    QString bom_class_name_zh;
    QString bom_class_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        BomClassCd = 0,
        BomClassNameEn,
        BomClassNameZh,
        BomClassDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<BomClassCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_bom_class"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString bom_class_cd READ getbom_class_cd WRITE setbom_class_cd)
    T_DEFINE_PROPERTY(QString, bom_class_cd)
    Q_PROPERTY(QString bom_class_name_en READ getbom_class_name_en WRITE setbom_class_name_en)
    T_DEFINE_PROPERTY(QString, bom_class_name_en)
    Q_PROPERTY(QString bom_class_name_zh READ getbom_class_name_zh WRITE setbom_class_name_zh)
    T_DEFINE_PROPERTY(QString, bom_class_name_zh)
    Q_PROPERTY(QString bom_class_desc READ getbom_class_desc WRITE setbom_class_desc)
    T_DEFINE_PROPERTY(QString, bom_class_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFBOMCLASSOBJECT_H
