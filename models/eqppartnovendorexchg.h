#ifndef EQPPARTNOVENDOREXCHG_H
#define EQPPARTNOVENDOREXCHG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoVendorExchgObject;
class Vendor;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoVendorExchg : public TAbstractModel
{
public:
    EqpPartNoVendorExchg();
    EqpPartNoVendorExchg(const EqpPartNoVendorExchg &other);
    EqpPartNoVendorExchg(const EqpPartNoVendorExchgObject &object);
    ~EqpPartNoVendorExchg();

    int partNoId() const;
    void setPartNoId(int partNoId);
    int vendorId() const;
    void setVendorId(int vendorId);
    double basePrice() const;
    void setBasePrice(double basePrice);
    double exchgCost() const;
    void setExchgCost(double exchgCost);
    QString leadTime() const;
    void setLeadTime(const QString &leadTime);
    bool prefBool() const;
    void setPrefBool(bool prefBool);
    QDateTime returnTime() const;
    void setReturnTime(const QDateTime &returnTime);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoVendorExchg &operator=(const EqpPartNoVendorExchg &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoVendorExchg create(int partNoId, int vendorId, double basePrice, double exchgCost, const QString &leadTime, bool prefBool, const QDateTime &returnTime, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoVendorExchg create(const QVariantMap &values);
    static EqpPartNoVendorExchg get(int partNoId, int vendorId);
    static int count();
    static QList<EqpPartNoVendorExchg> getAll();

private:
    QSharedDataPointer<EqpPartNoVendorExchgObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorExchg &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorExchg &model);
};

Q_DECLARE_METATYPE(EqpPartNoVendorExchg)
Q_DECLARE_METATYPE(QList<EqpPartNoVendorExchg>)

#endif // EQPPARTNOVENDOREXCHG_H
