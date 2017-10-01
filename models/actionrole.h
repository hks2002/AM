#ifndef ACTIONROLE_H
#define ACTIONROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ActionRoleObject;
class RoleApp;
class ActionApp;


class T_MODEL_EXPORT ActionRole : public TAbstractModel
{
public:
    ActionRole();
    ActionRole(const ActionRole &other);
    ActionRole(const ActionRoleObject &object);
    ~ActionRole();

    int actionId() const;
    void setActionId(int actionId);
    int roleId() const;
    void setRoleId(int roleId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RoleApp roleAppByroleId() const;
    ActionApp actionAppByactionId() const;
    ActionRole &operator=(const ActionRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ActionRole create(int actionId, int roleId, const QString &createdBy, const QString &updatedBy);
    static ActionRole create(const QVariantMap &values);
    static ActionRole get(int actionId, int roleId);
    static int count();
    static QList<ActionRole> getAll();

private:
    QSharedDataPointer<ActionRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ActionRole &model);
    friend QDataStream &operator>>(QDataStream &ds, ActionRole &model);
};

Q_DECLARE_METATYPE(ActionRole)
Q_DECLARE_METATYPE(QList<ActionRole>)

#endif // ACTIONROLE_H
