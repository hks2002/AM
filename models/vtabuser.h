#ifndef VTABUSER_H
#define VTABUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VTabUserObject;


class T_MODEL_EXPORT VTabUser : public TAbstractModel
{
public:
    VTabUser();
    VTabUser(const VTabUser &other);
    VTabUser(const VTabUserObject &object);
    ~VTabUser();

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
    int userId() const;
    void setUserId(int userId);
    int todoListOrder() const;
    void setTodoListOrder(int todoListOrder);
    int tabOrder() const;
    void setTabOrder(int tabOrder);
    VTabUser &operator=(const VTabUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VTabUser create(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int tabOrder);
    static VTabUser create(const QVariantMap &values);
    static VTabUser get(int tabId, const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, int userId, int todoListOrder, int tabOrder);
    static int count();
    static QList<VTabUser> getAll();

private:
    QSharedDataPointer<VTabUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VTabUser &model);
    friend QDataStream &operator>>(QDataStream &ds, VTabUser &model);
};

Q_DECLARE_METATYPE(VTabUser)
Q_DECLARE_METATYPE(QList<VTabUser>)

#endif // VTABUSER_H
