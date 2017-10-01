#ifndef REQPART_H
#define REQPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ReqPartObject;
class RefReqType;
class RefReqPriority;
class EqpPartNo;
class EqpAssmbl;
class EqpAssmblBom;
class EqpStock;
class Loc;
class InvInv;
class RefPartProviderType;
class FncAccount;
class SchedStask;
class SchedInstPart;
class SchedPart;
class ShipShipmentLine;
class PoHeader;
class PoLine;
class Vendor;
class UserApp;


class T_MODEL_EXPORT ReqPart : public TAbstractModel
{
public:
    ReqPart();
    ReqPart(const ReqPart &other);
    ReqPart(const ReqPartObject &object);
    ~ReqPart();

    int reqPartId() const;
    QString reqTypeCd() const;
    void setReqTypeCd(const QString &reqTypeCd);
    QString reqPriorityCd() const;
    void setReqPriorityCd(const QString &reqPriorityCd);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int stockId() const;
    void setStockId(int stockId);
    int locId() const;
    void setLocId(int locId);
    bool lockReserveBool() const;
    void setLockReserveBool(bool lockReserveBool);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QDateTime estArrivalDt() const;
    void setEstArrivalDt(const QDateTime &estArrivalDt);
    QString partProviderTypeCd() const;
    void setPartProviderTypeCd(const QString &partProviderTypeCd);
    bool maTrackBool() const;
    void setMaTrackBool(bool maTrackBool);
    int accountId() const;
    void setAccountId(int accountId);
    double issueUnitPrice() const;
    void setIssueUnitPrice(double issueUnitPrice);
    QString reqMasterId() const;
    void setReqMasterId(const QString &reqMasterId);
    QString reqNote() const;
    void setReqNote(const QString &reqNote);
    QDateTime reqQt() const;
    void setReqQt(const QDateTime &reqQt);
    QDateTime reqDt() const;
    void setReqDt(const QDateTime &reqDt);
    int schedId() const;
    void setSchedId(int schedId);
    int schedInstPartId() const;
    void setSchedInstPartId(int schedInstPartId);
    int schedPartId() const;
    void setSchedPartId(int schedPartId);
    int shipmentLineId() const;
    void setShipmentLineId(int shipmentLineId);
    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    int csgnVendorId() const;
    void setCsgnVendorId(int csgnVendorId);
    int csgnOwedQt() const;
    void setCsgnOwedQt(int csgnOwedQt);
    int assignedTo() const;
    void setAssignedTo(int assignedTo);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReqType refReqTypeByreqTypeCd() const;
    RefReqPriority refReqPriorityByreqPriorityCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpStock eqpStockBystockId() const;
    Loc locBylocId() const;
    InvInv invInvByinvNoId() const;
    RefPartProviderType refPartProviderTypeBypartProviderTypeCd() const;
    FncAccount fncAccountByaccountId() const;
    SchedStask schedStaskByschedId() const;
    SchedInstPart schedInstPartByschedInstPartId() const;
    SchedPart schedPartByschedPartId() const;
    ShipShipmentLine shipShipmentLineByshipmentLineId() const;
    PoHeader poHeaderBypoId() const;
    PoLine poLineBypoLineId() const;
    Vendor vendorBycsgnVendorId() const;
    UserApp userAppByassignedTo() const;
    ReqPart &operator=(const ReqPart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ReqPart create(const QString &reqTypeCd, const QString &reqPriorityCd, int partNoId, int assmblId, int assmblBomId, int stockId, int locId, bool lockReserveBool, int invNoId, const QDateTime &estArrivalDt, const QString &partProviderTypeCd, bool maTrackBool, int accountId, double issueUnitPrice, const QString &reqMasterId, const QString &reqNote, const QDateTime &reqQt, const QDateTime &reqDt, int schedId, int schedInstPartId, int schedPartId, int shipmentLineId, int poId, int poLineId, int csgnVendorId, int csgnOwedQt, int assignedTo, const QString &createdBy, const QString &updatedBy);
    static ReqPart create(const QVariantMap &values);
    static ReqPart get(int reqPartId);
    static int count();
    static QList<ReqPart> getAll();

private:
    QSharedDataPointer<ReqPartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ReqPart &model);
    friend QDataStream &operator>>(QDataStream &ds, ReqPart &model);
};

Q_DECLARE_METATYPE(ReqPart)
Q_DECLARE_METATYPE(QList<ReqPart>)

#endif // REQPART_H
