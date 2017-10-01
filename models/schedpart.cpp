#include <TreeFrogModel>
#include "schedpart.h"
#include "schedpartobject.h"
#include "refpartstatus.h"
#include "refreqaction.h"
#include "eqpassmblbompos.h"
#include "eqppartno.h"
#include "eqpassmblbom.h"
#include "eqpassmbl.h"
#include "schedstask.h"

SchedPart::SchedPart()
    : TAbstractModel(), d(new SchedPartObject())
{
    d->sched_part_id = 0;
    d->sched_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
    d->part_no_id = 0;
    d->assmbl_bom_pos_id = 0;
    d->sched_qt = 0;
}

SchedPart::SchedPart(const SchedPart &other)
    : TAbstractModel(), d(new SchedPartObject(*other.d))
{ }

SchedPart::SchedPart(const SchedPartObject &object)
    : TAbstractModel(), d(new SchedPartObject(object))
{ }

SchedPart::~SchedPart()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedPartObject' is deleted.
}

int SchedPart::schedPartId() const
{
    return d->sched_part_id;
}

int SchedPart::schedId() const
{
    return d->sched_id;
}

void SchedPart::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedPart::assmblId() const
{
    return d->assmbl_id;
}

void SchedPart::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int SchedPart::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void SchedPart::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int SchedPart::partNoId() const
{
    return d->part_no_id;
}

void SchedPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

int SchedPart::assmblBomPosId() const
{
    return d->assmbl_bom_pos_id;
}

void SchedPart::setAssmblBomPosId(int assmblBomPosId)
{
    d->assmbl_bom_pos_id = assmblBomPosId;
}

QString SchedPart::partNote() const
{
    return d->part_note;
}

void SchedPart::setPartNote(const QString &partNote)
{
    d->part_note = partNote;
}

int SchedPart::schedQt() const
{
    return d->sched_qt;
}

void SchedPart::setSchedQt(int schedQt)
{
    d->sched_qt = schedQt;
}

QString SchedPart::reqActionCd() const
{
    return d->req_action_cd;
}

void SchedPart::setReqActionCd(const QString &reqActionCd)
{
    d->req_action_cd = reqActionCd;
}

QString SchedPart::schedPartStatusCd() const
{
    return d->sched_part_status_cd;
}

void SchedPart::setSchedPartStatusCd(const QString &schedPartStatusCd)
{
    d->sched_part_status_cd = schedPartStatusCd;
}

QDateTime SchedPart::createdAt() const
{
    return d->created_at;
}

QString SchedPart::createdBy() const
{
    return d->created_by;
}

void SchedPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedPart::updatedAt() const
{
    return d->updated_at;
}

QString SchedPart::updatedBy() const
{
    return d->updated_by;
}

void SchedPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPartStatus SchedPart::refPartStatusByschedPartStatusCd() const
{
 return RefPartStatus::get(d->sched_part_status_cd);
}

RefReqAction SchedPart::refReqActionByreqActionCd() const
{
 return RefReqAction::get(d->req_action_cd);
}

EqpAssmblBomPos SchedPart::eqpAssmblBomPosByassmblBomPosId() const
{
 return EqpAssmblBomPos::get(d->assmbl_bom_pos_id);
}

EqpPartNo SchedPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBom SchedPart::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmbl SchedPart::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

SchedStask SchedPart::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedPart &SchedPart::operator=(const SchedPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedPart SchedPart::create(int schedId, int assmblId, int assmblBomId, int partNoId, int assmblBomPosId, const QString &partNote, int schedQt, const QString &reqActionCd, const QString &schedPartStatusCd, const QString &createdBy, const QString &updatedBy)
{
    SchedPartObject obj;
    obj.sched_id = schedId;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.part_no_id = partNoId;
    obj.assmbl_bom_pos_id = assmblBomPosId;
    obj.part_note = partNote;
    obj.sched_qt = schedQt;
    obj.req_action_cd = reqActionCd;
    obj.sched_part_status_cd = schedPartStatusCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedPart();
    }
    return SchedPart(obj);
}

SchedPart SchedPart::create(const QVariantMap &values)
{
    SchedPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedPart SchedPart::get(int schedPartId)
{
    TSqlORMapper<SchedPartObject> mapper;
    return SchedPart(mapper.findByPrimaryKey(schedPartId));
}

int SchedPart::count()
{
    TSqlORMapper<SchedPartObject> mapper;
    return mapper.findCount();
}

QList<SchedPart> SchedPart::getAll()
{
    return tfGetModelListByCriteria<SchedPart, SchedPartObject>();
}

TModelObject *SchedPart::modelData()
{
    return d.data();
}

const TModelObject *SchedPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedPart)
