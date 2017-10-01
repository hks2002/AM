#ifndef LOCINVRECOUNTOBJECT_H
#define LOCINVRECOUNTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LocInvRecountObject : public TSqlObject, public QSharedData
{
public:
    int inv_recount_id {0};
    int loc_id {0};
    int part_no_id {0};
    int loc_part_count_id {0};
    int user_id {0};
    int inv_no_id {0};
    QString serial_no_oem;
    int count_actual_qt {0};
    int count_expect_qt {0};
    QDateTime recount_dt;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvRecountId = 0,
        LocId,
        PartNoId,
        LocPartCountId,
        UserId,
        InvNoId,
        SerialNoOem,
        CountActualQt,
        CountExpectQt,
        RecountDt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvRecountId; }
    int autoValueIndex() const override { return InvRecountId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<InvNoId<<UserId<<LocPartCountId<<PartNoId<<LocId; }
    QString tableName() const override { return QLatin1String("loc_inv_recount"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_recount_id READ getinv_recount_id WRITE setinv_recount_id)
    T_DEFINE_PROPERTY(int, inv_recount_id)
    Q_PROPERTY(int loc_id READ getloc_id WRITE setloc_id)
    T_DEFINE_PROPERTY(int, loc_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int loc_part_count_id READ getloc_part_count_id WRITE setloc_part_count_id)
    T_DEFINE_PROPERTY(int, loc_part_count_id)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(QString serial_no_oem READ getserial_no_oem WRITE setserial_no_oem)
    T_DEFINE_PROPERTY(QString, serial_no_oem)
    Q_PROPERTY(int count_actual_qt READ getcount_actual_qt WRITE setcount_actual_qt)
    T_DEFINE_PROPERTY(int, count_actual_qt)
    Q_PROPERTY(int count_expect_qt READ getcount_expect_qt WRITE setcount_expect_qt)
    T_DEFINE_PROPERTY(int, count_expect_qt)
    Q_PROPERTY(QDateTime recount_dt READ getrecount_dt WRITE setrecount_dt)
    T_DEFINE_PROPERTY(QDateTime, recount_dt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LOCINVRECOUNTOBJECT_H
