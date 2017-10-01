#ifndef CARRIEROBJECT_H
#define CARRIEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CarrierObject : public TSqlObject, public QSharedData
{
public:
    int carrier_id {0};
    QString carrier_cd;
    QString carrier_name;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        CarrierId = 0,
        CarrierCd,
        CarrierName,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<CarrierId; }
    int autoValueIndex() const override { return CarrierId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("carrier"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int carrier_id READ getcarrier_id WRITE setcarrier_id)
    T_DEFINE_PROPERTY(int, carrier_id)
    Q_PROPERTY(QString carrier_cd READ getcarrier_cd WRITE setcarrier_cd)
    T_DEFINE_PROPERTY(QString, carrier_cd)
    Q_PROPERTY(QString carrier_name READ getcarrier_name WRITE setcarrier_name)
    T_DEFINE_PROPERTY(QString, carrier_name)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // CARRIEROBJECT_H
