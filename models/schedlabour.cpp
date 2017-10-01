#include <TreeFrogModel>
#include "schedlabour.h"
#include "schedlabourobject.h"
#include "reflabourstage.h"
#include "labourskill.h"
#include "schedstask.h"

SchedLabour::SchedLabour()
    : TAbstractModel(), d(new SchedLabourObject())
{
    d->sched_labour_id = 0;
    d->sched_id = 0;
    d->labour_skill_id = 0;
    d->labour_ord = 0;
}

SchedLabour::SchedLabour(const SchedLabour &other)
    : TAbstractModel(), d(new SchedLabourObject(*other.d))
{ }

SchedLabour::SchedLabour(const SchedLabourObject &object)
    : TAbstractModel(), d(new SchedLabourObject(object))
{ }

SchedLabour::~SchedLabour()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedLabourObject' is deleted.
}

int SchedLabour::schedLabourId() const
{
    return d->sched_labour_id;
}

int SchedLabour::schedId() const
{
    return d->sched_id;
}

void SchedLabour::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedLabour::labourSkillId() const
{
    return d->labour_skill_id;
}

void SchedLabour::setLabourSkillId(int labourSkillId)
{
    d->labour_skill_id = labourSkillId;
}

int SchedLabour::labourOrd() const
{
    return d->labour_ord;
}

void SchedLabour::setLabourOrd(int labourOrd)
{
    d->labour_ord = labourOrd;
}

QString SchedLabour::labourStageCd() const
{
    return d->labour_stage_cd;
}

void SchedLabour::setLabourStageCd(const QString &labourStageCd)
{
    d->labour_stage_cd = labourStageCd;
}

bool SchedLabour::workPerfBool() const
{
    return d->work_perf_bool;
}

void SchedLabour::setWorkPerfBool(bool workPerfBool)
{
    d->work_perf_bool = workPerfBool;
}

bool SchedLabour::inspBool() const
{
    return d->insp_bool;
}

void SchedLabour::setInspBool(bool inspBool)
{
    d->insp_bool = inspBool;
}

bool SchedLabour::riiBool() const
{
    return d->rii_bool;
}

void SchedLabour::setRiiBool(bool riiBool)
{
    d->rii_bool = riiBool;
}

QString SchedLabour::note() const
{
    return d->note;
}

void SchedLabour::setNote(const QString &note)
{
    d->note = note;
}

QDateTime SchedLabour::createdAt() const
{
    return d->created_at;
}

QString SchedLabour::createdBy() const
{
    return d->created_by;
}

void SchedLabour::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedLabour::updatedAt() const
{
    return d->updated_at;
}

QString SchedLabour::updatedBy() const
{
    return d->updated_by;
}

void SchedLabour::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLabourStage SchedLabour::refLabourStageBylabourStageCd() const
{
 return RefLabourStage::get(d->labour_stage_cd);
}

LabourSkill SchedLabour::labourSkillBylabourSkillId() const
{
 return LabourSkill::get(d->labour_skill_id);
}

SchedStask SchedLabour::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedLabour &SchedLabour::operator=(const SchedLabour &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedLabour SchedLabour::create(int schedId, int labourSkillId, int labourOrd, const QString &labourStageCd, bool workPerfBool, bool inspBool, bool riiBool, const QString &note, const QString &createdBy, const QString &updatedBy)
{
    SchedLabourObject obj;
    obj.sched_id = schedId;
    obj.labour_skill_id = labourSkillId;
    obj.labour_ord = labourOrd;
    obj.labour_stage_cd = labourStageCd;
    obj.work_perf_bool = workPerfBool;
    obj.insp_bool = inspBool;
    obj.rii_bool = riiBool;
    obj.note = note;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedLabour();
    }
    return SchedLabour(obj);
}

SchedLabour SchedLabour::create(const QVariantMap &values)
{
    SchedLabour model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedLabour SchedLabour::get(int schedLabourId)
{
    TSqlORMapper<SchedLabourObject> mapper;
    return SchedLabour(mapper.findByPrimaryKey(schedLabourId));
}

int SchedLabour::count()
{
    TSqlORMapper<SchedLabourObject> mapper;
    return mapper.findCount();
}

QList<SchedLabour> SchedLabour::getAll()
{
    return tfGetModelListByCriteria<SchedLabour, SchedLabourObject>();
}

TModelObject *SchedLabour::modelData()
{
    return d.data();
}

const TModelObject *SchedLabour::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedLabour &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedLabour &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedLabour)
