#ifndef LOCLABOURCAPACITY_H
#define LOCLABOURCAPACITY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LocLabourCapacityObject;
class LabourSkill;
class Loc;


class T_MODEL_EXPORT LocLabourCapacity : public TAbstractModel
{
public:
    LocLabourCapacity();
    LocLabourCapacity(const LocLabourCapacity &other);
    LocLabourCapacity(const LocLabourCapacityObject &object);
    ~LocLabourCapacity();

    int locId() const;
    void setLocId(int locId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    double hoursPerDayQt() const;
    void setHoursPerDayQt(double hoursPerDayQt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    LabourSkill labourSkillBylabourSkillId() const;
    Loc locBylocId() const;
    LocLabourCapacity &operator=(const LocLabourCapacity &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static LocLabourCapacity create(int locId, int labourSkillId, double hoursPerDayQt, const QString &createdBy, const QString &updatedBy);
    static LocLabourCapacity create(const QVariantMap &values);
    static LocLabourCapacity get(int locId, int labourSkillId);
    static int count();
    static QList<LocLabourCapacity> getAll();

private:
    QSharedDataPointer<LocLabourCapacityObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const LocLabourCapacity &model);
    friend QDataStream &operator>>(QDataStream &ds, LocLabourCapacity &model);
};

Q_DECLARE_METATYPE(LocLabourCapacity)
Q_DECLARE_METATYPE(QList<LocLabourCapacity>)

#endif // LOCLABOURCAPACITY_H
