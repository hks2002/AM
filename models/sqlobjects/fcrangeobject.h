#ifndef FCRANGEOBJECT_H
#define FCRANGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FcRangeObject : public TSqlObject, public QSharedData
{
public:
    int fc_range_id {0};
    int fc_model_id {0};
    int start_month {0};
    int start_day {0};
    int end_month {0};
    int end_day {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        FcRangeId = 0,
        FcModelId,
        StartMonth,
        StartDay,
        EndMonth,
        EndDay,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<FcRangeId; }
    int autoValueIndex() const override { return FcRangeId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<FcModelId; }
    QString tableName() const override { return QLatin1String("fc_range"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int fc_range_id READ getfc_range_id WRITE setfc_range_id)
    T_DEFINE_PROPERTY(int, fc_range_id)
    Q_PROPERTY(int fc_model_id READ getfc_model_id WRITE setfc_model_id)
    T_DEFINE_PROPERTY(int, fc_model_id)
    Q_PROPERTY(int start_month READ getstart_month WRITE setstart_month)
    T_DEFINE_PROPERTY(int, start_month)
    Q_PROPERTY(int start_day READ getstart_day WRITE setstart_day)
    T_DEFINE_PROPERTY(int, start_day)
    Q_PROPERTY(int end_month READ getend_month WRITE setend_month)
    T_DEFINE_PROPERTY(int, end_month)
    Q_PROPERTY(int end_day READ getend_day WRITE setend_day)
    T_DEFINE_PROPERTY(int, end_day)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // FCRANGEOBJECT_H
