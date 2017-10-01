#ifndef LOCPARTCOUNTOBJECT_H
#define LOCPARTCOUNTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocPartCountObject : public TSqlObject, public QSharedData
{
public:
    int loc_part_count_id {0};
    int loc_id {0};
    int part_no_id {0};
    int user_id {0};
    QDateTime last_count_dt;
    QDateTime next_count_dt;
    bool req_recount_bool;
    bool hist_bool;
    bool count_accept_bool;
    int count_actual_qt {0};
    int count_expect_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LocPartCountId = 0,
        LocId,
        PartNoId,
        UserId,
        LastCountDt,
        NextCountDt,
        ReqRecountBool,
        HistBool,
        CountAcceptBool,
        CountActualQt,
        CountExpectQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LocPartCountId; }
    int autoValueIndex() const override { return LocPartCountId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<UserId<<PartNoId<<LocId; }
    QString tableName() const override { return QLatin1String("loc_part_count"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int loc_part_count_id READ getloc_part_count_id WRITE setloc_part_count_id)
    T_DEFINE_PROPERTY(int, loc_part_count_id)
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QDateTime last_count_dt READ getlast_count_dt WRITE setlast_count_dt)
    T_DEFINE_PROPERTY(QDateTime, last_count_dt)
    Q_PROPERTY(QDateTime next_count_dt READ getnext_count_dt WRITE setnext_count_dt)
    T_DEFINE_PROPERTY(QDateTime, next_count_dt)
    Q_PROPERTY(bool req_recount_bool READ getreq_recount_bool WRITE setreq_recount_bool)
    T_DEFINE_PROPERTY(bool, req_recount_bool)
    Q_PROPERTY(bool hist_bool READ gethist_bool WRITE sethist_bool)
    T_DEFINE_PROPERTY(bool, hist_bool)
    Q_PROPERTY(bool count_accept_bool READ getcount_accept_bool WRITE setcount_accept_bool)
    T_DEFINE_PROPERTY(bool, count_accept_bool)
    Q_PROPERTY(int count_actual_qt READ getcount_actual_qt WRITE setcount_actual_qt)
    T_DEFINE_PROPERTY(int, count_actual_qt)
    Q_PROPERTY(int count_expect_qt READ getcount_expect_qt WRITE setcount_expect_qt)
    T_DEFINE_PROPERTY(int, count_expect_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCPARTCOUNTOBJECT_H
