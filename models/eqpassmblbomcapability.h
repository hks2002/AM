#ifndef EQPASSMBLBOMCAPABILITY_H
#define EQPASSMBLBOMCAPABILITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomCapabilityObject;
class OperationCapability;
class EqpAssmblBom;


class T_MODEL_EXPORT EqpAssmblBomCapability : public TAbstractModel
{
public:
    EqpAssmblBomCapability();
    EqpAssmblBomCapability(const EqpAssmblBomCapability &other);
    EqpAssmblBomCapability(const EqpAssmblBomCapabilityObject &object);
    ~EqpAssmblBomCapability();

    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int capabilityId() const;
    void setCapabilityId(int capabilityId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    OperationCapability operationCapabilityBycapabilityId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmblBomCapability &operator=(const EqpAssmblBomCapability &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomCapability create(int assmblBomId, int capabilityId, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomCapability create(const QVariantMap &values);
    static EqpAssmblBomCapability get(int assmblBomId, int capabilityId);
    static int count();
    static QList<EqpAssmblBomCapability> getAll();

private:
    QSharedDataPointer<EqpAssmblBomCapabilityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomCapability &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomCapability &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomCapability)
Q_DECLARE_METATYPE(QList<EqpAssmblBomCapability>)

#endif // EQPASSMBLBOMCAPABILITY_H
