#include <TreeFrogModel>
#include "schedwpline.h"
#include "schedwplineobject.h"
#include "userapp.h"
#include "schedstask.h"
#include "schedwp.h"

SchedWpLine::SchedWpLine()
    : TAbstractModel(), d(new SchedWpLineObject())
{
    d->sched_wp_id = 0;
    d->sched_id = 0;
    d->workscope_order = 0;
    d->assign_by = 0;
    d->unassign_by = 0;
    d->collected_by = 0;
}

SchedWpLine::SchedWpLine(const SchedWpLine &other)
    : TAbstractModel(), d(new SchedWpLineObject(*other.d))
{ }

SchedWpLine::SchedWpLine(const SchedWpLineObject &object)
    : TAbstractModel(), d(new SchedWpLineObject(object))
{ }

SchedWpLine::~SchedWpLine()
{
    // If the reference count becomes 0,
    // the shared data object 'SchedWpLineObject' is deleted.
}

int SchedWpLine::schedWpId() const
{
    return d->sched_wp_id;
}

void SchedWpLine::setSchedWpId(int schedWpId)
{
    d->sched_wp_id = schedWpId;
}

int SchedWpLine::schedId() const
{
    return d->sched_id;
}

void SchedWpLine::setSchedId(int schedId)
{
    d->sched_id = schedId;
}

int SchedWpLine::workscopeOrder() const
{
    return d->workscope_order;
}

void SchedWpLine::setWorkscopeOrder(int workscopeOrder)
{
    d->workscope_order = workscopeOrder;
}

QString SchedWpLine::vendorLineNo() const
{
    return d->vendor_line_no;
}

void SchedWpLine::setVendorLineNo(const QString &vendorLineNo)
{
    d->vendor_line_no = vendorLineNo;
}

bool SchedWpLine::unassignBool() const
{
    return d->unassign_bool;
}

void SchedWpLine::setUnassignBool(bool unassignBool)
{
    d->unassign_bool = unassignBool;
}

QDateTime SchedWpLine::assignDt() const
{
    return d->assign_dt;
}

void SchedWpLine::setAssignDt(const QDateTime &assignDt)
{
    d->assign_dt = assignDt;
}

int SchedWpLine::assignBy() const
{
    return d->assign_by;
}

void SchedWpLine::setAssignBy(int assignBy)
{
    d->assign_by = assignBy;
}

QDateTime SchedWpLine::unassignDt() const
{
    return d->unassign_dt;
}

void SchedWpLine::setUnassignDt(const QDateTime &unassignDt)
{
    d->unassign_dt = unassignDt;
}

int SchedWpLine::unassignBy() const
{
    return d->unassign_by;
}

void SchedWpLine::setUnassignBy(int unassignBy)
{
    d->unassign_by = unassignBy;
}

bool SchedWpLine::collectedBool() const
{
    return d->collected_bool;
}

void SchedWpLine::setCollectedBool(bool collectedBool)
{
    d->collected_bool = collectedBool;
}

int SchedWpLine::collectedBy() const
{
    return d->collected_by;
}

void SchedWpLine::setCollectedBy(int collectedBy)
{
    d->collected_by = collectedBy;
}

QDateTime SchedWpLine::collectedDt() const
{
    return d->collected_dt;
}

void SchedWpLine::setCollectedDt(const QDateTime &collectedDt)
{
    d->collected_dt = collectedDt;
}

QDateTime SchedWpLine::createdAt() const
{
    return d->created_at;
}

QString SchedWpLine::createdBy() const
{
    return d->created_by;
}

void SchedWpLine::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime SchedWpLine::updatedAt() const
{
    return d->updated_at;
}

QString SchedWpLine::updatedBy() const
{
    return d->updated_by;
}

void SchedWpLine::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

UserApp SchedWpLine::userAppBycollectedBy() const
{
 return UserApp::get(d->collected_by);
}

SchedStask SchedWpLine::schedStaskByschedId() const
{
 return SchedStask::get(d->sched_id);
}

SchedWp SchedWpLine::schedWpByschedWpId() const
{
 return SchedWp::get(d->sched_wp_id);
}

SchedWpLine &SchedWpLine::operator=(const SchedWpLine &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

SchedWpLine SchedWpLine::create(int schedWpId, int schedId, int workscopeOrder, const QString &vendorLineNo, bool unassignBool, const QDateTime &assignDt, int assignBy, const QDateTime &unassignDt, int unassignBy, bool collectedBool, int collectedBy, const QDateTime &collectedDt, const QString &createdBy, const QString &updatedBy)
{
    SchedWpLineObject obj;
    obj.sched_wp_id = schedWpId;
    obj.sched_id = schedId;
    obj.workscope_order = workscopeOrder;
    obj.vendor_line_no = vendorLineNo;
    obj.unassign_bool = unassignBool;
    obj.assign_dt = assignDt;
    obj.assign_by = assignBy;
    obj.unassign_dt = unassignDt;
    obj.unassign_by = unassignBy;
    obj.collected_bool = collectedBool;
    obj.collected_by = collectedBy;
    obj.collected_dt = collectedDt;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return SchedWpLine();
    }
    return SchedWpLine(obj);
}

SchedWpLine SchedWpLine::create(const QVariantMap &values)
{
    SchedWpLine model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

SchedWpLine SchedWpLine::get(int schedWpId, int schedId)
{
    TSqlORMapper<SchedWpLineObject> mapper;
    return SchedWpLine(mapper.findByPrimaryKey(QVariantList()<<QVariant(schedWpId)<<QVariant(schedId)));
}

int SchedWpLine::count()
{
    TSqlORMapper<SchedWpLineObject> mapper;
    return mapper.findCount();
}

QList<SchedWpLine> SchedWpLine::getAll()
{
    return tfGetModelListByCriteria<SchedWpLine, SchedWpLineObject>();
}

TModelObject *SchedWpLine::modelData()
{
    return d.data();
}

const TModelObject *SchedWpLine::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const SchedWpLine &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SchedWpLine &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(SchedWpLine)
