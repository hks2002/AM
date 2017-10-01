#ifndef TASKSCHEDRULEMESUR_H
#define TASKSCHEDRULEMESUR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskSchedRuleMesurObject;
class MesurUnit;
class DataType;
class TaskTask;


class T_MODEL_EXPORT TaskSchedRuleMesur : public TAbstractModel
{
public:
    TaskSchedRuleMesur();
    TaskSchedRuleMesur(const TaskSchedRuleMesur &other);
    TaskSchedRuleMesur(const TaskSchedRuleMesurObject &object);
    ~TaskSchedRuleMesur();

    int taskId() const;
    void setTaskId(int taskId);
    int dataTypeId() const;
    void setDataTypeId(int dataTypeId);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    int mesurFormQt() const;
    void setMesurFormQt(int mesurFormQt);
    int mesurToQt() const;
    void setMesurToQt(int mesurToQt);
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
    MesurUnit mesurUnitBymesurUnitId() const;
    DataType dataTypeBydataTypeId() const;
    TaskTask taskTaskBytaskId() const;
    TaskSchedRuleMesur &operator=(const TaskSchedRuleMesur &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskSchedRuleMesur create(int taskId, int dataTypeId, int mesurUnitId, int mesurFormQt, int mesurToQt, double deviationQt, double initialQt, double intervalQt, double notifyQt, double prefixedQt, double postfixedQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy);
    static TaskSchedRuleMesur create(const QVariantMap &values);
    static TaskSchedRuleMesur get(int taskId, int dataTypeId, int mesurUnitId);
    static int count();
    static QList<TaskSchedRuleMesur> getAll();

private:
    QSharedDataPointer<TaskSchedRuleMesurObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskSchedRuleMesur &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskSchedRuleMesur &model);
};

Q_DECLARE_METATYPE(TaskSchedRuleMesur)
Q_DECLARE_METATYPE(QList<TaskSchedRuleMesur>)

#endif // TASKSCHEDRULEMESUR_H
