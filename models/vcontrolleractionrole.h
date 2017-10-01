#ifndef VCONTROLLERACTIONROLE_H
#define VCONTROLLERACTIONROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleObject;


class T_MODEL_EXPORT VControllerActionRole : public TAbstractModel
{
public:
    VControllerActionRole();
    VControllerActionRole(const VControllerActionRole &other);
    VControllerActionRole(const VControllerActionRoleObject &object);
    ~VControllerActionRole();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    VControllerActionRole &operator=(const VControllerActionRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRole create(const QString &controller, const QString &action, int roleId);
    static VControllerActionRole create(const QVariantMap &values);
    static VControllerActionRole get(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRole> getAll();

private:
    QSharedDataPointer<VControllerActionRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRole &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRole &model);
};

Q_DECLARE_METATYPE(VControllerActionRole)
Q_DECLARE_METATYPE(QList<VControllerActionRole>)

#endif // VCONTROLLERACTIONROLE_H
