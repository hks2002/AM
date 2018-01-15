#ifndef EQPPARTNOVENDORPUROBJECT_H
#define EQPPARTNOVENDORPUROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT EqpPartNoVendorPurObject : public TSqlObject, public QSharedData
{
public:
    int part_no_id {0};
    int vendor_id {0};
    bool pref_bool;
    QString part_no_vendor;
    int min_pur_account {0};
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        PartNoId = 0,
        VendorId,
        PrefBool,
        PartNoVendor,
        MinPurAccount,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<PartNoId<<VendorId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<VendorId<<PartNoId; }
    QString tableName() const override { return QLatin1String("eqp_part_no_vendor_pur"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int part_no_id READ getpart_no_id WRITE setpart_no_id)
    T_DEFINE_PROPERTY(int, part_no_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(bool pref_bool READ getpref_bool WRITE setpref_bool)
    T_DEFINE_PROPERTY(bool, pref_bool)
    Q_PROPERTY(QString part_no_vendor READ getpart_no_vendor WRITE setpart_no_vendor)
    T_DEFINE_PROPERTY(QString, part_no_vendor)
    Q_PROPERTY(int min_pur_account READ getmin_pur_account WRITE setmin_pur_account)
    T_DEFINE_PROPERTY(int, min_pur_account)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // EQPPARTNOVENDORPUROBJECT_H
