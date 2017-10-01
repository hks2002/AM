#ifndef CARRIER_H
#define CARRIER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CarrierObject;


class T_MODEL_EXPORT Carrier : public TAbstractModel
{
public:
    Carrier();
    Carrier(const Carrier &other);
    Carrier(const CarrierObject &object);
    ~Carrier();

    int carrierId() const;
    QString carrierCd() const;
    void setCarrierCd(const QString &carrierCd);
    QString carrierName() const;
    void setCarrierName(const QString &carrierName);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Carrier &operator=(const Carrier &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Carrier create(const QString &carrierCd, const QString &carrierName, const QString &createdBy, const QString &updatedBy);
    static Carrier create(const QVariantMap &values);
    static Carrier get(int carrierId);
    static int count();
    static QList<Carrier> getAll();

private:
    QSharedDataPointer<CarrierObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Carrier &model);
    friend QDataStream &operator>>(QDataStream &ds, Carrier &model);
};

Q_DECLARE_METATYPE(Carrier)
Q_DECLARE_METATYPE(QList<Carrier>)

#endif // CARRIER_H
