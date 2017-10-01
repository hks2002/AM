#include <TreeFrogModel>
#include "currency.h"
#include "currencyobject.h"

Currency::Currency()
    : TAbstractModel(), d(new CurrencyObject())
{
    d->currency_id = 0;
}

Currency::Currency(const Currency &other)
    : TAbstractModel(), d(new CurrencyObject(*other.d))
{ }

Currency::Currency(const CurrencyObject &object)
    : TAbstractModel(), d(new CurrencyObject(object))
{ }

Currency::~Currency()
{
    // If the reference count becomes 0,
    // the shared data object 'CurrencyObject' is deleted.
}

int Currency::currencyId() const
{
    return d->currency_id;
}

QString Currency::currencyCd() const
{
    return d->currency_cd;
}

void Currency::setCurrencyCd(const QString &currencyCd)
{
    d->currency_cd = currencyCd;
}

QString Currency::currencyNameZh() const
{
    return d->currency_name_zh;
}

void Currency::setCurrencyNameZh(const QString &currencyNameZh)
{
    d->currency_name_zh = currencyNameZh;
}

QString Currency::currencyNameEn() const
{
    return d->currency_name_en;
}

void Currency::setCurrencyNameEn(const QString &currencyNameEn)
{
    d->currency_name_en = currencyNameEn;
}

QDateTime Currency::createdAt() const
{
    return d->created_at;
}

QString Currency::createdBy() const
{
    return d->created_by;
}

void Currency::setCreatedBy(const QString &createdBy)
{
    d->created_by = createdBy;
}

QDateTime Currency::updatedAt() const
{
    return d->updated_at;
}

QString Currency::updatedBy() const
{
    return d->updated_by;
}

void Currency::setUpdatedBy(const QString &updatedBy)
{
    d->updated_by = updatedBy;
}

Currency &Currency::operator=(const Currency &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Currency Currency::create(const QString &currencyCd, const QString &currencyNameZh, const QString &currencyNameEn, const QString &createdBy, const QString &updatedBy)
{
    CurrencyObject obj;
    obj.currency_cd = currencyCd;
    obj.currency_name_zh = currencyNameZh;
    obj.currency_name_en = currencyNameEn;
    obj.created_by = createdBy;
    obj.updated_by = updatedBy;
    if (!obj.create()) {
        return Currency();
    }
    return Currency(obj);
}

Currency Currency::create(const QVariantMap &values)
{
    Currency model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Currency Currency::get(int currencyId)
{
    TSqlORMapper<CurrencyObject> mapper;
    return Currency(mapper.findByPrimaryKey(currencyId));
}

int Currency::count()
{
    TSqlORMapper<CurrencyObject> mapper;
    return mapper.findCount();
}

QList<Currency> Currency::getAll()
{
    return tfGetModelListByCriteria<Currency, CurrencyObject>();
}

TModelObject *Currency::modelData()
{
    return d.data();
}

const TModelObject *Currency::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Currency &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Currency &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Currency)
