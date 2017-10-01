#ifndef POLINE_H
#define POLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PoLineObject;
class ShipShipment;
class SchedStask;
class OwnerApp;
class RefPriceType;
class QtyUnit;
class RefPoLineType;
class EqpPartNo;
class PoHeader;


class T_MODEL_EXPORT PoLine : public TAbstractModel
{
public:
    PoLine();
    PoLine(const PoLine &other);
    PoLine(const PoLineObject &object);
    ~PoLine();

    int poLineId() const;
    int poId() const;
    void setPoId(int poId);
    int lineNoOrd() const;
    void setLineNoOrd(int lineNoOrd);
    QString lineDesc() const;
    void setLineDesc(const QString &lineDesc);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString poLineTypeCd() const;
    void setPoLineTypeCd(const QString &poLineTypeCd);
    int orderQt() const;
    void setOrderQt(int orderQt);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    QString priceTypeCd() const;
    void setPriceTypeCd(const QString &priceTypeCd);
    double baseUnitPrice() const;
    void setBaseUnitPrice(double baseUnitPrice);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    double origUnitPrice() const;
    void setOrigUnitPrice(double origUnitPrice);
    double linePrice() const;
    void setLinePrice(double linePrice);
    double accruedValue() const;
    void setAccruedValue(double accruedValue);
    QDateTime promiseDt() const;
    void setPromiseDt(const QDateTime &promiseDt);
    bool confirmPromiseByBool() const;
    void setConfirmPromiseByBool(bool confirmPromiseByBool);
    int receivedQt() const;
    void setReceivedQt(int receivedQt);
    int invoiceQt() const;
    void setInvoiceQt(int invoiceQt);
    int preInspQt() const;
    void setPreInspQt(int preInspQt);
    QDateTime origPromiseDt() const;
    void setOrigPromiseDt(const QDateTime &origPromiseDt);
    bool maintPickupBool() const;
    void setMaintPickupBool(bool maintPickupBool);
    QDateTime receivedDt() const;
    void setReceivedDt(const QDateTime &receivedDt);
    QDateTime returnDt() const;
    void setReturnDt(const QDateTime &returnDt);
    QString noteToVendor() const;
    void setNoteToVendor(const QString &noteToVendor);
    QString noteToReceiver() const;
    void setNoteToReceiver(const QString &noteToReceiver);
    bool warrantyBool() const;
    void setWarrantyBool(bool warrantyBool);
    bool lineDeletedBool() const;
    void setLineDeletedBool(bool lineDeletedBool);
    int ownerId() const;
    void setOwnerId(int ownerId);
    int schedId() const;
    void setSchedId(int schedId);
    int shipmentId() const;
    void setShipmentId(int shipmentId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    ShipShipment shipShipmentByshipmentId() const;
    SchedStask schedStaskByschedId() const;
    OwnerApp ownerAppByownerId() const;
    RefPriceType refPriceTypeBypriceTypeCd() const;
    QtyUnit qtyUnitByqtyUnitId() const;
    RefPoLineType refPoLineTypeBypoLineTypeCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    PoHeader poHeaderBypoId() const;
    PoLine &operator=(const PoLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PoLine create(int poId, int lineNoOrd, const QString &lineDesc, int partNoId, const QString &poLineTypeCd, int orderQt, int qtyUnitId, const QString &priceTypeCd, double baseUnitPrice, double unitPrice, double origUnitPrice, double linePrice, double accruedValue, const QDateTime &promiseDt, bool confirmPromiseByBool, int receivedQt, int invoiceQt, int preInspQt, const QDateTime &origPromiseDt, bool maintPickupBool, const QDateTime &receivedDt, const QDateTime &returnDt, const QString &noteToVendor, const QString &noteToReceiver, bool warrantyBool, bool lineDeletedBool, int ownerId, int schedId, int shipmentId, const QString &createdBy, const QString &updatedBy);
    static PoLine create(const QVariantMap &values);
    static PoLine get(int poLineId);
    static int count();
    static QList<PoLine> getAll();

private:
    QSharedDataPointer<PoLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PoLine &model);
    friend QDataStream &operator>>(QDataStream &ds, PoLine &model);
};

Q_DECLARE_METATYPE(PoLine)
Q_DECLARE_METATYPE(QList<PoLine>)

#endif // POLINE_H
