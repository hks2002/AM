#ifndef TASKSTEP_H
#define TASKSTEP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskStepObject;
class TaskTask;


class T_MODEL_EXPORT TaskStep : public TAbstractModel
{
public:
    TaskStep();
    TaskStep(const TaskStep &other);
    TaskStep(const TaskStepObject &object);
    ~TaskStep();

    int taskId() const;
    void setTaskId(int taskId);
    int stepOrd() const;
    void setStepOrd(int stepOrd);
    QString stepDesc() const;
    void setStepDesc(const QString &stepDesc);
    bool signBool() const;
    void setSignBool(bool signBool);
    bool inspBool() const;
    void setInspBool(bool inspBool);
    bool riiBool() const;
    void setRiiBool(bool riiBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskTask taskTaskBytaskId() const;
    TaskStep &operator=(const TaskStep &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskStep create(int taskId, int stepOrd, const QString &stepDesc, bool signBool, bool inspBool, bool riiBool, const QString &createdBy, const QString &updatedBy);
    static TaskStep create(const QVariantMap &values);
    static TaskStep get(int taskId, int stepOrd);
    static int count();
    static QList<TaskStep> getAll();

private:
    QSharedDataPointer<TaskStepObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskStep &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskStep &model);
};

Q_DECLARE_METATYPE(TaskStep)
Q_DECLARE_METATYPE(QList<TaskStep>)

#endif // TASKSTEP_H
