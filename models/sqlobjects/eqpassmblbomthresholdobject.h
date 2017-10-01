#ifndef EQPASSMBLBOMTHRESHOLDOBJECT_H
#define EQPASSMBLBOMTHRESHOLDOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblBomThresholdObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_bom_id {0};
    QString threshold_mode_cd;
    int threshold_days_qt {0};
    int threshold_qt {0};
    QString threshold_desc;
    QDateTime effective_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblBomId = 0,
        ThresholdModeCd,
        ThresholdDaysQt,
        ThresholdQt,
        ThresholdDesc,
        EffectiveDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblBomId<<ThresholdModeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<ThresholdModeCd<<AssmblBomId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_bom_threshold"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(QString threshold_mode_cd READ getthreshold_mode_cd WRITE setthreshold_mode_cd)
    T_DEFINE_PROPERTY(QString, threshold_mode_cd)
    Q_PROPERTY(int threshold_days_qt READ getthreshold_days_qt WRITE setthreshold_days_qt)
    T_DEFINE_PROPERTY(int, threshold_days_qt)
    Q_PROPERTY(int threshold_qt READ getthreshold_qt WRITE setthreshold_qt)
    T_DEFINE_PROPERTY(int, threshold_qt)
    Q_PROPERTY(QString threshold_desc READ getthreshold_desc WRITE setthreshold_desc)
    T_DEFINE_PROPERTY(QString, threshold_desc)
    Q_PROPERTY(QDateTime effective_dt READ geteffective_dt WRITE seteffective_dt)
    T_DEFINE_PROPERTY(QDateTime, effective_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPASSMBLBOMTHRESHOLDOBJECT_H
