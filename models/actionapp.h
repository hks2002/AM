#ifndef ACTIONAPP_H
#define ACTIONAPP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ActionAppObject;


class T_MODEL_EXPORT ActionApp : public TAbstractModel
{
public:
    ActionApp();
    ActionApp(const ActionApp &other);
    ActionApp(const ActionAppObject &object);
    ~ActionApp();

    int actionId() const;
    QString actionDesc() const;
    void setActionDesc(const QString &actionDesc);
    QString actionTypeZh() const;
    void setActionTypeZh(const QString &actionTypeZh);
    QString actionTypeEn() const;
    void setActionTypeEn(const QString &actionTypeEn);
    QString controller() const;
    void setController(const QString &controller);
    QString action() const;
    void setAction(const QString &action);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    ActionApp &operator=(const ActionApp &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ActionApp create(const QString &actionDesc, const QString &actionTypeZh, const QString &actionTypeEn, const QString &controller, const QString &action, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static ActionApp create(const QVariantMap &values);
    static ActionApp get(int actionId);
    static int count();
    static QList<ActionApp> getAll();

private:
    QSharedDataPointer<ActionAppObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ActionApp &model);
    friend QDataStream &operator>>(QDataStream &ds, ActionApp &model);
};

Q_DECLARE_METATYPE(ActionApp)
Q_DECLARE_METATYPE(QList<ActionApp>)

#endif // ACTIONAPP_H
