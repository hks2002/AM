#include <TreeFrogModel>
#include "countryprovince.h"
#include "countryprovinceobject.h"
#include "province.h"
#include "country.h"

CountryProvince::CountryProvince()
    : TAbstractModel(), d(new CountryProvinceObject())
{
    d->country_id = 0;
    d->province_id = 0;
}

CountryProvince::CountryProvince(const CountryProvince &other)
    : TAbstractModel(), d(new CountryProvinceObject(*other.d))
{ }

CountryProvince::CountryProvince(const CountryProvinceObject &object)
    : TAbstractModel(), d(new CountryProvinceObject(object))
{ }

CountryProvince::~CountryProvince()
{
    // If the reference count becomes 0,
    // the shared data object 'CountryProvinceObject' is deleted.
}

int CountryProvince::countryId() const
{
    return d->country_id;
}

void CountryProvince::setCountryId(int countryId)
{
    d->country_id = countryId;
}

int CountryProvince::provinceId() const
{
    return d->province_id;
}

void CountryProvince::setProvinceId(int provinceId)
{
    d->province_id = provinceId;
}

QDateTime CountryProvince::createdAt() const
{
    return d->created_at;
}

QString CountryProvince::createdBy() const
{
    return d->created_by;
}

void CountryProvince::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime CountryProvince::updatedAt() const
{
    return d->updated_at;
}

QString CountryProvince::updatedBy() const
{
    return d->updated_by;
}

void CountryProvince::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Province CountryProvince::provinceByprovinceId() const
{
 return Province::get(d->province_id);
}

Country CountryProvince::countryBycountryId() const
{
 return Country::get(d->country_id);
}

CountryProvince &CountryProvince::operator=(const CountryProvince &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

CountryProvince CountryProvince::create(int countryId, int provinceId, const QString &createdBy, const QString &updatedBy)
{
    CountryProvinceObject obj;
    obj.country_id = countryId;
    obj.province_id = provinceId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return CountryProvince();
    }
    return CountryProvince(obj);
}

CountryProvince CountryProvince::create(const QVariantMap &values)
{
    CountryProvince model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

CountryProvince CountryProvince::get(int countryId, int provinceId)
{
    TSqlORMapper<CountryProvinceObject> mapper;
    return CountryProvince(mapper.findByPrimaryKey(QVariantList()<<QVariant(countryId)<<QVariant(provinceId)));
}

int CountryProvince::count()
{
    TSqlORMapper<CountryProvinceObject> mapper;
    return mapper.findCount();
}

QList<CountryProvince> CountryProvince::getAll()
{
    return tfGetModelListByCriteria<CountryProvince, CountryProvinceObject>();
}

TModelObject *CountryProvince::modelData()
{
    return d.data();
}

const TModelObject *CountryProvince::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const CountryProvince &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, CountryProvince &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(CountryProvince)
