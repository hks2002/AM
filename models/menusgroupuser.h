#ifndef MENUSGROUPUSER_H
#define MENUSGROUPUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MenusGroupUserObject;
class UserApp;
class MenusGroup;


class T_MODEL_EXPORT MenusGroupUser : public TAbstractModel
{
public:
    MenusGroupUser();
    MenusGroupUser(const MenusGroupUser &other);
    MenusGroupUser(const MenusGroupUserObject &object);
    ~MenusGroupUser();

    int menusGroupId() const;
    void setMenusGroupId(int menusGroupId);
    int userId() const;
    void setUserId(int userId);
    int menusGroupOrder() const;
    void setMenusGroupOrder(int menusGroupOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    MenusGroup menusGroupBymenusGroupId() const;
    MenusGroupUser &operator=(const MenusGroupUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MenusGroupUser create(int menusGroupId, int userId, int menusGroupOrder, const QString &createdBy, const QString &updatedBy);
    static MenusGroupUser create(const QVariantMap &values);
    static MenusGroupUser get(int menusGroupId, int userId);
    static int count();
    static QList<MenusGroupUser> getAll();

private:
    QSharedDataPointer<MenusGroupUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MenusGroupUser &model);
    friend QDataStream &operator>>(QDataStream &ds, MenusGroupUser &model);
};

Q_DECLARE_METATYPE(MenusGroupUser)
Q_DECLARE_METATYPE(QList<MenusGroupUser>)

#endif // MENUSGROUPUSER_H
