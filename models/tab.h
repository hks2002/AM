#ifndef TAB_H
#define TAB_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TabObject;


class T_MODEL_EXPORT Tab : public TAbstractModel
{
public:
    Tab();
    Tab(const Tab &other);
    Tab(const TabObject &object);
    ~Tab();

    int tabId() const;
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
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Tab &operator=(const Tab &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Tab create(const QString &tabCd, const QString &tabNameZh, const QString &tabNameEn, const QString &tabTooltip, const QString &tabDesc, const QString &controller, const QString &action, const QString &createdBy, const QString &updatedBy);
    static Tab create(const QVariantMap &values);
    static Tab get(int tabId);
    static int count();
    static QList<Tab> getAll();

private:
    QSharedDataPointer<TabObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Tab &model);
    friend QDataStream &operator>>(QDataStream &ds, Tab &model);
};

Q_DECLARE_METATYPE(Tab)
Q_DECLARE_METATYPE(QList<Tab>)

#endif // TAB_H
