#ifndef TASKIMPACT_H
#define TASKIMPACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskImpactObject;
class RefMesurType;
class MesurUnit;
class TaskTask;


class T_MODEL_EXPORT TaskImpact : public TAbstractModel
{
public:
    TaskImpact();
    TaskImpact(const TaskImpact &other);
    TaskImpact(const TaskImpactObject &object);
    ~TaskImpact();

    int taskId() const;
    void setTaskId(int taskId);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    QString mesurTypeCd() const;
    void setMesurTypeCd(const QString &mesurTypeCd);
    double mesurQt() const;
    void setMesurQt(double mesurQt);
    QString impactDesc() const;
    void setImpactDesc(const QString &impactDesc);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefMesurType refMesurTypeBymesurTypeCd() const;
    MesurUnit mesurUnitBymesurUnitId() const;
    TaskTask taskTaskBytaskId() const;
    TaskImpact &operator=(const TaskImpact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskImpact create(int taskId, int mesurUnitId, const QString &mesurTypeCd, double mesurQt, const QString &impactDesc, const QString &createdBy, const QString &updatedBy);
    static TaskImpact create(const QVariantMap &values);
    static TaskImpact get(int taskId, int mesurUnitId, const QString &mesurTypeCd);
    static int count();
    static QList<TaskImpact> getAll();

private:
    QSharedDataPointer<TaskImpactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskImpact &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskImpact &model);
};

Q_DECLARE_METATYPE(TaskImpact)
Q_DECLARE_METATYPE(QList<TaskImpact>)

#endif // TASKIMPACT_H
