#include <TreeFrogModel>
#include "schedstask.h"
#include "schedstaskobject.h"
#include "fncaccount.h"
#include "refreschedfrom.h"
#include "refcancelwhen.h"
#include "reffirstschedfrom.h"
#include "invinv.h"
#include "taskoriginator.h"
#include "tasksubclass.h"
#include "reftaskclass.h"
#include "eqppartno.h"
#include "tasktask.h"

SchedStask::SchedStask()
    : TAbstractModel(), d(new SchedStaskObject())
{
    d->sched_id = 0;
    d->h_sched_id = 0;
    d->task_id = 0;
    d->part_no_id = 0;
    d->task_subclass_id = 0;
    d->task_originator_id = 0;
    d->inv_no_id = 0;
    d->wo_commit_line_ord = 0;
    d->account_id = 0;
}

SchedStask::SchedStask(const SchedStask &other)
    : TAbstractModel(), d(new SchedStaskObject(*other.d))
{ }

SchedStask::SchedStask(const SchedStaskObject &object)
    : TAbstractModel(), d(new SchedStaskObject(object))
{ }

SchedStask::~SchedStask()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedStaskObject' is deleted.
}

int SchedStask::schedId() const
{
    return d->sched_id;
}

int SchedStask::hSchedId() const
{
    return d->h_sched_id;
}

void SchedStask::setHSchedId(int hSchedId)
{
    d->h_sched_id = hSchedId;
}

int SchedStask::taskId() const
{
    return d->task_id;
}

void SchedStask::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int SchedStask::partNoId() const
{
    return d->part_no_id;
}

void SchedStask::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString SchedStask::taskClassCd() const
{
    return d->task_class_cd;
}

void SchedStask::setTaskClassCd(const QString &taskClassCd)
{
    d->task_class_cd = taskClassCd;
}

int SchedStask::taskSubclassId() const
{
    return d->task_subclass_id;
}

void SchedStask::setTaskSubclassId(int taskSubclassId)
{
    d->task_subclass_id = taskSubclassId;
}

int SchedStask::taskOriginatorId() const
{
    return d->task_originator_id;
}

void SchedStask::setTaskOriginatorId(int taskOriginatorId)
{
    d->task_originator_id = taskOriginatorId;
}

QString SchedStask::taskRefDesc() const
{
    return d->task_ref_desc;
}

void SchedStask::setTaskRefDesc(const QString &taskRefDesc)
{
    d->task_ref_desc = taskRefDesc;
}

int SchedStask::invNoId() const
{
    return d->inv_no_id;
}

void SchedStask::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

QString SchedStask::taskName() const
{
    return d->task_name;
}

void SchedStask::setTaskName(const QString &taskName)
{
    d->task_name = taskName;
}

QString SchedStask::taskDesc() const
{
    return d->task_desc;
}

void SchedStask::setTaskDesc(const QString &taskDesc)
{
    d->task_desc = taskDesc;
}

QString SchedStask::instructionDesc() const
{
    return d->instruction_desc;
}

void SchedStask::setInstructionDesc(const QString &instructionDesc)
{
    d->instruction_desc = instructionDesc;
}

QString SchedStask::operationRestriction() const
{
    return d->operation_restriction;
}

void SchedStask::setOperationRestriction(const QString &operationRestriction)
{
    d->operation_restriction = operationRestriction;
}

QString SchedStask::engineeringDesc() const
{
    return d->engineering_desc;
}

void SchedStask::setEngineeringDesc(const QString &engineeringDesc)
{
    d->engineering_desc = engineeringDesc;
}

QString SchedStask::barcodeDesc() const
{
    return d->barcode_desc;
}

void SchedStask::setBarcodeDesc(const QString &barcodeDesc)
{
    d->barcode_desc = barcodeDesc;
}

QString SchedStask::estDurationQt() const
{
    return d->est_duration_qt;
}

void SchedStask::setEstDurationQt(const QString &estDurationQt)
{
    d->est_duration_qt = estDurationQt;
}

QString SchedStask::nrMultQt() const
{
    return d->nr_mult_qt;
}

void SchedStask::setNrMultQt(const QString &nrMultQt)
{
    d->nr_mult_qt = nrMultQt;
}

QString SchedStask::firstSchedFromCd() const
{
    return d->first_sched_from_cd;
}

void SchedStask::setFirstSchedFromCd(const QString &firstSchedFromCd)
{
    d->first_sched_from_cd = firstSchedFromCd;
}

QString SchedStask::cancelWhenCd() const
{
    return d->cancel_when_cd;
}

void SchedStask::setCancelWhenCd(const QString &cancelWhenCd)
{
    d->cancel_when_cd = cancelWhenCd;
}

QString SchedStask::reschedFromCd() const
{
    return d->resched_from_cd;
}

void SchedStask::setReschedFromCd(const QString &reschedFromCd)
{
    d->resched_from_cd = reschedFromCd;
}

QDateTime SchedStask::planByDt() const
{
    return d->plan_by_dt;
}

void SchedStask::setPlanByDt(const QDateTime &planByDt)
{
    d->plan_by_dt = planByDt;
}

QString SchedStask::warrantyNote() const
{
    return d->warranty_note;
}

void SchedStask::setWarrantyNote(const QString &warrantyNote)
{
    d->warranty_note = warrantyNote;
}

int SchedStask::woCommitLineOrd() const
{
    return d->wo_commit_line_ord;
}

void SchedStask::setWoCommitLineOrd(int woCommitLineOrd)
{
    d->wo_commit_line_ord = woCommitLineOrd;
}

int SchedStask::accountId() const
{
    return d->account_id;
}

void SchedStask::setAccountId(int accountId)
{
    d->account_id = accountId;
}

QDateTime SchedStask::createdAt() const
{
    return d->created_at;
}

QString SchedStask::createdBy() const
{
    return d->created_by;
}

void SchedStask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedStask::updatedAt() const
{
    return d->updated_at;
}

QString SchedStask::updatedBy() const
{
    return d->updated_by;
}

void SchedStask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FncAccount SchedStask::fncAccountByaccountId() const
{
 return FncAccount::get(d->account_id);
}

RefReschedFrom SchedStask::refReschedFromByreschedFromCd() const
{
 return RefReschedFrom::get(d->resched_from_cd);
}

RefCancelWhen SchedStask::refCancelWhenBycancelWhenCd() const
{
 return RefCancelWhen::get(d->cancel_when_cd);
}

RefFirstSchedFrom SchedStask::refFirstSchedFromByfirstSchedFromCd() const
{
 return RefFirstSchedFrom::get(d->first_sched_from_cd);
}

InvInv SchedStask::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

TaskOriginator SchedStask::taskOriginatorBytaskOriginatorId() const
{
 return TaskOriginator::get(d->task_originator_id);
}

TaskSubclass SchedStask::taskSubclassBytaskSubclassId() const
{
 return TaskSubclass::get(d->task_subclass_id);
}

RefTaskClass SchedStask::refTaskClassBytaskClassCd() const
{
 return RefTaskClass::get(d->task_class_cd);
}

EqpPartNo SchedStask::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

TaskTask SchedStask::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

SchedStask &SchedStask::operator=(const SchedStask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedStask SchedStask::create(int hSchedId, int taskId, int partNoId, const QString &taskClassCd, int taskSubclassId, int taskOriginatorId, const QString &taskRefDesc, int invNoId, const QString &taskName, const QString &taskDesc, const QString &instructionDesc, const QString &operationRestriction, const QString &engineeringDesc, const QString &barcodeDesc, const QString &estDurationQt, const QString &nrMultQt, const QString &firstSchedFromCd, const QString &cancelWhenCd, const QString &reschedFromCd, const QDateTime &planByDt, const QString &warrantyNote, int woCommitLineOrd, int accountId, const QString &createdBy, const QString &updatedBy)
{
    SchedStaskObject obj;
    obj.h_sched_id = hSchedId;
    obj.task_id = taskId;
    obj.part_no_id = partNoId;
    obj.task_class_cd = taskClassCd;
    obj.task_subclass_id = taskSubclassId;
    obj.task_originator_id = taskOriginatorId;
    obj.task_ref_desc = taskRefDesc;
    obj.inv_no_id = invNoId;
    obj.task_name = taskName;
    obj.task_desc = taskDesc;
    obj.instruction_desc = instructionDesc;
    obj.operation_restriction = operationRestriction;
    obj.engineering_desc = engineeringDesc;
    obj.barcode_desc = barcodeDesc;
    obj.est_duration_qt = estDurationQt;
    obj.nr_mult_qt = nrMultQt;
    obj.first_sched_from_cd = firstSchedFromCd;
    obj.cancel_when_cd = cancelWhenCd;
    obj.resched_from_cd = reschedFromCd;
    obj.plan_by_dt = planByDt;
    obj.warranty_note = warrantyNote;
    obj.wo_commit_line_ord = woCommitLineOrd;
    obj.account_id = accountId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedStask();
    }
    return SchedStask(obj);
}

SchedStask SchedStask::create(const QVariantMap &values)
{
    SchedStask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedStask SchedStask::get(int schedId)
{
    TSqlORMapper<SchedStaskObject> mapper;
    return SchedStask(mapper.findByPrimaryKey(schedId));
}

int SchedStask::count()
{
    TSqlORMapper<SchedStaskObject> mapper;
    return mapper.findCount();
}

QList<SchedStask> SchedStask::getAll()
{
    return tfGetModelListByCriteria<SchedStask, SchedStaskObject>();
}

TModelObject *SchedStask::modelData()
{
    return d.data();
}

const TModelObject *SchedStask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedStask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedStask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedStask)
