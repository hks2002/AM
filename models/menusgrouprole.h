#ifndef MENUSGROUPROLE_H
#define MENUSGROUPROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MenusGroupRoleObject;
class RoleApp;
class MenusGroup;


class T_MODEL_EXPORT MenusGroupRole : public TAbstractModel
{
public:
    MenusGroupRole();
    MenusGroupRole(const MenusGroupRole &other);
    MenusGroupRole(const MenusGroupRoleObject &object);
    ~MenusGroupRole();

    int menusGroupId() const;
    void setMenusGroupId(int menusGroupId);
    int roleId() const;
    void setRoleId(int roleId);
    int menusGroupOrder() const;
    void setMenusGroupOrder(int menusGroupOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RoleApp roleAppByroleId() const;
    MenusGroup menusGroupBymenusGroupId() const;
    MenusGroupRole &operator=(const MenusGroupRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MenusGroupRole create(int menusGroupId, int roleId, int menusGroupOrder, const QString &createdBy, const QString &updatedBy);
    static MenusGroupRole create(const QVariantMap &values);
    static MenusGroupRole get(int menusGroupId, int roleId);
    static int count();
    static QList<MenusGroupRole> getAll();

private:
    QSharedDataPointer<MenusGroupRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MenusGroupRole &model);
    friend QDataStream &operator>>(QDataStream &ds, MenusGroupRole &model);
};

Q_DECLARE_METATYPE(MenusGroupRole)
Q_DECLARE_METATYPE(QList<MenusGroupRole>)

#endif // MENUSGROUPROLE_H
