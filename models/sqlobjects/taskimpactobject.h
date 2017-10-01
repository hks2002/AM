#ifndef TASKIMPACTOBJECT_H
#define TASKIMPACTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TaskImpactObject : public TSqlObject, public QSharedData
{
public:
    int task_id {0};
    int mesur_unit_id {0};
    QString mesur_type_cd;
    double mesur_qt {0};
    QString impact_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        TaskId = 0,
        MesurUnitId,
        MesurTypeCd,
        MesurQt,
        ImpactDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<TaskId<<MesurUnitId<<MesurTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<MesurTypeCd<<MesurUnitId<<TaskId; }
    QString tableName() const override { return QLatin1String("task_impact"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int mesur_unit_id READ getmesur_unit_id WRITE setmesur_unit_id)
    T_DEFINE_PROPERTY(int, mesur_unit_id)
    Q_PROPERTY(QString mesur_type_cd READ getmesur_type_cd WRITE setmesur_type_cd)
    T_DEFINE_PROPERTY(QString, mesur_type_cd)
    Q_PROPERTY(double mesur_qt READ getmesur_qt WRITE setmesur_qt)
    T_DEFINE_PROPERTY(double, mesur_qt)
    Q_PROPERTY(QString impact_desc READ getimpact_desc WRITE setimpact_desc)
    T_DEFINE_PROPERTY(QString, impact_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // TASKIMPACTOBJECT_H
