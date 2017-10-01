#ifndef TASKTOOLREQ_H
#define TASKTOOLREQ_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskToolReqObject;
class EqpPartNo;
class EqpAssmblBom;
class EqpAssmbl;
class TaskTask;


class T_MODEL_EXPORT TaskToolReq : public TAbstractModel
{
public:
    TaskToolReq();
    TaskToolReq(const TaskToolReq &other);
    TaskToolReq(const TaskToolReqObject &object);
    ~TaskToolReq();

    int taskToolReqId() const;
    int taskId() const;
    void setTaskId(int taskId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString reqNote() const;
    void setReqNote(const QString &reqNote);
    int reqQt() const;
    void setReqQt(int reqQt);
    QString schedUsetime() const;
    void setSchedUsetime(const QString &schedUsetime);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    TaskTask taskTaskBytaskId() const;
    TaskToolReq &operator=(const TaskToolReq &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskToolReq create(int taskId, int assmblId, int assmblBomId, int partNoId, const QString &reqNote, int reqQt, const QString &schedUsetime, const QString &createdBy, const QString &updatedBy);
    static TaskToolReq create(const QVariantMap &values);
    static TaskToolReq get(int taskToolReqId);
    static int count();
    static QList<TaskToolReq> getAll();

private:
    QSharedDataPointer<TaskToolReqObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskToolReq &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskToolReq &model);
};

Q_DECLARE_METATYPE(TaskToolReq)
Q_DECLARE_METATYPE(QList<TaskToolReq>)

#endif // TASKTOOLREQ_H
