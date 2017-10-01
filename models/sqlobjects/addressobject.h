#ifndef ADDRESSOBJECT_H
#define ADDRESSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AddressObject : public TSqlObject, public QSharedData
{
public:
    int address_id {0};
    QString address_line1;
    QString address_line2;
    int city_id {0};
    int country_id {0};
    int province_id {0};
    QString zip_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AddressId = 0,
        AddressLine1,
        AddressLine2,
        CityId,
        CountryId,
        ProvinceId,
        ZipCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AddressId; }
    int autoValueIndex() const override { return AddressId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ProvinceId<<CountryId<<CityId; }
    QString tableName() const override { return QLatin1String("address"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int address_id READ getaddress_id WRITE setaddress_id)
    T_DEFINE_PROPERTY(int, address_id)
    Q_PROPERTY(QString address_line1 READ getaddress_line1 WRITE setaddress_line1)
    T_DEFINE_PROPERTY(QString, address_line1)
    Q_PROPERTY(QString address_line2 READ getaddress_line2 WRITE setaddress_line2)
    T_DEFINE_PROPERTY(QString, address_line2)
    Q_PROPERTY(int city_id READ getcity_id WRITE setcity_id)
    T_DEFINE_PROPERTY(int, city_id)
    Q_PROPERTY(int country_id READ getcountry_id WRITE setcountry_id)
    T_DEFINE_PROPERTY(int, country_id)
    Q_PROPERTY(int province_id READ getprovince_id WRITE setprovince_id)
    T_DEFINE_PROPERTY(int, province_id)
    Q_PROPERTY(QString zip_cd READ getzip_cd WRITE setzip_cd)
    T_DEFINE_PROPERTY(QString, zip_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // ADDRESSOBJECT_H
