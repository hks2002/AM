#include <TreeFrogModel>
#include "reflicensestatus.h"
#include "reflicensestatusobject.h"

RefLicenseStatus::RefLicenseStatus()
    : TAbstractModel(), d(new RefLicenseStatusObject())
{ }

RefLicenseStatus::RefLicenseStatus(const RefLicenseStatus &other)
    : TAbstractModel(), d(new RefLicenseStatusObject(*other.d))
{ }

RefLicenseStatus::RefLicenseStatus(const RefLicenseStatusObject &object)
    : TAbstractModel(), d(new RefLicenseStatusObject(object))
{ }

RefLicenseStatus::~RefLicenseStatus()
{
    // If the reference count becomes 0,
    // the shared data object 'RefLicenseStatusObject' is deleted.
}

QString RefLicenseStatus::licenseStatusCd() const
{
    return d->license_status_cd;
}

void RefLicenseStatus::setLicenseStatusCd(const QString &licenseStatusCd)
{
    d->license_status_cd = licenseStatusCd;
}

QString RefLicenseStatus::licenseStatusNameEn() const
{
    return d->license_status_name_en;
}

void RefLicenseStatus::setLicenseStatusNameEn(const QString &licenseStatusNameEn)
{
    d->license_status_name_en = licenseStatusNameEn;
}

QString RefLicenseStatus::licenseStatusNameZh() const
{
    return d->license_status_name_zh;
}

void RefLicenseStatus::setLicenseStatusNameZh(const QString &licenseStatusNameZh)
{
    d->license_status_name_zh = licenseStatusNameZh;
}

QString RefLicenseStatus::licenseStatusDesc() const
{
    return d->license_status_desc;
}

void RefLicenseStatus::setLicenseStatusDesc(const QString &licenseStatusDesc)
{
    d->license_status_desc = licenseStatusDesc;
}

QDateTime RefLicenseStatus::createdAt() const
{
    return d->created_at;
}

QString RefLicenseStatus::createdBy() const
{
    return d->created_by;
}

void RefLicenseStatus::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime RefLicenseStatus::updatedAt() const
{
    return d->updated_at;
}

QString RefLicenseStatus::updatedBy() const
{
    return d->updated_by;
}

void RefLicenseStatus::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

RefLicenseStatus &RefLicenseStatus::operator=(const RefLicenseStatus &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

RefLicenseStatus RefLicenseStatus::create(const QString &licenseStatusCd, const QString &licenseStatusNameEn, const QString &licenseStatusNameZh, const QString &licenseStatusDesc, const QString &createdBy, const QString &updatedBy)
{
    RefLicenseStatusObject obj;
    obj.license_status_cd = licenseStatusCd;
    obj.license_status_name_en = licenseStatusNameEn;
    obj.license_status_name_zh = licenseStatusNameZh;
    obj.license_status_desc = licenseStatusDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return RefLicenseStatus();
    }
    return RefLicenseStatus(obj);
}

RefLicenseStatus RefLicenseStatus::create(const QVariantMap &values)
{
    RefLicenseStatus model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

RefLicenseStatus RefLicenseStatus::get(const QString &licenseStatusCd)
{
    TSqlORMapper<RefLicenseStatusObject> mapper;
    return RefLicenseStatus(mapper.findByPrimaryKey(licenseStatusCd));
}

int RefLicenseStatus::count()
{
    TSqlORMapper<RefLicenseStatusObject> mapper;
    return mapper.findCount();
}

QList<RefLicenseStatus> RefLicenseStatus::getAll()
{
    return tfGetModelListByCriteria<RefLicenseStatus, RefLicenseStatusObject>();
}

TModelObject *RefLicenseStatus::modelData()
{
    return d.data();
}

const TModelObject *RefLicenseStatus::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const RefLicenseStatus &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, RefLicenseStatus &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(RefLicenseStatus)
