#ifndef TASKSCHEDRULEAC_H
#define TASKSCHEDRULEAC_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskSchedRuleAcObject;
class InvInv;
class DataType;
class TaskTask;


class T_MODEL_EXPORT TaskSchedRuleAc : public TAbstractModel
{
public:
    TaskSchedRuleAc();
    TaskSchedRuleAc(const TaskSchedRuleAc &other);
    TaskSchedRuleAc(const TaskSchedRuleAcObject &object);
    ~TaskSchedRuleAc();

    int taskId() const;
    void setTaskId(int taskId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    double initialQt() const;
    void setInitialQt(double initialQt);
    double intervalQt() const;
    void setIntervalQt(double intervalQt);
    double deviationQt() const;
    void setDeviationQt(double deviationQt);
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
    InvInv invInvByinvNoId() const;
    DataType dataTypeBydataTypeId() const;
    TaskTask taskTaskBytaskId() const;
    TaskSchedRuleAc &operator=(const TaskSchedRuleAc &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskSchedRuleAc create(int taskId, int dataTypeId, int invNoId, double initialQt, double intervalQt, double deviationQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy);
    static TaskSchedRuleAc create(const QVariantMap &values);
    static TaskSchedRuleAc get(int taskId, int dataTypeId, int invNoId);
    static int count();
    static QList<TaskSchedRuleAc> getAll();

private:
    QSharedDataPointer<TaskSchedRuleAcObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskSchedRuleAc &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskSchedRuleAc &model);
};

Q_DECLARE_METATYPE(TaskSchedRuleAc)
Q_DECLARE_METATYPE(QList<TaskSchedRuleAc>)

#endif // TASKSCHEDRULEAC_H
