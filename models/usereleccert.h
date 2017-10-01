#ifndef USERELECCERT_H
#define USERELECCERT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserElecCertObject;
class UserApp;


class T_MODEL_EXPORT UserElecCert : public TAbstractModel
{
public:
    UserElecCert();
    UserElecCert(const UserElecCert &other);
    UserElecCert(const UserElecCertObject &object);
    ~UserElecCert();

    int userElecCertId() const;
    int userId() const;
    void setUserId(int userId);
    QByteArray handSignImg() const;
    void setHandSignImg(const QByteArray &handSignImg);
    QString publicKey() const;
    void setPublicKey(const QString &publicKey);
    QDateTime issueDt() const;
    void setIssueDt(const QDateTime &issueDt);
    QDateTime expireDt() const;
    void setExpireDt(const QDateTime &expireDt);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    UserElecCert &operator=(const UserElecCert &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserElecCert create(int userId, const QByteArray &handSignImg, const QString &publicKey, const QDateTime &issueDt, const QDateTime &expireDt, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static UserElecCert create(const QVariantMap &values);
    static UserElecCert get(int userElecCertId);
    static int count();
    static QList<UserElecCert> getAll();

private:
    QSharedDataPointer<UserElecCertObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserElecCert &model);
    friend QDataStream &operator>>(QDataStream &ds, UserElecCert &model);
};

Q_DECLARE_METATYPE(UserElecCert)
Q_DECLARE_METATYPE(QList<UserElecCert>)

#endif // USERELECCERT_H
