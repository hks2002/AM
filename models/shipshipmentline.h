#ifndef SHIPSHIPMENTLINE_H
#define SHIPSHIPMENTLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ShipShipmentLineObject;
class RefReceivePriority;
class InvInv;
class RefInvCond;
class EqpPartNo;
class PoLine;
class PoHeader;
class ShipShipment;


class T_MODEL_EXPORT ShipShipmentLine : public TAbstractModel
{
public:
    ShipShipmentLine();
    ShipShipmentLine(const ShipShipmentLine &other);
    ShipShipmentLine(const ShipShipmentLineObject &object);
    ~ShipShipmentLine();

    int shipmentLineId() const;
    int shipmentId() const;
    void setShipmentId(int shipmentId);
    int lineNoOrd() const;
    void setLineNoOrd(int lineNoOrd);
    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int expectQt() const;
    void setExpectQt(int expectQt);
    QString invCondCd() const;
    void setInvCondCd(const QString &invCondCd);
    QString serialNoOem() const;
    void setSerialNoOem(const QString &serialNoOem);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QString rcvPriorityCd() const;
    void setRcvPriorityCd(const QString &rcvPriorityCd);
    bool receivedDocBool() const;
    void setReceivedDocBool(bool receivedDocBool);
    QString shipmentLineNotes() const;
    void setShipmentLineNotes(const QString &shipmentLineNotes);
    int receivedQt() const;
    void setReceivedQt(int receivedQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReceivePriority refReceivePriorityByrcvPriorityCd() const;
    InvInv invInvByinvNoId() const;
    RefInvCond refInvCondByinvCondCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    PoLine poLineBypoLineId() const;
    PoHeader poHeaderBypoId() const;
    ShipShipment shipShipmentByshipmentId() const;
    ShipShipmentLine &operator=(const ShipShipmentLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ShipShipmentLine create(int shipmentId, int lineNoOrd, int poId, int poLineId, int partNoId, int expectQt, const QString &invCondCd, const QString &serialNoOem, int invNoId, const QString &rcvPriorityCd, bool receivedDocBool, const QString &shipmentLineNotes, int receivedQt, const QString &createdBy, const QString &updatedBy);
    static ShipShipmentLine create(const QVariantMap &values);
    static ShipShipmentLine get(int shipmentLineId);
    static int count();
    static QList<ShipShipmentLine> getAll();

private:
    QSharedDataPointer<ShipShipmentLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ShipShipmentLine &model);
    friend QDataStream &operator>>(QDataStream &ds, ShipShipmentLine &model);
};

Q_DECLARE_METATYPE(ShipShipmentLine)
Q_DECLARE_METATYPE(QList<ShipShipmentLine>)

#endif // SHIPSHIPMENTLINE_H
