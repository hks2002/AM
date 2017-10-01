#ifndef PROVINCEOBJECT_H
#define PROVINCEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ProvinceObject : public TSqlObject, public QSharedData
{
public:
    int province_id {0};
    QString province_name_zh;
    QString province_name_en;
    QString province_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ProvinceId = 0,
        ProvinceNameZh,
        ProvinceNameEn,
        ProvinceDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ProvinceId; }
    int autoValueIndex() const override { return ProvinceId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("province"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int province_id READ getprovince_id WRITE setprovince_id)
    T_DEFINE_PROPERTY(int, province_id)
    Q_PROPERTY(QString province_name_zh READ getprovince_name_zh WRITE setprovince_name_zh)
    T_DEFINE_PROPERTY(QString, province_name_zh)
    Q_PROPERTY(QString province_name_en READ getprovince_name_en WRITE setprovince_name_en)
    T_DEFINE_PROPERTY(QString, province_name_en)
    Q_PROPERTY(QString province_desc READ getprovince_desc WRITE setprovince_desc)
    T_DEFINE_PROPERTY(QString, province_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // PROVINCEOBJECT_H
