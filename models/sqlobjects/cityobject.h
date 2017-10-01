#ifndef CITYOBJECT_H
#define CITYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CityObject : public TSqlObject, public QSharedData
{
public:
    int city_id {0};
    QString city_name_zh;
    QString city_name_en;
    QString city_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CityId = 0,
        CityNameZh,
        CityNameEn,
        CityDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CityId; }
    int autoValueIndex() const override { return CityId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("city"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int city_id READ getcity_id WRITE setcity_id)
    T_DEFINE_PROPERTY(int, city_id)
    Q_PROPERTY(QString city_name_zh READ getcity_name_zh WRITE setcity_name_zh)
    T_DEFINE_PROPERTY(QString, city_name_zh)
    Q_PROPERTY(QString city_name_en READ getcity_name_en WRITE setcity_name_en)
    T_DEFINE_PROPERTY(QString, city_name_en)
    Q_PROPERTY(QString city_desc READ getcity_desc WRITE setcity_desc)
    T_DEFINE_PROPERTY(QString, city_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // CITYOBJECT_H
