#include <TreeFrogModel>
#include "maintprgmtasktempissuelog.h"
#include "maintprgmtasktempissuelogobject.h"
#include "userapp.h"
#include "tasktask.h"
#include "maintprgm.h"

MaintPrgmTaskTempIssueLog::MaintPrgmTaskTempIssueLog()
    : TAbstractModel(), d(new MaintPrgmTaskTempIssueLogObject())
{
    d->task_temp_issue_log_id = 0;
    d->maint_prgm_id = 0;
    d->task_id = 0;
    d->temp_issue_by = 0;
}

MaintPrgmTaskTempIssueLog::MaintPrgmTaskTempIssueLog(const MaintPrgmTaskTempIssueLog &other)
    : TAbstractModel(), d(new MaintPrgmTaskTempIssueLogObject(*other.d))
{ }

MaintPrgmTaskTempIssueLog::MaintPrgmTaskTempIssueLog(const MaintPrgmTaskTempIssueLogObject &object)
    : TAbstractModel(), d(new MaintPrgmTaskTempIssueLogObject(object))
{ }

MaintPrgmTaskTempIssueLog::~MaintPrgmTaskTempIssueLog()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmTaskTempIssueLogObject' is deleted.
}

int MaintPrgmTaskTempIssueLog::taskTempIssueLogId() const
{
    return d->task_temp_issue_log_id;
}

int MaintPrgmTaskTempIssueLog::maintPrgmId() const
{
    return d->maint_prgm_id;
}

void MaintPrgmTaskTempIssueLog::setMaintPrgmId(int maintPrgmId)
{
    d->maint_prgm_id = maintPrgmId;
}

int MaintPrgmTaskTempIssueLog::taskId() const
{
    return d->task_id;
}

void MaintPrgmTaskTempIssueLog::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int MaintPrgmTaskTempIssueLog::tempIssueBy() const
{
    return d->temp_issue_by;
}

void MaintPrgmTaskTempIssueLog::setTempIssueBy(int tempIssueBy)
{
    d->temp_issue_by = tempIssueBy;
}

QDateTime MaintPrgmTaskTempIssueLog::tempIssueDt() const
{
    return d->temp_issue_dt;
}

void MaintPrgmTaskTempIssueLog::setTempIssueDt(const QDateTime &tempIssueDt)
{
    d->temp_issue_dt = tempIssueDt;
}

QDateTime MaintPrgmTaskTempIssueLog::createdAt() const
{
    return d->created_at;
}

QString MaintPrgmTaskTempIssueLog::createdBy() const
{
    return d->created_by;
}

void MaintPrgmTaskTempIssueLog::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgmTaskTempIssueLog::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgmTaskTempIssueLog::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgmTaskTempIssueLog::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp MaintPrgmTaskTempIssueLog::userAppBytempIssueBy() const
{
 return UserApp::get(d->temp_issue_by);
}

TaskTask MaintPrgmTaskTempIssueLog::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

MaintPrgm MaintPrgmTaskTempIssueLog::maintPrgmBymaintPrgmId() const
{
 return MaintPrgm::get(d->maint_prgm_id);
}

MaintPrgmTaskTempIssueLog &MaintPrgmTaskTempIssueLog::operator=(const MaintPrgmTaskTempIssueLog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgmTaskTempIssueLog MaintPrgmTaskTempIssueLog::create(int maintPrgmId, int taskId, int tempIssueBy, const QDateTime &tempIssueDt, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmTaskTempIssueLogObject obj;
    obj.maint_prgm_id = maintPrgmId;
    obj.task_id = taskId;
    obj.temp_issue_by = tempIssueBy;
    obj.temp_issue_dt = tempIssueDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgmTaskTempIssueLog();
    }
    return MaintPrgmTaskTempIssueLog(obj);
}

MaintPrgmTaskTempIssueLog MaintPrgmTaskTempIssueLog::create(const QVariantMap &values)
{
    MaintPrgmTaskTempIssueLog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgmTaskTempIssueLog MaintPrgmTaskTempIssueLog::get(int taskTempIssueLogId)
{
    TSqlORMapper<MaintPrgmTaskTempIssueLogObject> mapper;
    return MaintPrgmTaskTempIssueLog(mapper.findByPrimaryKey(taskTempIssueLogId));
}

int MaintPrgmTaskTempIssueLog::count()
{
    TSqlORMapper<MaintPrgmTaskTempIssueLogObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgmTaskTempIssueLog> MaintPrgmTaskTempIssueLog::getAll()
{
    return tfGetModelListByCriteria<MaintPrgmTaskTempIssueLog, MaintPrgmTaskTempIssueLogObject>();
}

TModelObject *MaintPrgmTaskTempIssueLog::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgmTaskTempIssueLog::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgmTaskTempIssueLog &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgmTaskTempIssueLog &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgmTaskTempIssueLog)
