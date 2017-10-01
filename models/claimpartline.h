#ifndef CLAIMPARTLINE_H
#define CLAIMPARTLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ClaimPartLineObject;
class InvInv;
class WarrantyEvalPart;
class Claim;


class T_MODEL_EXPORT ClaimPartLine : public TAbstractModel
{
public:
    ClaimPartLine();
    ClaimPartLine(const ClaimPartLine &other);
    ClaimPartLine(const ClaimPartLineObject &object);
    ~ClaimPartLine();

    int claimId() const;
    void setClaimId(int claimId);
    int warrantyEvalId() const;
    void setWarrantyEvalId(int warrantyEvalId);
    int schedId() const;
    void setSchedId(int schedId);
    int schedPartId() const;
    void setSchedPartId(int schedPartId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    QString lineLdesc() const;
    void setLineLdesc(const QString &lineLdesc);
    int claimQt() const;
    void setClaimQt(int claimQt);
    double unitPrice() const;
    void setUnitPrice(double unitPrice);
    double linePrice() const;
    void setLinePrice(double linePrice);
    QString note() const;
    void setNote(const QString &note);
    bool rejectWarrantyBool() const;
    void setRejectWarrantyBool(bool rejectWarrantyBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    InvInv invInvByinvNoId() const;
    WarrantyEvalPart warrantyEvalPartBywarrantyEvalIdschedIdschedPartId() const;
    Claim claimByclaimId() const;
    ClaimPartLine &operator=(const ClaimPartLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ClaimPartLine create(int claimId, int warrantyEvalId, int schedId, int schedPartId, int invNoId, const QString &lineLdesc, int claimQt, double unitPrice, double linePrice, const QString &note, bool rejectWarrantyBool, const QString &createdBy, const QString &updatedBy);
    static ClaimPartLine create(const QVariantMap &values);
    static ClaimPartLine get(int claimId, int warrantyEvalId);
    static int count();
    static QList<ClaimPartLine> getAll();

private:
    QSharedDataPointer<ClaimPartLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ClaimPartLine &model);
    friend QDataStream &operator>>(QDataStream &ds, ClaimPartLine &model);
};

Q_DECLARE_METATYPE(ClaimPartLine)
Q_DECLARE_METATYPE(QList<ClaimPartLine>)

#endif // CLAIMPARTLINE_H
