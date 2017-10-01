#ifndef USERPOAUTHLVL_H
#define USERPOAUTHLVL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserPoAuthLvlObject;
class Currency;
class UserApp;


class T_MODEL_EXPORT UserPoAuthLvl : public TAbstractModel
{
public:
    UserPoAuthLvl();
    UserPoAuthLvl(const UserPoAuthLvl &other);
    UserPoAuthLvl(const UserPoAuthLvlObject &object);
    ~UserPoAuthLvl();

    int userId() const;
    void setUserId(int userId);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    double authLvlLimit() const;
    void setAuthLvlLimit(double authLvlLimit);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Currency currencyBycurrencyId() const;
    UserApp userAppByuserId() const;
    UserPoAuthLvl &operator=(const UserPoAuthLvl &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static UserPoAuthLvl create(int userId, int currencyId, double authLvlLimit, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static UserPoAuthLvl create(const QVariantMap &values);
    static UserPoAuthLvl get(int userId, int currencyId);
    static int count();
    static QList<UserPoAuthLvl> getAll();

private:
    QSharedDataPointer<UserPoAuthLvlObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const UserPoAuthLvl &model);
    friend QDataStream &operator>>(QDataStream &ds, UserPoAuthLvl &model);
};

Q_DECLARE_METATYPE(UserPoAuthLvl)
Q_DECLARE_METATYPE(QList<UserPoAuthLvl>)

#endif // USERPOAUTHLVL_H
