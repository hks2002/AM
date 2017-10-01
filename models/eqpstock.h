#ifndef EQPSTOCK_H
#define EQPSTOCK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpStockObject;
class QtyUnit;


class T_MODEL_EXPORT EqpStock : public TAbstractModel
{
public:
    EqpStock();
    EqpStock(const EqpStock &other);
    EqpStock(const EqpStockObject &object);
    ~EqpStock();

    int stockId() const;
    QString stockNoCd() const;
    void setStockNoCd(const QString &stockNoCd);
    QString stockNoName() const;
    void setStockNoName(const QString &stockNoName);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    int monthlyDemandQt() const;
    void setMonthlyDemandQt(int monthlyDemandQt);
    int safetyLevelQt() const;
    void setSafetyLevelQt(int safetyLevelQt);
    int maxMultQt() const;
    void setMaxMultQt(int maxMultQt);
    int defaultReorderQt() const;
    void setDefaultReorderQt(int defaultReorderQt);
    int defaultShipQt() const;
    void setDefaultShipQt(int defaultShipQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    QtyUnit qtyUnitByqtyUnitId() const;
    EqpStock &operator=(const EqpStock &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpStock create(const QString &stockNoCd, const QString &stockNoName, int qtyUnitId, int monthlyDemandQt, int safetyLevelQt, int maxMultQt, int defaultReorderQt, int defaultShipQt, const QString &createdBy, const QString &updatedBy);
    static EqpStock create(const QVariantMap &values);
    static EqpStock get(int stockId);
    static int count();
    static QList<EqpStock> getAll();

private:
    QSharedDataPointer<EqpStockObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpStock &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpStock &model);
};

Q_DECLARE_METATYPE(EqpStock)
Q_DECLARE_METATYPE(QList<EqpStock>)

#endif // EQPSTOCK_H
