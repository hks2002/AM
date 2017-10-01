#ifndef TASKFIGURE_H
#define TASKFIGURE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskFigureObject;
class TaskTask;


class T_MODEL_EXPORT TaskFigure : public TAbstractModel
{
public:
    TaskFigure();
    TaskFigure(const TaskFigure &other);
    TaskFigure(const TaskFigureObject &object);
    ~TaskFigure();

    int taskId() const;
    void setTaskId(int taskId);
    int figureOrd() const;
    void setFigureOrd(int figureOrd);
    QString figureDesc() const;
    void setFigureDesc(const QString &figureDesc);
    QString figureNote() const;
    void setFigureNote(const QString &figureNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskTask taskTaskBytaskId() const;
    TaskFigure &operator=(const TaskFigure &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskFigure create(int taskId, int figureOrd, const QString &figureDesc, const QString &figureNote, const QString &createdBy, const QString &updatedBy);
    static TaskFigure create(const QVariantMap &values);
    static TaskFigure get(int taskId, int figureOrd);
    static int count();
    static QList<TaskFigure> getAll();

private:
    QSharedDataPointer<TaskFigureObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskFigure &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskFigure &model);
};

Q_DECLARE_METATYPE(TaskFigure)
Q_DECLARE_METATYPE(QList<TaskFigure>)

#endif // TASKFIGURE_H
