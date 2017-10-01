#ifndef MENU_H
#define MENU_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MenuObject;


class T_MODEL_EXPORT Menu : public TAbstractModel
{
public:
    Menu();
    Menu(const Menu &other);
    Menu(const MenuObject &object);
    ~Menu();

    int menuId() const;
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
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Menu &operator=(const Menu &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Menu create(const QString &menuCd, const QString &menuNameZh, const QString &menuNameEn, const QString &menuTooltip, const QString &menuDesc, const QString &controller, const QString &action, const QString &createdBy, const QString &updatedBy);
    static Menu create(const QVariantMap &values);
    static Menu get(int menuId);
    static int count();
    static QList<Menu> getAll();

private:
    QSharedDataPointer<MenuObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Menu &model);
    friend QDataStream &operator>>(QDataStream &ds, Menu &model);
};

Q_DECLARE_METATYPE(Menu)
Q_DECLARE_METATYPE(QList<Menu>)

#endif // MENU_H
