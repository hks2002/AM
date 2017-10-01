#ifndef EQPSTOCKPARTNO_H
#define EQPSTOCKPARTNO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpStockPartNoObject;
class EqpPartNo;
class EqpStock;


class T_MODEL_EXPORT EqpStockPartNo : public TAbstractModel
{
public:
    EqpStockPartNo();
    EqpStockPartNo(const EqpStockPartNo &other);
    EqpStockPartNo(const EqpStockPartNoObject &object);
    ~EqpStockPartNo();

    int stockId() const;
    void setStockId(int stockId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    double partNoPct() const;
    void setPartNoPct(double partNoPct);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpStock eqpStockBystockId() const;
    EqpStockPartNo &operator=(const EqpStockPartNo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpStockPartNo create(int stockId, int partNoId, double partNoPct, const QString &createdBy, const QString &updatedBy);
    static EqpStockPartNo create(const QVariantMap &values);
    static EqpStockPartNo get(int stockId, int partNoId);
    static int count();
    static QList<EqpStockPartNo> getAll();

private:
    QSharedDataPointer<EqpStockPartNoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpStockPartNo &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpStockPartNo &model);
};

Q_DECLARE_METATYPE(EqpStockPartNo)
Q_DECLARE_METATYPE(QList<EqpStockPartNo>)

#endif // EQPSTOCKPARTNO_H
