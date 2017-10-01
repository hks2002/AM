#ifndef RFQLINEVENDORCHARGE_H
#define RFQLINEVENDORCHARGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqLineVendorChargeObject;
class Charge;
class RfqLineVendor;


class T_MODEL_EXPORT RfqLineVendorCharge : public TAbstractModel
{
public:
    RfqLineVendorCharge();
    RfqLineVendorCharge(const RfqLineVendorCharge &other);
    RfqLineVendorCharge(const RfqLineVendorChargeObject &object);
    ~RfqLineVendorCharge();

    int vendorId() const;
    void setVendorId(int vendorId);
    int rfqId() const;
    void setRfqId(int rfqId);
    int rfqLineId() const;
    void setRfqLineId(int rfqLineId);
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
    RfqLineVendor rfqLineVendorByvendorIdrfqIdrfqLineId() const;
    RfqLineVendorCharge &operator=(const RfqLineVendorCharge &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqLineVendorCharge create(int vendorId, int rfqId, int rfqLineId, int chargeId, double chargeAmount, const QString &createdBy, const QString &updatedBy);
    static RfqLineVendorCharge create(const QVariantMap &values);
    static RfqLineVendorCharge get(int vendorId, int rfqId, int rfqLineId);
    static int count();
    static QList<RfqLineVendorCharge> getAll();

private:
    QSharedDataPointer<RfqLineVendorChargeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqLineVendorCharge &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqLineVendorCharge &model);
};

Q_DECLARE_METATYPE(RfqLineVendorCharge)
Q_DECLARE_METATYPE(QList<RfqLineVendorCharge>)

#endif // RFQLINEVENDORCHARGE_H
