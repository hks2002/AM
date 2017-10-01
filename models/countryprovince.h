#ifndef COUNTRYPROVINCE_H
#define COUNTRYPROVINCE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CountryProvinceObject;
class Province;
class Country;


class T_MODEL_EXPORT CountryProvince : public TAbstractModel
{
public:
    CountryProvince();
    CountryProvince(const CountryProvince &other);
    CountryProvince(const CountryProvinceObject &object);
    ~CountryProvince();

    int countryId() const;
    void setCountryId(int countryId);
    int provinceId() const;
    void setProvinceId(int provinceId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Province provinceByprovinceId() const;
    Country countryBycountryId() const;
    CountryProvince &operator=(const CountryProvince &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static CountryProvince create(int countryId, int provinceId, const QString &createdBy, const QString &updatedBy);
    static CountryProvince create(const QVariantMap &values);
    static CountryProvince get(int countryId, int provinceId);
    static int count();
    static QList<CountryProvince> getAll();

private:
    QSharedDataPointer<CountryProvinceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const CountryProvince &model);
    friend QDataStream &operator>>(QDataStream &ds, CountryProvince &model);
};

Q_DECLARE_METATYPE(CountryProvince)
Q_DECLARE_METATYPE(QList<CountryProvince>)

#endif // COUNTRYPROVINCE_H
