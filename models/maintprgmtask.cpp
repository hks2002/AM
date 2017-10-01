#include <TreeFrogModel>
#include "maintprgmtask.h"
#include "maintprgmtaskobject.h"
#include "userapp.h"
#include "tasktask.h"
#include "taskdefn.h"
#include "maintprgm.h"

MaintPrgmTask::MaintPrgmTask()
    : TAbstractModel(), d(new MaintPrgmTaskObject())
{
    d->maint_prgm_id = 0;
    d->task_defn_id = 0;
    d->task_id = 0;
    d->block_defn_id = 0;
    d->block_id = 0;
    d->issue_ord = 0;
    d->action_by = 0;
}

MaintPrgmTask::MaintPrgmTask(const MaintPrgmTask &other)
    : TAbstractModel(), d(new MaintPrgmTaskObject(*other.d))
{ }

MaintPrgmTask::MaintPrgmTask(const MaintPrgmTaskObject &object)
    : TAbstractModel(), d(new MaintPrgmTaskObject(object))
{ }

MaintPrgmTask::~MaintPrgmTask()
{
    // If the reference count becomes 0,
    // the shared data object 'MaintPrgmTaskObject' is deleted.
}

int MaintPrgmTask::maintPrgmId() const
{
    return d->maint_prgm_id;
}

void MaintPrgmTask::setMaintPrgmId(int maintPrgmId)
{
    d->maint_prgm_id = maintPrgmId;
}

int MaintPrgmTask::taskDefnId() const
{
    return d->task_defn_id;
}

void MaintPrgmTask::setTaskDefnId(int taskDefnId)
{
    d->task_defn_id = taskDefnId;
}

int MaintPrgmTask::taskId() const
{
    return d->task_id;
}

void MaintPrgmTask::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int MaintPrgmTask::blockDefnId() const
{
    return d->block_defn_id;
}

void MaintPrgmTask::setBlockDefnId(int blockDefnId)
{
    d->block_defn_id = blockDefnId;
}

int MaintPrgmTask::blockId() const
{
    return d->block_id;
}

void MaintPrgmTask::setBlockId(int blockId)
{
    d->block_id = blockId;
}

QString MaintPrgmTask::blockNote() const
{
    return d->block_note;
}

void MaintPrgmTask::setBlockNote(const QString &blockNote)
{
    d->block_note = blockNote;
}

int MaintPrgmTask::issueOrd() const
{
    return d->issue_ord;
}

void MaintPrgmTask::setIssueOrd(int issueOrd)
{
    d->issue_ord = issueOrd;
}

QString MaintPrgmTask::groupCd() const
{
    return d->group_cd;
}

void MaintPrgmTask::setGroupCd(const QString &groupCd)
{
    d->group_cd = groupCd;
}

bool MaintPrgmTask::unassignBool() const
{
    return d->unassign_bool;
}

void MaintPrgmTask::setUnassignBool(bool unassignBool)
{
    d->unassign_bool = unassignBool;
}

bool MaintPrgmTask::onConditionBool() const
{
    return d->on_condition_bool;
}

void MaintPrgmTask::setOnConditionBool(bool onConditionBool)
{
    d->on_condition_bool = onConditionBool;
}

QDateTime MaintPrgmTask::actionDt() const
{
    return d->action_dt;
}

void MaintPrgmTask::setActionDt(const QDateTime &actionDt)
{
    d->action_dt = actionDt;
}

QString MaintPrgmTask::actionNote() const
{
    return d->action_note;
}

void MaintPrgmTask::setActionNote(const QString &actionNote)
{
    d->action_note = actionNote;
}

int MaintPrgmTask::actionBy() const
{
    return d->action_by;
}

void MaintPrgmTask::setActionBy(int actionBy)
{
    d->action_by = actionBy;
}

QDateTime MaintPrgmTask::createdAt() const
{
    return d->created_at;
}

QString MaintPrgmTask::createdBy() const
{
    return d->created_by;
}

void MaintPrgmTask::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime MaintPrgmTask::updatedAt() const
{
    return d->updated_at;
}

QString MaintPrgmTask::updatedBy() const
{
    return d->updated_by;
}

void MaintPrgmTask::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp MaintPrgmTask::userAppByactionBy() const
{
 return UserApp::get(d->action_by);
}

TaskTask MaintPrgmTask::taskTaskByblockId() const
{
 return TaskTask::get(d->block_id);
}

TaskDefn MaintPrgmTask::taskDefnByblockDefnId() const
{
 return TaskDefn::get(d->block_defn_id);
}

MaintPrgm MaintPrgmTask::maintPrgmBymaintPrgmId() const
{
 return MaintPrgm::get(d->maint_prgm_id);
}

MaintPrgmTask &MaintPrgmTask::operator=(const MaintPrgmTask &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

MaintPrgmTask MaintPrgmTask::create(int maintPrgmId, int taskDefnId, int taskId, int blockDefnId, int blockId, const QString &blockNote, int issueOrd, const QString &groupCd, bool unassignBool, bool onConditionBool, const QDateTime &actionDt, const QString &actionNote, int actionBy, const QString &createdBy, const QString &updatedBy)
{
    MaintPrgmTaskObject obj;
    obj.maint_prgm_id = maintPrgmId;
    obj.task_defn_id = taskDefnId;
    obj.task_id = taskId;
    obj.block_defn_id = blockDefnId;
    obj.block_id = blockId;
    obj.block_note = blockNote;
    obj.issue_ord = issueOrd;
    obj.group_cd = groupCd;
    obj.unassign_bool = unassignBool;
    obj.on_condition_bool = onConditionBool;
    obj.action_dt = actionDt;
    obj.action_note = actionNote;
    obj.action_by = actionBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return MaintPrgmTask();
    }
    return MaintPrgmTask(obj);
}

MaintPrgmTask MaintPrgmTask::create(const QVariantMap &values)
{
    MaintPrgmTask model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MaintPrgmTask MaintPrgmTask::get(int maintPrgmId, int taskDefnId, int taskId, int blockDefnId, int blockId)
{
    TSqlORMapper<MaintPrgmTaskObject> mapper;
    return MaintPrgmTask(mapper.findByPrimaryKey(QVariantList()<<QVariant(maintPrgmId)<<QVariant(taskDefnId)<<QVariant(taskId)<<QVariant(blockDefnId)<<QVariant(blockId)));
}

int MaintPrgmTask::count()
{
    TSqlORMapper<MaintPrgmTaskObject> mapper;
    return mapper.findCount();
}

QList<MaintPrgmTask> MaintPrgmTask::getAll()
{
    return tfGetModelListByCriteria<MaintPrgmTask, MaintPrgmTaskObject>();
}

TModelObject *MaintPrgmTask::modelData()
{
    return d.data();
}

const TModelObject *MaintPrgmTask::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MaintPrgmTask &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MaintPrgmTask &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MaintPrgmTask)
