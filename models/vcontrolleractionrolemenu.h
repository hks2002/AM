#ifndef VCONTROLLERACTIONROLEMENU_H
#define VCONTROLLERACTIONROLEMENU_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionRoleMenuObject;


class T_MODEL_EXPORT VControllerActionRoleMenu : public TAbstractModel
{
public:
    VControllerActionRoleMenu();
    VControllerActionRoleMenu(const VControllerActionRoleMenu &other);
    VControllerActionRoleMenu(const VControllerActionRoleMenuObject &object);
    ~VControllerActionRoleMenu();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    VControllerActionRoleMenu &operator=(const VControllerActionRoleMenu &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionRoleMenu create(const QString &controller, const QString &action, int roleId);
    static VControllerActionRoleMenu create(const QVariantMap &values);
    static VControllerActionRoleMenu get(const QString &controller, const QString &action, int roleId);
    static int count();
    static QList<VControllerActionRoleMenu> getAll();

private:
    QSharedDataPointer<VControllerActionRoleMenuObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionRoleMenu &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionRoleMenu &model);
};

Q_DECLARE_METATYPE(VControllerActionRoleMenu)
Q_DECLARE_METATYPE(QList<VControllerActionRoleMenu>)

#endif // VCONTROLLERACTIONROLEMENU_H
