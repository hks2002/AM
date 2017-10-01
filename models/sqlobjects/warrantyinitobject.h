#ifndef WARRANTYINITOBJECT_H
#define WARRANTYINITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyInitObject : public TSqlObject, public QSharedData
{
public:
    int warranty_init_id {0};
    int warranty_defn_id {0};
    QString warranty_priority_cd;
    bool expires_first_bool;
    QDateTime start_dt;
    QDateTime end_dt;
    double start_tsn_hours_qt {0};
    double end_tsn_hours_qt {0};
    int start_tsn_cycles_qt {0};
    int end_tsn_cycles_qt {0};
    bool expired_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyInitId = 0,
        WarrantyDefnId,
        WarrantyPriorityCd,
        ExpiresFirstBool,
        StartDt,
        EndDt,
        StartTsnHoursQt,
        EndTsnHoursQt,
        StartTsnCyclesQt,
        EndTsnCyclesQt,
        ExpiredBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyInitId; }
    int autoValueIndex() const override { return WarrantyInitId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<WarrantyPriorityCd<<WarrantyDefnId; }
    QString tableName() const override { return QLatin1String("warranty_init"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_init_id READ getwarranty_init_id WRITE setwarranty_init_id)
    T_DEFINE_PROPERTY(int, warranty_init_id)
    Q_PROPERTY(int warranty_defn_id READ getwarranty_defn_id WRITE setwarranty_defn_id)
    T_DEFINE_PROPERTY(int, warranty_defn_id)
    Q_PROPERTY(QString warranty_priority_cd READ getwarranty_priority_cd WRITE setwarranty_priority_cd)
    T_DEFINE_PROPERTY(QString, warranty_priority_cd)
    Q_PROPERTY(bool expires_first_bool READ getexpires_first_bool WRITE setexpires_first_bool)
    T_DEFINE_PROPERTY(bool, expires_first_bool)
    Q_PROPERTY(QDateTime start_dt READ getstart_dt WRITE setstart_dt)
    T_DEFINE_PROPERTY(QDateTime, start_dt)
    Q_PROPERTY(QDateTime end_dt READ getend_dt WRITE setend_dt)
    T_DEFINE_PROPERTY(QDateTime, end_dt)
    Q_PROPERTY(double start_tsn_hours_qt READ getstart_tsn_hours_qt WRITE setstart_tsn_hours_qt)
    T_DEFINE_PROPERTY(double, start_tsn_hours_qt)
    Q_PROPERTY(double end_tsn_hours_qt READ getend_tsn_hours_qt WRITE setend_tsn_hours_qt)
    T_DEFINE_PROPERTY(double, end_tsn_hours_qt)
    Q_PROPERTY(int start_tsn_cycles_qt READ getstart_tsn_cycles_qt WRITE setstart_tsn_cycles_qt)
    T_DEFINE_PROPERTY(int, start_tsn_cycles_qt)
    Q_PROPERTY(int end_tsn_cycles_qt READ getend_tsn_cycles_qt WRITE setend_tsn_cycles_qt)
    T_DEFINE_PROPERTY(int, end_tsn_cycles_qt)
    Q_PROPERTY(bool expired_bool READ getexpired_bool WRITE setexpired_bool)
    T_DEFINE_PROPERTY(bool, expired_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // WARRANTYINITOBJECT_H
