#ifndef COUNTRYOBJECT_H
#define COUNTRYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CountryObject : public TSqlObject, public QSharedData
{
public:
    int country_id {0};
    QString country_name_zh;
    QString country_name_en;
    QString country_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CountryId = 0,
        CountryNameZh,
        CountryNameEn,
        CountryDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CountryId; }
    int autoValueIndex() const override { return CountryId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("country"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int country_id READ getcountry_id WRITE setcountry_id)
    T_DEFINE_PROPERTY(int, country_id)
    Q_PROPERTY(QString country_name_zh READ getcountry_name_zh WRITE setcountry_name_zh)
    T_DEFINE_PROPERTY(QString, country_name_zh)
    Q_PROPERTY(QString country_name_en READ getcountry_name_en WRITE setcountry_name_en)
    T_DEFINE_PROPERTY(QString, country_name_en)
    Q_PROPERTY(QString country_desc READ getcountry_desc WRITE setcountry_desc)
    T_DEFINE_PROPERTY(QString, country_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // COUNTRYOBJECT_H
