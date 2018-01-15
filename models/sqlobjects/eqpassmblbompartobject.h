#ifndef EQPASSMBLBOMPARTOBJECT_H
#define EQPASSMBLBOMPARTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpAssmblBomPartObject : public TSqlObject, public QSharedData
{
public:
    int assmbl_bom_id {0};
    int part_no_id {0};
    bool standard_bool;
    bool approved_bool;
    int interchg_ord {0};
    bool conditional_bool;
    QString appl_desc;
    QString appl_eff_desc;
    QString appl_sql_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        AssmblBomId = 0,
        PartNoId,
        StandardBool,
        ApprovedBool,
        InterchgOrd,
        ConditionalBool,
        ApplDesc,
        ApplEffDesc,
        ApplSqlDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<AssmblBomId<<PartNoId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartNoId<<AssmblBomId; }
    QString tableName() const override { return QLatin1String("eqp_assmbl_bom_part"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int assmbl_bom_id READ getassmbl_bom_id WRITE setassmbl_bom_id)
    T_DEFINE_PROPERTY(int, assmbl_bom_id)
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(bool standard_bool READ getstandard_bool WRITE setstandard_bool)
    T_DEFINE_PROPERTY(bool, standard_bool)
    Q_PROPERTY(bool approved_bool READ getapproved_bool WRITE setapproved_bool)
    T_DEFINE_PROPERTY(bool, approved_bool)
    Q_PROPERTY(int interchg_ord READ getinterchg_ord WRITE setinterchg_ord)
    T_DEFINE_PROPERTY(int, interchg_ord)
    Q_PROPERTY(bool conditional_bool READ getconditional_bool WRITE setconditional_bool)
    T_DEFINE_PROPERTY(bool, conditional_bool)
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


#endif // EQPASSMBLBOMPARTOBJECT_H
