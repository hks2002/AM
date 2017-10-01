#ifndef EQPPARTNOVENDORPRICE_H
#define EQPPARTNOVENDORPRICE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoVendorPriceObject;
class QtyUnit;
class RefPriceType;
class EqpPartNo;
class Vendor;


class T_MODEL_EXPORT EqpPartNoVendorPrice : public TAbstractModel
{
public:
    EqpPartNoVendorPrice();
    EqpPartNoVendorPrice(const EqpPartNoVendorPrice &other);
    EqpPartNoVendorPrice(const EqpPartNoVendorPriceObject &object);
    ~EqpPartNoVendorPrice();

    int partNoVendorPriceId() const;
    int vendorId() const;
    void setVendorId(int vendorId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString priceTypeCd() const;
    void setPriceTypeCd(const QString &priceTypeCd);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    int minOrderQt() const;
    void setMinOrderQt(int minOrderQt);
    double discountPct() const;
    void setDiscountPct(double discountPct);
    int stdSaleQt() const;
    void setStdSaleQt(int stdSaleQt);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    QString leadTime() const;
    void setLeadTime(const QString &leadTime);
    QDateTime quoteDt() const;
    void setQuoteDt(const QDateTime &quoteDt);
    QDateTime effectiveFromDt() const;
    void setEffectiveFromDt(const QDateTime &effectiveFromDt);
    QDateTime effectiveToDt() const;
    void setEffectiveToDt(const QDateTime &effectiveToDt);
    QString vendorNote() const;
    void setVendorNote(const QString &vendorNote);
    QString docRefDesc() const;
    void setDocRefDesc(const QString &docRefDesc);
    bool histBool() const;
    void setHistBool(bool histBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    QtyUnit qtyUnitByqtyUnitId() const;
    RefPriceType refPriceTypeBypriceTypeCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    Vendor vendorByvendorId() const;
    EqpPartNoVendorPrice &operator=(const EqpPartNoVendorPrice &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoVendorPrice create(int vendorId, int partNoId, const QString &priceTypeCd, double unitPrice, int minOrderQt, double discountPct, int stdSaleQt, int qtyUnitId, const QString &leadTime, const QDateTime &quoteDt, const QDateTime &effectiveFromDt, const QDateTime &effectiveToDt, const QString &vendorNote, const QString &docRefDesc, bool histBool, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoVendorPrice create(const QVariantMap &values);
    static EqpPartNoVendorPrice get(int partNoVendorPriceId);
    static int count();
    static QList<EqpPartNoVendorPrice> getAll();

private:
    QSharedDataPointer<EqpPartNoVendorPriceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorPrice &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorPrice &model);
};

Q_DECLARE_METATYPE(EqpPartNoVendorPrice)
Q_DECLARE_METATYPE(QList<EqpPartNoVendorPrice>)

#endif // EQPPARTNOVENDORPRICE_H
