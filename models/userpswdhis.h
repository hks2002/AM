#ifndef USERPSWDHIS_H
#define USERPSWDHIS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserPswdHisObject;
class UserApp;


class T_MODEL_EXPORT UserPswdHis : public TAbstractModel
{
public:
    UserPswdHis();
    UserPswdHis(const UserPswdHis &other);
    UserPswdHis(const UserPswdHisObject &object);
    ~UserPswdHis();

    int userPswdHisId() const;
    int userId() const;
    void setUserId(int userId);
    QString password() const;
    void setPassword(const QString &password);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    UserPswdHis &operator=(const UserPswdHis &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserPswdHis create(int userId, const QString &password, const QString &createdBy, const QString &updatedBy);
    static UserPswdHis create(const QVariantMap &values);
    static UserPswdHis get(int userPswdHisId);
    static int count();
    static QList<UserPswdHis> getAll();

private:
    QSharedDataPointer<UserPswdHisObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserPswdHis &model);
    friend QDataStream &operator>>(QDataStream &ds, UserPswdHis &model);
};

Q_DECLARE_METATYPE(UserPswdHis)
Q_DECLARE_METATYPE(QList<UserPswdHis>)

#endif // USERPSWDHIS_H
