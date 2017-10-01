#ifndef EVTTOOL_H
#define EVTTOOL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class EvtToolObject;
class TaskToolReq;
class TaskTask;
class InvInv;
class EqpPartNo;
class EqpAssmblBom;
class SchedTool;
class EvtEvent;


class T_MODEL_EXPORT EvtTool : public TAbstractModel
{
public:
    EvtTool();
    EvtTool(const EvtTool &other);
    EvtTool(const EvtToolObject &object);
    ~EvtTool();

    int eventId() const;
    void setEventId(int eventId);
    int schedToolId() const;
    void setSchedToolId(int schedToolId);
    int assmblBomId() const;
    void setAssmblBomId(int assmblBomId);
    int partNoId() const;
    void setPartNoId(int partNoId);
    int invNoId() const;
    void setInvNoId(int invNoId);
    int taskId() const;
    void setTaskId(int taskId);
    int taskToolReqId() const;
    void setTaskToolReqId(int taskToolReqId);
    int schedHr() const;
    void setSchedHr(int schedHr);
    int actualHr() const;
    void setActualHr(int actualHr);
    double toolCost() const;
    void setToolCost(double toolCost);
    QDateTime createdAt() const;
    QString createdBy() const;
    void setCreatedBy(const QString &createdBy);
    QDateTime updatedAt() const;
    QString updatedBy() const;
    void setUpdatedBy(const QString &updatedBy);
    TaskToolReq taskToolReqBytaskToolReqId() const;
    TaskTask taskTaskBytaskId() const;
    InvInv invInvByinvNoId() const;
    EqpPartNo eqpPartNoBypartNoId() const;
    EqpAssmblBom eqpAssmblBomByassmblBomId() const;
    SchedTool schedToolByschedToolId() const;
    EvtEvent evtEventByeventId() const;
    EvtTool &operator=(const EvtTool &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static EvtTool create(int eventId, int schedToolId, int assmblBomId, int partNoId, int invNoId, int taskId, int taskToolReqId, int schedHr, int actualHr, double toolCost, const QString &createdBy, const QString &updatedBy);
    static EvtTool create(const QVariantMap &values);
    static EvtTool get(int eventId, int schedToolId);
    static int count();
    static QList<EvtTool> getAll();

private:
    QSharedDataPointer<EvtToolObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const EvtTool &model);
    friend QDataStream &operator>>(QDataStream &ds, EvtTool &model);
};

Q_DECLARE_METATYPE(EvtTool)
Q_DECLARE_METATYPE(QList<EvtTool>)

#endif // EVTTOOL_H
