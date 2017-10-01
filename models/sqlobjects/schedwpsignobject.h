#ifndef SCHEDWPSIGNOBJECT_H
#define SCHEDWPSIGNOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SchedWpSignObject : public TSqlObject, public QSharedData
{
public:
    int sched_wp_sign_id {0};
    int sched_id {0};
    bool signed_bool;
    int signed_by {0};
    QDateTime signoff_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        SchedWpSignId = 0,
        SchedId,
        SignedBool,
        SignedBy,
        SignoffDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<SchedWpSignId; }
    int autoValueIndex() const override { return SchedWpSignId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<SignedBy<<SchedId; }
    QString tableName() const override { return QLatin1String("sched_wp_sign"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int sched_wp_sign_id READ getsched_wp_sign_id WRITE setsched_wp_sign_id)
    T_DEFINE_PROPERTY(int, sched_wp_sign_id)
    Q_PROPERTY(int sched_id READ getsched_id WRITE setsched_id)
    T_DEFINE_PROPERTY(int, sched_id)
    Q_PROPERTY(bool signed_bool READ getsigned_bool WRITE setsigned_bool)
    T_DEFINE_PROPERTY(bool, signed_bool)
    Q_PROPERTY(int signed_by READ getsigned_by WRITE setsigned_by)
    T_DEFINE_PROPERTY(int, signed_by)
    Q_PROPERTY(QDateTime signoff_dt READ getsignoff_dt WRITE setsignoff_dt)
    T_DEFINE_PROPERTY(QDateTime, signoff_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // SCHEDWPSIGNOBJECT_H
