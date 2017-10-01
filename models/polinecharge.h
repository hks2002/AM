#ifndef POLINECHARGE_H
#define POLINECHARGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineChargeObject;
class Charge;
class PoLine;


class T_MODEL_EXPORT PoLineCharge : public TAbstractModel
{
public:
    PoLineCharge();
    PoLineCharge(const PoLineCharge &other);
    PoLineCharge(const PoLineChargeObject &object);
    ~PoLineCharge();

    int poLineId() const;
    void setPoLineId(int poLineId);
    int chargeId() const;
    void setChargeId(int chargeId);
    double chargeAmount() const;
    void setChargeAmount(double chargeAmount);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Charge chargeBychargeId() const;
    PoLine poLineBypoLineId() const;
    PoLineCharge &operator=(const PoLineCharge &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLineCharge create(int poLineId, int chargeId, double chargeAmount, const QString &createdBy, const QString &updatedBy);
    static PoLineCharge create(const QVariantMap &values);
    static PoLineCharge get(int poLineId);
    static int count();
    static QList<PoLineCharge> getAll();

private:
    QSharedDataPointer<PoLineChargeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLineCharge &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLineCharge &model);
};

Q_DECLARE_METATYPE(PoLineCharge)
Q_DECLARE_METATYPE(QList<PoLineCharge>)

#endif // POLINECHARGE_H
