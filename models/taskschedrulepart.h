#ifndef TASKSCHEDRULEPART_H
#define TASKSCHEDRULEPART_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskSchedRulePartObject;
class EqpPartNo;
class DataType;
class TaskTask;


class T_MODEL_EXPORT TaskSchedRulePart : public TAbstractModel
{
public:
    TaskSchedRulePart();
    TaskSchedRulePart(const TaskSchedRulePart &other);
    TaskSchedRulePart(const TaskSchedRulePartObject &object);
    ~TaskSchedRulePart();

    int taskId() const;
    void setTaskId(int taskId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    double deviationQt() const;
    void setDeviationQt(double deviationQt);
    double initialQt() const;
    void setInitialQt(double initialQt);
    double intervalQt() const;
    void setIntervalQt(double intervalQt);
    double notifyQt() const;
    void setNotifyQt(double notifyQt);
    double prefixedQt() const;
    void setPrefixedQt(double prefixedQt);
    double postfixedQt() const;
    void setPostfixedQt(double postfixedQt);
    double minPlanQt() const;
    void setMinPlanQt(double minPlanQt);
    bool postfixedMandBool() const;
    void setPostfixedMandBool(bool postfixedMandBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    DataType dataTypeBydataTypeId() const;
    TaskTask taskTaskBytaskId() const;
    TaskSchedRulePart &operator=(const TaskSchedRulePart &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskSchedRulePart create(int taskId, int dataTypeId, int partNoId, double deviationQt, double initialQt, double intervalQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy);
    static TaskSchedRulePart create(const QVariantMap &values);
    static TaskSchedRulePart get(int taskId, int dataTypeId, int partNoId);
    static int count();
    static QList<TaskSchedRulePart> getAll();

private:
    QSharedDataPointer<TaskSchedRulePartObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskSchedRulePart &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskSchedRulePart &model);
};

Q_DECLARE_METATYPE(TaskSchedRulePart)
Q_DECLARE_METATYPE(QList<TaskSchedRulePart>)

#endif // TASKSCHEDRULEPART_H
