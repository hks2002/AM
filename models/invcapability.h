#ifndef INVCAPABILITY_H
#define INVCAPABILITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvCapabilityObject;
class OperationCapability;
class InvInv;


class T_MODEL_EXPORT InvCapability : public TAbstractModel
{
public:
    InvCapability();
    InvCapability(const InvCapability &other);
    InvCapability(const InvCapabilityObject &object);
    ~InvCapability();

    int invNoId() const;
    void setInvNoId(int invNoId);
    int capabilityId() const;
    void setCapabilityId(int capabilityId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    OperationCapability operationCapabilityBycapabilityId() const;
    InvInv invInvByinvNoId() const;
    InvCapability &operator=(const InvCapability &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static InvCapability create(int invNoId, int capabilityId, const QString &createdBy, const QString &updatedBy);
    static InvCapability create(const QVariantMap &values);
    static InvCapability get(int invNoId, int capabilityId);
    static int count();
    static QList<InvCapability> getAll();

private:
    QSharedDataPointer<InvCapabilityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const InvCapability &model);
    friend QDataStream &operator>>(QDataStream &ds, InvCapability &model);
};

Q_DECLARE_METATYPE(InvCapability)
Q_DECLARE_METATYPE(QList<InvCapability>)

#endif // INVCAPABILITY_H
