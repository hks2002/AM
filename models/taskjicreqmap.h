#ifndef TASKJICREQMAP_H
#define TASKJICREQMAP_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskJicReqMapObject;
class TaskDefn;
class TaskTask;


class T_MODEL_EXPORT TaskJicReqMap : public TAbstractModel
{
public:
    TaskJicReqMap();
    TaskJicReqMap(const TaskJicReqMap &other);
    TaskJicReqMap(const TaskJicReqMapObject &object);
    ~TaskJicReqMap();

    int taskId() const;
    void setTaskId(int taskId);
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    int jicTaskOrder() const;
    void setJicTaskOrder(int jicTaskOrder);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn taskDefnBytaskDefnId() const;
    TaskTask taskTaskBytaskId() const;
    TaskJicReqMap &operator=(const TaskJicReqMap &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskJicReqMap create(int taskId, int taskDefnId, int jicTaskOrder, const QString &createdBy, const QString &updatedBy);
    static TaskJicReqMap create(const QVariantMap &values);
    static TaskJicReqMap get(int taskId, int taskDefnId);
    static int count();
    static QList<TaskJicReqMap> getAll();

private:
    QSharedDataPointer<TaskJicReqMapObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskJicReqMap &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskJicReqMap &model);
};

Q_DECLARE_METATYPE(TaskJicReqMap)
Q_DECLARE_METATYPE(QList<TaskJicReqMap>)

#endif // TASKJICREQMAP_H
