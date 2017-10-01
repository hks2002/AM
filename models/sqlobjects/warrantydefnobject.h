#ifndef WARRANTYDEFNOBJECT_H
#define WARRANTYDEFNOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WarrantyDefnObject : public TSqlObject, public QSharedData
{
public:
    int warranty_defn_id {0};
    QString warranty_cd;
    QString warranty_status_cd;
    QString priority_cd;
    int vendor_id {0};
    QString warranty_desc;
    QString summary_desc;
    QDateTime expire_dt;
    bool expires_first_bool;
    bool routine_bool;
    bool labour_bool;
    bool orig_eqp_only_bool;
    double unit_price_threshold_qt {0};
    double turn_in_price_threshold_qt {0};
    int duration_qt {0};
    double hours_qt {0};
    int cycles_qt {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        WarrantyDefnId = 0,
        WarrantyCd,
        WarrantyStatusCd,
        PriorityCd,
        VendorId,
        WarrantyDesc,
        SummaryDesc,
        ExpireDt,
        ExpiresFirstBool,
        RoutineBool,
        LabourBool,
        OrigEqpOnlyBool,
        UnitPriceThresholdQt,
        TurnInPriceThresholdQt,
        DurationQt,
        HoursQt,
        CyclesQt,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<WarrantyDefnId; }
    int autoValueIndex() const override { return WarrantyDefnId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<VendorId<<PriorityCd<<WarrantyStatusCd; }
    QString tableName() const override { return QLatin1String("warranty_defn"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int warranty_defn_id READ getwarranty_defn_id WRITE setwarranty_defn_id)
    T_DEFINE_PROPERTY(int, warranty_defn_id)
    Q_PROPERTY(QString warranty_cd READ getwarranty_cd WRITE setwarranty_cd)
    T_DEFINE_PROPERTY(QString, warranty_cd)
    Q_PROPERTY(QString warranty_status_cd READ getwarranty_status_cd WRITE setwarranty_status_cd)
    T_DEFINE_PROPERTY(QString, warranty_status_cd)
    Q_PROPERTY(QString priority_cd READ getpriority_cd WRITE setpriority_cd)
    T_DEFINE_PROPERTY(QString, priority_cd)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(QString warranty_desc READ getwarranty_desc WRITE setwarranty_desc)
    T_DEFINE_PROPERTY(QString, warranty_desc)
    Q_PROPERTY(QString summary_desc READ getsummary_desc WRITE setsummary_desc)
    T_DEFINE_PROPERTY(QString, summary_desc)
    Q_PROPERTY(QDateTime expire_dt READ getexpire_dt WRITE setexpire_dt)
    T_DEFINE_PROPERTY(QDateTime, expire_dt)
    Q_PROPERTY(bool expires_first_bool READ getexpires_first_bool WRITE setexpires_first_bool)
    T_DEFINE_PROPERTY(bool, expires_first_bool)
    Q_PROPERTY(bool routine_bool READ getroutine_bool WRITE setroutine_bool)
    T_DEFINE_PROPERTY(bool, routine_bool)
    Q_PROPERTY(bool labour_bool READ getlabour_bool WRITE setlabour_bool)
    T_DEFINE_PROPERTY(bool, labour_bool)
    Q_PROPERTY(bool orig_eqp_only_bool READ getorig_eqp_only_bool WRITE setorig_eqp_only_bool)
    T_DEFINE_PROPERTY(bool, orig_eqp_only_bool)
    Q_PROPERTY(double unit_price_threshold_qt READ getunit_price_threshold_qt WRITE setunit_price_threshold_qt)
    T_DEFINE_PROPERTY(double, unit_price_threshold_qt)
    Q_PROPERTY(double turn_in_price_threshold_qt READ getturn_in_price_threshold_qt WRITE setturn_in_price_threshold_qt)
    T_DEFINE_PROPERTY(double, turn_in_price_threshold_qt)
    Q_PROPERTY(int duration_qt READ getduration_qt WRITE setduration_qt)
    T_DEFINE_PROPERTY(int, duration_qt)
    Q_PROPERTY(double hours_qt READ gethours_qt WRITE sethours_qt)
    T_DEFINE_PROPERTY(double, hours_qt)
    Q_PROPERTY(int cycles_qt READ getcycles_qt WRITE setcycles_qt)
    T_DEFINE_PROPERTY(int, cycles_qt)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // WARRANTYDEFNOBJECT_H
