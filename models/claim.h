#ifndef CLAIM_H
#define CLAIM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ClaimObject;
class UserApp;
class InvInv;
class Vendor;
class WarrantyEval;
class Transportor;
class RefClaimTo;


class T_MODEL_EXPORT Claim : public TAbstractModel
{
public:
    Claim();
    Claim(const Claim &other);
    Claim(const ClaimObject &object);
    ~Claim();

    int claimId() const;
    QString claimToCd() const;
    void setClaimToCd(const QString &claimToCd);
    int transportorId() const;
    void setTransportorId(int transportorId);
    int warrantyEvalId() const;
    void setWarrantyEvalId(int warrantyEvalId);
    int vendorId() const;
    void setVendorId(int vendorId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int contactTo() const;
    void setContactTo(int contactTo);
    QString creditRefDesc() const;
    void setCreditRefDesc(const QString &creditRefDesc);
    int totalRequestedQt() const;
    void setTotalRequestedQt(int totalRequestedQt);
    int totalRecoveredQt() const;
    void setTotalRecoveredQt(int totalRecoveredQt);
    QString claimNote() const;
    void setClaimNote(const QString &claimNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    UserApp userAppBycontactTo() const;
    InvInv invInvByinvNoId() const;
    Vendor vendorByvendorId() const;
    WarrantyEval warrantyEvalBywarrantyEvalId() const;
    Transportor transportorBytransportorId() const;
    RefClaimTo refClaimToByclaimToCd() const;
    Claim &operator=(const Claim &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Claim create(const QString &claimToCd, int transportorId, int warrantyEvalId, int vendorId, int invNoId, int contactTo, const QString &creditRefDesc, int totalRequestedQt, int totalRecoveredQt, const QString &claimNote, const QString &createdBy, const QString &updatedBy);
    static Claim create(const QVariantMap &values);
    static Claim get(int claimId);
    static int count();
    static QList<Claim> getAll();

private:
    QSharedDataPointer<ClaimObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Claim &model);
    friend QDataStream &operator>>(QDataStream &ds, Claim &model);
};

Q_DECLARE_METATYPE(Claim)
Q_DECLARE_METATYPE(QList<Claim>)

#endif // CLAIM_H
