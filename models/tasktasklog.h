#ifndef TASKTASKLOG_H
#define TASKTASKLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskTaskLogObject;
class RefLogAction;
class TaskTask;


class T_MODEL_EXPORT TaskTaskLog : public TAbstractModel
{
public:
    TaskTaskLog();
    TaskTaskLog(const TaskTaskLog &other);
    TaskTaskLog(const TaskTaskLogObject &object);
    ~TaskTaskLog();

    int taskTaskLogId() const;
    int taskId() const;
    void setTaskId(int taskId);
    QString logActionCd() const;
    void setLogActionCd(const QString &logActionCd);
    QDateTime logDt() const;
    void setLogDt(const QDateTime &logDt);
    QString userNote() const;
    void setUserNote(const QString &userNote);
    QString systemNote() const;
    void setSystemNote(const QString &systemNote);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefLogAction refLogActionBylogActionCd() const;
    TaskTask taskTaskBytaskId() const;
    TaskTaskLog &operator=(const TaskTaskLog &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskTaskLog create(int taskId, const QString &logActionCd, const QDateTime &logDt, const QString &userNote, const QString &systemNote, const QString &createdBy, const QString &updatedBy);
    static TaskTaskLog create(const QVariantMap &values);
    static TaskTaskLog get(int taskTaskLogId);
    static int count();
    static QList<TaskTaskLog> getAll();

private:
    QSharedDataPointer<TaskTaskLogObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskTaskLog &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskTaskLog &model);
};

Q_DECLARE_METATYPE(TaskTaskLog)
Q_DECLARE_METATYPE(QList<TaskTaskLog>)

#endif // TASKTASKLOG_H
