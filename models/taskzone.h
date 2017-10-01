#ifndef TASKZONE_H
#define TASKZONE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskZoneObject;
class EqpZone;
class TaskTask;


class T_MODEL_EXPORT TaskZone : public TAbstractModel
{
public:
    TaskZone();
    TaskZone(const TaskZone &other);
    TaskZone(const TaskZoneObject &object);
    ~TaskZone();

    int taskId() const;
    void setTaskId(int taskId);
    int zoneId() const;
    void setZoneId(int zoneId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpZone eqpZoneByzoneId() const;
    TaskTask taskTaskBytaskId() const;
    TaskZone &operator=(const TaskZone &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskZone create(int taskId, int zoneId, const QString &createdBy, const QString &updatedBy);
    static TaskZone create(const QVariantMap &values);
    static TaskZone get(int taskId, int zoneId);
    static int count();
    static QList<TaskZone> getAll();

private:
    QSharedDataPointer<TaskZoneObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskZone &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskZone &model);
};

Q_DECLARE_METATYPE(TaskZone)
Q_DECLARE_METATYPE(QList<TaskZone>)

#endif // TASKZONE_H
