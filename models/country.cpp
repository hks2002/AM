#include <TreeFrogModel>
#include "country.h"
#include "countryobject.h"

Country::Country()
    : TAbstractModel(), d(new CountryObject())
{
    d->country_id = 0;
}

Country::Country(const Country &other)
    : TAbstractModel(), d(new CountryObject(*other.d))
{ }

Country::Country(const CountryObject &object)
    : TAbstractModel(), d(new CountryObject(object))
{ }

Country::~Country()
{
    // If the reference count becomes 0,
    // the shared data object 'CountryObject' is deleted.
}

int Country::countryId() const
{
    return d->country_id;
}

QString Country::countryNameZh() const
{
    return d->country_name_zh;
}

void Country::setCountryNameZh(const QString &countryNameZh)
{
    d->country_name_zh = countryNameZh;
}

QString Country::countryNameEn() const
{
    return d->country_name_en;
}

void Country::setCountryNameEn(const QString &countryNameEn)
{
    d->country_name_en = countryNameEn;
}

QString Country::countryDesc() const
{
    return d->country_desc;
}

void Country::setCountryDesc(const QString &countryDesc)
{
    d->country_desc = countryDesc;
}

QDateTime Country::createdAt() const
{
    return d->created_at;
}

QString Country::createdBy() const
{
    return d->created_by;
}

void Country::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Country::updatedAt() const
{
    return d->updated_at;
}

QString Country::updatedBy() const
{
    return d->updated_by;
}

void Country::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Country &Country::operator=(const Country &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Country Country::create(const QString &countryNameZh, const QString &countryNameEn, const QString &countryDesc, const QString &createdBy, const QString &updatedBy)
{
    CountryObject obj;
    obj.country_name_zh = countryNameZh;
    obj.country_name_en = countryNameEn;
    obj.country_desc = countryDesc;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Country();
    }
    return Country(obj);
}

Country Country::create(const QVariantMap &values)
{
    Country model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Country Country::get(int countryId)
{
    TSqlORMapper<CountryObject> mapper;
    return Country(mapper.findByPrimaryKey(countryId));
}

int Country::count()
{
    TSqlORMapper<CountryObject> mapper;
    return mapper.findCount();
}

QList<Country> Country::getAll()
{
    return tfGetModelListByCriteria<Country, CountryObject>();
}

TModelObject *Country::modelData()
{
    return d.data();
}

const TModelObject *Country::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Country &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Country &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Country)
