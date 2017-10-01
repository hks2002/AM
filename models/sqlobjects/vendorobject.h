#ifndef VENDOROBJECT_H
#define VENDOROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VendorObject : public TSqlObject, public QSharedData
{
public:
    int vendor_id {0};
    QString vendor_cd;
    QString vendor_name;
    QString cert_cd;
    QDateTime cert_expiry_dt;
    int currency_id {0};
    QString receive_note;
    QString vendor_note;
    QString vendor_status_cd;
    QString warning_desc;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        VendorId = 0,
        VendorCd,
        VendorName,
        CertCd,
        CertExpiryDt,
        CurrencyId,
        ReceiveNote,
        VendorNote,
        VendorStatusCd,
        WarningDesc,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<VendorId; }
    int autoValueIndex() const override { return VendorId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<VendorStatusCd<<CurrencyId; }
    QString tableName() const override { return QLatin1String("vendor"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int vendor_id READ getvendor_id WRITE setvendor_id)
    T_DEFINE_PROPERTY(int, vendor_id)
    Q_PROPERTY(QString vendor_cd READ getvendor_cd WRITE setvendor_cd)
    T_DEFINE_PROPERTY(QString, vendor_cd)
    Q_PROPERTY(QString vendor_name READ getvendor_name WRITE setvendor_name)
    T_DEFINE_PROPERTY(QString, vendor_name)
    Q_PROPERTY(QString cert_cd READ getcert_cd WRITE setcert_cd)
    T_DEFINE_PROPERTY(QString, cert_cd)
    Q_PROPERTY(QDateTime cert_expiry_dt READ getcert_expiry_dt WRITE setcert_expiry_dt)
    T_DEFINE_PROPERTY(QDateTime, cert_expiry_dt)
    Q_PROPERTY(int currency_id READ getcurrency_id WRITE setcurrency_id)
    T_DEFINE_PROPERTY(int, currency_id)
    Q_PROPERTY(QString receive_note READ getreceive_note WRITE setreceive_note)
    T_DEFINE_PROPERTY(QString, receive_note)
    Q_PROPERTY(QString vendor_note READ getvendor_note WRITE setvendor_note)
    T_DEFINE_PROPERTY(QString, vendor_note)
    Q_PROPERTY(QString vendor_status_cd READ getvendor_status_cd WRITE setvendor_status_cd)
    T_DEFINE_PROPERTY(QString, vendor_status_cd)
    Q_PROPERTY(QString warning_desc READ getwarning_desc WRITE setwarning_desc)
    T_DEFINE_PROPERTY(QString, warning_desc)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // VENDOROBJECT_H
