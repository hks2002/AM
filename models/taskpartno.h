#ifndef TASKPARTNO_H
#define TASKPARTNO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskPartNoObject;
class Manufact;
class EqpPartNo;
class TaskTask;


class T_MODEL_EXPORT TaskPartNo : public TAbstractModel
{
public:
    TaskPartNo();
    TaskPartNo(const TaskPartNo &other);
    TaskPartNo(const TaskPartNoObject &object);
    ~TaskPartNo();

    int taskId() const;
    void setTaskId(int taskId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int manufactId() const;
    void setManufactId(int manufactId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    Manufact manufactBymanufactId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    TaskTask taskTaskBytaskId() const;
    TaskPartNo &operator=(const TaskPartNo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskPartNo create(int taskId, int partNoId, int manufactId, const QString &createdBy, const QString &updatedBy);
    static TaskPartNo create(const QVariantMap &values);
    static TaskPartNo get(int taskId, int partNoId, int manufactId);
    static int count();
    static QList<TaskPartNo> getAll();

private:
    QSharedDataPointer<TaskPartNoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskPartNo &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskPartNo &model);
};

Q_DECLARE_METATYPE(TaskPartNo)
Q_DECLARE_METATYPE(QList<TaskPartNo>)

#endif // TASKPARTNO_H
