#ifndef EQPPARTNOVENDORPUR_H
#define EQPPARTNOVENDORPUR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoVendorPurObject;
class Vendor;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoVendorPur : public TAbstractModel
{
public:
    EqpPartNoVendorPur();
    EqpPartNoVendorPur(const EqpPartNoVendorPur &other);
    EqpPartNoVendorPur(const EqpPartNoVendorPurObject &object);
    ~EqpPartNoVendorPur();

    int partNoId() const;
    void setPartNoId(int partNoId);
    int vendorId() const;
    void setVendorId(int vendorId);
    bool prefBool() const;
    void setPrefBool(bool prefBool);
    QString partNoVendor() const;
    void setPartNoVendor(const QString &partNoVendor);
    int minPurAccount() const;
    void setMinPurAccount(int minPurAccount);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Vendor vendorByvendorId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoVendorPur &operator=(const EqpPartNoVendorPur &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoVendorPur create(int partNoId, int vendorId, bool prefBool, const QString &partNoVendor, int minPurAccount, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoVendorPur create(const QVariantMap &values);
    static EqpPartNoVendorPur get(int partNoId, int vendorId);
    static int count();
    static QList<EqpPartNoVendorPur> getAll();

private:
    QSharedDataPointer<EqpPartNoVendorPurObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoVendorPur &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoVendorPur &model);
};

Q_DECLARE_METATYPE(EqpPartNoVendorPur)
Q_DECLARE_METATYPE(QList<EqpPartNoVendorPur>)

#endif // EQPPARTNOVENDORPUR_H
