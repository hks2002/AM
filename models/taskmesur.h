#ifndef TASKMESUR_H
#define TASKMESUR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskMesurObject;
class MesurUnit;
class TaskTask;


class T_MODEL_EXPORT TaskMesur : public TAbstractModel
{
public:
    TaskMesur();
    TaskMesur(const TaskMesur &other);
    TaskMesur(const TaskMesurObject &object);
    ~TaskMesur();

    int taskId() const;
    void setTaskId(int taskId);
    int mesurUnitId() const;
    void setMesurUnitId(int mesurUnitId);
    int mesurOrd() const;
    void setMesurOrd(int mesurOrd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    MesurUnit mesurUnitBymesurUnitId() const;
    TaskTask taskTaskBytaskId() const;
    TaskMesur &operator=(const TaskMesur &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskMesur create(int taskId, int mesurUnitId, int mesurOrd, const QString &createdBy, const QString &updatedBy);
    static TaskMesur create(const QVariantMap &values);
    static TaskMesur get(int taskId, int mesurUnitId);
    static int count();
    static QList<TaskMesur> getAll();

private:
    QSharedDataPointer<TaskMesurObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskMesur &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskMesur &model);
};

Q_DECLARE_METATYPE(TaskMesur)
Q_DECLARE_METATYPE(QList<TaskMesur>)

#endif // TASKMESUR_H
