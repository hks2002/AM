#ifndef FCRANGE_H
#define FCRANGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FcRangeObject;
class FcModel;


class T_MODEL_EXPORT FcRange : public TAbstractModel
{
public:
    FcRange();
    FcRange(const FcRange &other);
    FcRange(const FcRangeObject &object);
    ~FcRange();

    int fcRangeId() const;
    int fcModelId() const;
    void setFcModelId(int fcModelId);
    int startMonth() const;
    void setStartMonth(int startMonth);
    int startDay() const;
    void setStartDay(int startDay);
    int endMonth() const;
    void setEndMonth(int endMonth);
    int endDay() const;
    void setEndDay(int endDay);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    FcModel fcModelByfcModelId() const;
    FcRange &operator=(const FcRange &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FcRange create(int fcModelId, int startMonth, int startDay, int endMonth, int endDay, const QString &createdBy, const QString &updatedBy);
    static FcRange create(const QVariantMap &values);
    static FcRange get(int fcRangeId);
    static int count();
    static QList<FcRange> getAll();

private:
    QSharedDataPointer<FcRangeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FcRange &model);
    friend QDataStream &operator>>(QDataStream &ds, FcRange &model);
};

Q_DECLARE_METATYPE(FcRange)
Q_DECLARE_METATYPE(QList<FcRange>)

#endif // FCRANGE_H
