#ifndef ORGVENDORAPPROVALOBJECT_H
#define ORGVENDORAPPROVALOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT OrgVendorApprovalObject : public TSqlObject, public QSharedData
{
public:
    int org_id {0};
    int vendor_id {0};
    QString vendor_type_cd;
    QString approval_cd;
    QDateTime approval_expiry_dt;
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        OrgId = 0,
        VendorId,
        VendorTypeCd,
        ApprovalCd,
        ApprovalExpiryDt,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<OrgId<<VendorId<<VendorTypeCd; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<VendorTypeCd<<VendorId<<OrgId; }
    QString tableName() const override { return QLatin1String("org_vendor_approval"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int org_id READ getorg_id WRITE setorg_id)
    T_DEFINE_PROPERTY(int, org_id)
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(QString vendor_type_cd READ getvendor_type_cd WRITE setvendor_type_cd)
    T_DEFINE_PROPERTY(QString, vendor_type_cd)
    Q_PROPERTY(QString approval_cd READ getapproval_cd WRITE setapproval_cd)
    T_DEFINE_PROPERTY(QString, approval_cd)
    Q_PROPERTY(QDateTime approval_expiry_dt READ getapproval_expiry_dt WRITE setapproval_expiry_dt)
    T_DEFINE_PROPERTY(QDateTime, approval_expiry_dt)
    Q_PROPERTY(bool active_bool READ getactive_bool WRITE setactive_bool)
    T_DEFINE_PROPERTY(bool, active_bool)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};


#endif // ORGVENDORAPPROVALOBJECT_H
