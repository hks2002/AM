#ifndef CLAIMLABOURLINE_H
#define CLAIMLABOURLINE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ClaimLabourLineObject;
class WarrantyEvalLabour;
class Claim;


class T_MODEL_EXPORT ClaimLabourLine : public TAbstractModel
{
public:
    ClaimLabourLine();
    ClaimLabourLine(const ClaimLabourLine &other);
    ClaimLabourLine(const ClaimLabourLineObject &object);
    ~ClaimLabourLine();

    int claimId() const;
    void setClaimId(int claimId);
    int warrantyEvalId() const;
    void setWarrantyEvalId(int warrantyEvalId);
    int schedId() const;
    void setSchedId(int schedId);
    int labourId() const;
    void setLabourId(int labourId);
    QString lineDesc() const;
    void setLineDesc(const QString &lineDesc);
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
    WarrantyEvalLabour warrantyEvalLabourBywarrantyEvalIdschedIdlabourId() const;
    Claim claimByclaimId() const;
    ClaimLabourLine &operator=(const ClaimLabourLine &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ClaimLabourLine create(int claimId, int warrantyEvalId, int schedId, int labourId, const QString &lineDesc, int claimQt, double unitPrice, double linePrice, const QString &note, bool rejectWarrantyBool, const QString &createdBy, const QString &updatedBy);
    static ClaimLabourLine create(const QVariantMap &values);
    static ClaimLabourLine get(int claimId, int warrantyEvalId);
    static int count();
    static QList<ClaimLabourLine> getAll();

private:
    QSharedDataPointer<ClaimLabourLineObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ClaimLabourLine &model);
    friend QDataStream &operator>>(QDataStream &ds, ClaimLabourLine &model);
};

Q_DECLARE_METATYPE(ClaimLabourLine)
Q_DECLARE_METATYPE(QList<ClaimLabourLine>)

#endif // CLAIMLABOURLINE_H
