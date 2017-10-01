#ifndef EQPPARTNOALTUNIT_H
#define EQPPARTNOALTUNIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoAltUnitObject;
class QtyUnit;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoAltUnit : public TAbstractModel
{
public:
    EqpPartNoAltUnit();
    EqpPartNoAltUnit(const EqpPartNoAltUnit &other);
    EqpPartNoAltUnit(const EqpPartNoAltUnitObject &object);
    ~EqpPartNoAltUnit();

    int partNoId() const;
    void setPartNoId(int partNoId);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    int altUnitId() const;
    void setAltUnitId(int altUnitId);
    double qtyConvertQt() const;
    void setQtyConvertQt(double qtyConvertQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    QtyUnit qtyUnitByaltUnitId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoAltUnit &operator=(const EqpPartNoAltUnit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoAltUnit create(int partNoId, int qtyUnitId, int altUnitId, double qtyConvertQt, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoAltUnit create(const QVariantMap &values);
    static EqpPartNoAltUnit get(int partNoId, int qtyUnitId, int altUnitId);
    static int count();
    static QList<EqpPartNoAltUnit> getAll();

private:
    QSharedDataPointer<EqpPartNoAltUnitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoAltUnit &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoAltUnit &model);
};

Q_DECLARE_METATYPE(EqpPartNoAltUnit)
Q_DECLARE_METATYPE(QList<EqpPartNoAltUnit>)

#endif // EQPPARTNOALTUNIT_H
