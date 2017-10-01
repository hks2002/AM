#ifndef VTABROLE_H
#define VTABROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VTabRoleObject;


class T_MODEL_EXPORT VTabRole : public TAbstractModel
{
public:
    VTabRole();
    VTabRole(const VTabRole &other);
    VTabRole(const VTabRoleObject &object);
    ~VTabRole();

    int tabId() const;
    void setTabId(int tabId);
    QString tabCd() const;
    void setTabCd(const QString &tabCd);
    QString tabNameZh() const;
    void setTabNameZh(const QString &tabNameZh);
    QString tabNameEn() const;
    void setTabNameEn(const QString &tabNameEn);
    QString tabTooltip() const;
    void setTabTooltip(const QString &tabTooltip);
    QString tabDesc() const;
    void setTabDesc(const QString &tabDesc);
    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    int roleId() const;
    void setRoleId(int roleId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    int tabOrder() const;
    void setTabOrder(int tabOrder);
    VTabRole &operator=(const VTabRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VTabRole create(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int tabOrder);
    static VTabRole create(const QVariantMap &values);
    static VTabRole get(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int roleId, int todoListOrder, int tabOrder);
    static int count();
    static QList<VTabRole> getAll();

private:
    QSharedDataPointer<VTabRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VTabRole &model);
    friend QDataStream &operator>>(QDataStream &ds, VTabRole &model);
};

Q_DECLARE_METATYPE(VTabRole)
Q_DECLARE_METATYPE(QList<VTabRole>)

#endif // VTABROLE_H
