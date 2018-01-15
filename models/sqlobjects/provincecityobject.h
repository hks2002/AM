#ifndef PROVINCECITYOBJECT_H
#define PROVINCECITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ProvinceCityObject : public TSqlObject, public QSharedData
{
public:
    int province_id {0};
    int city_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ProvinceId = 0,
        CityId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ProvinceId<<CityId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CityId<<ProvinceId; }
    QString tableName() const override { return QLatin1String("province_city"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int province_id READ getprovince_id WRITE setprovince_id)
    T_DEFINE_PROPERTY(int, province_id)
    Q_PROPERTY(int city_id READ getcity_id WRITE setcity_id)
    T_DEFINE_PROPERTY(int, city_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // PROVINCECITYOBJECT_H
