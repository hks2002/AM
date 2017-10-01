#include <TreeFrogModel>
#include "orgcontact.h"
#include "orgcontactobject.h"
#include "contact.h"
#include "org.h"

OrgContact::OrgContact()
    : TAbstractModel(), d(new OrgContactObject())
{
    d->org_id = 0;
    d->contact_id = 0;
}

OrgContact::OrgContact(const OrgContact &other)
    : TAbstractModel(), d(new OrgContactObject(*other.d))
{ }

OrgContact::OrgContact(const OrgContactObject &object)
    : TAbstractModel(), d(new OrgContactObject(object))
{ }

OrgContact::~OrgContact()
{
    // If the reference count becomes 0,
    // the shared data object 'OrgContactObject' is deleted.
}

int OrgContact::orgId() const
{
    return d->org_id;
}

void OrgContact::setOrgId(int orgId)
{
    d->org_id = orgId;
}

int OrgContact::contactId() const
{
    return d->contact_id;
}

void OrgContact::setContactId(int contactId)
{
    d->contact_id = contactId;
}

bool OrgContact::mainBool() const
{
    return d->main_bool;
}

void OrgContact::setMainBool(bool mainBool)
{
    d->main_bool = mainBool;
}

QDateTime OrgContact::createdAt() const
{
    return d->created_at;
}

QString OrgContact::createdBy() const
{
    return d->created_by;
}

void OrgContact::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime OrgContact::updatedAt() const
{
    return d->updated_at;
}

QString OrgContact::updatedBy() const
{
    return d->updated_by;
}

void OrgContact::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Contact OrgContact::contactBycontactId() const
{
 return Contact::get(d->contact_id);
}

Org OrgContact::orgByorgId() const
{
 return Org::get(d->org_id);
}

OrgContact &OrgContact::operator=(const OrgContact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

OrgContact OrgContact::create(int orgId, int contactId, bool mainBool, const QString &createdBy, const QString &updatedBy)
{
    OrgContactObject obj;
    obj.org_id = orgId;
    obj.contact_id = contactId;
    obj.main_bool = mainBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return OrgContact();
    }
    return OrgContact(obj);
}

OrgContact OrgContact::create(const QVariantMap &values)
{
    OrgContact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

OrgContact OrgContact::get(int orgId, int contactId)
{
    TSqlORMapper<OrgContactObject> mapper;
    return OrgContact(mapper.findByPrimaryKey(QVariantList()<<QVariant(orgId)<<QVariant(contactId)));
}

int OrgContact::count()
{
    TSqlORMapper<OrgContactObject> mapper;
    return mapper.findCount();
}

QList<OrgContact> OrgContact::getAll()
{
    return tfGetModelListByCriteria<OrgContact, OrgContactObject>();
}

TModelObject *OrgContact::modelData()
{
    return d.data();
}

const TModelObject *OrgContact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const OrgContact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, OrgContact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(OrgContact)
