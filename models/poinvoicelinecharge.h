#ifndef POINVOICELINECHARGE_H
#define POINVOICELINECHARGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoInvoiceLineChargeObject;
class Charge;
class PoInvoiceLine;


class T_MODEL_EXPORT PoInvoiceLineCharge : public TAbstractModel
{
public:
    PoInvoiceLineCharge();
    PoInvoiceLineCharge(const PoInvoiceLineCharge &other);
    PoInvoiceLineCharge(const PoInvoiceLineChargeObject &object);
    ~PoInvoiceLineCharge();

    int poInvoiceLineId() const;
    void setPoInvoiceLineId(int poInvoiceLineId);
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
    PoInvoiceLine poInvoiceLineBypoInvoiceLineId() const;
    PoInvoiceLineCharge &operator=(const PoInvoiceLineCharge &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoInvoiceLineCharge create(int poInvoiceLineId, int chargeId, double chargeAmount, const QString &createdBy, const QString &updatedBy);
    static PoInvoiceLineCharge create(const QVariantMap &values);
    static PoInvoiceLineCharge get(int poInvoiceLineId);
    static int count();
    static QList<PoInvoiceLineCharge> getAll();

private:
    QSharedDataPointer<PoInvoiceLineChargeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoInvoiceLineCharge &model);
    friend QDataStream &operator>>(QDataStream &ds, PoInvoiceLineCharge &model);
};

Q_DECLARE_METATYPE(PoInvoiceLineCharge)
Q_DECLARE_METATYPE(QList<PoInvoiceLineCharge>)

#endif // POINVOICELINECHARGE_H
