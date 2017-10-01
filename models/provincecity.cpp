#include <TreeFrogModel>
#include "provincecity.h"
#include "provincecityobject.h"
#include "city.h"
#include "province.h"

ProvinceCity::ProvinceCity()
    : TAbstractModel(), d(new ProvinceCityObject())
{
    d->province_id = 0;
    d->city_id = 0;
}

ProvinceCity::ProvinceCity(const ProvinceCity &other)
    : TAbstractModel(), d(new ProvinceCityObject(*other.d))
{ }

ProvinceCity::ProvinceCity(const ProvinceCityObject &object)
    : TAbstractModel(), d(new ProvinceCityObject(object))
{ }

ProvinceCity::~ProvinceCity()
{
    // If the reference count becomes 0,
    // the shared data object 'ProvinceCityObject' is deleted.
}

int ProvinceCity::provinceId() const
{
    return d->province_id;
}

void ProvinceCity::setProvinceId(int provinceId)
{
    d->province_id = provinceId;
}

int ProvinceCity::cityId() const
{
    return d->city_id;
}

void ProvinceCity::setCityId(int cityId)
{
    d->city_id = cityId;
}

QDateTime ProvinceCity::createdAt() const
{
    return d->created_at;
}

QString ProvinceCity::createdBy() const
{
    return d->created_by;
}

void ProvinceCity::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime ProvinceCity::updatedAt() const
{
    return d->updated_at;
}

QString ProvinceCity::updatedBy() const
{
    return d->updated_by;
}

void ProvinceCity::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

City ProvinceCity::cityBycityId() const
{
 return City::get(d->city_id);
}

Province ProvinceCity::provinceByprovinceId() const
{
 return Province::get(d->province_id);
}

ProvinceCity &ProvinceCity::operator=(const ProvinceCity &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ProvinceCity ProvinceCity::create(int provinceId, int cityId, const QString &createdBy, const QString &updatedBy)
{
    ProvinceCityObject obj;
    obj.province_id = provinceId;
    obj.city_id = cityId;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return ProvinceCity();
    }
    return ProvinceCity(obj);
}

ProvinceCity ProvinceCity::create(const QVariantMap &values)
{
    ProvinceCity model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ProvinceCity ProvinceCity::get(int provinceId, int cityId)
{
    TSqlORMapper<ProvinceCityObject> mapper;
    return ProvinceCity(mapper.findByPrimaryKey(QVariantList()<<QVariant(provinceId)<<QVariant(cityId)));
}

int ProvinceCity::count()
{
    TSqlORMapper<ProvinceCityObject> mapper;
    return mapper.findCount();
}

QList<ProvinceCity> ProvinceCity::getAll()
{
    return tfGetModelListByCriteria<ProvinceCity, ProvinceCityObject>();
}

TModelObject *ProvinceCity::modelData()
{
    return d.data();
}

const TModelObject *ProvinceCity::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ProvinceCity &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ProvinceCity &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ProvinceCity)
