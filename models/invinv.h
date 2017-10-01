#ifndef INVINV_H
#define INVINV_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvInvObject;
class RefInvClass;
class EqpAssmbl;
class EqpAssmblBom;
class EqpAssmblBomPos;
class EqpPartNo;
class Loc;
class Authority;
class Vendor;
class RefInvCond;
class RefReceiveCond;
class OwnerApp;
class RefOwnBy;
class PoHeader;
class PoLine;
class FncAccount;


class T_MODEL_EXPORT InvInv : public TAbstractModel
{
public:
    InvInv();
    InvInv(const InvInv &other);
    InvInv(const InvInvObject &object);
    ~InvInv();

    int invNoId() const;
    QString invClassCd() const;
    void setInvClassCd(const QString &invClassCd);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int assmblBomPosId() const;
    void setAssmblBomPosId(int assmblBomPosId);
    QString configPosDesc() const;
    void setConfigPosDesc(const QString &configPosDesc);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString serialNoOem() const;
    void setSerialNoOem(const QString &serialNoOem);
    QString batchNoOem() const;
    void setBatchNoOem(const QString &batchNoOem);
    QString icnNoDesc() const;
    void setIcnNoDesc(const QString &icnNoDesc);
    QString applEffCd() const;
    void setApplEffCd(const QString &applEffCd);
    QString invNoDesc() const;
    void setInvNoDesc(const QString &invNoDesc);
    QString lotOemTag() const;
    void setLotOemTag(const QString &lotOemTag);
    QString modStatusNote() const;
    void setModStatusNote(const QString &modStatusNote);
    QString barcodeDesc() const;
    void setBarcodeDesc(const QString &barcodeDesc);
    int locId() const;
    void setLocId(int locId);
    int authorityId() const;
    void setAuthorityId(int authorityId);
    int hInvNoId() const;
    void setHInvNoId(int hInvNoId);
    int nhInvNoId() const;
    void setNhInvNoId(int nhInvNoId);
    int assmblInvNoId() const;
    void setAssmblInvNoId(int assmblInvNoId);
    int vendorId() const;
    void setVendorId(int vendorId);
    QString invCondCd() const;
    void setInvCondCd(const QString &invCondCd);
    QString receiveCondCd() const;
    void setReceiveCondCd(const QString &receiveCondCd);
    QString origAssmblCd() const;
    void setOrigAssmblCd(const QString &origAssmblCd);
    int origAssmblInvNoId() const;
    void setOrigAssmblInvNoId(int origAssmblInvNoId);
    QDateTime manufactDt() const;
    void setManufactDt(const QDateTime &manufactDt);
    QDateTime receivedDt() const;
    void setReceivedDt(const QDateTime &receivedDt);
    QDateTime installDt() const;
    void setInstallDt(const QDateTime &installDt);
    int ownerId() const;
    void setOwnerId(int ownerId);
    QString ownByCd() const;
    void setOwnByCd(const QString &ownByCd);
    bool notFoundBool() const;
    void setNotFoundBool(bool notFoundBool);
    bool completeBool() const;
    void setCompleteBool(bool completeBool);
    bool issuedBool() const;
    void setIssuedBool(bool issuedBool);
    bool lockedBool() const;
    void setLockedBool(bool lockedBool);
    bool pickedBool() const;
    void setPickedBool(bool pickedBool);
    bool usedBool() const;
    void setUsedBool(bool usedBool);
    QString shelfExpiryDt() const;
    void setShelfExpiryDt(const QString &shelfExpiryDt);
    QString note() const;
    void setNote(const QString &note);
    int binQt() const;
    void setBinQt(int binQt);
    int reserveBinQt() const;
    void setReserveBinQt(int reserveBinQt);
    bool reservedBool() const;
    void setReservedBool(bool reservedBool);
    int poId() const;
    void setPoId(int poId);
    int poLineId() const;
    void setPoLineId(int poLineId);
    int accountId() const;
    void setAccountId(int accountId);
    QString releaseNumber() const;
    void setReleaseNumber(const QString &releaseNumber);
    QString releaseRemarksDesc() const;
    void setReleaseRemarksDesc(const QString &releaseRemarksDesc);
    QDateTime releaseDt() const;
    void setReleaseDt(const QDateTime &releaseDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefInvClass refInvClassByinvClassCd() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmblBomPos eqpAssmblBomPosByassmblBomPosId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    Loc locBylocId() const;
    Authority authorityByauthorityId() const;
    Vendor vendorByvendorId() const;
    RefInvCond refInvCondByinvCondCd() const;
    RefReceiveCond refReceiveCondByreceiveCondCd() const;
    OwnerApp ownerAppByownerId() const;
    RefOwnBy refOwnByByownByCd() const;
    PoHeader poHeaderBypoId() const;
    PoLine poLineBypoLineId() const;
    FncAccount fncAccountByaccountId() const;
    InvInv &operator=(const InvInv &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvInv create(const QString &invClassCd, int assmblId, int assmblBomId, int assmblBomPosId, const QString &configPosDesc, int partNoId, const QString &serialNoOem, const QString &batchNoOem, const QString &icnNoDesc, const QString &applEffCd, const QString &invNoDesc, const QString &lotOemTag, const QString &modStatusNote, const QString &barcodeDesc, int locId, int authorityId, int hInvNoId, int nhInvNoId, int assmblInvNoId, int vendorId, const QString &invCondCd, const QString &receiveCondCd, const QString &origAssmblCd, int origAssmblInvNoId, const QDateTime &manufactDt, const QDateTime &receivedDt, const QDateTime &installDt, int ownerId, const QString &ownByCd, bool notFoundBool, bool completeBool, bool issuedBool, bool lockedBool, bool pickedBool, bool usedBool, const QString &shelfExpiryDt, const QString &note, int binQt, int reserveBinQt, bool reservedBool, int poId, int poLineId, int accountId, const QString &releaseNumber, const QString &releaseRemarksDesc, const QDateTime &releaseDt, const QString &createdBy, const QString &updatedBy);
    static InvInv create(const QVariantMap &values);
    static InvInv get(int invNoId);
    static int count();
    static QList<InvInv> getAll();

private:
    QSharedDataPointer<InvInvObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvInv &model);
    friend QDataStream &operator>>(QDataStream &ds, InvInv &model);
};

Q_DECLARE_METATYPE(InvInv)
Q_DECLARE_METATYPE(QList<InvInv>)

#endif // INVINV_H
