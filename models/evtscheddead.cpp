#include <TreeFrogModel>
#include "evtscheddead.h"
#include "evtscheddeadobject.h"
#include "datatype.h"
#include "evtevent.h"

EvtSchedDead::EvtSchedDead()
    : TAbstractModel(), d(new EvtSchedDeadObject())
{
    d->event_id = 0;
    d->data_type_id = 0;
    d->sched_dead_qt = 0;
    d->start_qt = 0;
    d->usage_rem_qt = 0;
    d->deviation_qt = 0;
    d->interval_qt = 0;
    d->prefixed_qt = 0;
    d->postfixed_qt = 0;
    d->notify_qt = 0;
    d->min_plan_qt = 0;
}

EvtSchedDead::EvtSchedDead(const EvtSchedDead &other)
    : TAbstractModel(), d(new EvtSchedDeadObject(*other.d))
{ }

EvtSchedDead::EvtSchedDead(const EvtSchedDeadObject &object)
    : TAbstractModel(), d(new EvtSchedDeadObject(object))
{ }

EvtSchedDead::~EvtSchedDead()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtSchedDeadObject' is deleted.
}

int EvtSchedDead::eventId() const
{
    return d->event_id;
}

void EvtSchedDead::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtSchedDead::dataTypeId() const
{
    return d->data_type_id;
}

void EvtSchedDead::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

double EvtSchedDead::schedDeadQt() const
{
    return d->sched_dead_qt;
}

void EvtSchedDead::setSchedDeadQt(double schedDeadQt)
{
    d->sched_dead_qt = schedDeadQt;
}

QDateTime EvtSchedDead::schedDeadDt() const
{
    return d->sched_dead_dt;
}

void EvtSchedDead::setSchedDeadDt(const QDateTime &schedDeadDt)
{
    d->sched_dead_dt = schedDeadDt;
}

QDateTime EvtSchedDead::schedDeadDtLastUpdated() const
{
    return d->sched_dead_dt_last_updated;
}

void EvtSchedDead::setSchedDeadDtLastUpdated(const QDateTime &schedDeadDtLastUpdated)
{
    d->sched_dead_dt_last_updated = schedDeadDtLastUpdated;
}

QString EvtSchedDead::schedFromCd() const
{
    return d->sched_from_cd;
}

void EvtSchedDead::setSchedFromCd(const QString &schedFromCd)
{
    d->sched_from_cd = schedFromCd;
}

double EvtSchedDead::startQt() const
{
    return d->start_qt;
}

void EvtSchedDead::setStartQt(double startQt)
{
    d->start_qt = startQt;
}

QDateTime EvtSchedDead::startDt() const
{
    return d->start_dt;
}

void EvtSchedDead::setStartDt(const QDateTime &startDt)
{
    d->start_dt = startDt;
}

double EvtSchedDead::usageRemQt() const
{
    return d->usage_rem_qt;
}

void EvtSchedDead::setUsageRemQt(double usageRemQt)
{
    d->usage_rem_qt = usageRemQt;
}

bool EvtSchedDead::schedDriverBool() const
{
    return d->sched_driver_bool;
}

void EvtSchedDead::setSchedDriverBool(bool schedDriverBool)
{
    d->sched_driver_bool = schedDriverBool;
}

double EvtSchedDead::deviationQt() const
{
    return d->deviation_qt;
}

void EvtSchedDead::setDeviationQt(double deviationQt)
{
    d->deviation_qt = deviationQt;
}

double EvtSchedDead::intervalQt() const
{
    return d->interval_qt;
}

void EvtSchedDead::setIntervalQt(double intervalQt)
{
    d->interval_qt = intervalQt;
}

double EvtSchedDead::prefixedQt() const
{
    return d->prefixed_qt;
}

void EvtSchedDead::setPrefixedQt(double prefixedQt)
{
    d->prefixed_qt = prefixedQt;
}

double EvtSchedDead::postfixedQt() const
{
    return d->postfixed_qt;
}

void EvtSchedDead::setPostfixedQt(double postfixedQt)
{
    d->postfixed_qt = postfixedQt;
}

double EvtSchedDead::notifyQt() const
{
    return d->notify_qt;
}

void EvtSchedDead::setNotifyQt(double notifyQt)
{
    d->notify_qt = notifyQt;
}

double EvtSchedDead::minPlanQt() const
{
    return d->min_plan_qt;
}

void EvtSchedDead::setMinPlanQt(double minPlanQt)
{
    d->min_plan_qt = minPlanQt;
}

bool EvtSchedDead::postfixedMandBool() const
{
    return d->postfixed_mand_bool;
}

void EvtSchedDead::setPostfixedMandBool(bool postfixedMandBool)
{
    d->postfixed_mand_bool = postfixedMandBool;
}

QDateTime EvtSchedDead::createdAt() const
{
    return d->created_at;
}

QString EvtSchedDead::createdBy() const
{
    return d->created_by;
}

void EvtSchedDead::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtSchedDead::updatedAt() const
{
    return d->updated_at;
}

QString EvtSchedDead::updatedBy() const
{
    return d->updated_by;
}

void EvtSchedDead::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

DataType EvtSchedDead::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

EvtEvent EvtSchedDead::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtSchedDead &EvtSchedDead::operator=(const EvtSchedDead &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtSchedDead EvtSchedDead::create(int eventId, int dataTypeId, double schedDeadQt, const QDateTime &schedDeadDt, const QDateTime &schedDeadDtLastUpdated, const QString &schedFromCd, double startQt, const QDateTime &startDt, double usageRemQt, bool schedDriverBool, double deviationQt, double intervalQt, double prefixedQt, double postfixedQt, double notifyQt, double minPlanQt, bool postfixedMandBool, const QString &createdBy, const QString &updatedBy)
{
    EvtSchedDeadObject obj;
    obj.event_id = eventId;
    obj.data_type_id = dataTypeId;
    obj.sched_dead_qt = schedDeadQt;
    obj.sched_dead_dt = schedDeadDt;
    obj.sched_dead_dt_last_updated = schedDeadDtLastUpdated;
    obj.sched_from_cd = schedFromCd;
    obj.start_qt = startQt;
    obj.start_dt = startDt;
    obj.usage_rem_qt = usageRemQt;
    obj.sched_driver_bool = schedDriverBool;
    obj.deviation_qt = deviationQt;
    obj.interval_qt = intervalQt;
    obj.prefixed_qt = prefixedQt;
    obj.postfixed_qt = postfixedQt;
    obj.notify_qt = notifyQt;
    obj.min_plan_qt = minPlanQt;
    obj.postfixed_mand_bool = postfixedMandBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtSchedDead();
    }
    return EvtSchedDead(obj);
}

EvtSchedDead EvtSchedDead::create(const QVariantMap &values)
{
    EvtSchedDead model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtSchedDead EvtSchedDead::get(int eventId, int dataTypeId)
{
    TSqlORMapper<EvtSchedDeadObject> mapper;
    return EvtSchedDead(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(dataTypeId)));
}

int EvtSchedDead::count()
{
    TSqlORMapper<EvtSchedDeadObject> mapper;
    return mapper.findCount();
}

QList<EvtSchedDead> EvtSchedDead::getAll()
{
    return tfGetModelListByCriteria<EvtSchedDead, EvtSchedDeadObject>();
}

TModelObject *EvtSchedDead::modelData()
{
    return d.data();
}

const TModelObject *EvtSchedDead::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtSchedDead &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtSchedDead &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtSchedDead)
