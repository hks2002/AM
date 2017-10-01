#ifndef MAINTPRGMOBJECT_H
#define MAINTPRGMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MaintPrgmObject : public TSqlObject, public QSharedData
{
public:
    int maint_prgm_id {0};
    int maint_prgm_defn_id {0};
    QString maint_prgm_cd;
    QString maint_prgm_desc;
    QString maint_prgm_status_cd;
    int revision_ord {0};
    int carrier_revision_ord {0};
    int actived_by {0};
    QDateTime actived_dt;
    QString active_desc;
    bool locked_bool;
    QDateTime locked_dt;
    int locked_by {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        MaintPrgmId = 0,
        MaintPrgmDefnId,
        MaintPrgmCd,
        MaintPrgmDesc,
        MaintPrgmStatusCd,
        RevisionOrd,
        CarrierRevisionOrd,
        ActivedBy,
        ActivedDt,
        ActiveDesc,
        LockedBool,
        LockedDt,
        LockedBy,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<MaintPrgmId; }
    int autoValueIndex() const override { return MaintPrgmId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LockedBy<<ActivedBy<<MaintPrgmStatusCd<<MaintPrgmDefnId; }
    QString tableName() const override { return QLatin1String("maint_prgm"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int maint_prgm_id READ getmaint_prgm_id WRITE setmaint_prgm_id)
    T_DEFINE_PROPERTY(int, maint_prgm_id)
    Q_PROPERTY(int maint_prgm_defn_id READ getmaint_prgm_defn_id WRITE setmaint_prgm_defn_id)
    T_DEFINE_PROPERTY(int, maint_prgm_defn_id)
    Q_PROPERTY(QString maint_prgm_cd READ getmaint_prgm_cd WRITE setmaint_prgm_cd)
    T_DEFINE_PROPERTY(QString, maint_prgm_cd)
    Q_PROPERTY(QString maint_prgm_desc READ getmaint_prgm_desc WRITE setmaint_prgm_desc)
    T_DEFINE_PROPERTY(QString, maint_prgm_desc)
    Q_PROPERTY(QString maint_prgm_status_cd READ getmaint_prgm_status_cd WRITE setmaint_prgm_status_cd)
    T_DEFINE_PROPERTY(QString, maint_prgm_status_cd)
    Q_PROPERTY(int revision_ord READ getrevision_ord WRITE setrevision_ord)
    T_DEFINE_PROPERTY(int, revision_ord)
    Q_PROPERTY(int carrier_revision_ord READ getcarrier_revision_ord WRITE setcarrier_revision_ord)
    T_DEFINE_PROPERTY(int, carrier_revision_ord)
    Q_PROPERTY(int actived_by READ getactived_by WRITE setactived_by)
    T_DEFINE_PROPERTY(int, actived_by)
    Q_PROPERTY(QDateTime actived_dt READ getactived_dt WRITE setactived_dt)
    T_DEFINE_PROPERTY(QDateTime, actived_dt)
    Q_PROPERTY(QString active_desc READ getactive_desc WRITE setactive_desc)
    T_DEFINE_PROPERTY(QString, active_desc)
    Q_PROPERTY(bool locked_bool READ getlocked_bool WRITE setlocked_bool)
    T_DEFINE_PROPERTY(bool, locked_bool)
    Q_PROPERTY(QDateTime locked_dt READ getlocked_dt WRITE setlocked_dt)
    T_DEFINE_PROPERTY(QDateTime, locked_dt)
    Q_PROPERTY(int locked_by READ getlocked_by WRITE setlocked_by)
    T_DEFINE_PROPERTY(int, locked_by)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // MAINTPRGMOBJECT_H
