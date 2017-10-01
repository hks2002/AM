#include <TreeFrogModel>
#include "evtvendor.h"
#include "evtvendorobject.h"
#include "vendor.h"
#include "evtevent.h"

EvtVendor::EvtVendor()
    : TAbstractModel(), d(new EvtVendorObject())
{
    d->event_id = 0;
    d->vendor_id = 0;
}

EvtVendor::EvtVendor(const EvtVendor &other)
    : TAbstractModel(), d(new EvtVendorObject(*other.d))
{ }

EvtVendor::EvtVendor(const EvtVendorObject &object)
    : TAbstractModel(), d(new EvtVendorObject(object))
{ }

EvtVendor::~EvtVendor()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtVendorObject' is deleted.
}

int EvtVendor::eventId() const
{
    return d->event_id;
}

void EvtVendor::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtVendor::vendorId() const
{
    return d->vendor_id;
}

void EvtVendor::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

QDateTime EvtVendor::createdAt() const
{
    return d->created_at;
}

QString EvtVendor::createdBy() const
{
    return d->created_by;
}

void EvtVendor::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtVendor::updatedAt() const
{
    return d->updated_at;
}

QString EvtVendor::updatedBy() const
{
    return d->updated_by;
}

void EvtVendor::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Vendor EvtVendor::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

EvtEvent EvtVendor::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtVendor &EvtVendor::operator=(const EvtVendor &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtVendor EvtVendor::create(int eventId, int vendorId, const QString &createdBy, const QString &updatedBy)
{
    EvtVendorObject obj;
    obj.event_id = eventId;
    obj.vendor_id = vendorId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtVendor();
    }
    return EvtVendor(obj);
}

EvtVendor EvtVendor::create(const QVariantMap &values)
{
    EvtVendor model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtVendor EvtVendor::get(int eventId, int vendorId)
{
    TSqlORMapper<EvtVendorObject> mapper;
    return EvtVendor(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(vendorId)));
}

int EvtVendor::count()
{
    TSqlORMapper<EvtVendorObject> mapper;
    return mapper.findCount();
}

QList<EvtVendor> EvtVendor::getAll()
{
    return tfGetModelListByCriteria<EvtVendor, EvtVendorObject>();
}

TModelObject *EvtVendor::modelData()
{
    return d.data();
}

const TModelObject *EvtVendor::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtVendor &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtVendor &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtVendor)
