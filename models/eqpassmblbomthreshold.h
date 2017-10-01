#ifndef EQPASSMBLBOMTHRESHOLD_H
#define EQPASSMBLBOMTHRESHOLD_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EqpAssmblBomThresholdObject;
class RefThresholdMode;
class EqpAssmblBom;


class T_MODEL_EXPORT EqpAssmblBomThreshold : public TAbstractModel
{
public:
    EqpAssmblBomThreshold();
    EqpAssmblBomThreshold(const EqpAssmblBomThreshold &other);
    EqpAssmblBomThreshold(const EqpAssmblBomThresholdObject &object);
    ~EqpAssmblBomThreshold();

    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    QString thresholdModeCd() const;
    void setThresholdModeCd(const QString &thresholdModeCd);
    int thresholdDaysQt() const;
    void setThresholdDaysQt(int thresholdDaysQt);
    int thresholdQt() const;
    void setThresholdQt(int thresholdQt);
    QString thresholdDesc() const;
    void setThresholdDesc(const QString &thresholdDesc);
    QDateTime effectiveDt() const;
    void setEffectiveDt(const QDateTime &effectiveDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefThresholdMode refThresholdModeBythresholdModeCd() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmblBomThreshold &operator=(const EqpAssmblBomThreshold &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EqpAssmblBomThreshold create(int assmblBomId, const QString &thresholdModeCd, int thresholdDaysQt, int thresholdQt, const QString &thresholdDesc, const QDateTime &effectiveDt, const QString &createdBy, const QString &updatedBy);
    static EqpAssmblBomThreshold create(const QVariantMap &values);
    static EqpAssmblBomThreshold get(int assmblBomId, const QString &thresholdModeCd);
    static int count();
    static QList<EqpAssmblBomThreshold> getAll();

private:
    QSharedDataPointer<EqpAssmblBomThresholdObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EqpAssmblBomThreshold &model);
    friend QDataStream &operator>>(QDataStream &ds, EqpAssmblBomThreshold &model);
};

Q_DECLARE_METATYPE(EqpAssmblBomThreshold)
Q_DECLARE_METATYPE(QList<EqpAssmblBomThreshold>)

#endif // EQPASSMBLBOMTHRESHOLD_H
