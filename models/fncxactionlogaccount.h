#ifndef FNCXACTIONLOGACCOUNT_H
#define FNCXACTIONLOGACCOUNT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FncXactionLogAccountObject;
class FncAccount;
class FncXactionLog;


class T_MODEL_EXPORT FncXactionLogAccount : public TAbstractModel
{
public:
    FncXactionLogAccount();
    FncXactionLogAccount(const FncXactionLogAccount &other);
    FncXactionLogAccount(const FncXactionLogAccountObject &object);
    ~FncXactionLogAccount();

    int xactionId() const;
    void setXactionId(int xactionId);
    int accountId() const;
    void setAccountId(int accountId);
    int xactionAccountId() const;
    void setXactionAccountId(int xactionAccountId);
    double creditCost() const;
    void setCreditCost(double creditCost);
    double debitCost() const;
    void setDebitCost(double debitCost);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByxactionAccountId() const;
    FncXactionLog fncXactionLogByxactionId() const;
    FncXactionLogAccount &operator=(const FncXactionLogAccount &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FncXactionLogAccount create(int xactionId, int accountId, int xactionAccountId, double creditCost, double debitCost, const QString &createdBy, const QString &updatedBy);
    static FncXactionLogAccount create(const QVariantMap &values);
    static FncXactionLogAccount get(int xactionId, int accountId, int xactionAccountId);
    static int count();
    static QList<FncXactionLogAccount> getAll();

private:
    QSharedDataPointer<FncXactionLogAccountObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FncXactionLogAccount &model);
    friend QDataStream &operator>>(QDataStream &ds, FncXactionLogAccount &model);
};

Q_DECLARE_METATYPE(FncXactionLogAccount)
Q_DECLARE_METATYPE(QList<FncXactionLogAccount>)

#endif // FNCXACTIONLOGACCOUNT_H
