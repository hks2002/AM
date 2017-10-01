#ifndef MENUSGROUP_H
#define MENUSGROUP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MenusGroupObject;


class T_MODEL_EXPORT MenusGroup : public TAbstractModel
{
public:
    MenusGroup();
    MenusGroup(const MenusGroup &other);
    MenusGroup(const MenusGroupObject &object);
    ~MenusGroup();

    int menusGroupId() const;
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
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MenusGroup &operator=(const MenusGroup &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MenusGroup create(const QString &menusGroupCd, const QString &menusGroupNameZh, const QString &menusGroupNameEn, const QString &menusGroupTooltip, const QString &menusGroupDesc, const QString &createdBy, const QString &updatedBy);
    static MenusGroup create(const QVariantMap &values);
    static MenusGroup get(int menusGroupId);
    static int count();
    static QList<MenusGroup> getAll();

private:
    QSharedDataPointer<MenusGroupObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MenusGroup &model);
    friend QDataStream &operator>>(QDataStream &ds, MenusGroup &model);
};

Q_DECLARE_METATYPE(MenusGroup)
Q_DECLARE_METATYPE(QList<MenusGroup>)

#endif // MENUSGROUP_H
