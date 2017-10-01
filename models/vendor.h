#ifndef VENDOR_H
#define VENDOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VendorObject;
class RefVendorStatus;
class Currency;


class T_MODEL_EXPORT Vendor : public TAbstractModel
{
public:
    Vendor();
    Vendor(const Vendor &other);
    Vendor(const VendorObject &object);
    ~Vendor();

    int vendorId() const;
    QString vendorCd() const;
    void setVendorCd(const QString &vendorCd);
    QString vendorName() const;
    void setVendorName(const QString &vendorName);
    QString certCd() const;
    void setCertCd(const QString &certCd);
    QDateTime certExpiryDt() const;
    void setCertExpiryDt(const QDateTime &certExpiryDt);
    int currencyId() const;
    void setCurrencyId(int currencyId);
    QString receiveNote() const;
    void setReceiveNote(const QString &receiveNote);
    QString vendorNote() const;
    void setVendorNote(const QString &vendorNote);
    QString vendorStatusCd() const;
    void setVendorStatusCd(const QString &vendorStatusCd);
    QString warningDesc() const;
    void setWarningDesc(const QString &warningDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefVendorStatus refVendorStatusByvendorStatusCd() const;
    Currency currencyBycurrencyId() const;
    Vendor &operator=(const Vendor &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Vendor create(const QString &vendorCd, const QString &vendorName, const QString &certCd, const QDateTime &certExpiryDt, int currencyId, const QString &receiveNote, const QString &vendorNote, const QString &vendorStatusCd, const QString &warningDesc, const QString &createdBy, const QString &updatedBy);
    static Vendor create(const QVariantMap &values);
    static Vendor get(int vendorId);
    static int count();
    static QList<Vendor> getAll();

private:
    QSharedDataPointer<VendorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Vendor &model);
    friend QDataStream &operator>>(QDataStream &ds, Vendor &model);
};

Q_DECLARE_METATYPE(Vendor)
Q_DECLARE_METATYPE(QList<Vendor>)

#endif // VENDOR_H
