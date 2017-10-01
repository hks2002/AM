#ifndef ROLEAPP_H
#define ROLEAPP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RoleAppObject;


class T_MODEL_EXPORT RoleApp : public TAbstractModel
{
public:
    RoleApp();
    RoleApp(const RoleApp &other);
    RoleApp(const RoleAppObject &object);
    ~RoleApp();

    int roleId() const;
    QString roleCd() const;
    void setRoleCd(const QString &roleCd);
    QString roleNameZh() const;
    void setRoleNameZh(const QString &roleNameZh);
    QString roleNameEn() const;
    void setRoleNameEn(const QString &roleNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RoleApp &operator=(const RoleApp &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RoleApp create(const QString &roleCd, const QString &roleNameZh, const QString &roleNameEn, const QString &createdBy, const QString &updatedBy);
    static RoleApp create(const QVariantMap &values);
    static RoleApp get(int roleId);
    static int count();
    static QList<RoleApp> getAll();

private:
    QSharedDataPointer<RoleAppObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RoleApp &model);
    friend QDataStream &operator>>(QDataStream &ds, RoleApp &model);
};

Q_DECLARE_METATYPE(RoleApp)
Q_DECLARE_METATYPE(QList<RoleApp>)

#endif // ROLEAPP_H
