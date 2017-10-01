#ifndef TASKCOMPLIANCE_H
#define TASKCOMPLIANCE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskComplianceObject;
class TaskDefn;
class TaskTask;


class T_MODEL_EXPORT TaskCompliance : public TAbstractModel
{
public:
    TaskCompliance();
    TaskCompliance(const TaskCompliance &other);
    TaskCompliance(const TaskComplianceObject &object);
    ~TaskCompliance();

    int taskId() const;
    void setTaskId(int taskId);
    int complianceTask_id() const;
    void setComplianceTask_id(int complianceTask_id);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn taskDefnBycomplianceTask_id() const;
    TaskTask taskTaskBytaskId() const;
    TaskCompliance &operator=(const TaskCompliance &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskCompliance create(int taskId, int complianceTask_id, const QString &createdBy, const QString &updatedBy);
    static TaskCompliance create(const QVariantMap &values);
    static TaskCompliance get(int taskId, int complianceTask_id);
    static int count();
    static QList<TaskCompliance> getAll();

private:
    QSharedDataPointer<TaskComplianceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskCompliance &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskCompliance &model);
};

Q_DECLARE_METATYPE(TaskCompliance)
Q_DECLARE_METATYPE(QList<TaskCompliance>)

#endif // TASKCOMPLIANCE_H
