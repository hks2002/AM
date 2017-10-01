#ifndef TASKBLOCKREQMAP_H
#define TASKBLOCKREQMAP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskBlockReqMapObject;
class TaskDefn;
class TaskTask;


class T_MODEL_EXPORT TaskBlockReqMap : public TAbstractModel
{
public:
    TaskBlockReqMap();
    TaskBlockReqMap(const TaskBlockReqMap &other);
    TaskBlockReqMap(const TaskBlockReqMapObject &object);
    ~TaskBlockReqMap();

    int taskId() const;
    void setTaskId(int taskId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    int reqTaskOrder() const;
    void setReqTaskOrder(int reqTaskOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn taskDefnBytaskDefnId() const;
    TaskTask taskTaskBytaskId() const;
    TaskBlockReqMap &operator=(const TaskBlockReqMap &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskBlockReqMap create(int taskId, int taskDefnId, int reqTaskOrder, const QString &createdBy, const QString &updatedBy);
    static TaskBlockReqMap create(const QVariantMap &values);
    static TaskBlockReqMap get(int taskId, int taskDefnId);
    static int count();
    static QList<TaskBlockReqMap> getAll();

private:
    QSharedDataPointer<TaskBlockReqMapObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskBlockReqMap &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskBlockReqMap &model);
};

Q_DECLARE_METATYPE(TaskBlockReqMap)
Q_DECLARE_METATYPE(QList<TaskBlockReqMap>)

#endif // TASKBLOCKREQMAP_H
