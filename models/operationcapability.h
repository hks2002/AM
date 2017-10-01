#ifndef OPERATIONCAPABILITY_H
#define OPERATIONCAPABILITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class OperationCapabilityObject;


class T_MODEL_EXPORT OperationCapability : public TAbstractModel
{
public:
    OperationCapability();
    OperationCapability(const OperationCapability &other);
    OperationCapability(const OperationCapabilityObject &object);
    ~OperationCapability();

    int capabilityId() const;
    QString capabilityCd() const;
    void setCapabilityCd(const QString &capabilityCd);
    QString capabilityNameZh() const;
    void setCapabilityNameZh(const QString &capabilityNameZh);
    QString capabilityNameEn() const;
    void setCapabilityNameEn(const QString &capabilityNameEn);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    OperationCapability &operator=(const OperationCapability &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static OperationCapability create(const QString &capabilityCd, const QString &capabilityNameZh, const QString &capabilityNameEn, const QString &createdBy, const QString &updatedBy);
    static OperationCapability create(const QVariantMap &values);
    static OperationCapability get(int capabilityId);
    static int count();
    static QList<OperationCapability> getAll();

private:
    QSharedDataPointer<OperationCapabilityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const OperationCapability &model);
    friend QDataStream &operator>>(QDataStream &ds, OperationCapability &model);
};

Q_DECLARE_METATYPE(OperationCapability)
Q_DECLARE_METATYPE(QList<OperationCapability>)

#endif // OPERATIONCAPABILITY_H
