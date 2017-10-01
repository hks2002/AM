#ifndef CITY_H
#define CITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CityObject;


class T_MODEL_EXPORT City : public TAbstractModel
{
public:
    City();
    City(const City &other);
    City(const CityObject &object);
    ~City();

    int cityId() const;
    QString cityNameZh() const;
    void setCityNameZh(const QString &cityNameZh);
    QString cityNameEn() const;
    void setCityNameEn(const QString &cityNameEn);
    QString cityDesc() const;
    void setCityDesc(const QString &cityDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    City &operator=(const City &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static City create(const QString &cityNameZh, const QString &cityNameEn, const QString &cityDesc, const QString &createdBy, const QString &updatedBy);
    static City create(const QVariantMap &values);
    static City get(int cityId);
    static int count();
    static QList<City> getAll();

private:
    QSharedDataPointer<CityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const City &model);
    friend QDataStream &operator>>(QDataStream &ds, City &model);
};

Q_DECLARE_METATYPE(City)
Q_DECLARE_METATYPE(QList<City>)

#endif // CITY_H
