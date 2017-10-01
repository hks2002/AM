#ifndef REFTHRESHOLDMODE_H
#define REFTHRESHOLDMODE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class RefThresholdModeObject;


class T_MODEL_EXPORT RefThresholdMode : public TAbstractModel
{
public:
    RefThresholdMode();
    RefThresholdMode(const RefThresholdMode &other);
    RefThresholdMode(const RefThresholdModeObject &object);
    ~RefThresholdMode();

    QString thresholdModeCd() const;
    void setThresholdModeCd(const QString &thresholdModeCd);
    QString thresholdModeNameEn() const;
    void setThresholdModeNameEn(const QString &thresholdModeNameEn);
    QString thresholdModeNameZh() const;
    void setThresholdModeNameZh(const QString &thresholdModeNameZh);
    QString thresholdModeDesc() const;
    void setThresholdModeDesc(const QString &thresholdModeDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefThresholdMode &operator=(const RefThresholdMode &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static RefThresholdMode create(const QString &thresholdModeCd, const QString &thresholdModeNameEn, const QString &thresholdModeNameZh, const QString &thresholdModeDesc, const QString &createdBy, const QString &updatedBy);
    static RefThresholdMode create(const QVariantMap &values);
    static RefThresholdMode get(const QString &thresholdModeCd);
    static int count();
    static QList<RefThresholdMode> getAll();

private:
    QSharedDataPointer<RefThresholdModeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const RefThresholdMode &model);
    friend QDataStream &operator>>(QDataStream &ds, RefThresholdMode &model);
};

Q_DECLARE_METATYPE(RefThresholdMode)
Q_DECLARE_METATYPE(QList<RefThresholdMode>)

#endif // REFTHRESHOLDMODE_H
