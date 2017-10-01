#ifndef TASKPARTREQ_H
#define TASKPARTREQ_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TaskPartReqObject;
class RefReqPriority;
class RefRemoveReason;
class QtyUnit;
class RefReqAction;
class EqpPartNo;
class EqpAssmblBomPos;
class EqpAssmblBom;
class EqpAssmbl;
class TaskTask;


class T_MODEL_EXPORT TaskPartReq : public TAbstractModel
{
public:
    TaskPartReq();
    TaskPartReq(const TaskPartReq &other);
    TaskPartReq(const TaskPartReqObject &object);
    ~TaskPartReq();

    int taskPartReqId() const;
    int taskId() const;
    void setTaskId(int taskId);
    int assmblId() const;
    void setAssmblId(int assmblId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int assmblBomPosId() const;
    void setAssmblBomPosId(int assmblBomPosId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    QString reqActionCd() const;
    void setReqActionCd(const QString &reqActionCd);
    int reqQt() const;
    void setReqQt(int reqQt);
    QString reqNote() const;
    void setReqNote(const QString &reqNote);
    int qtyUnitId() const;
    void setQtyUnitId(int qtyUnitId);
    bool removeBool() const;
    void setRemoveBool(bool removeBool);
    QString removeReasonCd() const;
    void setRemoveReasonCd(const QString &removeReasonCd);
    bool installBool() const;
    void setInstallBool(bool installBool);
    QString reqPriorityCd() const;
    void setReqPriorityCd(const QString &reqPriorityCd);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    RefReqPriority refReqPriorityByreqPriorityCd() const;
    RefRemoveReason refRemoveReasonByremoveReasonCd() const;
    QtyUnit qtyUnitByqtyUnitId() const;
    RefReqAction refReqActionByreqActionCd() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBomPos eqpAssmblBomPosByassmblBomPosId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    EqpAssmbl eqpAssmblByassmblId() const;
    TaskTask taskTaskBytaskId() const;
    TaskPartReq &operator=(const TaskPartReq &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TaskPartReq create(int taskId, int assmblId, int assmblBomId, int assmblBomPosId, int partNoId, const QString &reqActionCd, int reqQt, const QString &reqNote, int qtyUnitId, bool removeBool, const QString &removeReasonCd, bool installBool, const QString &reqPriorityCd, const QString &createdBy, const QString &updatedBy);
    static TaskPartReq create(const QVariantMap &values);
    static TaskPartReq get(int taskPartReqId);
    static int count();
    static QList<TaskPartReq> getAll();

private:
    QSharedDataPointer<TaskPartReqObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TaskPartReq &model);
    friend QDataStream &operator>>(QDataStream &ds, TaskPartReq &model);
};

Q_DECLARE_METATYPE(TaskPartReq)
Q_DECLARE_METATYPE(QList<TaskPartReq>)

#endif // TASKPARTREQ_H
