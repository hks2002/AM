#ifndef TASKLABOURSUMMARY_H
#define TASKLABOURSUMMARY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskLabourSummaryObject;
class LabourSkill;
class SchedStask;
class TaskDefn;
class TaskTask;


class T_MODEL_EXPORT TaskLabourSummary : public TAbstractModel
{
public:
    TaskLabourSummary();
    TaskLabourSummary(const TaskLabourSummary &other);
    TaskLabourSummary(const TaskLabourSummaryObject &object);
    ~TaskLabourSummary();

    int taskId() const;
    void setTaskId(int taskId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    int schedId() const;
    void setSchedId(int schedId);
    int labourSkillId() const;
    void setLabourSkillId(int labourSkillId);
    double schedManHr() const;
    void setSchedManHr(double schedManHr);
    int schedManPwrCt() const;
    void setSchedManPwrCt(int schedManPwrCt);
    double actualTotalManHr() const;
    void setActualTotalManHr(double actualTotalManHr);
    int actualManPwrCt() const;
    void setActualManPwrCt(int actualManPwrCt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    LabourSkill labourSkillBylabourSkillId() const;
    SchedStask schedStaskByschedId() const;
    TaskDefn taskDefnBytaskDefnId() const;
    TaskTask taskTaskBytaskId() const;
    TaskLabourSummary &operator=(const TaskLabourSummary &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskLabourSummary create(int taskId, int taskDefnId, int schedId, int labourSkillId, double schedManHr, int schedManPwrCt, double actualTotalManHr, int actualManPwrCt, const QString &createdBy, const QString &updatedBy);
    static TaskLabourSummary create(const QVariantMap &values);
    static TaskLabourSummary get(int taskId, int taskDefnId, int schedId, int labourSkillId);
    static int count();
    static QList<TaskLabourSummary> getAll();

private:
    QSharedDataPointer<TaskLabourSummaryObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskLabourSummary &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskLabourSummary &model);
};

Q_DECLARE_METATYPE(TaskLabourSummary)
Q_DECLARE_METATYPE(QList<TaskLabourSummary>)

#endif // TASKLABOURSUMMARY_H
