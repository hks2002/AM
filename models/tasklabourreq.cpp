#include <TreeFrogModel>
#include "tasklabourreq.h"
#include "tasklabourreqobject.h"
#include "license.h"
#include "labourskill.h"
#include "tasktask.h"

TaskLabourReq::TaskLabourReq()
    : TAbstractModel(), d(new TaskLabourReqObject())
{
    d->task_id = 0;
    d->labour_skill_id = 0;
    d->man_ct = 0;
    d->insp_hour = 0;
    d->insp_license = 0;
    d->rii_hour = 0;
    d->rii_license = 0;
}

TaskLabourReq::TaskLabourReq(const TaskLabourReq &other)
    : TAbstractModel(), d(new TaskLabourReqObject(*other.d))
{ }

TaskLabourReq::TaskLabourReq(const TaskLabourReqObject &object)
    : TAbstractModel(), d(new TaskLabourReqObject(object))
{ }

TaskLabourReq::~TaskLabourReq()
{
    // If the reference count becomes 0,
    // the shared data object 'TaskLabourReqObject' is deleted.
}

int TaskLabourReq::taskId() const
{
    return d->task_id;
}

void TaskLabourReq::setTaskId(int taskId)
{
    d->task_id = taskId;
}

int TaskLabourReq::labourSkillId() const
{
    return d->labour_skill_id;
}

void TaskLabourReq::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

QString TaskLabourReq::manHour() const
{
    return d->man_hour;
}

void TaskLabourReq::setManHour(const QString &manHour)
{
    d->man_hour = manHour;
}

int TaskLabourReq::manCt() const
{
    return d->man_ct;
}

void TaskLabourReq::setManCt(int manCt)
{
    d->man_ct = manCt;
}

bool TaskLabourReq::inspBool() const
{
    return d->insp_bool;
}

void TaskLabourReq::setInspBool(bool inspBool)
{
    d->insp_bool = inspBool;
}

double TaskLabourReq::inspHour() const
{
    return d->insp_hour;
}

void TaskLabourReq::setInspHour(double inspHour)
{
    d->insp_hour = inspHour;
}

int TaskLabourReq::inspLicense() const
{
    return d->insp_license;
}

void TaskLabourReq::setInspLicense(int inspLicense)
{
    d->insp_license = inspLicense;
}

bool TaskLabourReq::riiBool() const
{
    return d->rii_bool;
}

void TaskLabourReq::setRiiBool(bool riiBool)
{
    d->rii_bool = riiBool;
}

double TaskLabourReq::riiHour() const
{
    return d->rii_hour;
}

void TaskLabourReq::setRiiHour(double riiHour)
{
    d->rii_hour = riiHour;
}

int TaskLabourReq::riiLicense() const
{
    return d->rii_license;
}

void TaskLabourReq::setRiiLicense(int riiLicense)
{
    d->rii_license = riiLicense;
}

QDateTime TaskLabourReq::createdAt() const
{
    return d->created_at;
}

QString TaskLabourReq::createdBy() const
{
    return d->created_by;
}

void TaskLabourReq::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime TaskLabourReq::updatedAt() const
{
    return d->updated_at;
}

QString TaskLabourReq::updatedBy() const
{
    return d->updated_by;
}

void TaskLabourReq::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

License TaskLabourReq::licenseByriiLicense() const
{
 return License::get(d->rii_license);
}

LabourSkill TaskLabourReq::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

TaskTask TaskLabourReq::taskTaskBytaskId() const
{
 return TaskTask::get(d->task_id);
}

TaskLabourReq &TaskLabourReq::operator=(const TaskLabourReq &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TaskLabourReq TaskLabourReq::create(int taskId, int labourSkillId, const QString &manHour, int manCt, bool inspBool, double inspHour, int inspLicense, bool riiBool, double riiHour, int riiLicense, const QString &createdBy, const QString &updatedBy)
{
    TaskLabourReqObject obj;
    obj.task_id = taskId;
    obj.labour_skill_id = labourSkillId;
    obj.man_hour = manHour;
    obj.man_ct = manCt;
    obj.insp_bool = inspBool;
    obj.insp_hour = inspHour;
    obj.insp_license = inspLicense;
    obj.rii_bool = riiBool;
    obj.rii_hour = riiHour;
    obj.rii_license = riiLicense;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return TaskLabourReq();
    }
    return TaskLabourReq(obj);
}

TaskLabourReq TaskLabourReq::create(const QVariantMap &values)
{
    TaskLabourReq model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TaskLabourReq TaskLabourReq::get(int taskId, int labourSkillId)
{
    TSqlORMapper<TaskLabourReqObject> mapper;
    return TaskLabourReq(mapper.findByPrimaryKey(QVariantList()<<QVariant(taskId)<<QVariant(labourSkillId)));
}

int TaskLabourReq::count()
{
    TSqlORMapper<TaskLabourReqObject> mapper;
    return mapper.findCount();
}

QList<TaskLabourReq> TaskLabourReq::getAll()
{
    return tfGetModelListByCriteria<TaskLabourReq, TaskLabourReqObject>();
}

TModelObject *TaskLabourReq::modelData()
{
    return d.data();
}

const TModelObject *TaskLabourReq::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TaskLabourReq &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TaskLabourReq &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TaskLabourReq)
