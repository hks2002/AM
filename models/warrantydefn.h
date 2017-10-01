#ifndef WARRANTYDEFN_H
#define WARRANTYDEFN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WarrantyDefnObject;
class Vendor;
class RefWarrantyPriority;
class RefWarrantyStatus;


class T_MODEL_EXPORT WarrantyDefn : public TAbstractModel
{
public:
    WarrantyDefn();
    WarrantyDefn(const WarrantyDefn &other);
    WarrantyDefn(const WarrantyDefnObject &object);
    ~WarrantyDefn();

    int warrantyDefnId() const;
    QString warrantyCd() const;
    void setWarrantyCd(const QString &warrantyCd);
    QString warrantyStatusCd() const;
    void setWarrantyStatusCd(const QString &warrantyStatusCd);
    QString priorityCd() const;
    void setPriorityCd(const QString &priorityCd);
    int vendorId() const;
    void setVendorId(int vendorId);
    QString warrantyDesc() const;
    void setWarrantyDesc(const QString &warrantyDesc);
    QString summaryDesc() const;
    void setSummaryDesc(const QString &summaryDesc);
    QDateTime expireDt() const;
    void setExpireDt(const QDateTime &expireDt);
    bool expiresFirstBool() const;
    void setExpiresFirstBool(bool expiresFirstBool);
    bool routineBool() const;
    void setRoutineBool(bool routineBool);
    bool labourBool() const;
    void setLabourBool(bool labourBool);
    bool origEqpOnlyBool() const;
    void setOrigEqpOnlyBool(bool origEqpOnlyBool);
    double unitPriceThresholdQt() const;
    void setUnitPriceThresholdQt(double unitPriceThresholdQt);
    double turnInPriceThresholdQt() const;
    void setTurnInPriceThresholdQt(double turnInPriceThresholdQt);
    int durationQt() const;
    void setDurationQt(int durationQt);
    double hoursQt() const;
    void setHoursQt(double hoursQt);
    int cyclesQt() const;
    void setCyclesQt(int cyclesQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    RefWarrantyPriority refWarrantyPriorityBypriorityCd() const;
    RefWarrantyStatus refWarrantyStatusBywarrantyStatusCd() const;
    WarrantyDefn &operator=(const WarrantyDefn &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static WarrantyDefn create(const QString &warrantyCd, const QString &warrantyStatusCd, const QString &priorityCd, int vendorId, const QString &warrantyDesc, const QString &summaryDesc, const QDateTime &expireDt, bool expiresFirstBool, bool routineBool, bool labourBool, bool origEqpOnlyBool, double unitPriceThresholdQt, double turnInPriceThresholdQt, int durationQt, double hoursQt, int cyclesQt, const QString &createdBy, const QString &updatedBy);
    static WarrantyDefn create(const QVariantMap &values);
    static WarrantyDefn get(int warrantyDefnId);
    static int count();
    static QList<WarrantyDefn> getAll();

private:
    QSharedDataPointer<WarrantyDefnObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const WarrantyDefn &model);
    friend QDataStream &operator>>(QDataStream &ds, WarrantyDefn &model);
};

Q_DECLARE_METATYPE(WarrantyDefn)
Q_DECLARE_METATYPE(QList<WarrantyDefn>)

#endif // WARRANTYDEFN_H
