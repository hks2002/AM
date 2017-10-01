#ifndef MENUSGROUPMENU_H
#define MENUSGROUPMENU_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MenusGroupMenuObject;
class Menu;
class MenusGroup;


class T_MODEL_EXPORT MenusGroupMenu : public TAbstractModel
{
public:
    MenusGroupMenu();
    MenusGroupMenu(const MenusGroupMenu &other);
    MenusGroupMenu(const MenusGroupMenuObject &object);
    ~MenusGroupMenu();

    int menusGroupId() const;
    void setMenusGroupId(int menusGroupId);
    int menuId() const;
    void setMenuId(int menuId);
    bool breakBool() const;
    void setBreakBool(bool breakBool);
    int menuOrder() const;
    void setMenuOrder(int menuOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Menu menuBymenuId() const;
    MenusGroup menusGroupBymenusGroupId() const;
    MenusGroupMenu &operator=(const MenusGroupMenu &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MenusGroupMenu create(int menusGroupId, int menuId, bool breakBool, int menuOrder, const QString &createdBy, const QString &updatedBy);
    static MenusGroupMenu create(const QVariantMap &values);
    static MenusGroupMenu get(int menusGroupId, int menuId);
    static int count();
    static QList<MenusGroupMenu> getAll();

private:
    QSharedDataPointer<MenusGroupMenuObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MenusGroupMenu &model);
    friend QDataStream &operator>>(QDataStream &ds, MenusGroupMenu &model);
};

Q_DECLARE_METATYPE(MenusGroupMenu)
Q_DECLARE_METATYPE(QList<MenusGroupMenu>)

#endif // MENUSGROUPMENU_H
