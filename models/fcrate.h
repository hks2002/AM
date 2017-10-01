#ifndef FCRATE_H
#define FCRATE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FcRateObject;
class DataType;
class FcRange;
class FcModel;


class T_MODEL_EXPORT FcRate : public TAbstractModel
{
public:
    FcRate();
    FcRate(const FcRate &other);
    FcRate(const FcRateObject &object);
    ~FcRate();

    int fcModelId() const;
    void setFcModelId(int fcModelId);
    int fcRangeId() const;
    void setFcRangeId(int fcRangeId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    double forecastRateQt() const;
    void setForecastRateQt(double forecastRateQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    DataType dataTypeBydataTypeId() const;
    FcRange fcRangeByfcRangeId() const;
    FcModel fcModelByfcModelId() const;
    FcRate &operator=(const FcRate &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FcRate create(int fcModelId, int fcRangeId, int dataTypeId, double forecastRateQt, const QString &createdBy, const QString &updatedBy);
    static FcRate create(const QVariantMap &values);
    static FcRate get(int fcModelId, int fcRangeId, int dataTypeId);
    static int count();
    static QList<FcRate> getAll();

private:
    QSharedDataPointer<FcRateObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FcRate &model);
    friend QDataStream &operator>>(QDataStream &ds, FcRate &model);
};

Q_DECLARE_METATYPE(FcRate)
Q_DECLARE_METATYPE(QList<FcRate>)

#endif // FCRATE_H
