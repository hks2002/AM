#include <TreeFrogModel>
#include "address.h"
#include "addressobject.h"
#include "province.h"
#include "country.h"
#include "city.h"

Address::Address()
    : TAbstractModel(), d(new AddressObject())
{
    d->address_id = 0;
    d->city_id = 0;
    d->country_id = 0;
    d->province_id = 0;
}

Address::Address(const Address &other)
    : TAbstractModel(), d(new AddressObject(*other.d))
{ }

Address::Address(const AddressObject &object)
    : TAbstractModel(), d(new AddressObject(object))
{ }

Address::~Address()
{
    // If the reference count becomes 0,
    // the shared data object 'AddressObject' is deleted.
}

int Address::addressId() const
{
    return d->address_id;
}

QString Address::addressLine1() const
{
    return d->address_line1;
}

void Address::setAddressLine1(const QString &addressLine1)
{
    d->address_line1 = addressLine1;
}

QString Address::addressLine2() const
{
    return d->address_line2;
}

void Address::setAddressLine2(const QString &addressLine2)
{
    d->address_line2 = addressLine2;
}

int Address::cityId() const
{
    return d->city_id;
}

void Address::setCityId(int cityId)
{
    d->city_id = cityId;
}

int Address::countryId() const
{
    return d->country_id;
}

void Address::setCountryId(int countryId)
{
    d->country_id = countryId;
}

int Address::provinceId() const
{
    return d->province_id;
}

void Address::setProvinceId(int provinceId)
{
    d->province_id = provinceId;
}

QString Address::zipCd() const
{
    return d->zip_cd;
}

void Address::setZipCd(const QString &zipCd)
{
    d->zip_cd = zipCd;
}

QDateTime Address::createdAt() const
{
    return d->created_at;
}

QString Address::createdBy() const
{
    return d->created_by;
}

void Address::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Address::updatedAt() const
{
    return d->updated_at;
}

QString Address::updatedBy() const
{
    return d->updated_by;
}

void Address::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Province Address::provinceByprovinceId() const
{
 return Province::get(d->province_id);
}

Country Address::countryBycountryId() const
{
 return Country::get(d->country_id);
}

City Address::cityBycityId() const
{
 return City::get(d->city_id);
}

Address &Address::operator=(const Address &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Address Address::create(const QString &addressLine1, const QString &addressLine2, int cityId, int countryId, int provinceId, const QString &zipCd, const QString &createdBy, const QString &updatedBy)
{
    AddressObject obj;
    obj.address_line1 = addressLine1;
    obj.address_line2 = addressLine2;
    obj.city_id = cityId;
    obj.country_id = countryId;
    obj.province_id = provinceId;
    obj.zip_cd = zipCd;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Address();
    }
    return Address(obj);
}

Address Address::create(const QVariantMap &values)
{
    Address model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Address Address::get(int addressId)
{
    TSqlORMapper<AddressObject> mapper;
    return Address(mapper.findByPrimaryKey(addressId));
}

int Address::count()
{
    TSqlORMapper<AddressObject> mapper;
    return mapper.findCount();
}

QList<Address> Address::getAll()
{
    return tfGetModelListByCriteria<Address, AddressObject>();
}

TModelObject *Address::modelData()
{
    return d.data();
}

const TModelObject *Address::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Address &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Address &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Address)
