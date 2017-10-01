#ifndef TASKPANEL_H
#define TASKPANEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskPanelObject;
class EqpPanel;
class TaskTask;


class T_MODEL_EXPORT TaskPanel : public TAbstractModel
{
public:
    TaskPanel();
    TaskPanel(const TaskPanel &other);
    TaskPanel(const TaskPanelObject &object);
    ~TaskPanel();

    int taskId() const;
    void setTaskId(int taskId);
    int panelId() const;
    void setPanelId(int panelId);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPanel eqpPanelBypanelId() const;
    TaskTask taskTaskBytaskId() const;
    TaskPanel &operator=(const TaskPanel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskPanel create(int taskId, int panelId, const QString &createdBy, const QString &updatedBy);
    static TaskPanel create(const QVariantMap &values);
    static TaskPanel get(int taskId, int panelId);
    static int count();
    static QList<TaskPanel> getAll();

private:
    QSharedDataPointer<TaskPanelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskPanel &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskPanel &model);
};

Q_DECLARE_METATYPE(TaskPanel)
Q_DECLARE_METATYPE(QList<TaskPanel>)

#endif // TASKPANEL_H
