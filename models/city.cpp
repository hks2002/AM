#include <TreeFrogModel>
#include "city.h"
#include "cityobject.h"

City::City()
    : TAbstractModel(), d(new CityObject())
{
    d->city_id = 0;
}

City::City(const City &other)
    : TAbstractModel(), d(new CityObject(*other.d))
{ }

City::City(const CityObject &object)
    : TAbstractModel(), d(new CityObject(object))
{ }

City::~City()
{
    // If the reference count becomes 0,
    // the shared data object 'CityObject' is deleted.
}

int City::cityId() const
{
    return d->city_id;
}

QString City::cityNameZh() const
{
    return d->city_name_zh;
}

void City::setCityNameZh(const QString &cityNameZh)
{
    d->city_name_zh = cityNameZh;
}

QString City::cityNameEn() const
{
    return d->city_name_en;
}

void City::setCityNameEn(const QString &cityNameEn)
{
    d->city_name_en = cityNameEn;
}

QString City::cityDesc() const
{
    return d->city_desc;
}

void City::setCityDesc(const QString &cityDesc)
{
    d->city_desc = cityDesc;
}

QDateTime City::createdAt() const
{
    return d->created_at;
}

QString City::createdBy() const
{
    return d->created_by;
}

void City::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime City::updatedAt() const
{
    return d->updated_at;
}

QString City::updatedBy() const
{
    return d->updated_by;
}

void City::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

City &City::operator=(const City &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

City City::create(const QString &cityNameZh, const QString &cityNameEn, const QString &cityDesc, const QString &createdBy, const QString &updatedBy)
{
    CityObject obj;
    obj.city_name_zh = cityNameZh;
    obj.city_name_en = cityNameEn;
    obj.city_desc = cityDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return City();
    }
    return City(obj);
}

City City::create(const QVariantMap &values)
{
    City model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

City City::get(int cityId)
{
    TSqlORMapper<CityObject> mapper;
    return City(mapper.findByPrimaryKey(cityId));
}

int City::count()
{
    TSqlORMapper<CityObject> mapper;
    return mapper.findCount();
}

QList<City> City::getAll()
{
    return tfGetModelListByCriteria<City, CityObject>();
}

TModelObject *City::modelData()
{
    return d.data();
}

const TModelObject *City::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const City &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, City &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(City)
