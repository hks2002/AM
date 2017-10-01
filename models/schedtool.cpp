#include <TreeFrogModel>
#include "schedtool.h"
#include "schedtoolobject.h"
#include "userapp.h"
#include "eqppartno.h"
#include "eqpassmblbom.h"
#include "eqpassmbl.h"
#include "schedstask.h"

SchedTool::SchedTool()
    : TAbstractModel(), d(new SchedToolObject())
{
    d->sched_tool_id = 0;
    d->sched_id = 0;
    d->assmbl_id = 0;
    d->assmbl_bom_id = 0;
    d->part_no_id = 0;
    d->sched_qt = 0;
    d->check_out_to_user = 0;
}

SchedTool::SchedTool(const SchedTool &other)
    : TAbstractModel(), d(new SchedToolObject(*other.d))
{ }

SchedTool::SchedTool(const SchedToolObject &object)
    : TAbstractModel(), d(new SchedToolObject(object))
{ }

SchedTool::~SchedTool()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedToolObject' is deleted.
}

int SchedTool::schedToolId() const
{
    return d->sched_tool_id;
}

int SchedTool::schedId() const
{
    return d->sched_id;
}

void SchedTool::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedTool::assmblId() const
{
    return d->assmbl_id;
}

void SchedTool::setAssmblId(int assmblId)
{
    d->assmbl_id = assmblId;
}

int SchedTool::assmblBomId() const
{
    return d->assmbl_bom_id;
}

void SchedTool::setAssmblBomId(int assmblBomId)
{
    d->assmbl_bom_id = assmblBomId;
}

int SchedTool::partNoId() const
{
    return d->part_no_id;
}

void SchedTool::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString SchedTool::partNote() const
{
    return d->part_note;
}

void SchedTool::setPartNote(const QString &partNote)
{
    d->part_note = partNote;
}

int SchedTool::schedQt() const
{
    return d->sched_qt;
}

void SchedTool::setSchedQt(int schedQt)
{
    d->sched_qt = schedQt;
}

QString SchedTool::schedUsetime() const
{
    return d->sched_usetime;
}

void SchedTool::setSchedUsetime(const QString &schedUsetime)
{
    d->sched_usetime = schedUsetime;
}

QString SchedTool::actualUsetime() const
{
    return d->actual_usetime;
}

void SchedTool::setActualUsetime(const QString &actualUsetime)
{
    d->actual_usetime = actualUsetime;
}

int SchedTool::checkOutToUser() const
{
    return d->check_out_to_user;
}

void SchedTool::setCheckOutToUser(int checkOutToUser)
{
    d->check_out_to_user = checkOutToUser;
}

QDateTime SchedTool::createdAt() const
{
    return d->created_at;
}

QString SchedTool::createdBy() const
{
    return d->created_by;
}

void SchedTool::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedTool::updatedAt() const
{
    return d->updated_at;
}

QString SchedTool::updatedBy() const
{
    return d->updated_by;
}

void SchedTool::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedTool::userAppBycheckOutToUser() const
{
 return UserApp::get(d->check_out_to_user);
}

EqpPartNo SchedTool::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

EqpAssmblBom SchedTool::eqpAssmblBomByassmblBomId() const
{
 return EqpAssmblBom::get(d->assmbl_bom_id);
}

EqpAssmbl SchedTool::eqpAssmblByassmblId() const
{
 return EqpAssmbl::get(d->assmbl_id);
}

SchedStask SchedTool::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedTool &SchedTool::operator=(const SchedTool &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedTool SchedTool::create(int schedId, int assmblId, int assmblBomId, int partNoId, const QString &partNote, int schedQt, const QString &schedUsetime, const QString &actualUsetime, int checkOutToUser, const QString &createdBy, const QString &updatedBy)
{
    SchedToolObject obj;
    obj.sched_id = schedId;
    obj.assmbl_id = assmblId;
    obj.assmbl_bom_id = assmblBomId;
    obj.part_no_id = partNoId;
    obj.part_note = partNote;
    obj.sched_qt = schedQt;
    obj.sched_usetime = schedUsetime;
    obj.actual_usetime = actualUsetime;
    obj.check_out_to_user = checkOutToUser;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedTool();
    }
    return SchedTool(obj);
}

SchedTool SchedTool::create(const QVariantMap &values)
{
    SchedTool model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedTool SchedTool::get(int schedToolId)
{
    TSqlORMapper<SchedToolObject> mapper;
    return SchedTool(mapper.findByPrimaryKey(schedToolId));
}

int SchedTool::count()
{
    TSqlORMapper<SchedToolObject> mapper;
    return mapper.findCount();
}

QList<SchedTool> SchedTool::getAll()
{
    return tfGetModelListByCriteria<SchedTool, SchedToolObject>();
}

TModelObject *SchedTool::modelData()
{
    return d.data();
}

const TModelObject *SchedTool::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedTool &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedTool &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedTool)
