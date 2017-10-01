#ifndef RFQVENDOR_H
#define RFQVENDOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RfqVendorObject;
class RefTradeTerms;
class RefPaymentTerms;
class Transportor;
class Currency;
class Vendor;
class RfqHeader;


class T_MODEL_EXPORT RfqVendor : public TAbstractModel
{
public:
    RfqVendor();
    RfqVendor(const RfqVendor &other);
    RfqVendor(const RfqVendorObject &object);
    ~RfqVendor();

    int rfqId() const;
    void setRfqId(int rfqId);
    int vendorId() const;
    void setVendorId(int vendorId);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    double exchgQt() const;
    void setExchgQt(double exchgQt);
    int transportorId() const;
    void setTransportorId(int transportorId);
    QString paymentTermsCd() const;
    void setPaymentTermsCd(const QString &paymentTermsCd);
    QString tradeTermCd() const;
    void setTradeTermCd(const QString &tradeTermCd);
    QString vendorNote() const;
    void setVendorNote(const QString &vendorNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefTradeTerms refTradeTermsBytradeTermCd() const;
    RefPaymentTerms refPaymentTermsBypaymentTermsCd() const;
    Transportor transportorBytransportorId() const;
    Currency currencyBycurrencyId() const;
    Vendor vendorByvendorId() const;
    RfqHeader rfqHeaderByrfqId() const;
    RfqVendor &operator=(const RfqVendor &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RfqVendor create(int rfqId, int vendorId, int currencyId, double exchgQt, int transportorId, const QString &paymentTermsCd, const QString &tradeTermCd, const QString &vendorNote, const QString &createdBy, const QString &updatedBy);
    static RfqVendor create(const QVariantMap &values);
    static RfqVendor get(int rfqId, int vendorId);
    static int count();
    static QList<RfqVendor> getAll();

private:
    QSharedDataPointer<RfqVendorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RfqVendor &model);
    friend QDataStream &operator>>(QDataStream &ds, RfqVendor &model);
};

Q_DECLARE_METATYPE(RfqVendor)
Q_DECLARE_METATYPE(QList<RfqVendor>)

#endif // RFQVENDOR_H
