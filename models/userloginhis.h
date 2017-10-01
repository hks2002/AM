#ifndef USERLOGINHIS_H
#define USERLOGINHIS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserLoginHisObject;
class UserApp;


class T_MODEL_EXPORT UserLoginHis : public TAbstractModel
{
public:
    UserLoginHis();
    UserLoginHis(const UserLoginHis &other);
    UserLoginHis(const UserLoginHisObject &object);
    ~UserLoginHis();

    int userLoginHisId() const;
    int userId() const;
    void setUserId(int userId);
    QDateTime loginDt() const;
    void setLoginDt(const QDateTime &loginDt);
    QString loginIp() const;
    void setLoginIp(const QString &loginIp);
    QString loginMac() const;
    void setLoginMac(const QString &loginMac);
    QString loginComputer() const;
    void setLoginComputer(const QString &loginComputer);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    UserLoginHis &operator=(const UserLoginHis &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserLoginHis create(int userId, const QDateTime &loginDt, const QString &loginIp, const QString &loginMac, const QString &loginComputer, const QString &createdBy, const QString &updatedBy);
    static UserLoginHis create(const QVariantMap &values);
    static UserLoginHis get(int userLoginHisId);
    static int count();
    static QList<UserLoginHis> getAll();

private:
    QSharedDataPointer<UserLoginHisObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserLoginHis &model);
    friend QDataStream &operator>>(QDataStream &ds, UserLoginHis &model);
};

Q_DECLARE_METATYPE(UserLoginHis)
Q_DECLARE_METATYPE(QList<UserLoginHis>)

#endif // USERLOGINHIS_H
