#ifndef TASKNREST_H
#define TASKNREST_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskNrEstObject;
class LabourSkill;
class TaskTask;


class T_MODEL_EXPORT TaskNrEst : public TAbstractModel
{
public:
    TaskNrEst();
    TaskNrEst(const TaskNrEst &other);
    TaskNrEst(const TaskNrEstObject &object);
    ~TaskNrEst();

    int taskId() const;
    void setTaskId(int taskId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    QString estEffort() const;
    void setEstEffort(const QString &estEffort);
    double estNrFactor() const;
    void setEstNrFactor(double estNrFactor);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    LabourSkill labourSkillBylabourSkillId() const;
    TaskTask taskTaskBytaskId() const;
    TaskNrEst &operator=(const TaskNrEst &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskNrEst create(int taskId, int labourSkillId, const QString &estEffort, double estNrFactor, const QString &createdBy, const QString &updatedBy);
    static TaskNrEst create(const QVariantMap &values);
    static TaskNrEst get(int taskId, int labourSkillId);
    static int count();
    static QList<TaskNrEst> getAll();

private:
    QSharedDataPointer<TaskNrEstObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskNrEst &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskNrEst &model);
};

Q_DECLARE_METATYPE(TaskNrEst)
Q_DECLARE_METATYPE(QList<TaskNrEst>)

#endif // TASKNREST_H
