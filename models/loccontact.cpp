#include <TreeFrogModel>
#include "loccontact.h"
#include "loccontactobject.h"
#include "contact.h"
#include "loc.h"

LocContact::LocContact()
    : TAbstractModel(), d(new LocContactObject())
{
    d->loc_id = 0;
    d->contact_id = 0;
}

LocContact::LocContact(const LocContact &other)
    : TAbstractModel(), d(new LocContactObject(*other.d))
{ }

LocContact::LocContact(const LocContactObject &object)
    : TAbstractModel(), d(new LocContactObject(object))
{ }

LocContact::~LocContact()
{
    // If the reference count becomes 0,
    // the shared data object 'LocContactObject' is deleted.
}

int LocContact::locId() const
{
    return d->loc_id;
}

void LocContact::setLocId(int locId)
{
    d->loc_id = locId;
}

int LocContact::contactId() const
{
    return d->contact_id;
}

void LocContact::setContactId(int contactId)
{
    d->contact_id = contactId;
}

bool LocContact::defaultBool() const
{
    return d->default_bool;
}

void LocContact::setDefaultBool(bool defaultBool)
{
    d->default_bool = defaultBool;
}

QDateTime LocContact::createdAt() const
{
    return d->created_at;
}

QString LocContact::createdBy() const
{
    return d->created_by;
}

void LocContact::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime LocContact::updatedAt() const
{
    return d->updated_at;
}

QString LocContact::updatedBy() const
{
    return d->updated_by;
}

void LocContact::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Contact LocContact::contactBycontactId() const
{
 return Contact::get(d->contact_id);
}

Loc LocContact::locBylocId() const
{
 return Loc::get(d->loc_id);
}

LocContact &LocContact::operator=(const LocContact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

LocContact LocContact::create(int locId, int contactId, bool defaultBool, const QString &createdBy, const QString &updatedBy)
{
    LocContactObject obj;
    obj.loc_id = locId;
    obj.contact_id = contactId;
    obj.default_bool = defaultBool;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return LocContact();
    }
    return LocContact(obj);
}

LocContact LocContact::create(const QVariantMap &values)
{
    LocContact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

LocContact LocContact::get(int locId, int contactId)
{
    TSqlORMapper<LocContactObject> mapper;
    return LocContact(mapper.findByPrimaryKey(QVariantList()<<QVariant(locId)<<QVariant(contactId)));
}

int LocContact::count()
{
    TSqlORMapper<LocContactObject> mapper;
    return mapper.findCount();
}

QList<LocContact> LocContact::getAll()
{
    return tfGetModelListByCriteria<LocContact, LocContactObject>();
}

TModelObject *LocContact::modelData()
{
    return d.data();
}

const TModelObject *LocContact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const LocContact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, LocContact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(LocContact)
