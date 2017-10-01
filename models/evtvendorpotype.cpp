#include <TreeFrogModel>
#include "evtvendorpotype.h"
#include "evtvendorpotypeobject.h"
#include "refpotype.h"
#include "org.h"
#include "vendor.h"
#include "evtevent.h"

EvtVendorPoType::EvtVendorPoType()
    : TAbstractModel(), d(new EvtVendorPoTypeObject())
{
    d->event_id = 0;
    d->vendor_id = 0;
    d->org_id = 0;
}

EvtVendorPoType::EvtVendorPoType(const EvtVendorPoType &other)
    : TAbstractModel(), d(new EvtVendorPoTypeObject(*other.d))
{ }

EvtVendorPoType::EvtVendorPoType(const EvtVendorPoTypeObject &object)
    : TAbstractModel(), d(new EvtVendorPoTypeObject(object))
{ }

EvtVendorPoType::~EvtVendorPoType()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtVendorPoTypeObject' is deleted.
}

int EvtVendorPoType::eventId() const
{
    return d->event_id;
}

void EvtVendorPoType::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtVendorPoType::vendorId() const
{
    return d->vendor_id;
}

void EvtVendorPoType::setVendorId(int vendorId)
{
    d->vendor_id = vendorId;
}

int EvtVendorPoType::orgId() const
{
    return d->org_id;
}

void EvtVendorPoType::setOrgId(int orgId)
{
    d->org_id = orgId;
}

QString EvtVendorPoType::poTypeCd() const
{
    return d->po_type_cd;
}

void EvtVendorPoType::setPoTypeCd(const QString &poTypeCd)
{
    d->po_type_cd = poTypeCd;
}

QDateTime EvtVendorPoType::createdAt() const
{
    return d->created_at;
}

QString EvtVendorPoType::createdBy() const
{
    return d->created_by;
}

void EvtVendorPoType::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtVendorPoType::updatedAt() const
{
    return d->updated_at;
}

QString EvtVendorPoType::updatedBy() const
{
    return d->updated_by;
}

void EvtVendorPoType::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefPoType EvtVendorPoType::refPoTypeBypoTypeCd() const
{
 return RefPoType::get(d->po_type_cd);
}

Org EvtVendorPoType::orgByorgId() const
{
 return Org::get(d->org_id);
}

Vendor EvtVendorPoType::vendorByvendorId() const
{
 return Vendor::get(d->vendor_id);
}

EvtEvent EvtVendorPoType::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtVendorPoType &EvtVendorPoType::operator=(const EvtVendorPoType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtVendorPoType EvtVendorPoType::create(int eventId, int vendorId, int orgId, const QString &poTypeCd, const QString &createdBy, const QString &updatedBy)
{
    EvtVendorPoTypeObject obj;
    obj.event_id = eventId;
    obj.vendor_id = vendorId;
    obj.org_id = orgId;
    obj.po_type_cd = poTypeCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtVendorPoType();
    }
    return EvtVendorPoType(obj);
}

EvtVendorPoType EvtVendorPoType::create(const QVariantMap &values)
{
    EvtVendorPoType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtVendorPoType EvtVendorPoType::get(int eventId, int vendorId)
{
    TSqlORMapper<EvtVendorPoTypeObject> mapper;
    return EvtVendorPoType(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(vendorId)));
}

int EvtVendorPoType::count()
{
    TSqlORMapper<EvtVendorPoTypeObject> mapper;
    return mapper.findCount();
}

QList<EvtVendorPoType> EvtVendorPoType::getAll()
{
    return tfGetModelListByCriteria<EvtVendorPoType, EvtVendorPoTypeObject>();
}

TModelObject *EvtVendorPoType::modelData()
{
    return d.data();
}

const TModelObject *EvtVendorPoType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtVendorPoType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtVendorPoType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtVendorPoType)
