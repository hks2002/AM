#ifndef VCONTROLLERACTIONUSERMENU_H
#define VCONTROLLERACTIONUSERMENU_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VControllerActionUserMenuObject;


class T_MODEL_EXPORT VControllerActionUserMenu : public TAbstractModel
{
public:
    VControllerActionUserMenu();
    VControllerActionUserMenu(const VControllerActionUserMenu &other);
    VControllerActionUserMenu(const VControllerActionUserMenuObject &object);
    ~VControllerActionUserMenu();

    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    VControllerActionUserMenu &operator=(const VControllerActionUserMenu &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VControllerActionUserMenu create(const QString &controller, const QString &action, int userId);
    static VControllerActionUserMenu create(const QVariantMap &values);
    static VControllerActionUserMenu get(const QString &controller, const QString &action, int userId);
    static int count();
    static QList<VControllerActionUserMenu> getAll();

private:
    QSharedDataPointer<VControllerActionUserMenuObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VControllerActionUserMenu &model);
    friend QDataStream &operator>>(QDataStream &ds, VControllerActionUserMenu &model);
};

Q_DECLARE_METATYPE(VControllerActionUserMenu)
Q_DECLARE_METATYPE(QList<VControllerActionUserMenu>)

#endif // VCONTROLLERACTIONUSERMENU_H
