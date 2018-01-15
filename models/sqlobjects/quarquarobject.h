#ifndef QUARQUAROBJECT_H
#define QUARQUAROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT QuarQuarObject : public TSqlObject, public QSharedData
{
public:
    int quar_id {0};
    QString quar_note;
    QDateTime quar_dt;
    int user_id {0};
    int inv_no_id {0};
    int loc_id {0};
    bool hist_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        QuarId = 0,
        QuarNote,
        QuarDt,
        UserId,
        InvNoId,
        LocId,
        HistBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<QuarId; }
    int autoValueIndex() const override { return QuarId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LocId<<InvNoId<<UserId; }
    QString tableName() const override { return QLatin1String("quar_quar"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int quar_id READ getquar_id WRITE setquar_id)
    T_DEFINE_PROPERTY(int, quar_id)
    Q_PROPERTY(QString quar_note READ getquar_note WRITE setquar_note)
    T_DEFINE_PROPERTY(QString, quar_note)
    Q_PROPERTY(QDateTime quar_dt READ getquar_dt WRITE setquar_dt)
    T_DEFINE_PROPERTY(QDateTime, quar_dt)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(bool hist_bool READ gethist_bool WRITE sethist_bool)
    T_DEFINE_PROPERTY(bool, hist_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // QUARQUAROBJECT_H
