#include <TreeFrogModel>
#include "schedrmvdpart.h"
#include "schedrmvdpartobject.h"
#include "userapp.h"
#include "refremovereason.h"
#include "eqppartno.h"
#include "invinv.h"
#include "schedpart.h"

SchedRmvdPart::SchedRmvdPart()
    : TAbstractModel(), d(new SchedRmvdPartObject())
{
    d->sched_part_id = 0;
    d->inv_no_id = 0;
    d->part_no_id = 0;
    d->rmvd_qt = 0;
    d->rmvd_by = 0;
}

SchedRmvdPart::SchedRmvdPart(const SchedRmvdPart &other)
    : TAbstractModel(), d(new SchedRmvdPartObject(*other.d))
{ }

SchedRmvdPart::SchedRmvdPart(const SchedRmvdPartObject &object)
    : TAbstractModel(), d(new SchedRmvdPartObject(object))
{ }

SchedRmvdPart::~SchedRmvdPart()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedRmvdPartObject' is deleted.
}

int SchedRmvdPart::schedPartId() const
{
    return d->sched_part_id;
}

void SchedRmvdPart::setSchedPartId(int schedPartId)
{
    d->sched_part_id = schedPartId;
}

int SchedRmvdPart::invNoId() const
{
    return d->inv_no_id;
}

void SchedRmvdPart::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int SchedRmvdPart::partNoId() const
{
    return d->part_no_id;
}

void SchedRmvdPart::setPartNoId(int partNoId)
{
    d->part_no_id = partNoId;
}

QString SchedRmvdPart::serialNoOem() const
{
    return d->serial_no_oem;
}

void SchedRmvdPart::setSerialNoOem(const QString &serialNoOem)
{
    d->serial_no_oem = serialNoOem;
}

QString SchedRmvdPart::removeReasonCd() const
{
    return d->remove_reason_cd;
}

void SchedRmvdPart::setRemoveReasonCd(const QString &removeReasonCd)
{
    d->remove_reason_cd = removeReasonCd;
}

int SchedRmvdPart::rmvdQt() const
{
    return d->rmvd_qt;
}

void SchedRmvdPart::setRmvdQt(int rmvdQt)
{
    d->rmvd_qt = rmvdQt;
}

int SchedRmvdPart::rmvdBy() const
{
    return d->rmvd_by;
}

void SchedRmvdPart::setRmvdBy(int rmvdBy)
{
    d->rmvd_by = rmvdBy;
}

QDateTime SchedRmvdPart::createdAt() const
{
    return d->created_at;
}

QString SchedRmvdPart::createdBy() const
{
    return d->created_by;
}

void SchedRmvdPart::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedRmvdPart::updatedAt() const
{
    return d->updated_at;
}

QString SchedRmvdPart::updatedBy() const
{
    return d->updated_by;
}

void SchedRmvdPart::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedRmvdPart::userAppByrmvdBy() const
{
 return UserApp::get(d->rmvd_by);
}

RefRemoveReason SchedRmvdPart::refRemoveReasonByremoveReasonCd() const
{
 return RefRemoveReason::get(d->remove_reason_cd);
}

EqpPartNo SchedRmvdPart::eqpPartNoBypartNoId() const
{
 return EqpPartNo::get(d->part_no_id);
}

InvInv SchedRmvdPart::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

SchedPart SchedRmvdPart::schedPartByschedPartId() const
{
 return SchedPart::get(d->sched_part_id);
}

SchedRmvdPart &SchedRmvdPart::operator=(const SchedRmvdPart &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedRmvdPart SchedRmvdPart::create(int schedPartId, int invNoId, int partNoId, const QString &serialNoOem, const QString &removeReasonCd, int rmvdQt, int rmvdBy, const QString &createdBy, const QString &updatedBy)
{
    SchedRmvdPartObject obj;
    obj.sched_part_id = schedPartId;
    obj.inv_no_id = invNoId;
    obj.part_no_id = partNoId;
    obj.serial_no_oem = serialNoOem;
    obj.remove_reason_cd = removeReasonCd;
    obj.rmvd_qt = rmvdQt;
    obj.rmvd_by = rmvdBy;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedRmvdPart();
    }
    return SchedRmvdPart(obj);
}

SchedRmvdPart SchedRmvdPart::create(const QVariantMap &values)
{
    SchedRmvdPart model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedRmvdPart SchedRmvdPart::get(int schedPartId)
{
    TSqlORMapper<SchedRmvdPartObject> mapper;
    return SchedRmvdPart(mapper.findByPrimaryKey(schedPartId));
}

int SchedRmvdPart::count()
{
    TSqlORMapper<SchedRmvdPartObject> mapper;
    return mapper.findCount();
}

QList<SchedRmvdPart> SchedRmvdPart::getAll()
{
    return tfGetModelListByCriteria<SchedRmvdPart, SchedRmvdPartObject>();
}

TModelObject *SchedRmvdPart::modelData()
{
    return d.data();
}

const TModelObject *SchedRmvdPart::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedRmvdPart &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedRmvdPart &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedRmvdPart)
