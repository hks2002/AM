#ifndef MAINTPRGMCARRIERTEMPTASKOBJECT_H
#define MAINTPRGMCARRIERTEMPTASKOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MaintPrgmCarrierTempTaskObject : public TSqlObject, public QSharedData
{
public:
    int maint_prgm_defn_id {0};
    int task_defn_id {0};
    int task_id {0};
    int carrier_id {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MaintPrgmDefnId = 0,
        TaskDefnId,
        TaskId,
        CarrierId,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MaintPrgmDefnId<<TaskDefnId<<TaskId<<CarrierId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<CarrierId<<TaskId<<TaskDefnId<<MaintPrgmDefnId; }
    QString tableName() const override { return QLatin1String("maint_prgm_carrier_temp_task"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int maint_prgm_defn_id READ getmaint_prgm_defn_id WRITE setmaint_prgm_defn_id)
    T_DEFINE_PROPERTY(int, maint_prgm_defn_id)
    Q_PROPERTY(int task_defn_id READ gettask_defn_id WRITE settask_defn_id)
    T_DEFINE_PROPERTY(int, task_defn_id)
    Q_PROPERTY(int task_id READ gettask_id WRITE settask_id)
    T_DEFINE_PROPERTY(int, task_id)
    Q_PROPERTY(int carrier_id READ getcarrier_id WRITE setcarrier_id)
    T_DEFINE_PROPERTY(int, carrier_id)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // MAINTPRGMCARRIERTEMPTASKOBJECT_H
