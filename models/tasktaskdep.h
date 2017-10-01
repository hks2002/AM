#ifndef TASKTASKDEP_H
#define TASKTASKDEP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskTaskDepObject;
class RefTaskDepAction;
class TaskDefn;
class TaskTask;


class T_MODEL_EXPORT TaskTaskDep : public TAbstractModel
{
public:
    TaskTaskDep();
    TaskTaskDep(const TaskTaskDep &other);
    TaskTaskDep(const TaskTaskDepObject &object);
    ~TaskTaskDep();

    int taskId() const;
    void setTaskId(int taskId);
    int taskDepId() const;
    void setTaskDepId(int taskDepId);
    QString taskDepActionCd() const;
    void setTaskDepActionCd(const QString &taskDepActionCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefTaskDepAction refTaskDepActionBytaskDepActionCd() const;
    TaskDefn taskDefnBytaskDepId() const;
    TaskTask taskTaskBytaskId() const;
    TaskTaskDep &operator=(const TaskTaskDep &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskTaskDep create(int taskId, int taskDepId, const QString &taskDepActionCd, const QString &createdBy, const QString &updatedBy);
    static TaskTaskDep create(const QVariantMap &values);
    static TaskTaskDep get(int taskId, int taskDepId);
    static int count();
    static QList<TaskTaskDep> getAll();

private:
    QSharedDataPointer<TaskTaskDepObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskTaskDep &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskTaskDep &model);
};

Q_DECLARE_METATYPE(TaskTaskDep)
Q_DECLARE_METATYPE(QList<TaskTaskDep>)

#endif // TASKTASKDEP_H
