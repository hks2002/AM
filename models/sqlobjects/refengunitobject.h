#ifndef REFENGUNITOBJECT_H
#define REFENGUNITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefEngUnitObject : public TSqlObject, public QSharedData
{
public:
    QString eng_unit_cd;
    QString eng_unit_name_en;
    QString eng_unit_name_zh;
    QString eng_unit_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        EngUnitCd = 0,
        EngUnitNameEn,
        EngUnitNameZh,
        EngUnitDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<EngUnitCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_eng_unit"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString eng_unit_cd READ geteng_unit_cd WRITE seteng_unit_cd)
    T_DEFINE_PROPERTY(QString, eng_unit_cd)
    Q_PROPERTY(QString eng_unit_name_en READ geteng_unit_name_en WRITE seteng_unit_name_en)
    T_DEFINE_PROPERTY(QString, eng_unit_name_en)
    Q_PROPERTY(QString eng_unit_name_zh READ geteng_unit_name_zh WRITE seteng_unit_name_zh)
    T_DEFINE_PROPERTY(QString, eng_unit_name_zh)
    Q_PROPERTY(QString eng_unit_desc READ geteng_unit_desc WRITE seteng_unit_desc)
    T_DEFINE_PROPERTY(QString, eng_unit_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFENGUNITOBJECT_H
