#ifndef SCHEDWP_H
#define SCHEDWP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SchedWpObject;
class UserApp;
class RefReceiveCond;
class SchedStask;


class T_MODEL_EXPORT SchedWp : public TAbstractModel
{
public:
    SchedWp();
    SchedWp(const SchedWp &other);
    SchedWp(const SchedWpObject &object);
    ~SchedWp();

    int schedId() const;
    void setSchedId(int schedId);
    bool delayBool() const;
    void setDelayBool(bool delayBool);
    bool enforceNsvBool() const;
    void setEnforceNsvBool(bool enforceNsvBool);
    bool enforceWorkscopeBool() const;
    void setEnforceWorkscopeBool(bool enforceWorkscopeBool);
    bool collectionRequiredBool() const;
    void setCollectionRequiredBool(bool collectionRequiredBool);
    bool lrpBool() const;
    void setLrpBool(bool lrpBool);
    bool heavyBool() const;
    void setHeavyBool(bool heavyBool);
    bool initExpCostLockedBool() const;
    void setInitExpCostLockedBool(bool initExpCostLockedBool);
    bool expCostLockedBool() const;
    void setExpCostLockedBool(bool expCostLockedBool);
    bool actualCostLockedBool() const;
    void setActualCostLockedBool(bool actualCostLockedBool);
    bool adjustedBillingBool() const;
    void setAdjustedBillingBool(bool adjustedBillingBool);
    double schedHrMultQt() const;
    void setSchedHrMultQt(double schedHrMultQt);
    int vendorId() const;
    void setVendorId(int vendorId);
    QString vendorWoRefDesc() const;
    void setVendorWoRefDesc(const QString &vendorWoRefDesc);
    QString woRefDesc() const;
    void setWoRefDesc(const QString &woRefDesc);
    QString releaseNumber() const;
    void setReleaseNumber(const QString &releaseNumber);
    QString releaseRemarksDesc() const;
    void setReleaseRemarksDesc(const QString &releaseRemarksDesc);
    QString receiveCondCd() const;
    void setReceiveCondCd(const QString &receiveCondCd);
    int roIssuedBy() const;
    void setRoIssuedBy(int roIssuedBy);
    QDateTime roIssuedDt() const;
    void setRoIssuedDt(const QDateTime &roIssuedDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppByroIssuedBy() const;
    RefReceiveCond refReceiveCondByreceiveCondCd() const;
    SchedStask schedStaskByschedId() const;
    SchedWp &operator=(const SchedWp &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static SchedWp create(int schedId, bool delayBool, bool enforceNsvBool, bool enforceWorkscopeBool, bool collectionRequiredBool, bool lrpBool, bool heavyBool, bool initExpCostLockedBool, bool expCostLockedBool, bool actualCostLockedBool, bool adjustedBillingBool, double schedHrMultQt, int vendorId, const QString &vendorWoRefDesc, const QString &woRefDesc, const QString &releaseNumber, const QString &releaseRemarksDesc, const QString &receiveCondCd, int roIssuedBy, const QDateTime &roIssuedDt, const QString &createdBy, const QString &updatedBy);
    static SchedWp create(const QVariantMap &values);
    static SchedWp get(int schedId);
    static int count();
    static QList<SchedWp> getAll();

private:
    QSharedDataPointer<SchedWpObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const SchedWp &model);
    friend QDataStream &operator>>(QDataStream &ds, SchedWp &model);
};

Q_DECLARE_METATYPE(SchedWp)
Q_DECLARE_METATYPE(QList<SchedWp>)

#endif // SCHEDWP_H
