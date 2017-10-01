#ifndef VENDORACCOUNT_H
#define VENDORACCOUNT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VendorAccountObject;
class FncAccount;
class Vendor;


class T_MODEL_EXPORT VendorAccount : public TAbstractModel
{
public:
    VendorAccount();
    VendorAccount(const VendorAccount &other);
    VendorAccount(const VendorAccountObject &object);
    ~VendorAccount();

    int vendorId() const;
    void setVendorId(int vendorId);
    int accountId() const;
    void setAccountId(int accountId);
    bool mainBool() const;
    void setMainBool(bool mainBool);
    bool activeBool() const;
    void setActiveBool(bool activeBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FncAccount fncAccountByaccountId() const;
    Vendor vendorByvendorId() const;
    VendorAccount &operator=(const VendorAccount &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VendorAccount create(int vendorId, int accountId, bool mainBool, bool activeBool, const QString &createdBy, const QString &updatedBy);
    static VendorAccount create(const QVariantMap &values);
    static VendorAccount get(int vendorId, int accountId);
    static int count();
    static QList<VendorAccount> getAll();

private:
    QSharedDataPointer<VendorAccountObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VendorAccount &model);
    friend QDataStream &operator>>(QDataStream &ds, VendorAccount &model);
};

Q_DECLARE_METATYPE(VendorAccount)
Q_DECLARE_METATYPE(QList<VendorAccount>)

#endif // VENDORACCOUNT_H
