#ifndef REFTHRESHOLDMODEOBJECT_H
#define REFTHRESHOLDMODEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefThresholdModeObject : public TSqlObject, public QSharedData
{
public:
    QString threshold_mode_cd;
    QString threshold_mode_name_en;
    QString threshold_mode_name_zh;
    QString threshold_mode_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        ThresholdModeCd = 0,
        ThresholdModeNameEn,
        ThresholdModeNameZh,
        ThresholdModeDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<ThresholdModeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_threshold_mode"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString threshold_mode_cd READ getthreshold_mode_cd WRITE setthreshold_mode_cd)
    T_DEFINE_PROPERTY(QString, threshold_mode_cd)
    Q_PROPERTY(QString threshold_mode_name_en READ getthreshold_mode_name_en WRITE setthreshold_mode_name_en)
    T_DEFINE_PROPERTY(QString, threshold_mode_name_en)
    Q_PROPERTY(QString threshold_mode_name_zh READ getthreshold_mode_name_zh WRITE setthreshold_mode_name_zh)
    T_DEFINE_PROPERTY(QString, threshold_mode_name_zh)
    Q_PROPERTY(QString threshold_mode_desc READ getthreshold_mode_desc WRITE setthreshold_mode_desc)
    T_DEFINE_PROPERTY(QString, threshold_mode_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // REFTHRESHOLDMODEOBJECT_H
