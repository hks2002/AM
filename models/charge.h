#ifndef CHARGE_H
#define CHARGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ChargeObject;
class FncAccount;


class T_MODEL_EXPORT Charge : public TAbstractModel
{
public:
    Charge();
    Charge(const Charge &other);
    Charge(const ChargeObject &object);
    ~Charge();

    int chargeId() const;
    QString chargeCd() const;
    void setChargeCd(const QString &chargeCd);
    QString chargeName() const;
    void setChargeName(const QString &chargeName);
    int accountId() const;
    void setAccountId(int accountId);
    bool recoverableBool() const;
    void setRecoverableBool(bool recoverableBool);
    bool archiveBool() const;
    void setArchiveBool(bool archiveBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByaccountId() const;
    Charge &operator=(const Charge &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Charge create(const QString &chargeCd, const QString &chargeName, int accountId, bool recoverableBool, bool archiveBool, const QString &createdBy, const QString &updatedBy);
    static Charge create(const QVariantMap &values);
    static Charge get(int chargeId);
    static int count();
    static QList<Charge> getAll();

private:
    QSharedDataPointer<ChargeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Charge &model);
    friend QDataStream &operator>>(QDataStream &ds, Charge &model);
};

Q_DECLARE_METATYPE(Charge)
Q_DECLARE_METATYPE(QList<Charge>)

#endif // CHARGE_H
