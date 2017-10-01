#ifndef USERAUTHORITY_H
#define USERAUTHORITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserAuthorityObject;
class Authority;
class UserApp;


class T_MODEL_EXPORT UserAuthority : public TAbstractModel
{
public:
    UserAuthority();
    UserAuthority(const UserAuthority &other);
    UserAuthority(const UserAuthorityObject &object);
    ~UserAuthority();

    int userId() const;
    void setUserId(int userId);
    int authorityId() const;
    void setAuthorityId(int authorityId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Authority authorityByauthorityId() const;
    UserApp userAppByuserId() const;
    UserAuthority &operator=(const UserAuthority &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserAuthority create(int userId, int authorityId, const QString &createdBy, const QString &updatedBy);
    static UserAuthority create(const QVariantMap &values);
    static UserAuthority get(int userId, int authorityId);
    static int count();
    static QList<UserAuthority> getAll();

private:
    QSharedDataPointer<UserAuthorityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserAuthority &model);
    friend QDataStream &operator>>(QDataStream &ds, UserAuthority &model);
};

Q_DECLARE_METATYPE(UserAuthority)
Q_DECLARE_METATYPE(QList<UserAuthority>)

#endif // USERAUTHORITY_H
