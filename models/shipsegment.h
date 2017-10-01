#ifndef SHIPSEGMENT_H
#define SHIPSEGMENT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ShipSegmentObject;
class UserApp;
class Loc;
class RefSegmentStatus;
class ShipShipment;


class T_MODEL_EXPORT ShipSegment : public TAbstractModel
{
public:
    ShipSegment();
    ShipSegment(const ShipSegment &other);
    ShipSegment(const ShipSegmentObject &object);
    ~ShipSegment();

    int segmentId() const;
    int shipmentId() const;
    void setShipmentId(int shipmentId);
    int segmentOrd() const;
    void setSegmentOrd(int segmentOrd);
    QString segmentStatusCd() const;
    void setSegmentStatusCd(const QString &segmentStatusCd);
    QString waybillNo() const;
    void setWaybillNo(const QString &waybillNo);
    QString customsDesc() const;
    void setCustomsDesc(const QString &customsDesc);
    int shipFromId() const;
    void setShipFromId(int shipFromId);
    int shipToId() const;
    void setShipToId(int shipToId);
    int completeBy() const;
    void setCompleteBy(int completeBy);
    QDateTime completeDt() const;
    void setCompleteDt(const QDateTime &completeDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBycompleteBy() const;
    Loc locByshipToId() const;
    RefSegmentStatus refSegmentStatusBysegmentStatusCd() const;
    ShipShipment shipShipmentByshipmentId() const;
    ShipSegment &operator=(const ShipSegment &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ShipSegment create(int shipmentId, int segmentOrd, const QString &segmentStatusCd, const QString &waybillNo, const QString &customsDesc, int shipFromId, int shipToId, int completeBy, const QDateTime &completeDt, const QString &createdBy, const QString &updatedBy);
    static ShipSegment create(const QVariantMap &values);
    static ShipSegment get(int segmentId);
    static int count();
    static QList<ShipSegment> getAll();

private:
    QSharedDataPointer<ShipSegmentObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ShipSegment &model);
    friend QDataStream &operator>>(QDataStream &ds, ShipSegment &model);
};

Q_DECLARE_METATYPE(ShipSegment)
Q_DECLARE_METATYPE(QList<ShipSegment>)

#endif // SHIPSEGMENT_H
