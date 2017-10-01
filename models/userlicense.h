#ifndef USERLICENSE_H
#define USERLICENSE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserLicenseObject;
class License;
class UserApp;


class T_MODEL_EXPORT UserLicense : public TAbstractModel
{
public:
    UserLicense();
    UserLicense(const UserLicense &other);
    UserLicense(const UserLicenseObject &object);
    ~UserLicense();

    int userId() const;
    void setUserId(int userId);
    int licenseId() const;
    void setLicenseId(int licenseId);
    QDateTime expiryDt() const;
    void setExpiryDt(const QDateTime &expiryDt);
    bool suspendedBool() const;
    void setSuspendedBool(bool suspendedBool);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    License licenseBylicenseId() const;
    UserApp userAppByuserId() const;
    UserLicense &operator=(const UserLicense &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserLicense create(int userId, int licenseId, const QDateTime &expiryDt, bool suspendedBool, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static UserLicense create(const QVariantMap &values);
    static UserLicense get(int userId, int licenseId);
    static int count();
    static QList<UserLicense> getAll();

private:
    QSharedDataPointer<UserLicenseObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserLicense &model);
    friend QDataStream &operator>>(QDataStream &ds, UserLicense &model);
};

Q_DECLARE_METATYPE(UserLicense)
Q_DECLARE_METATYPE(QList<UserLicense>)

#endif // USERLICENSE_H
