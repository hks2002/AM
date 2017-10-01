#ifndef VTODOLISTTABROLE_H
#define VTODOLISTTABROLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VTodoListTabRoleObject;


class T_MODEL_EXPORT VTodoListTabRole : public TAbstractModel
{
public:
    VTodoListTabRole();
    VTodoListTabRole(const VTodoListTabRole &other);
    VTodoListTabRole(const VTodoListTabRoleObject &object);
    ~VTodoListTabRole();

    int roleId() const;
    void setRoleId(int roleId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    int todoListId() const;
    void setTodoListId(int todoListId);
    QString todoListCd() const;
    void setTodoListCd(const QString &todoListCd);
    QString todoListNameZh() const;
    void setTodoListNameZh(const QString &todoListNameZh);
    QString todoListNameEn() const;
    void setTodoListNameEn(const QString &todoListNameEn);
    QString todoListTooltip() const;
    void setTodoListTooltip(const QString &todoListTooltip);
    QString todoListDesc() const;
    void setTodoListDesc(const QString &todoListDesc);
    int tabId() const;
    void setTabId(int tabId);
    int tabOrder() const;
    void setTabOrder(int tabOrder);
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
    VTodoListTabRole &operator=(const VTodoListTabRole &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VTodoListTabRole create(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action);
    static VTodoListTabRole create(const QVariantMap &values);
    static VTodoListTabRole get(int roleId, int todoListOrder, int todoListId, const QString &todoListCd, const QString &todoListNameZh, const QString &todoListNameEn, const QString &todoListTooltip, const QString &todoListDesc, int tabId, int tabOrder, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action);
    static int count();
    static QList<VTodoListTabRole> getAll();

private:
    QSharedDataPointer<VTodoListTabRoleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VTodoListTabRole &model);
    friend QDataStream &operator>>(QDataStream &ds, VTodoListTabRole &model);
};

Q_DECLARE_METATYPE(VTodoListTabRole)
Q_DECLARE_METATYPE(QList<VTodoListTabRole>)

#endif // VTODOLISTTABROLE_H
