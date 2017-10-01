#ifndef VROLEUSER_H
#define VROLEUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VRoleUserObject;


class T_MODEL_EXPORT VRoleUser : public TAbstractModel
{
public:
    VRoleUser();
    VRoleUser(const VRoleUser &other);
    VRoleUser(const VRoleUserObject &object);
    ~VRoleUser();

    int roleId() const;
    void setRoleId(int roleId);
    QString roleCd() const;
    void setRoleCd(const QString &roleCd);
    QString roleNameZh() const;
    void setRoleNameZh(const QString &roleNameZh);
    QString roleNameEn() const;
    void setRoleNameEn(const QString &roleNameEn);
    int userId() const;
    void setUserId(int userId);
    QString userName() const;
    void setUserName(const QString &userName);
    QString hrCd() const;
    void setHrCd(const QString &hrCd);
    QString fullNameZh() const;
    void setFullNameZh(const QString &fullNameZh);
    QString fullNameEn() const;
    void setFullNameEn(const QString &fullNameEn);
    VRoleUser &operator=(const VRoleUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VRoleUser create(int roleId, const QString &roleCd, const QString &roleNameZh, const QString &roleNameEn, int userId, const QString &userName, const QString &hrCd, const QString &fullNameZh, const QString &fullNameEn);
    static VRoleUser create(const QVariantMap &values);
    static VRoleUser get(int roleId, const QString &roleCd, const QString &roleNameZh, const QString &roleNameEn, int userId, const QString &userName, const QString &hrCd, const QString &fullNameZh, const QString &fullNameEn);
    static int count();
    static QList<VRoleUser> getAll();

private:
    QSharedDataPointer<VRoleUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VRoleUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VRoleUser &model);
};

Q_DECLARE_METATYPE(VRoleUser)
Q_DECLARE_METATYPE(QList<VRoleUser>)

#endif // VROLEUSER_H
