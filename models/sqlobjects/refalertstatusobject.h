#ifndef REFALERTSTATUSOBJECT_H
#define REFALERTSTATUSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT RefAlertStatusObject : public TSqlObject, public QSharedData
{
public:
    QString alert_status_cd;
    QString alert_status_name_en;
    QString alert_status_name_zh;
    QString alert_status_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AlertStatusCd = 0,
        AlertStatusNameEn,
        AlertStatusNameZh,
        AlertStatusDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AlertStatusCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList; }
    QString tableName() const override { return QLatin1String("ref_alert_status"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString alert_status_cd READ getalert_status_cd WRITE setalert_status_cd)
    T_DEFINE_PROPERTY(QString, alert_status_cd)
    Q_PROPERTY(QString alert_status_name_en READ getalert_status_name_en WRITE setalert_status_name_en)
    T_DEFINE_PROPERTY(QString, alert_status_name_en)
    Q_PROPERTY(QString alert_status_name_zh READ getalert_status_name_zh WRITE setalert_status_name_zh)
    T_DEFINE_PROPERTY(QString, alert_status_name_zh)
    Q_PROPERTY(QString alert_status_desc READ getalert_status_desc WRITE setalert_status_desc)
    T_DEFINE_PROPERTY(QString, alert_status_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // REFALERTSTATUSOBJECT_H
