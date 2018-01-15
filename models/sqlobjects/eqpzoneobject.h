#ifndef EQPZONEOBJECT_H
#define EQPZONEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpZoneObject : public TSqlObject, public QSharedData
{
public:
    int zone_id {0};
    int assmbl_id {0};
    QString zone_cd;
    QString desc_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ZoneId = 0,
        AssmblId,
        ZoneCd,
        DescDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ZoneId; }
    int autoValueIndex() const override { return ZoneId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<AssmblId; }
    QString tableName() const override { return QLatin1String("eqp_zone"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int zone_id READ getzone_id WRITE setzone_id)
    T_DEFINE_PROPERTY(int, zone_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(QString zone_cd READ getzone_cd WRITE setzone_cd)
    T_DEFINE_PROPERTY(QString, zone_cd)
    Q_PROPERTY(QString desc_desc READ getdesc_desc WRITE setdesc_desc)
    T_DEFINE_PROPERTY(QString, desc_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPZONEOBJECT_H
