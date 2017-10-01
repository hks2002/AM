#ifndef ORGVENDORAPPROVAL_H
#define ORGVENDORAPPROVAL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgVendorApprovalObject;
class RefVendorType;
class Vendor;
class Org;


class T_MODEL_EXPORT OrgVendorApproval : public TAbstractModel
{
public:
    OrgVendorApproval();
    OrgVendorApproval(const OrgVendorApproval &other);
    OrgVendorApproval(const OrgVendorApprovalObject &object);
    ~OrgVendorApproval();

    int orgId() const;
    void setOrgId(int orgId);
    int vendorId() const;
    void setVendorId(int vendorId);
    QString vendorTypeCd() const;
    void setVendorTypeCd(const QString &vendorTypeCd);
    QString approvalCd() const;
    void setApprovalCd(const QString &approvalCd);
    QDateTime approvalExpiryDt() const;
    void setApprovalExpiryDt(const QDateTime &approvalExpiryDt);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefVendorType refVendorTypeByvendorTypeCd() const;
    Vendor vendorByvendorId() const;
    Org orgByorgId() const;
    OrgVendorApproval &operator=(const OrgVendorApproval &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OrgVendorApproval create(int orgId, int vendorId, const QString &vendorTypeCd, const QString &approvalCd, const QDateTime &approvalExpiryDt, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static OrgVendorApproval create(const QVariantMap &values);
    static OrgVendorApproval get(int orgId, int vendorId, const QString &vendorTypeCd);
    static int count();
    static QList<OrgVendorApproval> getAll();

private:
    QSharedDataPointer<OrgVendorApprovalObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OrgVendorApproval &model);
    friend QDataStream &operator>>(QDataStream &ds, OrgVendorApproval &model);
};

Q_DECLARE_METATYPE(OrgVendorApproval)
Q_DECLARE_METATYPE(QList<OrgVendorApproval>)

#endif // ORGVENDORAPPROVAL_H
