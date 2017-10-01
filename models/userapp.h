#ifndef USERAPP_H
#define USERAPP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TModelObject;
class UserAppObject;


class T_MODEL_EXPORT UserApp : public TAbstractUser, public TAbstractModel
{
public:
    UserApp();
    UserApp(const UserApp &other);
    UserApp(const UserAppObject &object);
    ~UserApp();

    int userId() const;
    QString userName() const;
    void setUserName(const QString &userName);
    QString fullNameZh() const;
    void setFullNameZh(const QString &fullNameZh);
    QString fullNameEn() const;
    void setFullNameEn(const QString &fullNameEn);
    QString hrCd() const;
    void setHrCd(const QString &hrCd);
    QString password() const;
    void setPassword(const QString &password);
    QString emailAddr() const;
    void setEmailAddr(const QString &emailAddr);
    bool lockedBool() const;
    void setLockedBool(bool lockedBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    QString identityKey() const { return userName(); }
    UserApp &operator=(const UserApp &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static UserApp authenticate(const QString &userName, const QString &password);
    static UserApp create(const QString &userName, const QString &fullNameZh, const QString &fullNameEn, const QString &hrCd, const QString &password, const QString &emailAddr, bool lockedBool, const QString &createdBy, const QString &updatedBy);
    static UserApp create(const QVariantMap &values);
    static UserApp get(int userId);
	static UserApp getByIdentityKey(const QString &userName);
    static int count();
    static QList<UserApp> getAll();

private:
    QSharedDataPointer<UserAppObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
    friend QDataStream &operator<<(QDataStream &ds, const UserApp &model);
    friend QDataStream &operator>>(QDataStream &ds, UserApp &model);
};

Q_DECLARE_METATYPE(UserApp)
Q_DECLARE_METATYPE(QList<UserApp>)

#endif // USERAPP_H
