#include <TreeFrogModel>
#include "evtinvusage.h"
#include "evtinvusageobject.h"
#include "flightleg.h"
#include "datatype.h"
#include "invinv.h"
#include "evtevent.h"

EvtInvUsage::EvtInvUsage()
    : TAbstractModel(), d(new EvtInvUsageObject())
{
    d->event_id = 0;
    d->inv_no_id = 0;
    d->data_type_id = 0;
    d->leg_id = 0;
    d->tsi_qt = 0;
    d->tsn_qt = 0;
    d->tso_qt = 0;
    d->h_tsn_qt = 0;
    d->h_tso_qt = 0;
    d->nh_tsn_qt = 0;
    d->nh_tso_qt = 0;
    d->assmbl_tsn_qt = 0;
    d->assmbl_tso_qt = 0;
}

EvtInvUsage::EvtInvUsage(const EvtInvUsage &other)
    : TAbstractModel(), d(new EvtInvUsageObject(*other.d))
{ }

EvtInvUsage::EvtInvUsage(const EvtInvUsageObject &object)
    : TAbstractModel(), d(new EvtInvUsageObject(object))
{ }

EvtInvUsage::~EvtInvUsage()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtInvUsageObject' is deleted.
}

int EvtInvUsage::eventId() const
{
    return d->event_id;
}

void EvtInvUsage::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtInvUsage::invNoId() const
{
    return d->inv_no_id;
}

void EvtInvUsage::setInvNoId(int invNoId)
{
    d->inv_no_id = invNoId;
}

int EvtInvUsage::dataTypeId() const
{
    return d->data_type_id;
}

void EvtInvUsage::setDataTypeId(int dataTypeId)
{
    d->data_type_id = dataTypeId;
}

int EvtInvUsage::legId() const
{
    return d->leg_id;
}

void EvtInvUsage::setLegId(int legId)
{
    d->leg_id = legId;
}

double EvtInvUsage::tsiQt() const
{
    return d->tsi_qt;
}

void EvtInvUsage::setTsiQt(double tsiQt)
{
    d->tsi_qt = tsiQt;
}

double EvtInvUsage::tsnQt() const
{
    return d->tsn_qt;
}

void EvtInvUsage::setTsnQt(double tsnQt)
{
    d->tsn_qt = tsnQt;
}

double EvtInvUsage::tsoQt() const
{
    return d->tso_qt;
}

void EvtInvUsage::setTsoQt(double tsoQt)
{
    d->tso_qt = tsoQt;
}

double EvtInvUsage::hTsnQt() const
{
    return d->h_tsn_qt;
}

void EvtInvUsage::setHTsnQt(double hTsnQt)
{
    d->h_tsn_qt = hTsnQt;
}

double EvtInvUsage::hTsoQt() const
{
    return d->h_tso_qt;
}

void EvtInvUsage::setHTsoQt(double hTsoQt)
{
    d->h_tso_qt = hTsoQt;
}

double EvtInvUsage::nhTsnQt() const
{
    return d->nh_tsn_qt;
}

void EvtInvUsage::setNhTsnQt(double nhTsnQt)
{
    d->nh_tsn_qt = nhTsnQt;
}

double EvtInvUsage::nhTsoQt() const
{
    return d->nh_tso_qt;
}

void EvtInvUsage::setNhTsoQt(double nhTsoQt)
{
    d->nh_tso_qt = nhTsoQt;
}

double EvtInvUsage::assmblTsnQt() const
{
    return d->assmbl_tsn_qt;
}

void EvtInvUsage::setAssmblTsnQt(double assmblTsnQt)
{
    d->assmbl_tsn_qt = assmblTsnQt;
}

double EvtInvUsage::assmblTsoQt() const
{
    return d->assmbl_tso_qt;
}

void EvtInvUsage::setAssmblTsoQt(double assmblTsoQt)
{
    d->assmbl_tso_qt = assmblTsoQt;
}

bool EvtInvUsage::negatedBool() const
{
    return d->negated_bool;
}

void EvtInvUsage::setNegatedBool(bool negatedBool)
{
    d->negated_bool = negatedBool;
}

QDateTime EvtInvUsage::createdAt() const
{
    return d->created_at;
}

QString EvtInvUsage::createdBy() const
{
    return d->created_by;
}

void EvtInvUsage::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtInvUsage::updatedAt() const
{
    return d->updated_at;
}

QString EvtInvUsage::updatedBy() const
{
    return d->updated_by;
}

void EvtInvUsage::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

FlightLeg EvtInvUsage::flightLegBylegId() const
{
 return FlightLeg::get(d->leg_id);
}

DataType EvtInvUsage::dataTypeBydataTypeId() const
{
 return DataType::get(d->data_type_id);
}

InvInv EvtInvUsage::invInvByinvNoId() const
{
 return InvInv::get(d->inv_no_id);
}

EvtEvent EvtInvUsage::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtInvUsage &EvtInvUsage::operator=(const EvtInvUsage &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtInvUsage EvtInvUsage::create(int eventId, int invNoId, int dataTypeId, int legId, double tsiQt, double tsnQt, double tsoQt, double hTsnQt, double hTsoQt, double nhTsnQt, double nhTsoQt, double assmblTsnQt, double assmblTsoQt, bool negatedBool, const QString &createdBy, const QString &updatedBy)
{
    EvtInvUsageObject obj;
    obj.event_id = eventId;
    obj.inv_no_id = invNoId;
    obj.data_type_id = dataTypeId;
    obj.leg_id = legId;
    obj.tsi_qt = tsiQt;
    obj.tsn_qt = tsnQt;
    obj.tso_qt = tsoQt;
    obj.h_tsn_qt = hTsnQt;
    obj.h_tso_qt = hTsoQt;
    obj.nh_tsn_qt = nhTsnQt;
    obj.nh_tso_qt = nhTsoQt;
    obj.assmbl_tsn_qt = assmblTsnQt;
    obj.assmbl_tso_qt = assmblTsoQt;
    obj.negated_bool = negatedBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtInvUsage();
    }
    return EvtInvUsage(obj);
}

EvtInvUsage EvtInvUsage::create(const QVariantMap &values)
{
    EvtInvUsage model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtInvUsage EvtInvUsage::get(int eventId, int invNoId, int dataTypeId)
{
    TSqlORMapper<EvtInvUsageObject> mapper;
    return EvtInvUsage(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(invNoId)<<QVariant(dataTypeId)));
}

int EvtInvUsage::count()
{
    TSqlORMapper<EvtInvUsageObject> mapper;
    return mapper.findCount();
}

QList<EvtInvUsage> EvtInvUsage::getAll()
{
    return tfGetModelListByCriteria<EvtInvUsage, EvtInvUsageObject>();
}

TModelObject *EvtInvUsage::modelData()
{
    return d.data();
}

const TModelObject *EvtInvUsage::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtInvUsage &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtInvUsage &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtInvUsage)
