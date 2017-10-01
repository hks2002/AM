#ifndef PROVINCECITY_H
#define PROVINCECITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ProvinceCityObject;
class City;
class Province;


class T_MODEL_EXPORT ProvinceCity : public TAbstractModel
{
public:
    ProvinceCity();
    ProvinceCity(const ProvinceCity &other);
    ProvinceCity(const ProvinceCityObject &object);
    ~ProvinceCity();

    int provinceId() const;
    void setProvinceId(int provinceId);
    int cityId() const;
    void setCityId(int cityId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    City cityBycityId() const;
    Province provinceByprovinceId() const;
    ProvinceCity &operator=(const ProvinceCity &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ProvinceCity create(int provinceId, int cityId, const QString &createdBy, const QString &updatedBy);
    static ProvinceCity create(const QVariantMap &values);
    static ProvinceCity get(int provinceId, int cityId);
    static int count();
    static QList<ProvinceCity> getAll();

private:
    QSharedDataPointer<ProvinceCityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ProvinceCity &model);
    friend QDataStream &operator>>(QDataStream &ds, ProvinceCity &model);
};

Q_DECLARE_METATYPE(ProvinceCity)
Q_DECLARE_METATYPE(QList<ProvinceCity>)

#endif // PROVINCECITY_H
