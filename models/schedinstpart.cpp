#include <TreeFrogModel>
#include "schedinstpart.h"
#include "schedinstpartobject.h"
#include "userapp.h"
#include "eqppartno.h"
#include "invinv.h"
#include "schedpart.h"

SchedInstPart::SchedInstPart()
    : TAbstractModel(), d(new SchedInstPartObject())
{
    d->sched_part_id = 0;
    d->inv_no_id = 0;
    d->part_no_id = 0;
    d->inst_qt = 0;
    d->inst_by = 0;
}

SchedInstPart::SchedInstPart(const SchedInstPart &other)
    : TAbstractModel(), d(new SchedInstPartObject(*other.d))
{ }

SchedInstPart::SchedInstPart(const SchedInstPartObject &object)
    : TAbstractModel(), d(new SchedInstPartObject(object))
{ }

SchedInstPart::~SchedInstPart()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedInstPartObject' is deleted.
}

int SchedInstPart::schedPartId() const
{
    return d->sched_part_id;
}

void SchedInstPart::setSchedPartId(int schedPartId)
{
    d->sched_part_id = schedPartId;
}

int SchedInstPart::invNoId() const
{
    return d->inv_no_id;
}

void SchedInstPart::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int SchedInstPart::partNoId() const
{
    return d->part_no_id;
}

void SchedInstPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString SchedInstPart::serialNoOem() const
{
    return d->serial_no_oem;
}

void SchedInstPart::setSerialNoOem(const QString &serialNoOem)
{
    d->serial_no_oem = serialNoOem;
}

int SchedInstPart::instQt() const
{
    return d->inst_qt;
}

void SchedInstPart::setInstQt(int instQt)
{
    d->inst_qt = instQt;
}

int SchedInstPart::instBy() const
{
    return d->inst_by;
}

void SchedInstPart::setInstBy(int instBy)
{
    d->inst_by = instBy;
}

QDateTime SchedInstPart::createdAt() const
{
    return d->created_at;
}

QString SchedInstPart::createdBy() const
{
    return d->created_by;
}

void SchedInstPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedInstPart::updatedAt() const
{
    return d->updated_at;
}

QString SchedInstPart::updatedBy() const
{
    return d->updated_by;
}

void SchedInstPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedInstPart::userAppByinstBy() const
{
 return UserApp::get(d->inst_by);
}

EqpPartNo SchedInstPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

InvInv SchedInstPart::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

SchedPart SchedInstPart::schedPartByschedPartId() const
{
 return SchedPart::get(d->sched_part_id);
}

SchedInstPart &SchedInstPart::operator=(const SchedInstPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedInstPart SchedInstPart::create(int schedPartId, int invNoId, int partNoId, const QString &serialNoOem, int instQt, int instBy, const QString &createdBy, const QString &updatedBy)
{
    SchedInstPartObject obj;
    obj.sched_part_id = schedPartId;
    obj.inv_no_id = invNoId;
    obj.part_no_id = partNoId;
    obj.serial_no_oem = serialNoOem;
    obj.inst_qt = instQt;
    obj.inst_by = instBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedInstPart();
    }
    return SchedInstPart(obj);
}

SchedInstPart SchedInstPart::create(const QVariantMap &values)
{
    SchedInstPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedInstPart SchedInstPart::get(int schedPartId)
{
    TSqlORMapper<SchedInstPartObject> mapper;
    return SchedInstPart(mapper.findByPrimaryKey(schedPartId));
}

int SchedInstPart::count()
{
    TSqlORMapper<SchedInstPartObject> mapper;
    return mapper.findCount();
}

QList<SchedInstPart> SchedInstPart::getAll()
{
    return tfGetModelListByCriteria<SchedInstPart, SchedInstPartObject>();
}

TModelObject *SchedInstPart::modelData()
{
    return d.data();
}

const TModelObject *SchedInstPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedInstPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedInstPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedInstPart)
