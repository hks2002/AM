#ifndef ROLEUSER_H
#define ROLEUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RoleUserObject;
class UserApp;
class RoleApp;


class T_MODEL_EXPORT RoleUser : public TAbstractModel
{
public:
    RoleUser();
    RoleUser(const RoleUser &other);
    RoleUser(const RoleUserObject &object);
    ~RoleUser();

    int roleId() const;
    void setRoleId(int roleId);
    int userId() const;
    void setUserId(int userId);
    int roleOrder() const;
    void setRoleOrder(int roleOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    RoleApp roleAppByroleId() const;
    RoleUser &operator=(const RoleUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RoleUser create(int roleId, int userId, int roleOrder, const QString &createdBy, const QString &updatedBy);
    static RoleUser create(const QVariantMap &values);
    static RoleUser get(int roleId, int userId);
    static int count();
    static QList<RoleUser> getAll();

private:
    QSharedDataPointer<RoleUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RoleUser &model);
    friend QDataStream &operator>>(QDataStream &ds, RoleUser &model);
};

Q_DECLARE_METATYPE(RoleUser)
Q_DECLARE_METATYPE(QList<RoleUser>)

#endif // ROLEUSER_H
