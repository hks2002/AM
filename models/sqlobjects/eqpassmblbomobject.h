#ifndef EQPASSMBLBOMOBJECT_H
#define EQPASSMBLBOMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblBomObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_bom_id {0};
    int assmbl_id {0};
    QString assmbl_bom_cd;
    QString assmbl_bom_name;
    QString bom_class_cd;
    bool mandatory_bool;
    bool software_bool;
    int pos_ct {0};
    bool must_special_part_no;
    QString appl_desc;
    QString appl_eff_desc;
    QString appl_sql_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblBomId = 0,
        AssmblId,
        AssmblBomCd,
        AssmblBomName,
        BomClassCd,
        MandatoryBool,
        SoftwareBool,
        PosCt,
        MustSpecialPartNo,
        ApplDesc,
        ApplEffDesc,
        ApplSqlDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblBomId; }
    int autoValueIndex() const override { return AssmblBomId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<BomClassCd<<AssmblId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_bom"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int assmbl_id READ getassmbl_id WRITE setassmbl_id)
    T_DEFINE_PROPERTY(int, assmbl_id)
    Q_PROPERTY(QString assmbl_bom_cd READ getassmbl_bom_cd WRITE setassmbl_bom_cd)
    T_DEFINE_PROPERTY(QString, assmbl_bom_cd)
    Q_PROPERTY(QString assmbl_bom_name READ getassmbl_bom_name WRITE setassmbl_bom_name)
    T_DEFINE_PROPERTY(QString, assmbl_bom_name)
    Q_PROPERTY(QString bom_class_cd READ getbom_class_cd WRITE setbom_class_cd)
    T_DEFINE_PROPERTY(QString, bom_class_cd)
    Q_PROPERTY(bool mandatory_bool READ getmandatory_bool WRITE setmandatory_bool)
    T_DEFINE_PROPERTY(bool, mandatory_bool)
    Q_PROPERTY(bool software_bool READ getsoftware_bool WRITE setsoftware_bool)
    T_DEFINE_PROPERTY(bool, software_bool)
    Q_PROPERTY(int pos_ct READ getpos_ct WRITE setpos_ct)
    T_DEFINE_PROPERTY(int, pos_ct)
    Q_PROPERTY(bool must_special_part_no READ getmust_special_part_no WRITE setmust_special_part_no)
    T_DEFINE_PROPERTY(bool, must_special_part_no)
    Q_PROPERTY(QString appl_desc READ getappl_desc WRITE setappl_desc)
    T_DEFINE_PROPERTY(QString, appl_desc)
    Q_PROPERTY(QString appl_eff_desc READ getappl_eff_desc WRITE setappl_eff_desc)
    T_DEFINE_PROPERTY(QString, appl_eff_desc)
    Q_PROPERTY(QString appl_sql_desc READ getappl_sql_desc WRITE setappl_sql_desc)
    T_DEFINE_PROPERTY(QString, appl_sql_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPASSMBLBOMOBJECT_H
