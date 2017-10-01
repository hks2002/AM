#ifndef POINVOICE_H
#define POINVOICE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoInvoiceObject;
class UserApp;
class RefPaymentTerms;
class Currency;
class FncAccount;
class Vendor;


class T_MODEL_EXPORT PoInvoice : public TAbstractModel
{
public:
    PoInvoice();
    PoInvoice(const PoInvoice &other);
    PoInvoice(const PoInvoiceObject &object);
    ~PoInvoice();

    int poInvoiceId() const;
    QString poInvoiceCd() const;
    void setPoInvoiceCd(const QString &poInvoiceCd);
    int vendorId() const;
    void setVendorId(int vendorId);
    int vendorAccountId() const;
    void setVendorAccountId(int vendorAccountId);
    double totalInvoice() const;
    void setTotalInvoice(double totalInvoice);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    double exchgQt() const;
    void setExchgQt(double exchgQt);
    QString paymentTermsCd() const;
    void setPaymentTermsCd(const QString &paymentTermsCd);
    QString invoiceNote() const;
    void setInvoiceNote(const QString &invoiceNote);
    double cashDiscountPct() const;
    void setCashDiscountPct(double cashDiscountPct);
    QDateTime cashDiscountExpDt() const;
    void setCashDiscountExpDt(const QDateTime &cashDiscountExpDt);
    QDateTime invoiceDt() const;
    void setInvoiceDt(const QDateTime &invoiceDt);
    int poInvoicePayBy() const;
    void setPoInvoicePayBy(int poInvoicePayBy);
    QDateTime poInvoicePayDt() const;
    void setPoInvoicePayDt(const QDateTime &poInvoicePayDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBypoInvoicePayBy() const;
    RefPaymentTerms refPaymentTermsBypaymentTermsCd() const;
    Currency currencyBycurrencyId() const;
    FncAccount fncAccountByvendorAccountId() const;
    Vendor vendorByvendorId() const;
    PoInvoice &operator=(const PoInvoice &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoInvoice create(const QString &poInvoiceCd, int vendorId, int vendorAccountId, double totalInvoice, int currencyId, double exchgQt, const QString &paymentTermsCd, const QString &invoiceNote, double cashDiscountPct, const QDateTime &cashDiscountExpDt, const QDateTime &invoiceDt, int poInvoicePayBy, const QDateTime &poInvoicePayDt, const QString &createdBy, const QString &updatedBy);
    static PoInvoice create(const QVariantMap &values);
    static PoInvoice get(int poInvoiceId);
    static int count();
    static QList<PoInvoice> getAll();

private:
    QSharedDataPointer<PoInvoiceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoInvoice &model);
    friend QDataStream &operator>>(QDataStream &ds, PoInvoice &model);
};

Q_DECLARE_METATYPE(PoInvoice)
Q_DECLARE_METATYPE(QList<PoInvoice>)

#endif // POINVOICE_H
