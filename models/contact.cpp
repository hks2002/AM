#include <TreeFrogModel>
#include "contact.h"
#include "contactobject.h"

Contact::Contact()
    : TAbstractModel(), d(new ContactObject())
{
    d->contact_id = 0;
}

Contact::Contact(const Contact &other)
    : TAbstractModel(), d(new ContactObject(*other.d))
{ }

Contact::Contact(const ContactObject &object)
    : TAbstractModel(), d(new ContactObject(object))
{ }

Contact::~Contact()
{
    // If the reference count becomes 0,
    // the shared data object 'ContactObject' is deleted.
}

int Contact::contactId() const
{
    return d->contact_id;
}

QString Contact::addressEmail() const
{
    return d->address_email;
}

void Contact::setAddressEmail(const QString &addressEmail)
{
    d->address_email = addressEmail;
}

QString Contact::contactName() const
{
    return d->contact_name;
}

void Contact::setContactName(const QString &contactName)
{
    d->contact_name = contactName;
}

QString Contact::jobTitle() const
{
    return d->job_title;
}

void Contact::setJobTitle(const QString &jobTitle)
{
    d->job_title = jobTitle;
}

QString Contact::faxPh() const
{
    return d->fax_ph;
}

void Contact::setFaxPh(const QString &faxPh)
{
    d->fax_ph = faxPh;
}

QString Contact::phonePh() const
{
    return d->phone_ph;
}

void Contact::setPhonePh(const QString &phonePh)
{
    d->phone_ph = phonePh;
}

QDateTime Contact::createdAt() const
{
    return d->created_at;
}

QString Contact::createdBy() const
{
    return d->created_by;
}

void Contact::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Contact::updatedAt() const
{
    return d->updated_at;
}

QString Contact::updatedBy() const
{
    return d->updated_by;
}

void Contact::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Contact &Contact::operator=(const Contact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Contact Contact::create(const QString &addressEmail, const QString &contactName, const QString &jobTitle, const QString &faxPh, const QString &phonePh, const QString &createdBy, const QString &updatedBy)
{
    ContactObject obj;
    obj.address_email = addressEmail;
    obj.contact_name = contactName;
    obj.job_title = jobTitle;
    obj.fax_ph = faxPh;
    obj.phone_ph = phonePh;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Contact();
    }
    return Contact(obj);
}

Contact Contact::create(const QVariantMap &values)
{
    Contact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Contact Contact::get(int contactId)
{
    TSqlORMapper<ContactObject> mapper;
    return Contact(mapper.findByPrimaryKey(contactId));
}

int Contact::count()
{
    TSqlORMapper<ContactObject> mapper;
    return mapper.findCount();
}

QList<Contact> Contact::getAll()
{
    return tfGetModelListByCriteria<Contact, ContactObject>();
}

TModelObject *Contact::modelData()
{
    return d.data();
}

const TModelObject *Contact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Contact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Contact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Contact)
