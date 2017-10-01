#include <TreeFrogModel>
#include "license.h"
#include "licenseobject.h"
#include "reflicensestatus.h"

License::License()
    : TAbstractModel(), d(new LicenseObject())
{
    d->license_id = 0;
}

License::License(const License &other)
    : TAbstractModel(), d(new LicenseObject(*other.d))
{ }

License::License(const LicenseObject &object)
    : TAbstractModel(), d(new LicenseObject(object))
{ }

License::~License()
{
    // If the reference count becomes 0,
    // the shared data object 'LicenseObject' is deleted.
}

int License::licenseId() const
{
    return d->license_id;
}

QString License::licenseCd() const
{
    return d->license_cd;
}

void License::setLicenseCd(const QString &licenseCd)
{
    d->license_cd = licenseCd;
}

QString License::licenseName() const
{
    return d->license_name;
}

void License::setLicenseName(const QString &licenseName)
{
    d->license_name = licenseName;
}

QString License::licenseDesc() const
{
    return d->license_desc;
}

void License::setLicenseDesc(const QString &licenseDesc)
{
    d->license_desc = licenseDesc;
}

QString License::licenseStatusCd() const
{
    return d->license_status_cd;
}

void License::setLicenseStatusCd(const QString &licenseStatusCd)
{
    d->license_status_cd = licenseStatusCd;
}

QDateTime License::createdAt() const
{
    return d->created_at;
}

QString License::createdBy() const
{
    return d->created_by;
}

void License::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime License::updatedAt() const
{
    return d->updated_at;
}

QString License::updatedBy() const
{
    return d->updated_by;
}

void License::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLicenseStatus License::refLicenseStatusBylicenseStatusCd() const
{
 return RefLicenseStatus::get(d->license_status_cd);
}

License &License::operator=(const License &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

License License::create(const QString &licenseCd, const QString &licenseName, const QString &licenseDesc, const QString &licenseStatusCd, const QString &createdBy, const QString &updatedBy)
{
    LicenseObject obj;
    obj.license_cd = licenseCd;
    obj.license_name = licenseName;
    obj.license_desc = licenseDesc;
    obj.license_status_cd = licenseStatusCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return License();
    }
    return License(obj);
}

License License::create(const QVariantMap &values)
{
    License model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

License License::get(int licenseId)
{
    TSqlORMapper<LicenseObject> mapper;
    return License(mapper.findByPrimaryKey(licenseId));
}

int License::count()
{
    TSqlORMapper<LicenseObject> mapper;
    return mapper.findCount();
}

QList<License> License::getAll()
{
    return tfGetModelListByCriteria<License, LicenseObject>();
}

TModelObject *License::modelData()
{
    return d.data();
}

const TModelObject *License::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const License &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, License &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(License)
