#ifndef EQPPARTNOOBJECT_H
#define EQPPARTNOOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    int manufact_id {0};
    QString part_no_oem;
    QString part_no_name;
    QString model_name;
    QString part_no_desc;
    QString part_status_cd;
    QString inv_class_cd;
    int account_id {0};
    bool pma_bool;
    QString picture;
    int qty_unit_id {0};
    QString part_use_cd;
    QString part_type_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        ManufactId,
        PartNoOem,
        PartNoName,
        ModelName,
        PartNoDesc,
        PartStatusCd,
        InvClassCd,
        AccountId,
        PmaBool,
        Picture,
        QtyUnitId,
        PartUseCd,
        PartTypeCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId; }
    int autoValueIndex() const override { return PartNoId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<PartTypeCd<<PartUseCd<<QtyUnitId<<AccountId<<InvClassCd<<PartStatusCd<<ManufactId; }
    QString tableName() const override { return QLatin1String("eqp_part_no"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int manufact_id READ getmanufact_id WRITE setmanufact_id)
    T_DEFINE_PROPERTY(int, manufact_id)
    Q_PROPERTY(QString part_no_oem READ getpart_no_oem WRITE setpart_no_oem)
    T_DEFINE_PROPERTY(QString, part_no_oem)
    Q_PROPERTY(QString part_no_name READ getpart_no_name WRITE setpart_no_name)
    T_DEFINE_PROPERTY(QString, part_no_name)
    Q_PROPERTY(QString model_name READ getmodel_name WRITE setmodel_name)
    T_DEFINE_PROPERTY(QString, model_name)
    Q_PROPERTY(QString part_no_desc READ getpart_no_desc WRITE setpart_no_desc)
    T_DEFINE_PROPERTY(QString, part_no_desc)
    Q_PROPERTY(QString part_status_cd READ getpart_status_cd WRITE setpart_status_cd)
    T_DEFINE_PROPERTY(QString, part_status_cd)
    Q_PROPERTY(QString inv_class_cd READ getinv_class_cd WRITE setinv_class_cd)
    T_DEFINE_PROPERTY(QString, inv_class_cd)
    Q_PROPERTY(int account_id READ getaccount_id WRITE setaccount_id)
    T_DEFINE_PROPERTY(int, account_id)
    Q_PROPERTY(bool pma_bool READ getpma_bool WRITE setpma_bool)
    T_DEFINE_PROPERTY(bool, pma_bool)
    Q_PROPERTY(QString picture READ getpicture WRITE setpicture)
    T_DEFINE_PROPERTY(QString, picture)
    Q_PROPERTY(int qty_unit_id READ getqty_unit_id WRITE setqty_unit_id)
    T_DEFINE_PROPERTY(int, qty_unit_id)
    Q_PROPERTY(QString part_use_cd READ getpart_use_cd WRITE setpart_use_cd)
    T_DEFINE_PROPERTY(QString, part_use_cd)
    Q_PROPERTY(QString part_type_cd READ getpart_type_cd WRITE setpart_type_cd)
    T_DEFINE_PROPERTY(QString, part_type_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // EQPPARTNOOBJECT_H
