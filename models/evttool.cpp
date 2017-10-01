#include <TreeFrogModel>
#include "evttool.h"
#include "evttoolobject.h"
#include "tasktoolreq.h"
#include "tasktask.h"
#include "invinv.h"
#include "eqppartno.h"
#include "eqpassmblbom.h"
#include "schedtool.h"
#include "evtevent.h"

EvtTool::EvtTool()
    : TAbstractModel(), d(new EvtToolObject())
{
    d->event_id = 0;
    d->sched_tool_id = 0;
    d->assmbl_bom_id = 0;
    d->part_no_id = 0;
    d->inv_no_id = 0;
    d->task_id = 0;
    d->task_tool_req_id = 0;
    d->sched_hr = 0;
    d->actual_hr = 0;
    d->tool_cost = 0;
}

EvtTool::EvtTool(const EvtTool &other)
    : TAbstractModel(), d(new EvtToolObject(*other.d))
{ }

EvtTool::EvtTool(const EvtToolObject &object)
    : TAbstractModel(), d(new EvtToolObject(object))
{ }

EvtTool::~EvtTool()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtToolObject' is deleted.
}

int EvtTool::eventId() const
{
    return d->event_id;
}

void EvtTool::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtTool::schedToolId() const
{
    return d->sched_tool_id;
}

void EvtTool::setSchedToolId(int schedToolId)
{
    d->sched_tool_id = schedToolId;
}

int EvtTool::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void EvtTool::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int EvtTool::partNoId() const
{
    return d->part_no_id;
}

void EvtTool::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int EvtTool::invNoId() const
{
    return d->inv_no_id;
}

void EvtTool::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int EvtTool::taskId() const
{
    return d->task_id;
}

void EvtTool::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int EvtTool::taskToolReqId() const
{
    return d->task_tool_req_id;
}

void EvtTool::setTaskToolReqId(int taskToolReqId)
{
    d->task_tool_req_id = taskToolReqId;
}

int EvtTool::schedHr() const
{
    return d->sched_hr;
}

void EvtTool::setSchedHr(int schedHr)
{
    d->sched_hr = schedHr;
}

int EvtTool::actualHr() const
{
    return d->actual_hr;
}

void EvtTool::setActualHr(int actualHr)
{
    d->actual_hr = actualHr;
}

double EvtTool::toolCost() const
{
    return d->tool_cost;
}

void EvtTool::setToolCost(double toolCost)
{
    d->tool_cost = toolCost;
}

QDateTime EvtTool::createdAt() const
{
    return d->created_at;
}

QString EvtTool::createdBy() const
{
    return d->created_by;
}

void EvtTool::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtTool::updatedAt() const
{
    return d->updated_at;
}

QString EvtTool::updatedBy() const
{
    return d->updated_by;
}

void EvtTool::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

TaskToolReq EvtTool::taskToolReqBytaskToolReqId() const
{
 return TaskToolReq::get(d->task_tool_req_id);
}

TaskTask EvtTool::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

InvInv EvtTool::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

EqpPartNo EvtTool::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBom EvtTool::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

SchedTool EvtTool::schedToolByschedToolId() const
{
 return SchedTool::get(d->sched_tool_id);
}

EvtEvent EvtTool::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtTool &EvtTool::operator=(const EvtTool &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtTool EvtTool::create(int eventId, int schedToolId, int assmblBomId, int partNoId, int invNoId, int taskId, int taskToolReqId, int schedHr, int actualHr, double toolCost, const QString &createdBy, const QString &updatedBy)
{
    EvtToolObject obj;
    obj.event_id = eventId;
    obj.sched_tool_id = schedToolId;
    obj.assmbl_bom_id = assmblBomId;
    obj.part_no_id = partNoId;
    obj.inv_no_id = invNoId;
    obj.task_id = taskId;
    obj.task_tool_req_id = taskToolReqId;
    obj.sched_hr = schedHr;
    obj.actual_hr = actualHr;
    obj.tool_cost = toolCost;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtTool();
    }
    return EvtTool(obj);
}

EvtTool EvtTool::create(const QVariantMap &values)
{
    EvtTool model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtTool EvtTool::get(int eventId, int schedToolId)
{
    TSqlORMapper<EvtToolObject> mapper;
    return EvtTool(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(schedToolId)));
}

int EvtTool::count()
{
    TSqlORMapper<EvtToolObject> mapper;
    return mapper.findCount();
}

QList<EvtTool> EvtTool::getAll()
{
    return tfGetModelListByCriteria<EvtTool, EvtToolObject>();
}

TModelObject *EvtTool::modelData()
{
    return d.data();
}

const TModelObject *EvtTool::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtTool &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtTool &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtTool)
