#ifndef ORGADDRESS_H
#define ORGADDRESS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OrgAddressObject;
class Address;
class Org;


class T_MODEL_EXPORT OrgAddress : public TAbstractModel
{
public:
    OrgAddress();
    OrgAddress(const OrgAddress &other);
    OrgAddress(const OrgAddressObject &object);
    ~OrgAddress();

    int orgId() const;
    void setOrgId(int orgId);
    int addressId() const;
    void setAddressId(int addressId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Address addressByaddressId() const;
    Org orgByorgId() const;
    OrgAddress &operator=(const OrgAddress &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OrgAddress create(int orgId, int addressId, const QString &createdBy, const QString &updatedBy);
    static OrgAddress create(const QVariantMap &values);
    static OrgAddress get(int orgId);
    static int count();
    static QList<OrgAddress> getAll();

private:
    QSharedDataPointer<OrgAddressObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OrgAddress &model);
    friend QDataStream &operator>>(QDataStream &ds, OrgAddress &model);
};

Q_DECLARE_METATYPE(OrgAddress)
Q_DECLARE_METATYPE(QList<OrgAddress>)

#endif // ORGADDRESS_H
