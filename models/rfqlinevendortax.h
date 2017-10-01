#ifndef RFQLINEVENDORTAX_H
#define RFQLINEVENDORTAX_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqLineVendorTaxObject;
class Tax;
class RfqLineVendor;


class T_MODEL_EXPORT RfqLineVendorTax : public TAbstractModel
{
public:
    RfqLineVendorTax();
    RfqLineVendorTax(const RfqLineVendorTax &other);
    RfqLineVendorTax(const RfqLineVendorTaxObject &object);
    ~RfqLineVendorTax();

    int vendorId() const;
    void setVendorId(int vendorId);
    int rfqId() const;
    void setRfqId(int rfqId);
    int rfqLineId() const;
    void setRfqLineId(int rfqLineId);
    int taxId() const;
    void setTaxId(int taxId);
    double taxAmount() const;
    void setTaxAmount(double taxAmount);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Tax taxBytaxId() const;
    RfqLineVendor rfqLineVendorByvendorIdrfqIdrfqLineId() const;
    RfqLineVendorTax &operator=(const RfqLineVendorTax &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqLineVendorTax create(int vendorId, int rfqId, int rfqLineId, int taxId, double taxAmount, const QString &createdBy, const QString &updatedBy);
    static RfqLineVendorTax create(const QVariantMap &values);
    static RfqLineVendorTax get(int vendorId, int rfqId, int rfqLineId);
    static int count();
    static QList<RfqLineVendorTax> getAll();

private:
    QSharedDataPointer<RfqLineVendorTaxObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqLineVendorTax &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqLineVendorTax &model);
};

Q_DECLARE_METATYPE(RfqLineVendorTax)
Q_DECLARE_METATYPE(QList<RfqLineVendorTax>)

#endif // RFQLINEVENDORTAX_H
