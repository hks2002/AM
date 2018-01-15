#ifndef USERLICENSEOBJECT_H
#define USERLICENSEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserLicenseObject : public TSqlObject, public QSharedData
{
public:
    int user_id {0};
    int license_id {0};
    QDateTime expiry_dt;
    bool suspended_bool;
    bool active_bool;
    QDateTime created_at;
    QString created_by;
    QDateTime updated_at;
    QString updated_by;

    enum PropertyIndex {
        UserId = 0,
        LicenseId,
        ExpiryDt,
        SuspendedBool,
        ActiveBool,
        CreatedAt,
        CreatedBy,
        UpdatedAt,
        UpdatedBy,
    };

public slots:
    QList<int> primaryKeyIndexList() const override { QList<int> pkidxList; return pkidxList<<UserId<<LicenseId; }
    int autoValueIndex() const override { return -1; }
    QList<int> foreignKeyIndexList() const { QList<int> fkIdxList;return fkIdxList<<LicenseId<<UserId; }
    QString tableName() const override { return QLatin1String("user_license"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int license_id READ getlicense_id WRITE setlicense_id)
    T_DEFINE_PROPERTY(int, license_id)
    Q_PROPERTY(QDateTime expiry_dt READ getexpiry_dt WRITE setexpiry_dt)
    T_DEFINE_PROPERTY(QDateTime, expiry_dt)
    Q_PROPERTY(bool suspended_bool READ getsuspended_bool WRITE setsuspended_bool)
    T_DEFINE_PROPERTY(bool, suspended_bool)
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


#endif // USERLICENSEOBJECT_H
