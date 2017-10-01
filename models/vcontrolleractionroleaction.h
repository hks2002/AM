#ifndef VCONTROLLERACTIONROLEACTION_H
#define VCONTROLLERACTIONROLEACTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleActionObject;


class T_MODEL_EXPORT VControllerActionRoleAction : public TAbstractModel
{
public:
    VControllerActionRoleAction();
    VControllerActionRoleAction(const VControllerActionRoleAction &other);
    VControllerActionRoleAction(const VControllerActionRoleActionObject &object);
    ~VControllerActionRoleAction();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    VControllerActionRoleAction &operator=(const VControllerActionRoleAction &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRoleAction create(const QString &controller, const QString &action, int roleId);
    static VControllerActionRoleAction create(const QVariantMap &values);
    static VControllerActionRoleAction get(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRoleAction> getAll();

private:
    QSharedDataPointer<VControllerActionRoleActionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleAction &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRoleAction &model);
};

Q_DECLARE_METATYPE(VControllerActionRoleAction)
Q_DECLARE_METATYPE(QList<VControllerActionRoleAction>)

#endif // VCONTROLLERACTIONROLEACTION_H
