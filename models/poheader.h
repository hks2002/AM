#ifndef POHEADER_H
#define POHEADER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoHeaderObject;
class RefPoType;
class RefReqPriority;
class RefReqType;
class Vendor;
class FncAccount;
class Currency;
class RefBorrowRate;
class RefPaymentTerms;
class RefTradeTerms;
class Loc;
class Transportor;
class Org;
class UserApp;


class T_MODEL_EXPORT PoHeader : public TAbstractModel
{
public:
    PoHeader();
    PoHeader(const PoHeader &other);
    PoHeader(const PoHeaderObject &object);
    ~PoHeader();

    int poId() const;
    QString poTypeCd() const;
    void setPoTypeCd(const QString &poTypeCd);
    QString reqPriorityCd() const;
    void setReqPriorityCd(const QString &reqPriorityCd);
    QString reqTypeCd() const;
    void setReqTypeCd(const QString &reqTypeCd);
    int vendorId() const;
    void setVendorId(int vendorId);
    int vendorAccountId() const;
    void setVendorAccountId(int vendorAccountId);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    QString borrowRateCd() const;
    void setBorrowRateCd(const QString &borrowRateCd);
    QString paymentTermsCd() const;
    void setPaymentTermsCd(const QString &paymentTermsCd);
    QString tradeTermCd() const;
    void setTradeTermCd(const QString &tradeTermCd);
    QString shippingPoint() const;
    void setShippingPoint(const QString &shippingPoint);
    int finalLocId() const;
    void setFinalLocId(int finalLocId);
    int reExpediteToLocId() const;
    void setReExpediteToLocId(int reExpediteToLocId);
    int transportorId() const;
    void setTransportorId(int transportorId);
    bool receiptInspBool() const;
    void setReceiptInspBool(bool receiptInspBool);
    QString noteToVendor() const;
    void setNoteToVendor(const QString &noteToVendor);
    QString noteToReceiver() const;
    void setNoteToReceiver(const QString &noteToReceiver);
    bool authBool() const;
    void setAuthBool(bool authBool);
    int orgId() const;
    void setOrgId(int orgId);
    int contactTo() const;
    void setContactTo(int contactTo);
    int poCreatedBy() const;
    void setPoCreatedBy(int poCreatedBy);
    QDateTime poCreatedDt() const;
    void setPoCreatedDt(const QDateTime &poCreatedDt);
    int poIssuedBy() const;
    void setPoIssuedBy(int poIssuedBy);
    QDateTime poIssuedDt() const;
    void setPoIssuedDt(const QDateTime &poIssuedDt);
    int poClosedBy() const;
    void setPoClosedBy(int poClosedBy);
    QDateTime poClosedDt() const;
    void setPoClosedDt(const QDateTime &poClosedDt);
    int poInvoiceCreatedBy() const;
    void setPoInvoiceCreatedBy(int poInvoiceCreatedBy);
    QDateTime poInvoiceCreatedDt() const;
    void setPoInvoiceCreatedDt(const QDateTime &poInvoiceCreatedDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefPoType refPoTypeBypoTypeCd() const;
    RefReqPriority refReqPriorityByreqPriorityCd() const;
    RefReqType refReqTypeByreqTypeCd() const;
    Vendor vendorByvendorId() const;
    FncAccount fncAccountByvendorAccountId() const;
    Currency currencyBycurrencyId() const;
    RefBorrowRate refBorrowRateByborrowRateCd() const;
    RefPaymentTerms refPaymentTermsBypaymentTermsCd() const;
    RefTradeTerms refTradeTermsBytradeTermCd() const;
    Loc locByfinalLocId() const;
    Transportor transportorBytransportorId() const;
    Org orgByorgId() const;
    UserApp userAppBycontactTo() const;
    PoHeader &operator=(const PoHeader &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoHeader create(const QString &poTypeCd, const QString &reqPriorityCd, const QString &reqTypeCd, int vendorId, int vendorAccountId, int currencyId, const QString &borrowRateCd, const QString &paymentTermsCd, const QString &tradeTermCd, const QString &shippingPoint, int finalLocId, int reExpediteToLocId, int transportorId, bool receiptInspBool, const QString &noteToVendor, const QString &noteToReceiver, bool authBool, int orgId, int contactTo, int poCreatedBy, const QDateTime &poCreatedDt, int poIssuedBy, const QDateTime &poIssuedDt, int poClosedBy, const QDateTime &poClosedDt, int poInvoiceCreatedBy, const QDateTime &poInvoiceCreatedDt, const QString &createdBy, const QString &updatedBy);
    static PoHeader create(const QVariantMap &values);
    static PoHeader get(int poId);
    static int count();
    static QList<PoHeader> getAll();

private:
    QSharedDataPointer<PoHeaderObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoHeader &model);
    friend QDataStream &operator>>(QDataStream &ds, PoHeader &model);
};

Q_DECLARE_METATYPE(PoHeader)
Q_DECLARE_METATYPE(QList<PoHeader>)

#endif // POHEADER_H
