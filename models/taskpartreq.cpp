#include <TreeFrogModel>
#include "taskpartreq.h"
#include "taskpartreqobject.h"
#include "refreqpriority.h"
#include "refremovereason.h"
#include "qtyunit.h"
#include "refreqaction.h"
#include "eqppartno.h"
#include "eqpassmblbompos.h"
#include "eqpassmblbom.h"
#include "eqpassmbl.h"
#include "tasktask.h"

TaskPartReq::TaskPartReq()
    : TAbstractModel(), d(new TaskPartReqObject())
{
    d->task_part_req_id = 0;
    d->task_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
    d->assmbl_bom_pos_id = 0;
    d->part_no_id = 0;
    d->req_qt = 0;
    d->qty_unit_id = 0;
}

TaskPartReq::TaskPartReq(const TaskPartReq &other)
    : TAbstractModel(), d(new TaskPartReqObject(*other.d))
{ }

TaskPartReq::TaskPartReq(const TaskPartReqObject &object)
    : TAbstractModel(), d(new TaskPartReqObject(object))
{ }

TaskPartReq::~TaskPartReq()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskPartReqObject' is deleted.
}

int TaskPartReq::taskPartReqId() const
{
    return d->task_part_req_id;
}

int TaskPartReq::taskId() const
{
    return d->task_id;
}

void TaskPartReq::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskPartReq::assmblId() const
{
    return d->assmbl_id;
}

void TaskPartReq::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int TaskPartReq::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void TaskPartReq::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int TaskPartReq::assmblBomPosId() const
{
    return d->assmbl_bom_pos_id;
}

void TaskPartReq::setAssmblBomPosId(int assmblBomPosId)
{
    d->assmbl_bom_pos_id = assmblBomPosId;
}

int TaskPartReq::partNoId() const
{
    return d->part_no_id;
}

void TaskPartReq::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString TaskPartReq::reqActionCd() const
{
    return d->req_action_cd;
}

void TaskPartReq::setReqActionCd(const QString &reqActionCd)
{
    d->req_action_cd = reqActionCd;
}

int TaskPartReq::reqQt() const
{
    return d->req_qt;
}

void TaskPartReq::setReqQt(int reqQt)
{
    d->req_qt = reqQt;
}

QString TaskPartReq::reqNote() const
{
    return d->req_note;
}

void TaskPartReq::setReqNote(const QString &reqNote)
{
    d->req_note = reqNote;
}

int TaskPartReq::qtyUnitId() const
{
    return d->qty_unit_id;
}

void TaskPartReq::setQtyUnitId(int qtyUnitId)
{
    d->qty_unit_id = qtyUnitId;
}

bool TaskPartReq::removeBool() const
{
    return d->remove_bool;
}

void TaskPartReq::setRemoveBool(bool removeBool)
{
    d->remove_bool = removeBool;
}

QString TaskPartReq::removeReasonCd() const
{
    return d->remove_reason_cd;
}

void TaskPartReq::setRemoveReasonCd(const QString &removeReasonCd)
{
    d->remove_reason_cd = removeReasonCd;
}

bool TaskPartReq::installBool() const
{
    return d->install_bool;
}

void TaskPartReq::setInstallBool(bool installBool)
{
    d->install_bool = installBool;
}

QString TaskPartReq::reqPriorityCd() const
{
    return d->req_priority_cd;
}

void TaskPartReq::setReqPriorityCd(const QString &reqPriorityCd)
{
    d->req_priority_cd = reqPriorityCd;
}

QDateTime TaskPartReq::createdAt() const
{
    return d->created_at;
}

QString TaskPartReq::createdBy() const
{
    return d->created_by;
}

void TaskPartReq::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskPartReq::updatedAt() const
{
    return d->updated_at;
}

QString TaskPartReq::updatedBy() const
{
    return d->updated_by;
}

void TaskPartReq::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefReqPriority TaskPartReq::refReqPriorityByreqPriorityCd() const
{
 return RefReqPriority::get(d->req_priority_cd);
}

RefRemoveReason TaskPartReq::refRemoveReasonByremoveReasonCd() const
{
 return RefRemoveReason::get(d->remove_reason_cd);
}

QtyUnit TaskPartReq::qtyUnitByqtyUnitId() const
{
 return QtyUnit::get(d->qty_unit_id);
}

RefReqAction TaskPartReq::refReqActionByreqActionCd() const
{
 return RefReqAction::get(d->req_action_cd);
}

EqpPartNo TaskPartReq::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBomPos TaskPartReq::eqpAssmblBomPosByassmblBomPosId() const
{
 return EqpAssmblBomPos::get(d->assmbl_bom_pos_id);
}

EqpAssmblBom TaskPartReq::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmbl TaskPartReq::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

TaskTask TaskPartReq::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskPartReq &TaskPartReq::operator=(const TaskPartReq &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskPartReq TaskPartReq::create(int taskId, int assmblId, int assmblBomId, int assmblBomPosId, int partNoId, const QString &reqActionCd, int reqQt, const QString &reqNote, int qtyUnitId, bool removeBool, const QString &removeReasonCd, bool installBool, const QString &reqPriorityCd, const QString &createdBy, const QString &updatedBy)
{
    TaskPartReqObject obj;
    obj.task_id = taskId;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.assmbl_bom_pos_id = assmblBomPosId;
    obj.part_no_id = partNoId;
    obj.req_action_cd = reqActionCd;
    obj.req_qt = reqQt;
    obj.req_note = reqNote;
    obj.qty_unit_id = qtyUnitId;
    obj.remove_bool = removeBool;
    obj.remove_reason_cd = removeReasonCd;
    obj.install_bool = installBool;
    obj.req_priority_cd = reqPriorityCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskPartReq();
    }
    return TaskPartReq(obj);
}

TaskPartReq TaskPartReq::create(const QVariantMap &values)
{
    TaskPartReq model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskPartReq TaskPartReq::get(int taskPartReqId)
{
    TSqlORMapper<TaskPartReqObject> mapper;
    return TaskPartReq(mapper.findByPrimaryKey(taskPartReqId));
}

int TaskPartReq::count()
{
    TSqlORMapper<TaskPartReqObject> mapper;
    return mapper.findCount();
}

QList<TaskPartReq> TaskPartReq::getAll()
{
    return tfGetModelListByCriteria<TaskPartReq, TaskPartReqObject>();
}

TModelObject *TaskPartReq::modelData()
{
    return d.data();
}

const TModelObject *TaskPartReq::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskPartReq &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskPartReq &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskPartReq)
