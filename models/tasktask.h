#ifndef TASKTASK_H
#define TASKTASK_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskTaskObject;
class TaskDefn;
class RefTaskDefStatus;
class TaskOriginator;
class RefTaskClass;
class TaskSubclass;
class RefFirstSchedFrom;
class RefReschedFrom;
class RefCreateWhen;
class RefCancelWhen;
class UserApp;


class T_MODEL_EXPORT TaskTask : public TAbstractModel
{
public:
    TaskTask();
    TaskTask(const TaskTask &other);
    TaskTask(const TaskTaskObject &object);
    ~TaskTask();

    int taskId() const;
    int taskDefnId() const;
    void setTaskDefnId(int taskDefnId);
    QString taskDefStatusCd() const;
    void setTaskDefStatusCd(const QString &taskDefStatusCd);
    QString taskCd() const;
    void setTaskCd(const QString &taskCd);
    QString taskName() const;
    void setTaskName(const QString &taskName);
    QString taskRefDesc() const;
    void setTaskRefDesc(const QString &taskRefDesc);
    QString taskDesc() const;
    void setTaskDesc(const QString &taskDesc);
    QString instructionDesc() const;
    void setInstructionDesc(const QString &instructionDesc);
    QString engineeringDesc() const;
    void setEngineeringDesc(const QString &engineeringDesc);
    int taskOriginatorId() const;
    void setTaskOriginatorId(int taskOriginatorId);
    QString taskClassCd() const;
    void setTaskClassCd(const QString &taskClassCd);
    int taskSubclassId() const;
    void setTaskSubclassId(int taskSubclassId);
    bool taskMustRemoveCd() const;
    void setTaskMustRemoveCd(bool taskMustRemoveCd);
    bool recurBool() const;
    void setRecurBool(bool recurBool);
    QString firstSchedFromCd() const;
    void setFirstSchedFromCd(const QString &firstSchedFromCd);
    QString reschedFromCd() const;
    void setReschedFromCd(const QString &reschedFromCd);
    QString createWhenCd() const;
    void setCreateWhenCd(const QString &createWhenCd);
    QString cancelWhenCd() const;
    void setCancelWhenCd(const QString &cancelWhenCd);
    bool schedFromLatestBool() const;
    void setSchedFromLatestBool(bool schedFromLatestBool);
    bool lastSchedDeadBool() const;
    void setLastSchedDeadBool(bool lastSchedDeadBool);
    QDate effectiveDt() const;
    void setEffectiveDt(const QDate &effectiveDt);
    QString estDurationQt() const;
    void setEstDurationQt(const QString &estDurationQt);
    QString taskApplEffDesc() const;
    void setTaskApplEffDesc(const QString &taskApplEffDesc);
    QString taskApplDesc() const;
    void setTaskApplDesc(const QString &taskApplDesc);
    QString taskApplSqlDesc() const;
    void setTaskApplSqlDesc(const QString &taskApplSqlDesc);
    int revisionOrd() const;
    void setRevisionOrd(int revisionOrd);
    QString revNote() const;
    void setRevNote(const QString &revNote);
    int preparedBy() const;
    void setPreparedBy(int preparedBy);
    QDateTime preparedDt() const;
    void setPreparedDt(const QDateTime &preparedDt);
    int reviewedBy() const;
    void setReviewedBy(int reviewedBy);
    QDateTime reviewedDt() const;
    void setReviewedDt(const QDateTime &reviewedDt);
    int approvedBy() const;
    void setApprovedBy(int approvedBy);
    QDateTime approvedDt() const;
    void setApprovedDt(const QDateTime &approvedDt);
    int activedBy() const;
    void setActivedBy(int activedBy);
    QDateTime activedDt() const;
    void setActivedDt(const QDateTime &activedDt);
    int lockedBy() const;
    void setLockedBy(int lockedBy);
    QDateTime lockedDt() const;
    void setLockedDt(const QDateTime &lockedDt);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskDefn taskDefnBytaskDefnId() const;
    RefTaskDefStatus refTaskDefStatusBytaskDefStatusCd() const;
    TaskOriginator taskOriginatorBytaskOriginatorId() const;
    RefTaskClass refTaskClassBytaskClassCd() const;
    TaskSubclass taskSubclassBytaskSubclassId() const;
    RefFirstSchedFrom refFirstSchedFromByfirstSchedFromCd() const;
    RefReschedFrom refReschedFromByreschedFromCd() const;
    RefCreateWhen refCreateWhenBycreateWhenCd() const;
    RefCancelWhen refCancelWhenBycancelWhenCd() const;
    UserApp userAppBypreparedBy() const;
    TaskTask &operator=(const TaskTask &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskTask create(int taskDefnId, const QString &taskDefStatusCd, const QString &taskCd, const QString &taskName, const QString &taskRefDesc, const QString &taskDesc, const QString &instructionDesc, const QString &engineeringDesc, int taskOriginatorId, const QString &taskClassCd, int taskSubclassId, bool taskMustRemoveCd, bool recurBool, const QString &firstSchedFromCd, const QString &reschedFromCd, const QString &createWhenCd, const QString &cancelWhenCd, bool schedFromLatestBool, bool lastSchedDeadBool, const QDate &effectiveDt, const QString &estDurationQt, const QString &taskApplEffDesc, const QString &taskApplDesc, const QString &taskApplSqlDesc, int revisionOrd, const QString &revNote, int preparedBy, const QDateTime &preparedDt, int reviewedBy, const QDateTime &reviewedDt, int approvedBy, const QDateTime &approvedDt, int activedBy, const QDateTime &activedDt, int lockedBy, const QDateTime &lockedDt, const QString &createdBy, const QString &updatedBy);
    static TaskTask create(const QVariantMap &values);
    static TaskTask get(int taskId);
    static int count();
    static QList<TaskTask> getAll();

private:
    QSharedDataPointer<TaskTaskObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskTask &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskTask &model);
};

Q_DECLARE_METATYPE(TaskTask)
Q_DECLARE_METATYPE(QList<TaskTask>)

#endif // TASKTASK_H
