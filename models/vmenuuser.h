#ifndef VMENUUSER_H
#define VMENUUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VMenuUserObject;


class T_MODEL_EXPORT VMenuUser : public TAbstractModel
{
public:
    VMenuUser();
    VMenuUser(const VMenuUser &other);
    VMenuUser(const VMenuUserObject &object);
    ~VMenuUser();

    QString menusGroupCd() const;
    void setMenusGroupCd(const QString &menusGroupCd);
    QString menusGroupNameZh() const;
    void setMenusGroupNameZh(const QString &menusGroupNameZh);
    QString menusGroupNameEn() const;
    void setMenusGroupNameEn(const QString &menusGroupNameEn);
    QString menusGroupTooltip() const;
    void setMenusGroupTooltip(const QString &menusGroupTooltip);
    QString menusGroupDesc() const;
    void setMenusGroupDesc(const QString &menusGroupDesc);
    int menuId() const;
    void setMenuId(int menuId);
    QString menuCd() const;
    void setMenuCd(const QString &menuCd);
    QString menuNameZh() const;
    void setMenuNameZh(const QString &menuNameZh);
    QString menuNameEn() const;
    void setMenuNameEn(const QString &menuNameEn);
    QString menuTooltip() const;
    void setMenuTooltip(const QString &menuTooltip);
    QString menuDesc() const;
    void setMenuDesc(const QString &menuDesc);
    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int userId() const;
    void setUserId(int userId);
    int menusGroupId() const;
    void setMenusGroupId(int menusGroupId);
    int menusGroupOrder() const;
    void setMenusGroupOrder(int menusGroupOrder);
    int menuOrder() const;
    void setMenuOrder(int menuOrder);
    bool breakBool() const;
    void setBreakBool(const bool &breakBool);
    VMenuUser &operator=(const VMenuUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VMenuUser create(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, int userId, int menusGroupId, int menusGroupOrder, int menuOrder, const bool &breakBool);
    static VMenuUser create(const QVariantMap &values);
    static VMenuUser get(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, int menuId, const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, int userId, int menusGroupId, int menusGroupOrder, int menuOrder, const bool &breakBool);
    static int count();
    static QList<VMenuUser> getAll();

private:
    QSharedDataPointer<VMenuUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VMenuUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VMenuUser &model);
};

Q_DECLARE_METATYPE(VMenuUser)
Q_DECLARE_METATYPE(QList<VMenuUser>)

#endif // VMENUUSER_H
