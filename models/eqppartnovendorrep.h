#ifndef EQPPARTNOVENDORREP_H
#define EQPPARTNOVENDORREP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoVendorRepObject;
class Vendor;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoVendorRep : public TAbstractModel
{
public:
    EqpPartNoVendorRep();
    EqpPartNoVendorRep(const EqpPartNoVendorRep &other);
    EqpPartNoVendorRep(const EqpPartNoVendorRepObject &object);
    ~EqpPartNoVendorRep();

    int partNoId() const;
    void setPartNoId(int partNoId);
    int vendorId() const;
    void setVendorId(int vendorId);
    double repairCost() const;
    void setRepairCost(double repairCost);
    QString leadTime() const;
    void setLeadTime(const QString &leadTime);
    bool prefBool() const;
    void setPrefBool(bool prefBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoVendorRep &operator=(const EqpPartNoVendorRep &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoVendorRep create(int partNoId, int vendorId, double repairCost, const QString &leadTime, bool prefBool, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoVendorRep create(const QVariantMap &values);
    static EqpPartNoVendorRep get(int partNoId, int vendorId);
    static int count();
    static QList<EqpPartNoVendorRep> getAll();

private:
    QSharedDataPointer<EqpPartNoVendorRepObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorRep &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorRep &model);
};

Q_DECLARE_METATYPE(EqpPartNoVendorRep)
Q_DECLARE_METATYPE(QList<EqpPartNoVendorRep>)

#endif // EQPPARTNOVENDORREP_H
