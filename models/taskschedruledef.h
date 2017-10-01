#ifndef TASKSCHEDRULEDEF_H
#define TASKSCHEDRULEDEF_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskSchedRuleDefObject;
class DataType;
class TaskTask;


class T_MODEL_EXPORT TaskSchedRuleDef : public TAbstractModel
{
public:
    TaskSchedRuleDef();
    TaskSchedRuleDef(const TaskSchedRuleDef &other);
    TaskSchedRuleDef(const TaskSchedRuleDefObject &object);
    ~TaskSchedRuleDef();

    int taskId() const;
    void setTaskId(int taskId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
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
    DataType dataTypeBydataTypeId() const;
    TaskTask taskTaskBytaskId() const;
    TaskSchedRuleDef &operator=(const TaskSchedRuleDef &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskSchedRuleDef create(int taskId, int dataTypeId, double initialQt, double intervalQt, double deviationQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy);
    static TaskSchedRuleDef create(const QVariantMap &values);
    static TaskSchedRuleDef get(int taskId, int dataTypeId);
    static int count();
    static QList<TaskSchedRuleDef> getAll();

private:
    QSharedDataPointer<TaskSchedRuleDefObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskSchedRuleDef &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskSchedRuleDef &model);
};

Q_DECLARE_METATYPE(TaskSchedRuleDef)
Q_DECLARE_METATYPE(QList<TaskSchedRuleDef>)

#endif // TASKSCHEDRULEDEF_H
