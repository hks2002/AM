#ifndef ACTIONUSER_H
#define ACTIONUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ActionUserObject;
class ActionApp;
class UserApp;


class T_MODEL_EXPORT ActionUser : public TAbstractModel
{
public:
    ActionUser();
    ActionUser(const ActionUser &other);
    ActionUser(const ActionUserObject &object);
    ~ActionUser();

    int userId() const;
    void setUserId(int userId);
    int actionId() const;
    void setActionId(int actionId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    ActionApp actionAppByactionId() const;
    UserApp userAppByuserId() const;
    ActionUser &operator=(const ActionUser &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ActionUser create(int userId, int actionId, const QString &createdBy, const QString &updatedBy);
    static ActionUser create(const QVariantMap &values);
    static ActionUser get(int userId, int actionId);
    static int count();
    static QList<ActionUser> getAll();

private:
    QSharedDataPointer<ActionUserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ActionUser &model);
    friend QDataStream &operator>>(QDataStream &ds, ActionUser &model);
};

Q_DECLARE_METATYPE(ActionUser)
Q_DECLARE_METATYPE(QList<ActionUser>)

#endif // ACTIONUSER_H
