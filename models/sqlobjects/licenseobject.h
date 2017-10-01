#ifndef LICENSEOBJECT_H
#define LICENSEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LicenseObject : public TSqlObject, public QSharedData
{
public:
    int license_id {0};
    QString license_cd;
    QString license_name;
    QString license_desc;
    QString license_status_cd;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        LicenseId = 0,
        LicenseCd,
        LicenseName,
        LicenseDesc,
        LicenseStatusCd,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<LicenseId; }
    int autoValueIndex() const override { return LicenseId; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LicenseStatusCd; }
    QString tableName() const override { return QLatin1String("license"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int license_id READ getlicense_id WRITE setlicense_id)
    T_DEFINE_PROPERTY(int, license_id)
    Q_PROPERTY(QString license_cd READ getlicense_cd WRITE setlicense_cd)
    T_DEFINE_PROPERTY(QString, license_cd)
    Q_PROPERTY(QString license_name READ getlicense_name WRITE setlicense_name)
    T_DEFINE_PROPERTY(QString, license_name)
    Q_PROPERTY(QString license_desc READ getlicense_desc WRITE setlicense_desc)
    T_DEFINE_PROPERTY(QString, license_desc)
    Q_PROPERTY(QString license_status_cd READ getlicense_status_cd WRITE setlicense_status_cd)
    T_DEFINE_PROPERTY(QString, license_status_cd)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QString created_by READ getcreated_by WRITE setcreated_by)
    T_DEFINE_PROPERTY(QString, created_by)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString updated_by READ getupdated_by WRITE setupdated_by)
    T_DEFINE_PROPERTY(QString, updated_by)
};

#endif // LICENSEOBJECT_H
