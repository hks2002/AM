#include <TreeFrogModel>
#include "evtlicense.h"
#include "evtlicenseobject.h"
#include "license.h"
#include "evtevent.h"

EvtLicense::EvtLicense()
    : TAbstractModel(), d(new EvtLicenseObject())
{
    d->event_id = 0;
    d->license_id = 0;
}

EvtLicense::EvtLicense(const EvtLicense &other)
    : TAbstractModel(), d(new EvtLicenseObject(*other.d))
{ }

EvtLicense::EvtLicense(const EvtLicenseObject &object)
    : TAbstractModel(), d(new EvtLicenseObject(object))
{ }

EvtLicense::~EvtLicense()
{
    // If the reference count becomes 0,
    // the shared data object 'EvtLicenseObject' is deleted.
}

int EvtLicense::eventId() const
{
    return d->event_id;
}

void EvtLicense::setEventId(int eventId)
{
    d->event_id = eventId;
}

int EvtLicense::licenseId() const
{
    return d->license_id;
}

void EvtLicense::setLicenseId(int licenseId)
{
    d->license_id = licenseId;
}

QDateTime EvtLicense::createdAt() const
{
    return d->created_at;
}

QString EvtLicense::createdBy() const
{
    return d->created_by;
}

void EvtLicense::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime EvtLicense::updatedAt() const
{
    return d->updated_at;
}

QString EvtLicense::updatedBy() const
{
    return d->updated_by;
}

void EvtLicense::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

License EvtLicense::licenseBylicenseId() const
{
 return License::get(d->license_id);
}

EvtEvent EvtLicense::evtEventByeventId() const
{
 return EvtEvent::get(d->event_id);
}

EvtLicense &EvtLicense::operator=(const EvtLicense &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

EvtLicense EvtLicense::create(int eventId, int licenseId, const QString &createdBy, const QString &updatedBy)
{
    EvtLicenseObject obj;
    obj.event_id = eventId;
    obj.license_id = licenseId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return EvtLicense();
    }
    return EvtLicense(obj);
}

EvtLicense EvtLicense::create(const QVariantMap &values)
{
    EvtLicense model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

EvtLicense EvtLicense::get(int eventId, int licenseId)
{
    TSqlORMapper<EvtLicenseObject> mapper;
    return EvtLicense(mapper.findByPrimaryKey(QVariantList()<<QVariant(eventId)<<QVariant(licenseId)));
}

int EvtLicense::count()
{
    TSqlORMapper<EvtLicenseObject> mapper;
    return mapper.findCount();
}

QList<EvtLicense> EvtLicense::getAll()
{
    return tfGetModelListByCriteria<EvtLicense, EvtLicenseObject>();
}

TModelObject *EvtLicense::modelData()
{
    return d.data();
}

const TModelObject *EvtLicense::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const EvtLicense &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, EvtLicense &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(EvtLicense)
