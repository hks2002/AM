#ifndef TASKPARTTRANSFORM_H
#define TASKPARTTRANSFORM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskPartTransformObject;
class EqpPartNo;
class TaskTask;


class T_MODEL_EXPORT TaskPartTransform : public TAbstractModel
{
public:
    TaskPartTransform();
    TaskPartTransform(const TaskPartTransform &other);
    TaskPartTransform(const TaskPartTransformObject &object);
    ~TaskPartTransform();

    int taskId() const;
    void setTaskId(int taskId);
    int oldPartNoId() const;
    void setOldPartNoId(int oldPartNoId);
    int newPartNoId() const;
    void setNewPartNoId(int newPartNoId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBynewPartNoId() const;
    TaskTask taskTaskBytaskId() const;
    TaskPartTransform &operator=(const TaskPartTransform &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskPartTransform create(int taskId, int oldPartNoId, int newPartNoId, const QString &createdBy, const QString &updatedBy);
    static TaskPartTransform create(const QVariantMap &values);
    static TaskPartTransform get(int taskId, int oldPartNoId, int newPartNoId);
    static int count();
    static QList<TaskPartTransform> getAll();

private:
    QSharedDataPointer<TaskPartTransformObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskPartTransform &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskPartTransform &model);
};

Q_DECLARE_METATYPE(TaskPartTransform)
Q_DECLARE_METATYPE(QList<TaskPartTransform>)

#endif // TASKPARTTRANSFORM_H
