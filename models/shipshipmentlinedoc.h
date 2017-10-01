#ifndef SHIPSHIPMENTLINEDOC_H
#define SHIPSHIPMENTLINEDOC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ShipShipmentLineDocObject;
class RegBodyDoc;
class ShipShipmentLine;


class T_MODEL_EXPORT ShipShipmentLineDoc : public TAbstractModel
{
public:
    ShipShipmentLineDoc();
    ShipShipmentLineDoc(const ShipShipmentLineDoc &other);
    ShipShipmentLineDoc(const ShipShipmentLineDocObject &object);
    ~ShipShipmentLineDoc();

    int shipmentLineId() const;
    void setShipmentLineId(int shipmentLineId);
    int regBodyDocId() const;
    void setRegBodyDocId(int regBodyDocId);
    bool receivedDocBool() const;
    void setReceivedDocBool(bool receivedDocBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RegBodyDoc regBodyDocByregBodyDocId() const;
    ShipShipmentLine shipShipmentLineByshipmentLineId() const;
    ShipShipmentLineDoc &operator=(const ShipShipmentLineDoc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ShipShipmentLineDoc create(int shipmentLineId, int regBodyDocId, bool receivedDocBool, const QString &createdBy, const QString &updatedBy);
    static ShipShipmentLineDoc create(const QVariantMap &values);
    static ShipShipmentLineDoc get(int shipmentLineId, int regBodyDocId);
    static int count();
    static QList<ShipShipmentLineDoc> getAll();

private:
    QSharedDataPointer<ShipShipmentLineDocObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ShipShipmentLineDoc &model);
    friend QDataStream &operator>>(QDataStream &ds, ShipShipmentLineDoc &model);
};

Q_DECLARE_METATYPE(ShipShipmentLineDoc)
Q_DECLARE_METATYPE(QList<ShipShipmentLineDoc>)

#endif // SHIPSHIPMENTLINEDOC_H
