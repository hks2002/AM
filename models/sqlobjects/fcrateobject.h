#ifndef FCRATEOBJECT_H
#define FCRATEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FcRateObject : public TSqlObject, public QSharedData
{
public:
    int fc_model_id {0};
    int fc_range_id {0};
    int data_type_id {0};
    double forecast_rate_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FcModelId = 0,
        FcRangeId,
        DataTypeId,
        ForecastRateQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FcModelId<<FcRangeId<<DataTypeId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<DataTypeId<<FcRangeId<<FcModelId; }
    QString tableName() const override { return QLatin1String("fc_rate"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int fc_model_id READ getfc_model_id WRITE setfc_model_id)
    T_DEFINE_PROPERTY(int, fc_model_id)
    Q_PROPERTY(int fc_range_id READ getfc_range_id WRITE setfc_range_id)
    T_DEFINE_PROPERTY(int, fc_range_id)
    Q_PROPERTY(int data_type_id READ getdata_type_id WRITE setdata_type_id)
    T_DEFINE_PROPERTY(int, data_type_id)
    Q_PROPERTY(double forecast_rate_qt READ getforecast_rate_qt WRITE setforecast_rate_qt)
    T_DEFINE_PROPERTY(double, forecast_rate_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // FCRATEOBJECT_H
