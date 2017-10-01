#ifndef TASKFLAGS_H
#define TASKFLAGS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskFlagsObject;
class TaskTask;


class T_MODEL_EXPORT TaskFlags : public TAbstractModel
{
public:
    TaskFlags();
    TaskFlags(const TaskFlags &other);
    TaskFlags(const TaskFlagsObject &object);
    ~TaskFlags();

    int taskId() const;
    void setTaskId(int taskId);
    bool nsvBool() const;
    void setNsvBool(bool nsvBool);
    bool preventExeBool() const;
    void setPreventExeBool(bool preventExeBool);
    QDateTime preventExeReviewDt() const;
    void setPreventExeReviewDt(const QDateTime &preventExeReviewDt);
    bool reviewReceiptBool() const;
    void setReviewReceiptBool(bool reviewReceiptBool);
    bool riiReqBool() const;
    void setRiiReqBool(bool riiReqBool);
    bool routineBool() const;
    void setRoutineBool(bool routineBool);
    bool etopsBool() const;
    void setEtopsBool(bool etopsBool);
    bool rvsmBool() const;
    void setRvsmBool(bool rvsmBool);
    bool softDeadlineBool() const;
    void setSoftDeadlineBool(bool softDeadlineBool);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskTask taskTaskBytaskId() const;
    TaskFlags &operator=(const TaskFlags &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskFlags create(int taskId, bool nsvBool, bool preventExeBool, const QDateTime &preventExeReviewDt, bool reviewReceiptBool, bool riiReqBool, bool routineBool, bool etopsBool, bool rvsmBool, bool softDeadlineBool, const QString &createdBy, const QString &updatedBy);
    static TaskFlags create(const QVariantMap &values);
    static TaskFlags get(int taskId);
    static int count();
    static QList<TaskFlags> getAll();

private:
    QSharedDataPointer<TaskFlagsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskFlags &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskFlags &model);
};

Q_DECLARE_METATYPE(TaskFlags)
Q_DECLARE_METATYPE(QList<TaskFlags>)

#endif // TASKFLAGS_H
