#ifndef ADDRESS_H
#define ADDRESS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AddressObject;
class Province;
class Country;
class City;


class T_MODEL_EXPORT Address : public TAbstractModel
{
public:
    Address();
    Address(const Address &other);
    Address(const AddressObject &object);
    ~Address();

    int addressId() const;
    QString addressLine1() const;
    void setAddressLine1(const QString &addressLine1);
    QString addressLine2() const;
    void setAddressLine2(const QString &addressLine2);
    int cityId() const;
    void setCityId(int cityId);
    int countryId() const;
    void setCountryId(int countryId);
    int provinceId() const;
    void setProvinceId(int provinceId);
    QString zipCd() const;
    void setZipCd(const QString &zipCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Province provinceByprovinceId() const;
    Country countryBycountryId() const;
    City cityBycityId() const;
    Address &operator=(const Address &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Address create(const QString &addressLine1, const QString &addressLine2, int cityId, int countryId, int provinceId, const QString &zipCd, const QString &createdBy, const QString &updatedBy);
    static Address create(const QVariantMap &values);
    static Address get(int addressId);
    static int count();
    static QList<Address> getAll();

private:
    QSharedDataPointer<AddressObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Address &model);
    friend QDataStream &operator>>(QDataStream &ds, Address &model);
};

Q_DECLARE_METATYPE(Address)
Q_DECLARE_METATYPE(QList<Address>)

#endif // ADDRESS_H
