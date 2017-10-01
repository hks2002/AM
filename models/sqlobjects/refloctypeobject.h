#ifndef REFLOCTYPEOBJECT_H
#define REFLOCTYPEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefLocTypeObject : public TSqlObject, public QSharedData
{
public:
    QString loc_type_cd;
    QString loc_type_name_en;
    QString loc_type_name_zh;
    QString loc_type_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocTypeCd = 0,
        LocTypeNameEn,
        LocTypeNameZh,
        LocTypeDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_loc_type"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString loc_type_cd READ getloc_type_cd WRITE setloc_type_cd)
    T_DEFINE_PROPERTY(QString, loc_type_cd)
    Q_PROPERTY(QString loc_type_name_en READ getloc_type_name_en WRITE setloc_type_name_en)
    T_DEFINE_PROPERTY(QString, loc_type_name_en)
    Q_PROPERTY(QString loc_type_name_zh READ getloc_type_name_zh WRITE setloc_type_name_zh)
    T_DEFINE_PROPERTY(QString, loc_type_name_zh)
    Q_PROPERTY(QString loc_type_desc READ getloc_type_desc WRITE setloc_type_desc)
    T_DEFINE_PROPERTY(QString, loc_type_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFLOCTYPEOBJECT_H
