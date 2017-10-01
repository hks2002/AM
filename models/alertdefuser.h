#ifndef ALERTDEFUSER_H
#define ALERTDEFUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AlertDefUserObject;
class UserApp;
class AlertDef;


class T_MODEL_EXPORT AlertDefUser : public TAbstractModel
{
public:
    AlertDefUser();
    AlertDefUser(const AlertDefUser &other);
    AlertDefUser(const AlertDefUserObject &object);
    ~AlertDefUser();

    int alertDefId() const;
    void setAlertDefId(int alertDefId);
    int userId() const;
    void setUserId(int userId);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByuserId() const;
    AlertDef alertDefByalertDefId() const;
    AlertDefUser &operator=(const AlertDefUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AlertDefUser create(int alertDefId, int userId, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static AlertDefUser create(const QVariantMap &values);
    static AlertDefUser get(int alertDefId, int userId);
    static int count();
    static QList<AlertDefUser> getAll();

private:
    QSharedDataPointer<AlertDefUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AlertDefUser &model);
    friend QDataStream &operator>>(QDataStream &ds, AlertDefUser &model);
};

Q_DECLARE_METATYPE(AlertDefUser)
Q_DECLARE_METATYPE(QList<AlertDefUser>)

#endif // ALERTDEFUSER_H
