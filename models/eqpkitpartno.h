#ifndef EQPKITPARTNO_H
#define EQPKITPARTNO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpKitPartNoObject;
class EqpPartNo;


class T_MODEL_EXPORT EqpKitPartNo : public TAbstractModel
{
public:
    EqpKitPartNo();
    EqpKitPartNo(const EqpKitPartNo &other);
    EqpKitPartNo(const EqpKitPartNoObject &object);
    ~EqpKitPartNo();

    int kitPartNoId() const;
    void setKitPartNoId(int kitPartNoId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int partOrder() const;
    void setPartOrder(int partOrder);
    double qty() const;
    void setQty(double qty);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpKitPartNo &operator=(const EqpKitPartNo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpKitPartNo create(int kitPartNoId, int partNoId, int partOrder, double qty, const QString &createdBy, const QString &updatedBy);
    static EqpKitPartNo create(const QVariantMap &values);
    static EqpKitPartNo get(int kitPartNoId, int partNoId);
    static int count();
    static QList<EqpKitPartNo> getAll();

private:
    QSharedDataPointer<EqpKitPartNoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpKitPartNo &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpKitPartNo &model);
};

Q_DECLARE_METATYPE(EqpKitPartNo)
Q_DECLARE_METATYPE(QList<EqpKitPartNo>)

#endif // EQPKITPARTNO_H
