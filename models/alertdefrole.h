#ifndef ALERTDEFROLE_H
#define ALERTDEFROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AlertDefRoleObject;
class RoleApp;
class AlertDef;


class T_MODEL_EXPORT AlertDefRole : public TAbstractModel
{
public:
    AlertDefRole();
    AlertDefRole(const AlertDefRole &other);
    AlertDefRole(const AlertDefRoleObject &object);
    ~AlertDefRole();

    int alertDefId() const;
    void setAlertDefId(int alertDefId);
    int roleId() const;
    void setRoleId(int roleId);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RoleApp roleAppByroleId() const;
    AlertDef alertDefByalertDefId() const;
    AlertDefRole &operator=(const AlertDefRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AlertDefRole create(int alertDefId, int roleId, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static AlertDefRole create(const QVariantMap &values);
    static AlertDefRole get(int alertDefId, int roleId);
    static int count();
    static QList<AlertDefRole> getAll();

private:
    QSharedDataPointer<AlertDefRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AlertDefRole &model);
    friend QDataStream &operator>>(QDataStream &ds, AlertDefRole &model);
};

Q_DECLARE_METATYPE(AlertDefRole)
Q_DECLARE_METATYPE(QList<AlertDefRole>)

#endif // ALERTDEFROLE_H
