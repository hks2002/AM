#include <TreeFrogModel>
#include "taskrefdoc.h"
#include "taskrefdocobject.h"
#include "userapp.h"
#include "refdocdisposition.h"
#include "manufact.h"
#include "regbody.h"
#include "refdocissueby.h"
#include "org.h"
#include "tasktask.h"

TaskRefDoc::TaskRefDoc()
    : TAbstractModel(), d(new TaskRefDocObject())
{
    d->task_id = 0;
    d->org_id = 0;
    d->reg_body_id = 0;
    d->manufact_id = 0;
    d->received_by = 0;
    d->disposition_by = 0;
}

TaskRefDoc::TaskRefDoc(const TaskRefDoc &other)
    : TAbstractModel(), d(new TaskRefDocObject(*other.d))
{ }

TaskRefDoc::TaskRefDoc(const TaskRefDocObject &object)
    : TAbstractModel(), d(new TaskRefDocObject(object))
{ }

TaskRefDoc::~TaskRefDoc()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskRefDocObject' is deleted.
}

int TaskRefDoc::taskId() const
{
    return d->task_id;
}

void TaskRefDoc::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskRefDoc::orgId() const
{
    return d->org_id;
}

void TaskRefDoc::setOrgId(int orgId)
{
    d->org_id = orgId;
}

QString TaskRefDoc::amendRefDesc() const
{
    return d->amend_ref_desc;
}

void TaskRefDoc::setAmendRefDesc(const QString &amendRefDesc)
{
    d->amend_ref_desc = amendRefDesc;
}

QString TaskRefDoc::docIssueByCd() const
{
    return d->doc_issue_by_cd;
}

void TaskRefDoc::setDocIssueByCd(const QString &docIssueByCd)
{
    d->doc_issue_by_cd = docIssueByCd;
}

int TaskRefDoc::regBodyId() const
{
    return d->reg_body_id;
}

void TaskRefDoc::setRegBodyId(int regBodyId)
{
    d->reg_body_id = regBodyId;
}

int TaskRefDoc::manufactId() const
{
    return d->manufact_id;
}

void TaskRefDoc::setManufactId(int manufactId)
{
    d->manufact_id = manufactId;
}

QDateTime TaskRefDoc::issueDt() const
{
    return d->issue_dt;
}

void TaskRefDoc::setIssueDt(const QDateTime &issueDt)
{
    d->issue_dt = issueDt;
}

QDateTime TaskRefDoc::receivedDt() const
{
    return d->received_dt;
}

void TaskRefDoc::setReceivedDt(const QDateTime &receivedDt)
{
    d->received_dt = receivedDt;
}

int TaskRefDoc::receivedBy() const
{
    return d->received_by;
}

void TaskRefDoc::setReceivedBy(int receivedBy)
{
    d->received_by = receivedBy;
}

QString TaskRefDoc::docDispositionCd() const
{
    return d->doc_disposition_cd;
}

void TaskRefDoc::setDocDispositionCd(const QString &docDispositionCd)
{
    d->doc_disposition_cd = docDispositionCd;
}

QDateTime TaskRefDoc::dispositionDt() const
{
    return d->disposition_dt;
}

void TaskRefDoc::setDispositionDt(const QDateTime &dispositionDt)
{
    d->disposition_dt = dispositionDt;
}

int TaskRefDoc::dispositionBy() const
{
    return d->disposition_by;
}

void TaskRefDoc::setDispositionBy(int dispositionBy)
{
    d->disposition_by = dispositionBy;
}

QString TaskRefDoc::dispositionDesc() const
{
    return d->disposition_desc;
}

void TaskRefDoc::setDispositionDesc(const QString &dispositionDesc)
{
    d->disposition_desc = dispositionDesc;
}

QDateTime TaskRefDoc::createdAt() const
{
    return d->created_at;
}

QString TaskRefDoc::createdBy() const
{
    return d->created_by;
}

void TaskRefDoc::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskRefDoc::updatedAt() const
{
    return d->updated_at;
}

QString TaskRefDoc::updatedBy() const
{
    return d->updated_by;
}

void TaskRefDoc::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp TaskRefDoc::userAppBydispositionBy() const
{
 return UserApp::get(d->disposition_by);
}

RefDocDisposition TaskRefDoc::refDocDispositionBydocDispositionCd() const
{
 return RefDocDisposition::get(d->doc_disposition_cd);
}

Manufact TaskRefDoc::manufactBymanufactId() const
{
 return Manufact::get(d->manufact_id);
}

RegBody TaskRefDoc::regBodyByregBodyId() const
{
 return RegBody::get(d->reg_body_id);
}

RefDocIssueBy TaskRefDoc::refDocIssueByBydocIssueByCd() const
{
 return RefDocIssueBy::get(d->doc_issue_by_cd);
}

Org TaskRefDoc::orgByorgId() const
{
 return Org::get(d->org_id);
}

TaskTask TaskRefDoc::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskRefDoc &TaskRefDoc::operator=(const TaskRefDoc &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskRefDoc TaskRefDoc::create(int taskId, int orgId, const QString &amendRefDesc, const QString &docIssueByCd, int regBodyId, int manufactId, const QDateTime &issueDt, const QDateTime &receivedDt, int receivedBy, const QString &docDispositionCd, const QDateTime &dispositionDt, int dispositionBy, const QString &dispositionDesc, const QString &createdBy, const QString &updatedBy)
{
    TaskRefDocObject obj;
    obj.task_id = taskId;
    obj.org_id = orgId;
    obj.amend_ref_desc = amendRefDesc;
    obj.doc_issue_by_cd = docIssueByCd;
    obj.reg_body_id = regBodyId;
    obj.manufact_id = manufactId;
    obj.issue_dt = issueDt;
    obj.received_dt = receivedDt;
    obj.received_by = receivedBy;
    obj.doc_disposition_cd = docDispositionCd;
    obj.disposition_dt = dispositionDt;
    obj.disposition_by = dispositionBy;
    obj.disposition_desc = dispositionDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskRefDoc();
    }
    return TaskRefDoc(obj);
}

TaskRefDoc TaskRefDoc::create(const QVariantMap &values)
{
    TaskRefDoc model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskRefDoc TaskRefDoc::get(int taskId)
{
    TSqlORMapper<TaskRefDocObject> mapper;
    return TaskRefDoc(mapper.findByPrimaryKey(taskId));
}

int TaskRefDoc::count()
{
    TSqlORMapper<TaskRefDocObject> mapper;
    return mapper.findCount();
}

QList<TaskRefDoc> TaskRefDoc::getAll()
{
    return tfGetModelListByCriteria<TaskRefDoc, TaskRefDocObject>();
}

TModelObject *TaskRefDoc::modelData()
{
    return d.data();
}

const TModelObject *TaskRefDoc::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskRefDoc &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskRefDoc &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskRefDoc)
