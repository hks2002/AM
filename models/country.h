#ifndef COUNTRY_H
#define COUNTRY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CountryObject;


class T_MODEL_EXPORT Country : public TAbstractModel
{
public:
    Country();
    Country(const Country &other);
    Country(const CountryObject &object);
    ~Country();

    int countryId() const;
    QString countryNameZh() const;
    void setCountryNameZh(const QString &countryNameZh);
    QString countryNameEn() const;
    void setCountryNameEn(const QString &countryNameEn);
    QString countryDesc() const;
    void setCountryDesc(const QString &countryDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Country &operator=(const Country &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Country create(const QString &countryNameZh, const QString &countryNameEn, const QString &countryDesc, const QString &createdBy, const QString &updatedBy);
    static Country create(const QVariantMap &values);
    static Country get(int countryId);
    static int count();
    static QList<Country> getAll();

private:
    QSharedDataPointer<CountryObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Country &model);
    friend QDataStream &operator>>(QDataStream &ds, Country &model);
};

Q_DECLARE_METATYPE(Country)
Q_DECLARE_METATYPE(QList<Country>)

#endif // COUNTRY_H
