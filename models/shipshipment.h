#ifndef SHIPSHIPMENT_H
#define SHIPSHIPMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ShipShipmentObject;
class FncAccount;
class SchedStask;
class PoHeader;
class MesurUnit;
class Org;
class Transportor;
class RefShipmentType;


class T_MODEL_EXPORT ShipShipment : public TAbstractModel
{
public:
    ShipShipment();
    ShipShipment(const ShipShipment &other);
    ShipShipment(const ShipShipmentObject &object);
    ~ShipShipment();

    int shipmentId() const;
    QString shipmentTypeCd() const;
    void setShipmentTypeCd(const QString &shipmentTypeCd);
    int transportorId() const;
    void setTransportorId(int transportorId);
    int orgId() const;
    void setOrgId(int orgId);
    QString waybillNo() const;
    void setWaybillNo(const QString &waybillNo);
    QString flightNo() const;
    void setFlightNo(const QString &flightNo);
    QString customsDeclaration() const;
    void setCustomsDeclaration(const QString &customsDeclaration);
    QString customsDesc() const;
    void setCustomsDesc(const QString &customsDesc);
    bool confirmReceiptBool() const;
    void setConfirmReceiptBool(bool confirmReceiptBool);
    QDateTime shipAfterDt() const;
    void setShipAfterDt(const QDateTime &shipAfterDt);
    QDateTime shipDt() const;
    void setShipDt(const QDateTime &shipDt);
    QString returnAuthNo() const;
    void setReturnAuthNo(const QString &returnAuthNo);
    double returnPrice() const;
    void setReturnPrice(double returnPrice);
    QString returnDesc() const;
    void setReturnDesc(const QString &returnDesc);
    double weightQt() const;
    void setWeightQt(double weightQt);
    int weightUnitId() const;
    void setWeightUnitId(int weightUnitId);
    double heightQt() const;
    void setHeightQt(double heightQt);
    int heightUnitId() const;
    void setHeightUnitId(int heightUnitId);
    double lengthQt() const;
    void setLengthQt(double lengthQt);
    int lengthUnitId() const;
    void setLengthUnitId(int lengthUnitId);
    double widthQt() const;
    void setWidthQt(double widthQt);
    int widthUnitId() const;
    void setWidthUnitId(int widthUnitId);
    int poId() const;
    void setPoId(int poId);
    int schedId() const;
    void setSchedId(int schedId);
    int accountId() const;
    void setAccountId(int accountId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByaccountId() const;
    SchedStask schedStaskByschedId() const;
    PoHeader poHeaderBypoId() const;
    MesurUnit mesurUnitBywidthUnitId() const;
    Org orgByorgId() const;
    Transportor transportorBytransportorId() const;
    RefShipmentType refShipmentTypeByshipmentTypeCd() const;
    ShipShipment &operator=(const ShipShipment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ShipShipment create(const QString &shipmentTypeCd, int transportorId, int orgId, const QString &waybillNo, const QString &flightNo, const QString &customsDeclaration, const QString &customsDesc, bool confirmReceiptBool, const QDateTime &shipAfterDt, const QDateTime &shipDt, const QString &returnAuthNo, double returnPrice, const QString &returnDesc, double weightQt, int weightUnitId, double heightQt, int heightUnitId, double lengthQt, int lengthUnitId, double widthQt, int widthUnitId, int poId, int schedId, int accountId, const QString &createdBy, const QString &updatedBy);
    static ShipShipment create(const QVariantMap &values);
    static ShipShipment get(int shipmentId);
    static int count();
    static QList<ShipShipment> getAll();

private:
    QSharedDataPointer<ShipShipmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ShipShipment &model);
    friend QDataStream &operator>>(QDataStream &ds, ShipShipment &model);
};

Q_DECLARE_METATYPE(ShipShipment)
Q_DECLARE_METATYPE(QList<ShipShipment>)

#endif // SHIPSHIPMENT_H
