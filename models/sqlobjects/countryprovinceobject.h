#ifndef COUNTRYPROVINCEOBJECT_H
#define COUNTRYPROVINCEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CountryProvinceObject : public TSqlObject, public QSharedData
{
public:
    int country_id {0};
    int province_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CountryId = 0,
        ProvinceId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CountryId<<ProvinceId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ProvinceId<<CountryId; }
    QString tableName() const override { return QLatin1String("country_province"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int country_id READ getcountry_id WRITE setcountry_id)
    T_DEFINE_PROPERTY(int, country_id)
    Q_PROPERTY(int province_id READ getprovince_id WRITE setprovince_id)
    T_DEFINE_PROPERTY(int, province_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // COUNTRYPROVINCEOBJECT_H
