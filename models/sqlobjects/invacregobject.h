#ifndef INVACREGOBJECT_H
#define INVACREGOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvAcRegObject : public TSqlObject, public QSharedData
{
public:
    int inv_no_id {0};
    int org_id {0};
    int reg_body_id {0};
    int country_id {0};
    int fc_model_id {0};
    QString ac_reg_cd;
    QString airworth_cd;
    bool private_bool;
    QString var_no_oem;
    QString line_no_oem;
    QString fin_no_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        InvNoId = 0,
        OrgId,
        RegBodyId,
        CountryId,
        FcModelId,
        AcRegCd,
        AirworthCd,
        PrivateBool,
        VarNoOem,
        LineNoOem,
        FinNoCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<InvNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<FcModelId<<CountryId<<RegBodyId<<OrgId<<InvNoId; }
    QString tableName() const override { return QLatin1String("inv_ac_reg"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int inv_no_id READ getinv_no_id WRITE setinv_no_id)
    T_DEFINE_PROPERTY(int, inv_no_id)
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(int reg_body_id READ getreg_body_id WRITE setreg_body_id)
    T_DEFINE_PROPERTY(int, reg_body_id)
    Q_PROPERTY(int country_id READ getcountry_id WRITE setcountry_id)
    T_DEFINE_PROPERTY(int, country_id)
    Q_PROPERTY(int fc_model_id READ getfc_model_id WRITE setfc_model_id)
    T_DEFINE_PROPERTY(int, fc_model_id)
    Q_PROPERTY(QString ac_reg_cd READ getac_reg_cd WRITE setac_reg_cd)
    T_DEFINE_PROPERTY(QString, ac_reg_cd)
    Q_PROPERTY(QString airworth_cd READ getairworth_cd WRITE setairworth_cd)
    T_DEFINE_PROPERTY(QString, airworth_cd)
    Q_PROPERTY(bool private_bool READ getprivate_bool WRITE setprivate_bool)
    T_DEFINE_PROPERTY(bool, private_bool)
    Q_PROPERTY(QString var_no_oem READ getvar_no_oem WRITE setvar_no_oem)
    T_DEFINE_PROPERTY(QString, var_no_oem)
    Q_PROPERTY(QString line_no_oem READ getline_no_oem WRITE setline_no_oem)
    T_DEFINE_PROPERTY(QString, line_no_oem)
    Q_PROPERTY(QString fin_no_cd READ getfin_no_cd WRITE setfin_no_cd)
    T_DEFINE_PROPERTY(QString, fin_no_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // INVACREGOBJECT_H
