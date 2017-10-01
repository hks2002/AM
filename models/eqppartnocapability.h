#ifndef EQPPARTNOCAPABILITY_H
#define EQPPARTNOCAPABILITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpPartNoCapabilityObject;
class OperationCapability;
class EqpPartNo;


class T_MODEL_EXPORT EqpPartNoCapability : public TAbstractModel
{
public:
    EqpPartNoCapability();
    EqpPartNoCapability(const EqpPartNoCapability &other);
    EqpPartNoCapability(const EqpPartNoCapabilityObject &object);
    ~EqpPartNoCapability();

    int partNoId() const;
    void setPartNoId(int partNoId);
    int capabilityId() const;
    void setCapabilityId(int capabilityId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    OperationCapability operationCapabilityBycapabilityId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpPartNoCapability &operator=(const EqpPartNoCapability &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpPartNoCapability create(int partNoId, int capabilityId, const QString &createdBy, const QString &updatedBy);
    static EqpPartNoCapability create(const QVariantMap &values);
    static EqpPartNoCapability get(int partNoId, int capabilityId);
    static int count();
    static QList<EqpPartNoCapability> getAll();

private:
    QSharedDataPointer<EqpPartNoCapabilityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpPartNoCapability &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpPartNoCapability &model);
};

Q_DECLARE_METATYPE(EqpPartNoCapability)
Q_DECLARE_METATYPE(QList<EqpPartNoCapability>)

#endif // EQPPARTNOCAPABILITY_H
